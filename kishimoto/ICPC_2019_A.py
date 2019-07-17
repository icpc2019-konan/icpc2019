while (True):
    N, M = map(int, input().split())
    if N == 0 and M == 0:
        break
    Score = [list(map(int, input().split())) for _ in range(M)]
    Total = []
    for n in range(N):
        sum_score = 0
        for m in range(M):
            sum_score += Score[m][n]
        Total.append(sum_score)
    print(max(Total))
