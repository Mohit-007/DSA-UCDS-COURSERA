#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

// 0 3   => 0 1 && 2 3
// 4 7	=> 4 5 && 6 7

//int partition(int a[],int low,int high)
//{int i,j,pivot,temp1,temp2;
// pivot=a[low];
// i=low;
// j=high;
// while(i<j)
// {while(a[i]<=pivot)
//  i++;
//  while(a[j]>pivot)
//  j--;
//  if(i<j)
//  {temp1=a[j];
//  a[j]=a[i];
//  a[i]=temp1;
//  }
// }
// temp2=a[j];
// a[j]=a[low];
// a[low]=temp2;
// return j;
//}




//int quicksort(int a[],int low,int high)
//{int j;
// if(low<high)
//  {j=partition(a,low,high);
//   quicksort(a,low,j-1);
//   quicksort(a,j+1,high);
//  }
//} 


int get_majority_element(vector<int> &a, int left, int right) {
  
  if (left == right) 
  	return -1;
if (left + 1 == right) 
  	return a[left];
  //write your code here
  int i;
  int mid = (left + right - 1)/2; 
  int left_element = get_majority_element(a, left, mid+1);
  int right_element = get_majority_element(a, mid+1, right);
  
  int right_count = 0;
  int left_count = 0;

  for(int i=left;i<right;i++)
  {
  	if(a[i] == right_element)
  		right_count++;
  }
  
  if(right_count > (right - left)/2)
  {
  	return right_element;
  }
  
  for(int i=left;i<right;i++)
  {
  	if(a[i] == left_element)
  		left_count = left_count + 1;
  }
  
  if(left_count > (right - left)/2)
  {
  	return left_element;
  }

	return -1;
}


int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
