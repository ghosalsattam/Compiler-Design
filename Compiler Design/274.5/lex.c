#include "lex.h"
#include<stdio.h>
//string expression="";
token_t token;
void getNextToken()
{
	char c;
	int d,nd=0,n,tenMul=1,k;
	//printf("Enter next token\n");
	k=scanf("%c",&c);
	printf("%d\n",k);
	//printf("%d\n",EOF);
	if(k!=EOF)
	{
		if(c>='0'&&c<='9')
		{
			d=(int)c-48;
			
			while(c>='0'&&c<='9'&&(k=scanf("%c",&c))!=EOF)
			{
				d=d*10+(int) c-48;
				//scanf("%c",&c);
			}
			if(k!=EOF)
			{
				ungetc(c,stdin);
				token.val=d;
				token.tokenClass=NUM;
			}
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
/*int main()
{
	getNextToken();
	printf("Token=%d\n",token.tokenClass);
	getNextToken();
	printf("Token=%d\n",token.tokenClass);
}*/

