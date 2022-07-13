#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 100
using namespace std;

class User {
	int age;
	string name;

public:
	User() {
		age = 0;
		name = "noname";
	}
	User(int a, string n) {
		age = a;
		name = n;
	}

	void set(int a, string n) {
		age = a;
		name = n;
	}

	int getAge() { return age; }
	string getName() { return name; }

	bool operator <= (User u) {
		if (this->age <= u.age) {
			return true;
		}
		return false;
	}

	string toString() {
		return to_string(age) + " " + name;
	}
};

class Merge {
	int size;
	User *list;
	User *sorted;

public:
	Merge() {
		size = 0;
		list = new User[MAX]{};
		sorted = new User[MAX]{};
	}

	~Merge() {
		delete[] list;
		delete[] sorted;
	}

	void set(int n) {
		int a;
		string na;
		User tmp;
		size = n;

		for (int i = 0; i < size; i++) {
			cin >> a >> na;
			tmp.set(a, na);
			list[i] = tmp;
		}
	}

	void sort(int L, int R) {
		if (L < R) {
			int mid = ((R - L) / 2) + L;
			sort(L, mid);
			sort(mid + 1, R);
			merge(L, mid + 1, R);
		}
	}

	void merge(int L, int M, int R) {
		int li = L, ri = M, index = L;

		while (li < M && ri <= R) {
			if (list[li] <= list[ri]) {
				sorted[index++] = list[li++];
			}
			else {
				sorted[index++] = list[ri++];
			}
		}

		for (int i = li; i < M; i++) {
			sorted[index++] = list[i];
		}
		for (int i = ri; i <= R; i++) {
			sorted[index++] = list[i];
		}

		for (int i = L; i <= R; i++) {
			list[i] = sorted[i];
		}
	}

	void print() {
		for (int i = 0; i < size; i++) {
			cout << list[i].toString() << '\n';
		}
	}
};

bool compare(User a, User b) {
	if (a.getAge() < b.getAge()) return true;
	return false;
}

int main() {
	int N;
	cin >> N;
	/*
	Merge mg;

	mg.set(N);
	mg.sort(0, N - 1);
	mg.print();
	*/

	vector<User> list;
	User tmp;
	int age;
	string name;
	for (int i = 0; i < N; i++) {
		cin >> age >> name;
		tmp.set(age, name);
		list.push_back(tmp);
	}

	stable_sort(list.begin(), list.end(), compare);

	for (auto i : list) {
		cout << i.getAge() << " " << i.getName() << "\n";
	}
	return 0;
}