struct automaton{
    struct Node{
        int len,link;
        map<char,int> next;
    };
    vector<Node> vec;
    int last;
    automaton(){
        vec.push_back(Node());
        vec.back().len=0;
        vec.back().link=-1;
        last=0;
    }
    int create(){
        vec.push_back(Node());
        return sz(vec)-1;
    }
    void add(char c){
        int cur=create();
        vec[cur].len=vec[last].len+1;
        int p=last;
        while(p!=-1 && !vec[p].next.count(c)){
            vec[p].next[c]=cur;
            p=vec[p].link;
        }
        if(p==-1){
            vec[cur].link=0;
        }else{
            int q=vec[p].next[c];
            if(vec[p].len+1==vec[q].len){
                vec[cur].link=q;
            }else{
                int clone=create();
                vec[clone].len=vec[p].len+1;
                vec[clone].next=vec[q].next;
                vec[clone].link=vec[q].link;
                while(p!=-1 && vec[p].next[c]==q){
                    vec[p].next[c]=clone;
                    p=vec[p].link;
                }
                vec[q].link=vec[cur].link=clone;
            }
        }
        last=cur;
    }
};
