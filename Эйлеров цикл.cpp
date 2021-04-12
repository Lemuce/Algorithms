
vector<vector<int>>g;
vector<int>ans;
void func(int v) { // in case of euler path, we start from vertex with odd degree
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
