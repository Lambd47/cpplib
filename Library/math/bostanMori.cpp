//nao ta stress-tested
mint bostanMori(vector<mint> A, vector<mint> B, int m) {
    if(m == 0)return A[0]/B[0];
    vector<mint> nB = B;
    for(int i=1;i<sz(nB);i+=2) {
        nB[i] = -nB[i];
    }
    vector<mint> A2 = multiply(A, nB);
    vector<mint> B2 = multiply(B, nB); 
    vector<mint> A3, B3;
    for(int i=m%2; i<sz(A2); i+=2) {
        A3.push_back(A2[i]);
    }
    for(int i=0; i<sz(B2); i+=2) {
        B3.push_back(B2[i]);
    }
    return bostanMori(A3, B3, m / 2);
}
mint mthTerm(const vector<mint>& S,int m) {//primeiros 2k termos (se tem grau <=k) e o indice que queremos
    vector<mint> C = berlekampMassey(S);
    int K = sz(C);
    if (K==0) return 0;
    vector<mint> B(K + 1);
    B[0]=1;
    for (int i=0; i<K; i++) {
        B[i + 1]=-C[i];
    }
    vector<mint> A(K);
    for (int i=0; i<K; i++) {
        for (int j=0; j<=i; j++) {
            A[i] += S[i-j]*B[j];
        }
    }
    return bostanMori(A, B, m);
}
