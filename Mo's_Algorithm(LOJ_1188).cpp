/*      bismillahir rahmanir rahim   
 *		     @ monjurul0007
 */


#include <bits/stdc++.h>

using namespace std;

#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define all(x) x.begin(),x.end()
#define mem(arr,value) memset(arr, value, sizeof(arr))
#define F first
#define S second
#define mod 100000007

typedef long long int ll;    
typedef unsigned long long int ull;   
typedef pair<int , int>  pii;
typedef pair<int , pii > piii; 
typedef priority_queue <pii, vector<pii> , greater<pii> > pq;

const int dx4[4] = {0,1,0,-1};
const int dy4[4] = {1,0,-1,0};
const int dx8[8] = {0,1,0,-1,1,-1,1,-1};
const int dy8[8] = {1,0,-1,0,1,-1,-1,1};

int ar[100005],n,q,k;

struct queries{
	int in,l,r;
	bool operator < (const queries &cur){
		if(l/k == cur.l/k )
			return r < cur.r;
		else
			return l/k < cur.l/k ;
	}
} qu[50005];


int main(){
	int t;
	scanf("%d",&t);
	
	for(int T=1; T<=t; T++){
		scanf("%d %d",&n,&q);
		for(int i=1; i<=n; i++)
			scanf("%d",&ar[i]);
		for(int i=0; i<q; i++){
			qu[i].in = i;
			scanf("%d %d",&qu[i].l,&qu[i].r);
		}
		
		k = ceil(sqrt(n));
		sort(qu, qu+q);
		
		
		int ans[q+5],fre[100005],l=1,r=0,cnt=0;
		mem(fre,0);
		
		for(int i=0; i<q; i++){
			while(r < qu[i].r){
				if(fre[ar[++r]] == 0) cnt++;
				fre[ar[r]]++;	
			}
			
			while(l < qu[i].l){
				if(fre[ar[l]] == 1) cnt--;
				fre[ar[l++]]--;
			}
			
			while(r > qu[i].r){
				if(fre[ar[r]] == 1) cnt--;
				fre[ar[r--]]--;	
			}
			
			while(l > qu[i].l){
				if(fre[ar[--l]] == 0) cnt++;
				fre[ar[l]]++;
			}	
			
			ans[qu[i].in] = cnt;
		}
		
		printf("Case %d:\n",T);
		for(int i=0; i<q; i++)
			printf("%d\n",ans[i]);
			
	}
	return 0;
}
