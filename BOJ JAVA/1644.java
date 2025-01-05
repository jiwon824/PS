import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // 첫째 줄에 자연수 N이 주어진다. (1 ≤ N ≤ 4,000,000)
        int n = Integer.parseInt(br.readLine());
        br.close();

        List<Integer> primeNum = makePrimeList(n);
        int left =0, right=0, sum=0, answer =0;
        while(true){
            if(sum>=n){
                if(sum==n) answer++;
                sum-=primeNum.get(left++);
            }else if(right==primeNum.size()){
                break;
            }else{
                sum+=primeNum.get(right++);
            }
        }
        System.out.println(answer);
    }

    private static List<Integer> makePrimeList(int n) {
        List<Integer> primeList = new ArrayList<>();
        // n까지의 소수 목록 구하기
        boolean[] primeNum = new boolean[n +1];
        Arrays.fill(primeNum, true);

        primeNum[0]=false; primeNum[1]=false;
        for (int i = 2; i <= n; i++) {
            if(!primeNum[i]) continue;
            // i를 소수 list에 추가
            primeList.add(i);
            // i의 배수는 소수가 아님
            for (int j = i; j <= n / i; j++) { // 오버플로우 방지
                primeNum[i * j] = false;
            }
        }
        return primeList;
    }
}
