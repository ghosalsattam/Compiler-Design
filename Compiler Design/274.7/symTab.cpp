#include<bits/stdc++.h>
#include"symTab.h"

symTabEntry ste[tab_size];
int lastInd;
int search(char id[id_len])
{
	int i;
	cout<<"in search\n";
	for(i=0;i<tab_size;i++)
	{
		if(strcmp(ste[i].id,id)==0)
			return i;
	}
	return -1;
}

int insert(char id[id_len])
{
	cout<<"in insert.............\n";
	strcpy(ste[lastInd].id,id);
	ste[lastInd].type='I';
	ste[lastInd].size=4;
	ste[lastInd].disp=a*lastInd;
	lastInd++;
}

int initialize()
{
	lastInd=0;
}
