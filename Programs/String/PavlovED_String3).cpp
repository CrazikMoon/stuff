#include <set>
#include <iostream>
#include <string>
using namespace std;

int main()
{
  string temp, mystring;
  set<string> myset;

  while(getline(cin, temp))
      mystring += temp + ' ';
  temp = "";

  for (size_t i = 0; i < mystring.length(); i++)
  {
    if (mystring.at(i) == ' ' || mystring.at(i) == '\n' || mystring.at(i) == '\t')
    {
      myset.insert(temp);
      temp = "";
    }
    else
    {
      temp.push_back(mystring.at(i));
    }
  }
  if (temp != " " || temp != "\n" || temp != "\t")
    myset.insert(temp);

  for (std::set<std::string>::iterator i = myset.begin(); i != myset.end(); i++)
  {
    std::cout << *i << std::endl;
  }
  return 0;
}
