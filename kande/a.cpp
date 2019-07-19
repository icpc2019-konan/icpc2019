#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	while(1){
		int n, m; cin >> n >> m;
		if(!n && !m) break;

		int sum[1005] ={0}; //各生徒の合計点
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				int p; cin >> p;
				sum[j] += p; //点数を足していく
			}
		}

		int ans = -1;
		for(int i=0; i<n; i++){
			ans = max(ans, sum[i]); //ansとsum[i]の大きい方をansに代入
		}

		cout << ans << endl;
	}
	return 0;
}