#include<iostream>
#include<cmath>
int F(int m,int n){
    if ((m-n)%2!=0){
        while((m > 0) and (n > 0)){
        if(m > n)
            m %= n;
        else
            n %= m;
        }
        if ((m+n)==1)
        return 1;
        else
        return 0;
    }
    else return 0;
}
using namespace std;

int main(){
    int N;
    cin>>N;
    int k=0;
        for (int i=1;i<=100;i++){
            for (int j=1;j<=100;j++){
                if (k==N) break;
            else{
                if((F(i,j)) and (i*i-j*j)>0) {
                    cout<<i*i-j*j<<" "<<2*i*j<<" "<<i*i+j*j<<endl;
                    k+=1;
                }
            }
            }
        }



}

