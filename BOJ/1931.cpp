#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first; // second값이 같으면 first값이 더 작은 게 앞으로 가게 정렬
	return a.second < b.second; //second 값이 더 작은 게 앞으로 가게 해라!
}


int main() {
	int n;
	cin >> n;
	int meetingCnt = 0;
	vector<pair<int, int>> time;

	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		time.push_back({ start, end });
	}
	//빨리 끝나야 다음 회의를 빨리 시작할 수 있어서 더 많은 회의를 할 수 있다
	sort(time.begin(), time.end(), compare);

	int nextMeetingIdx = 0;

	for (int i = 0; i < n; i++) {
		i = nextMeetingIdx;
		meetingCnt++;
		//cout << "선택된 회의: " << time[i].first << " " << time[i].second << '\n';
		// 다음 인덱스부터 찾아
		for (int j = i+1; j < n; j++) {
			if (time[i].second <= time[j].first) {
				nextMeetingIdx = j;
				break;
			}
		}
		if (i == nextMeetingIdx) break;
	}

	cout << meetingCnt << '\n';
	return 0;
}