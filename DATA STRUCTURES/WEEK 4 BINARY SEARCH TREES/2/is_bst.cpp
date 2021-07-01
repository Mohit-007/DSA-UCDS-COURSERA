#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

void inorder_traversal(const vector<Node>& tree, vector<int> &result, int root) 
{
    if (root == -1) 
	{
		return;
	}
    inorder_traversal(tree, result, tree[root].left);
    result.push_back(tree[root].key);
    inorder_traversal(tree, result, tree[root].right);
}

vector <int> inorder(const vector<Node>& tree) {
    vector<int> result;
    inorder_traversal(tree,result, 0);
	return result;
}

bool IsBinarySearchTree(const vector<Node>& tree) {
  // Implement correct algorithm here
    vector<int> v = inorder(tree);
	for(int i = 0; i < v.size()-1; i++) 
  	{
  		if(v[i+1] < v[i])
  		{
  			return false;	
		}
	}
  return true;
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  
  if(nodes == 0)
  	cout << "CORRECT" << endl;

  else
  {  
	  for (int i = 0; i < nodes; ++i) {
	    int key, left, right;
	    cin >> key >> left >> right;
	    tree.push_back(Node(key, left, right));
	  }
	  if (IsBinarySearchTree(tree)) {
	    cout << "CORRECT" << endl;
	  } else {
	    cout << "INCORRECT" << endl;
	  }
 }
  return 0;
}
