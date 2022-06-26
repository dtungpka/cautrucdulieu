#include <iostream>
#include <bits/stdc++.h>
#define INF 3.402823466e+38F 
using namespace std ;

using ll =long long;
const int maxn =100001;
int n , m, s;
vector<pair< int,int >> adj[maxn];
void nhap(){
	cin >>n>>m>>s;
	for(int i=0;i<m;i++){
		int x,y,w; cin >>x>>y>>w;
		adj[x].push_back ({y,w});
		adj[y].push_back ({x,w});
	}
}

void dijkstra(int s){
	//mang luu khoang cach duong di
	vector<ll> d(n+1,INF);
	d[s]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>Q;
	//{Khoang cach ,dinh}
	Q.push({0,s});
	while (!Q.empty()){
		//chon ra dinh co khoang cach nho nhat 
		pair <int ,int>top=Q.top();Q.pop();
		int u= top.second ;
		int kc =top.first;
		if(kc >d[u]) continue;
		//relaxation : cap nhat khoang cach s cho toi dinh ke vs u
		for (auto it : adj[u]){
			int v = it.first;
			int w =it.second;
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
				Q.push ({d[v],v});
			}
		}
	}
	for (int i=1;i<=n;i++){
		cout<< d[i]<<' ';
	}
}
int main (){
	#ifndef ONLINE_JUDGE
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	nhap();
	dijkstra(s);
	
}
