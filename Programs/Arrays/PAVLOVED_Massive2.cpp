#include<iostream>

using namespace std;

int main(){
setlocale(LC_ALL,"RUS");
int n;
int m=0;
cout<<"������� ���-�� ��������� �������:";
cin>>n;
int *a = new int [n];
cout<<"������� �������� �������:";
for (int i=0;i<n;i++)
    cin>>a[i];
for (int i=0;i<n;i++){
    if ((i%2!=0) and (a[i]%2!=0)){
        m+=a[i];
    }
}
if (m==0)
    cout<<"����� ��������� ���";
else
    cout<<m;
}
