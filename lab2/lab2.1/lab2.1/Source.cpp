#include<iostream>
using namespace std;

struct University {
	int classes;
	University* left, * right;
}*root = NULL;

University* leaf(int x) {
	University* tree = new University;
	tree->classes = x;
	tree->right = tree->left = NULL;
	return tree;
}

University* create(University* root) {
	University* previous=NULL, * t= NULL;
	int n, b, find;
	cout << "n= ";
	cin >> n;
	if (!root) {
		n--;
		/*
		cout << "Input root: ";
		cin >> b;*/
		b = rand() % 50;
		root = leaf(b);
	}
	for (int i = 1; i <= n; i++) {
		cout << "Input info: ";
		cin >> b;
		t = root;
		find = 0;
		while (t && !find) {
			previous = t;
			if (b == t->classes) {
				find = 1;
				cout << "There is the same" << endl;
			}
			else
				if (b < t->classes)t = t->left;
				else t = t->right;
		}
		if (!find) {
			t = leaf(b);
			if (b < previous->classes)
				previous->left = t;
			else previous->right = t;
		}
	}
	return root;
}

void addleaf(University* root, int key) {
	University* previous= NULL, * t=NULL;
	int find = 1;
	t = root;
	while (t && find) {
		previous = t;
		if (key == t->classes) {
			find = 0;
			cout << "There is the same" << endl;
		}
		else if (key < t->classes) t = t->left;
		else t = t->right;
	}
	if (find) {
		t = leaf(key);
		if (key < previous->classes) previous->left = t;
		else previous->right = t;
	}
}

University* del(University* root, int key) {
	University* del, * prev_del, * r, * prev_r;
	del = root;
	prev_del = NULL;
	while (del != NULL && del->classes != key) {
		prev_del = del;
		if (del->classes > key) del = del->left;
		else del = del->right;
	}
	if (del == NULL) {
		cout << "\nNo key" << endl;
			return root;
	}
	if (del->right == NULL) r = del->left;
	else if (del->left == NULL)r = del->right;
	else {
		prev_r = del;
		r = del->left;
		while (r->right != NULL) {
			prev_r = r;
			r = r->right;
		}
		if (prev_r == del)r->right = del->right;
		else {
			r->right = del->right;
			prev_r->right = r->left;
			r->left = prev_r;
		}
	}
	if (del == root)root = r;
	else if (del->classes < prev_del->classes)prev_del->left = r;
	else prev_del->right = r;
	cout << "delete " << del->classes << endl;
	delete del;
	return root;
}

void view(University* t, int level) {
	if (t) {
		view(t->right, level + 1);
		for (int i = 0; i < level; i++) cout << " ";
		cout << t->classes << endl;
		view(t->left, level + 1);
	}
}

void del_all(University *tree){
	if (tree != NULL) {
		del_all(tree->left);
		del_all(tree->right);
		delete tree;
		tree = NULL;
    }
}

void menu() {
	int choice;
	int in, key;
	do {
		cout << "Menu:\n 1-to create a tree\n 2-to add a leaf\n 3-to delete a node\n 4-to view a tree\n 5-to delete all tree\n 6-exit\n" << endl;
		cout << "Choose: ";
		cin >> choice;
		switch (choice) {
		case 1:
			root = create(root);
			break;
		case 2:
			cout << "Input info: ";
			cin >> in;
			if (root == NULL) root = leaf(in);
			else addleaf(root, in);
			break;
		case 3:
			cout << "Input del info: ";
			cin >> key;
			root = del(root, key);
			break;
		case 4:
			view(root, 0);
			break;

		case 5:
			del_all(root);
			break;
		case 6:
			exit(0);
		default:
			cout << "error";
			exit(0);
		}
	} while (choice < 10);
}

int main() {
	menu();
}