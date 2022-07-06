def f(n, a, b):
    if n == 1:
        print(1, a, b)
    else:
        f(n-1, a, 6 - a - b)
        print(n, a, b)
        f(n-1, 6 - a - b, b)

def main():
    n = int(input())
    f(n, 1, 3)

if __name__ == "__main__":
    main()