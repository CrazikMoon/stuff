#include<iostream>
using namespace std;

float cheb(int b,int x,int i,int n){
	if (i<=n){
		if (i==0){
			b=1;
		}
		else if (i==1) 
			b=2*x-1;
		else b=2*b;
	return cheb(b,x,i+1,n);
	}
	else cout<<b<<endl;
}

int main(){
	int b;
	int x;
	cin>>x;
	int n,i=0;
	cin>>n;
	cheb(b,x,i,n);
	if (n==0) b=1;
	else{	
		b=2*x-1;
		for (int j=2;j<=n;j++){ 
				b=2*b;
		}
	}
	cout<<b;
}
