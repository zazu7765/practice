const std = @import("std");
const eql = std.mem.eql;
const test_alloc = std.testing.allocator;
const expect = std.testing.expect;

test "arraylist" {
    var list = std.ArrayList(u8).init(test_alloc);
    defer list.deinit();

    try list.append('H');
    try list.append('e');
    try list.append('l');
    try list.append('l');
    try list.append('o');

    try list.appendSlice(" World!");

    try expect(eql(u8, list.items, "Hello World!"));
}
