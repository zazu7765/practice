const expect = @import("std").testing.expect;

test "optional type" {
    var found: ?usize = null;
    const data = [_]i32{ 1, 2, 3, 4, 5 };
    for (data, 0..) |v, i| {
        if (v == 10) found = i;
    }
    try expect(found == null);
}

test "optional type orelse" {
    const a: ?f32 = null;
    const fallback: f32 = 0;
    const b = a orelse fallback;
    try expect(b == 0);
    try expect(@TypeOf(b) == f32);
}

// .? is syntax for orelse unreachable, should never be null
test ".? / orelse unreachable" {
    const a: ?f32 = 5;
    // The following two statements are identical
    const b = a orelse unreachable;
    const c = a.?;

    try expect(b == c);
    try expect(@TypeOf(c) == f32);
}

// Optional payload capture:
test "if (optional payload capture)" {
    // usual if check c-style
    const a: ?i32 = 5;
    if (a != null) {
        const value = a.?;
        _ = value;
    }

    // zig-specific var capture
    var b: ?i32 = 5;
    if (b) |*value| {
        value.* += 1;
    }

    try expect(b.? == 6);
}

var nums_left: u32 = 4;
fn testNullSequence() ?u32 {
    if (nums_left == 0) return null;
    nums_left -= 1;
    return nums_left;
}

test "while (null capture)" {
    var sum: u32 = 0;
    // Null pointers must be unwrapped to non-optional before dereferencing
    // i.e no accidental null pointer dereferences
    while (testNullSequence()) |val| {
        sum += val;
    }
    try expect(sum == 6);
}
