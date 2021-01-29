#include<iostream>
#include<cmath>
using namespace std;
struct Edge {
	int dest;
	Edge* next;
	Edge() { dest= 0; next = NULL; }
};
struct node {
	int val;
	node* left;
	node* right;
	node() { val = 0; left = right = 0; }
};
bool insert(int val, node*& root, node* parent);
bool insert_edge(int start, int end);//һ���߲�������ͼ�ڽӱ�
int get_first_neighbor(int v);//��һ���ڽӶ����λ��
int get_next_neighbor(int v, int w);//v���ڽӶ���w�ĵ�һ���ڽӶ����λ��
struct Edge nodetable[100000];//�洢��ͷ
int input[100000] = { 0 };
int in_deg[100000] = { 0 };
int main()
{
	node* root = new node;
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> input[i];
		insert(input[i], root, 0);
	}
	int res = 0;
	in_deg[input[0]] = 0;
	while (1)
	{
		int flag = 0;
		for (int i = 0; i < num; i++)
		{
			int cnt = 0;
			
			if (in_deg[input[i]] == 0)
			{
				flag = 1;
				in_deg[input[i]] = -1;
				int w = get_first_neighbor(input[i]);
				if (w != -1)
				{
					in_deg[w]--;
					cnt++;
				}
				int k = -1;
				if(w!=-1)
					 k = get_next_neighbor(input[i], w);
				while (w != -1 && k != -1&&in_deg[k]>0)
				{
						in_deg[k]--;
						cnt++;
					k = get_next_neighbor(input[i], w);
				}
				int tmp = 1;
				for (int j = cnt; j >= 1; j--)
					tmp = tmp * j;
				res = res + tmp;
			}
			
		}
		if (flag == 0)
				break;
	}
	cout << res;
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
bool insert(int val, node*& root ,node* parent)
{
	if (root == NULL)
	{
		root = new node;
		root->val = val;
		if (parent != NULL)
		{
			insert_edge(parent->val, val);
			in_deg[val]++;
		}
		return true;
	}
	else if (val < root->val)
	{
		insert(val, root->left, root);
	}
	else if (val > root->val)
	{
		insert(val, root->right, root);
	}
	else
		return false;
}

