#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

void print(int** a, int n) { //функция, выводящая массив в файл
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			out << a[i][j] << ' ';
			if (a[i][j]<100) out<<' ';
			if (a[i][j]<10) out<<' ';
		}
		out << endl;
	}
}

void insertsort(vector<int>& x) { //функция, сортирующая массив методом вставками
    for (int i = 1; i < x.size(); ++i) {
        int j = i;
        while (j > 0 && x[j] < x[j - 1]) {
            swap(x[j], x[j - 1]);
            j--;
        }
    }
}


int main()
{
    setlocale(LC_ALL, "RUS");
    int n, count = 0;
    string tmp, t;
    while (getline(in, t)) {//считаем размер входного массива
        count++;
    }
    in.close();
    ifstream in("input.txt");
    n = count;

    int** a = new int* [n]; //создаем двумерный массив
    for (int i = 0; i < n; ++i) {
        a[i] = new int[n];
    }

    for (int i = 0; i < n; ++i) { //заполняем двумерный массив
        getline(in, tmp);
        for (int j = 0; j < n; ++j) {
            t = tmp.substr(0, tmp.find_first_of(' '));
            tmp.erase(0, tmp.find_first_of(' ') + 1);
            a[i][j] = stoi(t);
        }
    }

    for (int k = 1; k < 2 * n - 1; ++k) { //сортируем каждую диагональ по возрастанию функцией insertsort
        vector <int> sortedvector;
        int c = 0;
        for (int i = 0; i < n; ++i) {
            if (k - i < n && k - i >= 0) {
                sortedvector.push_back(a[i][k - i]);
            }
        }
        c = 0;
        insertsort(sortedvector);
        for (int i = 0; i < n; ++i) {
            if (k - i < n && k - i >= 0) {
                a[i][k - i] = sortedvector[c++];
            }
        }
        sortedvector.clear();
    }

    print(a, n);
    return 0;
}
