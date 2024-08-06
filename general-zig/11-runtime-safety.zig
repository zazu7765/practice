const expect = @import("std").testing.expect;
test "out-of-bounds" {
    const a = [3]u8{ 1, 2, 3 };
    const idx: u8 = 2;
    const b = a[idx]; // index 5 outside of array length 3, so temp set to 2
    _ = b;
}

fn asciiToUpperCase(x: u8) u8 {
    return switch (x) {
        'a'...'z' => x + 'A' - 'a',
        'A'...'Z' => x,
        else => unreachable,
    };
}

test "unreachable" {
    try expect(asciiToUpperCase('a') == 'A');
    try expect(asciiToUpperCase('A') == 'A');
}
