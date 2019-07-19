#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector <int> can;//今ある分銅で測れる重さ

//今ある分銅で測れる重さを、総当たりで求める再帰関数。
void make_can(int depth, int sum, vector<int> w){
	if(depth >= m){
		can.push_back(sum);
		return;
	}
	make_can(depth+1, sum, w);//置かない
	make_can(depth+1, sum+w[depth], w);//薬品じゃない方に置く(足す)
	make_can(depth+1, abs(sum-w[depth]), w); //薬品の方に置く(引く)
}

int main(void){
	while(1){
		cin >> n >> m;
		if(!n && !m) break;

		vector <int> a(n);
		for(int i=0; i<n; i++){
			cin >> a[i];
		}
		vector <int> w(m);
		for(int i=0; i<m; i++){
			cin >> w[i];
		}

		//前半(今ある分銅で、全ての薬品を測れるか)
		can.clear();
		make_can(0, 0, w); 
		sort(can.begin(), can.end());
		for(int i=0; i<can.size(); i++){
			for(int j=0; j<a.size(); j++){
				if(can[i] == a[j]) a.erase(a.begin()+j); //今ある分銅で測れる薬品を消す
			}
		}

		if(a.size() == 0){
			cout << 0 << endl; //全ての薬品は今ある分銅で測れる
			continue;
		}

		//後半(どの重さの分銅を追加すればいいか)
		vector <vector<int> > cand(n); //各薬品に対して追加が必要な分銅の候補
		for(int i=0; i<a.size(); i++){
			for(int j=0; j<can.size(); j++){
				cand[i].push_back(can[j]+a[i]);
				cand[i].push_back((abs(can[j]-a[i])));
			}
			sort(cand[i].begin(), cand[i].end());
		}

		vector <int> need = cand[0]; //v1とv2の積集合。答えの候補。
		for(int s=1; s<a.size(); s++){
			vector <int> v1 = need;
			vector <int> v2 = cand[s];
			need.clear();
			int i=0, j=0; // iはv1に jはv2に対応。v1[i], v2[j]
			while(i<v1.size() && j<v2.size()){
				if(v1[i] < v2[j]) i++;
				else if(v1[i] > v2[j]) j++;
				else{
					//重複を省くための条件式
					if(need.size() == 0) need.push_back(v1[i]);
					else if(need[need.size()-1] != v1[i]){
						need.push_back(v1[i]);
					}
					i++; j++;
				}
			}
		}

		if(need.empty()) cout << -1 << endl; //候補が残っていない -> 1つ追加しても無理
		else cout << need[0] << endl; //候補の中で一番軽いやつが答え
	}
	return 0;
}
