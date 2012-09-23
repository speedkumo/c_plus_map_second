#include <string>
#include <iostream>

int main()
{
  using namespace std;

  string str1( "abcde" );
  string com(", ");
  string str2( "fghij" );
  str1+=com;
  str1 += str2;   // str1の末尾にstr2を連結
  cout << str1 << endl;

  if( str1 == "abcdefghij" )  // ２つの文字列を比較
    {
      cout << "一致" << endl;
    }
  else
    {
      cout << "不一致" << endl;
    }

  cout << "str1の文字数は" << str1.size() << endl; // 文字列の長さを出力
  return 0;
}
