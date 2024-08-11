const std = @import("std");
const expect = std.testing.expect;
const eql = std.mem.eql;

test "file functions" {
    const file = try std.fs.cwd().createFile("testF.txt", .{ .read = true });
    defer {
        file.close();
        std.fs.cwd().deleteFile("testF.txt") catch unreachable;
    }

    const bytes_w = try file.writeAll("Hello File!\n");

    _ = bytes_w;

    var buf: [100]u8 = undefined;
    try file.seekTo(0);
    const bytes_read = try file.readAll(&buf);

    try expect(eql(u8, buf[0..bytes_read], "Hello File!\n"));
}

test "file status" {
    const file = try std.fs.cwd().createFile("testF2.txt", .{ .read = true });
    defer {
        file.close();
        std.fs.cwd().deleteFile("testF2.txt") catch unreachable;
    }

    const stat = try file.stat();

    try expect(stat.size == 0);
    try expect(stat.kind == .file);
    try expect(stat.ctime <= std.time.nanoTimestamp());
    try expect(stat.mtime <= std.time.nanoTimestamp());
    try expect(stat.atime <= std.time.nanoTimestamp());
}

test "mkdir" {
    try std.fs.cwd().makeDir("test-tmp");
    var iter_dir = try std.fs.cwd().openDir(
        "test-tmp",
        .{ .iterate = true },
    );
    defer {
        iter_dir.close();
        std.fs.cwd().deleteTree("test-tmp") catch unreachable;
    }

    _ = try iter_dir.createFile("x", .{});
    _ = try iter_dir.createFile("y", .{});
    _ = try iter_dir.createFile("z", .{});

    var file_count: usize = 0;
    var iter = iter_dir.iterate();
    while (try iter.next()) |entry| {
        if (entry.kind == .file) file_count += 1;
    }

    try expect(file_count == 3);
}
