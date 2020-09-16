#include"parser.c"

int main()
{
	formRules(rules);
	formParseTable(P);
	//printf("Formed Table\n");
	int i,j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<10;j++)
			printf("%d\t",P[i][j]);
		printf("\n");
	}
	if(parseExp(P)==1)
		printf("Accepted\n");
	else
		printf("Rejected\n");
}

