const expect = @import("std").testing.expect;
const eql = @import("std").mem.eql;

test "optional-if" {
    const maybe: ?usize = 10;
    if (maybe) |n| {
        try expect(@TypeOf(n) == usize);
        try expect(n == 10);
    } else unreachable;
}

test "error union if" {
    const entOrNum: error{UnknownEntity}!u32 = 5;
    if (entOrNum) |entity| {
        try expect(@TypeOf(entity) == u32);
        try expect(entity == 5);
    } else |err| {
        _ = err catch {};
        unreachable;
    }
}

test "while optional" {
    var i: ?u32 = 10;
    while (i) |num| : (i.? -= 1) {
        try expect(@TypeOf(num) == u32);
        if (num == 1) {
            i = null;
            break;
        }
    }

    try expect(i == null);
}

test "capture pointer values and mutate" {
    var data = [_]u8{ 1, 2, 3 };
    for (&data) |*b| b.* += 1;
    try expect(eql(u8, &data, &[_]u8{ 2, 3, 4 }));
}
