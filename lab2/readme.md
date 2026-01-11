# Lab 2: Symbol Table and Opcode Table

Modify the Symbol Table from Lab 1 to include address (so we know where each symbol points to in memory). 
Additionally, implement an Opcode Table that will be used later to build an assembler.

## Symbol Table
Tells us what the programmer defined.
```C
//symtab.h
#ifndef SYMTAB_H
#define SYMTAB_H

#define SYMTAB_SIZE 20
#define SYMBOL_LEN 10
typedef struct {
    char symbol[SYMBOL_LEN];
    int address;
    int is_occupied;    
} SymNode;

void init_symtab(); // Initializes SymNode SymTab[SYMTAB_SIZE];
int insert_symbol(char *symbol, int address); // Returns 1 on success, 0 on failure.
int search_symbol(char *symbol); // Returns address or -1 if not found
void display_symtab();

#endif
```

Write the implementation of these functions in `symtab.c` and test it in `main.c`.

## Opcode Table
Tells us what the machine knows.
```C
//optab.h
#ifndef OPTAB_H
#define OPTAB_H

#define OPTAB_SIZE 20
#define MNEMONIC_LEN 10
#define MACHINE_CODE_LEN 3
typedef struct {
    char mnemonic[MNEMONIC_LEN];
    char machine_code[MACHINE_CODE_LEN];
} OpNode;

// Hardcoded SIC Standard Opcodes (Partial List)
OpNode OPTAB[] = {
    {"LDA", "00"}, {"LDX", "04"}, {"LDL", "08"},
    {"STA", "0C"}, {"STX", "10"}, {"STL", "14"},
    {"ADD", "18"}, {"SUB", "1C"}, {"MUL", "20"},
    {"DIV", "24"}, {"COMP","28"}, {"TIX", "2C"},
    {"JEQ", "30"}, {"JGT", "34"}, {"JLT", "38"},
    {"J",   "3C"}, {"AND", "40"}, {"OR",  "44"},
    {"JSUB","48"}, {"RSUB","4C"}
};

const int OPTAB_LEN = sizeof(OPTAB)/sizeof(OpNode);

char* search_optab(char *mnemonic); // Returns machine code or NULL if not found

#endif
```

Write the implementation of these functions in `optab.c` and test it in `lab2.c`.

## Sample `main.c`
```C
//lab2.c
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
```

## Compilation and Execution
To compile, use the following `Makefile` and run `make` in the terminal:
```Makefile
lab2: lab2.o symtab.o optab.o
	gcc lab2.o symtab.o optab.o -o lab2

lab2.o: lab2.c symtab.h optab.h
	gcc -c lab2.c

symtab.o: symtab.c symtab.h
	gcc -c symtab.c

optab.o: optab.c optab.h
	gcc -c optab.c

clean:
	rm *.o lab2
```

To execute, run `./lab2` in the terminal.

## Expected Output
```Text
--- LAB 2: DATA STRUCTURES SETUP ---

Testing Symbol Table Insertion...
Duplicate 'COPY' rejected correctly.
Found 'CLOOP' at Address: 1006

[Symbol Table]
Index   Label   Address
(Note: Indices may vary depending on hash calculation)
3       COPY    1000
5       CLOOP   1006
12      FIRST   1003

Testing Opcode Table Lookup...
LDA -> 00
STA -> 0C
ADD -> 18
XYZ -> Invalid Opcode
```