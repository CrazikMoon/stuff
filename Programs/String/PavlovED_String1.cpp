#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    getline(cin,s);
    string g="aeiouyAEIOUY";
    for (size_t i = 0; i < s.size(); i++)
        if (g.find(s[i])!=std::string::npos) {s.insert(i,1,'!');i++;}
    cout << s << "\n";
}
