//���д����һ��������ת�����磺�����ĵ�����Ϊ 1��2��3��4��5��6��
//�����Ӧ��Ϊ 6��5��4��3��2��1��
//����ĵ�һ�и�����������׽��ĵ�ַ���ͽ���ܸ��� N(N �� 1e5)��
//�������� N �У� ÿ�и�ʽΪ��Address Data Next
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdio.h>
using namespace std;
struct link {//����Ľṹ����
	int data;
	int next;
	link() { data = 0, next = -2; }//��ʼ��
};
struct newlink {//����Ľṹ����
	int address;
	int data;
	int next;
	newlink() { address = -2; data = 0, next = -2; }//��ʼ��
};
void sort(struct link node[ ], struct newlink list[], int cur, int pre,int i );
void output(int num, struct link node[], int head);
int main()
{
	int num,head,end;
	cin >>head>>num;
	struct link node[100000];//�洢���������
	struct link p;
	int address;
	for (int i = 0; i < num; i++)
	{
		scanf("%d %d %d", &address, &p.data, &p.next);
		node[address].data = p.data;//address��Ϊ�±�
		node[address].next = p.next;//���룬�洢����Ӧ��ַ
		if (p.next == -1)
			end = address;
	}
	output(num,node,head);
	return 0;
}
void output(int num,struct link node[],int head)//�������
{
	struct newlink *list=new newlink [num];//�洢������
	sort(node, list, head, -1, num-1);
	for(int i=0;i<num;i++)
		if(list[i].next==-1)
			printf("%05d %d %d\n", list[i].address,list[i].data,list[i].next);
		else
			printf("%05d %d %05d\n", list[i].address, list[i].data, list[i].next);
	delete []list;
}
void sort(struct link node[ ], struct newlink list[], int cur,int pre,int i)//ʹ�õݹ飬��������
{//��ʼʱ��curΪhead��preΪ-1������ʼ�������ݣ����Ŵ���list��
	if (node[cur].next == -1)//����ĩβ�ڵ㣬��ʱ�±�iһ��Ϊ0
	{
		list[i].address = cur;
		list[i].data = node[cur].data;
		list[i].next = pre;//nextΪ��һ�����ĵ�ַ
		return;
	}
	sort(node, list, node[cur].next, cur, i - 1);//��ǰ���ݵ�next��Ϊ�µ�cur����ǰ�±���Ϊpre��list���±�-1
	list[i].address = cur;
	list[i].data = node[cur].data;
	list[i].next = pre;//nextΪ��һ�����ĵ�ַ
}