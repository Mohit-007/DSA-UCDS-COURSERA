#include <iostream>
#include <string>

using std::string;

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  int p = str1.size();
  int q = str2.size();
  int a[p+1][q+1];	
  int i,j;
  for(i = 0; i <= q; i++) 
	a[0][i] = i;

  for(i = 0; i <= p; i++) 
  	a[i][0] = i;
  
  int penalty = 0;
  for(i = 1; i < p+1; i++) 
  {
	for(j = 1; j < q+1; j++) 
	{
		if(str1[i-1] == str2[j-1])
			penalty = 0;
		else
			penalty = 1;
			
		int temp = std::min(a[i-1][j], a[i][j-1]);
		a[i][j] = std::min(temp + 1, a[i-1][j-1] + penalty);
	}
  }
  return a[p][q];  
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
