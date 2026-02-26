//dado 2n termos de uma sequencia linear, acha os coeficientes.
//O(n^2), nao ta testado
//ith-term com bostanMori
vector<mint> berlekampMassey(const std::vector<mint>& s) {
    int n = s.size(), L = 0, m = 0;
    std::vector<mint> C(n), B(n), T;
    C[0] = B[0] = 1; 
    mint b = 1;
    L(i,0,n-1) {
        ++m;
        mint d = s[i];
        L(j,1,L) {
            d += C[j] * s[i - j];
        }
        if (d.value == 0) continue;
        T = C;
        mint coef = d * b.inv(); 
        L(j,m,n-1) {
            C[j] -= coef * B[j - m];
        }
        if (2*L>i) continue;
        L = i + 1 - L;B = T;b = d;m = 0;
    }
    C.resize(L + 1);
    C.erase(C.begin());
    for (mint& x : C) {
        x = -x; 
    }
    return C;
}
