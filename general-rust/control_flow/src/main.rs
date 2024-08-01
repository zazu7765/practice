#![allow(dead_code)]
fn main() {
    // if_else_one();
    // if_else_two();
    // match_case();
    // match_as_var();
    // string_tuple_match();
    // match_guard();
    // rgb_example();
    // advanced_match();
    match_with_at_char(13);
}

fn if_else_one() {
    // regular if else
    let my_num = 5;
    if my_num == 7 {
        println!("number is 7");
    } else if my_num == 6 {
        println!("number is 6");
    } else {
        println!("there's definitely a number somewhere");
    }
}

fn if_else_two() {
    // extension of if else with logical operators
    let my_num = 5;
    if my_num % 2 == 0 && my_num > 0 {
        println!("positive odd number");
    } else if my_num == 6 {
        println!("number is 6");
    } else {
        println!("there's definitely a number somewhere");
    }
}

fn match_case() {
    // standard example of a match case
    let my_num: u32 = 6;
    match my_num {
        0 => println!("number is 0"),
        1 => println!("number is 1"),
        2 => println!("number is 2"),
        _ => println!("there's definitely a number somewhere"),
    }
}

fn match_as_var() {
    // storing result of a match case in a variable, in this case a number 10 higher than the input
    // (or 69).
    let my_num = 5;
    let match_result = match my_num {
        0 => 10,
        1 => 11,
        2 => 12,
        3 => 13,
        4 => 14,
        5 => 15,
        _ => 69,
    };
    println!("{}", match_result);
}

fn string_tuple_match() {
    // regular tuple matching
    let sky = "clear";
    let temperature = "cold";
    match (sky, temperature) {
        ("cloudy", "cold") => println!("you should grab a jacket"),
        ("cloudy", "warm") => println!("dont need a jacket!"),
        ("clear", "cold") => println!("bring a jacket and hope for sun"),
        ("clear", "warm") => println!("dont need a jacket!"),
        (_, _) => println!("idk there's definitely some weather outside"),
    };
}

fn match_guard() {
    /* by putting an if statement within our initial match statement we do something called "match
     * guarding" where we still validate input within our match case.
     */
    let bananas = 9;
    let hungry = true;
    match (bananas, hungry) {
        (bananas, hungry) if hungry == false => println!("Not hungry with {} bananas :)", bananas),
        (bananas, hungry) if bananas == 0 && hungry == true => println!("Hungry but no bananas :("),
        _ => println!("Hungry? {}, How many bananas? {}", hungry, bananas),
    };
}

fn rgb_example() {
    fn rgb_checker(rgb: (i32, i32, i32)) {
        /* by storing input as a tuple you can match the entire tuple based on different elements
         * already contained in it, reducing the need to keep rewriting the same variable names 10
         * times over.
         */
        match rgb {
            (r, g, b) if r < 10 && g < 10 && b < 10 => println!("There's barely any color!"),
            (r, _, _) if r < 10 => println!("There's barely any red!"),
            (_, g, _) if g < 10 => println!("There's barely any green!"),
            (_, _, b) if b < 10 => println!("There's barely any blue!"),
            (r, g, b) if r == g && r == b => println!("There's an equal amount of each!"),
            _ => println!("theres a good amount of color"),
        }
    }
    rgb_checker((10, 1, 1));
    rgb_checker((200, 50, 0));
    rgb_checker((50, 50, 50));
}

fn advanced_match() {
    // regular logical operators and slicing work on match cases too!
    let my_num = 24;
    match my_num {
        1 => println!("one"),
        2 | 3 | 5 | 7 | 11 | 13 => println!("one of first 6 primes"),
        13..=19 => println!("x-teen number"),
        _ => println!("not a cool number"),
    }
}

fn match_with_at_char(input: i32) {
    /* matching also lets you assign a custom variable name for whatever purposes you want to use
     * it for, in this case: printing a 'number'.
     */
    match input {
        number @ 13 => println!(
            "{} is an unlucky number in the US & Canada, but lucky in Italy.",
            number
        ),
        number @ 4 => println!("{} is an unlucky number in China", number),
        _ => println!("Number isn't particularly lucky or unlucky!"),
    }
}
