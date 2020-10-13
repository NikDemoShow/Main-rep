#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<stdlib.h>
using namespace std;

#define b 3
#define n 21
#define m 9

struct pare {
	int x;
	int y;

	pare(int n_x, int n_y) {
		x = n_x;
		y = n_y;
	}
	pare() {
		x = 0;
		y = 0;
	}
};

bool operator==(const pare& a, const pare& d) {
	return(a.x == d.x && a.y == d.y);
}


int main() {
	int A[n][m] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 0},
		{0, 1, 1, 1, 1, 1, 1, 1, 0},
		{0, 1, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 1, 1, 1, 1, 1, 1, 0},
		{0, 1, 0, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 0},
		{0, 1, 0, 1, 1, 1, 1, 1, 0},
		{0, 1, 0, 1, 0, 0, 0, 0, 0},
		{0, 1, 0, 1, 1, 1, 1, 1, 0},
		{0, 1, 0, 0, 0, 0, 0, 1, 0},
		{0, 1, 0, 1, 1, 1, 1, 1, 0},
		{0, 1, 0, 1, 0, 0, 0, 0, 0},
		{0, 1, 0, 1, 1, 1, 1, 1, 0},
		{0, 1, 0, 0, 0, 0, 0, 1, 0},
		{0, 1, 1, 1, 1, 1, 1, 1, 0},
		{0, 1, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 1, 1, 0, 1, 1, 1, 1},
		{0, 0, 0, 0, 0, 0, 0, 0, 1},

	};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (A[i][j]) {
				cout << setw(3) << ' ';
			}
			else {
				cout << setw(3) << '#';
			}
		}
		cout << endl;
	}

	int x, y;
	cin >> x >> y;

	int bomb[b + 2][n][m];
	int	step = -1;
	for (int bb = 0; bb < b + 1; bb++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				bomb[bb][i][j] = INT_MAX;
			}
		}
		bomb[bb][x][y] = 0;
	}
	pare Way[n][m];

	while (bomb[b][n - 1][m - 1] == INT_MAX) {
		step++;
		for (int bb = 0; bb < b + 1; bb++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (bomb[bb][i][j] == step) {
						if (i) {
							if (A[i - 1][j] && bomb[bb][i - 1][j] == INT_MAX) {
								bomb[bb][i - 1][j] = step + 1;
								Way[i - 1][j] = { i, j };
							}
							else {
								if (bomb[bb + 1][i - 1][j] > step + 1) {
									bomb[bb + 1][i - 1][j] = step + 1;
									Way[i - 1][j] = { i, j };
								}
							}
						}if (j) {
							if (A[i][j - 1] && bomb[bb][i][j - 1]==INT_MAX) {
								bomb[bb][i][j - 1] = step + 1;
								Way[i][j - 1] = { i, j };
							}
							else {
								if (bomb[bb + 1][i][j - 1] > step + 1) {
									bomb[bb + 1][i][j - 1] = step + 1;
									Way[i][j - 1] = { i, j };
								}
							}
						}if (i != n - 1) {
							if (A[i + 1][j] && bomb[bb][i + 1][j] == INT_MAX) {
								bomb[bb][i + 1][j] = step + 1;
								Way[i + 1][j] = { i, j };
							}
							else {
								if (bomb[bb + 1][i + 1][j] > step + 1) {
									bomb[bb + 1][i + 1][j] = step + 1;
									Way[i + 1][j] = { i, j };
								}
							}
						}if (j != m - 1) {
							if (A[i][j + 1] && bomb[bb][i][j + 1] == INT_MAX) {
								bomb[bb][i][j + 1] = step + 1;
								Way[i][j + 1] = { i, j };
							}
							else {
								if (bomb[bb + 1][i][j + 1] > step + 1) {
									bomb[bb + 1][i][j + 1] = step + 1;
									Way[i][j + 1] = { i, j };
								}
							}
						}
						/*
						for (int bb = 0; bb < b + 1; bb++) {
							for (int i = 0; i < n; i++) {
								for (int j = 0; j < m; j++) {
									cout << setw(4) << bomb[bb][i][j] << ' ';
								}
								cout << endl;
							}
							cout << endl;
						}
						cout << "---------------------------" << endl;
						*/
					}
				}
			}
		}
	}
	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << setw(5) << Way[i][j].x << '-' << Way[i][j].y << ' ';
		}
		cout << endl;
	}
	cout << endl;
	*/
	
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << setw(10) << bomb[b][i][j] << ' ';
			}
			cout << endl;
		}
	cout << "---------------------------" << endl;

	
	cout << "Way length = " << bomb[b][n - 1][m - 1] << endl;
	
	vector<pare> way;
	{
		x = n - 1;
		y = m - 1;
		while (x || y) {
			way.push_back({ x, y });
			int x_cont = Way[x][y].x;
			int y_cont = Way[x][y].y;
			x = x_cont;
			y = y_cont;
		}
		reverse(begin(way), end(way));
		for (auto el : way) {
			cout << '(' << el.x << " ," << el.y << ')' << " -> ";
		}
		cout << "Exit" << endl;
		cout << "Bad Way length = " << way.size() << endl;
	}

	/*
	for (int bb = 0; bb < b + 1; bb++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << setw(4) << bomb[bb][i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl;
	}
	*/
	
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (end(way) != find(begin(way), end(way), pare(i, j))) {
					if (A[i][j]) {
						cout << setw(3) << '.';
					}
					else {
						cout << setw(3) << '*';
					}
				}
				else if (A[i][j]) {
					cout << setw(3) << ' ';
				}
				else {
					cout << setw(3) << '#';
				}
			}
			cout << endl;
		}
		


	return 0;
}