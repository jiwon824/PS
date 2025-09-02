import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	public static class Coord{
		int x;
		int y;
		
		public Coord(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	
	static int n, m;
    static List<Coord> houses = new ArrayList<>();
    static List<Coord> chickens = new ArrayList<>();

    static int c; // 치킨집 수
    static int answer = Integer.MAX_VALUE;
    static int[] pick; // 선택한 치킨집 인덱스 (크기 M)
	
	// 1. 일단 치킨집을 M개 골라 nCm
	// 2. 치킨 거리를 구해
	// 3. 위 2단계를 반복하면서 도시 치킨 거리(도시의 치킨 거리는 모든 집의 치킨 거리의 합)의 최소값을 찾아
	public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        
        for(int i=0; i<n; i++) {
        	st = new StringTokenizer(br.readLine());
        	for(int j =0; j<n; j++) {
        		int v = Integer.parseInt(st.nextToken());
        		// 집이면 houses에 좌표 추가
        		if(v==1) houses.add(new Coord(i, j));
        		// 치킨집이면  chickens에 좌표 추가
        		else if(v==2) chickens.add(new Coord(i, j));
        	}
        }
       
        c = chickens.size();
        pick = new int[m];
        
        comb(0, 0);
        
        System.out.println(answer);
    }
	
	public static void comb(int idx, int cnt) {
		// m개의 치킨집을 선택해
		if(cnt==m) {
			// 선택한 치킨집을 이용해서 치킨 거리 구하기
			int cityChickenDist = getCityChickenDist();
			answer = Math.min(answer, cityChickenDist);
			return;
		}
		
		for(int i = idx; i<c; i++) {
			pick[cnt] = i;
			comb(i+1, cnt+1);
		}
		
	}

	private static int getCityChickenDist() {
		int sum = 0;
		
		// 각 집에 대해 모든 치킨집과의 거리 중 최소인 값이 치킨 거리임
		// 각 집의 최소 거리를 구해서 sum에 누적해주면 됨
		for(Coord house : houses) {
			int minDist = Integer.MAX_VALUE;
			
			for(int idx : pick) {
				Coord chicken = chickens.get(idx);
				int dist = Math.abs(house.x-chicken.x)+Math.abs(house.y-chicken.y);
				minDist = Math.min(minDist, dist);
			}
			sum += minDist;
			if(sum >= answer) return Integer.MAX_VALUE;
		}
		return sum;
	}
	
}
