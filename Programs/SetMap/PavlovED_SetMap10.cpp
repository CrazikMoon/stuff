#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	int pos=0;
	int pos1 = 0;
	int k = 0;
	int k1=0;
	char x;
	cout << "Put the text" << endl;
	string str,signs,pred,word;
	set <string> other,quex;
	vector <string> answer;
	getline(cin, str);//�������������� ������ ���������� � ���������� �����
	signs = ".?!";//������ �� ������� ����������
	k = str.find_first_of(signs,pos);//������� ������ ���� ����������
	do
        {k = str.find_first_of(signs, pos);//������ � ����� ������� ��� ����������� �����
		pred = str.substr(pos, k - pos);//� pred ������� �� ����� ����� �������, �� ���� �����������
		pos1 = 0;
		k1 = pred.find_first_of(' ', pos1);//������� � ����������� ������ ������
		pred.push_back(' ');
		do {k1 = pred.find_first_of(' ', pos1);
			word = pred.substr(pos1, k1 - pos1);//������� � word �� ����� ����� ����� ���������
			for (int i = 0; i < word.size(); i++) {
				x = tolower(word[i]);//������ ��� �������� � ����� �������
				word[i] = x;
			}
			if ((str[k] == '?')or(str[k]=='!')) quex.insert(word);
			else other.insert(word);//���� ���� ���������� � ����������� ������ ��� ����.���� �� ������� ����� � quex ����� � other
			pos1 = k1+1;//������ ����������� �� ����� ������� ��������� �������, ����� ����� ��������� ������

		} while (k1 != (pred.size() - 1));//��� �� �����
		pos = k+1;//����� �� ����������� � ��� ������
	} while (k != (str.size() - 1));//������� �� ����� ����� ���������� ���������� �����
	cout <<"Answer is" << endl;
	set_difference(quex.begin(), quex.end(), other.begin(), other.end(), inserter(answer,answer.end()));//������� ������� ����� ����������� ����������������� � ������ ����, ���������� ������� � ������ answer
	for (int i = 0; i < answer.size();i++) cout << answer[i] << " ";//������� �����
}
