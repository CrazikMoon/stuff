#include<iostream>
#include<string>
using namespace std;
string replaced(string s,string a,int i){
    int m=0;
    int n=i+1;
    while (s[n]!=' '){
        if (a.find(s[i])!=std::string::npos) {
            m++;
            n++;
        }
        else n++;
    }
    if ((n-i)==m){
        s.replace(i,m,"");
        return s;
    }
    else return s;
}

int main()
{
    string s;
    getline(cin,s);
    string a;
    cin>>a;
    for (size_t i = 0; i < s.size(); i++)
        if (s[i]==' '){
                s.replace(s,a,i);
            }
        }
    cout << s << "\n";
}
