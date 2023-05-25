#include<iostream>
using namespace std;

int main(){
int x,y;
cin>>x>>y;
if (x>y){
    if ((x-y)<(7-x+y))
        cout<<x-y<<" "<<7-x+y;
    else
        cout<<7-x+y<<" "<<x-y;
}

else{
    if ((y-x)<(7-y+x))
        cout<<y-x<<" "<<7-y+x;
    else
        cout<<7-y+x<<" "<<y-x;
}
}
