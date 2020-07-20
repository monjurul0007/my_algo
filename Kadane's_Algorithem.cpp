/*      bismillahir rahmanir rahim   
  		     @ monjurul0007
           
 UVa - 507 Jill Rides Again
 Kadane's Algorithem to find a range with maximum sum in a given 1D arrey.
 
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
typedef pair<int , int>  pii;
typedef pair<int , pii > piii; 
typedef priority_queue <pii, vector<pii> , greater<pii> > pq;

const int dx4[4] = {0,1,0,-1};
const int dy4[4] = {1,0,-1,0};
const int dx8[8] = {0,1,0,-1,1,-1,1,-1};
const int dy8[8] = {1,0,-1,0,1,-1,-1,1};



 
int main(){
	fasterInOut;
	
	int t;
	cin >> t;
	
	int cnt = 1;
	while(t--){
		int n;
		cin >> n;
	
		int ar[n+1],ans=1,sum=0,in=1;
		int mx=-2,mi=-1;

		for(int i=0; i<n-1; i++){
			cin >> ar[i];
			sum += ar[i];
			
			if(sum < 0){
				sum = 0;
				in = i+2;
			}
			
			if(ans < sum || (ans == sum  && mx - mi < i-in+2)){
				ans = sum;
				mi = in;
				mx = i+2;
			}
			
		}
		
		
		if(mi == -1)
			cout << "Route " << cnt++ << " has no nice parts\n";
		else
			cout << "The nicest part of route " << cnt++ << " is between stops " << mi << " and " << mx << "\n";
		
		
	}
	
    return 0;
}
