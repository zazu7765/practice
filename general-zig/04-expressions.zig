const expect = @import("std").testing.expect;

test "if statement" {
    const inc = true;
    var name: u16 = 0;
    if (inc) {
        name += 1;
    } else {
        name += 2;
    }
    try expect(name == 1);
}

test "if statement as expression" {
    const inc = true;
    var name: u16 = 0;
    name += if (inc) 1 else 2;
    try expect(name == 1);
}
