//thatsramen

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define eb emplace_back
#define pb push_back
#define ft first
#define sd second
#define pi pair<int, int>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(...) dbg_out(__VA_ARGS__)

using ll = long long;
using ld = long double;
using namespace std;
using namespace __gnu_pbds;

//Constants
const ll INF = 5 * 1e18;
const int IINF = 2 * 1e9;
// const ll MOD = 1e9 + 7;
const ll MOD = 998244353;
const ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ld PI = 3.14159265359;

//Templates
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) {return os << '(' << p.first << ", " << p.second << ')';}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) {os << '['; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << ']';}
void dbg_out() {cerr << endl;}
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << ' '; dbg_out(T...); }
template<typename T> bool mins(T& x, T y) { if (x > y) { x = y; return true; } return false; }
template<typename T> bool maxs(T& x, T y) { if (x < y) { x = y; return true; } return false; }
template<typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using omset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

//order_of_key(k): number of elements strictly less than k
//find_by_order(k): k-th element in the set

void setPrec() {cout << fixed << setprecision(15);}
void unsyncIO() {cin.tie(0)->sync_with_stdio(0);}
void setIn(string s) {freopen(s.c_str(), "r", stdin);}
void setOut(string s) {freopen(s.c_str(), "w", stdout);}
void setIO(string s = "") {
    unsyncIO(); setPrec();
    if(s.size()) setIn(s + ".in"), setOut(s + ".out");
}

// #define TEST_CASES

void solve() {
    
}

int main() {
    setIO();

    int tt = 1;
    #ifdef TEST_CASES
        cin >> tt;
    #endif

    while (tt--)
        solve();

    return 0;
}
