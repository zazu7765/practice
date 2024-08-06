const expect = @import("std").testing.expect;

fn increment(num: *u8) void {
    num.* += 1;
}

test "increment pointer" {
    var x: u8 = 1;
    increment(&x);
    try expect(x == 2);
}

test "const pointers" {
    const x: u8 = 1;
    const y = &x;
    _ = y;
    // y.* += 1; // cannot assign to constant
}

test "usize values" {
    try expect(@sizeOf(usize) == @sizeOf(*u8));
    try expect(@sizeOf(isize) == @sizeOf(*u8));
}
