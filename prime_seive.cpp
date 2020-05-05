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
typedef pair<ll , ll>  pii;
typedef pair<int , pii > piii; 

const int dirx[4] = {0,1,0,-1};
const int diry[4] = {1,0,-1,0};

vector <ll> prime;
bool mark[10000007];

void seive(){
	ll n = 10000000; 
	ll lim = sqrt(n*1.)+2;
	
	for(ll i=4; i<=n; i+=2)
		mark[i] = true;
	
	mark[0] = true;
	mark[1] = true;
	
	prime.push_back(2);
	
	for(ll i=3; i<=n; i++){
		if(!mark[i]){
			prime.push_back(i);
			if(i<=lim)
				for(ll j=i*i; j<=n; j += i*2)
					mark[j] = true;
		}
	}
}

int main(){
	fasterInOut;
	
	seive();
	
	for(int i=0; i<1000; i++)
		cout << prime[i] << " ";
	cout << endl;
		
    return 0;
}
