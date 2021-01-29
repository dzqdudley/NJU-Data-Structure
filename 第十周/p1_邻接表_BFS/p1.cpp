/*Ϊ�˺����й���ͳ�Ļ����ḻ�����ǵ�ҵ�����ĳС�������ٰ�һ��Χ����������С���ľ���ܶ඼��ϲ����Χ�壬
����ƽʱҲ����Լ���壬����һ��������˶ԶԷ���Χ�幦�׶����˽⡣Ϊ������Ȥζ�ԣ������Ƿ�ӳ��
�ܷ�����Ҫ��ƽʱ����һ����������ڵ�һ�ֱ���ʱ��������
���ŵ�������ĸ��ӵ����ѹ�ϵ������췽ͷ���ˣ������ҵ����㣬�������æ���������⡣
����췽׼�����������˷�Ϊ���飨�����������Բ�ͬ������һ�ֱ���ʱ�������ڽ��ж��ģ�
���췽������֪�����ܷ񽫲�����Ա��Ϊ����������˵Ҫ������飨����ƽʱ����һ��������˷��ڲ�ͬ�飩��
�����ʽ
��һ���������������ֱ��ǲ���ѡ������ N���Լ�һ������ M���� 0 < N ��M < INT_MAX ��
������ M �У�ÿ�о����������� x��y�����Ǵ����Ӧ��� x��y �����������������ѣ���ƽʱ����һ��������ˣ���
( N �������ߵı�Ŷ�ӦΪ 0 ~ N-1���ʶ���0 <= x��y <= N-1 )
�����ʽ
������԰�Ҫ����飬��� Yes��������� No��*/
#include<iostream>
using namespace std;
#define num 100000
struct Edge {
	int dest;
	Edge* next;
	Edge() { dest = -1; next = NULL; }
};//����ͼ�ڽӱ�����Ȩ����ͬ
bool insert_edge(int start, int end);//һ���߲�������ͼ�ڽӱ�
int get_first_neighbor(int v);//��һ���ڽӶ����λ��
int get_next_neighbor(int v, int w);//v���ڽӶ���w�ĵ�һ���ڽӶ����λ��
bool visited[num] = { false };//DFS���Ƿ񱻷��ʹ�
bool BFS(int v);//��v��ʼbreadth��������
struct Edge nodetable[num];//�洢��ͷ
int queue[num] = { 0 };//queue
void enqueue(int val);
int dequeue();
int front = 0, rear = 0;
int N, M;
short color[num] = { 0 };//�Բ�ͬ���еĶ���Ϳɫ
int main()
{
	bool res = true;
	cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		insert_edge(a, b);
	}//��Ϊ���ѣ�����һ����
	for (int i = 0; i < N; i++)
	{
		if (color[i] != 0)
			continue;//������ѱ�Ϳɫ��������
		res = BFS(i);
		if (res == false)
			break;
	}//Ϳɫ���е���ͨ��֧
	if (res)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}
bool insert_edge(int start, int end)//����ͼ�����ڽӱ�
{
	Edge* p = nodetable[start].next;//������ڱ�ͷ��һ�����
	while (p != NULL && p->dest != end)
		p = p->next;
	if (p != NULL)
		return false;
	p = new struct Edge;
	p->dest = end;
	p->next = nodetable[start].next;
	nodetable[start].next = p;//ͷ����start��������
	Edge* q = new struct Edge;
	q->dest = start;
	q->next = nodetable[end].next;
	nodetable[end].next = q;//ͷ����end��������
	return true;
}
int get_first_neighbor(int v)//��һ���ڽӶ����λ��
{
	if (v != -1)
	{
		Edge* p = nodetable[v].next;
		if (p != NULL)
			return p->dest;
	}
	return -1;
}
int get_next_neighbor(int v, int w)//v���ڽӶ���w�ĵ�һ���ڽӶ����λ��
{
	if (v != -1)
	{
		Edge* p = nodetable[v].next;
		while (p != NULL && p->dest != w)
			p = p->next;
		if (p != NULL && p->next != NULL)
			return p->next->dest;
	}
	return -1;
}
bool BFS(int v)//��v��ʼbreadth��������
{
	for (int j = 0; j < N; j++)//NΪ�������
		visited[j] = false;//initialize visited
	visited[v] = true;
	enqueue(v);
	int w, loc;
	while (front != rear)
	{
		loc = dequeue();
		if (color[loc] == 0)//��δͿɫ
			color[loc] = 1;
		w = get_first_neighbor(loc);
		while (w != -1)
		{
			if (color[w] == 0 && color[loc] == 1)
				color[w] = 2;
			else if (color[w] == 0 && color[loc] == 2)
				color[w] = 1;//w��locͿ�ɲ�ͬ��ɫ
			else if (color[w] == color[loc])
				return false;//�����ڵ�ͬɫ�����޷�����
			if (visited[w] == false)
			{
				visited[w] = true;
				enqueue(w);
			}
			w = get_next_neighbor(loc, w);
		}
	}
	return true;
}
void enqueue(int val)
{
	queue[rear] = val;
	rear++;
}
int dequeue()
{
	int val = queue[front];
	front++;
	return val;
}