#include<iostream>

using namespace std;

int main(){
setlocale(LC_ALL,"RUS");
int n;
int k=0,m=999990;
cout<<"Введите кол-во элементов массива:";
cin>>n;
int *a = new int [n];
cout<<"Введите элементы массива:";
for (int i=0;i<n;i++){
    cin>>a[i];
    if ((a[i]<m)and(a[i]%2!=0))
        m=a[i];
}
for (int i=0;i<n;i++){
    if (a[i]==m){
        cout<<i<<" ";
        k++;
    }
}
if (k==0)
    cout<<"Нечётных элементов нет";
}
