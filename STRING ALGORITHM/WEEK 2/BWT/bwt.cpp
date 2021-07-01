#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

string BWT(const string& text) {
  string result = "";

  // write your code here

  vector<string> bwt_matrix;

  int i,j;

  string new_string = "";

  
  for(i = 0; i < text.size(); i++)
  {
    
    new_string = "";
    
    for(j = 0; j < text.size(); j++)
		new_string = new_string + text[(i+j)%text.size()];
    
    bwt_matrix.push_back(new_string);
  }
 
  sort(bwt_matrix.begin(),bwt_matrix.end());
  
  int k;
  
  for(k = 0; k < bwt_matrix.size(); k++)
  	result = result + bwt_matrix[k][bwt_matrix[k].size()-1];
  

  return result;
}

int main() {
  string text;
  cin >> text;
  cout << BWT(text) << endl;
  return 0;
}
