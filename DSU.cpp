struct DSU {
    vector<int> e;
    DSU (int n) : e(n + 5, -1) {}
    int get(int x) { return e[x] <= -1 ? x : e[x] = get(e[x]); }
    int sz(int x) { return -e[get(x)]; }
    bool same(int x, int y) { return get(x) == get(y); }
    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return false;
        if (-e[x] < -e[y]) swap(x, y);
        e[x] += e[y]; e[y] = x;
        return true;
    }
};