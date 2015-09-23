#include <stdio.h>

int ClosePoint(int x[], int y[], int n);

int main()
{
	int n, i = 0;
	int x[100], y[100];
	printf("请输入想要输入的点得个数：");
	scanf("%d", &n);
	for(; i < n;)
	{
		printf("请输入第%d个点得横纵坐标：", ++i);
		scanf("%d %d", &x[i], &y[i]);
	}
	x[i + 1] = '\0';
	y[i + 1] = '\0';
	ClosePoint(x, y, n);


	return 0;
}

int ClosePoint(int x[], int y[], int n)
{
	int index1, index2;
	int dist, closest = 1000;
	int i = 0, j;
	for(; i < n - 1; i++)
	{
		for(j = i + 1; j < n; j++)
		{
			dist = (x[i] - x[j]) * (x[i] - x[i]) +(y[i] - y[j]) * (x[i] - y[j]);
			if(dist < closest)
			{
				closest = dist;
				index1 = i;
				index2 = j;
			}
		}
	}
	printf("最近点对是(%d, %d)\n", index1, index2);
	return closest;
}