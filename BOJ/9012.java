import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int tc = Integer.parseInt(br.readLine());
        for (int t = 0; t < tc; t++) {
            if(checkParenthesis(br.readLine())){
                sb.append("YES").append('\n');
            } else{
                sb.append("NO").append('\n');
            }
        }
        br.close();

        System.out.println(sb);
    }

    // 모든 문자열을 확인했는데, stack에 남은 원소가 있는 경우
    // stack에 남은 '('가 없는데, ')'가 입력된 경우
    public static boolean checkParenthesis(String parenthesis){
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < parenthesis.length(); i++) {
            char c = parenthesis.charAt(i);
            if(c=='('){
                stack.push(c);
            }else{
                if(stack.empty()) return false;
                char e = stack.pop();
                if (e == ')') return false;
            }
        }

        // 모든 문자열을 처리했는데, stack 안에 원소가 남아 있으면
        // 괄호 쌍이 안 맞는 것
        if(!stack.empty()) return false;

        return true;
    }
}
