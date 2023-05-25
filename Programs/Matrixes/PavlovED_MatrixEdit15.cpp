#include<iostream>
using namespace std;
int main(){
    int n,y,m=0;
    cin>>n;
    int k = n;
    int** a = new int* [n];
    for (int j=0;j<n*2;j++){
        a[j] = new int[k];
    }
    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for (int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            if (a[i][j]%2!=0){
                m++;
            }
        if(m==5){
            for (int h=i;h<n;h++){
                    for(int j=0;j<k;j++){
                        a[h][j]=a[h+1][j];
                    }
                }
                n--;
                i--;
            }
        }
        m=0;
    }
    cout<<endl;
    for (int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
