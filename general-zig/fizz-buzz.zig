const std = @import("std");

pub fn main() !void {
    // const stdout = std.io.getStdOut().writer();
    // try stdFizzBuzz();
    // try stdout.writeAll("----- NEW FIZZBUZZ -----\n");
    try switchFizzBuzz();
}

fn stdFizzBuzz() !void {
    const stdout = std.io.getStdOut().writer();
    var count: u8 = 1;

    while (count <= 100) : (count += 1) {
        if (count % 3 == 0 and count % 5 == 0) {
            try stdout.writeAll("fizbuz\n");
        } else if (count % 5 == 0) {
            try stdout.writeAll("buz\n");
        } else if (count % 3 == 0) {
            try stdout.writeAll("fiz\n");
        } else {
            try stdout.print("{}\n", .{count});
        }
    }
}

fn switchFizzBuzz() !void {
    const stdout = std.io.getStdOut().writer();
    var count: u8 = 1;

    while (count <= 100) : (count += 1) {
        const by3: u2 = @intFromBool(count % 3 == 0);
        const by5 = @intFromBool(count % 5 == 0);

        switch (by3 << 1 | by5) {
            0b10 => try stdout.writeAll("Fiz\n"),
            0b11 => try stdout.writeAll("FizBuz\n"),
            0b01 => try stdout.writeAll("Buz\n"),
            0b00 => try stdout.print("{}\n", .{count}),
        }
    }
}
