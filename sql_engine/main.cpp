#include <stdio.h>

extern "C" {
    void yyparse();
    void yy_scan_string(const char*);
    void yylex_destroy();
}

int main() {
    const char* input = "SELECT * FROM Table;";

    // Pass the string to the lexer
    yy_scan_string(input);

    yyparse();

    return 0;
}
