import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(br.readLine());

        int[] deque = new int[n];
        int size = 0;

        // push_front X: 정수 X를 덱의 앞에 넣는다.
        // push_back X: 정수 X를 덱의 뒤에 넣는다.
        // pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
        // pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
        // size: 덱에 들어있는 정수의 개수를 출력한다.
        // empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
        // front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
        // back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String command = st.nextToken();

            if(command.equals("push_front")){
                int x = Integer.parseInt(st.nextToken());
                // shiftRight
                for(int j=size; j>0; j--){
                    deque[j]=deque[j-1];
                }
                deque[0]=x;
                size++;
            } else if (command.equals("push_back")){
                int x = Integer.parseInt(st.nextToken());
                deque[size++] = x;
            } else if (command.equals("pop_front")) {
                int x = (size==0) ? -1: deque[0];
                if(x != -1) {
                    // shiftLeft
                    for (int j = 0; j < size; j++) {
                        deque[j]=deque[j+1];
                    }
                    size--;
                }
                sb.append(x).append('\n');
            } else if (command.equals("pop_back")){
                int x = (size==0) ? -1: deque[size-1];
                if(x != -1) {
                    size--;
                }
                sb.append(x).append('\n');
            } else if (command.equals("size")){
                sb.append(size).append('\n');
            } else if (command.equals("empty")){
                int x = (size==0) ? 1: 0;
                sb.append(x).append('\n');
            } else if (command.equals("front")){
                int x = (size==0) ? -1: deque[0];
                sb.append(x).append('\n');
            } else if (command.equals("back")) {
                int x = (size==0) ? -1: deque[size-1];
                sb.append(x).append('\n');
            }
        }

        System.out.println(sb);
    }

}
