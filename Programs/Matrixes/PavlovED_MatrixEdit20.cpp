#include<iostream>
using namespace std;
int main(){
    int n,x;
    cin>>n;
    int k = n;
    int** a = new int* [k];
    for (int j=0;j<n*2;j++){
        a[j] = new int[n];
    }
    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    cin>>x;
    for (int j=0;j<n;j++){
        for(int i=0;i<k;i++){
            if(a[i][j]%10==x){
                for (int h=j;h<n;h++){
                    for(int z=0;z<k;z++){
                        a[z][h]=a[z][h+1];
                    }
                }
                n--;
                j--;
            }
        }
    }
    cout<<endl;
    for (int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
