#include <bits/stdc++.h>

#define int long long
using namespace std;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define pb(x) push_back(x)
#define mp make_pair

template<class T> bool chmin(T& a, const T& b){return (b<a)?a=b,true:false;}
template<class T> bool chmax(T& a, const T& b){return (b>a)?a=b,true:false;}

#define tcT template<class T
#define tcTU tcT, class U
#define tcTUU tcT, class ...U

tcT> void re(T& x) { cin >> x; }
tcTUU> void re(T& t, U&... u) { re(t); re(u...); }
tcTU> void re(pair<T,U>& p) { re(p.first,p.second); }
tcT> void re(vector<T>& x) { for(auto& a:x) re(a); }

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {


}
 
int32_t main() {
    std::cin.tie(0)->sync_with_stdio(0); 
    std::cin.exceptions(std::cin.failbit);

    int T = 1;
//    std::cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}


