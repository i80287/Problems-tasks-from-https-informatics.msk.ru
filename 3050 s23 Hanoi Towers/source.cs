using System;

static void f(int n, int a, int b)
{
    if (n == 1)
    {
        Console.WriteLine($"{1} {a} {b}");
    }
    else
    {
        f(n - 1, a, 6 - a - b);
        Console.WriteLine($"{n} {a} {b}");
        f(n - 1, 6 - a - b, b);
    }
}

var n = int.Parse(Console.ReadLine());
f(n, 1, 3);