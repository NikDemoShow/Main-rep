#include<iostream>
#include<fstream>
using namespace std;

struct Node {
	int key;
	int data;
	Node* left = NULL;
	Node* right = NULL;
};


Node* ADD(Node* root, int key) {
	if (!root) {
		Node* new_node = new Node;
		new_node->key = key;
		new_node->left = NULL;
		new_node->right = NULL;
		root = new_node;
	}
	else if (key < root->key) {
		root->left = ADD(root->left, key);
	}
	else{
		root->right = ADD(root->right, key);
	}
	return root;
}

void Print_Tree(const Node* root) {
	if (root->left) {
		Print_Tree(root->left);
	}
	cout << root->key << endl;
	if (root->right) {
		Print_Tree(root->right);
	}
}

void Interval(Node* root, int min, int max) {
	if (root->left && root->key >= min) {
		Interval(root->left, min, max);
	}
	if (root->key >= min && root->key <= max) {
		cout << root->key << endl;
	}
	if (root->right && root->key <= max) {
		Interval(root->right, min, max);
	}
}

auto Find(Node* root, int key) {
	if (root->key == key) {
		return 1;
	}
	else {
		if (root->left && key < root->key) {
			return Find(root->left, key);
		}
		if (root->right && key > root->key) {
			return Find(root->right, key);
		}
	}
}

int main() {
	ifstream file;
	file.open("input.txt");
	Node* tree = NULL;
	int value, min, max;
	string req;
	while (file) {
		file >> value;
		file.ignore(1);
		tree = ADD(tree, value);
	}
	file.close();
	cout << "Add <value>\nFind <value>\nInterval <min_value max<value>\nEnd\n----------" << endl;
	while (true) {
		cout << "Enter request" << endl;
		cin >> req;
		if (req == "Add") {
			cin >> value;
			ADD(tree, value);
			cout << "Added " << value << endl;
		}
		if (req == "Find") {
			cin >> value;
			if (Find(tree, value) == 1) {
				cout << "Finded " << value << endl;
			}
			else {
				cout << "There isn't such value" << endl;
			}
		}
		if (req == "Interval") {
			cin >> min >> max;
			Interval(tree, min, max);
		}
		if (req == "End") {
			return 0;
		}
	}
}