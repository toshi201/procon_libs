def prime_factorize(N):
    N2 = N
    ans = []
    i = 2
    while i * i <= N:
        cnt = 0
        while N2 % i == 0:
            N2 //= i
            cnt += 1

        if cnt > 0:
            ans.append([i, cnt])
        i += 1

    if N2 != 1:
        ans.append([N2, 1])

    return ans
