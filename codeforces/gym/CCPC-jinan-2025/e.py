def solve():
    a, b, c, x, y, d = map(int, input().split(' '))

    if (d <= x):
        ans = a
    elif (d <= x + y):
        ans = min(a * (d // x) + min(a, b * (d % x)), a + b * (d - x)) # A*(A|B)
    else:
        ans = a + b * y + c * (d - x - y) # ABC

        q = d // x
        r = d % x
        ans = min(ans,
                  a * q + min(a, b * min(r, q * y) + c * max(0, r - q * y)), # A*(A|B|BC)
                  a * q + min(a, b * y + c * max(0, r - y)) # A*(ABC)
                  )
        q = d // (x + y)
        r = d % (x + y)
        ans = min(ans, (a + b * y) * q + min(a + b * max(-q * y, r - x), c * r)) # (AB)*(A|AB|C)
    print(ans)

def main():
    T = int(input())
    for _ in range(T):
        solve()

if __name__ == '__main__':
    main()
