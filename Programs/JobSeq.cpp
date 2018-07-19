#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b){
	if(a.second > b.second){
		return true;
	}else if(a.second < b.second){
		return false;
	}else{
		return a.first < b.first;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n, profit, id, dead;
		cin>>n;
		vector<pair<int, int> > a(n);
		int maxDead = 0;
		for(int i = 0;i<n;i++){
			cin>>id>>dead>>profit;
			a[i] = make_pair(dead, profit);
			maxDead = max(maxDead, dead);
		}
		sort(a.begin(), a.end(), comp);
		vector<bool> b(maxDead, false);
		int ans = 0, ansCount = 0;
		for(int i =0;i<n;i++){
			int dead = a[i].first, profit = a[i].second;
			for(int j = dead;j>0;j--){
				if(b[j] == false){
					ans += profit;
					ansCount += 1;
					b[j] = true;
					break;
				}
			} 
		}
		cout<<ansCount<<" "<<ans<<endl;
	}
}
