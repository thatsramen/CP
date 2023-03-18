struct Modular {
    int val;
 
    Modular(long long v = 0) {
        if (v < 0)
            v = v % MOD + MOD;
 
        if (v >= MOD)
            v %= MOD;
 
        val = v;
    }
 
    static int mod_inv(int a, int m = MOD) {
        int g = m, r = a, x = 0, y = 1;
 
        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }
 
        return x < 0 ? x + m : x;
    }
 
    explicit operator int() const {
        return val;
    }
 
    Modular& operator+=(const Modular &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
 
    Modular& operator-=(const Modular &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }
 
    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
           #if !defined(_WIN32) || defined(_WIN64)
                return x % m;
           #endif
           unsigned x_high = x >> 32, x_low = (unsigned) x;
           unsigned quot, rem;
           asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
           return rem;
    }
 
    Modular& operator*=(const Modular &other) {
        val = fast_mod((uint64_t) val * other.val);
        return *this;
    }
 
    Modular& operator/=(const Modular &other) {
        return *this *= other.inv();
    }
 
    friend Modular operator+(const Modular &a, const Modular &b) { return Modular(a) += b; }
    friend Modular operator-(const Modular &a, const Modular &b) { return Modular(a) -= b; }
    friend Modular operator*(const Modular &a, const Modular &b) { return Modular(a) *= b; }
    friend Modular operator/(const Modular &a, const Modular &b) { return Modular(a) /= b; }
 
    Modular& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
 
    Modular& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }
 
    Modular operator++(int32_t) { Modular before = *this; ++*this; return before; }
    Modular operator--(int32_t) { Modular before = *this; --*this; return before; }
 
    Modular operator-() const {
        return val == 0 ? 0 : MOD - val;
    }
 
    bool operator==(const Modular &other) const { return val == other.val; }
    bool operator!=(const Modular &other) const { return val != other.val; }
 
    Modular inv() const {
        return mod_inv(val);
    }
 
    Modular pow(long long p) const {
        assert(p >= 0);
        Modular a = *this, result = 1;
 
        while (p > 0) {
            if (p & 1)
                result *= a;
 
            a *= a;
            p >>= 1;
        }
 
        return result;
    }
 
    friend ostream& operator<<(ostream &stream, const Modular &m) {
        return stream << m.val;
    }
    friend istream& operator >> (istream &stream, Modular &m) {
        return stream >> m.val;   
    }
};

using mint = Modular;