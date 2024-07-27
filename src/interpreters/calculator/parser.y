%{
    void yyerror (char *s); /* syntaxcial error */
    int yylex();
    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>

    int symbols[52]; /* store arrays to primitive symbol */
    int symbolVal(char symbol);
    void updateSymbolVal(char symbol, int val);
%}

%union { int num; char id; } /* Yacc definitions */
%start line

%token print
%token exit_command
%token <num> number
%token <id> identifier

%type <num> line exp term /* map to the number */
%type <id> assigment /* map to the identifier */

%%

line        : assigment ';'         {;}
            | exit_command ';'      {exit(EXIT_SUCCESS);}
            | print exp ';'         {printf("Printing %d\n", $2);}
            | line assigment ';'    {;}
            | line print exp ';'    {printf("Printing %d\n", $3);}
            | line exit_command ';' {exit(EXIT_SUCCESS);}
            ;
assigment   : identifier '=' exp    { updateSymbolVal($1, $3); }
            ;
exp         : term                  { $$ = $1; }
            | exp '+' term          { $$ = $1 + $3; }
            | exp '-' term          { $$ = $1 - $3; }
            ;
term        : number                { $$ = $1; }
            | identifier            { $$ = symbolVal($1); }
            ;

%%

int computeSymbolIndex(char token) {
    int idx = -1;
    if(islower(token)) {
        idx = token - 'a' + 26;
    } else if(isupper(token)) {
        idx = token - 'A';
    }
    return idx;
}

int symbolVal(char symbol) {
    int bucket = computeSymbolIndex(symbol);
    return symbols[bucket];
}

void updateSymbolVal(char symbol, int val) {
    int bucket = computeSymbolIndex(symbol);
    symbols[bucket] = val;
}


int main(void) {
    for(int i = 0; i < 52; i++) {
        symbols[i] = 0;
    }
    return yyparse(); // generate by yacc and apply grammar rule
}

void yyerror (char *s) {fprintf (stderr, "%s\n", s);} 