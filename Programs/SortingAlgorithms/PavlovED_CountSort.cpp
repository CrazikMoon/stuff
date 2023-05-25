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
			if(a[i][j]<10) out<<' ';
		}
		out << endl;
	}
}

void countsort(vector<int>& x,int min,int max) {//функция сортировки подсчетом
	int k = max - min + 1;
	vector<int> a(k);
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < x.size(); ++j) {
			if (x[j] == i + min) {
				a[i]++;
			}
		}
	}
	int pos = 0;
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < a[i]; ++j) {
			x[pos++] = i + min;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	int n, count = 0;
	int maxx=0,minx=100000000;
	string tmp, t;
	while (getline(in, t)) {//считаем размер входного массива
		count++;
	}
	ifstream in("input.txt");
	n = count;
	int** a = new int* [n]; //создаем двумерный массив
	for (int i = 0; i < n; ++i) {
		a[i] = new int[n];
	}
	for (int i = 0; i < n; ++i) {//заполняем двумерный массив
		getline(in, tmp);
		for (int j = 0; j < n; ++j) {
			string t = tmp.substr(0, tmp.find_first_of(' ')); //берём из файла число как string
			tmp.erase(0, tmp.find_first_of(' ') + 1);
			a[i][j] = stoi(t);
			maxx=max(maxx,a[i][j]);
			minx=min(minx,a[i][j]);
		}
	}

	for (int k = 0; k < n; ++k) { //сортируем каждую строку сортировкой подсчётом
		vector <int> sortedvector(n);
		for (int i = 0; i < n; ++i) {
			sortedvector[i] = a[k][i];
		}
		countsort(sortedvector,minx,maxx);
		for (int i = 0; i < n; ++i) {
			a[k][i] = sortedvector[i];
		}
	}
	print(a, n);
	return 0;
}
