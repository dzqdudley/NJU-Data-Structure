/*����һ�����������ж��Ƿ����һ�����ڵ㵽Ҷ�ڵ�·��֮�͵���n����������������ͼ�ж������ı�ʾ��
5 4 11 7 - 1 - 1 2 - 1 - 1 - 1 8 13 - 1 - 1 4 - 1 1����ǰ�����������
��ô���дӸ��ڵ㵽Ҷ�ڵ�·��֮��Ϊ27, 22, 26, 18
�����ʽ
��һ��һ��n���ڶ�������һ�����ֱ�ʾ���� - 1��ʾ�սڵ㣬
�����ʽ
yes����no*/
#include <iostream>
using namespace std;
void create_tree(struct node* & subtree, int pre_distance);//������
struct node {
	int data;
	int distance;//�Ӹ��ڵ㵽�˽ڵ�ľ���
	struct node* left;
	struct node* right;
};
bool flag = false;
int dist=0;
int main()
{
	struct node *head;
	cin >> dist;
	create_tree(head, 0);
	//pre_order(head);
	if (flag)
		cout << "yes";
	else
		cout << "no";
	return 0;
}
void create_tree(struct node* &subtree, int pre_distance)//ǰ�����������
{
	int data;
	cin >> data;
	if (data == -1)
		subtree = NULL;
	else
	{
		subtree = new node;
		subtree->data = data;
		subtree->distance = data+pre_distance;//current_distance = pre_distance+current_value
		if (subtree->distance == dist)
		{
			flag = true;
			return;
		}
		create_tree(subtree->left, subtree->distance);
		create_tree(subtree->right,subtree->distance);
	}
}