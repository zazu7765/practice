const std = @import("std");
const eql = std.mem.eql;
const expect = std.testing.expect;
const test_allocator = std.testing.allocator;

test "fmt" {
    const string = try std.fmt.allocPrint(test_allocator, "{d} + {d} = {d}", .{ 9, 10, 19 });
    defer test_allocator.free(string);

    try expect(eql(u8, string, "9 + 10 = 19"));
}

test "fmt print into arraylist" {
    var list = std.ArrayList(u8).init(test_allocator);
    defer list.deinit();

    try list.writer().print("{} + {} = {}", .{ 9, 10, 19 });

    try expect(eql(u8, list.items, "9 + 10 = 19"));
}

test "fmt print arraylists" {
    const string = try std.fmt.allocPrint(test_allocator, "{any} + {any} = {any}", .{
        @as([]const u8, &[_]u8{ 1, 4 }),
        @as([]const u8, &[_]u8{ 2, 5 }),
        @as([]const u8, &[_]u8{ 3, 9 }),
    });
    defer test_allocator.free(string);

    try expect(eql(u8, string, "{ 1, 4 } + { 2, 5 } = { 3, 9 }"));
}

const Person = struct {
    name: []const u8,
    birth_year: i32,
    death_year: ?i32,
    pub fn format(self: Person, comptime fmt: []const u8, options: std.fmt.FormatOptions, writer: anytype) !void {
        _ = fmt;
        _ = options;

        try writer.print("{s} ({}-", .{ self.name, self.birth_year });

        if (self.death_year) |year| {
            try writer.print("{}", .{year});
        }

        try writer.print(")", .{});
    }
};

test "fmt Person struct" {
    const joe = Person{ .name = "Sleepy Joe", .birth_year = 1942, .death_year = null };

    const joe_string = try std.fmt.allocPrint(test_allocator, "{s}", .{joe});

    defer test_allocator.free(joe_string);

    const claude = Person{
        .name = "Claude Shannon",
        .birth_year = 1916,
        .death_year = 2001,
    };
    const claude_string = try std.fmt.allocPrint(
        test_allocator,
        "{s}",
        .{claude},
    );

    defer test_allocator.free(claude_string);

    try expect(eql(u8, joe_string, "Sleepy Joe (1942-)"));
    try expect(eql(u8, claude_string, "Claude Shannon (1916-2001)"));
}
