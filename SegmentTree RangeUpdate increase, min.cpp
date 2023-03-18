struct SegmentTreeMin {

    struct Node {
        int val, modi;
    };

    vector<Node> tre;
    const int NO_OPERATION = 0;
    const int NEUTRAL = IINF;
    int sz;

    SegmentTreeMin(vector<int> &a) {
        int n = (int) a.size();
        sz = 1;
        while (sz < n) sz *= 2;
        tre.assign(2 * sz, {NEUTRAL, NO_OPERATION});
        build(a, 1, 0, sz);
    }

    SegmentTreeMin(int n) {
        sz = 1;
        while (sz < n) sz *= 2;
        tre.assign(2 * sz, {NEUTRAL, NO_OPERATION});
    }

    int op_modify(int x, int y) {
        return x + y;
    }

    int op_calc(int x, int y) {
        return min(x, y);
    }

    void propagate(int x, int lx, int rx) {
        if (rx - lx == 1 || tre[x].modi == NO_OPERATION) return;
        int m = (lx + rx) / 2;
        tre[2 * x].modi     = op_modify(tre[2 * x].modi, tre[x].modi);
        tre[2 * x].val      = op_modify(tre[2 * x].val, tre[x].modi);
        tre[2 * x + 1].modi = op_modify(tre[2 * x + 1].modi, tre[x].modi);
        tre[2 * x + 1].val  = op_modify(tre[2 * x + 1].val, tre[x].modi);
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
            tre[x].val = op_modify(tre[x].val, v);
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

    int get(int l, int r, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if (rx <= l || lx >= r) {
            return NEUTRAL;
        }
        if (l <= lx && r >= rx) {
            return tre[x].val;
        }
        int m = (lx + rx) / 2;
        int s1 = get(l, r, 2 * x, lx, m);
        int s2 = get(l, r, 2 * x + 1, m, rx);
        return op_calc(s1, s2);
    }

    int get(int l, int r) {
        return get(l, r, 1, 0, sz);
    }
};
