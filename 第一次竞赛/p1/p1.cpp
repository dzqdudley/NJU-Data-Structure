/*���ǿ�����򵥵�һ���ı�ѹ����������������ͬ���ַ���ɵ�һ��������Ƭ�Σ�
������ַ���Ƭ���и��ַ��ĸ�������ʾ������ ccccc ���� 5c ����ʾ������ַ�û���ظ���
��ԭ����������� aba ѹ������Ȼ�� aba��
������Ҫ�����ѹ����Ҫ�󣬶Ը����ַ������д����������Ǽ򵥵ؼ���ԭʼ�ַ�������ȫ
��СдӢ����ĸ��ɵķǿ��ַ�����
�����ʽ
�����һ�и�����Ҫ��ѹ�����ѹ�Ĳ����� 1000 ���ַ����ַ�����
�����ʽ
��һ�������ѹ������ַ�����*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int num = 1;
	char input, cur;
	cur = '0';
	while ((input = getchar()) != '\n')
	{
		if (cur == '0')
			cur = input;
		else if (cur == input)
			num++;
		else if (cur != input)
		{
			if (num > 1)
				cout << num;
			cout <<cur;
			num = 1;
			cur = input;
		}
	}
	if (num > 1)//������һ�������Ԫ��ѹ�����ֵ
		cout << num;
	cout << cur;
	return 0;
}