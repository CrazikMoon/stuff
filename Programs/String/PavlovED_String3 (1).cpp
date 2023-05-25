#include<iostream>
#include<string>
using namespace std;
string replaced(string s,string a,int i){
	string j;
	int m=i;
    int flag=0;
    while(m<s.size()+1){
        while (s[i+1]!=' '){
    	j=s[i+1];
        if (a.find(j)!=std::string::npos) {
        	flag=1;
        }
        else {
		flag=0;
		}
		i++;
    }
    if (flag==1){
    //cout<<"Replacing...from "<<m<<" to "<<i<<endl;
        //cout<<s<<endl;
        s.replace(m,i+1,"");
       // cout<<s<<endl;
        return replaced(s,a,m);
    }
    else {
        return replaced(s,a,m+i);
    }
    }
        return s;
}

int main()
{
    string s;
    getline(cin,s);
    s.insert(0,1,' ');
    s.resize(s.size()+2);
    s.insert(s.size(),1,' ');
    string a;
    cin>>a;
    s=replaced(s,a,0);
    s.replace(0,1,"");
    cout << s << "\n";
}
