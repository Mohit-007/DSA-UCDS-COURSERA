#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::string;
using std::vector;

vector<int> pattern_processing(const string& p)
{
  int n = p.size(); 	
  vector<int> kmp(n,0);
  
  int length = 0;
  
  kmp[0] = 0;

  int j = 1;

  while(j < n)
  {
    if(p[length] == p[j])
	{
      length++;
      kmp[j] = length;
      j++;
    }
	else
	{
      if(length != 0)
	  {
		length = kmp[length - 1];
      }
	  else
	  {
		kmp[j] = 0;
		j++;
      }
    }
  }
  return kmp;
}

// Find all occurrences of the pattern in the text and return a
// vector with all positions in the text (starting from 0) where 
// the pattern starts in the text.
vector<int> find_pattern(const string& pattern, const string& text) {
  vector<int> result;
  // Implement this function yourself
  
 vector<int> kmp = pattern_processing(pattern);

  int m = pattern.size();
  int n = text.size();
  int p,q;
  
  p = 0;
  q = 0;
  
  while(p < n)
  {
    if(text[p] == pattern[q])
	{
      p++;
      q++;
    }
    if(q == m)
	{
      result.push_back(p-q);
      q = kmp[q-1];
    }
	else if(p < n && pattern[q] != text[p])
	{
      if(q != 0)
	  	q = kmp[q-1];
      
	  else
	  	p++;
      
    }
 }
  return result;
}

int main() {
  string pattern, text;
  cin >> pattern;
  cin >> text;
  vector<int> result = find_pattern(pattern, text);
  for (int i = 0; i < result.size(); ++i) {
    printf("%d ", result[i]);
  }
  printf("\n");
  return 0;
}
