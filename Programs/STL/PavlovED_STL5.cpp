#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main(){
    int n,x;
    cout<<"n=";
    cin>>n;     // ���� ���-�� ��������
    cout<<endl;

    vector<int> vec;
    cout << "Enter the sequence of numbers :";
    for(int i = 0; i < n; i++){//����������
        cin >> x;
        vec.push_back(x);
    }
    cout << endl;
    int Max = *max_element(vec.begin(), vec.end()); //���� �������
    int Min = *min_element(vec.begin(), vec.end()); //��� �������
    for(vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++){
        if (*iter == Min) { // ���� ������ ������� �����������
            vec.insert(iter + 1, Max); // �������� ����� ���� ������������ �������
        }
    }
    for(vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter ++){
        cout << *iter <<" ";    // ����� ������������������
    }
}
