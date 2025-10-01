import bisect
import sys

def main():
    input = sys.stdin.read
    data = input().split()
    idx = 0
    t = int(data[idx])
    idx += 1
    for _ in range(t):
        n = int(data[idx])
        idx += 1
        a = data[idx]
        idx += 1
        b = data[idx]
        idx += 1
        
        # Compute cnt0_a: cnt0_a[x] is number of '0's in a[0..x-1] (1-based x)
        cnt0_a = [0] * (n + 1)
        for x in range(1, n + 1):
            cnt0_a[x] = cnt0_a[x-1] + (a[x-1] == '0')
        
        # Compute cnt0_b
        cnt0_b = [0] * (n + 1)
        for y in range(1, n + 1):
            cnt0_b[y] = cnt0_b[y-1] + (b[y-1] == '0')
        
        # Prepare list for b: (K_y, B_y, D_y)
        b_list = []
        for y in range(1, n + 1):
            D = cnt0_b[y]
            B = y - D
            K = 2 * D - y
            b_list.append((K, B, D))
        
        # Sort b_list by K
        b_list.sort()
        K_sorted = [k for k, _, _ in b_list]
        
        # Compute prefix sums for B and D
        prefix_B = [0] * (n + 1)
        prefix_D = [0] * (n + 1)
        for i in range(n):
            prefix_B[i+1] = prefix_B[i] + b_list[i][1]
            prefix_D[i+1] = prefix_D[i] + b_list[i][2]
        S_D_total = prefix_D[n]
        
        total = 0
        for x in range(1, n + 1):
            C_x = cnt0_a[x]
            L_x = x - 2 * C_x
            # Find first index i where K_sorted[i] > L_x
            i = bisect.bisect_right(K_sorted, L_x)
            g1 = n - i
            S_B1 = prefix_B[n] - prefix_B[i]
            S_D1 = prefix_D[n] - prefix_D[i]
            sum_y = g1 * L_x + C_x * n + (S_B1 - S_D1) + S_D_total
            total += sum_y
        
        print(total)

if __name__ == "__main__":
    main()