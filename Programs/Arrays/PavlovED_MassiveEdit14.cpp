#include<iostream>
using namespace std;
int main(){
    int n,y;
    cin>>n;
    int k = n;
    int** a = new int* [2*n];
    int* b = new int[n];
    for (int i=0;i<n*2;i++){
        a[i] = new int[k];
    }
    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
            cin>>b[i];
        }
    cin>>y;
    for (int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            if ((a[i][j]%y==0)and(n!=i)){
                for (int t=n;t>i-1;t--){
                    for(int j=0;j<k;j++){
                        a[t+1][j]=a[t][j];
                    }
                }
                for (int j=0;j<k;j++){
                        a[i][j]=b[j];
                    }
            i+=2;
            n++;
            }
        }
    }
    for (int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
