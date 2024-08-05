const expect = @import("std").testing.expect;

fn fib(n: u16) u16 {
    if (n == 0 or n == 1) return n;
    return fib(n - 1) + fib(n - 2);
}

fn plusFive(x: u32) u32 {
    return x + 5;
}

test "fibonacci recursion" {
    const x = fib(10);
    try expect(x == 55);
}
test "plusFive func" {
    const x = plusFive(5);
    try expect(x == 10);
}
