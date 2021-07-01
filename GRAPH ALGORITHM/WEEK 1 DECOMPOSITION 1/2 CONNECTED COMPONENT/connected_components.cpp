#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void explore_breadth_first(vector<vector<int> > &adjacency_matrix, int x, vector<int> &visited)
{
	visited[x] = 1;
	int i = 0;
	for(i=0;i<adjacency_matrix[x].size();i++)
	{
		if(!visited[adjacency_matrix[x][i]])
			explore_breadth_first(adjacency_matrix, adjacency_matrix[x][i], visited);
	}
	
}

int number_of_components(vector<vector<int> > &adj) {
  int res = 0;
  //write your code here
  int n = adj.size();
  vector<int> visited(n);
  int i;
  for(i=0;i<n;i++)
  {
    if (!visited[i])
    {
      explore_breadth_first(adj, i, visited);
      res++;
    }
  }
  return res;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << number_of_components(adj);
}
