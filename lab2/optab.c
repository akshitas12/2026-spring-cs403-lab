#include <string.h>
#include "optab.h"

/* Opcode table structure */
typedef struct {
    const char *mnemonic;
    const char *opcode;
} OPTAB;

/* Static OPTAB (read-only, efficient) */
static const OPTAB optab[] = {
    {"ADD",  "18"},
    {"AND",  "40"},
    {"COMP", "28"},
    {"DIV",  "24"},
    {"J",    "3C"},
    {"JEQ",  "30"},
    {"JGT",  "34"},
    {"JLT",  "38"},
    {"JSUB", "48"},
    {"LDA",  "00"},
    {"LDCH", "50"},
    {"LDL",  "08"},
    {"LDX",  "04"},
    {"MUL",  "20"},
    {"OR",   "44"},
    {"RD",   "D8"},
    {"RSUB", "4C"},
    {"STA",  "0C"},
    {"STCH", "54"},
    {"STL",  "14"},
    {"STX",  "10"},
    {"SUB",  "1C"},
    {"TD",   "E0"},
    {"TIX",  "2C"},
    {"WD",   "DC"}
};

#define OPTAB_SIZE (sizeof(optab) / sizeof(optab[0]))

/*
 * Search OPTAB for mnemonic
 * Returns opcode string if found
 * Returns NULL if not found
 */
char* search_optab(char *mnemonic)
{
    for (int i = 0; i < OPTAB_SIZE; i++) {
        if (strcmp(optab[i].mnemonic, mnemonic) == 0) {
            return (char *)optab[i].opcode;
        }
    }
    return NULL;
}
