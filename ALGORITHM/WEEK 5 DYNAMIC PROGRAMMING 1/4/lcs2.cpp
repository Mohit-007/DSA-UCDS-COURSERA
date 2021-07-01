#include <iostream>
#include <vector>

using std::vector;
using std::max;

int lcs2(vector<int> &a, vector<int> &b) {
  //write your code here
  int sequence[a.size()+1][b.size()+1];
  int p = a.size();
  int q = b.size();
//  for(int i=0;i<p;i++)
//  	sequence[i][0] = 0;
//  for(int i=0;i<q;i++)
//  	sequence[0][i] = 0;

  for(int i=0;i<=p;i++)
  {
  	for(int j=0;j<=q;j++)
	{
		sequence[i][j] = 0;
	} 
  }	
  for(int i=1;i<=p;i++)
  {
  	for(int j=1;j<=q;j++)
	{
	  	if(a[i-1] == b[j-1])
	  		sequence[i][j] = sequence[i-1][j-1] + 1;
	  	else
		  	sequence[i][j] = std::max(sequence[i-1][j], sequence[i][j-1]);	
	}	
  }	  	
  return sequence[p][q];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
