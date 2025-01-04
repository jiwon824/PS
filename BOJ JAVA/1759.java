import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static int l;
    public static int c;
    public static char[] alphabets;
    public static boolean[] visited;
    public static char[] result;
    public static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // 새 보안 시스템에서 조교들이 암호로 사용했을 법한 문자의 종류는 C가지가 있다
        // 첫째 줄에 두 정수 L, C가 주어진다. (3 ≤ L ≤ C ≤ 15)
        StringTokenizer st = new StringTokenizer(br.readLine());
        l = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        alphabets = new char[c];
        visited = new boolean[c];
        result = new char[l];

        // 다음 줄에는 C개의 문자들이 공백으로 구분되어 주어진다. 주어지는 문자들은 알파벳 소문자이며, 중복되는 것은 없다
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < c; i++) {
            String tmp = st.nextToken();
            alphabets[i] = tmp.charAt(0);
        }
        br.close();

        // 암호를 이루는 알파벳이 증가하는 순서로
        // 즉, abc는 가능성이 있는 암호이지만 bac는 그렇지 않다.
        Arrays.sort(alphabets);

        // C개의 문자들이 모두 주어졌을 때, 가능성 있는 암호들을 모두 구하는 프로그램
        backtracking(0,0);

        System.out.println(sb);
    }


    public static void backtracking(int idx, int cnt){
        // (조건1) 암호는 서로 다른 L개의 알파벳 소문자들로 구성
        if(cnt==l){
            if(check()) {
                for (char c : result) {
                    sb.append(c);
                }
                sb.append('\n');
            }
            return;
        }

        for (int i = idx; i < c; i++) {
            if(visited[i]) continue;
            result[cnt] = alphabets[i];
            visited[i] = true;
            backtracking(i,cnt+1);

            visited[i]=false;
        }
    }

    public static boolean check(){
        char[] vowels = {'a', 'e', 'i', 'o', 'u'};
        int numOfVowel = 0;
        for (char c : result) {
            for (char vowel : vowels) {
                if(c==vowel) numOfVowel++;
            }
        }

        // (조건2) 최소 한 개의 모음(a, e, i, o, u) && 최소 두 개의 자음으로 구성
        return numOfVowel>=1 && l-numOfVowel>=2;
    }
}
