#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int main() {
	ifstream in;
	in.open("epic.txt");
	int n, pos;
	string str;
	map <string, int> words;
	string word;
	getline(in, str);
	str.push_back(' ');
	pos = 0;
	do {
		n = str.find_first_of(" ", pos);
		word = str.substr(pos, n-pos);

		if ((isdigit(word[0]))==false) {
            words[word]++;
		}
		pos = n + 1;
	} while (n != str.find_last_of(" "));
	map <string, int> ::iterator beg=words.begin();
	for (map <string, int> ::iterator it = words.begin(); it != words.end(); it++) {
        if (it->second==beg->second) cout << it->first<<endl;
	}
	for (map <string, int> ::iterator it = words.begin(); it != words.end(); it++) {
		cout << it->first << " " << it->second<<endl;
	}
}
