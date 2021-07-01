#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

/*
9 9 16 17 19 21 22 23 24 27
15 9 16 17 19 21 22 23 24 27 4 5 10 15 20 28

8 9 16 17 19 21 22 23 24 
15 9 16 17 19 21 22 23 24 27 4 5 10 15 20 28

*/

long long binary_search(const vector<long long> &a, long long x) {
  long long left = 0;
  long long right = (long long) a.size(); 
  //write your code here
  
//  	long long mid = left + (long long)(right - left)/2;
//	while(a[mid] != x)
//	{
//		if(right < left)
//		{
//			return -1;
//		}
//		
//		else if(a[mid] > x && mid != 0)
//		{
//			right = (long long) mid-1;
//			mid = (long long) left + (long long) (right - left)/2;	
//		}	
//		else if(a[mid] < x && mid != a.size())
//		{
//			left = (long long) mid+1;
//			mid = (long long) left + (long long) (right - left)/2;
//		}
//		else
//		{
//			return -1;
//		}
//		
//	}  
//	std::cout << mid << std::endl;
	while(left <= right)
	{
		long long mid = left + (long long)(right - left)/2;
		if(x < a[mid])
		{
			right = (long long) mid - 1;
		}
		else if(x == a[mid])
		{
			return mid;
		}
		else
		{
			left = (long long) mid + 1;
		}
	}
	return -1; 
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<long long> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<long long> b(m);
  for (long long i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (long long i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    //std::cout << linear_search(a, b[i]) << ' ';
  	std::cout << (long long) binary_search(a, b[i]) << ' ';
  
  }
}
