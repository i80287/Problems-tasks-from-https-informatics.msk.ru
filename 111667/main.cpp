l, d, t, v1, v2 = map(int, input().split())
if d / v1 < t:
    otw = d / v1 + l / v1
else:
    otw = t + (d - v1 * t) / (v2 + v1) + l / v1
print(otw)