#include<iostream>
#include<algorithm>
#include<string>
#include<fstream>
#include<iomanip>
#include<vector>
#include<bits/stdc++.h>
#include<cmath>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");

struct date{//����
    int dd, mm, yy;
};

struct people{//������ � ��������
    string Surname; //�������
    string Job;
    date DateOfBirth; //���� ��������
    int JobTime;
    int Salary; //��������
};

date Str_to_Date(string str){//�� ������ � ����
date x;
string temp = str.substr(0, 2);//����
x.dd = atoi(temp.c_str() );
temp = str.substr(3, 2);//�����
x.mm = atoi(temp.c_str());
temp = str.substr(6, 4);//���
x.yy = atoi(temp.c_str() );
return x;
}

vector<people> inFile(){//���� �� �����
    vector<people> x;
    people temp;
    while(in.peek() != EOF){
    in >> temp.Surname;//�������
    in >> temp.Job;
    string tmp;//���� ��������
    in >> tmp;
    temp.DateOfBirth = Str_to_Date(tmp);
    in >> temp.JobTime;
    in >> temp.Salary;//��������
    x.push_back(temp);
    }
    return x;
}

bool operator > (people a, people b) {//�������������� �������� >
    if (a.Surname > b.Surname) return true;
    if (a.DateOfBirth.yy > b.DateOfBirth.yy && a.Surname == b.Surname) return true;
    if (a.Surname == b.Surname && a.DateOfBirth.yy == b.DateOfBirth.yy && a.Salary > b.Salary) return true;
    return false;
}

void print(people x){//����� � ����
cout << setw(10) << left << x.Surname << " ";//�� ������ ����, 10 ������� ��� �������
cout << setw(10) << left << x.Job;//�� ������ ����, 10 ������� ��� �������
if (x.DateOfBirth.dd < 10) cout << left << '0' << x.DateOfBirth.dd << '.';//��������� 0
else cout << left << x.DateOfBirth.dd << '.';
if (x.DateOfBirth.mm < 10) cout << '0' << x.DateOfBirth.mm << '.';
else cout << x.DateOfBirth.mm << '.';
cout << left << setw(6) << x.DateOfBirth.yy;//�� ��� 6 �������
cout << x.JobTime ;//��������
cout << " " << x.Salary << endl;//��������
}

void evenoddsort(vector<people> &x){
    int n = x.size();
    for (int i = 0; i < n - 1; ++i) {
        if (i%2==0){
            for(int j = 2;j < n - 1;j+=2){
                if (x[j-1]>x[j]) swap(x[j-1],x[j]);
            }
        }
        else{
            for(int j = 1;j < n - 1;j+=2)
                if (x[j-1]>x[j]) swap(x[j-1],x[j]);
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    vector<people> x;
    x = inFile();
    evenoddsort(x);

    for (int i = 0; i < x.size(); ++i) {
        print(x[i]);
    }

    return 0;
}
