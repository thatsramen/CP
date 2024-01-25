struct SegmentTree {

    vector<int> tre;
    int sz;

    SegmentTree(vector<int> &a) {
        int n = (int) a.size();
        sz = 1;
        while (sz < n) sz *= 2;
        tre.assign(2 * sz, -IINF);
        build(a, 1, 0, sz);
    }

    SegmentTree(int n) {
        sz = 1;
        while (sz < n) sz *= 2;
        tre.assign(2 * sz, -IINF);
    }

    void rcl(int x) {
        tre[x] = max(tre[2 * x], tre[2 * x + 1]);
    }

    void build(vector<int> &a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < a.size()) {
                tre[x] = a[lx];
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2 * x, lx, m);
        build(a, 2 * x + 1, m, rx);
        rcl(x);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tre[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m) {
            set(i, v, 2 * x, lx, m);
        } else {
            set(i, v, 2 * x + 1, m, rx);
        }
        rcl(x);
    }

    void set(int i, int v) {
        set(i, v, 1, 0, sz);
    }

    int get(int l, int r, int x, int lx, int rx) {
        if (rx <= l || lx >= r) {
            return -IINF;
        }
        if (l <= lx && r >= rx) {
            return tre[x];
        }
        int m = (lx + rx) / 2;
        int s1 = get(l, r, 2 * x, lx, m);
        int s2 = get(l, r, 2 * x + 1, m, rx);
        return max(s1, s2);
    }

    int get(int l, int r) {
        return get(l, r, 1, 0, sz);
    }
};
