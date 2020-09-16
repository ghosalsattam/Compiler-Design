// parse.h header file for the parser
#ifndef PARSER_H
#define PARSER_H
#define LEN 6
#include "lex.h"
extern token_t token;
typedef struct{
	int len; // length of right-hand side of the rule
	int rule[LEN]; // code sequence of terminals and
	// non-terminals
} rule_t;


int parser();	// returns 1 on success,
							// returns 0 on failure.
#endif
