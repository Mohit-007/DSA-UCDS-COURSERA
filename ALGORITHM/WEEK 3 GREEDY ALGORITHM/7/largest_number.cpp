#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

string largest_number(vector<string> a) {
  //write your code here
  int n = a.size();
  for(int i=1;i<n;i++)
  {
  	for(int j=0;j<n-i;j++)
  	{
  		if((std::string) (a[j+1]) + (std::string)(a[j]) > (std::string) (a[j]) + (std::string) (a[j+1]))
		{
			swap(a[j], a[j+1]);	
		}	
	}
  }
  
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
