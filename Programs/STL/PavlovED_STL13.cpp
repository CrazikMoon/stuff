#include <iostream>
#include <vector> //�������������� ���������� vector
#include <algorithm> //�������������� ���������� algorithm
using namespace std;
vector<int> vec,vec1,vec2;
int X; //�������� ����� ��������� ������ ���� ��������
bool kratn(int x){//�� ������� X
return x % X == 0;
}
bool same(int v){
    bool e=0;
    for (int i=0;i<vec2.size();i++){
        if (v==vec2[i]){
            e=1;
            break;
        }
    }
    return e;
}
int main(){
    int n1,n2,x,d;
    cout<<"n1=";
    cin>>n1;     // ���� ���-�� ��������
    cout<<"n2=";
    cin>>n2;     // ���� ���-�� ��������
    cout << "Enter the first sequence of numbers :";
    for(int i = 0; i < n1; i++){//����������
        cin >> x;
        vec1.push_back(x);
    }
    cout<<endl;
    cout << "Enter the second sequence of numbers :";
    for(int i = 0; i < n2; i++){//����������
        cin >> x;
        vec2.push_back(x);
    }
    remove_if(vec1.begin(),vec1.end(),same);
    cout<<"Enter X:";
    cin>>X;
    cout<<endl;
    for(vector<int>::iterator iter = vec2.begin(); iter != vec2.end(); iter++){
        if (kratn(*iter)) { // ���� ������ ������� ������
            cout<<"Enter a new element: ";
            cin>>d;
            cout<<endl;
            vec2.insert(iter+1,d); // �������� ����� ���� �������
               for(vector<int>::iterator iter = vec2.begin(); iter != vec2.end(); iter ++){
        cout << *iter <<" ";    // ����� ������������������
    }
        }
    }
    sort(vec2.begin(),vec2.end());
    merge(vec1.begin(),vec1.end(),vec2.begin(),vec2.end(),back_inserter(vec));
    sort(vec.begin(),vec.end());
    for(vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter ++){
        cout << *iter <<" ";    // ����� ������������������
    }
}
