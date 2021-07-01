#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

vector<int> partition3(vector<int> &a, int l, int r) {
  int x = a[l];
  int q = l;
  int p = r;
  int i = l;
  while(i<=p)
  {
  	if(a[i] > x)
  	{
  		swap(a[i],a[p]);
		p--;  	
	}
	else if(a[i] < x)
	{
		swap(a[i],a[q]);
		q++;
		i++;
	}
	else
	{
		i++;
	}
  }
  vector<int> m(2);
  m[0] = q;
  m[1] = p;
  return m;
}


int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
//  int m = partition2(a, l, r);
  vector<int> m = partition3(a, l, r);
  int q = m[0];
  int p = m[1];
  randomized_quick_sort(a, l, q - 1);
  randomized_quick_sort(a, p + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
