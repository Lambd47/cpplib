#include <bits/stdc++.h>
using namespace std;
 
#define bug(x) cerr << #x << " " << x << endl;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; 

struct detectcycle{
    private:
    vector<vector<int>> adj;
    vector<int> marc;
    vector<int> resp;
    stack<int> s;

    public:

    detectcycle(vector<vector<int>> _adj):marc((int)_adj.size(),0),adj(_adj){
        for(int i=1;i<_adj.size();i++){
            if(marc[i]==0)dfs(i,i);
        }
    }
    vector<int> find(){
        return resp;
    }


    void dfs(int node,int lst){
        if(!resp.empty())return;
        marc[node]=1;
        s.push(node);
        for(auto a: adj[node]){
            if(a==lst || marc[a]==2)continue;
            if(marc[a]==0){
            
            }
            else if(marc[a]==1){
                while(s.top()!=a){
                    resp.push_back(s.top());
                    s.pop();
                }
                resp.push_back(a);
            }
        }
        marc[node]=2;
        s.pop();
    }
};


void solve() {
    int n;cin>>n;
    vector<vector<int>> adj;
    for(int i=1;i<=n;i++){
    }
    detectcycle

}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

    int T = 1;
//    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}


