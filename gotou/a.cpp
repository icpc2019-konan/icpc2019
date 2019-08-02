#include <iostream>
#include <vector>

using namespace std;
int main(){
    int n,m;
    while(cin>>n>>m){
        if(n+m==0)break;
        vector<int> v(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int x;cin>>x;
                v[j]+=x;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,v[i]);
        }
        cout<<ans<<endl;
    }

}

/*
//1次元による実装
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,m;
    while(cin>>n>>m){
        if(n+m==0)break;
        vector<int> sum(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int score;cin>>score;
                sum[j]+=score;
            }
        }
        cout<<(*max_element(sum.begin(),sum.end()))<<endl;
    }
}
*/