const print = @import("std").debug.print;

test "for" {
    const string = "hello";

    for (string, 0..) |char, idx| {
        print("char: {c}\tindex: {d}\n", .{ char, idx });
    }
}
