/*������ N ��С������Ҫ��������ѧ�Ĳٳ���վλ��������ѧ�Ĳٳ���һ�� NxN �ķ��󣬷����е�
ÿһ���������ֻ������һ��С���������ң������������ѩ�������еĸ����ǲ���վ�˵ģ���Ϊ��ˮ����
���⣬������ѧѧ��뺷��С������Ҳ���ǳ� aggressive�����������С����λ��ͬһ���С����С�����
б�ߣ����ǽ����������������ⲻ�á�
��ΪУ�쵼���㣬�϶�ϣ�������С������Ҫ�Ժ�Ϊ��Ҫ����£���Ҫ�����ﶷ��
����������ж�����վλ������ȷ��ÿ��С��������λ�ã��������ǲ����������
�����ʽ
����ĵ�һ�а������� N �� M�����У�N ������ʾ�ٳ��Ĵ�С��NxN����Ҳ��ʾС������������
M ��ʾ�ٳ����ж��ٸ�������Ϊ��ˮԭ���޷�վ�ˡ�
��������M�У�ÿ�а������������� X Y���ֱ��ʾ��ˮ���ӵĺ�������
������� 1 ��ʼ�����Ͻ��� 1 1�����½��� N N����
���ݷ�Χ��N ������ 12��M ������ N^2��*/
#include<iostream>
#include<cmath>
using namespace std;
bool is_option[12][12] = { false };//�Ƿ����վ��
int col_loc[12];//ÿһ�е�ͬѧ�����к�
void place_stu(int row);//�ŵ���row��
bool is_available(int x, int y);//�Ƿ���Է�������
int N, M;
int total_count=0;
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			is_option[i][j] = true;
	for (int i = 0; i < N; i++)
		col_loc[i] = -1;
	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		is_option[x-1][y-1] = false;
	}
	place_stu(0);
	cout << total_count;
}
void place_stu(int row)
{
	for (int col = 0; col < N; col++)//��N��
	{
		if (is_option[row][col] == false || is_available(row,col)==false)
			continue;//�˴����ܷ�
		col_loc[row] = col;
		if (row == N - 1)
		{
			total_count++;
			return;//�ѵ�����
		}
		place_stu(row + 1);//������һ��
	}
	row--;
	col_loc[row] = -1;//��һ�ж��Ҳ���������
	return;
}
bool is_available(int x, int y)//�Ƿ���Է�������
{
	for (int i = 0; i < x; i++)//����֮ǰx-1������Ԫ��λ��
		if (col_loc[i] == y||fabs(x-i)==fabs(col_loc[i]-y))
			return false;//ͬһ�л���ͬһ�Խ�����
	return true;
}
