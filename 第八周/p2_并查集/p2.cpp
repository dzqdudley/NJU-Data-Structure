/*��һȺС������ÿ��С�����и���ţ����Ϊ�������������κ�����С�����ı�Ż�����ͬ��
����С�����ı������ͬ�Ĺ������������������ 1 ��ʱ��������С������Ϊ���ѡ�
��С���� a �� b �����ѣ��γ�һ��С��������Ȧ��֮���� b �� c ҲΪ���ѣ���ô��ʱ��
������Ȧ����Ϊ 3 ��С�������� a, b, c.
����ӵ�����С������������Ȧ�������ж���С�����أ�
����
��һ��ΪС��������
�ڶ�������Ϊÿ��С�������
���
�����������Ȧ������*/
#include<iostream>
#include<cmath>
using namespace std;
int *ufset;//���鼯
int *dataset;//��������
int *result;//�������
int find(int x);
void weighted_union(int root1, int root2);
int main()
{
	int num;
	cin >> num;
	dataset = new int[num];
	int max_data=0;
	for (int i = 0; i < num; i++)
	{
		cin >> dataset[i];//��������
		if (max_data < dataset[i])
			max_data = dataset[i];
	}
	result = new int[max_data + 1];
	ufset = new int[max_data + 1];
	for (int i = 0; i < max_data + 1; i ++ )
		ufset[i] = -1;//��ʼ�����鼯
	for (int i = 0; i < max_data + 1; i++)
		result[i] = 0;//��ʼ���������
	for (int i = 0; i < num; i++)
	{
		for (int k = 2; k <= sqrt(dataset[i]); k++)
		{
			if (dataset[i] % k == 0)
			{
				 if (find(dataset[i]) != find(k))
					 weighted_union(find(dataset[i]), find(k));
				 if (find(dataset[i]) != find(dataset[i] / k) && find(k) != find(dataset[i] / k))
					 weighted_union(find(dataset[i]) , find(dataset[i] / k));//����������k���Լ�data/k
			}
		}
	}
	int max_cnt = 0;
	int cur;
	for (int i = 0; i < num; i++)
	{
		cur=++result[find(dataset[i])];
		if (max_cnt < cur)
			max_cnt = cur;
	}
	cout << max_cnt;
	return 0;
}
int find(int x)//����
{
	if (ufset[x] < 0)
		return x;
	return find(ufset[x]);
}
void weighted_union(int root1, int root2)//�ϲ������������Ľ��
{
	int temp = ufset[root1] + ufset[root2];
	if (ufset[root1] < ufset[root2])
	{
		ufset[root2] = root1;
		ufset[root1] = temp;
	}
	else
	{
		ufset[root1] = root2;
		ufset[root2] = temp;
	}
}