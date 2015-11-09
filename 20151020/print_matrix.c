/*************************************************************************
	> File Name: print_matrix.c
	> Author: NinthCode
	> Mail: admin@ninthcode.com 
	> Created Time: Tue 20 Oct 2015 11:15:17 PM CST
 ************************************************************************/

#include<stdio.h>
void print_matrix(int i_data[][4],int i_row_size,int i_colume_size);
void print_matrix_circle(int i_data[][4],int i_row_size,int i_colume_size,int i_start);

int main()
{
    int i_data[][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	print_matrix(i_data,4,4);
	return 0;
}

void print_matrix(int i_data[][4],int i_row_size,int i_colume_size)
{
	if(i_data == NULL || i_row_size <= 0 || i_colume_size <= 0)
	{
		return ;
	}
	int i_start = 0;
	while(i_colume_size > (i_start * 2) && i_row_size > (i_start * 2))
	{
		print_matrix_circle(i_data,4,4,i_start);
		++i_start;
	}
	printf("\n");
}
void print_matrix_circle(int i_data[][4],int i_row_size,int i_colume_size,int i_start)
{
	int i_endx = i_colume_size - 1 - i_start;
	int i_endy = i_row_size - 1 - i_start;
	int i_temp;
	for(i_temp = i_start;i_temp <= i_endx;++i_temp)
	{
		printf("%d ",i_data[i_start][i_temp]);
	}

	if(i_start < i_endy)
	{
		for(i_temp = i_start + 1;i_temp <= i_endy;++i_temp)
		{
			printf("%d ",i_data[i_temp][i_endx]);
		}
	}

	if(i_start < i_endx && i_start < i_endy)
	{
		for(i_temp = i_endx - 1;i_temp >= i_start;--i_temp)
		{
			printf("%d ",i_data[i_endy][i_temp]);
		}
	}
	if(i_start < i_endx && i_start < i_endy - 1)
	{
		for(i_temp = i_endy - 1;i_temp >= i_start + 1;--i_temp)
		{
			printf("%d ",i_data[i_temp][i_start]);
		}
	}
}
