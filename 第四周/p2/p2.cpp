/*����������С������ÿ��С�����ֱ����������Ŷӣ��γɾ��� A��n �� t �У������� B��t �� m �У�
������ C��n �� m �У������ζ�ÿ��С������˫ʮһ���������
���� A �У��� i �С��� j �е�С������õĹ��������Ŀ��Aij��ʾ����������ͬ��
���ɺϵ��ǣ����Ƿ���������һ�����ɣ�Cij=Aik*Bkj;
�����֪���� A��B ��С�����ǻ�õĽ����������������ܼ�������� C ��ÿ��С��������õ�˫ʮ
һ���������
��ʾ�����ڽ����������ޣ����Ժ��ź����ǣ����ܴ󲿷ֵ�С�����Ĺ��������Ϊ���ء�
�����ʽ
����ĵ�һ�и����� A ������ n��A ���������� B ��������t��B������ m������ n, t, m��(0, 1000]��
����������������� A �;��� B ��ÿ��С������õĹ��������ÿ��С������õĹ��������Ŀ
��Χ��[0, 100]��
�����ʽ
������� C ��ÿ��С������õĹ������*/
#include<iostream>
using namespace std;
struct triple {
	short row, col;//�к����к�
	int val;//ֵ
	triple() { row = -1; col = -1; val = -1; }
};   
int n, t, m;
struct triple A[1000000], B[1000000], C[1000000];
void get_matrix(triple A[], triple B[],int *row_size,int *row_start);
int multiply_matrix(triple A[], triple B[], triple C[], int row_size[], int row_start[]);
void print_matrix(triple C[],int count);
int main()
{
	cin >> n >> t >> m;
	int* row_size = new int[t];//����B���з�0Ԫ�ظ���
	int* row_start = new int[t + 1];//����B��������Ԫ�鿪ʼλ��
	get_matrix(A, B,row_size,row_start);
	int count=multiply_matrix(A,B,C,row_size,row_start);
	print_matrix(C,count);
	return 0;	
}

void get_matrix(triple A[], triple B[], int *row_size, int *row_start)//����A,B����
{
	int count = 0,val=0;//���м���������
	for (int i = 0; i < n; i++)
		for (int j = 0; j < t; j++)
		{
			cin >> val;
			if (val == 0)
				continue;
			else
			{
				A[count].val = val;
				A[count].row = i;
				A[count].col = j;
				count++;
			}
		}
	count = 0;//count���㣬Ϊ�´�������׼��
	for (int i = 0; i < t; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> val;
			if (val == 0)
				continue;
			else
			{
				B[count].val = val;
				B[count].row = i;
				B[count].col = j;
				count++;
			}
		}
	for (int i = 0; i < t; i++)
		row_size[i] = 0;//�Ƚ�rowsizeȫ��Ϊ0
	for (int i = 0; i <= count; i++)
		row_size[B[i].row]++;//ͨ��count��B��Ԫ������������ʼ������rowsize
	row_start[0] = 0;
	for (int i = 1; i <= t; i++)//��ʼ��rowstart������±�=��һ������±�+��һ��Ԫ�ظ���
		row_start[i] = row_start[i - 1] + row_size[i - 1];
}

int multiply_matrix(triple A[], triple B[], triple C[], int row_size[], int row_start[])//����C�з�0Ԫ�ظ���
{
	int cur = 0;
	int* temp = new int[m];//mΪ����B������,�ݴ�Cÿһ�м���Ľ��
	int count = 0;//C�з�0Ԫ�ؼ���
	while (A[cur].val > 0)//��A��������ʱ���˳�ѭ��
	{
		int row_A = A[cur].row;//A�е�ǰԪ�ص��к�
		for (int i = 0; i < m; i++)
			temp[i] = 0;//�Ƚ�tempȫ����Ϊ0
		while (A[cur].val > 0 && A[cur].row == row_A)//����A����Ԫ��
		{
			int col_A = A[cur].col;//A�е�ǰԪ�ص��к�
			for (int i = row_start[col_A]; i < row_start[col_A + 1]; i++)//����B���к�Ϊcol_A��Ԫ��
			{
				int col_B = B[i].col;//B�е�ǰԪ�ص��к�
				temp[col_B] += A[cur].val * B[i].val;//C��row_A�У�col_B�еĽ��
			}
			cur++;
		}
		for (int i = 0; i < m; i++)
			if (temp[i] != 0)
			{
				C[count].row = row_A;
				C[count].col = i;
				C[count].val = temp[i];
				count++;
			}
	}
	return count;
}

void print_matrix(triple C[],int count)
{
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (num<=count && i == C[num].row && j == C[num].col)
			{
				cout << C[num].val;
				num++;
			}
			else
				cout << "0";
			if (j < m - 1)
				cout << " ";
		}
		cout << endl;
	}
}
