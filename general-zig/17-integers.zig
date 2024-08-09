const expect = @import("std").testing.expect;

const decimal: i32 = 1234;
const hex: u8 = 0xff;
const caps_hex: u8 = 0xFF;
const octal: u16 = 0o755;
const binary: u8 = 0b11110000;

const bin_mask: u64 = 0b1_1111_1111;
const perms: u64 = 0o7_5_5;
const big_addr: u64 = 0xFF80_0000_0000_0000;

test "integer widening" {
    const a: u8 = 250;
    const b: u16 = a;
    const c: u32 = b;
    try expect(a == b and b == c);
}

test "intCast macro" {
    const x: u64 = 200;
    const y: u8 = @as(u8, @intCast(x));
    try expect(@TypeOf(y) == u8);
}

test "integer overflow defining" {
    var a: u8 = 255;
    // save overflow operator, this will rollover to 0
    a +%= 1;
    try expect(a == 0);
}
