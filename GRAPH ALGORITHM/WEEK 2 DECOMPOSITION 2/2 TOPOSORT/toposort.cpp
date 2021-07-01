#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::pair;

void dfs(vector<vector<int> > &adjacency_list, vector<int> &used, vector<int> &order, int x) 
{
  //write your code here
  int i;
  used[x] = 1;
  for(i=0;i<adjacency_list[x].size();i++) 
  {
	if(!used[adjacency_list[x][i]])
	{
		dfs(adjacency_list, used, order, adjacency_list[x][i]);	
	}  
  }
  order.insert(order.begin(), x);
}     


vector<int> toposort(vector<vector<int> > adj) 
{
  vector<int> used(adj.size(), 0);
  vector<int> order;
  //write your code here
  int n = adj.size();
  int i;
  for(i=0;i<n;i++) 
  {
	if(!used[i]) 
	{
	  dfs(adj, used, order, i);
	}
  }
  return order;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  vector<int> order = toposort(adj);
  for (size_t i = 0; i < order.size(); i++) {
    std::cout << order[i] + 1 << " ";
  }
}
