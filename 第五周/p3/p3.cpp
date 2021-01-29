/*һ�ö���ʥ������һ��ÿ����㶼��������Ķ��������������һ����������
һ�Ը����ĺ��������������п���ȷ��һ��Ψһ�Ķ���ʥ������
���ڣ�С�����ԡ�S�Ͳ�δ�������ķ�ʽһ�ΰ����ﶼ���ߡ�
Ҳ����˵������������ʼ���𼶴�����������Һʹ��ҵ����档
�ָ���һ�ö���ʥ�����ĺ������������������У������С����������������С�
�����ʽ
��һ�и���һ��������N (<= 31)��������ʥ�����еĽڵ��������ڶ��и�������������������У�
�����и����˺�������������С�
�����ʽ
����ÿ���������������С����������������С�һ���е���������֮�������һ���ո�
������β�����ж���Ŀո�*/
#include<iostream>
using namespace std;
struct node
{
	int data;
	int depth;
	struct node* left;
	struct node* right;
};
int num,post_pos;//Ԫ�ظ����������������±�
int queue_head=0;//��ͷָ��
int stack_head = 0;
int in_order[32] = { 0 };
int post_order[32] = { 0 };
node *queue[32];//�洢��α���Ԫ��˳��
int level_num[32] = { 0 };//�洢ÿ��Ԫ�ظ���
int stack[32] = { 0 };//����ջ�����������
void create_tree(int left_bd, int right_bd, struct node* &subtree,int depth);
int post_find_in(int loc);//Ѱ�Һ�����������������е��±�
void push_back(node* val, node* queue[]);//����β��
void push(int val, int stack[]);//ջβ��
int pop(int stack[]);//����ջ��
void visit_tree(struct node* tree);
void print_tree(struct node* tree);//�õ���α������в���¼ÿ��Ԫ�ظ���
void p_tree(struct node* tree)
{
	if (tree != NULL) 
	{
		p_tree(tree->left);
		cout << tree->data << " ";
		p_tree(tree->right);
	}
}
int main()
{
	cin >> num;
	post_pos = num-1;
	for (int i = 0; i < num; i++)
		cin >> in_order[i];
	for (int i = 0; i < num; i++)
		cin >> post_order[i];
	struct node* tree;
	create_tree(0, num - 1, tree,0);
	visit_tree(tree);
	print_tree(tree);
	
	return 0;
}
void create_tree(int left_bd, int right_bd, struct node* &subtree,int depth)//��ǰ�ݹ鵽�������е����������ұ߽�
{
	if (left_bd > right_bd)
		subtree = NULL;//����Ϊ��
	else
	{
		subtree = new struct node;
		subtree->data = post_order[post_pos];//������ʺ���������飬�и���������
		subtree->depth = depth;
		int temp = post_find_in(post_pos);//�ҵ������е�ǰԪ�����������±�
		post_pos--;
		create_tree(temp + 1, right_bd, subtree->right,depth+1);//�ݹ鴴��������
		create_tree(left_bd, temp - 1, subtree->left,depth+1);//�ݹ鴴��������
	}
}
void visit_tree(struct node* tree)//�õ���α������в���¼ÿ��Ԫ�ظ���
{
	if (tree == NULL)
		return;
	int cnt = 0;
	level_num[0] = 1;
	push_back(tree, queue);
	while (queue_head < num)//���������˳�ѭ��
	{
		if (queue[cnt]->left != NULL)
		{
			push_back(queue[cnt]->left, queue);
			level_num[queue[cnt]->left->depth]++;
		}
		if (queue[cnt]->right != NULL)
		{
			push_back(queue[cnt]->right, queue);
			level_num[queue[cnt]->right->depth]++;
		}
		cnt++;
	}
}
void print_tree(struct node* tree)//�õ���α������в���¼ÿ��Ԫ�ظ���
{
	int cnt = 0,queue_pos=0;//�������ұ���һ��queue����
	while (level_num[cnt] != 0)
	{
		if (cnt % 2 == 0)//�����������
		{
			for(int i=0;i<level_num[cnt];i++)
				push(queue[queue_pos++]->data, stack);//�ò�Ԫ�ش���ջ�У�queue_pos+1
			for (int i = 0; i < level_num[cnt]; i++)
				cout << pop(stack)<<" ";
		}
		else//�����������
		{
			for (int i = 0; i < level_num[cnt]; i++)
				cout << queue[queue_pos++]->data << " ";//ֱ�������queue_pos+1
		}
		cnt++;
	}
}
int post_find_in(int loc)//Ѱ�Һ�����������������е��±�
{
	int i;
	for (i = num-1; i >= 0; i--)
		if (in_order[i] == post_order[loc])
			break;
	return i;
}
void push_back(node *val, node* queue[])//����β��
{
	queue[queue_head] = val;
	queue_head = queue_head + 1;
}
void push(int val, int stack[])//ջβ��
{
	stack[stack_head] = val;
	stack_head = stack_head + 1;
}
int pop(int stack[])//����ջ��
{
	stack_head = stack_head-1;
	return stack[stack_head];
}