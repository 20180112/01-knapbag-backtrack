#include<stdio.h>
#include<stdlib.h>

int maxvalue;


//0-1背包问题回溯法
void backtrack(int t, int NumOfitem,int x[],int*w,int c,int *v) {
	//参数依次为物品数量(层数),物品数量,放置结果数组，物品重量数组，限制数组
	if (t == NumOfitem)
	{//当到达最后一层时，输出此种放置结果
		int sumweight = 0; int sumvalue = 0;
		for (int j = 0; j < t; j++)
		{//计算放入此物品后的总重量
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
			x[t] = i;//表示是否放入此物品
			int sumweight = 0;
			for (int j = 0; j <= t; j++)
			{//计算放入此物品后的总重量
				sumweight = sumweight + x[j]*w[j];
			}
			if (sumweight <= c)
			{//若总重量小于限制的重量，对下一层（下一个物品）进行选择
				backtrack(t + 1, NumOfitem, x, w, c, v);
			}
			else
			{//无法到达最后一层，则剪枝
				return;
			}
		}
	}
}
int main() {
	maxvalue = 0;
	int NumOfitem;//物品数量
	printf("请输入物品的数量:");
	scanf("%d", &NumOfitem);
	getchar();
	int* w = (int*)malloc(sizeof(int) * NumOfitem);//物体重量
	for (int i = 0; i < NumOfitem; i++)
	{//输入每个物品重量
		printf("请输入第%d个物品的重量:", i + 1);
		scanf("%d", &w[i]);
		getchar();
	}
	int* v = (int*)malloc(sizeof(int) * NumOfitem);//每个物品的价值
	for (int i = 0; i < NumOfitem; i++)
	{//输入每个物品价值
		printf("请输入第%d个物品的价值:", i + 1);
		scanf("%d", &v[i]);
		getchar();
	}
	int c;//限制的重量
	printf("请输入限制的重量:");
	scanf("%d", &c);
	getchar();
	int* result = (int*)malloc(sizeof(int) * NumOfitem);//放置结果的指针
	backtrack(0, NumOfitem, result, w, c, v);
	//printf("max value is %d\n", maxvalue);
	return 1;
}