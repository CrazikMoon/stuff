#include<iostream>
using namespace std;

float slash(float b,int n,int i){
    if (i<(n-2)){
        return b=i+(i+1)/slash(b,n,i+1);
    }
    if (i==(n-2)){
        return i+(i+1)/((i+1)+(i+2));
    }
    return b;
    }

int main(){
	float b;
	int n;
	cin>>n;
	int i=1;
	cout<<slash(b,n,i);
}
