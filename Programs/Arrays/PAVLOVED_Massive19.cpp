#include<iostream>

using namespace std;

int main(){
setlocale(LC_ALL,"RUS");
int n;
int k=0,m=999990,d=-1,flag1=-1,flag2=-1;
cout<<"Введите кол-во элементов массива:";
cin>>n;
int *a = new int [n];
cout<<"Введите элементы массива:";
for (int i=0;i<n;i++){
    cin>>a[i];
    if (a[i]%2==0){
        if (a[i]>d){
            d=a[i];
            flag1=i;
        }
    }
    else{
        if (a[i]<m){
            m=a[i];
            flag2=i;
        }
    }
}
if ((flag1!=-1) and (flag2!=-1)){
    a[flag1]=m;
    a[flag2]=d;
for (int i=0;i<n;i++){
    cout<<a[i]<<" ";
}
}
else cout<<"Таких элементов нет";
}
