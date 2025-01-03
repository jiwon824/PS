import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static class Pair {
        int num;
        int cnt;

        public Pair(int num, int cnt) {
            this.num = num;
            this.cnt = cnt;
        }
    }
    
    public static boolean[] primeNum;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // 첫 줄에 test case의 수 T가 주어진다.
        int tc = Integer.parseInt(br.readLine());

        // 처음 1회 primeNum 배열 채우기
        fillPrimeArr(9999);

        // 다음 T줄에 걸쳐 각 줄에 1쌍씩 네 자리 소수가 주어진다.
        while(tc-- > 0){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int target = Integer.parseInt(st.nextToken());

            // [solution] start->target
            int cnt = bfs(start, target);
            // cnt가 -1이면 Impossible, 아니면 cnt 출력
            System.out.println((cnt==-1)? "Impossible" : cnt);
        }
        br.close();
    }

    public static void fillPrimeArr(int size){
        primeNum = new boolean[size+1];
        Arrays.fill(primeNum, true);
        for (int i = 2; i <= size; i++) {
            if(!primeNum[i]) continue;
            for (int j = i*i; j <= size; j+=i) {
                primeNum[j]=false;
            }
        }
    }

    public static int bfs(int start, int target) {
        Queue<Pair> queue = new ArrayDeque<>();
        boolean[] visited = new boolean[10000]; // 4자리 소수

        queue.offer(new Pair(start, 0));
        visited[start] = true;

        while (!queue.isEmpty()){
            Pair curr = queue.poll();

            // [return1] target과 같으면 cnt 반환
            if(curr.num==target) return curr.cnt;

            // nextNumbers: 1자리 수만 변경한 수들 모임
            String num = String.valueOf(curr.num);
            List<Integer> nextNumbers = getNext(num);
            for (int next : nextNumbers) {
                // 소수가 아님 || 이미 방문한 수
                if(!primeNum[next] || visited[next]) continue;

                queue.offer(new Pair(next, curr.cnt+1));
                visited[next]=true;
            }
        }

        // [return2] 불가능한 경우
        return -1;
    }

    // num에서 1자릿수만 변경한 수들 리스트 반환
    private static List<Integer> getNext(String num) {
        List<Integer> nextNumbers = new ArrayList<>();
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 10; j++) {
                // i번째 자릿수를 j로 변경
                char[] tmp = num.toCharArray();
                tmp[i]= (char) (j + '0');

                int next = Integer.parseInt(new String(tmp));

                // 숫자가 4자리인지 확인
                if (next < 1000 || next > 9999) continue;

                nextNumbers.add(next);
            }
        }
        return nextNumbers;
    }
}
