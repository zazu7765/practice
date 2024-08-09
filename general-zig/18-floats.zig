const expect = @import("std").testing.expect;

// Zig floats are IEEE-compliant which uses their format UNLESS float mode is set to optimized which is the equivalent of -ffast-math on gcc

// floats have special literal syntax too
const floating_point: f64 = 123.0E+77;
const another_float: f64 = 123.0;
const yet_another: f64 = 123.0e+77;

const hex_floating_point: f64 = 0x103.70p-5;
const another_hex_float: f64 = 0x103.70;
const yet_another_hex_float: f64 = 0x103.70P-5;

// and can also use underscores that get removed when compiling;
const lightspeed: f64 = 299_792_458.000_000;
const nanosecond: f64 = 0.000_000_001;
const more_hex: f64 = 0x1234_5678.9ABC_CDEFp-10;

// same test as in 17-integers.zig
test "float widen" {
    const a: f16 = 0;
    const b: f32 = a;
    const c: f64 = b;
    try expect(a == b and b == c);
}

test "int to float" {
    const a: i32 = 0;
    const b = @as(f32, @floatFromInt(a));
    const c = @as(i32, @intFromFloat(b));
    try expect(a == c);
}
