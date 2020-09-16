#include"parser.c"
int main()
{
	head=NULL;
	printf("Enter Expression in brackets:\n");
	int rv=parseExp(&head);
	
	int eval;
	
	if(retval==1)
	{
		eval=backend(&head);
		printf("\nEvaluated Value :%d\n",eval);
	}
	else
		printf("Tree not made for invalid syntax\n");
	
}
