/*ÿ�궼���кܶ�����С���������Ͼ���ѧ��С�����ڱ����ʱ�������ܳ��Ķ��飬ÿ��ͬ
ѧֻ�ܿ����Լ�ǰ��һλͬѧ��id�������æ��ԭ������С����룺��һ��һ������n��n <= 100000����
��ʾ��n��������Id�ӣ�1 - n����ʾ������n�У�ÿ��������i��j����ʾ��������iǰ����Ǹ�����j��
�����1�У�n��������ʾ�����Ķ��С�*/
#include<iostream>
using namespace std;
struct node
{
	int i, j;
	node* next;
};
int count_out = 0, max_count = 0;
struct node* initial();//��ʼ����������
void search(struct node* first,int j);//���Ҳ���ӡ��ȷ˳��
int main()
{
	struct node* first = initial();
	search(first, 0);
	return 0;
}

struct node* initial()
{
	struct node* first=new node, * head = NULL, * tail = NULL;//β�巨��������
	int n, i, j;
	cin >> n;
	max_count = n;
	for (int m = 0;m < n; m++)
	{
		struct node* p = new node;
		cin >> i >> j;
		p->i = i;
		p->j = j;
		p->next = NULL;
		if (head == NULL)
			head = p;
		else
			tail->next = p;
		tail = p;
	}
	first->next = head;//first��Ϊ��ͷ���
	return first;
}
void search(struct node* first, int j)
{
	struct node* temp1 = first->next;
	while (temp1 != NULL)
	{
		if (temp1->j == j)
		{
			cout << temp1->i << " ";
			count_out++;
			if (count_out == max_count)
				break;//���n�κ���ֹ�ݹ�
			search(first, temp1->i);
			break;//�˳�ѭ���������������
		}
		else
			temp1 = temp1->next;
	}
}