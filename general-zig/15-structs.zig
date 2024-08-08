const expect = @import("std").testing.expect;

const Vec3 = struct { x: f32, y: f32, z: f32 };

const Vec4 = struct { x: f32 = 0, y: f32 = 0, z: f32 = 0, w: f32 = 0 };

const StructWithMethods = struct {
    x: i32,
    y: i32,
    fn swap(self: *StructWithMethods) void {
        const temp = self.x;
        self.x = self.y;
        self.y = temp;
    }
};

test "construct struct" {
    const my_vec = Vec3{
        .x = 0,
        .y = 1,
        .z = 2,
    };
    _ = my_vec;
}

test "struct with missing field" {
    const my_vec = Vec3{
        .x = 0,
        .y = 1, // if commented out, errors
        .z = 2,
    };
    _ = my_vec;
}

test "struct with defaults" {
    const my_vec = Vec4{
        .x = 25,
        .z = -50,
    };
    _ = my_vec;
}

test "automatic dereference of struct" {
    var thing = StructWithMethods{ .x = 10, .y = 20 };
    thing.swap();
    try expect(thing.x == 20);
    try expect(thing.y == 10);
}
