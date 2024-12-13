import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringBuilder sb = new StringBuilder(br.readLine());
        int cursor = sb.length();

        int m = Integer.parseInt(br.readLine());
        for (int i = 0; i < m; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String command = st.nextToken();

            if (command.equals("L")) {
                // Move cursor left
                if (cursor != 0) cursor--;
            } else if (command.equals("D")) {
                // Move cursor right
                if (cursor != sb.length()) cursor++;
            } else if (command.equals("B")) {
                // Delete the character to the left of the cursor
                if (cursor > 0) {
                    sb.deleteCharAt(cursor - 1);
                    cursor--;
                }
            } else if (command.equals("P")) {
                // Add the character to the left of the cursor
                String c = st.nextToken();
                sb.insert(cursor, c);
                cursor++;
            }
        }

        System.out.println(sb);
    }
}
