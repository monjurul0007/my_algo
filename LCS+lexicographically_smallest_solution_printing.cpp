#include <bits/stdc++.h>

using namespace std;

#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define inf LLONG_MAX
#define neginf LLONG_MIN
#define wk cout << "working" << endl
#define all(x) x.begin(),x.end()
#define mem(arr,value) memset(arr, value, sizeof(arr))
#define mod 1000000007

typedef long long int ll;     
typedef pair<int , int>  pii;
typedef pair<int , pii > piii; 
typedef priority_queue <pii, vector<pii> , greater<pii> > pq;

int n,m,lcs;
char a[105],b[105];
int dp[105][105];
string ans;

ll solve(int i, int j){
	if(dp[i][j] != -1)
		return dp[i][j];
		
	if(i >= n || j >= m)
		return 0;
	
	ll res = 0;
	
	if(a[i] == b[j])
		res = 1 + solve(i+1, j+1);
	else
		res = max(solve(i+1, j) , solve(i, j+1));
	
	dp[i][j] = res;
	return res;
}

void printSln(int x, int y, int cur){
	if(x >= n || y >= m)
		return;
	if(cur >= lcs){
		return;
	}
	
	bool done = false;
	for(int k='a'; k<='z'; k++){
		for(int i = x; i<n; i++){
			if(a[i] == k){
				for(int j = y; j<m; j++){
					if(b[j] == k && solve(i,j) == lcs - cur){
						ans.pb((char)k);
						printSln(i+1, j+1, cur+1);
						done = true;
						break;
					}
				}

			}
			if(done)
				break;
		}
		if(done)
			break;
	}
}

int main(){
	//fasterInOut;
	int t;
	scanf("%d",&t);
	for(int T=1; T<=t; T++){
		scanf("%s",a);
		scanf("%s",b);
		n = strlen(a);
		m = strlen(b);
		
		mem(dp,-1);
		ans.clear();
		lcs = solve(0,0);
		printSln(0,0,0);
		
		if(ans == "")
			printf("Case %d: :(\n",T);
		else{
			printf("Case %d: %s\n",T,ans.c_str());
		}
	}
    return 0;
}
