#include<iostream>
using namespace std;
int arrdelete(int m,int n,int *a){
    for (int i=m;i<n-1;i++){
        a[i]=a[i+1];
    }
}

int main(){
    int n,x;
    cin>>n;
    int *a = new int [n+1];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>x;
    for (int i=0;i<n;i++){
        if ((a[i]%x==0)and(a[i]%2==0)){
            arrdelete(i,n,a);
            i--;
            n--;
        }
    }
    for (int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
