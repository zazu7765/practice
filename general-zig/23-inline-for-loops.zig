const expect = @import("std").testing.expect;

test "inline for" {
    const tArr = [_]type{ i32, f32, u8, bool };
    var sum: usize = 0;
    inline for (tArr) |T| sum += @sizeOf(T);
    try expect(sum == 10);
}
