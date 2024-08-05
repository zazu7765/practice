const expect = @import("std").testing.expect;
const FileOpenError = error{ AccessDenied, OutOfMemory, FileNotFound };
const AllocErr = error{OutOfMemory};

test "coerce subset to superset" {
    const err: FileOpenError = AllocErr.OutOfMemory;
    try expect(err == FileOpenError.OutOfMemory);
}

test "error as union type" {
    const might_error: AllocErr!u16 = 10; // MIGHT error
    const wont_error = might_error catch 0; // WILL NOT error, guaranteed to be u16

    try expect(@TypeOf(wont_error) == u16);
    try expect(wont_error == 10);
}

fn funcWillFail() error{Mistake}!void {
    return error.Mistake;
}

test "return err from func" {
    funcWillFail() catch |err| {
        try expect(err == error.Mistake);
        return;
    };
}

fn triggerTry() error{Mistake}!i32 {
    try funcWillFail();
    return 12;
}

test "try from func" {
    const v = triggerTry() catch |err| {
        try expect(err == error.Mistake);
        return;
    };
    try expect(v == 12);
}

var exampleProblems: u32 = 98;

fn failAndIncrementVar() error{Mistake}!void {
    errdefer exampleProblems += 1;
    _ = try triggerTry();
}

test "errdefer" {
    failAndIncrementVar() catch |err| {
        try expect(err == error.Mistake);
        try expect(exampleProblems == 99);
        return;
    };
}

fn errCreateFile() !void {
    return error.AccessDenied;
}

test "inferred error" {
    const x: error{AccessDenied}!void = errCreateFile();

    _ = x catch {};
}
