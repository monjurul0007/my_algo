#include <bits/stdc++.h>

using namespace std;
     
#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define fin(i) freopen(i, "r", stdin)
#define fout(o) freopen(o, "w", stdout)
#define pb push_back
#define ll long long int
#define inf LLONG_MAX
#define neginf LLONG_MIN
#define wk cout << "working" << endl
     
typedef pair<int , int>  pii;
     
vector <pii> adj[10005];
bool vis[10005];

void init(int n){
	for(int i=1; i<=n; i++){
		adj[i].clear();
		vis[i] = false;
	}
}
     
void input(int m){
	int a,b,w;
	for(int i=0; i<m; i++){
		cin >> a >> b >> w;
		adj[a].pb(pii(w,b));
		adj[b].pb(pii(w,a));
	}
} 

ll prims(int n){
	priority_queue<pii, vector<pii>, greater<pii> > q;
	
	int mst = 0,edge = 0;
	
	vis[1] = true;
	
	for(int i=0; i<adj[1].size(); i++){
		q.push(adj[1][i]);
	}
	
	while(!q.empty()){
		int v = q.top().second;
		ll w = q.top().first;
		q.pop();
		
		vis[v] = true;
		mst += w;
		edge++;
		
		if(edge == n-1)
			break;
		
		for(int i=0; i<adj[v].size(); i++)
			if(vis[adj[v][i].second] == false)
				q.push(adj[v][i]);
	}
	return mst;
}
     
int main(){
    fin("input.txt");
    int n,m;
    cin >> n >> m;    
    
    init(n);
    input(m);
    
    cout << prims(n) << endl;
    
    return 0;
}
