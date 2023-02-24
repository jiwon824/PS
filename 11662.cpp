/*
민호는 점 A(Ax, Ay)에서 점 B(Bx, By)를 향해 걸어가고 있고,
강호는 점 C(Cx, Cy)에서 점 D(Dx, Dy)를 향해 걸어가고 있다.
민호와 강호는 동시에 출발하고, 민호가 점 B에 도착하는 순간 강호도 점 D에 도착한다.
또, 두 사람은 항상 일정한 속도로 걸어간다. 두 사람의 거리가 가장 가까울 때, 거리를 구하는 프로그램
*/
#include <iostream>
#include <algorithm> // min()
#include <cmath> // sqrt(), pow()

using namespace std;
// start와 end의 1/3지점
double leftMid(double start, double end){
    return start + (end - start) / 3;
}
// start와 end의 2/3지점
double rightMid(double start, double end) {
	return end - (end - start) / 3;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // 첫째 줄에 입력 Ax, Ay, Bx, By, Cx, Cy, Dx, Dy(0<=모든 좌표<=10000)
    double Ax, Ay; // 민호 출발 좌표
    double Bx, By; // 민호 도착 좌표

    double Cx, Cy; // 강호 출발 좌표
    double Dx, Dy; // 강호 도착 좌표

    cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy >> Dx >> Dy;

    int T=100;
    // mid1, mid2는 민호와 강호 사이의 거리
        // mid1은 민호 시작점과 강호 시작점 사이의 거리 -> 시작~도착 1/3 거리(leftMid 적용) -> 그 거리의 1/3 거리(leftMid 적용)
        // mid2는 민호 도착점과 강호 도착점 사이의 거리 -> 시작~도착 2/3 거리(rightMid 적용) -> 그 거리의 2/3 거리(rightMid 적용)
    double mid1, mid2;

    while (T--){
        // 두점 (x_1, y_1), (x_2, y_2) 사이의 거리
        // sqrt(pow(x_2-x_1, 2)+pow(y_2-y_1, 2))
            // 루트x = sqrt(double x)
            // base^n = pow(base, n)
        mid1=sqrt(pow(Ax-Cx, 2)+pow(Ay-Cy, 2));
        mid2=sqrt(pow(Bx-Dx, 2)+pow(By-Dy, 2));

        if (mid1>mid2){
            Ax=leftMid(Ax, Bx); // (민호)시작x, 도착x의 1/3지점을 시작x좌표으로 지정
            Ay=leftMid(Ay, By); // (민호)시작y, 도착y의 1/3지점을 시작y좌표로 지정
            Cx=leftMid(Cx, Dx); // (강호)시작x, 도착x의 1/3지점을 시작x좌표으로 지정
            Cy=leftMid(Cy, Dy); // (강호)시작y, 도착y의 1/3지점을 시작y좌표로 지정
        }
        else if (mid1<mid2){
            Bx=rightMid(Ax, Bx); // (민호)시작x, 도착x의 2/3지점을 도착x좌표으로 지정
            By=rightMid(Ay, By); // (민호)시작y, 도착y의 2/3지점을 도착y좌표로 지정
            Dx=rightMid(Cx, Dx); // (강호)시작x, 도착x의 2/3지점을 도착x좌표으로 지정
            Dy=rightMid(Cy, Dy); // (강호)시작y, 도착y의 2/3지점을 도착y좌표로 지정
        }
        else break;
    }
    // fixed는 고정 소수점 표기. 이 코드가 없으면 전체 자리 중 맨 앞 n자리만 표시하게 됨
    cout << fixed;
    // cout.precision(n) 실수를 n자리만큼 출력하겠다는 의미.
        // 여기서는 10자리를 출력하는데 cout << fixed가 있으므로 소수점 아래 10자리가 표시됨
        // 단, 마지막 자리수는 반올림하여 표기함.
            // ex) 4321.123456789 cout << fixed; cout.precision(6); 의 결과
            // 4321.123457
	cout.precision(10);
	cout << min(mid1, mid2);
    return 0;
}