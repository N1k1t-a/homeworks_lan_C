

int foo(int n, int k) {
    if (n <= 0)
        return k;
    else {
        int m = foo(n - 3) * foo(n - 1);
        return foo(n - 2) * m;
    }
}
