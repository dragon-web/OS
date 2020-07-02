#include<iostream>
#include<regex>//正则表达式必须要这个头文件
using namespace std;

int main()
{
  regex reg("b.?p.*k");
  cout<<regex_match("bopggk",reg)<<endl;
  cout << regex_match("boopgggk",reg);
  cout<< regex_match("b pk",reg);



  return 0;
}
