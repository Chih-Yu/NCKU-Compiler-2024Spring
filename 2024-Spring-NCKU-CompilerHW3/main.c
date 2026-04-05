#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#define WJCL_LINKED_LIST_IMPLEMENTATION
#include "main.h"
#define WJCL_HASH_MAP_IMPLEMENTATION
// #include "value_operation.h"

#define debug printf("%s:%d: ############### debug\n", __FILE__, __LINE__)
#define toupper(_char) (_char - (char)32)

#define iload(var) code("iload %" PRId64 " ; %s", (var)->symbol->addr, (var)->symbol->name)
#define lload(var) code("lload %" PRId64 " ; %s", (var)->symbol->addr, (var)->symbol->name)
#define fload(var) code("fload %" PRId64 " ; %s", (var)->symbol->addr, (var)->symbol->name)
#define dload(var) code("dload %" PRId64 " ; %s", (var)->symbol->addr, (var)->symbol->name)
#define aload(var) code("aload %" PRId64 " ; %s", (var)->symbol->addr, (var)->symbol->name)

#define istore(var) code("istore %" PRId64 " ; %s", (var)->symbol->addr, (var)->symbol->name)
#define lstore(var) code("lstore %" PRId64 " ; %s", (var)->symbol->addr, (var)->symbol->name)
#define fstore(var) code("fstore %" PRId64 " ; %s", (var)->symbol->addr, (var)->symbol->name)
#define dstore(var) code("dstore %" PRId64 " ; %s", (var)->symbol->addr, (var)->symbol->name)
#define astore(var) code("astore %" PRId64 " ; %s", (var)->symbol->addr, (var)->symbol->name)

#define ldz(val) code("ldc %d", getBool(val))
#define ldb(val) code("ldc %d", getByte(val))
#define ldc(val) code("ldc %d", getChar(val))
#define lds(val) code("ldc %d", getShort(val))
#define ldi(val) code("ldc %d", getInt(val))
#define ldl(val) code("ldc_w %" PRId64, getLong(val))
#define ldf(val) code("ldc %.6f", getFloat(val))
#define ldd(val) code("ldc_w %lf", getDouble(val))
#define ldt(val) code("ldc \"%s\"", getString(val))

const char* objectTypeName[] = {
    [OBJECT_TYPE_UNDEFINED] = "undefined",
    [OBJECT_TYPE_VOID] = "void",
    [OBJECT_TYPE_BOOL] = "bool",
    [OBJECT_TYPE_BYTE] = "byte",
    [OBJECT_TYPE_CHAR] = "char",
    [OBJECT_TYPE_SHORT] = "short",
    [OBJECT_TYPE_INT] = "int",
    [OBJECT_TYPE_LONG] = "long",
    [OBJECT_TYPE_FLOAT] = "float",
    [OBJECT_TYPE_DOUBLE] = "double",
    [OBJECT_TYPE_STR] = "string",
    
    [OBJECT_TYPE_FUNCTION] = "function",
};
const char* objectJavaTypeName[] = {
    [OBJECT_TYPE_UNDEFINED] = "V",
    [OBJECT_TYPE_VOID] = "V",
    [OBJECT_TYPE_BOOL] = "Z",
    [OBJECT_TYPE_BYTE] = "B",
    [OBJECT_TYPE_CHAR] = "C",
    [OBJECT_TYPE_SHORT] = "S",
    [OBJECT_TYPE_INT] = "I",
    [OBJECT_TYPE_LONG] = "J",
    [OBJECT_TYPE_FLOAT] = "F",
    [OBJECT_TYPE_DOUBLE] = "D",
    [OBJECT_TYPE_STR] = "Ljava/lang/String;",
};

char* yyInputFileName;
bool compileError;
int indent = 0;
int scopeLevel = -1;
int funcLineNo = 0;
int variableAddress = 0;
ObjectType variableIdentType;

Object symbolTable[10][10];
// int tableSize = -1;
int objectIndex[10];

Object stdoutList[30]; // save cout variable
int stdoutListSize = 0;

char* funcSig; // store function signature, only name
Object* funcObj = NULL; //

/* variable for HW3 */
int LabelCt = 0; // label count for compare

void printExpJ(ObjectType VariableType) {
    codeRaw("getstatic java/lang/System/out Ljava/io/PrintStream;");
    codeRaw("swap");
    if(VariableType == OBJECT_TYPE_INT) {
		codeRaw("invokevirtual java/io/PrintStream/print(I)V");
	} else if(VariableType == OBJECT_TYPE_BOOL) {
		codeRaw("invokevirtual java/io/PrintStream/print(Z)V");
	} else if(VariableType == OBJECT_TYPE_FLOAT) {
		codeRaw("invokevirtual java/io/PrintStream/print(F)V");
	} else if(VariableType == OBJECT_TYPE_STR || VariableType == OBJECT_TYPE_CHAR ) {
		codeRaw("invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V");
	}
}

void compareIntJ(char* operator) {
    if(strcmp(operator, "GTR") == 0) {
		// >
		code("if_icmpgt gtrLabel%d", LabelCt); // if v1 > v2
		codeRaw("iconst_0");	//false
		code("goto endLabel%d", LabelCt);
		code("gtrLabel%d:", LabelCt); //true
		codeRaw("iconst_1");	// true
		code("endLabel%d:", LabelCt);
		LabelCt++;
    }else if(strcmp(operator, "LES") == 0){
        // <
        code("if_icmplt lesLabel%d", LabelCt); // if v1 < v2
        codeRaw("iconst_0");	//false
        code("goto endLabel%d", LabelCt);
		code("lesLabel%d:", LabelCt); //true
		codeRaw("iconst_1");	// true
		code("endLabel%d:", LabelCt);
		LabelCt++;
	}else if(strcmp(operator, "NOT") == 0) {
        // !
		codeRaw("iconst_m1");
		codeRaw("ixor");
	}else if(strcmp(operator, "GEQ") == 0) {
		// >=
		code("if_icmpge geqLabel%d", LabelCt); // if v1 >= v2
		codeRaw("iconst_0");	//false
		code("goto endLabel%d", LabelCt);
		code("geqLabel%d:", LabelCt); //true
		codeRaw("iconst_1");	// true
		code("endLabel%d:", LabelCt);
		LabelCt++;
    }else if(strcmp(operator, "LEQ") == 0) {
		// <=
		code("if_icmple leqLabel%d", LabelCt); // if v1 <= v2
		codeRaw("iconst_0");	//false
		code("goto endLabel%d", LabelCt);
		code("leqLabel%d:", LabelCt); //true
		codeRaw("iconst_1");	// true
		code("endLabel%d:", LabelCt);
		LabelCt++;
    }else if(strcmp(operator, "NEQ") == 0){
        // !=
        code("if_icmpne neqLabel%d", LabelCt);
        codeRaw("iconst_0");
        code("goto endLabel%d", LabelCt);
        code("neqLabel%d:", LabelCt);
        codeRaw("iconst_1");
        code("endLabel%d:", LabelCt);
        LabelCt++;
    }else if(strcmp(operator, "EQL") == 0){
        // ==
        code("if_icmpeq eqlLabel%d", LabelCt); // if v1 = v2
		codeRaw("iconst_0");
        code("goto endLabel%d", LabelCt);
        code("eqlLabel%d:", LabelCt);
        codeRaw("iconst_1");
        code("endLabel%d:", LabelCt);
        LabelCt++;
    }else if(strcmp(operator, "INC") == 0) {
        //++
		codeRaw("ldc 1");
		codeRaw("iadd");
	}
	else if(strcmp(operator, "DEC") == 0) {
        // --
		codeRaw("ldc -1");
		codeRaw("iadd");
	}
}

void compareFloatJ(char* operator) {
    if(strcmp(operator, "GTR")==0) {
		//比較大小
        codeRaw("fcmpg");
		code("ifgt gtrLabel%d", LabelCt); // if v1 > v2
		codeRaw("iconst_0");	//false
		code("goto endLabel%d", LabelCt);
		code("gtrLabel%d:", LabelCt); //true
		codeRaw("iconst_1");	// true
		code("endLabel%d:", LabelCt);
		LabelCt++;
	}else if(strcmp(operator, "NOT") == 0) {
		codeRaw("iconst_1");
		codeRaw("ixor");
	}else if(strcmp(operator, "EQL") == 0){
        // ==
        codeRaw("fsub");
		codeRaw("f2i");
        code("if_icmpeq eqlLabel%d", LabelCt); // if v1 = v2
		codeRaw("iconst_0");
        code("goto endLabel%d", LabelCt);
        code("eqlLabel%d:", LabelCt);
        codeRaw("iconst_1");
        code("endLabel%d:", LabelCt);
        LabelCt++;
    }else if(strcmp(operator, "GEQ") == 0) {
		// >=
        codeRaw("fsub");
		codeRaw("f2i");
		code("if_icmpge geqLabel%d", LabelCt); // if v1 >= v2
		codeRaw("iconst_0");	//false
		code("goto endLabel%d", LabelCt);
		code("geqLabel%d:", LabelCt); //true
		codeRaw("iconst_1");	// true
		code("endLabel%d:", LabelCt);
		LabelCt++;
    }else if(strcmp(operator, "LEQ") == 0) {
		// <=
        codeRaw("fsub");
		codeRaw("f2i");
		code("if_icmple leqLabel%d", LabelCt); // if v1 <= v2
		codeRaw("iconst_0");	//false
		code("goto endLabel%d", LabelCt);
		code("leqLabel%d:", LabelCt); //true
		codeRaw("iconst_1");	// true
		code("endLabel%d:", LabelCt);
		LabelCt++;
    }else if(strcmp(operator, "INC") == 0){
        // ++
		codeRaw("ldc 1.0000");
		codeRaw("fadd");
	}
	else if(strcmp(operator, "DEC") == 0) {
        // --
		codeRaw("ldc -1.0000");
		codeRaw("fadd");
	}

}

void createVariableJ(char* variableName) {
    Object* obj = findVariable(variableName);
    int varAddr = obj->symbol->addr;
    ObjectType type = obj->type;

    if(type == OBJECT_TYPE_INT || type == OBJECT_TYPE_BOOL) {
        // if(ObjectType == OBJECT_TYPE_FLOAT) codeRaw("f2i");
		code("istore %d", varAddr);
	}else if(type == OBJECT_TYPE_FLOAT) {
        // if(ObjectType == OBJECT_TYPE_INT) codeRaw("i2f");
		code("fstore %d", varAddr);
	}else if(type == OBJECT_TYPE_STR) {
		code("astore %d", varAddr);
	}
}

void loadVariableJ(char* variableName) {
    Object* obj = findVariable(variableName);
    int varAddr = obj->symbol->addr;
    ObjectType type = obj->type;

    if(type == OBJECT_TYPE_INT || type == OBJECT_TYPE_BOOL) {
		code("iload %d", varAddr);
	}else if(type == OBJECT_TYPE_FLOAT) {
		code("fload %d", varAddr);
	}else if(type == OBJECT_TYPE_STR) {
		code("aload %d", varAddr);
	}
}

/********** Hw2 ************/

void init(){
    funcSig = malloc(100);
    for(int i=0; i<10; i++){
        objectIndex[i] = -1;
        for(int j=0; j<10; j++){
            SymbolData* tmp = (SymbolData*)malloc(sizeof(SymbolData));
            symbolTable[i][j].symbol = tmp;
            char* tmpname = (char*)malloc(100 * sizeof(char));
            symbolTable[i][j].symbol->name = tmpname;
            char* tmpfunc_sig = (char*)malloc(100 * sizeof(char));
            symbolTable[i][j].symbol->func_sig = tmpfunc_sig;
        }
    }
    for(int i=0; i<30; i++){
        SymbolData* stdtmp = (SymbolData*)malloc(sizeof(SymbolData));
        stdoutList[i].symbol = stdtmp;
        char* stdtmpname = (char*)malloc(100 * sizeof(char));
        stdoutList[i].symbol->name = stdtmpname;
        char* stdtmpfunc_sig = (char*)malloc(100 * sizeof(char));
        stdoutList[i].symbol->func_sig = stdtmpfunc_sig;
    }
}

void pushScope() {
    scopeLevel++;
    printf("> Create symbol table (scope level %d)\n", scopeLevel);
}
void printbug(){
    printf("%d\n", objectIndex[scopeLevel]);
}

void dumpScope() {
    printf("\n> Dump symbol table (scope level: %d)\n", scopeLevel);
    printf("Index     Name                Type      Addr      Lineno    Func_sig  \n");
    //printf("%s\n",objectTypeName[symbolTable[scopeLevel][objectIndex[scopeLevel]].type]);
    //printf("%s\n", symbolTable[scopeLevel][objectIndex[scopeLevel]].symbol->func_sig);
    for(int i=0; i<=objectIndex[scopeLevel]; i++) {
        printf("%-10d%-20s%-10s%-10ld%-10d%-10s\n", 
        symbolTable[scopeLevel][i].symbol->index,
        symbolTable[scopeLevel][i].symbol->name,
        objectTypeName[symbolTable[scopeLevel][i].type], 
        symbolTable[scopeLevel][i].symbol->addr,
        symbolTable[scopeLevel][i].symbol->lineno,
        symbolTable[scopeLevel][i].symbol->func_sig
        );
    }
    objectIndex[scopeLevel] = -1;
    scopeLevel--;
}


Object* createVariable(ObjectType variableType, char* variableName, int variableFlag) {
    objectIndex[scopeLevel]++;
    symbolTable[scopeLevel][objectIndex[scopeLevel]].symbol->name = variableName;
    symbolTable[scopeLevel][objectIndex[scopeLevel]].symbol->index = objectIndex[scopeLevel];
    symbolTable[scopeLevel][objectIndex[scopeLevel]].symbol->addr = variableAddress;
    symbolTable[scopeLevel][objectIndex[scopeLevel]].symbol->lineno = yylineno;
    symbolTable[scopeLevel][objectIndex[scopeLevel]].symbol->func_sig = strdup("-");
    symbolTable[scopeLevel][objectIndex[scopeLevel]].type = variableType;

    symbolTable[scopeLevel][objectIndex[scopeLevel]].symbol->func_var = variableFlag;
    printf("> Insert `%s` (addr: %d) to scope level %d\n", variableName, variableAddress, scopeLevel);
    variableAddress++;
    return &symbolTable[scopeLevel][objectIndex[scopeLevel]];
}

void defineType(ObjectType VariableType) {
    int level = scopeLevel;
    for (int i=0; i<=objectIndex[level]; i++){
        if(symbolTable[level][i].type == OBJECT_TYPE_UNDEFINED || symbolTable[level][i].type == OBJECT_TYPE_AUTO)
            symbolTable[level][i].type = VariableType;
        }
}

void pushFunParm(ObjectType variableType, char* variableName, int variableFlag) {
    Object* obj = createVariable(variableType, variableName, variableFlag);
    //get function parmater type and concate to function signature funcSig
    if (obj->symbol->func_var & VAR_FLAG_ARRAY) { strcat(funcSig, "["); }
    else if (obj->symbol->func_var & VAR_FLAG_POINTER) { strcat(funcSig, "L"); }
    switch (obj->type) {
        case OBJECT_TYPE_INT:
        strcat(funcSig, "I");
        break;
        case OBJECT_TYPE_FLOAT:
        strcat(funcSig, "F");
        break;
        case OBJECT_TYPE_BOOL:
        strcat(funcSig, "B");
        break;
        case OBJECT_TYPE_STR:
        strcat(funcSig, "Ljava/lang/String;");
        break;
        case OBJECT_TYPE_VOID:
        strcat(funcSig, "V");
        break;
        default:
        break;   
    }
}

void createFunction(ObjectType variableType, char* funcName) {
    objectIndex[scopeLevel]++;
    symbolTable[scopeLevel][objectIndex[scopeLevel]].symbol->name = funcName;
    symbolTable[scopeLevel][objectIndex[scopeLevel]].symbol->index = objectIndex[scopeLevel];
    symbolTable[scopeLevel][objectIndex[scopeLevel]].symbol->addr = -1;
    symbolTable[scopeLevel][objectIndex[scopeLevel]].symbol->lineno = yylineno;
    symbolTable[scopeLevel][objectIndex[scopeLevel]].type = OBJECT_TYPE_FUNCTION;
    symbolTable[scopeLevel][objectIndex[scopeLevel]].returnType = variableType;

    /*
    if(!strcmp(funcName, "main"))
        symbolTable[scopeLevel][objectIndex[scopeLevel]].symbol->func_sig = strdup("([Ljava/lang/String;)I");
    else if(!strcmp(funcName, "check"))
        symbolTable[scopeLevel][objectIndex[scopeLevel]].symbol->func_sig = strdup("(IILjava/lang/String;B)B");
    // printf("%d %d",scopeLevel, objectIndex[scopeLevel]);
    */

    funcObj = &symbolTable[scopeLevel][objectIndex[scopeLevel]]; // use to copy FunctionSignature to object
    strcpy(funcSig, ""); // initialize function signature name
    printf("func: %s\n", funcName);
    printf("> Insert `%s` (addr: %d) to scope level %d\n", funcName, -1, scopeLevel);

    fprintf(yyout, ".method public static %s", funcName);
}

void markFuncSig() {
    strcat(funcSig, ")"); // function parameter type,  func_sig = "parmType)"
    if(strcmp(funcObj->symbol->name, "main") == 0) {
        strcat(funcSig, "V");
    } else { 
        switch (funcObj->returnType) {
        case OBJECT_TYPE_INT:
        strcat(funcSig, "I");
        break;
        case OBJECT_TYPE_FLOAT:
        strcat(funcSig, "F");
        break;
        case OBJECT_TYPE_BOOL:
        strcat(funcSig, "B");
        break;
        case OBJECT_TYPE_STR:
        strcat(funcSig, "Ljava/lang/String;");
        break;
        case OBJECT_TYPE_VOID:
        strcat(funcSig, "V");
        break;
        default:
        break;   
        } // char func_sig = "parmType)returnType"
    }
    strcpy(funcObj->symbol->func_sig, "("); // Obj->func_sig = "("
    strcat(funcObj->symbol->func_sig, funcSig); // Obj->func_sig = "(" + "parmType)returnType"
    
    // funcObj->symbol->func_sig = funcSig;
    fprintf(yyout, "%s\n", funcObj->symbol->func_sig);
    codeRaw(".limit stack 100");
    codeRaw(".limit locals 100");
}

bool objectCast(ObjectType variableType, Object* dest, Object* out) {
    printf("Cast to %s\n", objectTypeName[variableType]);
    return false;
}

Object* findVariable(char* variableName) {
    int level = scopeLevel;
    while(level>=0) {
        for (int i=0; i<=objectIndex[level]; i++){
            if(strcmp(variableName, symbolTable[level][i].symbol->name) == 0)
                return &symbolTable[level][i];
        }
        level--;
    }
    return NULL;
}

void pushFunInParm(Object* variable) {
    stdoutList[stdoutListSize] = *variable;
    //stdoutList[0].type = (*variable).type;
    //printf("%ld\n", variable->type);
    stdoutListSize++;
}

void stdoutPrint() {
    printf("cout");
    for(int i=0; i<stdoutListSize; i++){
        //printf("%ld\n",stdoutList[i].type);
        printf(" %s", objectTypeName[stdoutList[i].type]);
    }
    printf("\n");
    stdoutListSize = 0;
}



int main(int argc, char* argv[]) {
    init();
    char* outputFileName = NULL;
    if (argc == 3) {
        yyin = fopen(yyInputFileName = argv[1], "r");
        yyout = fopen(outputFileName = argv[2], "w");
    } else if (argc == 2) {
        yyin = fopen(yyInputFileName = argv[1], "r");
        yyout = stdout;
    } else {
        printf("require input file");
        exit(1);
    }
    if (!yyin) {
        printf("file `%s` doesn't exists or cannot be opened\n", yyInputFileName);
        exit(1);
    }
    if (!yyout) {
        printf("file `%s` doesn't exists or cannot be opened\n", outputFileName);
        exit(1);
    }

    codeRaw(".class public Main");
    codeRaw(".super java/lang/Object");
    // codeRaw(".method public static main([Ljava/lang/String;)V");
    // codeRaw(".limit stack 100");
    // codeRaw(".limit locals 100");

    scopeLevel = -1;

    yyparse();
    printf("Total lines: %d\n", yylineno);
    fclose(yyin);

    yylex_destroy();
    return 0;
}