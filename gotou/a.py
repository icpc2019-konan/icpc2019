while True:
    n,m = map(int, input().split())
    if(n+m  ==0):
        break
    li = list()
    for i in range(m):
        line = map(int, input().split())
        li.append(line)
    ans = [0 for i in range(n)]
    for i in range(m):
        for j in range(n):
            ans[j] += li[i][j]
    print(max(ans))