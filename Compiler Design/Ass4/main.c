#include"symTab.h"
#include"parser.c"
int main()
{
	
	
	//initSymTab();
	extern symRec symTab[SIZE];
	head=NULL;
	initSymTab();
	printf("Enter Expression in brackets:\n");
	int rv=parseExp(&head);
	//printf("%c\n",head->left->op);
	
	int eval;
	
	if(retval==1)
	{
		eval=backend(&head);
		//printf("Backend completed");
		//printf("%d\n",head->right->left->val);
		printf("\nEvaluated Value :%d\n",eval);
	}
	else
		printf("Tree not made for invalid syntax\n");
	
}
