/*����һ���ַ����������ù���������ķ�ʽ�������ѹ����
��������ַ��� AAAAABCD������ô�ͳ��ASCII���룬����Ҫռ�� 8x8=64 bits �Ĵ洢�ռ䡣
���ǣ�����ù�������������������ǿ��Խ� A��B��C��D �ֱ��� 0��10��110��111 �����룬
��������������������ǣ�
A -> 0
B -> 10
C -> 110
D -> 111
��ʱ��AAAAABCD �ͱ�ѹ��Ϊ�� 0000010110111 ����ַ�����
զһ�������Ⱥ���䳤�ˣ���ʵ���ϣ�ǰ�ߵ�ÿ��Ӣ���ַ���Ҫ�� 8 ���������洢��һ����Ҫ64����
�أ��������ߣ�ֻ��Ҫ 13 �����ء�ѹ���ʻ��Ǻܸߵġ�
��Ȼ�������Ĺ���Ψһ�����磺
A -> 1
B -> 01
C -> 001
D -> 000
��Ҳ��ʹ�ù�����������õĹ��򡣵��ǣ������������ѹ���ʶ���һ���ġ�
��˱�����������һ���ַ��������Ȳ����� 1e4�������ҽ������� A~Z �� 26 ����дӢ���ַ���
�����̼��㣬���ʹ�ù�����������ѹ������ַ�����һ����Ҫ���ٸ����ء�*/
#include<iostream>
using namespace std;
struct huffman {
	int data;//��ǰ��ĸ������
	huffman* left;
	huffman* right;
	huffman* parent;
	huffman() { data = 0; left = NULL; right = NULL; parent = NULL; }
};
huffman* node[26] = { NULL };//�洢����������ֵ
int node_cnt = 0;//node�н�����
huffman* remove();//������Сֵ���
void insert(huffman* data);//����ֵ
huffman* merge(huffman* first, huffman* second);//�������ڵ�
void create_tree(huffman* &root);
void traverse(huffman* root,int depth);
int bit_num = 0;
int main()
{
	int alpha_cnt[26] = { 0 };
	huffman* root;
	char ch;
	while ((ch = getchar()) != '\n')
		alpha_cnt[ch - 'A']++;//���벢����
	for (int i = 0; i < 26; i++)
	{
		if (alpha_cnt[i] > 0)
		{
			huffman *root = new huffman;
			node[node_cnt] = root;
			root->data = alpha_cnt[i];//��ʼ��node����
			node_cnt++;//��ʼ��node_cnt
		}
	}
	create_tree(root);
	traverse(root, 0);
	cout << bit_num;
	return 0;
}
huffman* remove()//ɾȥ��Сֵ��㲢������Сֵ��ַ
{
	int min= 10000;
	for (int i = 0; i <26; i++)
		if (node[i] != NULL && node[i]->data < min)
			min = node[i]->data;
	int i;
	for (i = 0; i < 26; i++)
		if (node[i] != NULL && node[i]->data == min)
			break;
	node_cnt--;
	huffman* tmp = node[i];
	node[i] = NULL;
	return tmp;
}
void insert(huffman* root)//������
{
	for (int i = 0; i < 26; i++)
		if (node[i] == NULL)
		{
			node[i] = root;
			break;
		}
	node_cnt++;
}
huffman* merge(huffman* first, huffman* second)
{
	huffman* parent = new huffman;
	parent->left = first;
	parent->right = second;
	parent->data = first->data + second->data;
	return parent;
}
void create_tree(huffman* &root)
{
	huffman* first, * sec;
	while (node_cnt > 1)
	{
		first = remove();
		sec = remove();
		root=merge(first, sec);
		insert(root);
	}
}
void traverse(huffman* root,int depth)
{
	if (root->left != NULL)
		traverse(root->left, depth + 1);
	if (root->right != NULL)
		traverse(root->right, depth + 1);
	if (root->left == NULL && root->right == NULL)
	{
		bit_num += root->data * depth;
		return;
	}
}