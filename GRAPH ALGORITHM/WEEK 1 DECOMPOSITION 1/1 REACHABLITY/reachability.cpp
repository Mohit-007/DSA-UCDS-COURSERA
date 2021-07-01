#include <iostream>
#include <vector>

using std::vector;
using std::pair;

int explore(vector<vector<int> > &adjacency_matrix, int x, int y, vector<int> &visited)
{
	if(x == y)
		return 1;
	
	visited[x] = 1;
	int i = 0;
	for(i=0;i<adjacency_matrix[x].size();i++)
	{
		if(!visited[adjacency_matrix[x][i]])
			if(explore(adjacency_matrix, adjacency_matrix[x][i], y, visited))
				return 1;
			
		
	}
	return 0;
}

int reach(vector<vector<int> > &adj, int x, int y) {
  //write your code here
  int n = adj.size();
  vector<int> visited(n);
  
  int reachability = explore(adj, x, y, visited);
  return reachability;
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
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}
