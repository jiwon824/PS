import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();

        int n = sc.nextInt();
        sc.nextLine();
        List<Student> students = new ArrayList<>();

        for(int i=1; i<=n; i++){
            String userInfo = sc.nextLine();
            String[] split = userInfo.split(" ");

            String name = split[0];
            int kor = Integer.parseInt(split[1]);
            int eng = Integer.parseInt(split[2]);
            int math = Integer.parseInt(split[3]);
            Student student = new Student(name, kor, eng, math);
            students.add(student);
        }

        students.sort(comp);

        for (Student user : students) {
            sb.append(user.name).append('\n');
        }

        System.out.println(sb);
    }

    static Comparator<Student> comp = new Comparator<Student>() {
        @Override
        public int compare(Student o1, Student o2) {
//        모든 점수가 같으면 이름이 사전 순으로 증가하는 순서로 (단, 아스키 코드에서 대문자는 소문자보다 작으므로 사전순으로 앞에 온다.)
            if(o1.kor==o2.kor && o1.eng==o2.eng && o1.math==o2.math){
                return o1.name.compareTo(o2.name);
            }
//        국어 점수와 영어 점수가 같으면 수학 점수가 감소하는 순서로
            if(o1.kor==o2.kor && o1.eng==o2.eng) {
                return o2.math-o1.math;
            }
//        국어 점수가 같으면 영어 점수가 증가하는 순서로
            if(o1.kor==o2.kor){
                return o1.eng-o2.eng;
            }
//        국어 점수가 감소하는 순서로
            return o2.kor-o1.kor;
        }
    };

    static class Student {
        String name;
        int kor;
        int eng;
        int math;

        public Student(String name, int kor, int eng, int math) {
            this.name = name;
            this.kor = kor;
            this.eng = eng;
            this.math = math;
        }
    }
}
