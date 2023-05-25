#include <iostream>
#include <vector> //�������������� ���������� vector
#include <string> //�������������� ���������� string
#include <fstream> //�������������� ���������� fstream
#include <set> //�������������� ���������� set
#include <random> //�������������� ���������� random
#include <ctime>
#include<algorithm>
using namespace std;

random_device rd;
mt19937 gen(rd());

int random(int low, int high) //������� ��� ��������� ��������� �����
{
	uniform_int_distribution<> dist(low, high);
	return dist(gen);
}

int main() {
    setlocale(LC_ALL, "RUS");
    srand(time(0)+17);
    string unguessed; //������ set �� ����� ������� ����������� �����
	unguessed="a b c d e f g h i j k l m n o p q r s t u v w x y z";
	vector<string>words; //������ ������, ������� ����� ��������� ��� ����� ����������� �����
	ifstream file;
	file.open("words.txt");
	if (!file.is_open()) //���������, ���������� �� ������� ���� �����
		cout << "�� ������� ������� ����.";
	else {
		string s;
		while (!file.eof()) //���� �� �� ����� �� ����� �����
		{
			getline(file, s); //��������� ������ �� ������
			words.push_back(s); //��������� ����� � ������ words
		}
	}
	file.close(); //��������� ���� �����
	int random_pos = random(0, words.size()); //���� ��������� ������� ������� words
	string word = words[random_pos]; //���� ����� �� ��������� ������� � �������� ������������
	string shown(word.size(), '_'); //������ ������ shown ������ �� �������, ��� � ����������� �����, ��������� �� _
	cout << "�����: " << shown << endl;
	bool f = 0;
	int turn = 1, max;
	cout << "������� ������������ ���-�� �����: ";
	cin >> max;
	while (shown.find("_") != string::npos && turn <= max) { //���� �� �������� ����������� ����� ��� ���� �� �������� ����, ���� ������������
		cout << endl;
		cout << "���: " << turn << endl;
		cout << "�������� �����: " << max - turn << endl;
		cout << "���������������� �����: "<<unguessed<<endl;
		cout << endl << "�����: " << shown << endl;
		cout << "�� ������ ������� ����� ������� (Yes/No)?";
		string choose, wordguess;
		char guess;
		cin >> choose;
		if (choose == "Yes") { //����������� ������� ����� �������
			cout << "��� �����: ";
			cin >> wordguess;
			if (wordguess == word) { //���� ��������� ����� �����, �� ���� �������������
				cout << "����������, �� ��������! ���������� �����: " << word << endl;
				f = 1;
				break;
			}
			else { //����� ���������� ���� � ����������� ��� �� 1
				cout << "�������." << endl;
				turn++;
				continue;
			}
		}
		else { //���� �� �� ����� ��������� �� ����� �����
			cout << "� ����� ������, ������� �������������� �����: ";
			cin >> guess; //����������� �����
			int pos = unguessed.find(guess);
			unguessed.erase(pos,2);
			if (word.find(guess) != string::npos) { //���� ����� ����� ���� � �����
				int start = 0;
				vector<int>pos;
				while (word.find(guess, start) != string::npos) { //���� �������� ������� ��� ��������� ���� ����� � �����
					pos.push_back(word.find(guess, start));
					start = word.find(guess, start) + 1;
				}
				for (int i = 0; i < pos.size(); ++i)
					shown[pos[i]] = word[pos[i]]; //�������� � ������������ ������ ��� _ �� ����� �� �����
				cout << "�� ������� �����." << endl;
				turn++;
				continue;
			}
			else { //����� ������ ��������� �� ������ ���
				cout << "�� ������� �������." << endl;
				turn++;
				continue;
			}
		}
	}
	if (f == 0)
		if (shown.find("_") == string::npos) //���� � ����� ���� ����� �������, ������� ���������, ��� ����� �������
			cout << endl << "����������, �� ��������! ���������� �����: " << word;
		else //����� ������� ��������� � ���������
			cout << endl << "� ��� �� �������� �����, �� ���������. ���������� �����: " << word;
	return 0;
}


