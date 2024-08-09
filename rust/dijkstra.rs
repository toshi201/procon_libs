use std::cmp::Reverse;
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

fn dijkstra2(graph: &Vec<Vec<(i64, usize)>>, start: usize) -> Vec<i64> {
    let inf = 1e18 as i64;
    let mut dist = vec![inf; graph.len()];
    let mut seen = vec![false; graph.len()];

    let mut bheap = BinaryHeap::new();
    bheap.push((Reverse(0), start));

    dist[start] = 0;
    while let Some((Reverse(_d), v)) = bheap.pop() {
        if seen[v] {
            continue;
        }
        seen[v] = true;
        for i in 0..graph[v].len() {
            let (nd, nv) = graph[v][i];
            if dist[nv] > (dist[v] + nd) {
                dist[nv] = dist[v] + nd;
                bheap.push((Reverse(dist[nv]), nv));
            }
        }
    }

    dist
}
