const expect = @import("std").testing.expect;
const memeql = @import("std").mem.eql;

// comptime triggers compile-time code execution
fn fibonacci(n: u16) u16 {
    if (n == 0 or n == 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

test "comptime fibonacci" {
    const x = comptime fibonacci(10);
    const y = comptime blk: {
        break :blk fibonacci(10);
    };
    try expect(x == 55);
    try expect(y == 55);
}

test "compile time integers" {
    const a = 12; // comptime int
    const b = a + 10; // also comptime int

    const c: u4 = a; // coerced to uint4
    const d: f32 = b; // coerced to float32

    try expect(c == 12);
    try expect(d == 22);
}

test "branching types" {
    const a = 5;
    const b: if (a < 10) f32 else i32 = 5;
    try expect(b == 5);
    try expect(@TypeOf(b) == f32);
}

// Comptime applies to function parameters as well
fn Matrix(comptime T: type, comptime width: comptime_int, comptime height: comptime_int) type {
    return [height][width]T;
}

test "returning type comptime" {
    try expect(Matrix(f32, 4, 4) == [4][4]f32);
}

fn addSmallIntegers(comptime T: type, a: T, b: T) T {
    return switch (@typeInfo(T)) {
        .ComptimeInt => a + b,
        .Int => |info| if (info.bits <= 16)
            a + b
        else
            @compileError("int types too large"),
        else => @compileError("only ints are accepted"),
    };
}

test "switch reflection" {
    const x = addSmallIntegers(u16, 20, 30);
    try expect(@TypeOf(x) == u16);
    try expect(x == 50);
}

fn CreateBiggerIntType(comptime T: type) type {
    return @Type(.{
        .Int = .{
            .bits = @typeInfo(T).Int.bits + 1,
            .signedness = @typeInfo(T).Int.signedness,
        },
    });
}

test "@Type operator" {
    try expect(CreateBiggerIntType(u8) == u9);
    try expect(CreateBiggerIntType(i31) == i32);
}

// Generic Vector Example
fn Vec(
    comptime count: comptime_int,
    comptime T: type,
) type {
    return struct {
        data: [count]T,
        const Self = @This();

        fn abs(self: Self) Self {
            var temp = Self{ .data = undefined };
            for (self.data, 0..) |e, i| {
                temp.data[i] = if (e < 0) -e else e;
            }
            return temp;
        }

        fn init(data: [count]T) Self {
            return Self{ .data = data };
        }
    };
}

test "generic vector impl" {
    const x = Vec(3, f32).init([_]f32{ 10, -10, 5 });
    const y = x.abs();

    try expect(memeql(f32, &y.data, &[_]f32{ 10, 10, 5 }));
}

fn incOne(x: anytype) @TypeOf(x) {
    return x + 1;
}

test "inferred param" {
    try expect(incOne(@as(u32, 1)) == 2);
}

test "arr concatentation" {
    const x: [4]u8 = undefined;
    const y = x[0..];

    const a: [6]u8 = undefined;
    const b = a[0..];

    const new = y ++ b;

    try expect(new.len == 10);
}

test "array repetition" {
    const p = [_]u8{ 0xCC, 0xAA };
    const mem = p ** 3;
    try expect(memeql(u8, &mem, &[_]u8{ 0xCC, 0xAA, 0xCC, 0xAA, 0xCC, 0xAA }));
}
