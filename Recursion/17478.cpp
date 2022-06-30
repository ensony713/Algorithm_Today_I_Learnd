#include <iostream>
using namespace std;

int N;

void auto_bot(int n);

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	auto_bot(N);

	return 0;
}

void auto_bot(int n) {
	string head = "";
	for (int i = 0; i < N - n; i++) {
		head += "____";
	}
	
	cout << head << "\"����Լ��� ������?\"\n";

	if (n == 0) {
		cout << head << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
		cout << head << "��� �亯�Ͽ���.\n";
		return;
	}
	
	cout << head << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n"
		<< head << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n"
		<< head << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
	auto_bot(n - 1);
	cout << head << "��� �亯�Ͽ���.\n";
}