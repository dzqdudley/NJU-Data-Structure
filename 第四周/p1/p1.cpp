/*С��������ʦ����ڿ��Ͻ��˶ԽǾ����������Ǿ��󣬵���С����û������������
�����ڲ��õ���ҵ�������������ܰ��������ҵ�������ģ�����һ�� NxN �ķ��㷽��
�ж������͡�����ĵ�һ�������� N��N < 100������ʾ�����ά�ȡ�
����������һ�� NxN �ķ��󣬷����е�ÿ��Ԫ�ض�����Ȼ�����Ҳ����� 100��
	������ǶԽǾ������Խ��������Ԫ��ȫ��Ϊ 0��������� "diagonal"
	������������Ǿ������Խ������µ�Ԫ��ȫ��Ϊ 0��������� "upper"
	������������Ǿ������Խ������ϵ�Ԫ��ȫ��Ϊ 0��������� "lower"
	����������ֶ����ǣ������ "none"*/
#include <iostream>
using namespace std;
int main()
{
	int size;
	//int matrix[100][100] = { 0 };
	int element = 0;
	bool diagonal = 1, upper = 1, lower = 1;
	cin >> size;
	for(int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			cin >> element;
			if (i != j && diagonal && element != 0)//���ǶԽ�Ԫ��!=0����Ϊdiagonal
				diagonal = 0;
			if (i < j && lower && element != 0)//���ϰ�����Ԫ��!=0����Ϊlower
				lower = 0;
			if (i > j && upper && element != 0)//���°�����Ԫ��!=0����Ϊupper
				upper = 0;
		}
	if (diagonal)
		cout << "diagonal" << endl;
	else if (upper)
		cout << "upper" << endl;
	else if (lower)
		cout << "lower" << endl;
	else
		cout << "none" << endl;
	return 0;
}