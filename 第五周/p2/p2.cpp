/*��ǿ����
С���������μ���ǿ���Խ�Ŀ����ε���Ŀ�Ǹ���һ�Ż�ľ��ÿ���ľ�Ͽ���һ���ַ���
�����˸���һ���̶����ַ�������С���������Ż�ľ���ҵ����а��ַ���˳����������еĻ�ľ��
�����ʽ
�������룬��һ��Ϊ���Ż�ľ�������ҵ�����˳�򣬵ڶ�������Ϊ�����˸������ַ�����
�����ʽ
һ����������������г�����Ҫ���������ľ�����еĵ�һ����ľ���ڵ�λ�ã��±��0��ʼ������
δ�ҵ����ϵĽ�������-1��
����Լ��
������Ϊ��ľ�������ַ������ȶ���Ϊ0��
�һ�ľ������С���ַ������ȣ���ͬ��ĸ�Ĵ�Сд����Ϊ��ͬһ�ַ���*/
#include<iostream>
#include<string>
using namespace std;
void get_next(int next[], string target);
int KMP_find(string input, string target, int next[], int start);
int main()
{
	string input, target;
	cin >> input >> target;
	int *next =new int[target.size()];
	get_next(next, target);
	int cnt = 0,res;
	bool n_find = true;
	while (cnt + target.length() <= input.length())//һֱ�ҵ���β
	{
		res = KMP_find(input, target, next, cnt);
		if ((res == -1 && n_find)||res > -1)//��ȫ�Ҳ���ƥ�����ƥ��
			cout << res<<" ";
		if(res>-1)
		{
			n_find = false;//�Ѿ��ҵ�ƥ��
			cnt = res + 1;//���Ϊ��һλ
		}
		else //��ȫ�Ҳ���ƥ��
			break;
	}
	return 0;
 }
void get_next(int next[],string target)//����next[j]
{
	int j = 0, k = -1;
	next[0] = -1;
	while (j < (int)target.length())
	{
		if (k == -1 || target[j] == target[k])
		{
			j++;
			k++;
			next[j] = k;
		}
		else
			k = next[k];
	}
}
int KMP_find(string input, string target, int next[], int start)
{
	int pos = 0;//��target�е��±�
	while (pos < (int)target.length() && start < (int)input.length())//startΪinput���±�
	{
		if (pos==-1 || target[pos] == input[start])
		{
			pos++;
			start++;
		}
		else
			pos = next[pos];//������һλ��
	}//ƥ��ɹ���ɨ����ɺ�����
	if (pos < (int)target.length())
		return -1;//�޷�ƥ��
	else
		return start - pos;//������input�п�ʼ�±�
}