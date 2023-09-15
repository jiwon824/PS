#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first; // second���� ������ first���� �� ���� �� ������ ���� ����
	return a.second < b.second; //second ���� �� ���� �� ������ ���� �ض�!
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
	//���� ������ ���� ȸ�Ǹ� ���� ������ �� �־ �� ���� ȸ�Ǹ� �� �� �ִ�
	sort(time.begin(), time.end(), compare);

	int nextMeetingIdx = 0;

	for (int i = 0; i < n; i++) {
		i = nextMeetingIdx;
		meetingCnt++;
		//cout << "���õ� ȸ��: " << time[i].first << " " << time[i].second << '\n';
		// ���� �ε������� ã��
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