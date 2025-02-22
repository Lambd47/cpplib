template<typename T>
struct ST{
    int n;
    vector<vector<T>> sp;

    ST(vector<T> v) : n(v.size()), sp(int(__lg(n))+1, vector<T>(n)){
        sp[0] = v;

        for(int i = 1; i < sp.size(); i++)
            for(int j = 0; j + (1<<i) <= n; j++)
                sp[i][j] = merge(sp[i-1][j], sp[i-1][j+(1<<i-1)]);

    }

    static T merge(T a, T b){
        
    }

    T query(int l, int r){ // must be called with l <= r
        int logg = __lg(r-l+1);
        return merge(sp[logg][l], sp[logg][r-(1<<logg)+1]);
    }
};
