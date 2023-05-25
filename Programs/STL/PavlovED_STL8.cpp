#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
int a,b;
bool pred(int n) { //Условие для замены
	return n >= a && n <= b;
}

int main(){
    int n,x,c,d;
    cout<<"n=";
    cin>>n;     // ввод кол-ва символов
    cout<<endl;

    vector<int> vec;
    cout << "Enter the sequence of numbers :";
    for(int i = 0; i < n; i++){//заполнение
        cin >> x;
        vec.push_back(x);
    }
    cout << endl;
    for(vector<int>::iterator iter = vec.end()-1; iter >= vec.begin(); iter --){
        cout << *iter <<" ";    // вывод последовательности
    }
    cout<<endl;
    cout<<"Enter the interval of elements to replace with X:";
    cin>>a>>b;
    cout<<endl;
    cout<<"Enter X:";
    cin>>c;
    replace_if(vec.begin(), vec.end(), pred, x);
    sort (vec.begin(), vec.end());
    cout<<"Enter new element:";
    cin>>d;
    vec.push_back(d);
    vector<int>::iterator iter1 = unique(vec.begin(), vec.end());
    vec.erase(iter1,vec.end());
    for(vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter ++){
        cout << *iter <<" ";    // вывод последовательности
    }
}
