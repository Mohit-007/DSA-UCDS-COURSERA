#include <iostream>
#include <vector>

using std::vector;


long long merge(vector<int> &a, vector<int> &b, size_t l, int mid, size_t r) 
{
	
//	int n = mid - l + 1; 
//	int m =  r - mid; 
	  
	size_t i = l;
	size_t j = mid;
	size_t k = l;
	
	long long inversion_count = 0;

	while(i <= mid-1 && j <= r)
	{
		 if(a[i]<=a[j])
		 {
			  b[k]=a[i];
			  i++;
		 }
		 else
		 {
			  b[k]=a[j];
			  inversion_count += mid - i;
			  j++;
		 }
		 k++;
	}

/*	
	if(i>=mid-1)
	{
	     for(;j<=r;j++)
		 {
			  b[k]=a[j];
			  k++;
		 }
	}
*/

/*
	if(j >= r)
	{
		 for(;i<=mid-1;i++)
		 {
			  b[k]=a[i];
			  k++;
		 }
	}
*/
	for(;i<=mid-1;i++)
	{
		b[k] = a[i];
		k++;
	}

	for(;j <= r;j++)
	{
		b[k] = a[j];
		k++;	
	}	

	for(i=l;i<=r;i++)
	{
		a[i] = b[i];
	}

 	return inversion_count;
} 
 

  
//void mergesort(int a[], int l, int r) 
//{ 
//    if (l < r) 
//    { 
//        int m = l+(r-l)/2; 
//        mergesort(a, l, m); 
//        mergesort(a, m+1, r); 
//        merge(a, l, m, r); 
//    } 
//}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left) 
  	return number_of_inversions;
  size_t mid = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, mid);
  number_of_inversions += get_number_of_inversions(a, b, mid+1, right);
  //write your code here  
  number_of_inversions +=  merge(a, b, left, mid+1, right);
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()-1) << '\n';
}
