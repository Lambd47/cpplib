template<class Info>
struct SegmentTree {//1-indexada (obviamente xD)
    int n;
    vector<Info> info;

    SegmentTree() : n(0) {}
    SegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }

    template<class T>
    SegmentTree(vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(vector(n_, v_));
    }
    template<class T>
    void init(vector<T> init_) {
        n = init_.size();
        info.assign(4 << __lg(n), Info());
        function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (l==r) {
                info[p] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m+1, r);
            pull(p);
        };
        build(1, 1, n);
    }
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void update(int p, int l, int r, int id, const Info &v) {
        if(l>id || r<id)return;
        if(l==r){
            info[p]=v;
            return;
        }
        int m = (l + r) / 2;
        update(2 * p, l, m, id, v);
        update(2 * p + 1, m+1, r, id, v);
        pull(p);
    }
    void modify(int id, const Info &v) {
        modify(1, 1, n, id, v);
    }
    Info query(int p, int l, int r, int ll, int rr) {
        if (l >= rr || r <= ll) {
            return Info();//vazio
        }
        if (ll<=l && r <= rr) {
            return info[p];
        }
        int m = (l + r) / 2;
        return query(2 * p, l, m, ll, rr) + query(2 * p + 1, m+1, r, ll, rr);
    }
    Info query(int l, int r) {
        return query(1, 1, n, l, r);
    }
    
};

struct Info{

};

Info operator+(const Info& a, const Info& b){

}
