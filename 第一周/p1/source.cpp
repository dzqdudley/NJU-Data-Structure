//���������Ǹ���������һ��Ϊ���������ڶ���Ϊ������ʵ�ֳ��������������Ľ����
//���ܳ�����ֵ�ϴ�����֣���ʹ���ʵ������ݽṹ�洢���ֲ����㡣
#include<iostream>
using namespace std;
int my_minus(int a[], int b[], int res[], int lenth1, int lenth2);//a-b
int compare(int a[], int b[], int lenth1, int lenth2);//�Ƚϴ�С��a>b����1��a=b����0��a<b����-1
int main()
{
	int  a[301] = { 0 }, b[301] = { 0 }, res[301] = { 0 };
	char ch;
	int count1 = 0,count2=0;
	while ((ch = getchar()) != '\n')
	{
		a[count1] = ch-'0';
		count1++;
	}
	while ((ch = getchar()) != '\n')
	{
		b[count2] = ch-'0';
		count2++;
	}
	int sign = my_minus(a, b, res, count1 - 1, count2 - 1);
	if (sign == 0)
		cout << 0;
	else if (sign > 0)
	{
		int zero = 0;//������ʼȫΪ0ʱ�������
		for (int i = 0; i < count1; i++)
		{
			if (res[i] != 0)
				zero = 1;
			if(zero)
			cout << res[i];
		}
	}
	else
	{
		cout << "-";
		int zero = 0;//������ʼȫΪ0ʱ�������
		for (int i = 0; i < count2; i++)
		{
			if (res[i] != 0)
				zero = 1;
			if (zero)
				cout << res[i];
		}
	}
	return 0;
}

int compare(int a[], int b[], int lenth1, int lenth2)//�Ƚϴ�С��a>b����1��a=b����0��a<b����-1
{
	if (lenth1 > lenth2)
		return 1;
	else if (lenth1 < lenth2)
		return -1;
	else
	{
		for (int i = 0; i <= lenth1; i++)
		{
			if (a[i] < b[i])
				return -1;
			else if (a[i] > b[i])
				return 1;
		}
		return 0;
	}
}

int my_minus(int a[ ], int b[ ], int res[ ], int lenth1, int lenth2)//a-b
{
	int sign = compare(a, b, lenth1, lenth2);
	if (sign == 0)//a=b
	{
		res[0] = 0;
		return 0;
	}
	else if (sign == 1)//a>b
	{
		int i, j;
		for (i = lenth1, j = lenth2; j >= 0; i--, j--)//lenth2<=lenth1
		{
			if (a[i] >= b[j])
				res[i] = a[i] - b[j];
			else
			{
				res[i] = 10 + a[i] - b[j];
				a[i - 1] = a[i - 1] - 1;
			}
		}
		if (i >= 0)//lenth1>lenth2
		{
			for (int m = i; m >= 0; m--)
			{
				if (a[m] < 0)//��λ��λ�Ժ󣬻�Ϊ������ӦתΪ����
				{
					a[m] += 9;
					a[m - 1] = a[m - 1] - 1;
				}
				res[m] = a[m];
			}
		}
		return 1;
	}
	else//a<b
	{//��֮ǰ�Ĵ����ϣ�����a��b���ɣ����ʱ���ϸ���
		int i, j;
		for (i = lenth2, j = lenth1; j >= 0; i--, j--)//lenth1<=lenth2
		{
			if (b[i] >= a[j])
				res[i] = b[i] - a[j];
			else
			{
				res[i] = 10 + b[i] - a[j];
				b[i - 1] = b[i - 1] - 1;
			}
		}
		if (i >= 0)//lenth2>lenth1
		{
			for (int m = i; m >= 0; m--)
			{
				if (b[m] < 0)//��λ��λ�Ժ󣬻�Ϊ������ӦתΪ����
				{
					b[m] += 10;
					b[m - 1] = b[m - 1] - 1;
				}
				res[m] = b[m];
			}
		}
		return -1;
	}
}