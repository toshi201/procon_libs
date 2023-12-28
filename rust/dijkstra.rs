use std::collections::BinaryHeap;

fn dijkstra(G: &Vec<Vec<(usize, i64)>>, dist: &mut Vec<i64>, start: usize) {
    // distの初期値はinfであることを想定
    dist[start] = 0;
    let mut hea = BinaryHeap::from(vec![(0, start)]);

    let mut visited = vec![false; G.len()];
    while let Some((_, v)) = hea.pop() {
        if visited[v] {
            continue;
        }

        visited[v] = true;
        for i in 0..G[v].len() {
            let (nv, c) = G[v][i];
            if dist[nv] > dist[v] + c {
                dist[nv] = dist[v] + c;
                // heapはmax heapであるため、負の数にする
                hea.push((-dist[nv], nv));
            }
        }
    }
}
