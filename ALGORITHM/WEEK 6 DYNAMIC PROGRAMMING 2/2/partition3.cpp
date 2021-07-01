#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
using std::vector;

int partition3(vector<int> &A) {
  //write your code here
  int sum = accumulate(A.begin(),A.end(),0);
//  std::cout << sum << std::endl;
  if(sum%3)
  	return 0;
  int n = A.size();
  int k = sum/3;
  vector<vector<int> > a(k+1, vector<int>(n+1));
  for(int i=1;i<n+1;i++)
  {
  	int weight = A[i-1];
	for(int w=1;w<=k;w++)
	{
		a[w][i] = a[w][i-1];
		if(w >= weight)
		{
			a[w][i] = max(a[w - weight][i-1] + weight, a[w][i-1]);	
		}	
	}  	
  }	
  if(a[k][n] == k)
  	return 1;
  else
  	return 0;	
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
