#include"stack.h"
void init(stack *sta)
{
	sta->tos=-1;
}
int push(stack *sta , int data)
{
	if(sta->tos>=1000)
		return -1;
	sta->tos++;
	sta->data[sta->tos]=data;
	
	return 1;
}

int pop(stack *sta)
{
	if(sta->tos==-1)
		return -1;
	int x;
	x=sta->data[sta->tos];
	sta->tos--;
	return x;
}

int top(stack *sta, int *x)
{
	if(sta->tos==-1)
		return -1;
	*x=sta->data[sta->tos];
	return (*x);
}

int isEmpty(stack *sta)
{
	//printf("In isEmpty\n");
	if(sta->tos==-1)
		return -1;
	return 1;
}

int isFull(stack *sta)
{
	if(sta->tos==SIZE)
		return -1;
	return 1;
}

/*int main()
{
	stack sta;
	init(&sta);
	int x,c,i=0,v;
	while(1)
	{
		printf("1 push\n 2 pop\n 3 top\n 4 isempty\n 5 isfull\n");
		scanf("%d",&c);
		if(c==1)
		{
			if(push(&sta,i++)==1)
				printf("pushed %d\n",i-1);
		}
		if(c==2)
		{
			if(v=pop(&sta)!=-1)
				printf("poped %d\n",v);
		}
		if(c==3)
		{
			if(v=top(&sta,&v)!=-1)
				printf("Top=%d\n",v);
			else
				printf("-1\n");
		}
		if(c==4)
		{
			if(isEmpty(&sta)!=-1)
				printf("NotEmpty\n");
			else
				printf("Empty");
		}
		if(c==5)
		{
			if(isFull(&sta))
				printf("NotFull\n");
			else
				printf("Full");
		}
	}
}*/
