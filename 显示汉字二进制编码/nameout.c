#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int conv(char *);
void anticonv(char *);
int main(void)
{
	int i = 0;
	int oddcnt;
	char name[10][10];
	printf("Please enter the Chinese names(no more than 10).\n");
	printf("There should be a space between the two names.\n");
	printf("After finishing inputting the names, please enter the EOF.\n");
	while (((scanf("%s", name[i])) != 0)&&(i<10))
	{
		i++;
	}
	for (int a = 0; a < i; a++)
	{
		printf("%s", name[a]);	//显示姓名
		oddcnt=conv(name[a]);	//显示姓名汉字对应二进制码，并返回其中“1”的个数
		printf(" ");
		anticonv(name[a]);		//显示姓名汉字对应二进制码反码
		printf(" ");
		if (oddcnt % 2 == 1)	//奇校验
			printf("0");
		else
			printf("1");
		printf("\n\n");
	}
	
	system("pause");
	return 0;
}

//汉字转化成二进制码
int conv(char c[])
{
	char d[10];		//避免对原name[]进行数据操作
	strcpy(d, c);
	char ch[9] = { '\0' };
	int i;
	int j = 0;
	int count = 0;
	int oddcnt = 0;
	
	while ('\0' != d[j])
	{
		for (i = 7; i >= 0; i--)
		{
			ch[i] = (d[j] & 1) + '0';
			if (ch[i] == '1')
				oddcnt++;
			//右移
			d[j] >>= 1;
		}
		printf("%s", ch);
		j++;
	}	
	
	return oddcnt;
}

//汉字转化成二进制反码
void anticonv(char *c)
{
	char e[10];		//避免对原name[]进行数据操作
	strcpy(e, c);
	char ch[9] = { '\0' };
	char anti_ch[9] = { '\0' };
	int i;
	int j = 0;
	int count = 0;
	while ('\0' != e[j])
	{
		for (i = 7; i >= 0; i--)
		{
			ch[i] = (e[j] & 1) + '0';
			//将字符0和字符1“取反”
			if (ch[i] == '0')
				anti_ch[i] = '1';
			else if (ch[i] == '1')
				anti_ch[i] = '0';
			//右移
			e[j] >>= 1;
		}
		printf("%s", anti_ch);
		j++;
	}
}