import heapq

def dijkstra(start: int, G: list[tuple[int]]):
    """ 経路の表現
            [終点, 辺の値]
            A, B, C, D, ... → 0, 1, 2, ...とする """
    N = len(G)
    inf = 10**18
    dist = [inf] * N    #スタート地点以外の値は∞で初期化
    dist[start] = 0     #スタートは0で初期化

    node_name = []
    heapq.heappush(node_name, [start, 0])

    while len(node_name):
        #ヒープから取り出し
        _, min_point = heapq.heappop(node_name)
        
        #経路の要素を各変数に格納することで，視覚的に見やすくする
        for nex in G[min_point]:
            goal, cost = nex

            #更新条件
            if dist[min_point] + cost < dist[goal]:
                dist[goal] = dist[min_point] + cost     #更新
                #ヒープに登録
                heapq.heappush(node_name, [dist[min_point] + cost, goal])

    return dist
