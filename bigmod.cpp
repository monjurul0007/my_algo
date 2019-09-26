#include <bits/stdc++.h>
using namespace std;
     
typedef long long int ll;     
typedef pair<int , int>  pii;
     
ll bigmod(ll n, ll p, ll m){
	if(p <= 0)
		return 1;
	if(p%2 == 0){
		ll ans = bigmod(n,p/2,m);
		return ((ans%m)*(ans%m))%m;
	}
	else {
		ll ans = bigmod(n,p-1,m);
		return ((n%m)*(ans%m))%m;
	}
}
         
int main(){
  ll n,p,m;
  while(cin >> n >> p >> m){
		cout << bigmod(n,p,m) << endl;
	}
    return 0;
}
