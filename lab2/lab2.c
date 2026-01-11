#include <stdio.h>
#include "symtab.h"
#include "optab.h"

int main() {
    printf("--- LAB 2: DATA STRUCTURES SETUP ---\n");

    // 1. TEST SYMBOL TABLE (Dynamic)
    init_symtab();
    printf("\nTesting Symbol Table Insertion...\n");
    insert_symbol("COPY", 0x1000);
    insert_symbol("FIRST", 0x1003);
    insert_symbol("CLOOP", 0x1006);
    
    // Duplicate Check
    if(!insert_symbol("COPY", 0x2000)) printf("Duplicate 'COPY' rejected correctly.\n");

    // Search Check
    int addr = search_symbol("CLOOP");
    if(addr != -1) printf("Found 'CLOOP' at Address: %X\n", addr);
    
    display_symtab();

    // 2. TEST OPCODE TABLE (Static)
    printf("\nTesting Opcode Table Lookup...\n");
    char *mnemonics[] = {"LDA", "STA", "ADD", "XYZ", NULL};
    
    for(int i=0; mnemonics[i] != NULL; i++) {
        char *code = search_optab(mnemonics[i]);
        if(code) printf("%s -> %s\n", mnemonics[i], code);
        else     printf("%s -> Invalid Opcode\n", mnemonics[i]);
    }

    return 0;
}