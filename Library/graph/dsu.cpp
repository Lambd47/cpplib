
struct dsu{
    vector<int> pai;
    vector<int> sz;
    vector<pair<int*,int>> hist;
 
    dsu(int n):pai(n,0),sz(n,1){
        iota(pai.begin(),pai.end(),0);
    }
 
    //no compression
    /*int find(int node){
        int cor=0;
        while(pai[node]!=node){

            node=pai[node];
        }
        return node;
    }*/
    int find(int node){
        if(node==pai[node])return node;
        return pai[node]=find(pai[node]);
    }
 
    int snap(){
        return (int)hist.size();
    }
    void modify(int &a, int b){
        hist.emplace_back(&a,a);
        a=b;
    }
    void roll(int x){
        while((int)hist.size()>x){
            *hist.back().first=hist.back().second;
            hist.pop_back();
        }
    }
 
    bool uni(int a, int b){//1 se deu bom
        a=find(a);
        b=find(b);
        if(a==b)return 0;
        if(sz[a]<sz[b])swap(a,b);
        pai[b]=a;
        sz[a]+=sz[b];
        return 1;
    }
 
};
