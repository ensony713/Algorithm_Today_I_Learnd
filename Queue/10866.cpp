#include <iostream>
#define MAX 10000
using namespace std;

class Deque{
    
    int data[MAX] = { 0 };
    int f, b;
    
    int set(int i) {
        i %= MAX;
        if (i < 0) { i += MAX; }
        return i;
    }
    
public:

    Deque() {
        f = 0;
        b = 0;
    }
    
    void push_front(int x) {
        f = set(f - 1);
        data[f] = x;
    }
    
    void push_back(int x) {
        data[b] = x;
        b = set(b + 1);
    }
    
    int size() {
        if (f > b) { return MAX + (b - f); }
        return b - f;
    }
    
    int empty() {
        if (f == b) { return 1; }
        return 0;
    }
    
    int front() {
        if (empty()) { return -1; }   
        return data[f];
    }
    
    int back() {
        if (empty()) { return -1; }
        return data[set(b - 1)];
    }
    
    int pop_back() {
        if (empty()) { return -1; }
        b = set(b - 1);
        return data[b];
    }
    
    int pop_front() {
        if (empty()) { return -1; }
        int tmp = data[f];
        f = set(f + 1);
        return tmp;
    }
};

Deque dq;

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, x;
	string op;
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
	    cin >> op;
	    
	    if (op == "push_back") {
	        cin >> x;
	        dq.push_back(x);
	    }
	    else if (op == "push_front") {
	        cin >> x;
	        dq.push_front(x);
	    }
	    else if (op == "pop_front") {
	        cout << dq.pop_front() << '\n';
	    }
	    else if (op == "pop_back") {
	        cout << dq.pop_back() << '\n';
	    }
	    else if (op == "size") {
	        cout << dq.size() << '\n';
	    }
	    else if (op == "empty") {
	        cout << dq.empty() << '\n';
	    }
	    else if (op == "front") {
	        cout << dq.front() << '\n';
	    }
	    else if (op == "back") {
	        cout << dq.back() << '\n';
	    }
	}
	
	return 0;
}