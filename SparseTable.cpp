template<typename T>
struct SparseTable {

    vector<vector<T>> table;
    vector<int> log;

    function<T(T, T)> op;

    SparseTable(vector<T> &a, function<T(T, T)> f) {
        op = f;
        int n = a.size();
        log.assign(n + 5, 0);
        for (int i = 2; i <= n; i++) {
            log[i] = log[i / 2] + 1;
        }
        table.assign(log[n] + 5, vector<T> (n + 5));
        for (int j = 0; j < n; j++) {
            table[0][j] = a[j];
        }
        for (int i = 1; i <= log[n]; i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                table[i][j] = op(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    
    T query(int l, int r) {
        int sz = log[r - l + 1];
        T res = op(table[sz][l], table[sz][r - (1 << sz) + 1]);
        return res;
    }
};