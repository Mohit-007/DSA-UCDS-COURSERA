#include <iostream>
#include <vector>
using namespace std;
using std::vector;

// discrete knapsack problem (!with repeatition)

int max(int a,int b)
{
	if(a>b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
	int i,weight;
	vector<vector<int> > array(w.size()+1,vector<int>(W+1));
	for(i=0;i<=w.size();i++)
	{
		for(weight=0;weight<=W;weight++)
		{
			array[i][weight] = 0;
		}
	}
	for(i=1;i<=w.size();i++)
	{
		for(weight=1;weight<=W;weight++)
		{
		    	array[i][weight] = array[i-1][weight];
		    	if(w[i-1] <= weight)
		    	{
		    		int value = array[i-1][weight - w[i-1]] + w[i-1];
		    		if(array[i][weight] < value)
		    		{
		    			array[i][weight] = value;
					}

//					if(i==0||weight==0)
//						array[i][weight] = 0;
//					else if(w[weight-1]<=i)
//						array[i][weight] = max(w[weight-1] + array[i-w[weight-1]][weight-1], array[i][weight-1]);
//					else
//						array[i][weight] = array[i][weight-1];		
				}
		}
	}
  	return array[w.size()][W] ;

//  int current_weight = 0;
//  for (size_t i = 0; i < w.size(); ++i) {
//    if (current_weight + w[i] <= W) {
//      current_weight += w[i];
//    }
//  }
//  return current_weight;
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
