#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<unordered_map>
#include<unordered_set>
#include<bitset>
#include<sstream>
#include<numeric>
#include<queue>
#include<stack>
#include<cstdio>
#include<fstream>
#include<iomanip>
#include<exception>
#include<iterator>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
using ll = long long;
using ull = unsigned long long;

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define pb(x) push_back(x)
ll mod = 1e9 + 7;
ll inf = 1e9 + 7;
template<typename T, typename U>
T binpow(T a, U n) {
    if (n == 0)
        return 1;
    if (n % 2 == 1)
        return (binpow(a, n - 1) * a) % mod;
    else {
        ll b = binpow(a, n / 2) % mod;
        return (b * b) % mod;
    }
}
template<typename T>
T gcd(T a, T b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
template<typename T>
istream& operator>>(istream& str, vector<T>& vec) {
    for (auto& w : vec) {
        cin >> w;
    }
    return str;
}

template<typename T, typename U>
ostream& operator<<(ostream& str, pair<T, U>& th) {
    cout << '{' << th.first << ", " << th.second << '}';
    return str;
}
template<typename T>
ostream& operator<<(ostream& str, vector<T>& vec) {
    for (auto& w : vec) str << w << '\n';
    return str;
}


vector<vector<int>>g;
vector<int>ans;
void func(int v) { // в случае эйлерова пути нужно выходить из вершины с нечетной степенью
    vector<int>vec;
    vec.push_back(v);
    while (!vec.empty()) {
        v = vec.back();
        if (!g[v].empty()) {
            vec.push_back(g[v].back());
            g[v].pop_back();
        }
        else {
            ans.push_back(vec.back());
            vec.pop_back();
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    g.resize(k);
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            g[i].push_back(j);
        }
    }
    func(0);
    ans.pop_back();
    for (int i = 0; i < n; ++i) {
        cout << char('a' + ans[(i % ans.size())]);
    }
}