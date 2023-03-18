struct SegmentTree {

    struct Node {
        ll val, modi;
    };

    vector<Node> tre;
    const ll NO_OPERATION = 0;
    const ll NEUTRAL = 0;
    int sz;

    SegmentTree(vector<int> &a) {
        int n = (int) a.size();
        sz = 1;
        while (sz < n) sz *= 2;
        tre.assign(2 * sz, {NEUTRAL, NO_OPERATION});
        build(a, 1, 0, sz);
    }

    SegmentTree(int n) {
        sz = 1;
        while (sz < n) sz *= 2;
        tre.assign(2 * sz, {NEUTRAL, NO_OPERATION});
    }

    ll op_modify(ll x, ll y) {
        return x + y;
    }

    ll op_modify2(ll x, ll y, int lx, int rx) {
        return x + (rx - lx) * y;
    }

    ll op_calc(ll x, ll y) {
        return x + y;
    }

    void propagate(int x, int lx, int rx) {
        if (rx - lx == 1 || tre[x].modi == NO_OPERATION) return;
        int m = (lx + rx) / 2;
        tre[2 * x].modi     = op_modify(tre[2 * x].modi, tre[x].modi);
        tre[2 * x].val      = op_modify2(tre[2 * x].val, tre[x].modi, lx, m);
        tre[2 * x + 1].modi = op_modify(tre[2 * x + 1].modi, tre[x].modi);
        tre[2 * x + 1].val  = op_modify2(tre[2 * x + 1].val, tre[x].modi, m, rx);
        tre[x].modi = NO_OPERATION;
    }

    void build(vector<int> &a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < a.size()) {
                tre[x].val = a[lx];
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2 * x, lx, m);
        build(a, 2 * x + 1, m, rx);
        tre[x].val = op_calc(tre[2 * x].val, tre[2 * x + 1].val);
    }

    void set(int l, int r, int v, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if (rx <= l || lx >= r) {
            return;
        }
        if (l <= lx && r >= rx) {
            if (tre[x].modi == NO_OPERATION) {
                tre[x].modi = v;
            } else {
                tre[x].modi = op_modify(tre[x].modi, v);
            }
            tre[x].val = op_modify2(tre[x].val, v, lx, rx);
            return;
        }
        int m = (lx + rx) / 2;
        set(l, r, v, 2 * x, lx, m);
        set(l, r, v, 2 * x + 1, m, rx);
        tre[x].val = op_calc(tre[2 * x].val, tre[2 * x + 1].val);
    }

    void set(int l, int r, int v) {
        set(l, r, v, 1, 0, sz);
    }

    ll get(int l, int r, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if (rx <= l || lx >= r) {
            return NEUTRAL;
        }
        if (l <= lx && r >= rx) {
            return tre[x].val;
        }
        int m = (lx + rx) / 2;
        ll s1 = get(l, r, 2 * x, lx, m);
        ll s2 = get(l, r, 2 * x + 1, m, rx);
        return op_calc(s1, s2);
    }

    ll get(int l, int r) {
        return get(l, r, 1, 0, sz);
    }
};
