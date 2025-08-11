import sys

# 상수 설정
INF = float('inf')

# 입력 받기
# sys.stdin.readline()을 사용하여 빠르게 입력받습니다. 이는 백준 표준 방식입니다.
n, m = map(int, sys.stdin.readline().split())

# dist 배열 초기화 (플로이드-워셜 준비)
# 올바른 들여쓰기로 수정했습니다.
dist = [[INF] * (n + 1) for _ in range(n + 1)]
for i in range(1, n + 1):
    dist[i][i] = 0

# 간선 정보 저장
edges = []
for _ in range(m):
    # 올바른 들여쓰기로 수정했습니다.
    u, v, l = map(int, sys.stdin.readline().split())
    # 양방향 간선이며, 더 짧은 경로가 있을 수 있으므로 min 사용
    dist[u][v] = min(dist[u][v], l)
    dist[v][u] = min(dist[v][u], l)
    edges.append((u, v, l))

# 1. 플로이드-워셜 알고리즘으로 모든 쌍 최단 경로 계산
# 올바른 들여쓰기로 수정했습니다.
for k in range(1, n + 1):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if dist[i][j] > dist[i][k] + dist[k][j]:
                dist[i][j] = dist[i][k] + dist[k][j]

# 2. 최적의 시작점 찾기
min_max_time = INF

# 모든 정점을 시작점(s)으로 시도
# 올바른 들여쓰기로 수정했습니다.
for s in range(1, n + 1):
    current_max_time = 0
    # s에서 시작했을 때, 모든 간선이 타는 시간 계산
    for u, v, l in edges:
        # u 정점이 불붙는 시간: dist[s][u]
        # v 정점이 불붙는 시간: dist[s][v]
        # (u, v) 간선이 완전히 타는 시간
        burn_time = (dist[s][u] + dist[s][v] + l) / 2.0
        current_max_time = max(current_max_time, burn_time)
    
    # 모든 시작점 중 가장 빨리 끝나는 경우를 찾는다
    min_max_time = min(min_max_time, current_max_time)

# 결과 출력
# 만약 간선이 하나도 없다면(m=0) min_max_time은 초기값 INF를 가지므로 0.0을 출력해야 합니다.
if m == 0:
    print("0.0")
else:
    # f-string을 사용하여 소수점 첫째 자리까지 출력하는 것은 백준의 요구사항을 만족합니다.
    print(f"{min_max_time:.1f}")