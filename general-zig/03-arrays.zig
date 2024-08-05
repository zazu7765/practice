const std = @import("std");

pub fn main() !void {
    const a = [5]u8{ 'h', 'e', 'l', 'l', 'o' };
    const b = [_]u8{ 'h', 'e', 'l', 'l', 'o', ' ', 'n', 'o', 't' };
    std.debug.print("{s}\n", .{a});
    std.debug.print("{s}\n", .{b});
}
