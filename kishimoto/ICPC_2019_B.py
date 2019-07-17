while (True):
    N, M = map(int, input().split())
    if N == 0 and M == 0:
        break
    keyboard = []
    for i in range(N):
        keyboard.append(list(list(input())))

    inputLine = input()
    n_i = 0
    m_i = 0
    cnt = 0
    for i in range(len(inputLine)):
        for n, key_j in enumerate(keyboard):
            if (inputLine[i] in key_j):
                m = key_j.index(inputLine[i])
                cnt += abs(n_i - n) + abs(m_i - m)
                n_i = n
                m_i = m
                break
    cnt += len(inputLine)
    print(cnt)
