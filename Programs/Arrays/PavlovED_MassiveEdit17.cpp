#include<iostream>
using namespace std;
int arradd(int m,int n,int y,int *a){
    for (int i=n;i>m-1;i--){
        a[i+1]=a[i];
    }
    a[m]=y;
}

int main(){
    int n,x,y;
    cin>>n;
    int *a = new int [2*n];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>x;
    cin>>y;
    for (int i=0;i<n;i++){
        if ((a[i]%10==x)){
            arradd(i,n,y,a);
            i++;
            n++;
        }
    }
    for (int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
