from random import *

def gen_graph(n):
    m = randint(1, 1000)
    print(m)
    for i in range(m):
        print(randint(1, n), randint(1, n))

t = 1
print(t)

for _ in range(t):
    n = randint(1, 1000)
    s1 = randint(1, n)
    s2 = randint(1, n)

    print(n, s1, s2)

    gen_graph(n)
    gen_graph(n)
