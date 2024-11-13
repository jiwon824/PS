#include<iostream>

using namespace std;

const int MAX_STUDENT=1000;
const int MAX_SCORE=100;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int t_num;
    	cin >> t_num;
        
		int score_cnt[MAX_SCORE+1]={0, };
        for(int i=1; i<=MAX_STUDENT; ++i){
        	int score;
            cin >> score;
            score_cnt[score]++;
        }
        
        int max_score=0, max_cnt=0;
        for(int i=0; i<=MAX_SCORE; ++i){
        	if(score_cnt[i]>=max_cnt){
            	max_score=i;
                max_cnt=score_cnt[i];
            }
        }
        
        cout << "#" << test_case<< " " << max_score << '\n';
	}
	return 0;
}
