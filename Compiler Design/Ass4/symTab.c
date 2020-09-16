#include "symTab.h"
#include<stdio.h>
symRec symTab[SIZE];
void initSymTab()
{
	int i=0;
	
	for(i=0;i<SIZE;i++)
	{
		symTab[i].def='0';
		symTab[i].val=0;
	}
	
}
void updateSymTab(int index, int val)
{
	//printf("%d %d\n",index,val);
	
	symTab[index].val=val;
	symTab[index].def='1';
	//printf("%d\n",SIZE);
	return;
}
int getVal(int index, int *vP)
{
	//printf("getVal\n");
	//printf("%d\n",index);
	if(symTab[index].def=='1')
	{
		*vP=symTab[index].val;
		//printf("%d\n",*vP);
		return 0;
	}
	else
	{
		printf("Not defined variable: %c\n",index+65);
		exit(0);
	}
}
/*int main()
{
	//extern symRec symTab[SIZE];
	printf("%d\n",symTab[0].val);
}*/
