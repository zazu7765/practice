const expect = @import("std").testing.expect;

const Result = union {
    int: i64,
    float: f64,
    bool: bool,
};

const Tag = enum { a, b, c };

// Tagged union use enums to detect active field: either a/b/c
const Tagged = union(enum) { a: u8, b: f32, c: bool, none }; // Void fields don't need to specify type, it is inferred.
// const Tagged = union(Tag) { a: u8, b: f32, c: bool }; // same code

test "union values" {
    const res = Result{ .int = 1234 };
    // res.float = 1234.0; // Illegal change, only one field of a union can be active at a time.
    _ = res;
}

test "switch on tagged union" {
    var val = Tagged{ .b = 1.5 };
    switch (val) {
        .a => |*byte| byte.* += 1,
        .b => |*float| float.* *= 2,
        .c => |*b| b.* = !b.*,
        .none => {},
    }
    try expect(val.b == 3);
}
