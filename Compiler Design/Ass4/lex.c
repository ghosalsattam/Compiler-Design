#include "lex.h"
#include<stdio.h>
//string expression="";
extern token_t token;
void getNextToken()
{
	char c;
	int d,nd=0,n,tenMul=1,k;
	//printf("Enter next token\n");
	k=scanf("%c",&c);
	if(k!=EOF)
	{
		if(c>='0'&&c<='9')
		{
			d=(int)c-48;
			scanf("%c",&c);
			while(c>='0'&&c<='9')
			{
				d=d*10+(int) c-48;
				scanf("%c",&c);
			}
			ungetc(c,stdin);
			token.val=d;
			token.tokenClass=NUM;
		}
		else if(((char)c>='A'&&(char)c<='Z')||((char)c>='a'&&(char)c<='z')&&(char)c!='r')
		{
			token.val=(int)c-(int)'A';
			token.tokenClass=ID;
		}
		else
		{
			token.tokenClass=(int)c;
			//printf("%d\n",token.tokenClass);
		}
	}
	else
	{
		token.tokenClass=END;
	}
	//printf("%c\n",c);
}
