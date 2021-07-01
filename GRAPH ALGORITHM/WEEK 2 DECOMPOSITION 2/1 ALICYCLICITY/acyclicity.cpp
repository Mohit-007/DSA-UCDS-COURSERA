#include <iostream>
#include <vector>

using std::vector;
using std::pair;

int depth_first_search(vector<vector<int> > &adjacency_list, int x, vector<int> &visited, vector<int> &recursion_stack) 
{
  visited[x] = 1;
  recursion_stack[x] = 1;
  int i;
  for(i=0;i<adjacency_list[x].size();i++) 
  {
    if((!visited[adjacency_list[x][i]]) && depth_first_search(adjacency_list, adjacency_list[x][i], visited, recursion_stack) )
		return 1;
	else if(recursion_stack[adjacency_list[x][i]])
	  	return 1;
  }
  
  recursion_stack[x] = 0; 
  
  return 0;
}


int acyclic(vector<vector<int> > &adj) {
  //write your code here
  int n = adj.size();
  vector<int> visited(n);
  vector<int> recursion_stack(n);
  int i;
  for(i=0;i<n;i++)
  {
    if(!visited[i]) 
	{
      if(depth_first_search(adj, i, visited, recursion_stack)) 
    		return 1;
    }
  }
  return 0;
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
  std::cout << acyclic(adj);
}
