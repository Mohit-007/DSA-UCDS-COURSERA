#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

void heap(vector<int> &a,int n,int i)
{int temp;
 int largest = i;
 int left = 2*i + 1;
 int right = 2*i + 2;
 if(left < n && a[left] > a[largest])
 largest = left;
 if(right < n && a[right] > a[largest])
 largest = right;
 if(largest != i)
 {temp = a[largest];
  a[largest] = a[i];
  a[i] = temp;
  heap(a,n,largest);
 }
}


void heapsort(vector<int> &a,int n)
{int i,temp;
 for(i=(n/2)-1;i>=0;i-- )
 heap(a,n,i);
 for(i=n-1;i>=0;i--)
 {temp = a[i];
  a[i] = a[0];
  a[0] = temp;
  heap(a,i,0);
 }
}



long long max_dot_product(vector<int> a, vector<int> b) {
  // write your code here
//  std::sort(a.begin(),a.end());
//  std::sort(b.begin(),b.end());
  heapsort(a,a.size());
  heapsort(b,b.size());
  long long result = 0;
  for (size_t i = 0; i < a.size(); i++) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
