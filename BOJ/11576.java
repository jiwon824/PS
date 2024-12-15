import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // [input]
        // 미래세계에서 사용하는 진법 A와 정이가 사용하는 진법 B가 공백을 구분으로 주어진다.
        // A와 B는 모두 2이상 30이하의 자연수
        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());

        // A진법으로 나타낸 숫자의 자리수의 개수 m(1 ≤ m ≤ 25)
        int m = Integer.parseInt(br.readLine());

        // A진법을 이루고 있는 숫자 m개가 공백을 구분으로 높은 자릿수부터 차례대로 주어진다.
        // 각 숫자는 0이상 A미만임이 보장된다. 또한 수가 0으로 시작하는 경우는 존재하지 않는다.
        st = new StringTokenizer(br.readLine());

        br.close();

        // [solution] 입력으로 주어진 A진법으로 나타낸 수를 B진법으로 변환
        // 입력받은 A진법 수 List에 저장
        List<Integer> aNum = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            aNum.add(Integer.parseInt(st.nextToken()));
        }

        int decimal = convertToDecimal(aNum, a);
        String bNum = convertToBBase(decimal, b);

        // [output]
        System.out.println(bNum);
    }

    // covert A-base to decimal
    // A진법으로 나타낸 수를 10진법으로 변환하였을 때의 값은 양의 정수이며 2^{20}보다 작다.
    public static int convertToDecimal(List<Integer> aNUm, int a){
        int decimal = 0;

        int size = aNUm.size();
        for (int i = 0; i < size; i++) {
            int exponent = aNUm.size()-i-1; // 지수
            int digit = aNUm.get(i);
            decimal+= digit * (int)Math.pow(a, exponent);
        }

        return decimal;
    }

    // convert decimal to B-base
    // A: 10, B: 11, ..., F: 15, ..., Y: 34, Z: 35
    public  static String convertToBBase(int decimalNum, int b){
        List<String> bNum = new ArrayList<>();
        while(decimalNum>0){
            int num = decimalNum%b;
            bNum.add(String.valueOf(num));
            decimalNum/=b;
        }

        StringBuilder sb = new StringBuilder();
        for (int i = bNum.size()-1; i >=0; i--) {
            sb.append(bNum.get(i)).append(" ");
        }
        return sb.toString();
    }
}
