import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static class Meeting{
        int startTime;
        int endTime;

        public Meeting(int startTime, int endTime) {
            this.startTime = startTime;
            this.endTime = endTime;
        }
    }

    public static Comparator<Meeting> comp = new Comparator<>() {
        @Override
        public int compare(Meeting o1, Meeting o2) {
            if(o1.endTime==o2.endTime) return o1.startTime-o2.startTime;
            return o1.endTime-o2.endTime;
        }
    };

    public static Meeting[] meetings;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // 첫째 줄에 회의의 수 N(1 ≤ N ≤ 100,000)이 주어진다.
        int n = Integer.parseInt(br.readLine());
        meetings = new Meeting[n];

        // 둘째 줄부터 N+1 줄까지 각 회의의 시작시간과 끝나는 시간이 주어진다.
        // 시작 시간과 끝나는 시간은 2^{31}-1보다 작거나 같은 자연수 또는 0이다.
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            meetings[i] = new Meeting(s, e);
        }
        br.close();

        Arrays.sort(meetings, comp);

        int maxMeeting =1;
        Meeting lastMeeting = meetings[0];

        for (int i = 1; i < n; i++) {
            // 불가능한 미팅
            if(meetings[i].startTime<lastMeeting.endTime) continue;

            lastMeeting = meetings[i];
            maxMeeting++;
        }
        System.out.println(maxMeeting);
    }
}
