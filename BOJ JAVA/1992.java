import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static StringBuilder sb = new StringBuilder();
    public static int[][] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        arr = new int[n][n];

        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            for (int j = 0; j < n; j++) {
                arr[i][j] = str.charAt(j)-'0';
            }
        }

        br.close();

        divide(0, 0, n);

        System.out.println(sb);
    }

    // 주어진 범위가 모두 같은지 확인
    public static boolean check(int row, int col, int range){
        int num = arr[row][col];
        for (int i = row; i < row+range; i++) {
            for (int j = col; j < col+range; j++) {
                if(arr[i][j]!=num) return false;
            }
        }
        return true;
    }

    public static void divide(int row, int col, int range){
        if(check(row, col, range)){
            sb.append(arr[row][col]);
            return;
        }
        
        sb.append('(');
        for (int i = row; i < row+range; i+=range/2) {
            for (int j = col; j < col+range; j+=range/2) {
                divide(i, j, range/2);
            }
        }
        sb.append(')');
    }
}
