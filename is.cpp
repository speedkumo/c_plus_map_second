#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(void) {
  string str;
  int n;
  cin >> str;
  istringstream istr(str);
  istr >> n;
  cout << n << endl;
  return 0;
}
