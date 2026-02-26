// Constantes hardcoded para MOD = 998244353, depois ver como achar raiz primitiva pra qualquer primo
const int root_int = 15311432;      // Raiz primitiva de ordem 2^23
const int root_1_int = 469870224;   // Inverso modular da raiz
const int root_pw = 1 << 23;        // 8388608

void fft(vector<mint> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        mint wlen = invert ? root_1_int : root_int;

        for (int i = len; i < root_pw; i <<= 1)
            wlen *= wlen;

        for (int i = 0; i < n; i += len) {
            mint w = 1;
            for (int j = 0; j < len / 2; j++) {
                mint u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        mint n_inv = mint(n).inv();
        for (mint & x : a)
            x *= n_inv;
    }
}

vector<mint> multiply(vector<mint> const& a, vector<mint> const& b) {
    vector<mint> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < sz(a)+ sz(b))
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);
    return fa;
}

