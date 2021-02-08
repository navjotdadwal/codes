// finding bridges and marking them
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

// giving each bridge component its component id
void dfs1(int v, int p) {
    used[v] = 1;
    comp[v] = compid;
    for(auto &e: g[v]) {
        int to, id;
        tie(to, id) = e;
        
        if(isBridge[id]) { // avoid traversing from this edge. so we get full component.
            continue;
        }
        if(used[to]) {
            continue;
        }
        dfs1(to, v);
    }
}

// Traverse every edge, if it is a bridge, connect the two components via an edge.
for(int i = 1; i <= M; ++i) {
    if(isBridge[i]) {
         int u, v;
         tie(u, v) = edges[i];
         // connect two componets using edge.
         tree[comp[u]].push_back(comp[v]);
         tree[comp[v]].push_back(comp[u]);
    }
}
