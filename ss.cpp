#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string IntToString(int number);
string IntToString(int number)
{
  stringstream ss;
  ss << number;
  return ss.str();
}

int main()
{
  int number = 100;
  string str = IntToString(number);
  cout << str << endl;
}
