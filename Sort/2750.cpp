#include <iostream>
#define MAX 1005
using namespace std;

class Global {
public:
	static void printList(int list[], int n) {
		for (int i = 0; i < n; i++) {
			cout << list[i] << '\n';
		}
	}

	// 선택정렬
	static void selectionSort(int list[], int n) {
		int mini = 0, tmp;
		for (int i = 0; i < n; i++) {
			mini = i;
			for (int j = i + 1; j < n; j++) {
				mini = list[mini] > list[j] ? j : mini;
			}
			tmp = list[i];
			list[i] = list[mini];
			list[mini] = tmp;
		}
		printList(list, n);
	}

	// 삽입정렬
	static void insertSort(int list[], int n) {
		int tmp;
		for (int i = 0; i < n; i++) {
			for (int j = i; j > 0; j--) {
				if (list[j] < list[j - 1]) {
					tmp = list[j];
					list[j] = list[j - 1];
					list[j - 1] = tmp;
				}
			}
		}
		printList(list, n);
	}
	
	// 버블정렬
	static void boubleSort(int list[], int n) {
		int tmp;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - 1; j++) {
				if (list[j] > list[j + 1]) {
					tmp = list[j];
					list[j] = list[j + 1];
					list[j + 1] = tmp;
				}
			}
		}
		printList(list, n);
	}
};

int main() {

	int n, list[MAX];

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> list[i];
	}

	//Global::boubleSort(list, n);
	//Global::insertSort(list, n);
	Global::selectionSort(list, n);

	return 0;
}