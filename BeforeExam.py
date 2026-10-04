d, total = map(int, input().split())
lo, hi = [], []
for _ in range(d):
    a, b = map(int, input().split())
    lo.append(a)
    hi.append(b)

if total < sum(lo) or total > sum(hi):
    print("NO")
else:
    rem = total - sum(lo)
    res = []
    for i in range(d):
        add = min(hi[i] - lo[i], rem)
        res.append(lo[i] + add)
        rem -= add
    print("YES")
    print(*res)