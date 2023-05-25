#include<iostream>
#include<cmath>
using namespace std;

int main(){
    setlocale(LC_ALL,"Rus");
    int n,a,b;
    float s=0;
    cin>>a>>b>>n;
    int *m=new int[n+1];
    for (int i=0;i<n+1;i++)
        cin>>m[i];
    for (int i=0;i<n+1;i++){                                  //                                b
        s+=(m[i]*pow(b,(i+1))/(i+1)-m[i]*pow(a,(i+1))/(i+1)); //вычисление интеграла по формуле ∫m(i)*(x**i)= m(i)*(b**(i+1))/i+1 - m(i)*(a**(i+1))/i+1
        cout<<s<<endl;                                        //                                a
    }
    cout<<s;
}

