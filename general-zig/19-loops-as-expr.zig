const expect = @import("std").testing.expect;

fn rangeContainsNumber(begin: usize, end: usize, number: usize) bool {
    var i = begin;
    return while (i < end) : (i += 1) {
        if (i == number) break true;
    } else false;
}

test "rangeContainsNumber using while loop expresssion" {
    try expect(rangeContainsNumber(0, 10, 3));
}
