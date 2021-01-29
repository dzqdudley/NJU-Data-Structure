/*С�������ڵ�ѧУ��ʼ�޽�У԰��·��ѧУϣ��ѧУ�������������������໥����
������һ����ֱ�ӵĵ�·������ֻҪ������ͨ����·�ɴＴ�ɣ��������ٻ���Ҫ�����������·��
�����ʽ
ÿ�����������ĵ�1�и����������������ֱ��ǽ�����ĿN ( < 1000 )�͵�·��ĿM��
����M�ж�ӦM����·��ÿ�и���һ�����������ֱ��Ǹ�����·ֱ����ͨ����������ı�š�
Ϊ������������1��N��š� ע��:��������֮������ж�����·��ͨ,Ҳ����˵ 3 3 1 2 1 2 2 1 ��
������Ҳ�ǺϷ��� ��NΪ0ʱ�������������������������
�����ʽ
��ÿ��������������1����������ٻ���Ҫ����ĵ�·��Ŀ��*/
#include<iostream>
using namespace std;
#define max_sz 1000
short linked[max_sz][max_sz] = { 0 };//ÿ�д��һ�������Ľ������
short row_loc[max_sz+1];//���ÿ��������linked�����е��кţ���Ŵ�1��ʼ
void push(short val, short loc);//��val����linked����ĵ�loc��
int main()
{
	int building_cnt, path_cnt,start,end;
	int depth = 0, extra_cnt=0;//linked���������·�����кţ�����·������Ŀ
	cin >> building_cnt;
	if (building_cnt == 0)//�޽���
		return 0;
	cin >> path_cnt;
	
	for (int i = 0; i < max_sz+1; i++)
		row_loc[i] = -1;//��ʼ��row_loc����

	for (int i = 0; i < path_cnt; i++)//ѭ���������е�·
	{
		cin >> start>>end;
		if (row_loc[start] == -1 && row_loc[end] == -1)//����յ㶼��һ�γ��֣���������
		{
			linked[depth][0] = start;
			linked[depth][1] = end;
			row_loc[start] = row_loc[end] = depth;
			depth++;
			extra_cnt++;
		}
		else if (row_loc[start] != -1 && row_loc[end] == -1)//�յ��һ�γ��֣��������������
		{
			push(end, row_loc[start]);
			row_loc[end] = row_loc[start];
		}
		else if (row_loc[start] == -1 && row_loc[end] != -1)//����һ�γ��֣������յ�������
		{
			push(start, row_loc[end]);
			row_loc[start] = row_loc[end];
		}
		else if (row_loc[start] != -1 && row_loc[end] != -1 && (row_loc[end] != row_loc[start]))
		{//������߶��ѳ��֣����ڲ�ͬ���У��ϲ���ͬ����
			extra_cnt--;
			int row = row_loc[end];
			int new_row = row_loc[start];
			for (int i = 0; i < max_sz; i++)
			{
				if (linked[row][i] == 0)
					break;
				push(linked[row][i], new_row);
				row_loc[linked[row][i]] = new_row;//��end��������Ԫ������start������
			}
		}
		else if (row_loc[end] != -1 && (row_loc[end] == row_loc[start]))//����յ㶼�ѳ��ֹ�������ͬһ���У�����
			continue;
	}
	for (int i = 1; i <= building_cnt; i++)//��Ҫ����δ�е�·���ӵı����Ŀ
		if (row_loc[i] == -1)
			extra_cnt++;
	cout << extra_cnt-1<<endl;//���շֵ�����(�е�·��������+�����Ľ�����)-1��Ϊ������ӵ�·��
	return 0;
}
void push(short val, short loc)//��val����linked����ĵ�loc��
{
	int i;
	for (i = 0; i < max_sz; i++)
		if (linked[loc][i] == 0)
			break;
	linked[loc][i] = val;
}