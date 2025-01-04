import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static class Bottle {
        int[] currentState; // {A, B, C} 각 물병의 상태

        public Bottle(int[] state) {
            this.currentState = Arrays.copyOf(state, 3);
        }

        // from 물병에서 to 물병으로 물을 옮기는 메서드
        Bottle move(int from, int to) {
            int[] nextState = Arrays.copyOf(currentState, 3);
            int amount = Math.min(currentState[from], capacity[to] - currentState[to]);
            nextState[from] -= amount;
            nextState[to] += amount;
            return new Bottle(nextState);
        }
    }

    static int[] capacity;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        capacity = new int[3];
        for (int i = 0; i < 3; i++) {
            capacity[i] = Integer.parseInt(st.nextToken());
        }

        Set<Integer> result = findAllPossibleStates();

        for (int amount : result) {
            System.out.print(amount + " ");
        }
    }

    static Set<Integer> findAllPossibleStates() {
        Queue<Bottle> queue = new ArrayDeque<>();
        boolean[][] visited = new boolean[201][201]; // A와 B의 상태만으로 방문 체크
        Set<Integer> result = new TreeSet<>();

        int[] initialState = {0, 0, capacity[2]}; // 초기 상태
        queue.add(new Bottle(initialState));
        visited[0][0] = true;

        while (!queue.isEmpty()) {
            Bottle current = queue.poll();

            // A가 비어 있을 때, C의 상태를 결과에 추가
            if (current.currentState[0] == 0) {
                result.add(current.currentState[2]);
            }

            // 각 물병 간 물 이동 시도
            for (int from = 0; from < 3; from++) {
                for (int to = 0; to < 3; to++) {
                    if (from == to) continue;

                    Bottle next = current.move(from, to);
                    int nextA = next.currentState[0];
                    int nextB = next.currentState[1];

                    if (!visited[nextA][nextB]) {
                        visited[nextA][nextB] = true;
                        queue.add(next);
                    }
                }
            }
        }

        return result;
    }
}
