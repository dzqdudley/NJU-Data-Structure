/*С�������˵��С�����������������ˣ�С������Ҫ���ϻش����������������Ĺ�ͬ���棬
��Ҫע����ǣ�ĳЩ����£�С��˵������������ĳһ���������þ�����һ���˵����档
���ڣ�������ģ��ش�С����������⡣��֪��
С��������涨�����Ǽ�����ÿһ�Է������ֻ�����������ӡ�
Ϊ�˼����⣬������ֻд���˱����ˣ������ǵ��ɷ�/���Ӿ�δ�г����ش�ʱҲֻ��Ҫ�ش��С���ı����˼��ɡ�
С������ϲ����������ˣ����Ա�֤��ÿ���ʳ�������һ������ͬ����һ����С���ļ����ϡ�
С���Ѿ������С�������������˵��������뵽�����ݿ��У�������ֻ��Ҫ����һ�ݼ򻯺���ף�
����ÿ���˶�����һ��Ψһ�������ڼ����б�ʶ�ġ�
�����ʽ
��һ�к͵ڶ������������������������ͬ���� p,q, (0 < p,q < 1024) ��
����������򻯺�ļ��׵Ľڵ���� n ��
������һ�У����ռ򻯼��׵Ĳ�������ķ�ʽ���� n ��������ͬ������ t_i, ( -2 < t_i < 1024; i=1,2,��,n )��
���� -1 ����ýڵ�Ϊ�ա�
�����ʽ
������� p �� q ����Ĺ�ͬ������Ǹ����֡�*/
#include<iostream>
using namespace std;
struct node {
	int data;
	node* left;
	node* right;
	node* parent;
	node() { data = -1; left = right = parent = NULL; }
};
int tree_size;
node* tree=new node[10000];
node** queue = new node*[10000];
void init_tree(node *&root,int p,int q, node* &loc_p, node* &loc_q);
node* find_copar(node* &loc_p, node* &loc_q);
void push(node *data);
node* pop();
int front = 0,rear = 0;
bool p_first = true;//p��qǰ
int main()
{
	int p, q;
	cin>>p >> q>>tree_size;
	node* loc_p=NULL, *loc_q=NULL;//p,q���±�
	int res_loc = -1;
	node* root = NULL;
	init_tree(root,p,q,loc_p,loc_q);
	cout << find_copar(loc_p,loc_q)->data;
	return 0;
}
void init_tree(node*& root, int p, int q, node* &loc_p, node* &loc_q)
{
	int data;
	for (int i = 0; i < tree_size && ((front != rear)||(front==rear)&&front==0); i++)
	{
		cin >>data;
		if (data != -1&&root==NULL)
		{
			root = new node;
			root->data = data;
			root->parent = NULL;
			if (data == p)
				loc_p = root;
			else if (data == q)
				loc_q = root;
			push(root);
			cin >> data;
			i++;
		}//��ʼ����
		if (front != rear)//���в���
		{
			node* cur = pop();
			if (data == -1)
				cur->left = NULL;
			else
			{
				node* left = new node;
				cur->left = left;
				left->data = data;
				left->parent = cur;
				push(left);
				if (data == p)
					loc_p = left;
				else if (data == q)
					loc_q = left;
			}//����������Ϊ-1����cur�����ÿգ��������cur���ӣ��������
			cin >> data;
			i++;
			if (data == -1)
				cur->right = NULL;
			else
			{
				node* right = new node;
				cur->right = right;
				right->data = data;
				right->parent = cur;
				push(right);
				if (data == p)
					loc_p = right;
				else if (data == q)
					loc_q = right;
			}//����������Ϊ-1����cur�Һ����ÿգ��������cur�Һ��ӣ��Һ������
		}
		if (loc_p == NULL && loc_q != NULL && p_first)
			p_first = false;
	}
}
node* find_copar(node* &loc_p, node* &loc_q)
{
	if (p_first)
	{
		node* tmp = loc_p;
		loc_p = loc_q;
		loc_q = tmp;
	}//ȷ��loc_q��Ÿ��������ڵ�Ľڵ�
	while (loc_q != NULL && loc_q->parent != NULL)
	{
		node* tmp = loc_p;
		while (tmp!=NULL && tmp->parent != NULL)
		{
			if (tmp == loc_q)
				return loc_q;
			else
				tmp = tmp->parent;
		}
		loc_q = loc_q->parent;
	}
	return loc_q;
}
void push(node* data)
{
	queue[rear] = data;
	rear++;
}
node* pop()
{
	node* tmp = queue[front];
	front++;
	return tmp;
}