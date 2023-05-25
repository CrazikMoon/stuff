#include<iostream>
using namespace std;
int main(){
    int n,y;
    cin>>n;
    int k = n;
    int** a = new int* [k];
    int* b = new int[n];
    for (int j=0;j<n*2;j++){
        a[j] = new int[2*n];
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
    for (int j=0;j<n;j++){
        for(int i=0;i<k;i++){
            if ((a[i][j]%10==y)and(n!=j)){
                for (int t=n;t>j-1;t--){
                    for(int i=0;i<k;i++){
                        a[i][t+1]=a[i][t];
                    }
                }
                for (int i=0;i<k;i++){
                        a[i][j]=b[i];
                    }
            j++;
            n++;
            break;
            }
        }
    }
    for (int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
