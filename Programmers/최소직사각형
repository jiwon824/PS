#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    
    int len = sizes.size();
    
    int width = 0, height =0;
    for(int i =0; i<len; i++){
        int first = max(sizes[i][0], sizes[i][1]);
        int second = min(sizes[i][0], sizes[i][1]);
        width = max(width, first);
        height = max(height, second);
    }
    
    return width * height;
}
