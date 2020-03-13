#include<iostream>
#include<string>

using namespace std;

struct University {
	int groups;
	string firstStudent;
	University* next, *previous;
};

University* last, * first, *p;
int structSize,i;
University* key = NULL;

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

void viewFromBeginning() {
	p = first;
	do {
		cout << "The group: " << p->groups <<"\t"<< "First student: " << p->firstStudent << endl;
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

void del() {
	int choice;
	int search;
	string ssearch;
	cout << "Choose field for search: " << "\n" << "1-group number" <<"\n"<< "2-first student" << endl;
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
		else if(key == last) {
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

int main() {
	
    InDeque();
	viewFromBeginning();
	del();
	viewFromEnd();
}

