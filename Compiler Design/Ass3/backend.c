#include"parser.h"
#include<stdio.h>
int rval=-1;
int sum=0;

int backend(ASTnode_t **tpp)
{
	if((*tpp)!=NULL)
	{
		backend(&(*tpp)->left);
		backend(&(*tpp)->right);
		if((*tpp)->type=='D')
		{
			//printf("%d\n",(*tpp)->val);
			return (*tpp)->val;
		}
		if((*tpp)->type=='R')
		{
			if(rval==-1)
			{
				printf("Enter r:");
				scanf("%d",&rval);
				return rval;
			}
			else
				return rval;
		}
		if((*tpp)->type=='I')
		{
			if((*tpp)->op=='+')
			{
				//printf("%d\n",backend(&(*tpp)->left)+backend(&(*tpp)->right));
				return backend(&(*tpp)->left)+backend(&(*tpp)->right);
			}
			if((*tpp)->op=='*')
			{
				return backend(&(*tpp)->left)*backend(&(*tpp)->right);
			}
		}
		
		
		
	}
}
