#include <iostream>
#include <vector>
#include <algorithm>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using std::vector;
using std::ios_base;
using std::cin;
using std::cout;

class TreeOrders {
  int n;
  vector <int> key;
  vector <int> left;
  vector <int> right;
  vector<int> result_a;  
  vector<int> result_b;  
  vector<int> result_c;  


public:
  void read() 
  {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
    for (int i = 0; i < n; i++) 
	{
      cin >> key[i] >> left[i] >> right[i];
    }
  }



  vector <int> in_order() {
    // Finish the implementation
    // You may need to add a new recursive method to do that
	inorder_traversal(0);
    return result_a;
  }

	  

  vector <int> pre_order() {
    // Finish the implementation
    // You may need to add a new recursive method to do that
	preorder_traversal(0);
    return result_b;
  }

  vector <int> post_order() 
  {
    
    // Finish the implementation
    // You may need to add a new recursive method to do that
    postorder_traversal(0);
    return result_c;
  }

	void inorder_traversal(int index) 
	{
        if (left[index] != -1)
        {
	        inorder_traversal(left[index]);	
		}
        result_a.push_back(key[index]);
        if (right[index] != -1)
        {
        	inorder_traversal(right[index]);
		}  
    }
    
 	void preorder_traversal(int index) 
	{
        result_b.push_back(key[index]);
        if (left[index] != -1)
        {
        	preorder_traversal(left[index]);
		}  
        if (right[index] != -1)
        {
        	preorder_traversal(right[index]);
		}

    }  
    
	void postorder_traversal(int index) 
	{
        if (left[index] != -1)
        {
        	postorder_traversal(left[index]);
		}    

        if (right[index] != -1)
        {
        	postorder_traversal(right[index]);
		}    

        result_c.push_back(key[index]);
    }    
  
  
};

void print(vector <int> a) {
  for (size_t i = 0; i < a.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
}

int main_with_large_stack_space() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  print(t.in_order());
  print(t.pre_order());
  print(t.post_order());
  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }
#endif

  return main_with_large_stack_space();
}

