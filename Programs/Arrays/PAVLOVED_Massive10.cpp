#include<iostream>

using namespace std;

int main(){
setlocale(LC_ALL,"RUS");
int n;
int k=0,m=0;
cout<<"������� ���-�� ��������� �������:";
cin>>n;
int *a = new int [n];
cout<<"������� �������� �������:";
for (int i=0;i<n;i++)
    cin>>a[i];
for (int i=0;i<n;i++){
    if ((a[i]%3!=0) and (a[i]%2!=0)){
        cout<<i<<" ";
        k++;
    }
}
if (k==0)
    cout<<"����� ��������� ���";
}
