/*С�������Ծ����ն�
Ϊ��Ӧ�����п��ԣ���������������С������ϰ��������ͨ�������س��Ծ�����С����������ϰ�ķ�����
���˽�С������֪ʶ�����������С������Ա���֪ʶ�㹮��ѧϰ��
���ȣ���������С������ϰȥ����Ծ� a �����ţ����������Ծ� a Ϊģ�壬�޸�������Ŀ��
�����������Ծ�0 �� �Ծ����� �� 2��������С�������Ծ���ϰ��
ÿ��С��������һ���Ծ������������Ը��Ծ�Ϊģ�壬���������¾�������С������ϰ
��0 �� �Ծ����� �� 2����
����ÿһ���Ծ��������Ծ��Լ��Ը��Ծ�Ϊģ��������Ծ��ƽ���֣���ΪС�����������Ծ��
���նȡ����磬�Ծ� a Ϊ�����Ծ��ģ�壬��ˣ��Ծ� a �����նȣ��������Ծ�ķ����ܺͣ�
�����Ծ�������
��֪�����Ծ�ĵ÷֣������������Ծ��У�С�������նȵ����ֵ���٣�
�����ʽ
�Ծ�����ɹ�ϵ���Կ���һ�ö������������Ծ� a Ϊ���ڵ㡣
��α�������ÿ���Ծ�ĵ÷֡���-1 ��ʾ�޽ڵ㣩
�����ʽ
���������նȣ�������λС����*/
#include<iostream>
#include<iomanip>
using namespace std;
struct node {
	double data;//����
	double average;//ƽ����
	int node_count;//��ǰ����ӽڵ�����������ǰ��㣩
	node* left;
	node* right;
	node* parent;
	node() { data = -1; average = 0; node_count = 1; left = right = parent = NULL; }
};
int tree_size=50000;
node* tree = new node[tree_size];
node** queue = new node * [tree_size];
void init_tree(node*& root);
double get_average(node* root);
void push(node* data);
node* pop();
int front = 0, rear = 0;
double max_ave=0;
void print(node* tree)
{
	if (tree == NULL)
		return;
	cout << tree->average << " ";
	print(tree->left);
	print(tree->right);
}
int main()
{
	int res_loc = -1;
	node* root = NULL;
	init_tree(root);
	get_average(root);
	cout <<fixed<< setprecision(5)<<max_ave;
	return 0;
}
void init_tree(node*& root)
{
	double data=0;
	while (front != rear || (front == 0 && front==rear))
	{
		cin >> data;
		if (data != -1 && root == NULL)
		{
			root = new node;
			root->data = data;
			root->parent = NULL;
			push(root);
			cin >> data;
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
			}//����������Ϊ-1����cur�����ÿգ��������cur���ӣ��������
			cin >> data;
			if (data == -1)
				cur->right = NULL;
			else
			{
				node* right = new node;
				cur->right = right;
				right->data = data;
				right->parent = cur;
				push(right);
			}//����������Ϊ-1����cur�Һ����ÿգ��������cur�Һ��ӣ��Һ������
		}
	}
}
double get_average(node* root)
{
	if (root == NULL)
		return 0;
	else if (root->left == NULL && root->right == NULL)
	{
		root->average = root->data;
		if (root->average > max_ave)
			max_ave = root->average;
		return root->average;
	}
	else if (root->left == NULL && root->right != NULL)
	{
		double right_ave = get_average(root->right);//������ƽ��ֵ
		root->node_count += root->right->node_count;
		root->average = (root->data + right_ave * root->right->node_count) / root->node_count;
		if (root->average > max_ave)
			max_ave = root->average;
		return root->average;
	}//ֻ������Ů������ƽ����
	else if (root->left != NULL && root->right == NULL)
	{
		double left_ave = get_average(root->left);//������ƽ��ֵ
		root->node_count += root->left->node_count;
		root->average = (root->data + left_ave * root->left->node_count) / root->node_count;
		if (root->average > max_ave)
			max_ave = root->average;
		return root->average;
	}//ֻ������Ů������ƽ����
	else if (root->left != NULL && root->right != NULL)
	{
		double right_ave = get_average(root->right);//������ƽ��ֵ
		double left_ave = get_average(root->left);//������ƽ��ֵ
		root->node_count += root->right->node_count+root->left->node_count;
		root->average = (root->data + right_ave * root->right->node_count
			+ left_ave * root->left->node_count) / root->node_count;
		if (root->average > max_ave)
			max_ave = root->average;
		return root->average;
	}//��������Ů������ƽ����
	return 0;
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