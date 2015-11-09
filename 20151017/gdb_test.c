#include <stdio.h>
int swap(int *a,int *b);
int main()
{
	int a = 1;
	int b = 2;
	swap(&a,&b);
	printf("a = %d,b = %d\n",a,b);
}
int swap(int *a,int *b)
{
	if(a != b)
	{
		*a = (*a)^(*b);
		*b = (*a)^(*b);
		*a = (*a)^(*b);
	}
	return *a;
}
