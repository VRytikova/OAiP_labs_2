#include <iostream>
#include<string>

using namespace std;

struct University {
	int student;
	string faculties;
	int groups;
	string firstStudent;
	University* next, * previous;
};

int n, i, number;
string facName;
University* start = 0, * present;
University* first, * last, * p;
int structSize;
University* key = NULL;


University *InStack(University *p, int number, string facName)
{
	University* present = new University;
	present->student = number;
	present->faculties = facName;
	present->next = p;
	return present;
}

University* InDeque() {
	cout << "Enter the number of groups" << endl;
	cin >> structSize;
	University* p = new University;
	cout << "Enter group number" << endl;
	cin >> p->groups;
	cout << "Enter last name of first student" << endl;
	cin >> p->firstStudent;
	p->next = p->previous = NULL;
	first = last = p;
	for (i = 1; i < structSize; i++) {
		p = new University;
		cout << "Enter group number" << endl;
		cin >> p->groups;
		cout << "Enter last name of first student" << endl;
		cin >> p->firstStudent;
		p->next = NULL;
		p->previous = last;
		last->next = p;
		last = p;
	}
	return p;
}

void viewStack(University* p) 
{
	University* present = p;
	do {
		cout << present->student <<"\t"<< present->faculties << endl;
		present = present->next;
	} while (present != NULL);
}

void viewFromBeginning() {
	p = first;
	do {
		cout << "The group: " << p->groups << "\t" << "First student: " << p->firstStudent << endl;
		p = p->next;
	} while (p != NULL);
}

void viewFromEnd() {
	p = last;
	do {
		cout << "The group: " << p->groups << "\t" << "First student: " << p->firstStudent << endl;
		p = p->previous;
	} while (p != NULL);
}

void delStack(University **p)
{
	University* present;
	do {
		present = *p;
		*p = (*p)->next;
		delete present;
	} while (*p != 0);
}

void delDeque() {
	int choice;
	int search;
	string ssearch;
	cout << "Choose field for search: " << "\n" << "1-group number" << "\n" << "2-first student" << endl;
	cin >> choice;
	switch (choice) {
	case 1:
		cout << "Enter the element of search" << endl;
		cin >> search;
		p = first;
		do {
			if (p->groups == search)
			{
				cout << "this" << endl;
				key = p;
				break;
			}
			else p = p->next;
		} while (p != NULL);
		break;
	case 2:
		cout << "Enter the element of search" << endl;
		cin >> ssearch;
		p = first;
		do {
			if (p->firstStudent == ssearch)
			{
				cout << "this" << endl;
				key = p;
				break;
			}
			else p = p->next;
		} while (p != NULL);
		break;
	}

	if (key == NULL) exit(0);
	else {
		if (key == first) {
			first = first->next;
			first->previous = NULL;
			delete key;
		}
		else if (key == last) {
			last = last->previous;
			last->next = NULL;
			delete key;
		}
		else {
			key->previous->next = key->next;
			key->next->previous = key->previous;
			delete key;
		}
	}
}

int outStack(University** p)
{
	int out;
	string outch;
	University* present = *p;
	out = (*p)->student;
	outch = (*p)->faculties;
	cout << "Start info =" << out << "," << outch << endl;
	*p = (*p)->next;
	delete present;
	return out;
}


int main(){
	int k;
	do {
	cout << "1-enter stack" << "\n" << "2-view stack" << "\n" << "3-first element of stack out" << "\n" << "4-delete stack" << endl;
	cout << "5-enter deque" << "\n" << "6-view deque from the beginning" << "\n" << "7-view deque from the end" << "\n" << "8-delete element of deque" << endl;
	cout << "Choose\t";
	cin >> k;
		switch (k) {
		case 1:
			cout << "n = ";
			cin >> n;
			for (i = 0; i < n; i++) {
				cout << "The number of students is " << endl;
				cin >> number;
				cout << "The name of the faculty is " << endl;
				cin >> facName;
				start = InStack(start, number, facName);
			}
			break;
		case 2:
			if (start == NULL) {
				cout << "stack is empty" << endl;
				exit(0);
			}
			else viewStack(start);
			break;
		case 3:
			if (start == NULL) {
				cout << "stack is empty" << endl;
				exit(0);
			}
			else int out = outStack(&start);
			break;
		case 4:
			if (start == NULL) {
				cout << "stack is empty" << endl;
				exit(0);
			}
			else delStack(&start);
			cout << "all stack is deleted" << endl;
			break;
		case 5:
				InDeque();
				break;
		case 6: 
			viewFromBeginning();
			break;
		case 7:
			viewFromEnd();
			break;
		case 8:
			delDeque();
			break;
		default:
			cout << "ERROR" << endl;
			exit(0);
		}
	} while (k < 10);
	
}