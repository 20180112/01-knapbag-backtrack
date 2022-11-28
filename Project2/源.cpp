#include<stdio.h>
#include<stdlib.h>

int maxvalue;


//0-1����������ݷ�
void backtrack(int t, int NumOfitem,int x[],int*w,int c,int *v) {
	//��������Ϊ��Ʒ����(����),��Ʒ����,���ý�����飬��Ʒ�������飬��������
	if (t == NumOfitem)
	{//���������һ��ʱ��������ַ��ý��
		int sumweight = 0; int sumvalue = 0;
		for (int j = 0; j < t; j++)
		{//����������Ʒ���������
			sumweight = sumweight + x[j] * w[j];
			sumvalue = sumvalue + x[j] * v[j];
		}
		if (sumvalue > maxvalue)
		{
			maxvalue = sumvalue;
		}
//		printf("(");
//		for (int i = 0; i < NumOfitem; i++)
//		{
//			if (i == NumOfitem - 1) {
//				printf("%d", x[i]);
//			}
//			else printf("%d,", x[i]);
//		}
//		printf("),the weight is %d,the value is %d.\n",sumweight,sumvalue);
		return;
	}
	else
	{
		for (int i = 0; i <= 1; i++)
		{
			x[t] = i;//��ʾ�Ƿ�������Ʒ
			int sumweight = 0;
			for (int j = 0; j <= t; j++)
			{//����������Ʒ���������
				sumweight = sumweight + x[j]*w[j];
			}
			if (sumweight <= c)
			{//��������С�����Ƶ�����������һ�㣨��һ����Ʒ������ѡ��
				backtrack(t + 1, NumOfitem, x, w, c, v);
			}
			else
			{//�޷��������һ�㣬���֦
				return;
			}
		}
	}
}
int main() {
	maxvalue = 0;
	int NumOfitem;//��Ʒ����
	printf("��������Ʒ������:");
	scanf("%d", &NumOfitem);
	getchar();
	int* w = (int*)malloc(sizeof(int) * NumOfitem);//��������
	for (int i = 0; i < NumOfitem; i++)
	{//����ÿ����Ʒ����
		printf("�������%d����Ʒ������:", i + 1);
		scanf("%d", &w[i]);
		getchar();
	}
	int* v = (int*)malloc(sizeof(int) * NumOfitem);//ÿ����Ʒ�ļ�ֵ
	for (int i = 0; i < NumOfitem; i++)
	{//����ÿ����Ʒ��ֵ
		printf("�������%d����Ʒ�ļ�ֵ:", i + 1);
		scanf("%d", &v[i]);
		getchar();
	}
	int c;//���Ƶ�����
	printf("���������Ƶ�����:");
	scanf("%d", &c);
	getchar();
	int* result = (int*)malloc(sizeof(int) * NumOfitem);//���ý����ָ��
	backtrack(0, NumOfitem, result, w, c, v);
	//printf("max value is %d\n", maxvalue);
	return 1;
}