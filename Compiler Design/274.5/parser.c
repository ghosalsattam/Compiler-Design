#include"parser.h"
#include"lex.c"
#include"stack.c"
#include<stdio.h>
#define NT_S 0
#define NT_CE 1
#define NT_CED 2
#define NT_AE 3
#define NT_AD 4
#define NT_ME 5
#define NT_PED 6
#define NT_MED 7
#define NT_BE 8
#define T_id 9
#define T_num 10
#define T_r 11
#define T_ast 12
#define T_pl 13
#define T_eq 14
#define T_op 15
#define T_cp 16
#define T_com 17
#define T_eof 18
#define T_eps 19

token_t token;
rule_t rules[20];
int P[10][11];
int T[]={ID,NUM,(int)'r',(int)'*',(int)'+',(int)'=',(int)'(',(int)')',(int)',',END,T_eps};

int extractTerminal(int tok)
{
	if(tok==NUM)
		return T_num;
	if(tok==ID)
		return T_id;
	if(tok==(int)'r')
		return T_r;
	if(tok=='*')
		return T_ast;
	if(tok=='+')
		return T_pl;
	if(tok=='=')
		return T_eq;
	if(tok=='(')
		return T_op;
	if(tok==')')
		return T_cp;
	if(tok==',')
		return T_com;
	if(tok==END)
		return T_eof;
	return T_eps;
}

void formRules(rule_t rules[20])
{
	int i;
	rules[0].len=2;
	rules[0].rule[0]=NT_CE;
	rules[0].rule[1]=T_eof;
	
	rules[1].len=2;
	rules[1].rule[0]=NT_AE;
	rules[1].rule[1]=NT_CED;
	
	rules[2].len=3;
	rules[2].rule[0]=T_com;
	rules[2].rule[1]=NT_AE;
	rules[2].rule[2]=NT_CED;
	
	rules[3].len=1;
	rules[3].rule[0]=T_eps;
	
	rules[4].len=2;
	rules[4].rule[0]=T_id;
	rules[4].rule[1]=NT_AD;
	
	rules[5].len=2;
	rules[5].rule[0]=T_eq;
	rules[5].rule[1]=NT_AE;
	
	rules[6].len=2;
	rules[6].rule[0]=NT_MED;
	rules[6].rule[1]=NT_PED;
	
	rules[7].len=5;
	rules[7].rule[0]=T_op;
	rules[7].rule[1]=NT_CE;
	rules[7].rule[2]=T_cp;
	rules[7].rule[3]=NT_MED;
	rules[7].rule[4]=NT_PED;
	
	rules[8].len=3;
	rules[8].rule[0]=T_num;
	rules[8].rule[1]=NT_MED;
	rules[8].rule[2]=NT_PED;
	
	rules[9].len=3;
	rules[9].rule[0]=T_r;
	rules[9].rule[1]=NT_MED;
	rules[9].rule[2]=NT_PED;
	
	rules[10].len=3;
	rules[10].rule[0]=T_pl;
	rules[10].rule[1]=NT_ME;
	rules[10].rule[2]=NT_PED;
	
	rules[11].len=1;
	rules[11].rule[0]=T_eps;
	
	rules[12].len=2;
	rules[12].rule[0]=NT_BE;
	rules[12].rule[1]=NT_MED;
	
	rules[13].len=3;
	rules[13].rule[0]=T_ast;
	rules[13].rule[1]=NT_BE;
	rules[13].rule[2]=NT_MED;
	
	rules[14].len=3;
	rules[14].rule[0]=T_op;
	rules[14].rule[1]=NT_CE;
	rules[14].rule[2]=T_cp;
	
	rules[15].len=1;
	rules[15].rule[0]=T_id;
	
	rules[16].len=1;
	rules[16].rule[0]=T_num;
	
	rules[17].len=1;
	rules[17].rule[0]=T_r;
	
	rules[18].len=1;
	rules[18].rule[0]=T_eps;
}

void formParseTable(int P[10][11])
{
	int i,j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<10;j++)
		{
			P[i][j]=-1;
		}
	}
	P[0][0]=P[0][1]=P[0][2]=P[0][6]=0;
	P[1][0]=P[1][1]=P[1][2]=P[1][6]=1;
	P[2][7]=P[2][9]=3;
	P[2][8]=2;
	P[3][0]=4;
	P[3][1]=8;
	P[3][2]=9;
	P[3][6]=7;
	P[4][3]=P[4][4]=6;
	P[4][5]=5;
	P[5][0]=P[5][1]=P[5][2]=P[5][6]=12;
	P[6][4]=10;
	P[6][7]=P[6][8]=P[6][9]=11;
	P[7][3]=13;
	P[7][4]=18;
	P[7][7]=P[7][8]=P[7][9]=18;
	P[8][0]=15;
	P[8][1]=16;
	P[8][2]=17;
	P[8][6]=14;
}

int parseExp(int P[10][11])
{
	stack p_s;
	init(&p_s);
	int pr,x,i;
	push(&p_s,NT_S);
	//printf("Pushed %d\n",NT_S);
	getNextToken();
	while(isEmpty(&p_s)==1)
	{
		//printf("Token=%d\n",token.tokenClass);
		//printf("top=%d\n",top(&p_s,&x));
		//printf("Rule=%d\n",P[x][extractTerminal(token.tokenClass)-9]);
		if(top(&p_s,&x)<=8)
		{
			x=pop(&p_s);
			printf("Popped %d\n",x);
			if(P[x][extractTerminal(token.tokenClass)-9]==-1)
				return -1;
			else
			{
				if(rules[P[x][extractTerminal(token.tokenClass)-9]].rule[0]!=T_eps)
					for(i=rules[P[x][extractTerminal(token.tokenClass)-9]].len-1;i>=0;i--)
					{
						
						push(&p_s,rules[P[x][extractTerminal(token.tokenClass)-9]].rule[i]);
						printf("Pushed %d\n",rules[P[x][extractTerminal(token.tokenClass)-9]].rule[i]);
					}
				/*else
				{
					x=pop(&p_s);
					printf("Popped %d\n",x);
				}*/
			}
		}
		else
		{
			if(extractTerminal(token.tokenClass)==top(&p_s,&x))
			{
				x=pop(&p_s);
				printf("popped %d\n",x);
				getNextToken();
			}
			else
				return -1;
		}
	}
	return 1;
}


