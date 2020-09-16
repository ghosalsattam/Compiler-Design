/* Name : Sattam Ghosal
   Roll No : 17076
   Reg No : 274
*/

#include<bits/stdc++.h>
#include<elf.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <sstream>
using namespace std;
int main(int c,char *v[])
{
	if(c<2)
	{
		cout<<"Error"<<"\n";
		return 0;
	}
	
	
		int fp=open(v[1],O_RDONLY);
		int si,n,fact;
		Elf64_Ehdr *elfhP;
		si=sysconf(_SC_PAGE_SIZE);
		
		elfhP=(Elf64_Ehdr *)mmap(0,si,PROT_EXEC,MAP_PRIVATE,fp,0);
		int size,off,ind;
		//printf("%d\n",elfhP->e_ehsize);
		size=elfhP->e_shentsize;//size
		off=elfhP->e_shoff;//offset
		ind=elfhP->e_shstrndx;//index of str table header
		
		int name;
		Elf64_Shdr *shdr=(Elf64_Shdr *)((char *)elfhP+off);
		Elf64_Shdr *i;
		//printf("%d\n",l);
		char *shstP=(char *)elfhP+off+size*ind;
		shstP=(char *)elfhP+((Elf64_Shdr *)shstP)->sh_offset;
		char *textP;
		
		for(i=shdr;i<shdr+elfhP->e_shnum;i++)
		{
			name=i->sh_name;
			//compare with text
			if(shstP[name]=='.'&&shstP[name+1]=='t'&&shstP[name+2]=='e'&&shstP[name+3]=='x'&&shstP[name+4]=='t'&&shstP[name+5]=='\0')
			{
				//printf("In If\n");
				
				textP=((char *)elfhP+ i->sh_offset);
				break;
			}
		}
		//printf("%lld",elfhP);
		int (*funP)(int);
		
// other code
		cout << "Enter a +ve integer: " ;
		cin >> n ;
		funP = (int (*)(int))textP; // Pointer to .text
		int sq = (*funP)(n);
		cout<<sq<<"\n";
		
	
}
