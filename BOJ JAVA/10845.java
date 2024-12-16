import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(br.readLine());

        int[] queue = new int[n];
        int size = 0;

        // push X: 정수 X를 큐에 넣는 연산이다.
        // pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
        // size: 큐에 들어있는 정수의 개수를 출력한다.
        // empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
        // front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
        // back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String command = st.nextToken();
            if(command.equals("push")){
                int x = Integer.parseInt(st.nextToken());
                queue[size++]=x;
            } else if (command.equals("pop")) {
                int x = (size==0)? -1 : queue[0];
                sb.append(x).append('\n');

                if(size==0) continue;

                // size!=0 이면 배열 한 칸씩 당겨주기
                for (int j = 0; j < size-1; j++) {
                    queue[j]=queue[j+1];
                }
                size--;

            } else if(command.equals("size")) {
                sb.append(size).append('\n');
            } else if (command.equals("empty")) {
                int x = (size==0) ? 1 : 0;
                sb.append(x).append('\n');
            } else if (command.equals("front")) {
                int x = (size==0) ? -1: queue[0];
                sb.append(x).append('\n');
            } else if (command.equals("back")) {
                int x = (size==0) ? -1: queue[size-1];
                sb.append(x).append('\n');
            } else {
                System.out.println("wrong command");
                break;
            }

        }

        br.close();

        System.out.println(sb);
    }
}
