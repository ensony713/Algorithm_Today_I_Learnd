#include <iostream>
#define MAX 10
using namespace std;

void search(int start, int end, int data[]) {

	if (start >= end) { return; }

	int left = start + 1, right = end;

	for (int i = start + 1; i < end; i++) {
		if (data[start] < data[i]) {
			right = i;
			break;
		}
	}

	search(left, right, data);

	search(right, end, data);

	cout << data[start] << '\n';
}

int main(int argc, char** argv) {
	int n = 1, input;
	int data[MAX] = { 0 };

	while (cin >> input) {
		data[n++] = input;
	}

	search(1, n, data);

	return 0;
}