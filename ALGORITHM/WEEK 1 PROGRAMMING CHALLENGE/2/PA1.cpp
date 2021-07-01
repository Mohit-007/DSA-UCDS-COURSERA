#include<stdio.h>
#include<map>
#include <bits/stdc++.h> 
using namespace std; 


////int maxPairwiseProduct(int a[],int n)
//long long maxPairwiseProduct(int a[],int n)
//{
//	int i=0,j=0;
////	int max = a[0]*a[1];
//	long long max = a[0]*a[1];
//	for(i=0;i<n;i++)
//	{
//		for(j=i+1;j<n;j++)
//		{
//			if(max < a[i]*a[j])
//			{
////				max = a[i]*a[j];
//				max = (long long) a[i]*a[j];
//			}
//		}
//	}
//	return max;
//}

//int maxPairwiseProduct(int a[],int n)
long long maxPairwiseProductFast(int a[],int n)
{
	int i=0,j=0;
//	int max = a[0]*a[1];
	long long max = 0;
	int max_index1 = -1;
	int max_index2 = -1;

	for(i=0;i<n;i++)
	{
		if((max_index1 == -1) || (a[max_index1] < a[i]))
		{
			max_index1 = i;
		}
	}
	for(i=0;i<n;i++)
	{
//		if((a[max_index1] != a[i]) && ((max_index2 == -1) || (a[max_index2] < a[i])))
		if((max_index1 != i) && ((max_index2 == -1) || (a[max_index2] < a[i])))
		{
			max_index2 = i;
		}
	}

//	cout << max_index1 << " " << max_index2; 
	
	max = (long long)a[max_index1]*a[max_index2];
	
	return max;
}


int main()
{
//	while(1)
//	{
////		int n = rand()%10 + 2;
//		int n = rand()%4 + 2;
//		int a[n];
//		cout << n << endl;
//		int i;
//		for(i=0;i<n;i++)
//		{
////			a[i] = rand()%10000;
//			a[i] = rand()%10;
//		}
//		for(i=0;i<n;i++)
//		{
//			cout << a[i] << " ";
//		}
//		cout << endl;
//
//		long long res1 = maxPairwiseProduct(a,n);
//		long long res2 = maxPairwiseProductFast(a,n);
//		if(res1 != res2)
//		{
//			cout << res1 << " " << res2 << endl;
//			break;
//		}
//		else
//		{
//			cout << endl;
//			continue;
//			
//		}
//	}
	
	int n=0;
	cin >> n;
	int a[n];
	int i=0;
	for(i=0;i<n;i++)
	{
		cin >> a[i];
	}
	long long res = maxPairwiseProductFast(a,n);
	cout << res;
}

