#include <iostream>
#include <cmath>
using namespace std;
float f(int x){
    return log(x*x-1)/sqrt(x*x-4*x+4);
}
int main(){
    setlocale(LC_ALL,"RUS");
    int a,b,h;
    cin>>a>>b>>h;
    for (int i=a;i<=b;i=i+h){
        if (i==2)
        {
            cout<<"Деление на ноль"<<endl;
        }
        else if ((i<=1) and (i>=-1))
        {
            cout<<"Логарифм из неположительного числа"<<endl;
        }
        else{
            cout<<f(i)<<endl;
        }
    }
return 0;
}
