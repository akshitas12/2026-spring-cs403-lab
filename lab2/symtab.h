#ifndef SYMTAB_H
#define SYMTAB_H

#define SYMTAB_SIZE 20  // Increased size for Lab 2
#define SYMBOL_LEN 10   

typedef struct {
    char symbol[SYMBOL_LEN];
    int address;        // <--- ADDED: Critical for an Assembler
    int is_occupied;    
} SymNode;

void init_symtab();
int insert_symbol(char *symbol, int address); // Returns 1 on success, 0 on duplicate/full
int search_symbol(char *symbol); // Returns address or -1 if not found
void display_symtab();

#endif