// parse.h header file for the parser
#ifndef PARSER_H
#define PARSER_H

#include "lex.h"
extern token_t token;
typedef struct node 
{
	char type;                 // I: internal, D: data, R: read
	unsigned int  val;         // for a node of type D
	char op;                   // the operator in node type I
	
	// pointers to left and right subtrees for a node of type I
	struct node *left, *right;
	
} ASTnode_t;

int parser(ASTnode_t **);	// returns 1 on success,
							// returns 0 on failure.
#endif
