/*��һ����ȫ�������Ĳ����������ӡ���Ӹ��ڵ㵽����Ҷ�ڵ��·������ӡ˳�����Һ���
Ȼ���жϸ����Ǵ󶥶ѡ�С���ѻ��߲��Ƕ�
�����ʽ
��һ�и���һ��������N (1<N��1000)�������еĽڵ�����Ȼ����һ�а���N����ͬ������
(����int��Χ��)������ȫ�������Ĳ���������С�
�����ʽ
����ÿ���������������ȴ�ӡ�Ӹ���Ҷ������·����ÿ��·��ռ��һ�У���������֮����һ���ո����
�����׺���β��û�ж���Ŀո�
·�����밴����˳���ӡ:�������е�ÿ���ڵ㣬���������е�����·���������������е�����·��֮ǰ��ӡ��
����������һ�����ѣ��������Max Heap���������һ����С�ѣ��������Min Heap����
����������Ƕѣ������"Not Heap"��*/
#include<iostream>
using namespace std;
struct bintree {
	int val;
	bintree* left;
	bintree* right;
	bintree* parent;
	bintree() { val = 0; left = NULL; right = NULL; parent = NULL; }
};
bintree* create_tree();
void push_back(bintree* root);
bintree* pop_front();
bintree* queue[1000] = { NULL };
int front = 0;
int rear = 0;
/*void print_tree(bintree* root)
{
	if (root != NULL)
	{
		cout << root->val<<" ";
		print_tree(root->left);
		print_tree(root->right);
	}
}*/
void print_tree(bintree* root);
void get_leaf(bintree* root);//��ȡҶ�ӽ�㲢���
void recursive_print(bintree* leaf);//���õݹ飬�������
bool max_heap = true, min_heap = true;
int main()
{
	bintree* root = create_tree();
	print_tree(root);
	if (max_heap)
		cout << "Max Heap" << endl;
	else if(min_heap)
		cout << "Min Heap" << endl;
	else
		cout << "Not Heap" << endl;
	return 0;
}
bintree* create_tree()
{
	int num,val;
	cin >> num;
	bintree* root=new bintree, *cur;
	for (int i = 0; i < num;)
	{
		if (i == 0)
		{
			cin >> val;
			root->val = val;
			i++;
			push_back(root);
			continue;
		}//��ʼ�����ڵ�
		cin >> val;
		cur = pop_front();//��������
		bintree* left=new bintree;
		cur->left = left;
		left->val = val;//left��val, ����Ϊcur����ڵ�
		left->parent = cur;
		push_back(left);//left����
		i++;
		if (left->val > cur->val && max_heap)
			max_heap = false;
		if (left->val < cur->val && min_heap)
			min_heap = false;//����max min heap���ж�
		if (i == num)
			break;
		cin >> val;
		bintree* right = new bintree;
		cur->right = right;
		right->parent = cur;
		right->val = val;//right��val, ����Ϊcur���ҽڵ�
		if (right->val > cur->val && max_heap)
			max_heap = false;
		if (right->val < cur->val && min_heap)
			min_heap = false;//����max min heap���ж�
		push_back(right);//right����
		i++;
	}
	return root;
}
void print_tree(bintree* root)
{
	front = rear = 0;
	get_leaf(root);
	bintree* cur;
	while (front != rear)
	{
		cur = pop_front();
		recursive_print(cur);
		cout << "\n";
	}
}
void recursive_print(bintree* leaf)//���õݹ飬�������
{
	if (leaf->parent != NULL)
		recursive_print(leaf->parent);
		cout << leaf->val<<" ";
}
void get_leaf(bintree* root)
{
	if (root != NULL)
	{
		if (root->left == NULL && root->right == NULL)
			push_back(root);
		else
		{
			if (root->right != NULL)
				get_leaf(root->right);
			if (root->left != NULL)
				get_leaf(root->left);
		}
	}
}
void push_back(bintree* root)
{
	queue[rear] = root;
	rear=(rear+1)%1000;
	return;
}
bintree* pop_front()
{
	int tmp = front;
	front = (front + 1) % 1000;
	return queue[tmp];
}