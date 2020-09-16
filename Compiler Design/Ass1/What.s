#Name-Sattam Ghosal		Roll-39/CSE/17076/274

	.file	"what.c"	# generated from "what.c"
	.text			#text section starts
	.globl	what		#"what" is global and can be accessed from outside the program
	.type	what, @function #declares that what is a function
what:				#what tag, beginning of what function
.LFB0:
	pushq	%rbp		#pushes the value of base pointer register in stack
	movq	%rsp, %rbp	#stores the content of register rsp to rbp
	movq	%rdi, -24(%rbp) #stores the content of rdi at mem location %rbp-24(rdi=data)
	movl	%esi, -28(%rbp)	#store content of %esi at location %(rbp-28) (esi=no)
	movl	$1, -12(%rbp)	#store 1 at %(rbp-12)(i=1)
	jmp	.L2					#jump to L2
.L8:
	movl	-12(%rbp), %eax	#store content of %(rbp-12) at %eax(eax=i)
	cltq					#convert long to quad
	leaq	0(,%rax,4), %rdx#load effective address of %(rax*4) to rdx(rdx=rax*4)
	movq	-24(%rbp), %rax	#store content of%(rbp-24) to %rax(rax=data)
	addq	%rdx, %rax		#add content of %rdx to %rax and store to rax(rax=data[i])
	movl	(%rax), %eax	#store content of %rax to %eax(eax=data[i])
	movl	%eax, -4(%rbp)	#store content of%eax to %(rbp-4)(temp=eax)
	movl	-12(%rbp), %eax	#store content of%(rbp-12) to %eax(eax=i)
	subl	$1, %eax		#decrement eax by 1(eax=eax-1)(i=i-1)
	movl	%eax, -8(%rbp)	#store content of %eax at %(rbp-8)(j=i)
	jmp	.L3					#jump to L3
.L7:	
	movl	-8(%rbp), %eax	#store content of Mem[rbp-8] at %eax(eax=j)
	cltq					#convert long to int
	leaq	0(,%rax,4), %rdx#load address of rax*4 and store to %rdx(rdx=rax*4)
	movq	-24(%rbp), %rax	#$rax=$(rbp-24)(rax=data)
	addq	%rdx, %rax		#add rdx and rax and store to rax register(rax=data[j])
	movl	(%rax), %eax	#eax=rax
	cmpl	%eax, -4(%rbp)	#compare $eax and $(rbp-4)(compare eax and temp)
	jle	.L9					#if($eax<$(rbp-4)),then jump to L9(if eax<temp,jump L9)
	movl	-8(%rbp), %eax	#eax=$(rbp-8)(eax=j)
	cltq					#Change long to int
	leaq	0(,%rax,4), %rdx#load exact address at rdx(rdx=rax*4)
	movq	-24(%rbp), %rax	#rax=Mem[rbp-24](rax=data)
	addq	%rdx, %rax		#rax=rdx+rax
	movl	-8(%rbp), %edx	#edx=Mem[rbp-8](edx=j)
	movslq	%edx, %rdx		#(rdx=edx)
	addq	$1, %rdx		#rdx=rdx+1
	leaq	0(,%rdx,4), %rcx	#load effective address to rcx(rcx=rdx*4)
	movq	-24(%rbp), %rdx		#rdx=Mem[rbp-24](rdx=data)
	addq	%rcx, %rdx			#rdx=rcx+rdx
	movl	(%rax), %eax		#eax=rax
	movl	%eax, (%rdx)		#rdx=eax
	subl	$1, -8(%rbp)		#decrements content at (rbp-8) location of memory(j--)
.L3:
	cmpl	$0, -8(%rbp)	#compare 0 and Mem[rbp-8](0 and j)
	jns	.L7					#jump to L7 if True
	jmp	.L6					#jump to L6
.L9:
	nop						#does nothing
.L6:
	movl	-8(%rbp), %eax	#eax=rbp-8
	cltq					#change long to quad
	addq	$1, %rax		#rax=rax+1
	leaq	0(,%rax,4), %rdx#load address to rdx
	movq	-24(%rbp), %rax	#rax=rbp-24
	addq	%rax, %rdx		#rdx=rdx+rax(rdx=&data[j])
	movl	-4(%rbp), %eax	#eax=Mem[rbp-4](eax=temp)
	movl	%eax, (%rdx)	#rdx=eax(rdx=temp)
	addl	$1, -12(%rbp)	#Mem[rbp-12]++
.L2:
	movl	-12(%rbp), %eax	#eax=Mem[rbp-12](eax=i)
	cmpl	-28(%rbp), %eax	#compare content of %(rbp-28) and eax(compare if no > i)
	jl	.L8					#jump if condition is met L8
	nop
	popq	%rbp	
	ret
.LFE0:
	.size	what, .-what
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
