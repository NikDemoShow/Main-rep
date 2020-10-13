#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

void Print(vector<pair<double, int>>& v) {
	for (auto el : v) {
		cout << get<0>(el) << ' ' << get<1>(el) << endl;
	}
	cout << endl;
}

int main() {
	ifstream file("Algoses/inputpack.txt");
	unsigned int count;
	unsigned int val, weight;
	vector<int> C, W;
	file >> weight;
	file.ignore(1);
	file >> count;
	file.ignore(1);
	for (unsigned int i = 0; i < 2 * count; i++) {
		if (i < count) {
			file >> val;
			W.push_back(val);
			file.ignore(1);
		}
		else {
			file >> val;
			C.push_back(val);
			file.ignore(1);
		}

	}
	file.close();

	unsigned int** puck = new unsigned int* [count + 1];
	for (int i = 0; i <= count; i++) {
		puck[i] = new unsigned int[weight + 1];
		for (int j = 0; j <= weight; j++) {
			puck[i][j] = 0;
		}

	}
	for (int i = 1; i <= count; i++) {
		for (int j = 0; j <= weight; j++) {
			if (j >= W[i - 1]) {
				puck[i][j] = max(puck[i - 1][j], puck[i - 1][j - W[i - 1]] + C[i - 1]);
			}
			else {
				puck[i][j] = puck[i - 1][j];
			}
		}
	}
	/*
	for (unsigned int i = 0; i <= count; i++) {
		for (unsigned int j = 0; j <= weight; j++) {
			cout << puck[i][j] << ' ';
		}
		cout << endl;
	}
	*/
	cout << puck[count][weight];

	return 0;
}