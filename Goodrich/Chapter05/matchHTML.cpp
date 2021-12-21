#include <iostream>
#include "Stack.hpp"
#include <vector>

using namespace std;

vector <string> getHtmlTags() {
  vector<string> tags;
  while (cin) {
    string line;
    getline(cin, line);
    int pos = 0;
    size_t ts = line.find("<", pos);
    while (ts != string::npos) {
      size_t te = line.find(">", ts+1);
      tags.push_back(line.substr(ts, te-ts+1));
      pos = te + 1;
      ts = line.find("<", pos);
    }
  }
  return tags;
}

bool isHtmlMatched(const vector<string>& tags) {
  LinkedStack<string> S;
  typedef vector<string>::const_iterator Iter;

  for (Iter p = tags.begin(); p != tags.end(); ++p) {
    if (p->at(1) != '/')
      S.push(*p);
    else {
      if (S.empty()) return false;
      string open = S.top().substr(1);
      string close = p->substr(2);
      if (open.compare(close) != 0) return false;
      else S.pop();
    }
  }
  if (S.empty()) return true;
  else return false;
}

int main() {
  cout << "Usage:\n$ ./\"execName\" < \"HTML document\"\n\n";
  
  if (isHtmlMatched(getHtmlTags()))
    cout << "The input file is a matched HTML document.\n";
  else
    cout << "The input file is not a matched HTML document.\n";
}
