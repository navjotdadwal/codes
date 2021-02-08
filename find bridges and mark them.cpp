void dfs(int v, int p) {
    tin[v] = minAncestor[v] = ++timer;
    used[v] = 1;
    for(auto &e: g[v]) {
        int to, id;
        tie(to, id) = e;
        if(to == p) continue;
        if(used[to]) {
            minAncestor[v] = min(minAncestor[v], tin[to]);
        } else {
            dfs(to, v);
            minAncestor[v] = min(minAncestor[v], minAncestor[to]);
            if(minAncestor[to] > tin[v]) {
                isBridge[id] = true;
            }
        }
    }
}
