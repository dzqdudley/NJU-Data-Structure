/*�ڶ�ά�ռ��С����������Ϊ(xMe,yMe)��С������������(xHome,yHome)λ�á�ÿһ����С��������ѡ����㵱ǰ
λ�������������ĸ�����֮һ�ƶ�һ����λ��С������������ʱ���ڻص����ң�����Ƭ��ά�ռ��У���N�Դ����ţ�
ÿһ�Դ�������(xs,ys,xt,yt)����ʽ��������ʾ�㵽��(xs,ys)��Ϳ��Է��������⡱���ܣ�����10���ӵ���(xt,yt)�㣬
�෴��Ҳ���Ի���10���Ӵ�(xt,yt)�㷢�������⡱���ܵ���(xs,ys)�㡣
���ܿ������޶�η�������ֻ������������3�Դ�����֮��ʹ�á�����С���������������ʱ�����롣
�����ʽ
�����һ��N,��ʾ��N�Դ��͵�(N < 200) ������һ�У�������xMe��yMe��xHome��yHome��
��ʾ��ǰ���λ�ú���ҵ�λ�á�
������N�У�ÿ������һ�Դ�����(xs, ys, xt, yt)����������棨0 <= xi, yi <= 10^9��
�����ʽ
�����һ�У�����һ��������ʾ�ؼҵ�������ʱ*/
#include<iostream>
#include<cmath>
using namespace std;
#define max_size 100*100
struct vertice{
	int xs, ys;
	vertice() { xs = ys = 0; }
};//�ڽӱ��ͷ�ṹ
struct vertice nodetable[max_size];//�洢�ڵ�����
int edge[max_size][max_size] = { 0 };//��㡢�յ㡢��������ص����깹��һ����ȫͼ
void init_edges(int node_cnt);//������룬�޸��ڽӾ���
int dijkstra(int node_cnt);//ʹ��dijkstra�㷨�����·��
int main()
{
	int N, xMe, yMe, xHome, yHome;
	cin >> N >> xMe >> yMe >> xHome >> yHome;
	nodetable[1].xs = xMe;
	nodetable[1].ys = yMe;
	nodetable[0].xs = xHome;
	nodetable[0].ys = yHome;
	for (int i = 0; i < 2 * N + 2; i++)
		for (int j = 0; j < 2 * N + 2; j++)//�����2*N+2������
		{
			if (i != j)
				edge[i][j] = 2147483647;
		}//��ʼ���ڽӾ���
	edge[0][1] = edge[1][0] = fabs(xHome - xMe) + fabs(yHome - yMe);//0Ϊ�յ㣬1Ϊ���
	int node_cnt = 0;//��Ч���Ÿ���
	int xs, ys, xt, yt;
	for (int i = 0; i < N; i++)//������
	{
			cin >> xs >> ys >> xt >> yt;
			int pos1, pos2;
			pos1 = 2 + node_cnt;
			nodetable[pos1].xs = xs;
			nodetable[pos1].ys = ys;
			node_cnt++;
			pos2 = 2 + node_cnt;
			nodetable[pos2].xs = xt;
			nodetable[pos2].ys = yt;
			node_cnt++;
			edge[pos1][pos2] = edge[pos2][pos1] = 10;//���ż�cost=10
	}
	init_edges(2+node_cnt);
	cout <<dijkstra(2 + node_cnt);
	return 0;
}
void init_edges(int node_cnt)//������룬�޸��ڽӾ���
{
	int xs, ys, xt, yt;
	for (int i = 0; i < node_cnt; i++)
	{
		xs = nodetable[i].xs;
		ys = nodetable[i].ys;
		for (int j = i + 1; j < node_cnt; j++)
		{
			if (edge[i][j] != 2147483647)
				continue;//�Ѿ��б�����������
			xt = nodetable[j].xs;
			yt = nodetable[j].ys;
			edge[i][j] = edge[j][i] = fabs(xt - xs) + fabs(yt - ys);
		}
	}
}
int dijkstra(int n)//����ڵ����
{
	bool S[max_size] = { false };//���·�����㼯
	long int dist[max_size] = { 0 };
	for (int i = 0; i < n; i++)
		dist[i] = edge[0][i];//��ʼ��dist����
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
				dist[k] = dist[u] + w;//����
		}
	}
	return dist[1];
}
