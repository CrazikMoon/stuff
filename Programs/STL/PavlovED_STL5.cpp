#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main(){
    int n,x;
    cout<<"n=";
    cin>>n;     // ввод кол-ва символов
    cout<<endl;

    vector<int> vec;
    cout << "Enter the sequence of numbers :";
    for(int i = 0; i < n; i++){//заполнение
        cin >> x;
        vec.push_back(x);
    }
    cout << endl;
    int Max = *max_element(vec.begin(), vec.end()); //макс элемент
    int Min = *min_element(vec.begin(), vec.end()); //мин элемент
    for(vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++){
        if (*iter == Min) { // если данный элемент минимальный
            vec.insert(iter + 1, Max); // вставить после него максимальный элемент
        }
    }
    for(vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter ++){
        cout << *iter <<" ";    // вывод последовательности
    }
}
