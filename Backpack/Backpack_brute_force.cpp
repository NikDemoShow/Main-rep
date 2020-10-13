#include<iostream>
#include<fstream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

void Print(vector<int>& v) {
	for (auto el : v) {
		cout << el << endl;
	}
}

void Read_file(vector<double>& costs, vector<double>& items_weights, int& count, double& weight, const string& dir) {
	ifstream file(dir);
	double val;
	file >> weight;
	file.ignore(1);
	file >> count;
	file.ignore(1);
	for (int i = 0; i < 2 * count; i++) {
		if (i < count) {
			file >> val;
			items_weights.push_back(val);
			file.ignore(1);
		}
		else {
			file >> val;
			costs.push_back(val);
			file.ignore(1);
		}

	}
}

int rec(const vector<double>& costs, const vector<double>& items_weights, int ind, int weight, double w_now) {
	if (ind < 0) 
	{return 0;}
	int res = 0;
	if (w_now + items_weights[ind] <= weight) {
		res = rec(costs, items_weights, ind - 1, weight, w_now + items_weights[ind]) + costs[ind];
	}
	return max(res, rec(costs, items_weights, ind - 1, weight, w_now));
}

int main() {
	int count;
	double weight;
	vector<double> costs, items_weights;
	Read_file(costs, items_weights, count, weight, "Algoses/inputpack.txt");
	cout << rec(costs, items_weights, count - 1, weight, 0);

	return 0;
}