#include<iostream>
#include<fstream>
#include<vector>
#include<utility>
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
	int count;
	double val, weight;
	vector<double> costs, items_weights;
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
	vector<pair<double, int>> unit_costs;
	for (int i = 0; i < count; i++) {
		unit_costs.push_back({ costs[i] / items_weights[i], i });
	}
	sort(unit_costs.begin(), unit_costs.end(), [](pair<double, int> a, pair<double, int> b) {return get<0>(a) > get<0>(b);});

	int item = 0;
	double weight_now = 0;
	cout << "Need to take : ";
	while (weight_now < weight && item < count ) {
		if (items_weights[get<1>(unit_costs[item])] < weight - weight_now){
			weight_now += items_weights[get<1>(unit_costs[item])];
			cout << get<1>(unit_costs[item]) + 1 << " item, " ;
		}
		else {
			cout << (weight - weight_now) / items_weights[get<1>(unit_costs[item])] << " of " << // выводит долю от массы последнего предмета, вмещающегося в рюкзак; единицу в случае если масса предмета равна оставшемуся в рюкзаке месту
				get<1>(unit_costs[item]) + 1 << " item" << endl;
			weight_now = weight;
		}
		item++;
	}

	return 0;
}