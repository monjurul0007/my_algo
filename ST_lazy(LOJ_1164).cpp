#include <bits/stdc++.h>

using namespace std;

#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define inf LLONG_MAX
#define neginf LLONG_MIN
#define wk cout << "working" << endl

#define f0(i,n) for(i=0; i<n; i++)
#define f1(data,i,n) for(data i=1; i<=n; i++) 
#define all(x) x.begin(),x.end()

         
typedef long long int ll;     
typedef pair<int , int>  pii;
typedef pair<int , pii > piii; 
typedef priority_queue <pii, vector<pii> , greater<pii> > pq;

ll tree[100005*3];
ll tree_prop[100005*3];

void update(int node, int i, int j, int b, int e, ll v){
	if(j<b || e < i)
		return;
	
	if(i<=b && e<=j){
		tree_prop[node] += v;
		tree[node] += v*(e-b+1);
		return; 
	}
	
	int left = node*2;
	int right = node*2 +1;
	int mid = (b+e)/2;
	
	update(left, i, j, b, mid, v);
	update(right, i, j, mid+1, e, v);
	
	tree[node] = tree[left] + tree[right] + (e-b+1)*tree_prop[node];
		
}

ll query(int node, int i, int j, int b, int e, ll carry){
	if(j<b || e < i)
		return 0; 
	
	if(i<=b && e<=j){
		return tree[node]+ (e-b+1) * carry; 
	}
	
	int left = node*2;
	int right = node*2 +1;
	int mid = (b+e)/2;
	
	ll q1 = query(left, i, j, b, mid, carry + tree_prop[node]);
	ll q2 = query(right, i, j, mid+1, e, carry + tree_prop[node]);
	
	return q1 + q2;
}

int main(){
    int t,n,q,state,x,y,v;
    
	scanf("%d",&t);
	
	for(int T=1; T<=t; T++){
		memset(tree, 0, sizeof(tree));
		memset(tree_prop, 0, sizeof(tree_prop));
		scanf("%d %d",&n,&q);
		
		printf("Case %d:\n",T);
		
		for(int i=0; i<q; i++){
			scanf("%d %d %d",&state,&x,&y);
			x++;
			y++;
			
			if(state){
				printf("%lld\n",query(1,x,y,1,n,0));
			}
			else{
				scanf("%d",&v);
				update(1,x,y,1,n,v);
			}
	
		}
	}
	
    return 0;
}
