/*程序实现的功能*/

#include <stdio.h>
#include <stdlib.h>

void arraysort(char *, int);
int ascii_to_binary(char);

int main()
{
	char name[10][20] = { '\0' };
	char copyName[200];
	char ch;
	int i = 0, j = 0,n=0;
	int charCnt = 1;

	printf("Please enter names in English input method(no more than 10).\n");
	printf("There should be a comma between the two names.\n");
	printf("After finishing inputting the names, press the Enter.\n");

	//获取输入姓名值
	while (((ch = getchar()) != '\n')&&i<10)
	{
		if (ch != ',')
		{
			*(*(name+i)+j) = ch;
			*(copyName+n) = ch;
			j++;
			n++;
		}
		else
		{
			i++;
			j = 0;
		}
	}	

	//i最终值等于row（行值），本程序中取值为0~9
	if (i >= 10)	//i最大值等于10
	{
		printf("You entered more than ten names!!! We show the first ten names to you.\n");
		i--;
	}
	
	//输出姓名及ASCII码
	for (int k = 0; k <= i; k++)
	{
		printf("%s", *(name+k));	//输出姓名
		printf(" ");

		//输出ASCII码
		int m = 0;
		int cnt = 0;	//每个姓名二进制码中“1”个数
		while (*(*(name+k)+m) != '\0')
		{
			cnt += ascii_to_binary(*(*(name + k) + m));
			m++;
		}
		printf(" ");
		
		//倒序输出姓名
		while (--m >= 0)
		{
			printf("%c", *(*(name + k) + m));
		}
		printf(" ");

		//输出校验位
		if (cnt % 2 == 0)
			printf("1");
		else
			printf("0");

		printf("\n");
	}

	//统计所有姓名中字符出现次数
	arraysort(copyName, n);	//排序数组
	printf("The number of characters in this names is:\n");
	for (int i = 0; i < n; i++)
	{
		static p = 0;

		if (*(copyName + i + 1) == *(copyName + i))
		{
			charCnt++;
		}
		else
		{
			printf("%c %d\t", *(copyName + i),charCnt);
			//每行输出5组统计结果
			p++;
			if (p % 5 == 0)
			{
				printf("\n");
			}
			charCnt = 1;
		}
	}
	printf("\n");

	//system("pause");
	return 0;
}

//输出字符二进制ASCII码
int ascii_to_binary(char c)
{
	char ch[8] = { '\0' };
	int cnt = 0;
	for (int i = 6; i >= 0; i--)
	{
		*(ch + i) = (c & 1) + '0';
		c >>= 1;
		//统计“1”的个数
		if (*(ch+i)=='1')
		{
			cnt++;
		}
	}
	printf("%s", ch);
	return cnt;
}

//一维数组插入排序
void arraysort(char *a,int length)
{
	int i, j, key;
	for (j = 1; j < length; j++)
	{
		key = *(a + j);
		i = j - 1;
		while((i>=0)&&(*(a+i)>key))
		{
			*(a + i + 1) = *(a + i);
			i = i - 1;
			*(a + i + 1) = key;
		}
	}
}