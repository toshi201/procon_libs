fn dfs(G: &Vec<Vec<usize>>, seen: &mut Vec<bool>, v: usize) {
    seen[v] = true;

    for i in 0..(G[v].len()) {
        let nv = G[v][i];
        if seen[nv] {
            continue;
        }
        dfs(G, seen, nv);
    }
}
