const expect = @import("std").testing.expect;

fn total(vals: []const u8) usize {
    var sum: usize = 0;
    for (vals) |v|
        sum += v;
    return sum;
}

test "partial slice" {
    const arr = [_]u8{ 1, 2, 3, 4, 5 };
    const slice = arr[0..3];
    try expect(total(slice) == 6);
    try expect(@TypeOf(slice) == *const [3]u8);
}

test "full slice" {
    const arr = [_]u8{ 1, 2, 3, 4, 5 };
    const slice = arr[0..];
    try expect(total(slice) == 15);
}
