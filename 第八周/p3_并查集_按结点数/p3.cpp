/*��Ϊ̽�ռҵ���ĳ����������һ����Ƥֽ��������һ��С���Լ�һ���㿴�����׵�0��1����ԭ����
Ϊ��һ���ܾ�֮ǰ����ѧ�⣬�������˺ܶ���ѧ����̡�һ������֮��һ����ѧ����ѧ�Ҹ����㣬
�ⲻ����ѧ�����һ�ŵ�ͼ����Щ0��1�������һ�ŵ�ͼ���Աߵ�С����д���ǣ�ÿ���µ�����һ��
���ǡ�
�Ǹ���ѧ����ѧ�Ҿ�����ϸ�о�������㣺������Ƥֽ�ϵ� 1 Ӧ���Ǵ���½�ء�0 ����󺣣�
����С����ָ�Ĺµ�Ӧ����ָ��ȫ���󺣰�Χ��½�ء���ÿ��½�ؽ���ˮƽ/��ֱ�����ϵ�½��������
���⣬��Ϊ��Ƭ��½����û���˵�������������Ʋ���Ӧ����һƬ���󺣰�Χ��δ֪��½��
��ʮ�ָ��ˣ���������ȥ�����ǣ�������������֪��һ��Ҫ����ٿ����ǡ���֪������һ��̽����Ҫ
��Ŷ೤ʱ�䡣
�����ʽ
��֪��Ƥֽ�ϵ�0��1���������еģ�һ�� row �С�col �У�0 < row,col < 512����
��һ�к͵ڶ����������� row �� col��
������ row �У��������� col ���֣����ֽ�Ϊ 0 �� 1��
�����ʽ
�������һ��������Ҫ����ٿ����ǡ�*/
#include<iostream>
using namespace std;
int map[512][512] = { 0 };
int ufset[512*512] = { 0 };//���鼯
int find(int x);//����
void weighted_union(int root1, int root2);//���ڵ�����ϲ�
int main()
{
	int row, col;
	cin >> row>>col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
			{
				int pos = i * col + j;//�ڲ��鼯�е�λ��
				ufset[pos] = -1;
				if (i == 0 && j == 0)//�����Ͻ�
					continue;
				if (i == 0 )//�ڵ�һ��
				{
					if (map[i][j - 1] == 1)//��ߵĵ�
					{
						int v = find(pos - 1);
						weighted_union(pos, v);
					}
					continue;
				}
				if (j == 0)//��������
				{
					if (map[i - 1][j] == 1)//�ϱߵĵ�
					{
						int v = find(pos- col);
						weighted_union(pos, v);
					}
					continue;
				}
				//���м�or������
				if (map[i - 1][j] == 1 && map[i][j - 1] == 1)//�ϱߵĵ�����ߵĵ㶼Ϊ1
				{
					int u = find(pos - 1); 
					int v = find(pos - col);
					if (u != v)//�ڲ�ͬС��
					{//����pos�󣬺ϲ�������
						weighted_union(u, pos);
						weighted_union(u, v);
						continue;
					}
				}
				 if (map[i][j - 1] == 1)//��ߵĵ�
				{
					int v = find(pos - 1);
					weighted_union(pos, v);
				}
				else if (map[i - 1][j] == 1)//�ϱߵĵ�
				{
					int v = find((i - 1) * col + j);
					weighted_union(pos, v);
				}
			}
		}
	int total_cnt = 0;//��������
	for (int i = 0; i < row * col; i++)
		if (ufset[i] < 0)
			total_cnt++;
	cout << total_cnt;
	return 0;
}
int find(int x)//����
{
	if (ufset[x] < 0)
		return x;
	return find(ufset[x]);
}
void weighted_union(int root1, int root2)//���ڵ�����ϲ�
{
	int temp = ufset[root1] + ufset[root2];
	if (ufset[root2] < ufset[root1])//root2�н���������
	{
		ufset[root1] = root2;
		ufset[root2] = temp;
	}
	else
	{
		ufset[root2] = root1;
		ufset[root1] = temp;
	}
}