#include<iostream>
using namespace std;

struct University {
	int course;
	int group;
};

struct University arrAy[10];
int siZe;

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

void selectionSort(University arr[],  int n) {
	int j = 0, tmp = 0;
	if (arr != NULL) {
		for (int i = 0; i < n; i++) {
			j = i;
			for (int k = i + 1; k < n; k++) {
				if (arr[i].course > arr[k].course) {
					j = k;
				}
			}
			tmp = arr[i].course;
			arr[i].course = arr[j].course;
			arr[j].course = tmp;

			tmp = arr[i].group;
			arr[i].group = arr[j].group;
			arr[j].group = tmp;
		}
		cout << "\n" << "after selectSort" << "\n" << endl;
		for (int i = 0; i < n; i++) {
			cout << "the course: " << arr[i].course << "\t" << "The number of groups: " << arr[i].group << endl;
		}
	}
	else cout << "mistake"<<endl;

}

void insertionSort(struct University arr[], int n) {
	int key = 0, i = 0;
	int keyG;
	if (arr != NULL) {
		for (int j = 1; j < n; j++) {
			key = arr[j].course;
			keyG = arr[j].group;
			i = j - 1;
			while (i >= 0 && arr[i].course > key) {
				arr[i + 1].course = arr[i].course;
				arr[i + 1].group = arr[i].group;
				i = i - 1;
				arr[i + 1].course = key;
				arr[i + 1].group = keyG;
			}
		}
		cout << "\n" << "after insertionSort" << "\n" << endl;
		for (int i = 0; i < n; i++) {
			cout << "the course: " << arr[i].course << "\t" << "The number of groups: " << arr[i].group << endl;
		}
	}
	else cout << "mistake"<<endl;
}

void gnomeSort(struct University arr[], int n) {
	int i=1;
	if (arr != NULL) {
		while (i < n) {
			if (i == 0) {
				i = 1;
			}
			if (arr[i - 1].course <= arr[i].course) ++i;
			else {
				int tmp = arr[i].course;;
				arr[i].course = arr[i - 1].course;
				arr[i - 1].course = tmp;

				tmp = arr[i].group;
				arr[i].group = arr[i - 1].group;
				arr[i - 1].group = tmp;

				--i;
			}
		}
		cout << "\n" << "after gnomeSort" << "\n" << endl;
		for (int i = 0; i < n; i++) {
			cout << "the course: " << arr[i].course << "\t" << "The number of groups: " << arr[i].group << endl;
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
			selectionSort(arrAy,siZe);
			break;
		case 2:
			insertionSort(arrAy, siZe);
			break;
		case 3:
			gnomeSort(arrAy, siZe);
			break;
		default: 
			exit(0);
		}
	} while (choice >= 1);
}

int main() {
	cout <<"enter the size of array" << endl;
	cin >> siZe;
	/*University* arrAy = new University[siZe];*/
	for (int i = 0; i < siZe; i++) {
		arrAy[i].course = (rand() % 10 + 0);
		arrAy[i].group = (rand() % 7 + 0);
	}
	for (int i = 0; i < siZe; i++) {
		cout << "the course: " << arrAy[i].course << "\t" << "the number of groups: " << arrAy[i].group << endl;
	}
	choice();
}