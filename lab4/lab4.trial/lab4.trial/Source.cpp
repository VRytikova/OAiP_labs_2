#include<iostream>
using namespace std;

//struct University {
//	int course;
//	int group;
//};
//
//struct University* arrAy;
int siZe;
int arrAy[20];

//struct University *enter_array() {
//	
//	cout << "enter the size of array" << endl;
//	cin >> siZe;
//	University* arrAy = new University[siZe];
//	for (int i = 0; i < siZe; i++) {
//		/*cout << "enter the course ";
//		cin >> array[i].course;*/
//		/*cout << "enter the number of groups ";
//		cin >> array[i].group;*/
//		arrAy[i].course = (rand() % 10+0);
//		arrAy[i].group = (rand() % 7+0);
//	}
//	for (int i = 0; i < siZe; i++) {
//		cout << "the course: " << arrAy[i].course << "\t" << "the number of groups: " << arrAy[i].group << endl;
//	}
//	return arrAy;
//}

void selectionSort(int arr[], int n) {
	int j = 0, tmp = 0;
	if (arr != NULL) {
		for (int i = 0; i < n; i++) {
			j = i;
			for (int k = i + 1; k < n; k++) {
				if (arr[i] > arr[k]) {
					j = k;
				}
			}
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;

		}
		cout << "\n" << "after selectSort" << "\n" << endl;
		for (int i = 0; i < n; i++) {
			cout << "number: " << arr[i] << endl;
		}
	}
	else cout << "mistake" << endl;

}

void insertionSort(int arr[], int n) {
	int key = 0, i = 0;
	if (arr != NULL) {
		for (int j = 1; j < n; j++) {
			key = arr[j];
						i = j - 1;
			while (i >= 0 && arr[i] > key) {
				arr[i + 1] = arr[i];
				
				i = i - 1;
				arr[i + 1] = key;
				
			}
		}
		cout << "\n" << "after insertionSort" << "\n" << endl;
		for (int i = 0; i < n; i++) {
			cout << "number: " << arr[i]<< endl;
		}
	}
	else cout << "mistake" << endl;
}

void gnomeSort(int arr[], int n) {
	int i = 1;
	if (arr != NULL) {
	while (i < n) {
		if (i == 0) {
			i = 1;
		}
		if (arr[i - 1] <= arr[i]) ++i;
		else {
			int tmp = arr[i];
			arr[i] = arr[i - 1];
			arr[i - 1] = tmp;

			--i;
		}
	}
	cout << "\n" << "after gnomeSort" << "\n" << endl;
	for (int i = 0; i < n; i++) {
		cout << "number: " << arr[i] << endl;
	}
	}
	else cout << "mistake"<<endl;

}

void choice() {
	int choice;
	do {
		cout << "1 - selectionSort" << "\n" << "2 - insertionSort" << "\n" << "3 - gnomeSort" << endl;
		cout << "Choose: ";
		cin >> choice;
		switch (choice) {
		case 1:
			selectionSort(arrAy, siZe);
			break;
		case 2:
			insertionSort(arrAy, siZe);
			break;
		case 3:
			gnomeSort(arrAy, siZe);
			break;
		default:
			delete arrAy;
			exit(0);
		}
	} while (choice >= 1);
}

int main() {
	cout << "enter the size of array" << endl;
	cin >> siZe;
	/*int* arrAy = new int[siZe];*/
	for (int i = 0; i < siZe; i++) {
		arrAy[i]= rand() % 10;
	}
	for (int i = 0; i < siZe; i++) {
		cout << "number: " << arrAy[i] << endl;
	}
	choice();
}