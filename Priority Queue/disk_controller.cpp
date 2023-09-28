#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

bool compare(vector<int>& a, vector<int>& b) {
	return a[0] <= b[0];
}

// jobs���� now ���� ���� ������ ���� �� works�� �߰� 
//		== �������(now) ���� ���� ������ ���� �۾���(jobs)�� works�� �߰�
void push_works(vector<vector<int>>& jobs, priority_queue<pair<int, int>>& works, int now, int& idx) {
	

	for (int i = idx; i < jobs.size(); i++) {
		if (now >= jobs[i][0]) {
			works.push({ -jobs[i][1], jobs[i][0] });
			// priority_queue = �ִ���
		}
		else {
			idx = i;
			return;
		}
	}
	idx = jobs.size();
	cout << works.size() << "���� �۾� �����\n";
}

int solution(vector<vector<int>>& jobs) {
	// ��սð� ���̱� = SJF �����ٸ� �˰���

	// jobs[n][0] = ���� ����, jobs[n][1] = �ҿ�ð�
	int answer = 0;
	int now = 0; // ���� �ð�
	int idx = 0;
	int cnt = jobs.size(); // �۾� ����
	priority_queue<pair<int, int>> works; // ���� ������� �۾�
	// works.top().first = �ҿ�ð�, works.top().second = ���� ����

	// ���� ���� ������ ����
	sort(jobs.begin(), jobs.end(), compare);
	if (jobs[0][0] != 0) { // ù �۾��� ��û ������ 0�� �ƴ� ����� ó��
		now = jobs[0][0];
	}
	
	push_works(jobs, works, now, idx);

	while (!works.empty()) {

		int start = works.top().second; // ���� ����
		int work_time = -works.top().first; // �ҿ�ð�
		works.pop();

		int wait = now - start;
		answer += wait + work_time;
		now += work_time;

		push_works(jobs, works, now, idx);

		if (works.empty() && idx != cnt) { // �۾��� ���Ҵµ� �۾� ���̿� ������ �ִ� ��츦 ó��
			now = jobs[idx][0];
			push_works(jobs, works, now, idx);
		}
	}

	answer /= cnt;

	return answer;
}

int main(int argc, char** argv) {

	int a, b, n;
	vector<vector<int>> jobs;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		vector<int> tmp;
		tmp.push_back(a);
		tmp.push_back(b);
		jobs.push_back(tmp);
	}

	cout << solution(jobs) << '\n';

	return 0;
}