def create_t(array: list, t: list, i: int, t_l: int, t_r: int):
    if t_l == t_r:
        t[i] = array[t_l]
        return
    temp = (t_l + t_r) // 2
    create_t(array, t, 2 * i, t_l, temp)
    create_t(array, t, 2 * i + 1, temp+1, t_r)
    t[i] = t[2 * i] + t[2 * i + 1]
    return

def sum_l_r(t: list, i: int, t_l: int, t_r: int, l: int, r: int):
    if l > r:
        return 0
    if l == t_l and r == t_r:
        return t[i]
    mid = (t_r + t_l) // 2
    return (sum_l_r(t, 2 * i, t_l, mid, l, min(r, mid)) + sum_l_r(t, 2 * i + 1, mid + 1, t_r, max(l, mid+1), r))

if __name__ == "__main__":
    n = int(input())
    array = []
    for i in range(n):
        array.append(int(input()))
    t = [0] * (4 * n)
    create_t(array, t, 1, 0, n - 1)
    h = int(input())
    for _ in range(h):
        l = int(input())
        r = int(input())
        print(sum_l_r(t, 1, 0, n - 1, l-1, r-1))
 
