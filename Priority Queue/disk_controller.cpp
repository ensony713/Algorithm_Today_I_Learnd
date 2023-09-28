#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

bool compare(vector<int>& a, vector<int>& b) {
	return a[0] <= b[0];
}

// jobs에서 now 보다 들어온 시점이 빠른 걸 works에 추가 
//		== 현재시점(now) 보다 빠른 시점에 들어온 작업들(jobs)을 works에 추가
void push_works(vector<vector<int>>& jobs, priority_queue<pair<int, int>>& works, int now, int& idx) {
	

	for (int i = idx; i < jobs.size(); i++) {
		if (now >= jobs[i][0]) {
			works.push({ -jobs[i][1], jobs[i][0] });
			// priority_queue = 최대힙
		}
		else {
			idx = i;
			return;
		}
	}
	idx = jobs.size();
	cout << works.size() << "개의 작업 대기중\n";
}

int solution(vector<vector<int>>& jobs) {
	// 평균시간 줄이기 = SJF 스케줄링 알고리즘

	// jobs[n][0] = 들어온 시점, jobs[n][1] = 소요시간
	int answer = 0;
	int now = 0; // 현재 시각
	int idx = 0;
	int cnt = jobs.size(); // 작업 개수
	priority_queue<pair<int, int>> works; // 현재 대기중인 작업
	// works.top().first = 소요시간, works.top().second = 들어온 시점

	// 들어온 시점 순으로 정렬
	sort(jobs.begin(), jobs.end(), compare);
	if (jobs[0][0] != 0) { // 첫 작업의 요청 시점이 0이 아닐 경우의 처리
		now = jobs[0][0];
	}
	
	push_works(jobs, works, now, idx);

	while (!works.empty()) {

		int start = works.top().second; // 들어온 시점
		int work_time = -works.top().first; // 소요시간
		works.pop();

		int wait = now - start;
		answer += wait + work_time;
		now += work_time;

		push_works(jobs, works, now, idx);

		if (works.empty() && idx != cnt) { // 작업이 남았는데 작업 사이에 공백이 있던 경우를 처리
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