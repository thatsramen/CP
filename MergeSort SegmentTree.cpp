struct SegmentTree {
    
    vector<vector<int>> tre;
    int sz;
    
    SegmentTree(vector<int> &a) {
        int n = (int) a.size();
        sz = 1;
        while (sz < n) sz *= 2;
        tre.resize(2 * sz);
        build(a, 1, 0, sz);
    }

    vector<int> op(vector<int> &a, vector<int> &b) {
        vector<int> res;
        int n = a.size(), m = b.size();
        int i = 0, j = 0;
        while (i < n || j < m) {
            if (j == m || (i < n && a[i] < b[j])) {
                res.pb(a[i++]);
            } else {
                res.pb(b[j++]);
            }
        }
        return res;
    }

    void rcl(int x) {
        tre[x] = op(tre[2 * x], tre[2 * x + 1]);
    }

    void build(vector<int> &a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < a.size()) {
                tre[x] = {a[lx]};
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2 * x, lx, m);
        build(a, 2 * x + 1, m, rx);
        rcl(x);
    }

    int get(int l, int r, int bb, int x, int lx, int rx) {
        if (rx <= l || lx >= r) {
            return 0;
        }
        if (l <= lx && r >= rx) {
            //get
            return;
        }
        int m = (lx + rx) / 2;
        int s1 = get(l, r, bb, 2 * x, lx, m);
        int s2 = get(l, r, bb, 2 * x + 1, m, rx);
        return;
    }

    int get(int l, int r, int bb) {
        return get(l, r, bb, 1, 0, sz);
    }
};