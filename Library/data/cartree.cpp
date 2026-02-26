template<class T, class cmp = less<T>>
//copiado do mano defnotmee
struct CarTree{
    //menor em cima, maior em baixo
    //em particular, menor de todos eh o root, maiores as folhas
    private:
    int n;
    vector<T> v;
    public:
    vector<T> fl, fr, rl, rr, up;
    int root;
    // fl: FirstLeft : mais perto menor que ele da esquerda,default -1
    // fr: FirstRight: mais perto menor que ele da direita, default n
    // rl: RootLeft: root da esquerda,default i
    // rr: RootRight: root da direita,default i
    // up: pai, default -1

    CarTree(vector<T>& _v) : n(_v.size()), v(_v), fl(n), fr(n), rl(n), rr(n), up(n,-1){
        for(int i = 0; i < n; i++){
            fl[i] = i-1;
            rl[i] = rr[i] = i;
            fr[i] = n;

            int lst = -1;
            while(fl[i] != -1 && cmp()(v[i], v[fl[i]])){
                lst = fl[i];
                fr[fl[i]] = i;
                fl[i] = fl[fl[i]];
            }
            if(lst != -1)
                rl[i] = lst, up[lst] = i;
            if(fl[i] != -1)
                rr[fl[i]] = i, up[i] = fl[i];
        }

        root = min_element(up.begin(),up.end())-up.begin();
    }
};
