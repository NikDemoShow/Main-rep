#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<iomanip>
using namespace std;

int main() {
	const int n = 80, m = 10;
	int A[n][m];
	/*int A[n][m] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 0},
		{0, 1, 0, 0, 0, 0, 0, 1, 0},
		{0, 1, 1, 1, 1, 1, 1, 1, 0},
		{0, 1, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 1, 1, 1, 1, 1, 1, 0},
		{0, 1, 0, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 0},
		{0, 1, 0, 1, 1, 0, 0, 1, 0},
		{0, 1, 0, 0, 0, 0, 0, 1, 0},
		{0, 1, 0, 0, 0, 0, 0, 1, 0},
		{0, 1, 0, 1, 1, 1, 1, 1, 0},
		{0, 1, 0, 1, 0, 1, 0, 0, 0},
		{0, 1, 1, 1, 1, 1, 1, 1, 0},
		{0, 1, 0, 0, 0, 0, 0, 1, 0},
		{0, 1, 1, 1, 1, 1, 1, 1, 0},
		{0, 1, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 1, 1, 1, 1, 1, 1, 1},
		{0, 0, 0, 0, 0, 0, 0, 0, 1},

	};*/
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 78 && j == 8) {
				A[i][j] = 0;
			}
			else {
				A[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (A[i][j]) {
				cout << '.' << ' ';
			}
			else {
				cout << '#' << ' ';
			}
		}
		cout << endl;
	}
	cout << endl;
	long long int dist[n][m] = { 0 };
	int x, y, x_e, y_e;
	cin >> x >> y >> x_e >> y_e;

	dist[x][y] = 1;
	//while (!q.empty()) {
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			if (A[x][y]) {
				if (x != n - 1 && A[x + 1][y]) {
					dist[x + 1][y] = dist[x][y] + dist[x + 1][y];
				}
				if (y != m - 1 && A[x][y + 1]) {
					dist[x][y + 1] = dist[x][y] + dist[x][y + 1];
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << setw(12) << dist[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;

	cout << dist[n - 1][m - 1] % 100000 << endl;

	return 0;
}