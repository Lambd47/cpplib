struct pt{
    int x,y;
    bool operator<(const pt&aux)const{
        if(x==aux.x)return y<aux.y;
        return x<aux.x;
    }
    int operator*(const pt&aux)const{
        return x*aux.y -y*aux.x;
    }
    pt operator-(const pt&aux)const{
        return {x-aux.x,y-aux.y};
    }
    pt operator+(const pt&aux)const{
        return {x+aux.x,y+aux.y};
    }
    bool operator==(const pt&aux)const{
        return (x==aux.x)&&(y==aux.y);
    }
};

vector<pt> ptvazio;

vector<pt> uphull(vector<pt>& vec, bool include_col){
    sort(vec.begin(),vec.end());
    vector<pt> ret;

    for(int i=0;i<(int)vec.size();i++){
        if(i!=0 && vec[i]==vec[i-1])continue;
        while(ret.size()>1 && (((ret[ret.size()-2]-ret.back())*(vec[i]-ret.back())<0)
                    ||((!include_col)&&(ret[ret.size()-2]-ret.back())*(vec[i]-ret.back())==0))){
            ret.pop_back();
        }
        ret.push_back(vec[i]);
    }
    return ret;
}

vector<pt> dwnhull(vector<pt>& vec,bool include_col){
    sort(vec.begin(),vec.end());
    vector<pt> ret;

    for(int i=0;i<(int)vec.size();i++){
        if(i!=0 && vec[i]==vec[i-1])continue;
        while(ret.size()>1 && (((ret[ret.size()-2]-ret.back())*(vec[i]-ret.back())>0)
                    ||((!include_col)&&(ret[ret.size()-2]-ret.back())*(vec[i]-ret.back())==0))){
            ret.pop_back();
        }
        ret.push_back(vec[i]);
    }
    return ret;
}

vector<pt> convex_hull(vector<pt>&vec,bool include_col){
    if(vec.size()==0)return ptvazio;
    vector<pt> upper=uphull(vec,include_col);
    vector<pt> dwn=dwnhull(vec,include_col);
    dwn.pop_back();
    if(dwn.size()>=1){
    reverse(dwn.begin(),dwn.end());
    dwn.pop_back();
    }
    for(auto p:dwn)upper.push_back(p);
    return upper;
}

