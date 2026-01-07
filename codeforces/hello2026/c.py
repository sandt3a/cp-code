def solve(n, m, k):
    a = k-1
    b = n-k
    s = min(a,b)
    l = max(a,b)

    if m <= 3*s - 1:
        ans = 1 + (2*m + 2)//3
    else:
        ans = 1 + 2*s
        rem = m - (3*s - 1)
        ans += min(l - s, rem//2)

    ans = min(ans, n)
    print(ans)

try:
    T = int(input())
    for i in range(T):
        n, m, k = map(int, input().split(' '))
        solve(n, m, k)
except:
    exit(-1)
