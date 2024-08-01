#![allow(dead_code)]
fn main() {
    // infinite loop
    // loop{
    //
    // }
    // basic_loops();
    // labelled_loops();
    // while_loops();
    // for_loops();
    returning_from_loops();
}

fn basic_loops() {
    let mut count = 0;
    println!("Counter starts at {}", count);
    loop {
        count += 1;
        println!("Counter is {}", count);
        if count == 5 {
            break;
        }
    }
}

fn labelled_loops() {
    let mut counter = 0;
    let mut counter2 = 0;
    println!("Labeled loops!");
    'outside_loop: loop {
        counter += 1;
        println!("first counter is {}", counter);
        if counter > 9 {
            println!("Second loop");
            loop {
                println!("second counter is {}", counter2);
                counter2 += 1;
                if counter2 == 3 {
                    break 'outside_loop;
                }
            }
        }
    }
}

fn while_loops() {
    let mut counter = 0;
    while counter < 5 {
        counter += 1;
        println!("while loop counter is {}", counter);
    }
}

fn for_loops() {
    for number in 0..3 {
        println!("Non-Inclusive for loop number is {}", number);
    }
    for number in 0..=3 {
        println!("Inclusive for loop number is {}", number);
    }
    // discard the variable
    for _ in 0..3 {
        println!("printing the same thing 3 times");
    }
    // putting an underscore in front of variable name tells the compiler that you might be using
    // it and not to throw an error randomly
    for _number in 0..3 {
        println!("testing potential discard 3 times");
    }
}

fn returning_from_loops() {
    let mut counter = 12;
    let returned = loop {
        println!("loop value is {}", counter);
        counter -= 1;
        if counter % 10 == 0 {
            println!("break and return here");
            break counter;
        }
    };
    println!("Value returned from a loop: {}", returned);
}
