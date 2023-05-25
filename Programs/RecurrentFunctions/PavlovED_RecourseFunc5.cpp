#include<iostream>
using namespace std;

float geom(float b,float q,float s,int i,int n){
	if (i<=n){
		b=b*q;
		s+=b;
		return geom(b,q,s,i+1,n);
	}
	else
		cout<<b<<" "<<s<<endl;
}

int main(){
	float b,q;
	cin>>b>>q;
	float s=b;
	int n,i=1;
	cin>>n;
	geom(b,q,s,i,n);
	for (int j=1;j<=n;j++){
		b*=q;
		s+=b;
	}
	cout<<b<<" "<<s;
}
