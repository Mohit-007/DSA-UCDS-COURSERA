#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
using std::string;
using std::vector;


bool compare(const pair<string,int> &p, const pair<string,int> &q){
  return p.first < q.first;
}

// Build suffix array of the string text and
// return a vector result of the same length as the text
// such that the value result[i] is the index (0-based)
// in text where the i-th lexicographically smallest
// suffix of text starts.
vector<int> BuildSuffixArray(const string& text) {
  vector<int> result;
  // Implement this function yourself
  
  vector<pair<string,int> > s;
  int i,j;
  int n = text.size() ;
  
  for(j = 0; j <= n - 1; j++)
  	s.push_back(make_pair(text.substr(j , n - j),j));


  
  sort(s.begin(),s.end(),compare);
  
  for(i = 0 ; i <= s.size() - 1; i++)
  	result.push_back(s[i].second);
  

  return result;
}

int main() {
  string text;
  cin >> text;
  vector<int> suffix_array = BuildSuffixArray(text);
  for (int i = 0; i < suffix_array.size(); ++i) {
    cout << suffix_array[i] << ' ';
  }
  cout << endl;
  return 0;
}
