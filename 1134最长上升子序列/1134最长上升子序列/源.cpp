#include<stdio.h>
#include<stdlib.h>
int main()
{
	__int64 sum, sum1, tem;
	sum = sum1 = 0;
	int t, i;
	scanf("%d", &t);
	for (i = 0; i<t; i++)
	{
		scanf("%I64d", &tem);
		sum1 = sum1 + tem;
		if (sum1<0)
			sum1 = 0;
		if (sum1>sum)
			sum = sum1;

	}
	printf("%I64d\n", sum);
}