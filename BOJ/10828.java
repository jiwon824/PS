import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(br.readLine());

        int[] stack = new int[n];
        int size = 0;

        // push X: 정수 X를 스택에 넣는 연산이다.
        // pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
        // size: 스택에 들어있는 정수의 개수를 출력한다.
        // empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
        // top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String command = st.nextToken();
            if(command.equals("push")){
                int x = Integer.parseInt(st.nextToken());
                stack[size++]=x;
            } else if (command.equals("pop")) {
                int x = (size==0)? -1 : stack[--size];
                sb.append(x).append('\n');
            } else if (command.equals("size")){
                sb.append(size).append('\n');
            } else if (command.equals("empty")){
                int x = (size==0) ? 1 : 0;
                sb.append(x).append('\n');
            } else if(command.equals("top")){
                int x = (size==0) ? -1 :stack[size-1];
                sb.append(x).append('\n');
            }else{
                System.out.println("wrong input");
                break;
            }
        }
        br.close();

        System.out.println(sb);
    }
}
