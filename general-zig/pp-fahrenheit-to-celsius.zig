const std = @import("std");

const Cases = enum { fahrenheit, celsius };

pub fn main() !void {
    const stdout = std.io.getStdOut().writer();
    const args = try std.process.argsAlloc(std.heap.page_allocator);
    defer std.process.argsFree(std.heap.page_allocator, args);

    if (args.len < 2) return error.ExpectedArgument;

    const format = args[1];

    const case = std.meta.stringToEnum(Cases, format) orelse return error.ExpectedFormatType;

    switch (case) {
        .fahrenheit => {
            const f = try std.fmt.parseFloat(f32, args[2]);
            const c = (f - 32) * (5.0 / 9.0);

            try stdout.print("{d:.2}\n", .{c});
        },
        .celsius => {
            const c = try std.fmt.parseFloat(f32, args[2]);
            const f = c * (5.0 / 9.0) + 32;

            try stdout.print("{d:.2}\n", .{f});
        },
    }
}
