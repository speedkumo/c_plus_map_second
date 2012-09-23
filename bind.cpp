#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <typeinfo> 
#include <cassert>

using namespace std;

class MyMap: public map<string, vector<int> >
{
public:
  MyMap() {}
  ~MyMap() {};

  void find(string str)
  {
    map<string, vector<int> >::iterator it;

    it = map<string, vector<int> >::find(str);
    vector<int> intvec = it->second;

    for(int i = 0; i < intvec.size(); i++)
      {
        cout << intvec[i] << "\t";
      }
    cout << endl;
  }

  void insert(string str, int number)
  {
    vector<int> numvector;
    numvector.push_back(number);
    map<string, vector<int> >::insert(make_pair(str, numvector) );
  }
};


string IntToString(int number);
string IntToString(int number)
{
  stringstream ss;
  ss << number;
  return ss.str();
}


int main()
{
  //using namespace std;
  int number1 = 100;
  int number2 = 20000;
  string str1 = IntToString(number1);
  string str2 = IntToString(number2);
  string comma(", ");
  str1 += comma;
  str1 += str2;
  cout << str1 << endl;
  MyMap amap;
  amap.insert(str1,1);
  amap.find(str1);
  const char* strL;
  strL = str1.c_str();
  regex_t preg;
  size_t nmatch = 3;
  regmatch_t pmatch[nmatch];
  int i, j;
  string restring1;
  string restring2;
  if (regcomp(&preg, "([[:digit:]]+), ([[:digit:]]+)", REG_EXTENDED|REG_NEWLINE) != 0) {
    printf("regex compile failed.\n");
    exit(1);
  }
  printf("String = %s\n", strL);
  if (regexec(&preg, strL, nmatch, pmatch, 0) != 0) {
    printf("No match.\n");
  } else {
    for (i = 0; i < nmatch; i++) { /* nmatch にマッチした件数が入る */
      printf("Match position = %d, %d , str = ", (int)pmatch[i].rm_so, (int)pmatch[i].rm_eo);
      if (pmatch[i].rm_so >= 0 && pmatch[i].rm_eo >= 0) {
	for (j = pmatch[i].rm_so ; j < pmatch[i].rm_eo; j++) {
	  //putchar(strL[j]);
          if(i==1){
          restring1+=strL[j];
	  }
          if(i==2){
	   restring2+=strL[j];
	  }
	}
      }
      printf("\n");
    }
  }

  regfree(&preg);
  cout << restring1 <<endl;
  cout << restring2 <<endl;
  assert(typeid(restring1) == typeid(string));
  assert(typeid(restring2) == typeid(string));
  int renumber1,renumber2;
  istringstream istr1(restring1);
  istr1 >> renumber1;
  cout << renumber1 <<endl;
  assert(typeid(renumber2) == typeid(int));
  istringstream istr2(restring2);
  istr2 >> renumber2;
  cout << renumber2 <<endl;
  assert(typeid(renumber2) == typeid(int));
  return 0;
}
