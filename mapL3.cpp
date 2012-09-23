#include <iostream>
#include <map>
#include <vector>
using namespace std;
class MyMap: public multimap<string, vector<int> >
{
public:
  MyMap() {}
  ~MyMap() {};

  void find(string str)
  {
    multimap<string, vector<int> >::iterator it;

    it = multimap<string, vector<int> >::find(str);
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
    multimap<string, vector<int> >::insert( 
	make_pair(str, numvector) );
  }
};

int main ()
{
  MyMap amap;
  amap.insert("one", 1);
  amap.insert("two", 2);
  amap.insert("three", 3);
  //amap["three"].push_back(3);
  //amap["three"].push_back(3);
  //cout << amap["one"];
  amap.find("one");
  amap.find("two");
  amap.find("three");

  return 0;
}
