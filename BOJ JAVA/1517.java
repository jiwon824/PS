import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static long cnt = 0;
    public static long[] sorted;

    public static void main(String[] args) throws IOException {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int n = Integer.parseInt(br.readLine());
            sorted = new long[n];
            long[] arr = new long[n];

            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                arr[i] = Long.parseLong(st.nextToken());
            }

            // n개의 원소 mergesort
            mergeSort(arr, 0, n - 1);
            System.out.println(cnt);
        }
    }

    // 쪼갠 다음 합치면서 정렬
    public static void mergeSort(long[] arr, int start, int end) {
        if (start == end) return;

        int mid = (start + end) / 2;

        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }

    // 실제로 합쳐주는 작업
    public static void merge(long[] arr, int start, int mid, int end) {
        int left = start;
        int right = mid + 1;
        int idx = start;

        while (left <= mid && right <= end) {
            if (arr[left] <= arr[right]) {
                sorted[idx++] = arr[left++];
            } else {
                sorted[idx++] = arr[right++];
                cnt += (mid + 1 - left);
            }
        }

        while (left <= mid) {
            sorted[idx++] = arr[left++];
        }

        while (right <= end) {
            sorted[idx++] = arr[right++];
        }

        // 정렬된 결과를 원본 배열에 반영
        for (int i = start; i <= end; i++) {
            arr[i] = sorted[i];
        }
    }
}
