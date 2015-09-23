#include <stdio.h>
#include <math.h>

void PxSort(struct point *P);
void PySort(struct point *P);
double Closest(struct point *P, int low, int high);
double Distance(struct point a, struct point b);

struct point
{
	double x, y;
}P[1000];

int main()
{
	int n;
	printf("请输入要输入的数对的个数：");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lf %lf", &P[i].x, &P[i].y);
	PxSort(P, n);
	printf("%.2lf", Closest(P, 0, n));
	return 0;
}

void PxSort(struct point *P, int n)
{
	int i = 0;
	int j = 0;
	for (; i < n; i++)
	{
		for (; j < n; j++)
		{
			if (P[i].x > P[j].x)
			{
				struct point temp;
				temp.x = P[i].x;
				temp.y = P[i].y;
				P[i].x = P[j].x;
				P[i].y = P[j].y;
				P[j].x = temp.x;
				P[j].y = temp.y;
			}
		}
	}
}

void PySort(struct point *P, int n)
{
	int i = 0;
	int j = 0;
	for (; i < n; i++)
	{
		for (; j < n; j++)
		{
			if (P[i].y > P[j].y)
			{
				struct point temp;
				temp.x = P[i].x;
				temp.y = P[i].y;
				P[i].x = P[j].x;
				P[i].y = P[j].y;
				P[j].x = temp.x;
				P[j].y = temp.y;
			}
		}
	}
}

double Closest(struct point *S, int low, int high)
{
	double d1, d2, d3, d;
	int mid, i, j, index;
	struct point P[100];
	if (high - low == 1)
		return Distance(S[low], S[high]);
	if (high - low == 2)
	{
		d1 = Distance(S[low], S[low + 1]);
		d2 = Distance(S[low + 1], S[high]);
		d3 = Distance(S[low], S[high]);

		if ((d1 < d2) && (d1 < d3))
			return d1;
		else if (d2 < d3)
			return d2;
		else
			return d3;
	}
	mid = (low + high) >> 1;
	d1 = Closest(S, low, mid);
	d2 = Closest(S, mid + 1, high);
	if (d1 <= d2)
		d = d1;
	else
		d = d2;
	index = 0;
	for (i = mid; (i >= low) && (S[mid].x - S[i].x < d); i--)
		P[index++] = S[i];
	for (i = mid + 1; (i < high) && (S[mid].x - S[i].x) < d; i++)
		P[index++] = S[i];
	PySort(P, 0, index - 1);
	for (i = 0; i < index; i++)
	{
		for (j = i + 1; j < index; j++)
		{
			if (P[j].y - P[i].y >= d)
				break;
			else
			{
				d3 = Distance(P[i], P[j]);
				if (d3 < d)
					d = d3;
			}
		}
	}
	return d;
}

double Distance(struct point a, struct point b)
{
	return sqrtf(pow((a.x - b.x), 2) + (pow((a.y - b.y), 2)));
}