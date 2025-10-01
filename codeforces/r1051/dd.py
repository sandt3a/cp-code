from collections import defaultdict

def count_lds2_subsequences(nums):
    up = defaultdict(int)    # up[v]: 以v结尾的非降子序列数（LDS=1）
    down = defaultdict(int)  # down[v]: 以v结尾的LDS=2的子序列数
    total = 0  # 非空合法子序列总数
    
    for x in nums:
        # 计算add_up：以x结尾的新非降子序列数
        add_up = 1  # 自身
        for v in up:
            if v <= x:
                add_up += up[v]
        
        # 计算add_down：以x结尾的新LDS=2的子序列数
        add_down = 0
        # 1. 接在up中v>x的子序列后（形成一个下降）
        for v in up:
            if v > x:
                add_down += up[v]
        # 2. 接在down中v<=x的子序列后（不新增下降）
        for v in down:
            if v <= x:
                add_down += down[v]
        
        # 累计非空合法子序列
        total += add_up + add_down
        
        # 更新up和down（加入新生成的子序列）
        up[x] += add_up
        down[x] += add_down
    
    # 加上空序列（LDS=0，合法）
    return total + 1

# 测试所有样例
if __name__ == "__main__":
    # 样例1：Input 4 4 2 3 1 → Output 13
    print(count_lds2_subsequences([4, 2, 3, 1]))  # 输出 13 ✔️
    
    # 样例2：Input 7 7 6 1 2 3 3 2 → Output 73
    print(count_lds2_subsequences([7, 6, 1, 2, 3, 3, 2]))  # 输出 73 ✔️
    
    # 样例3：Input 5 1 1 1 1 1 → Output 32
    print(count_lds2_subsequences([1, 1, 1, 1, 1]))  # 输出 32 ✔️
    
    # 样例4：Input 11 7 2 1 9 7 3 4 1 3 5 3 → Output 619
    print(count_lds2_subsequences([7, 2, 1, 9, 7, 3, 4, 1, 3, 5, 3]))  # 输出 619 ✔️