#include <set>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include<cstdlib>
using namespace std;

int count = 0;
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


void print(people x){//����� � ����
out << setw(10) << left << x.Surname << " ";//�� ������ ����, 10 ������� ��� �������
out << setw(10) << left << x.Job;//�� ������ ����, 10 ������� ��� �������
if (x.DateOfBirth.dd < 10) out << left << '0' << x.DateOfBirth.dd << '.';//��������� 0
else out << left << x.DateOfBirth.dd << '.';
if (x.DateOfBirth.mm < 10) out << '0' << x.DateOfBirth.mm << '.';
else out << x.DateOfBirth.mm << '.';
out << left << setw(6) << x.DateOfBirth.yy;//�� ��� 6 �������
out << x.JobTime ;//��������
out << " " << x.Salary << endl;//��������
}

void merge(vector<people> &a, int l, int r, int m) {
    int i = l, j = m + 1;
    vector<people> buf;
    buf.resize(r - l + 1);
    int cur = 0;
    while ((i <= m) && (j <= r)) {
        if ((a[i].Salary < a[j].Salary)||((a[i].Salary == a[j].Salary) && (a[i].DateOfBirth.yy < a[j].DateOfBirth.yy))) {
            buf[cur++] = a[i++];
        }
        else buf[cur++] = a[j++];
    }

    while (i <= m) {
        buf[cur++] = a[i++];
    }
    while (j <= r) {
        buf[cur++] = a[j++];
    }
    for (int x = 0; x < buf.size(); ++x) {
        a[l + x] = buf[x];

	}
}

void merge_sort(vector<people>& a, int l, int r) {
    if (l < r) {
    int m = (l + r) / 2;
    merge_sort(a, l, m);
    merge_sort(a, m + 1, r);
    merge(a, l, r, m);
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    vector<people> x;
    x = inFile();
    merge_sort(x, 0, x.size() - 1);
    for (int i = 0; i < x.size(); ++i) {
        print(x[i]);
    }
    return 0;
}
