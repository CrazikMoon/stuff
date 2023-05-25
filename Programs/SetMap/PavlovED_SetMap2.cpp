#include<iostream>
#include<set>
#include<map>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,x;
    set<int> num1;
    set<int> num2;
    set<int> ans;
    cout<<"n=";
    cin>>n;
    list<int> l;
    cout<<"Enter the sequence of numbers: ";
    for (int i=0;i<n;i++){
        cin>>x;
        l.push_back(x);
        if((x<=99)and(x>=10)){
            num1.insert(x%10);
            num1.insert(x/10);
        }
        if((x<=999)and(x>=100)){
            num2.insert(x%10);
            num2.insert(x/100);
            num2.insert((x%100)/10);
        }
    }
    set_difference(num1.begin(),num1.end(),num2.begin(),num2.end(),inserter(ans,ans.end()));
    for (set <int> ::iterator it = ans.begin(); it != ans.end(); it++) cout << *it << " ";
}
