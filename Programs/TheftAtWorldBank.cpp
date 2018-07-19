#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b){
	float f = a.second / (float)a.first;
	float s = b.second / (float)b.first;
	return f > s;
}
int main(){
	int t ;
	cin>>t;
	while(t--){
		int n, w;
		cin>>n>>w;
		vector<pair<int, int> > a(n);
		int wi, pi;
		for(int i =0;i<n;i++){
			cin>>wi>>pi;
			a[i] = make_pair(wi, pi);
		}
		float ans = 0;
		for(int i =0;i<n && w > 0;i++){
			int cur = a[i].first;
			int sq = sqrt(cur);
			if(cur != sq*sq){
				if(cur <= w){
					ans += a[i].second;
					w -= cur;
				}else{
					int pro = a[i].second;
					float add = ( pro / (float)cur ) * (float)w;
					ans += add;
					w = 0;
				}
			}	
		}
		printf("%.3f\n", ans);
	}
	
}
