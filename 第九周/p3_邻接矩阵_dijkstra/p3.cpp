/*ÿ��Ժ¥¥�׵���󵥳�����Ϊһ��ż�� cmaxcmax �����һ����վ�������г�������ǡ��Ϊ cmax/2����ô�ƴ�������״̬��
���һ��¥�׵������������ģ��� cmax �������߿յģ�û�г������������������ڽ��0�����ͻ�Я�����ߴ�·���ռ�һ
�������ĵ���ǰ����Ժ¥����;�������е�Ժ¥¥�׵ĵ��������ﵽ������
���ڸ��� cmax��Ժ¥������ n������Ժ¥��� sp��m ��Ժ¥֮���Ժ¥�͵�������֮���·��·���������·����
Ժ¥�±��Ǵ�1��ʼ�ģ����0�ǵ���������
1������ж�����·�������ܴ������ٵ����г���Ŀ����������0����������ҪЯ�������ٵģ�ʹ����;���г�վ��������
2������кܶ಻ͬ·����һ����վ���ص����г���Ŀ���ٵģ���;����վ��������״̬����Ҫ�� spsp ��վ������Ŀ���ٵģ�
�����ʽ
��һ�У������������ cmax(<=100)��Ժ¥������ n(<=500)������Ժ¥��� sp��Ժ¥��·������ m
�ڶ��У�n ����վ�����е�����
������ m �У�����Ժ¥���·����
�����ʽ
���Я���ĵ������������·�������صĵ�������*/
#include<iostream>
#include<cmath>
using namespace std;
#define max_size 501
int nodetable[max_size];//�洢������г�����
int node_loc[max_size];
int edge[max_size][max_size] = { 0 };//�ڽӾ���
int dijkstra(int node_cnt, int path[],int sp);
void get_best_route(int node_cnt, int sp);
int get_bike_to(int n, int path[]);//��ô�ȥ������
int get_bike_back(int n, int path[], int bike_to);//��ô��ص�����
int get_min_path(int sp, int path[], int min_path[]);//�õ�·��/���򣬷��ؽ����
int cmax;
int main()
{
	int n, sp, m;
	cin >> cmax >> n >> sp >> m;
	nodetable[0] = -1;//����ͣ�ŵ�ĵ�����
	for (int i = 1; i <= n; i++)
		cin >> nodetable[i];//��Ժ¥ͣ�ŵ�����
	for (int i = 0; i < n+1; i++)
		for (int j = 0; j < n+1; j++)
		{
			if (i != j)
				edge[i][j] = 2147483647;
		}//��ʼ���ڽӾ���
	int start, end, cost;
	for (int i = 0; i < m; i++)
	{
		cin >> start >> end >> cost;
		edge[start][end] = edge[end][start] = cost;
	}//����·����
	get_best_route(n + 1, sp);
	return 0;
}
void get_best_route(int n, int sp)
{
	int path[max_size] = { 0 };
	int min_path[max_size] = { 0 };//�洢���·��������
	int min_dest = dijkstra(n, path, sp);
	int cnt = get_min_path(sp, path, min_path);//�õ�minpath{����}��·���Ͻ����
	int min_bike_to = get_bike_to(cnt, min_path);
	int min_bike_back = get_bike_back(cnt, min_path, min_bike_to);
	int loc = path[sp];
	edge[sp][loc] = edge[loc][sp] = 2147483647;//ɾȥ·������sp�����ı�
	int cur_path[max_size] = { 0 };
	int cur_bike_to = 0, cur_bike_back = 0;
	int cur_cnt;
	while (min_dest == dijkstra(n, path, sp))//���ҵ�·����·��ͬ����
	{
		cur_cnt= get_min_path(sp, path, cur_path);//�õ�minpath{����}��·���Ͻ����
		cur_bike_to = get_bike_to(cur_cnt, cur_path);
		cur_bike_back = get_bike_back(cur_cnt, cur_path, cur_bike_to);
		if (cur_bike_to < min_bike_to)
		{
			for (int i = 0; i < cur_cnt; i++)
				min_path[i] = cur_path[i];
			min_bike_to = cur_bike_to;
			min_bike_back = cur_bike_back;
			cnt = cur_cnt;
		}//�޸�����·��
		else if (cur_bike_back < min_bike_back)
		{
			for (int i = 0; i < cur_cnt; i++)
				min_path[i] = cur_path[i];
			min_bike_to = cur_bike_to;
			min_bike_back = cur_bike_back;
			cnt = cur_cnt;
		}//�޸�����·��
		int loc = path[sp];
		edge[sp][loc] = edge[loc][sp] = 2147483647;//ɾȥ·������sp�����ı�
	}
	cout << min_bike_to << " ";
	for (int i = cnt - 1; i > 0; i--)
		cout << min_path[i] << "->";
	cout << min_path[0] << " ";
	cout << min_bike_back;
}
int dijkstra(int n,int path[], int sp)//����ڵ����
{
	bool S[max_size] = { false };//���·�����㼯
	long int dist[max_size] = { 0 };
	path[0] = -1;
	for (int i = 1; i < n; i++)
	{
		dist[i] = edge[0][i];//��ʼ��dist����
		if (i != 0 && dist[i] < 2147483647)
			path[i] = 0;
		else
			path[i] = -1;
	}
	S[0] = true;
	int min;
	for (int i = 0; i < n - 1; i++)
	{
		min = 2147483647;
		int u = 0;
		for (int j = 0; j < n; j++)
			if (S[j] == false && dist[j] < min)
			{
				u = j;
				min = dist[j];
			}//����С
		S[u] = true;//��u���뼯��S
		for (int k = 0; k < n; k++)
		{
			int w = edge[k][u];
			if (S[k] == false && w < 2147483647 && dist[u] + w < dist[k])
			{
				dist[k] = dist[u] + w;//����
				path[k] = u;
			}
		}
	}
	return dist[sp];
}
int get_bike_to(int cnt, int min_path[])//��ô�ȥ������
{
	int bike_to = 0, cur_bike_to = 0;
	for (int i = cnt - 2; i >= 0; i--)//�ӵ�һ��Ժ¥��ʼ����
	{
		cur_bike_to += cmax / 2 - nodetable[min_path[i]];
		if (cur_bike_to > bike_to)
			bike_to = cur_bike_to;//ȡȫ����Ҫ����������ֵ
	}
	return bike_to;
}
int get_bike_back(int cnt, int min_path[], int bike_to)//��ô��ص�����
{
	int bike_back = bike_to;
	for (int i = cnt - 2; i >= 0; i--)//�ӵ�һ��Ժ¥��ʼ����
		bike_back += -cmax / 2 + nodetable[min_path[i]];//��;���г�������
	return bike_back;
}
int get_min_path(int sp, int path[], int min_path[])//�õ�·��/���򣬷��ؽ����
{
	int cur = sp;
	min_path[0] = sp;
	int cnt = 1;//·���Ͻ����
	while (path[cur] >= 0)
	{
		min_path[cnt] = path[cur];
		cur = path[cur];
		cnt++;
	}//�����ҵ�·���Ͻ��
	return cnt;
}