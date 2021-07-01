#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using std::vector;
using std::pair;
using std::stack;

vector<vector<int> > reverse_edges(vector<vector<int> > &adjacency_list)
{
	vector<vector<int> > reverse_adj(adjacency_list.size(), vector<int>());

	int i,j;

    for(i=0;i<adjacency_list.size();i++)
	{
	  for(j=0;j<adjacency_list[i].size();j++)
	  {
		reverse_adj[adjacency_list[i][j]].push_back(i);
	  }
	}

	return reverse_adj;
}

void depth_first_search(vector<vector<int> > &adjacency_list, int x, vector<int> &visited, stack<int> &stack) 
{
	visited[x] = 1;
	int i;
	
	for(i=0;i<adjacency_list[x].size();i++) 
	{
      if(!visited[adjacency_list[x][i]])
	  {
        visited[adjacency_list[x][i]] = 1;
		depth_first_search(adjacency_list, adjacency_list[x][i], visited, stack);
	  }	
	}
	
	stack.push(x);
}


int number_of_strongly_connected_components(vector<vector<int> > adjacency_list) {
  int result = 0;
  //write your code here
   stack<int> s;
  
  vector<int> visited(adjacency_list.size(), 0);
  int i;
  
  for(i=0;i<adjacency_list.size();i++) 
  {
	if(!visited[i])
	{
	  depth_first_search(adjacency_list, i, visited, s);
	}
  }
	
  vector<vector<int> > reverse_adj = reverse_edges(adjacency_list);
	
  for(i=0;i<adjacency_list.size();i++) 
  {
	visited[i] = 0;
  }
	
  while(!s.empty()) 
  {
	int x = s.top();
    s.pop();
 
    if (!visited[x]) 
	{
	  stack<int> stack_component;
	  depth_first_search(reverse_adj, x, visited, stack_component);
	  result = result + 1;
	}
  }
  return result;
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
  std::cout << number_of_strongly_connected_components(adj);
}
