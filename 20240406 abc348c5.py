import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n = int(input())
minimum_taste = {}  # 各色のおいしさの最小値
for _ in range(n):
    a, c = map(int, input().split())
    if c in minimum_taste:
        # すでに色cが存在している場合は最小値を更新
        minimum_taste[c] = min(minimum_taste[c], a)
    else:
        # 新しく追加される色
        minimum_taste[c] = a
ans = -1
# 存在する色をすべて走査する
for val in minimum_taste.values():
    ans = max(ans, val)
print(ans)