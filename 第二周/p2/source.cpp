//���� N ���Ǹ���������ʾÿ�����Ϊ 1 �����ӵĸ߶�ͼ�����㰴�����е����ӣ�
//����֮���ܽӶ�����ˮ�������ʽ��
//����ĵ�һ�и����������ܸ��� N(1 �� N �� 1e6)��
//����ĵڶ��и������� N ���Ǹ��������������� 1e8�����м��ÿո������
#include<iostream>
using namespace std;
bool push(int stack[], int data);
int pop(int stack[]);
long long int cal_rain( int stack[ ]);
long long int cal_end( int stack[]);
int stack[1000000] = { -1 };//ģ��һ��ջ����ʼ��Ϊ-1
int N=0;//ȫ�ֱ���N
int cnt = -1;//ȫ�ֱ���cnt��stack������±�
int main()
{
	cin >> N;
	long long int sum=cal_rain(stack);
	cout << sum;
	return 0;
}
long long int cal_rain(int stack[ ])//���㴢ˮ��
{
	int data=0,max=0,secmax=0;
	long long int sum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> data;
		if (data == 0&&stack[0]==-1)//����Ϊ0��ջ�գ�����
			continue;
		else {
			push(stack, data);
			if (cnt == 0)//ջ�н����˵�һ��Ԫ�أ���Ϊ���
			{
				max = data;
				secmax = data;
				continue;
			}
			else if (data > max)//����>��󣬸���max��secmax�󣬿�ʼ����
			{
					secmax = max;
					max = data;
			}
			else if (data > secmax&&data < max)//������ڵڶ��󣬸���max��secmax
			{
				secmax = data;
				if(i<N-1)
				continue;//���data�������һ��Ԫ�أ���������
			}
			else if (data < max && secmax == max)//�������С��max�ҵڶ���=�����dataΪ�ڶ���
			{
				secmax = data;
				if (i < N - 1)
					continue;//���data�������һ��Ԫ�أ���������
			}
			if (data <= secmax&&i<N-1)//����С�ڵڶ�����data�������һ��Ԫ�أ���������
				continue;//��data>=secmaxʱ���Ѿ�Χ�ɡ�ˮ�ء������Խ��м�����
			
			if (i == N - 1&&data<stack[0])//���������ĩβԪ��С��ջ��Ԫ�أ���������
			{
				sum = sum + cal_end(stack);
				break;
			}
			if (stack[0] == stack[cnt])//ջ��=ջ��
				secmax = max;
			int temp = data;//�Ȱ�data����
			while (cnt>=0)//���㲢��ջ��ֱ��ջ��û��Ԫ��
			{
				data = secmax-pop(stack);//ÿһ�����ܴ洢��ˮ������ջ�еڶ���Ԫ��Ϊ��׼
				if (data < 0)//data��Ϊ�Ǹ�������secmax < maxʱ��data��Ϊ������
					data = 0;
				sum += data;
			}
			push(stack, temp);//�ٰ�֮ǰ��data������temp�У�ѹ��ջ�У���ʱջ��ֻ��һ��Ԫ��
			max = temp;//���ֵ�޸�Ϊջ��Ԫ��
			secmax = temp;
		}
	}
	return sum;
}
bool push(int stack[],  int data)
{
	if (cnt==N-1)
		return false;
	cnt++;
	stack[cnt] = data;
	return true;

}
int pop( int stack[])
{
	if (cnt == -1)
		return false;
	int res = stack[cnt];
	stack[cnt] = -1;//������Ϊ-1
	cnt--;
	return res;
}
long long int cal_end(int stack[])
{
	while (cnt > 0)//��ĩβ�ݼ�����ĩβԪ�ص���
	{
		if (stack[cnt] <= stack[cnt - 1])
			pop(stack);
		else break;
	}
	 int* reverse_stack = new int[cnt+1];
	for(int i=0;i<=cnt;i++)
	reverse_stack[i]=-1;
	int data = 0, max = 0, secmax = 0;
	long long int sum = 0;
	int cnt_rev = cnt;//�洢cnt
	for (int i = 0; i <= cnt_rev; i++)
		reverse_stack[i]=pop(stack);//��stack��Ԫ��push��reversestack������cnt������
	for (int i = 0; i <=cnt_rev; i++)//���㴢ˮ��
	{
		data=reverse_stack[i];//��reverse_stack��ȡ����
		if (data == 0 && stack[0] == -1)//����Ϊ0��ջ�գ�����
			continue;
			push(stack, data);
			if (cnt == 0)//ջ�н����˵�һ��Ԫ�أ���Ϊ���
			{
				max = data;
				secmax = data;
				continue;
			}
			else if (data > max)//����>��󣬸���max��secmax�󣬿�ʼ����
			{
				secmax = max;
				max = data;
			}
			else if (data > secmax && data < max)//������ڵڶ��󣬸���max��secmax
			{
				secmax = data;
				if (i < N - 1)
					continue;//���data�������һ��Ԫ�أ���������
			}
			else if (data < max && secmax == max)//�������С��max�ҵڶ���=�����dataΪ�ڶ���
			{
				secmax = data;
				if (i < N - 1)
					continue;//���data�������һ��Ԫ�أ���������
			}
			if (data <= secmax && i < N - 1)//����С�ڵڶ�����data�������һ��Ԫ�أ���������
				continue;//��data>=secmaxʱ���Ѿ�Χ�ɡ�ˮ�ء������Խ��м�����

			if (i == N - 1 && data < stack[0])//���������ĩβԪ��С��ջ��Ԫ�أ���������
			{

			}
			if (stack[0] == stack[cnt])//ջ��=ջ��
				secmax = max;
			 int temp = data;//�Ȱ�data����
			while (cnt >= 0)//���㲢��ջ��ֱ��ջ��û��Ԫ��
			{
				data = secmax - pop(stack);//ÿһ�����ܴ洢��ˮ������ջ�еڶ���Ԫ��Ϊ��׼
				if (data < 0)//data��Ϊ�Ǹ�������secmax < maxʱ��data��Ϊ������
					data = 0;
				sum += data;
			}
			push(stack, temp);//�ٰ�֮ǰ��data������temp�У�ѹ��ջ�У���ʱջ��ֻ��һ��Ԫ��
			max = temp;//���ֵ�޸�Ϊջ��Ԫ��
			secmax = temp;
	}
		return sum;
}