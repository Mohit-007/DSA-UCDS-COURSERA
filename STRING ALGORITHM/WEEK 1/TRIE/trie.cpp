#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <utility>

using std::map;
using std::vector;
using std::string;

typedef map<char, int> edges;
typedef vector<edges> trie;

trie build_trie(vector<string> & patterns) {
  
  
//  map<char, int> trie;
//  vector<map<char, int> > r;

	trie tr;
	edges r;
  
  tr.push_back(r);
  
  int p,q;
  int node_number = 0;
  int n = patterns.size();
  
  for(p=0;p<n;p++)
  {
    int current_node = 0;
    
    for(q=0;q<patterns[p].length();q++)
	{
      char current_symbol = patterns[p][q];
      
      if(tr[current_node].find(current_symbol) != tr[current_node].end())
	  	current_node = tr[current_node][current_symbol];
      else
	  {
		tr[current_node][current_symbol] = ++node_number;
		
		edges temp;
		
		tr.push_back(temp);
		current_node = node_number;
      }
    }
  }
  return tr;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<string> patterns;
  for (size_t i = 0; i < n; i++) {
    string s;
    std::cin >> s;
    patterns.push_back(s);
  }

  trie t = build_trie(patterns);
  for (size_t i = 0; i < t.size(); ++i) {
    for (const auto & j : t[i]) {
      std::cout << i << "->" << j.second << ":" << j.first << "\n";
    }
  }

  return 0;
}
