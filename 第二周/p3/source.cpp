 //������״ͼ�������������������ε������
//����ĵ�һ�а������� T(1 <= T <= 100)����ʾ����������������
//�������� T �У�ÿ�ж�Ӧһ������������������ N(1 <= N <= 1e5) ��ͷ����ʾ����״ͼ�������ľ�����
//���������� N ����������Щ���ִ����ҷֱ��ʾ N ���εĸ߶ȣ���Ϊ������ 1e9 ������������
//ÿ�����εĿ��Ϊ 1��
#include<iostream>
using namespace std;
bool push(struct node stack[],  int data,int N);
bool pop(struct node stack[]);
void empty(struct node stack[]);
struct node {
	int data;
	int loc;
};//�洢�����Լ����������е�λ��
struct node stack[100000];//ջ
int leftbar_loc[100000];//�洢���߽�bar���±�
int rightbar_loc[100000];//�洢�Ҳ�߽�bar���±�
int input[100000];//�洢��������
int cnt = -1;//ȫ�ֱ���cnt��stack������±�
void sort(int N);
int main()
{
	int T, N;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		sort(N);//���м���
	}
	return 0;
}
bool push(struct node stack[],  int data,int loc,int N)
{
	if (cnt == N - 1)
		return false;
	cnt++;
	stack[cnt].data = data;
	stack[cnt].loc = loc;
	return true;

}
bool pop(struct node stack[])
{
	if (cnt == -1)
		return false;
	stack[cnt].data=0;
	stack[cnt].loc = -1;//������Ϊ-1
	cnt--;
	return true;
}
void empty(struct node stack[])
{
	while (cnt >= 0)
		pop(stack);
}
void sort(int N)
{
	for (int i = 0; i < N; i++)
		cin >> input[i];//�洢���������
	for (int i = 0; i < N; i++)
	{
		if (cnt == -1)//ջ�գ�ֱ��push
		{
			leftbar_loc[i] = -1;//�����߽�Ϊ-1
			push(stack, input[i], i, N);
		}
		else
		{
			while (input[i] <= stack[cnt].data && cnt > 0)
				pop(stack);//��ջ�д���input�����ݵ�������Щ���ݲ��Ǳ߽磩
			if (cnt == 0 && input[i] <= stack[0].data)//�ҵ��߽�
			{
				pop(stack);
				leftbar_loc[i] = -1;//�����߽�Ϊ-1
			}
			else//�ҵ��߽�
				leftbar_loc[i] = stack[cnt].loc;//�洢�����߽��ַ
			push(stack, input[i], i, N);//��bar��ջ
		}
	}
	empty(stack);//���ջ
	for (int i = N - 1; i >= 0; i--)
	{
		if (cnt == -1)//ջ�գ�ֱ��push
		{
			rightbar_loc[i] = N;//���Ҳ�߽�ΪN
			push(stack, input[i], i, N);
		}
		else
		{
			while (input[i] <= stack[cnt].data && cnt > 0)
				pop(stack);//��ջ�д��ڵ�����������ݵ�������Щ���ݲ��Ǳ߽磩
			if (cnt == 0 && input[i] <= stack[0].data)
			{
				pop(stack);
				rightbar_loc[i] = N;//���Ҳ�߽�ΪN
			}
			else
				rightbar_loc[i] = stack[cnt].loc;//�洢���Ҳ�߽�
			push(stack, input[i], i, N);//��bar��ջ
		}
		
	}
	empty(stack);//���ջ
	long long int max = 0,size=0;
	for (int i = 0; i < N; i++)
	{//������ÿ���ڵ�Ϊ�߶ȵ����������
		size = (long long int)input[i] *((long long int)rightbar_loc[i] - (long long int)leftbar_loc[i]-1);
		if (size > max)
			max = size;
	}
	cout << max << endl;		
}