/*����ʵ�ֵĹ���*/

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

	//��ȡ��������ֵ
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

	//i����ֵ����row����ֵ������������ȡֵΪ0~9
	if (i >= 10)	//i���ֵ����10
	{
		printf("You entered more than ten names!!! We show the first ten names to you.\n");
		i--;
	}
	
	//���������ASCII��
	for (int k = 0; k <= i; k++)
	{
		printf("%s", *(name+k));	//�������
		printf(" ");

		//���ASCII��
		int m = 0;
		int cnt = 0;	//ÿ���������������С�1������
		while (*(*(name+k)+m) != '\0')
		{
			cnt += ascii_to_binary(*(*(name + k) + m));
			m++;
		}
		printf(" ");
		
		//�����������
		while (--m >= 0)
		{
			printf("%c", *(*(name + k) + m));
		}
		printf(" ");

		//���У��λ
		if (cnt % 2 == 0)
			printf("1");
		else
			printf("0");

		printf("\n");
	}

	//ͳ�������������ַ����ִ���
	arraysort(copyName, n);	//��������
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
			//ÿ�����5��ͳ�ƽ��
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

//����ַ�������ASCII��
int ascii_to_binary(char c)
{
	char ch[8] = { '\0' };
	int cnt = 0;
	for (int i = 6; i >= 0; i--)
	{
		*(ch + i) = (c & 1) + '0';
		c >>= 1;
		//ͳ�ơ�1���ĸ���
		if (*(ch+i)=='1')
		{
			cnt++;
		}
	}
	printf("%s", ch);
	return cnt;
}

//һά�����������
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