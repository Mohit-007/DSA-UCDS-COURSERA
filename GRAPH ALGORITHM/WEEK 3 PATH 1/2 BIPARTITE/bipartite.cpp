#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int bipartite(vector<vector<int> > &adjacency_list) {
  //write your code here
  int n = adjacency_list.size();

 vector<int> color_array(adjacency_list.size(), -1);


//  int color_array[n];
//  for (int i=0;i<n;i++)
//    color_array[i] = -1;
  
  color_array[0] = 1;
  
  queue<int> queue;
  queue.push(0);

  while(!queue.empty()) 
  {
    int u = queue.front();
	queue.pop();
	   
    for(int i=0;i<adjacency_list[u].size();i++) 
	{
      int v = adjacency_list[u][i];
      if(color_array[v] == color_array[u]) 
		return 0;
			  
      else if(color_array[v] == -1)
	  {
        color_array[v] = 1- color_array[u];
		queue.push(v);
	  }
	}
  }
  return 1;  
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
