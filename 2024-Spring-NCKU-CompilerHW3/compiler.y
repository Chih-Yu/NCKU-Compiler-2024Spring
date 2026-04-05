/* Definition section */
%{
    #include "compiler_util.h"
    #include "main.h"

    int yydebug = 1;
    int arrayCount;

    char* identName;
    char* identNameX;

    bool castFlag = false; // casting flag
%}

/* Variable or self-defined structure */
%union {
    ObjectType var_type;

    bool b_var;
    char c_var;
    int32_t i_var;
    int64_t l_var;
    float f_var;
    double d_var;
    char *s_var;

    Object object_val;

    // LinkList<Object*>
    // LinkedList* array_subscript;
}

/* Token without return */
%token COUT ENDL
%token SHR SHL BAN BOR BNT BXO ADD SUB MUL DIV REM NOT GTR LES GEQ LEQ EQL NEQ LAN LOR
%token VAL_ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN REM_ASSIGN BAN_ASSIGN BOR_ASSIGN BXO_ASSIGN SHR_ASSIGN SHL_ASSIGN INC_ASSIGN DEC_ASSIGN
%token IF ELSE FOR WHILE RETURN BREAK CONTINUE

/* Token with return, which need to sepcify type */
%token <var_type> VARIABLE_T
%token <b_var> BOOL_LIT
%token <c_var> CHAR_LIT
%token <i_var> INT_LIT
%token <f_var> FLOAT_LIT
%token <s_var> STR_LIT
%token <s_var> IDENT

/* Nonterminal with return, which need to sepcify type */
%type <object_val> Expression 
%type <object_val> ExpHierarchy LORExp LANExp BORExp BXOExp BANExp EQUExp CompareExp ShiftExp AddSubExp MulExp UnaryExp
%type <object_val> DefineVariableStmt AssignStmt FuncCallStmt
%type <object_val> Literal IdentExp IdentAssignExp
// %type <array_subscript> ArraySubscriptStmtList

%left ADD SUB
%left MUL DIV REM

%nonassoc THEN
%nonassoc ELSE

/* Yacc will start at this nonterminal */
%start Program

%%
/* Grammar section */

Program
    : { pushScope(); } GlobalStmtList { dumpScope(); }
    | /* Empty file */
;

GlobalStmtList 
    : GlobalStmtList GlobalStmt
    | GlobalStmt
;

GlobalStmt
    : DefineVariableStmt ';'
    | FunctionDefStmt
;

DefineVariableStmt
    : VARIABLE_T DefineVariableList { defineType($1); /* 改type*/ } 
;

DefineVariableList
    : DefineVariableList ',' DefineVariable
    | DefineVariable
;

DefineVariable
    : IDENT { createVariable(OBJECT_TYPE_UNDEFINED, $<s_var>1, 0); codeRaw("ldc 0"); createVariableJ($<s_var>1); } /*進入連續變數宣告*/
    | IDENT VAL_ASSIGN Expression { createVariable($3.type, $1, 0); createVariableJ($1); }
    | IDENT '[' Literal ']' { createVariable(OBJECT_TYPE_UNDEFINED, $<s_var>1, VAR_FLAG_ARRAY); }
    | IDENT '[' Literal ']' { arrayCount = 0; } VAL_ASSIGN '{' ExpList '}' { 
        printf("create array: %d\n", arrayCount); createVariable(OBJECT_TYPE_UNDEFINED, $<s_var>1, VAR_FLAG_ARRAY); }
    | IDENT '[' Literal ']' '[' Literal ']' { createVariable(OBJECT_TYPE_UNDEFINED, $<s_var>1, VAR_FLAG_ARRAY); }
;

/* Function */
FunctionDefStmt
    : VARIABLE_T IDENT '(' { createFunction($<var_type>1, $<s_var>2); pushScope();} 
        FunctionParameterStmtList ')' { markFuncSig(); }
        '{' StmtList '}' { dumpScope(); codeRaw("return"); codeRaw(".end method"); }
;
FunctionParameterStmtList 
    : FunctionParameterStmtList ',' FunctionParameterStmt
    | FunctionParameterStmt
    | /* Empty function parameter */
;
FunctionParameterStmt
    : VARIABLE_T IDENT { pushFunParm($<var_type>1, $<s_var>2, VAR_FLAG_DEFAULT); }
    | VARIABLE_T IDENT '[' ']' { pushFunParm($<var_type>1, $<s_var>2, VAR_FLAG_ARRAY); }
;

/* Scope */
StmtList 
    : StmtList Stmt
    | Stmt
;

Stmt
    : ';' /*{codeRaw("return");}*/
    | COUT CoutParmListStmt ';' { stdoutPrint(); }
    | RETURN Expression ';' { printf("RETURN\n"); /*codeRaw("return");*/ }
    | RETURN ';' { printf("RETURN\n"); }
    | BREAK ';'  { printf("BREAK\n"); }
    | CONTINUE ';'  { printf("CONTINUE\n"); }
    | DefineVariableStmt ';'
    | AssignStmt ';'
    | FuncCallStmt ';'
    | IfStmt 
    | ForStmt
    | WhileStmt
;

CoutParmListStmt
    : CoutParmListStmt SHL ENDL { codeRaw("getstatic java/lang/System/out Ljava/io/PrintStream;"); codeRaw("invokevirtual java/io/PrintStream/println()V"); fprintf(yyout, "\n");}
    | CoutParmListStmt SHL Expression { printExpJ($3.type); pushFunInParm(&$<object_val>3); }
    | SHL Expression { printExpJ($2.type); pushFunInParm(&$<object_val>2); }
;

IfStmt
    : IF '(' Expression ')' { printf("IF\n"); pushScope(); } '{' StmtList '}' { dumpScope(); } ElseStmt
    | IF '(' Expression ')' { printf("IF\n"); } Stmt
;

ElseStmt
    : ELSE { printf("ELSE\n"); pushScope(); } '{' StmtList '}' { dumpScope();}
    | /* Empty else */
;

ForStmt
    : FOR { printf("FOR\n"); pushScope(); } '(' ForInitStmt ')' '{' StmtList '}' { dumpScope(); }
;

ForInitStmt
    : DefineVariableStmt ':' Expression { defineType($3.type); }
    | ForCondStmt ';' Expression ';' ForUpdateStmt

ForCondStmt
    : DefineVariableStmt
    | AssignStmt
    | /* Empty for init */
;

ForUpdateStmt
    : AssignStmt
    | /* Empty for update */
;

WhileStmt
    : WHILE { printf("WHILE\n"); } '(' Expression ')' { pushScope(); } '{' StmtList '}' { dumpScope();}
;

AssignStmt
    : IdentAssignExp VAL_ASSIGN { identNameX = strdup(identName); castFlag = false; } Expression { printf("EQL_ASSIGN\n");
        if (castFlag == true && $1.type == OBJECT_TYPE_INT) codeRaw("f2i"); createVariableJ(identNameX); /* cast operation */}
    | IdentExp ADD_ASSIGN { identNameX = strdup(identName); } Expression { printf("ADD_ASSIGN\n"); if($1.type == OBJECT_TYPE_INT){codeRaw("iadd");}else{codeRaw("fadd");} createVariableJ(identNameX);}
    | IdentExp SUB_ASSIGN { identNameX = strdup(identName); } Expression { printf("SUB_ASSIGN\n"); if($1.type == OBJECT_TYPE_INT){codeRaw("isub");}else{codeRaw("fsub");} createVariableJ(identNameX);}
    | IdentExp MUL_ASSIGN { identNameX = strdup(identName); } Expression { printf("MUL_ASSIGN\n"); if($1.type == OBJECT_TYPE_INT){codeRaw("imul");}else{codeRaw("fmul");} createVariableJ(identNameX);}
    | IdentExp DIV_ASSIGN { identNameX = strdup(identName); } Expression { printf("DIV_ASSIGN\n"); if($1.type == OBJECT_TYPE_INT){codeRaw("idiv");}else{codeRaw("fdiv");} createVariableJ(identNameX);}
    | IdentExp REM_ASSIGN { identNameX = strdup(identName); } Expression { printf("REM_ASSIGN\n"); if($1.type == OBJECT_TYPE_INT){codeRaw("irem");}else{codeRaw("frem");} createVariableJ(identNameX);}
    | IdentExp SHR_ASSIGN { identNameX = strdup(identName); } Expression { printf("SHR_ASSIGN\n"); if($1.type == OBJECT_TYPE_INT){codeRaw("ishr");}else{codeRaw("fshr");} createVariableJ(identNameX);}
    | IdentExp SHL_ASSIGN { identNameX = strdup(identName); } Expression { printf("SHL_ASSIGN\n"); if($1.type == OBJECT_TYPE_INT){codeRaw("ishl");}else{codeRaw("fshl");} createVariableJ(identNameX);}
    | IdentExp BAN_ASSIGN { identNameX = strdup(identName); } Expression { printf("BAN_ASSIGN\n"); if($1.type == OBJECT_TYPE_INT){codeRaw("iand");}else{codeRaw("fand");} createVariableJ(identNameX);}
    | IdentExp BOR_ASSIGN { identNameX = strdup(identName); } Expression { printf("BOR_ASSIGN\n"); if($1.type == OBJECT_TYPE_INT){codeRaw("ior");}else{codeRaw("for");} createVariableJ(identNameX);}
    | IdentExp BXO_ASSIGN { identNameX = strdup(identName); } Expression { printf("BXO_ASSIGN\n"); if($1.type == OBJECT_TYPE_INT){codeRaw("ixor");}else{codeRaw("fxor");} createVariableJ(identNameX);}
    | IdentExp INC_ASSIGN { printf("INC_ASSIGN\n"); if($$.type == OBJECT_TYPE_INT){compareIntJ("INC");}else{compareFloatJ("INC");}}
    | IdentExp DEC_ASSIGN { printf("DEC_ASSIGN\n"); if($$.type == OBJECT_TYPE_INT){compareIntJ("DEC");}else{compareFloatJ("DEC");}}
;

ExpList
    : ExpList ',' Expression { arrayCount++; }
    | Expression { arrayCount++; } 
    | /* Empty Expression List */
;

Expression
    : ExpHierarchy { $$ = $1; }
;

/* Hierachy */
ExpHierarchy
    : LORExp { $$ = $1; }
;

LORExp
    : LORExp LOR LANExp { printf("LOR\n"); $$ = $3; if($$.type == OBJECT_TYPE_INT){codeRaw("ior");}else{codeRaw("ior");}}
    | LANExp { $$ = $1; }
;

LANExp
    : LANExp LAN BORExp { printf("LAN\n"); $$ = $3; if($$.type == OBJECT_TYPE_INT){codeRaw("iand");}else{codeRaw("iand");} }
    | BORExp { $$ = $1; }
;

BORExp 
    : BORExp BOR BXOExp { printf("BOR\n"); $$ = $3; if($$.type == OBJECT_TYPE_INT){codeRaw("ior");}else{codeRaw("ior");}}
    | BXOExp { $$ = $1; }
;

BXOExp
    : BXOExp BXO BANExp { printf("BXO\n"); $$ = $3; if($$.type == OBJECT_TYPE_INT){codeRaw("ixor");}else{codeRaw("ixor");}}
    | BANExp { $$ = $1; }
;

BANExp
    : BANExp BAN EQUExp { printf("BAN\n"); $$ = $3; if($$.type == OBJECT_TYPE_INT){codeRaw("iand");}else{codeRaw("iand");}}
    | EQUExp { $$ = $1; }
;

EQUExp
    : EQUExp EQL CompareExp { printf("EQL\n"); $$ = $3; if($$.type == OBJECT_TYPE_INT){compareIntJ("EQL");}else{compareFloatJ("EQL");}}
    | EQUExp NEQ CompareExp { printf("NEQ\n"); $$ = $3; compareIntJ("NEQ"); }
    | CompareExp { $$ = $1; }
;

CompareExp
    : CompareExp GTR ShiftExp { $$ = $3; if($$.type == OBJECT_TYPE_INT){compareIntJ("GTR");}else{compareFloatJ("GTR");}}
    | CompareExp LES ShiftExp { $$ = $3; if($$.type == OBJECT_TYPE_INT){compareIntJ("LES");}else{compareFloatJ("LES");}}
    | CompareExp GEQ ShiftExp { $$ = $3; if($$.type == OBJECT_TYPE_INT){compareIntJ("GEQ");}else{compareFloatJ("GEQ");}}
    | CompareExp LEQ ShiftExp { $$ = $3; if($$.type == OBJECT_TYPE_INT){compareIntJ("LEQ");}else{compareFloatJ("LEQ");}}
    | ShiftExp { $$ = $1; }
;

ShiftExp 
    : ShiftExp SHR AddSubExp { $$ = $3; if($$.type == OBJECT_TYPE_INT){codeRaw("ishr");}else{codeRaw("fshr");}}
    | AddSubExp { $$ = $1; }
;

AddSubExp
    : AddSubExp ADD MulExp { $$ = $3; if($$.type == OBJECT_TYPE_INT){codeRaw("iadd");}else{codeRaw("fadd");}
                            if ($1.returnType == OBJECT_TYPE_FLOAT || $3.returnType == OBJECT_TYPE_FLOAT) castFlag = true; } 
                            /* use on casting, test case only cast add operation */        
    | AddSubExp SUB MulExp { $$ = $3; if($$.type == OBJECT_TYPE_INT){codeRaw("isub");}else{codeRaw("fsub");}}
    | MulExp { $$ = $1; }
;

MulExp 
    : MulExp MUL UnaryExp { $$ = $3; if($$.type == OBJECT_TYPE_INT){codeRaw("imul");}else{codeRaw("fmul");}}
    | MulExp DIV UnaryExp { $$ = $3; if($$.type == OBJECT_TYPE_INT){codeRaw("idiv");}else{codeRaw("fdiv");}}
    | MulExp REM UnaryExp { $$ = $3; if($$.type == OBJECT_TYPE_INT){codeRaw("irem");}else{codeRaw("frem");}}
    | UnaryExp { $$ = $1; }
;

UnaryExp 
    : NOT UnaryExp { printf("NOT\n"); $$ = $2; if($$.type == OBJECT_TYPE_INT){compareIntJ("NOT");}else{compareFloatJ("NOT");}}
    | BNT UnaryExp { printf("BNT\n"); $$ = $2; if($$.type == OBJECT_TYPE_INT){compareIntJ("NOT");}else{compareFloatJ("NOT");}}
    | SUB UnaryExp { printf("NEG\n"); $$ = $2; if($$.type == OBJECT_TYPE_INT){codeRaw("ineg");}else{codeRaw("fneg");}}
    | '(' VARIABLE_T ')' UnaryExp { $$.type = $<var_type>2; objectCast($$.type, NULL, NULL);
                                    if($<var_type>2==OBJECT_TYPE_INT){codeRaw("f2i");}else{codeRaw("i2f");};
                                    $$.returnType = $<var_type>2; }
    | FuncCallStmt { $$ = $1; }
    | Literal { $$ = $1; } 
;

FuncCallStmt
    : IDENT '(' ExpList ')' {
     Object *obj = findVariable($1); 
     $$.type = obj->returnType;
     printf("IDENT (name=%s, address=%ld)\n", $1, obj->symbol->addr); 
     printf("call: %s%s\n", obj->symbol->name, obj->symbol->func_sig);}
;

Literal
    : STR_LIT   { 
        printf("STR_LIT \"%s\"\n", $1); $$.type = OBJECT_TYPE_STR; code("ldc \"%s\";", $1); }
    | INT_LIT   { printf("INT_LIT %d\n", $1); $$.value = $1; $$.type = OBJECT_TYPE_INT; code("ldc %d", $1);}
    | FLOAT_LIT { printf("FLOAT_LIT %f\n", $1); $$.value = $1; $$.type = OBJECT_TYPE_FLOAT; code("ldc %f", $1); }
    | BOOL_LIT  { if($1==true){ printf("BOOL_LIT TRUE\n"); codeRaw("iconst_1")}
                  else{ printf("BOOL_LIT FALSE\n"); codeRaw("iconst_0")} 
                  $$.value = $1; $$.type = OBJECT_TYPE_BOOL; 
                }
    | CHAR_LIT { $$.type = OBJECT_TYPE_CHAR; code("ldc \"%c\";", $1); }
    | '(' Expression ')' { $$ = $2; }
    | IdentExp
;

IdentExp
    : IDENT {
	     Object *obj = findVariable($1); printf("IDENT (name=%s, address=%ld)\n", $1, obj->symbol->addr); 
         $$.type = obj->type; loadVariableJ($1); identName = strdup($1);
        } 
    | IDENT '[' Expression ']' { Object *obj = findVariable($1); printf("IDENT (name=%s, address=%ld)\n", $1, obj->symbol->addr); $$.type = obj->type; }
    | IDENT '[' Expression ']' '[' Expression ']' { Object *obj = findVariable($1); printf("IDENT (name=%s, address=%ld)\n", $1, obj->symbol->addr); $$.type = obj->type; }
;

IdentAssignExp
: IDENT {
	     Object *obj = findVariable($1); printf("IDENT (name=%s, address=%ld)\n", $1, obj->symbol->addr); 
         $$.type = obj->type; identName = strdup($1); // value assignment don't need to load stack
        } 
    | IDENT '[' Expression ']' { Object *obj = findVariable($1); printf("IDENT (name=%s, address=%ld)\n", $1, obj->symbol->addr); $$.type = obj->type; }
    | IDENT '[' Expression ']' '[' Expression ']' { Object *obj = findVariable($1); printf("IDENT (name=%s, address=%ld)\n", $1, obj->symbol->addr); $$.type = obj->type; }
;

%%
/* C code section */