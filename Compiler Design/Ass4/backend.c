#include<stdio.h>
#include"symTab.c"
int rval=-1;
int sum=0;


int backend(ASTnode_t **tpp)
{
	if((*tpp)!=NULL)
	{
		if((*tpp)->op!='=')
		{
			backend(&(*tpp)->left);
			backend(&(*tpp)->right);
		}
		else
		{
			backend(&(*tpp)->right);
		}
		if((*tpp)->type=='D')
		{
			
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
		if((*tpp)->type=='V')
		{
			int v=0;
			if(getVal((*tpp)->val,&v)==0)
			{
				//printf("v=%d\n",v);
				return v;
			}
			else
			{ 
				//printf("v=%d\n",v);
				return -1;
			
			}
		}
		if((*tpp)->type=='I')
		{
			if((*tpp)->op=='=')
			{
				if((*tpp)->left!=NULL)
				{
					if((*tpp)->left->type=='V')
					{
						//printf("Inv\n");
						//printf("%d\n",backend(&(*tpp)->right));
						updateSymTab((*tpp)->left->val,backend(&(*tpp)->right));
						//printf("After Update SymTab\n");
						//printf("%c\n",(*tpp)->);
						
						int v,v1;v=-1,v1=(getVal((*tpp)->left->val,&v));
						//printf("%d\n",v1);
						//printf("v1=%d\n",v1);
						if(v1==0)
						{
							//printf("returning v\n");
							return v;
						}
						else
						{
							//printf("returning -1\n");
							return -1;
						}
					}
					else return -1;
				}
				else return -1;
			}
			if((*tpp)->op==',')
			{
				//printf("in,\n");
				return(backend(&(*tpp)->right));
			}
			if((*tpp)->op=='+')
			{
				//printf("%d\n",backend(&(*tpp)->left)+backend(&(*tpp)->right));
				//printf("In+\n");
				return backend(&(*tpp)->left)+backend(&(*tpp)->right);
			}
			if((*tpp)->op=='*')
			{
				//printf("In *\n");
				
				return backend(&(*tpp)->left)*backend(&(*tpp)->right);
			}
		}
		
		
		
	}
}
