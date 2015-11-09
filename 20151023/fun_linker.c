/*************************************************************************
	> File Name: fun_linker.c
	> Author: NinthCode
	> Mail: admin@ninthcode.com 
	> Created Time: Fri 23 Oct 2015 02:13:21 PM CST
 ************************************************************************/

#include<stdio.h>
int get_call_links(unsigned long *records, int nr, unsigned long *usr_provide_bp)
{
	unsigned long *bp;
	int depth=0;
	if (usr_provide_bp!=NULL)
	{
		bp=usr_provide_bp;
	}
	else
	{
#if defined(__i386)
		asm ("movl %%ebp, %0":"=qm"(bp));
#elif defined( __x86_64)
		asm ("movq %%rbp, %0":"=qm"(bp));
#else
#error unsupported arch
#endif
	}				
	while (depth<nr && (*bp)!=0)
	{
		records[depth]=*(bp+1);
		bp=(void*)(*bp);
		depth++;
	}					
	return depth;
}


int f1()
{
	unsigned long calls[100];
	int depth;
	depth=get_call_links(calls, 100, NULL);
	printf("depth=%d\n", depth);
	return 1;
}
int f2()
{
	return f1();
}
int f3()
{
	return f2();
}
int main(int argc,  char *argv[])
{	
	f3();
	return 0;
}
