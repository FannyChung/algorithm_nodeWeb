#include<string>
#include<iostream>
using namespace std;


int getMin(int a, int b, int c){
	if (a <= b){
		if (a<= c){
			return a;
		}
		else{
			return c;
		}
	}
	else
	{
		if (b <= c){
			return b;
		}
		else
		{
			return c;
		}
	}
}
//递归方法
int getMinTimes(string a, string b, int n,int m){
	int k;
	if (n == 0){
		k = m;
	}
	else if (m == 0){
		k = n;
	}else if (a[n - 1] == b[m - 1]){
		k= getMinTimes(a, b, n - 1, m - 1);
	}
	else
	{
		k= getMin(getMinTimes(a, b, n - 1, m - 1) + 1, getMinTimes(a, b, n, m - 1) + 1, getMinTimes(a, b, n - 1, m) + 1);
	}
	//cout << "计算得" << n << " , " << m << "为 " << k << endl;
	return k;
}

void getEDMin(string a,string b,int n,int m,int **c,int **mark){
	for (int i = 0; i < m+1; i++)
	{
		c[0][i] = i;
		mark[0][i] = 1;
	}

	for (int i = 0; i < n+1; i++)
	{
		c[i][0] = i;
		mark[i][0] = 3;
	}

	for (int i = 1; i < n+1; i++)
	{
		for (int j = 1; j < m+1; j++)
		{
			if (a[i-1] == b[j-1]){
				c[i][j] = c[i - 1][j - 1];
				mark[i][j] = 0;
			}
			else
			{
				int c1 = c[i][j - 1] + 1;
				int c2 = c[i - 1][j - 1] + 1;
				int c3 = c[i - 1][j] + 1;
				if (c1<=c2&&c1<=c3){
					c[i][j] = c1;
					mark[i][j] = 1;
				}
				else if (c2 <= c1&&c2 <= c3){
					c[i][j] = c2;
					mark[i][j] = 2;
				}
				else {
					c[i][j] = c3;
					mark[i][j] = 3;
				}
			}
			//cout << "c[" << i << " , " << j << "] = " << c[i][j] << endl;
		}
	}
}
int main(){
	string a ;
	string b ;
	cin >> a >> b;
	//cout  << getMinTimes(a, b, a.length(), b.length())<< endl;
	
	int n1 = a.length() + 1;
	int m1 = b.length() + 1;
	int **c = new int*[n1];
	int **mark = new int*[n1];
	for (int i = 0; i < n1; i++)
	{
		c[i] = new int[m1];
		mark[i] = new int[m1];
	}

	getEDMin(a, b, a.length(), b.length(), c, mark);
	cout << c[n1-1][m1-1] << endl;
	return 0;
}