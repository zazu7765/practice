const std = @import("std");
const print = std.debug.print;

pub fn main() void {
    const constant: i32 = 5;
    var variable: u32 = 5000;

    print("Constant: {any}\n", .{constant});
    print("Variable: {any}\n", .{variable});

    const inf_constant = @as(i32, 5);
    variable = @as(u32, 5001);

    print("New Constant: {any}\n", .{inf_constant});
    print("Reassigned variable: {any}\n", .{variable});
}
