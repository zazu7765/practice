// malloc in zig focuses on different type of "allocators" unlike C which only is done through malloc

const std = @import("std");
const expect = std.testing.expect;

test "std heap allocator" {
    // Takes a page of memory, not just the amount you need
    const allocator = std.heap.page_allocator;

    const mem = try allocator.alloc(u8, 100);
    defer allocator.free(mem);

    try expect(mem.len == 100);
    try expect(@TypeOf(mem) == []u8);
}

test "fixed buffer allocator" {
    // allocates into a fixed buffer, and does not allocate heap
    var buf: [1000]u8 = undefined;
    var fba = std.heap.FixedBufferAllocator.init(&buf);
    const allocator = fba.allocator();
    const mem = try allocator.alloc(u8, 100);
    defer allocator.free(mem);

    try expect(mem.len == 100);
    try expect(@TypeOf(mem) == []u8);
}

test "heap arena allocator" {
    // takes in child allocator, allows multiple alloc and only one free, with .deinit() (free does nothing)
    var arena = std.heap.ArenaAllocator.init(std.heap.page_allocator);
    defer arena.deinit();
    const allocator = arena.allocator();

    _ = try allocator.alloc(u8, 1);
    _ = try allocator.alloc(u8, 10);
    _ = try allocator.alloc(u8, 100);
}

test "single instance create/destroy" {
    const byte = try std.heap.page_allocator.create(u8);
    defer std.heap.page_allocator.destroy(byte);

    byte.* = 128;

    try expect(byte.* == 128);
    try expect(@TypeOf(byte) == *u8);
}

test "general purpose allocator" {
    var gpa = std.heap.GeneralPurposeAllocator(.{}){};
    const allocator = gpa.allocator();
    defer {
        const deinit_status = gpa.deinit();
        if (deinit_status == .leak) expect(false) catch @panic("CANNOT ALLOC: TEST FAIL");
    }

    const bytes = try allocator.alloc(u8, 100);
    defer allocator.free(bytes);
}
