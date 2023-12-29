fn dfs(G: &Vec<Vec<usize>>, v: usize, prev: usize) {
    for i in 0..(G[v].len()) {
        let nv = G[v][i];
        if nv == prev {
            continue;
        }
        dfs(G, dist, nv, v);
    }
}
