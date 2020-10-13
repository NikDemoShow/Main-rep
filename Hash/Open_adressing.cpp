#include<iostream>
#include<string>
#include<fstream>
#include<set>
#include<ctime>
#include<vector>
#include<iomanip>
using namespace std;

#define M 500000
/*
* »сследование зависимости коллизий и максимального количества попыток
* найти новую €чейку от размера таблицы и функции
*/

int degree(int a, int b) {
	for (int i = 0; i < b; i++) {
		a *= a;
	}
	return a;
}

struct paire {
	string key, value;
	paire(string new_key, string new_value) {
		key = new_key;
		value = new_value;
	}
};


int hash_f(const string& s, int f, int try_key, int size) {
	unsigned int hash_res = 0;
	for (int i = 0; i < s.size(); i++) {
		switch (f) {
		case (0):
			hash_res += degree((s[i] * 31), i) % (M + 100000 * size);
			break;
		case(1):
			hash_res += (s[i] * degree(53, i)) % (M + 100000 * size);
			break;
		case(2):
			hash_res += (s[i] * degree(31, i)) % (M + 100000 * size);
			break;
		}
	}
	return (hash_res + try_key) % M;
}

bool is_eq_words(string s_1, string s_2) {
	int i = 0;
	while (i < s_1.size()) {
		if (s_1[i] != s_2[i]) {
			if (s_1[i - 1] != s_2[i]) {
				s_1.erase(i - 1, 1);
			}
			else {
				return false;
			}
		}
		else {
			i++;
		}
	}
	return s_1 == s_2;

}

string short_word(string word, int lit) {
	int count = 1, i = 1;
	while (i < word.size()) {
		if (word[i] == word[i - 1]) {
			count++;
		}
		else {
			count = 1;
		}
		if (count >= lit + 1) {
			word.erase(i, 1);
		}
		else {
			i++;
		}
	}
	return word;
}

int from_file_to_dict(string Dict[], string name, int f, int i) {
	string word;
	int collision = 0, max_try = 1;
	ifstream file(name);
	set <int> h;
	getline(file, word);
	while (file) {
		int try_key = 1;
		while (true) {
			int key = hash_f(short_word(word, 1), f, try_key, i);
			//cout << key << endl;
			if (Dict[key] != "") {
				collision++;
				try_key++;
			}
			else {
				Dict[key] = word;
				h.insert(key);
				break;
			}
			if (try_key > 1000000) {
				cout << Dict[key] << ' ' << word << ' ' << try_key << endl;
			}
		}
		max_try = max(max_try, try_key);
		getline(file, word);
	}
	file.close();
	cout << "Collision = " << collision << '\n' <<
		"Different hesh-values = " << h.size() << '\n' <<
		"Max try = " << max_try << endl;
	return collision;
}

int main() {
	double s_time, f_time;
	string word;
	ofstream points("points.txt");
	int count = 3;
	for (int i = 0; i < 36; i++) { 
		for (int f = 0; f < count; f++) {
			int collision = 0;
			s_time = clock();
			string* Dict_exp = new string [M + i * 100000];
			cout << "Hesh function " << f + 1 << " with table size = " << M + 100000 * i << endl;
			collision = from_file_to_dict(Dict_exp, "dict.txt", f, i);
			f_time = clock();
			points << M / 10000 + i * 10 << ';' << collision << endl;
			cout << "Time = " << (f_time - s_time) / 1000 << " sec" << '\n' << endl;
			delete[] Dict_exp;
		}
	}
	points.close();


	/*  
	cout << "Hesh function in programm" << endl;
	vector<pair<string, string>>* Dict = new vector<pair<string, string>>[M];
	from_file_to_dict(Dict, "dict.txt", 0);

	int n;
	string req;
	cin >> n;

	for (int i = 0; i < n; i++) {
		bool find = false;
		cin >> req;
		int key = hash_f(short_word(req, 1), 0);
		if (Dict[key].size()) {
			string short_req = short_word(req, 1);
			for (auto el : Dict[key]) {
				if (el.first == short_req) {
					if (is_eq_words(short_word(req, 2), el.second)) {
						cout << req << " -> " << el.second << endl;
						find = true;
					}
				}
			}
		}
		if (!find) {
			cout << req << " -> " << "there isn't such word!" << endl;
		}
		find = false;
	}
	*/
	return 0;
}