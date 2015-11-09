/*************************************************************************
	> File Name: turn_string.c
	> Author: NinthCode
	> Mail: admin@ninthcode.com 
	> Created Time: Tue 20 Oct 2015 10:55:41 PM CST
 ************************************************************************/

#include<stdio.h>

void turn_string(char *p_str,int i_len);
int main()
{
	char s_str[] = "abcdefg";
	turn_string(s_str,7);
	printf("%s",s_str);
}
void turn_string(char *p_str,int i_len)
{
	if(p_str == NULL || i_len <= 1)
	{
		return ;
	}
	char c_temp;
	c_temp = p_str[0];
	p_str[0] = p_str[i_len - 1];
	p_str[i_len - 1] = c_temp;
	turn_string(p_str + 1,i_len - 2);
}
