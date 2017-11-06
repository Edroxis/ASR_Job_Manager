#include <iostream>
#include <string>
using namespace std;

int main ()
{
  int i;
  cout << "Please enter a string: ";
  std::string str = std::string();
  cin >> str;
  cout << "The str you entered is " << str << std::endl;
  return 0;
}
