#include<iostream>
using namespace std;
int main()
{
	int a[6][6] = { 1,2,3,2,3,4,5,6,7,8,5,4,3,1,3,4,5,8,9,7,5,4,3,6,8,9,0,3,2,4,5,3,2,1,4,5 };
	int i, j, r, c, dim;
	cout <<"ORIGNAL MATRIX\n";
	for (i = 0;i < 6;i++)
	{
		for (j = 0;j < 6;j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	int seek[1][1];
	cout << "Enter the seek value(b,c):";
   cout << " Enter row:\n";
	cin >> seek[0][0];
	
  cout << "Enter column\n";
	cin >> seek[0][1];
		
	
	int b, n, d;
	b = seek[0][0];
	n = seek[0][1];
	cout << "Enter the dimension:\n";
	cin >> dim;
	d = dim;
	int s, t, count = 1, count1 = 1;			//query matrix
	cout << "QUERY MATRIX\n";
	if ((b+ (dim - 1) < 6) && (n + (dim - 1) < 6))
	{
		for (s = b;s < 6;s++)
		{
			count1 = 1;
			for (t = n;t < 6;t++)
			{
				cout << a[s][t] << " ";

				if (count1 == dim)
					break;
				count1++;
			}
			cout << endl;
			if (count == dim)
				break;
			count++;
		}
	}
	else
		cout << "index goes out of bound\n";
	//BONUS PART
	cout << "BONUS PART\n ";

		cout << "QUERY MATRIX\n";
		int q[1][1],qu=0;
		
		for (i = 0;i < dim;i++)
		{
			for (j = 0;j < dim;j++)
			{
				if (i == 0 && j == 0) q[i][j] = 2;
				else if (i == 0 && j == 1) q[i][j] = 3;
				else  if (i == 0 && j == 2) q[i][j] = 1;
				else   q[i][j] = (qu++) + 1;
			}
		}
		for (i = 0;i < dim;i++)
		{
			for (j = 0;j < dim;j++)
			{
				cout<< q[i][j]<<" ";
			}
			cout << endl;
		}
					//directional sum of QUERY matrix
		int sum[4] = {};

	for (i = 0;i < dim;i++)
	{
		for (j = 0;j < dim;j++)
		{
			if (i == j) sum[0] = sum[0] + q[i][j];
			if ((i + j) == (dim - 1))
				sum[1] = sum[1] + q[i][j];
			if (j == 1) 
				sum[2] = sum[2] + q[i][j];
			if (i == 1) 
				sum[3] = sum[3] + q[i][j];
		}
	}
	cout << "\nDIRECTIONAL SUM-1:" << sum[0];
	cout << "\nDIRECTIONAL SUM-2:" << sum[1];
	cout << "\nDIRECTIONAL SUM-3:" << sum[2];
	cout << "\nDIRECTIONAL SUM-4:\n" << sum[3];
	//SORTED ARRAY
	int temp=0;
	for (i = 0;i < 4;i++)
	{
		for (j = i + 1;j < 4;j++)
		{
			if (sum[i]<sum[j])
			{

				temp = sum[i];
				sum[i] = sum[j];
				sum[j] = temp;
			}
		}

	}
	cout << "SORTED SUM\n";
	for (i = 0;i < 4;++i)
	{
		cout << sum[i];
		cout << endl;
	}

	return 0;
}
