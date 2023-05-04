#include <iostream>
#include <vector>
#define MAX 100
using namespace std;

void input(int n, int index[], int in[], int post[]) {

	int tmp;
	// 중위 순회 입력
	for (int i = 0; i < n; i++) {
		cin >> in[i];
		index[in[i]] = i; // inorder 상의 순서를 저장
	}
	// 후위 순회 입력
	for (int i = 0; i < n; i++) {
		cin >> post[i];
	}
}

// inend = in에서 구간의 끝 + 1
// postend = post에서 구간의 끝 + 1
void divide(int instart, int inend, int poststart, int postend, int in[], int post[], int index[]) {

	if (inend <= instart || postend <= poststart || instart < 0 || poststart < 0) { return; }
	
	int root = index[post[postend - 1]];
	int rsize = inend - root;
	int lsize = root - instart;

	cout << in[root] << ' ';

	// inorder는 root를 제외하고 전달하기 위해 중간을, postorder는 root를 제외하고 전달하기 위해 맨 끝을 빼야함
	divide(instart, root, poststart, poststart + lsize, in, post, index);
	divide(root + 1, inend, poststart + lsize, postend - 1, in, post, index);
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	int pre[MAX] = { 0 }, in[MAX] = { 0 }, post[MAX] = { 0 }, index[MAX] = { 0 };
	// 전위(preorder), 중위(inorder), 후위(postorder)
	cin >> n;

	input(n, index, in, post);

	divide(0, n, 0, n, in, post, index);
	
	return 0;
}