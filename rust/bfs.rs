use std::collections::VecDeque;

fn bfs(G: &Vec<Vec<usize>>, dist: &mut Vec<i64>, start: usize) {
    let mut que = VecDeque::from(vec![start]);
    dist[start] = 0;
    
    while let Some(v) = que.pop_front() {
        for i in 0..G[v].len() {
            let nv = G[v][i];
            if dist[nv] == -1 {
                dist[nv] = dist[v] + 1;
                que.push_back(nv);
            }
        }
    }
}
