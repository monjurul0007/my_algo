#include <bits/stdc++.h>

using namespace std;

#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define inf INT_MAX
#define neginf LLONG_MIN
#define wk cout << "working" << endl
#define all(x) x.begin(),x.end()
#define mem(arr,value) memset(arr, value, sizeof(arr))
#define mod 100000007
#define F first  
#define S second   

typedef long long int ll;     
typedef pair<ll , int>  pii;
typedef pair<int , pii > piii; 

vector <pii> adj[30005];
int dis[30005];

void dijkstra(int s){
	priority_queue <pii, vector<pii> , greater<pii> > pq;
	pq.push({0,s});
	dis[s] = 0;
	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		for(int i=0; i<adj[u].size(); i++){
			int v = adj[u][i].second;
			int w = adj[u][i].first;
			if(dis[u] + w < dis[v]){
				dis[v] = dis[u] + w;
				pq.push({dis[v],v});
			}
		}
	}
}

int main(){

	int u,v,w,n,e;

	scanf("%d %d",&n,&e);
		
	for(int i=0; i<e; i++){
		scanf("%d %d %d",&u,&v,&w);
		adj[u].pb({w,v});
		adj[v].pb({w,u});
	}
	
	mem(dis,INT_MAX);	
	dijkstra(0);
		
    return 0;
}
