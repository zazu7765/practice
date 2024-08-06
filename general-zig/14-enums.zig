const expect = @import("std").testing.expect;
const Direction = enum { north, south, east, west };

const Value = enum(u2) { zero, one, two };
const Value2 = enum(u32) { hundred = 100, thousand = 1000, million = 1_000_000, millionandone };

const Suit = enum {
    spades,
    clubs,
    diamonds,
    hearts,

    // namespaced functions
    pub fn isClubs(self: Suit) bool {
        return self == Suit.clubs;
    }
};

const Mode = enum {
    var count: u32 = 0;
    on,
    off,
};

test "ordinal enum values" {
    try expect(@intFromEnum(Value.zero) == 0);
    try expect(@intFromEnum(Value.one) == 1);
    try expect(@intFromEnum(Value.two) == 2);
}

test "set enum ordinal values" {
    try expect(@intFromEnum(Value2.hundred) == 100);
    try expect(@intFromEnum(Value2.thousand) == 1000);
    try expect(@intFromEnum(Value2.million) == 1_000_000);
    try expect(@intFromEnum(Value2.millionandone) == 1_000_001);
}

test "enum suit method" {
    try expect(Suit.spades.isClubs() == Suit.isClubs(Suit.spades));
}

test "enum count" {
    Mode.count += 1;
    try expect(Mode.count == 1);
}
