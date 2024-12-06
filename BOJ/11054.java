import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int[] arr = new int[n+10];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        int[] dpInc = new int[n+10]; // 0->i까지 증가하는 수열의 수
        int[] dpDec = new int[n+10]; // n->i까지 감소하는 수열의 수

        // dpInc
        for (int i = 0; i < n; i++) {
            dpInc[i]=1;
            for (int j = 0; j < i ; j++) {
                if(arr[j]<arr[i]){
                    dpInc[i]=Math.max(dpInc[i], dpInc[j]+1);
                }
            }
        }

        //dpDec
        for (int i = n-1; i >=0 ; i--) {
            dpDec[i]=1;
            for (int j = i+1; j < n; j++) {
                if(arr[i]>arr[j]){
                    dpDec[i]=Math.max(dpDec[i], dpDec[j]+1);
                }
            }
        }

        // output
        int answer =0;
        for (int i = 0; i < n; i++) {
            answer = Math.max(answer, dpInc[i]+dpDec[i]-1);
        }
        System.out.println(answer);
    }
}
