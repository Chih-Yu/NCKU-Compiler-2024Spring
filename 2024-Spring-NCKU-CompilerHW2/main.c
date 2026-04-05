#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"

#define debug printf("%s:%d: ############### debug\n", __FILE__, __LINE__)

#define toupper(_char) (_char - (char)32)

const char* objectTypeName[] = {
    [OBJECT_TYPE_UNDEFINED] = "undefined",
    [OBJECT_TYPE_VOID] = "void",
    [OBJECT_TYPE_INT] = "int",
    [OBJECT_TYPE_FLOAT] = "float",
    [OBJECT_TYPE_BOOL] = "bool",
    [OBJECT_TYPE_STR] = "string",
    [OBJECT_TYPE_FUNCTION] = "function",
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

}

void markFuncSig() {
    strcat(funcSig, ")"); // function parameter type,  func_sig = "parmType)"
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
    strcpy(funcObj->symbol->func_sig, "("); // Obj->func_sig = "("
    strcat(funcObj->symbol->func_sig, funcSig); // Obj->func_sig = "(" + "parmType)returnType"
}

void debugPrintInst(char instc, Object* a, Object* b, Object* out) {
}

bool objectExpression(char op, Object* dest, Object* val, Object* out) {
    return false;
}

bool objectExpBinary(char op, Object* a, Object* b, Object* out) {
    return false;
}

bool objectExpBoolean(char op, Object* a, Object* b, Object* out) {
    return false;
}

bool objectExpAssign(char op, Object* dest, Object* val, Object* out) {
    return false;
}

bool objectValueAssign(Object* dest, Object* val, Object* out) {
    return false;
}

bool objectNotBinaryExpression(Object* dest, Object* out) {
    return false;
}

bool objectNegExpression(Object* dest, Object* out) {
    return false;
}
bool objectNotExpression(Object* dest, Object* out) {
    return false;
}

bool objectIncAssign(Object* a, Object* out) {
    return false;
}

bool objectDecAssign(Object* a, Object* out) {
    return false;
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
    if (argc == 2) {
        yyin = fopen(yyInputFileName = argv[1], "r");
    } else {
        yyin = stdin;
    }
    if (!yyin) {
        printf("file `%s` doesn't exists or cannot be opened\n", yyInputFileName);
        exit(1);
    }

    // Start parsing
    yyparse();
    printf("Total lines: %d\n", yylineno);
    fclose(yyin);

    yylex_destroy();
    return 0;
}
