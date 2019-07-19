#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
	while(1){
		int h, w; cin >> h >> w;
		if(!h && !w) break;

		string cell[55]; //与えられるセル
		for(int i=0; i<h; i++){
			cin >> cell[i];
		}
		string str; cin >> str; //入力したい文字列

		int ans = 0;
		int pos_x=0, pos_y=0; //最後に押した(強調されている)cellの位置
		for(int s=0; s<str.length(); s++){
			for(int y=0; y<h; y++){
				bool find = false; //二重ループを抜けるためのフラグ
				for(int x=0; x<w; x++){
					if(cell[y][x] == str[s]){
						ans += abs(y-pos_y) + abs(x-pos_x) + 1; //マンハッタン距離+1
						pos_x = x; 
						pos_y = y;
						find = true;
						break;
					}
				}
				if(find) break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}