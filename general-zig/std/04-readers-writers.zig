const std = @import("std");
const expect = std.testing.expect;
const ArrayList = std.ArrayList;
const test_allocator = std.testing.allocator;
const eql = std.mem.eql;

test "io writer" {
    var list = ArrayList(u8).init(test_allocator);
    defer list.deinit();

    const bytes_written = try list.writer().write("Hello World!");

    try expect(bytes_written == 12);
    try expect(eql(u8, list.items, "Hello World!"));
}

test "io reader" {
    const msg = "Hello World";

    const file = try std.fs.cwd().createFile("junk1.txt", .{ .read = true });
    defer {
        file.close();
        std.fs.cwd().deleteFile("junk1.txt") catch unreachable;
    }

    try file.writeAll(msg);
    try file.seekTo(0);

    const contents = try file.reader().readAllAlloc(test_allocator, msg.len);
    defer test_allocator.free(contents);

    try expect(eql(u8, contents, msg));
}
