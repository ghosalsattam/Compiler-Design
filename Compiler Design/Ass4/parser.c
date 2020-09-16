#include<stdio.h>
#include"parser.h"

#include"backend.c"
#include"lex.c"


//#include"backend.c"

token_t token;
ASTnode_t *head;
int retval=1;
int parseExp(ASTnode_t **tpp)
{
	
	ASTnode_t *ndptr;
	token.tokenClass=-1;
	while(token.tokenClass!=END)
	{
		parser(tpp);
		if((char)(token.tokenClass)==')')
		{
			
			if((*tpp)->left!=NULL && (*tpp)->right!=NULL )
			{
				
				return (1);
			}
			else
				return 0;
		}
		
		
		
		
		if(token.tokenClass==NUM)
		{
			ndptr=(ASTnode_t*)malloc(sizeof(ASTnode_t));
			(ndptr)->left=NULL;
			(ndptr)->right=NULL;
			(ndptr)->type='D';
			
			(ndptr)->val=token.val;
			
			
			if((*tpp)->left==NULL)
				(*tpp)->left=ndptr;
			else if((*tpp)->right==NULL)
			{
				(*tpp)->right=ndptr;
				//return 1;
			}
			else
				return 0;
		}
		
		if((char)(token.tokenClass)=='r')
		{
			ndptr=(ASTnode_t*)malloc(sizeof(ASTnode_t));
			(ndptr)->left=NULL;
			(ndptr)->right=NULL;
			(ndptr)->type='R';
			
			
			
			//getNextToken();
			if((*tpp)->left==NULL)
				(*tpp)->left=ndptr;
			else if((*tpp)->right==NULL)
			{
				(*tpp)->right=ndptr;
				//return 1;
			}
			else 
				return 0;
			
		}
		
//-------------------------------------Change Here--------------------------------------------------
	if(token.tokenClass==258)
	{
		ndptr=(ASTnode_t*)malloc(sizeof(ASTnode_t));
		ndptr->type='V';
		ndptr->val=token.val;
		if((*tpp)->left==NULL)
			(*tpp)->left=ndptr;
		else if((*tpp)->right==NULL)
		{
			(*tpp)->right=ndptr;
			//return 1;
		}
		else 
			return 0;
		
	}
//-------------------------------------Change End---------------------------------------------------
		
		if((char)(token.tokenClass)=='+')
		{
			if((*tpp)->op=='\0')
				(*tpp)->op='+';
			else
				return 0;
			
		}
		if((char)(token.tokenClass)=='*')
		{
			if((*tpp)->op=='\0')
				(*tpp)->op='*';
			else
				return 0;
			
		}
//--------------------------------------Change here-----------------------------------------------
		if((char)(token.tokenClass)=='=')
		{
			if((*tpp)->op=='\0')
				(*tpp)->op='=';
			else
				return 0;
			
		}
		if((char)(token.tokenClass)==',')
		{
			if((*tpp)->op=='\0')
				(*tpp)->op=',';
			else
				return 0;
			
		}

//--------------------------------------Change End------------------------------------------------
		
		
		if((char)(token.tokenClass)=='(')
		{
			
			if(*tpp==NULL)
			{
				*tpp=(ASTnode_t*)malloc(sizeof(ASTnode_t));
				(*tpp)->type='I';
				head=*tpp;
				
				retval=(retval&parseExp(&head));
				
			}
			else
			{
				ndptr=(ASTnode_t*)malloc(sizeof(ASTnode_t));
				ndptr->type='I';
				
				
				
				token.tokenClass=0;
				
				if((*tpp)->left==NULL)
				{
					
					(*tpp)->left=ndptr;
				}
				else if((*tpp)->right==NULL)
				{
					
					(*tpp)->right=ndptr;	
				}
				else
					return 0;
				retval=(retval&parseExp(&ndptr));
				
			}
		}
		
	}
}
int parser(ASTnode_t **tpp)
{
	int rv;
	getNextToken();
}


//----------------------------------------main-----------------------------------------
/*
int main()
{
	head=NULL;
	int rv=parseExp(&head);
	printf("%d\n",head->left->left->val);
}
*/
