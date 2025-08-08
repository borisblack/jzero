%{
#include "j0.h"
%}

%union {
  struct Tree* t;
}

%token <t> BREAK DOUBLE ELSE FOR IF INT RETURN VOID WHILE
%token <t> IDENTIFIER CLASSNAME CLASS STRING BOOLEAN
%token <t> INTLIT DOUBLELIT STRINGLIT BOOLLIT NULLVAL
%token <t> LESSTHANOREQUAL GREATERTHANOREQUAL
%token <t> ISEQUALTO NOTEQUALTO LOGICALAND LOGICALOR
%token <t> INCREMENT DECREMENT PUBLIC STATIC NEW

%type <t> ClassDecl ClassBody ClassBodyDecls ClassBodyDecl FieldDecl Type Name QualifiedName VarDecls VarDeclarator
%type <t> MethodReturnVal MethodDecl MethodHeader MethodDeclarator FormalParmListOpt FormalParmList FormalParm ConstructorDecl
%type <t> Block BlockStmtsOpt BlockStmt BlockStmts Stmt LocalVarDeclStmt LocalVarDecl
%type <t> Expr ExprOpt ExprStmt StmtExpr BreakStmt ReturnStmt IfThenStmt IfThenElseStmt IfThenElseIfStmt WhileStmt ForInit ForStmt ForUpdate ElseIfSequence ElseIfStmt StmtExprList
%type <t> Primary Literal ArgList ArgListOpt FieldAccess MethodCall UnaryExpr MulExpr AddExpr RelExpr RelOp EqExpr CondAndExpr CondOrExpr Assignment LeftHandSide AssignOp PostFixExpr
%type <t> InstanceCreation ArrayCreation ArrayAccess
%type <t> '-' '!' '<' '>' '=' ';'

%%
ClassDecl: PUBLIC CLASS IDENTIFIER ClassBody {
  $$=node("ClassDecl",1000,2,$3,$4);
  semantic($$);
  gencode($$);
 } ;
ClassBody: '{' ClassBodyDecls '}' { $$=node("ClassBody",1010,1,$2); }
         | '{' '}' { $$=node("ClassBody",1011,0); };
ClassBodyDecls: ClassBodyDecl
| ClassBodyDecls ClassBodyDecl {
  $$=node("ClassBodyDecls",1020,2,$1,$2); };
ClassBodyDecl: FieldDecl | MethodDecl | ConstructorDecl ;
FieldDecl: Type VarDecls ';' {
  $$=node("FieldDecl",1030,2,$1,$2);
  calcType($$);
 };
Type: INT | DOUBLE | BOOLEAN | STRING | Name ;

Name: IDENTIFIER | QualifiedName ;
QualifiedName: Name '.' IDENTIFIER {
  $$=node("QualifiedName",1040,2,$1,$3);};

VarDecls: VarDeclarator | VarDecls ',' VarDeclarator {
  $$=node("VarDecls",1050,2,$1,$3); };
VarDeclarator: IDENTIFIER | VarDeclarator '[' ']' {
  $$=node("VarDeclarator",1060,1,$1); };

MethodReturnVal : Type | VOID ;
MethodDecl: MethodHeader Block {
  $$=node("MethodDecl",1380,2,$1,$2);
 };
MethodHeader: PUBLIC STATIC MethodReturnVal MethodDeclarator {
  $$=node("MethodHeader",1070,2,$3,$4);
  calcType($$);
 };
MethodDeclarator: IDENTIFIER '(' FormalParmListOpt ')' {
  $$=node("MethodDeclarator",1080,2,$1,$3); };

FormalParmListOpt: FormalParmList | {$$=node("FormalParmListOpt",1081,0);};
FormalParmList: FormalParm | FormalParmList ',' FormalParm {
  $$=node("FormalParmList",1090,2,$1,$3); };
FormalParm: Type VarDeclarator {
  $$=node("FormalParm",1100,2,$1,$2);
  calcType($$);
 };

ConstructorDecl: MethodDeclarator Block {
  $$=node("ConstructorDecl",1110,2,$1,$2); };

Block: '{' BlockStmtsOpt '}' {$$=node("Block",1200,1,$2);};
BlockStmtsOpt: BlockStmts | {$$=node("BlockStmtsOpt",1201,0);};
BlockStmts:  BlockStmt | BlockStmts BlockStmt {
  $$=node("BlockStmts",1130,2,$1,$2); };
BlockStmt:   LocalVarDeclStmt | Stmt ;

LocalVarDeclStmt: LocalVarDecl ';' ;
LocalVarDecl: Type VarDecls {
  $$=node("LocalVarDecl",1140,2,$1,$2);
  calcType($$);
 };

Stmt: Block | ';' | ExprStmt | BreakStmt | ReturnStmt
      | IfThenStmt | IfThenElseStmt | IfThenElseIfStmt
      | WhileStmt | ForStmt ;

ExprStmt: StmtExpr ';' ;

StmtExpr: Assignment | MethodCall ;

IfThenStmt: IF '(' Expr ')' Block {
  $$=node("IfThenStmt",1150,2,$3,$5); };
IfThenElseStmt: IF '(' Expr ')' Block ELSE Block {
  $$=node("IfThenElseStmt",1160,3,$3,$5,$7); };
IfThenElseIfStmt: IF '(' Expr ')' Block ElseIfSequence {
  $$=node("IfThenElseIfStmt",1170,3,$3,$5,$6); }
|  IF '(' Expr ')' Block ElseIfSequence ELSE Block {
  $$=node("IfThenElseIfStmt",1171,3,$3,$5,$6,$8); };

ElseIfSequence: ElseIfStmt | ElseIfSequence ElseIfStmt {
  $$=node("ElseIfSequence",1180,2,$1,$2); };
ElseIfStmt: ELSE IfThenStmt {
  $$=node("ElseIfStmt",1190,1,$2); };
WhileStmt: WHILE '(' Expr ')' Stmt {
  $$=node("WhileStmt",1210,2,$3,$5); };

ForStmt: FOR '(' ForInit ';' ExprOpt ';' ForUpdate ')' Block {
  $$=node("ForStmt",1220,4,$3,$5,$7,$9); };
ForInit: StmtExprList | LocalVarDecl | {$$=node("ForInit",1221,0);};
ExprOpt: Expr | {$$=node("ExprOpt",1222,0);};
ForUpdate: StmtExprList | {$$=node("ForUpdate",1223,0);};

StmtExprList: StmtExpr | StmtExprList ',' StmtExpr {
  $$=node("StmtExprList",1230,2,$1,$3); };

BreakStmt: BREAK ';' | BREAK IDENTIFIER ';' {
  $$=node("BreakStmt",1240,1,$2); };
ReturnStmt: RETURN ExprOpt ';' {
  $$=node("ReturnStmt",1250,1,$2); };

Primary:  Literal | FieldAccess | MethodCall | ArrayAccess |
         '(' Expr ')' { $$=$2;} | ArrayCreation | InstanceCreation;
InstanceCreation: NEW Name '(' ArgListOpt ')' {
  $$=node("InstanceCreation", 1261, 2, $2, $4); };
ArrayCreation: NEW Type '[' Expr ']' {
  $$=node("ArrayCreation", 1260, 2, $2, $4); };
Literal: INTLIT	| DOUBLELIT | BOOLLIT | STRINGLIT | NULLVAL ;

ArgList: Expr | ArgList ',' Expr {
  $$=node("ArgList",1270,2,$1,$3); };
FieldAccess: Primary '.' IDENTIFIER {
  $$=node("FieldAccess",1280,2,$1,$3); };

ArgListOpt:  ArgList | {$$=node("ArgListOpt",1281,0);};
MethodCall: Name '(' ArgListOpt ')' {
  $$=node("MethodCall",1290,2,$1,$3); }
  | Primary '.' IDENTIFIER '(' ArgListOpt ')' {
    $$=node("MethodCall",1291,3,$1,$3,$5); }
	;

PostFixExpr: Primary | Name ;
UnaryExpr:  '-' UnaryExpr {
  $$=node("UnaryExpr",1300,2,$1,$2); }
    | '!' UnaryExpr {
  $$=node("UnaryExpr",1301,2,$1,$2); }
    | PostFixExpr ;
MulExpr: UnaryExpr
    | MulExpr '*' UnaryExpr {
      $$=node("MulExpr",1310,2,$1,$3); }
    | MulExpr '/' UnaryExpr {
      $$=node("MulExpr",1311,2,$1,$3); }
    | MulExpr '%' UnaryExpr {
      $$=node("MulExpr",1312,2,$1,$3); };
AddExpr: MulExpr
    | AddExpr '+' MulExpr {
      $$=node("AddExpr",1320,2,$1,$3); }
    | AddExpr '-' MulExpr {
      $$=node("AddExpr",1321,2,$1,$3); };
RelOp: LESSTHANOREQUAL | GREATERTHANOREQUAL | '<' | '>' ;
RelExpr: AddExpr | RelExpr RelOp AddExpr {
  $$=node("RelExpr",1330,3,$1,$2,$3); };

EqExpr: RelExpr
    | EqExpr ISEQUALTO RelExpr {
  $$=node("EqExpr",1340,2,$1,$3); }
| EqExpr NOTEQUALTO RelExpr {
  $$=node("EqExpr",1341,2,$1,$3); };
CondAndExpr: EqExpr | CondAndExpr LOGICALAND EqExpr {
  $$=node("CondAndExpr", 1350, 2, $1, $3); };
CondOrExpr: CondAndExpr | CondOrExpr LOGICALOR CondAndExpr {
  $$=node("CondOrExpr", 1360, 2, $1, $3); };

ArrayAccess: Name '[' Expr ']' { $$=node("ArrayAccess",1390,2, $1,$3); };

Expr: CondOrExpr | Assignment ;
Assignment: LeftHandSide AssignOp Expr {
  $$=node("Assignment",1370, 3, $1, $2, $3); };
LeftHandSide: Name | FieldAccess | ArrayAccess ;
AssignOp: '=' | INCREMENT | DECREMENT ;
%%

const char* token_Name(int t) {
    return yysymbol_name(YYTRANSLATE(t));
}