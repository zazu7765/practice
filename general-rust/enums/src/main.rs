#![allow(dead_code)]
/* enums are very similar to structs visually but function differently
 * structs are for when you want something AND another thing (MANY THINGS TOGETHER)
 * enums are for when you want something OR another thing (MANY CHOICES TOGETHER)
 */
enum ThingOneOrThingTwo {
    ThingOne,
    ThingTwo,
}

enum PickOnePickTwo {
    PickOne(String),
    PickTwo(String),
}

enum Mood {
    Happy,
    Sleepy,
    Sad,
    Angry,
}

enum NumbersAreValid {
    Zero,
    One,
    Two,
    Three,
}

fn main() {
    let thing = 2;
    let thing_state = return_one_or_two(thing);
    check_thing_state(&thing_state);
    println!("Using Strings!");
    let pick_thing = 1;
    let pick_state = return_one_or_two_string(pick_thing);
    check_thing_state_string(&pick_state);
    println!("Mood Imports!");
    let mood = Mood::Sleepy;
    let mood_level = value_mood(&mood);
    println!("Mood level: {}", mood_level);
    println!("Enums are numbers too!");
    enums_are_numbers_too();
}

fn return_one_or_two(thing: i8) -> ThingOneOrThingTwo {
    match thing {
        1 => ThingOneOrThingTwo::ThingOne,
        _ => ThingOneOrThingTwo::ThingTwo,
    }
}

fn return_one_or_two_string(thing: i8) -> PickOnePickTwo {
    match thing {
        1 => PickOnePickTwo::PickOne(String::from("ThingOneString")),
        _ => PickOnePickTwo::PickTwo(String::from("ThingTwoString")),
    }
}

fn check_thing_state(state: &ThingOneOrThingTwo) {
    match state {
        ThingOneOrThingTwo::ThingOne => println!("Thing One!"),
        ThingOneOrThingTwo::ThingTwo => println!("Thing Two!"),
    }
}

fn check_thing_state_string(state: &PickOnePickTwo) {
    match state {
        PickOnePickTwo::PickOne(set_string) => println!("{}", set_string),
        PickOnePickTwo::PickTwo(set_string_two) => println!("{}", set_string_two),
    }
}

fn value_mood(mood: &Mood) -> i32 {
    // use with star imports all things in namespace
    use Mood::*;
    match mood {
        Happy => 100,
        Sleepy => 50,
        Sad => 0,
        Angry => -100,
    }
}

fn enums_are_numbers_too() {
    use NumbersAreValid::*;
    let numbers = vec![Zero, One, Two, Three];
    for number in numbers {
        println!("{}", number as u32);
    }
}
