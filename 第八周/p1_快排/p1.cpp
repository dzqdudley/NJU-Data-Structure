/*��Ȼ 5G ���й���½�Ѿ��ռ�������������ѧ�Ÿո�ͨ����������Ҫ�� n ̨���������������һ̨��������Լ�ӵ�ͨ
�����������������һ̨��������ӡ��������ߵļ۸�ȡ���ڳ��ȣ���ͬ����̨�����֮������ӷ��ÿ����ǲ�ͬ�ġ�
����������ѧ�ǳ��С�����ǲ��ò������˸������ӣ���ʱ�򻹻�Գ����ӣ���������Ĳ��߷������ɻ��Ϊѹ��
������ѧ���񴦵����һ�����ݡ���ˣ�У�쵼ϣ���ܵ����ӷ�����ʡ������������̨�����֮�䶼����ͨ��
��������ֱ�ӻ��Ǽ�ӵģ��������̼��������С�ķ��á�
��������
�����һ��Ϊ�������� n, m��2 <= n <= 1e5��2 <= m <= 3e5�������У�n ��ʾ�����������m ��ʾ���Խ�������������
������ m �У�ÿ���������� a, b, c����ʾ�ڻ��� a �ͻ��� b ֮�佨�����ӵķ����� c��
��Ŀ��֤��
һ�����ڿ��е���ͨ����
�������Ի����� a=b �������
������ʾ��
���ܴ����رߣ��� a �� b ֮����ܿ��Խ���������ӣ���Ӧ��ֻ��ע������С�����ӣ�
long long �㶮��*/
#include<iostream>
using namespace std;
struct edge {
	int start;
	int end;
	long int cost;
	edge* next;
	edge() { start = end = 0; cost = 0; next = NULL; }
};
void quick_sort(struct edge edges[], int first,int last);//��������
int split(struct edge edges[], int first, int last);
void merge(int group1, int group2);
int cur_group = 1;
int group[300000] = { 0 };//ÿ���������ڼ���
int group_cnt[30000] = { 0 };//ÿ�����϶������
struct edge edges[300000];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> edges[i].start >> edges[i].end >> edges[i].cost;
	quick_sort(edges,0,m-1);
	int count = 1;
	long long int total_cost = 0;
	int cnt = -1;
	while (count < n)//���n-1����
	{
		cnt++;
		if (group[edges[cnt].start] == 0 && group[edges[cnt].end] == 0)//������һ������
		{
			total_cost += edges[cnt].cost;
			group[edges[cnt].start] = group[edges[cnt].end] = cur_group;
			group_cnt[cur_group] += 2;
			cur_group++;
			count++;
			continue;
		}
		if (group[edges[cnt].start] == 0 && group[edges[cnt].end] != 0)//����end�ļ���
		{
			total_cost += edges[cnt].cost;
			group[edges[cnt].start] = group[edges[cnt]. end];
			group_cnt[group[edges[cnt].start]] ++;
			count++;
			continue;
		}
		if (group[edges[cnt].start] != 0 && group[edges[cnt].end] == 0)//����start�ļ���
		{
			total_cost += edges[cnt].cost;
			group[edges[cnt].end] = group[edges[cnt].start];
			group_cnt[group[edges[cnt].start]] ++;
			count++;
			continue;
		}
		if (group[edges[cnt].start] != 0 && group[edges[cnt].end] != 0 && group[edges[cnt].start] != group[edges[cnt].end])//�ϲ���������
		{
			total_cost += edges[cnt].cost;
			merge(group[edges[cnt].end], group[edges[cnt].start]);
			count++;
			continue;
		}
	}
	cout << total_cost;
	return 0;
}
void quick_sort(struct edge edges[], int first, int last)//��������
{
	if (first < last)
	{
		int split_point = split(edges, first, last);
		quick_sort(edges, first, split_point - 1);
		quick_sort(edges, split_point+1, last);
	}
}
int split(struct edge edges[], int first, int last)
{
	struct edge pivot = edges[first];
	int split_point = first;
	for (int unknown = first + 1; unknown <= last; unknown++)
	{
		if (edges[unknown].cost < pivot.cost)
		{
			split_point++;
			struct edge temp = edges[split_point];
			edges[split_point] = edges[unknown];
			edges[unknown] = temp;
		}
	}
	edges[first] = edges[split_point];
	edges[split_point] = pivot;
	return split_point;
}
void merge(int group1, int group2)
{
	if (group_cnt[group1] < group_cnt[group2])
	{
		int temp = group2;
		group2 = group1;
		group1 = temp;
	}//group1Ϊ����ļ���
	int all_cnt = group_cnt[group2];
	int cur_cnt = 0;
	for (int i=1;cur_cnt != all_cnt;i++)
	{
		if (group[i] == group2)
		{
			group[i] = group1;
			group_cnt[group1]++;
			cur_cnt++;
		}
	}
}
