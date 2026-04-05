/* Definition section */
%{
    #include "compiler_common.h"
    #include "compiler_util.h"
    #include "main.h"

    int yydebug = 1;
    int arrayCount;
%}

/* Variable or self-defined structure */
%union {
    ObjectType var_type;

    bool b_var;
    int i_var;
    float f_var;
    char *s_var;

    Object object_val;
}

/* Token without return */
%token COUT
%token SHR SHL BAN BOR BNT BXO ADD SUB MUL DIV REM NOT GTR LES GEQ LEQ EQL NEQ LAN LOR
%token VAL_ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN REM_ASSIGN BAN_ASSIGN BOR_ASSIGN BXO_ASSIGN SHR_ASSIGN SHL_ASSIGN INC_ASSIGN DEC_ASSIGN
%token IF ELSE FOR WHILE RETURN BREAK CONTINUE

/* Token with return, which need to sepcify type */
%token <var_type> VARIABLE_T
%token <s_var> IDENT
%token <i_var> INT_LIT
%token <f_var> FLOAT_LIT
%token <b_var> BOOL_LIT
%token <s_var> STR_LIT

/* Nonterminal with return, which need to sepcify type */
%type <object_val> Expression 
%type <object_val> ExpHierarchy LORExp LANExp BORExp BXOExp BANExp EQUExp CompareExp ShiftExp AddSubExp MulExp UnaryExp
%type <object_val> DefineVariableStmt AssignStmt FuncCallStmt
%type <object_val> Literal IdentExp

%left ADD SUB
%left MUL DIV REM

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
    : IDENT { createVariable(OBJECT_TYPE_UNDEFINED, $<s_var>1, 0); } /*進入連續變數宣告*/
    | IDENT VAL_ASSIGN Expression { createVariable($3.type, $1, 0); }
    | IDENT '[' Literal ']' { createVariable(OBJECT_TYPE_UNDEFINED, $<s_var>1, VAR_FLAG_ARRAY); }
    | IDENT '[' Literal ']' { arrayCount = 0; } VAL_ASSIGN '{' ExpList '}' { 
        printf("create array: %d\n", arrayCount); createVariable(OBJECT_TYPE_UNDEFINED, $<s_var>1, VAR_FLAG_ARRAY); }
    | IDENT '[' Literal ']' '[' Literal ']' { createVariable(OBJECT_TYPE_UNDEFINED, $<s_var>1, VAR_FLAG_ARRAY); }
;

/* Function */
FunctionDefStmt
    : VARIABLE_T IDENT '(' { createFunction($<var_type>1, $<s_var>2); pushScope();} FunctionParameterStmtList ')' { markFuncSig(); }'{' StmtList '}' { dumpScope(); }
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
    : ';'
    | COUT CoutParmListStmt ';' { stdoutPrint(); }
    | RETURN Expression ';' { printf("RETURN\n"); }
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
    : CoutParmListStmt SHL Expression { pushFunInParm(&$<object_val>3); }
    | SHL Expression { pushFunInParm(&$<object_val>2); }
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
    : IdentExp VAL_ASSIGN Expression { printf("EQL_ASSIGN\n"); }
    | IdentExp ADD_ASSIGN Expression { printf("ADD_ASSIGN\n"); }
    | IdentExp SUB_ASSIGN Expression { printf("SUB_ASSIGN\n"); }
    | IdentExp MUL_ASSIGN Expression { printf("MUL_ASSIGN\n"); }
    | IdentExp DIV_ASSIGN Expression { printf("DIV_ASSIGN\n"); }
    | IdentExp REM_ASSIGN Expression { printf("REM_ASSIGN\n"); }
    | IdentExp SHR_ASSIGN Expression { printf("SHR_ASSIGN\n"); }
    | IdentExp SHL_ASSIGN Expression { printf("SHL_ASSIGN\n"); }
    | IdentExp BAN_ASSIGN Expression { printf("BAN_ASSIGN\n"); }
    | IdentExp BOR_ASSIGN Expression { printf("BOR_ASSIGN\n"); }
    | IdentExp BXO_ASSIGN Expression { printf("BXO_ASSIGN\n"); }
    | IdentExp INC_ASSIGN { printf("INC_ASSIGN\n"); }
    | IdentExp DEC_ASSIGN { printf("DEC_ASSIGN\n"); }
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
    : LORExp LOR LANExp { printf("LOR\n"); $$ = $3; }
    | LANExp { $$ = $1; }
;

LANExp
    : LANExp LAN BORExp { printf("LAN\n"); $$ = $3; }
    | BORExp { $$ = $1; }
;

BORExp 
    : BORExp BOR BXOExp { printf("BOR\n"); $$ = $3; }
    | BXOExp { $$ = $1; }
;

BXOExp
    : BXOExp BXO BANExp { printf("BXO\n"); $$ = $3; }
    | BANExp { $$ = $1; }
;

BANExp
    : BANExp BAN EQUExp { printf("BAN\n"); $$ = $3; }
    | EQUExp { $$ = $1; }
;

EQUExp
    : EQUExp EQL CompareExp { printf("EQL\n"); $$ = $3; }
    | EQUExp NEQ CompareExp { printf("NEQ\n"); $$ = $3; }
    | CompareExp { $$ = $1; }
;

CompareExp
    : CompareExp GTR ShiftExp { printf("GTR\n"); $$ = $3; }
    | CompareExp LES ShiftExp { printf("LES\n"); $$ = $3; }
    | CompareExp GEQ ShiftExp { printf("GEQ\n"); $$ = $3; }
    | CompareExp LEQ ShiftExp { printf("LEQ\n"); $$ = $3; }
    | ShiftExp { $$ = $1; }
;

ShiftExp 
    : ShiftExp SHR AddSubExp { printf("SHR\n"); $$ = $3; }
    | AddSubExp { $$ = $1; }
;

AddSubExp
    : AddSubExp ADD MulExp { printf("ADD\n"); $$ = $3; }
    | AddSubExp SUB MulExp { printf("SUB\n"); $$ = $3; }
    | MulExp { $$ = $1; }
;

MulExp 
    : MulExp MUL UnaryExp { printf("MUL\n"); $$ = $3; }
    | MulExp DIV UnaryExp { printf("DIV\n"); $$ = $3; }
    | MulExp REM UnaryExp { printf("REM\n"); $$ = $3; }
    | UnaryExp { $$ = $1; }
;

UnaryExp 
    : NOT UnaryExp { printf("NOT\n"); $$ = $2; }
    | BNT UnaryExp { printf("BNT\n"); $$ = $2; }
    | SUB UnaryExp { printf("NEG\n"); $$ = $2; }
    | '(' VARIABLE_T ')' UnaryExp { $$.type = $<var_type>2; objectCast($$.type, NULL, NULL); }
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
    : STR_LIT   { printf("STR_LIT \"%s\"\n", $1); $$.type = OBJECT_TYPE_STR; }
    | INT_LIT   { printf("INT_LIT %d\n", $1); $$.value = $1; $$.type = OBJECT_TYPE_INT; }
    | FLOAT_LIT { printf("FLOAT_LIT %f\n", $1); $$.value = $1; $$.type = OBJECT_TYPE_FLOAT; }
    | BOOL_LIT  { if($1==true) printf("BOOL_LIT TRUE\n"); 
                  else printf("BOOL_LIT FALSE\n"); $$.value = $1;$$.type = OBJECT_TYPE_BOOL; }
    | '(' Expression ')' { $$ = $2; }
    | IdentExp
;

IdentExp
    : IDENT {if(strcmp($<s_var>1, "endl") == 0){ printf("IDENT (name=endl, address=-1)\n");$$.type = OBJECT_TYPE_STR; }
                  else { Object *obj = findVariable($1); printf("IDENT (name=%s, address=%ld)\n", $1, obj->symbol->addr); $$.type = obj->type; } }
    | IDENT '[' Expression ']' { Object *obj = findVariable($1); printf("IDENT (name=%s, address=%ld)\n", $1, obj->symbol->addr); $$.type = obj->type; }
    | IDENT '[' Expression ']' '[' Expression ']' { Object *obj = findVariable($1); printf("IDENT (name=%s, address=%ld)\n", $1, obj->symbol->addr); $$.type = obj->type; }
;

%%
/* C code section */