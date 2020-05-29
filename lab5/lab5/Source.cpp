#include <iostream>
using namespace std;

int groups[10], siZe;

int power(int x, unsigned int y)
{
	int d = 0;
	if (y == 0)
		d = 1;
	else if (y == 1)
		d = x;
	else if (y % 2 == 0)
		d = power(x * x, y / 2);
	else
		d = x * power(x * x, y / 2);
	return d;
}

int sum(int i, int A[], int n)
{
	if (i == n)
		return A[i];
	else
		return A[i] + sum(i + 1, A, n);
}

void choice() {
	int key;
	do {
		cout << "1 - raise the number of students of x group to the y power\n" << "2 - find the sum of students of all groups" << endl;
		cout << "3 - exit\n"<<"Choose: ";
		cin >> key;
		switch (key) {
		case 1:
			int coeff, a;
			cout << "enter the number of a group ";
			cin >> coeff;
			cout << "\n enter the power ";
			cin >> a;
			power(groups[coeff], a);
			cout << "The number of student of group " << coeff << " in power " << a << " is " << power(groups[coeff], a) << endl;
			break;
		case 2:
			cout << "the sum of students of all groups " << sum(1, groups, siZe)<<endl;
			break;
		case 3: 
			exit(0);
		default: 
			cout << "mistake" << endl;
			exit(0);
		}
	}while(key>0);
}

void main() {
	int i;
	cout << "enter the amount of groups ";
	cin >> siZe;
	for (i = 1; i <= siZe; i++) {
		groups[i] = rand() % 30;
	}
	for (i = 1; i <= siZe; i++) {
		cout << "The number of student in group " << i << " is " << groups[i] << endl;
	}
	choice();
}