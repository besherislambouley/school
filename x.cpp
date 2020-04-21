/*
 * https://github.com/nikolapesic2802/Programming-Practice/blob/master/Schools/main.cpp
*/
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 547
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ll mod=1e9+7;
const ld pai=acos(-1);
ll n , m , s , ans ;
pll a[300009] ;
mset< pair < ll , pll > , greater < pair < ll , pll > > > t , ntm , nts ;
int main () {
	cin >> n >> m >> s ;
	for ( int i = 0 ; i < n ; i ++ ) {
		cin >> a[i].fi >> a[i].se ;
	}
	sort ( a , a + n ) ;
	reverse ( a , a + n ) ;
	for ( ll i = 0 ; i < m ; i ++ ) {
		ans += a[i].fi ;
		t.ins ( { a[i].se - a[i].fi , { a[i].fi , a[i].se } } ) ;
	}
	for ( ll i = m ; i < n ; i ++ ) {
		ntm .ins ( { a[i].fi , { a[i].fi , a[i].se } } ) ;
		nts .ins ( { a[i].se , { a[i].fi , a[i].se } } ) ;
	}
	for ( ll i = 0 ; i < s ; i ++ ) {
		ll val1 = nts.begin()->fi ;
		ll val2 = t.begin()->se.se - t.begin()->se.fi + ntm.begin()->fi;
		if ( val1 >= val2 ) {
			ans += val1 ;
			ll a = nts.begin()->se.fi , b = nts.begin()->se.se ;
			nts .era ( nts .find ( { b , { a , b } } ) ) ;
			ntm .era ( ntm .find ( { a , { a , b } } ) ) ;
		}
		else {
			ans += val2 ;
			ll A = t.begin()->se.fi , B = t.begin()->se.se ;
			t .era ( t.begin() ) ;
			ll a = ntm.begin()->se.fi , b = ntm.begin()->se.se ;
			nts .era ( nts .find ( { b , { a , b } } ) ) ;
                        ntm .era ( ntm .find ( { a , { a , b } } ) ) ;
			t .ins ( { b - a , { a , b } } ) ;
		}
	}
	cout << ans << endl ;
}
