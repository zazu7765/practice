use std::cmp::Ordering;
use std::io;
use rand::Rng;

fn main() {
    let rand_num = rand::thread_rng().gen_range(1..=100);
    println!("Try to guess the random number!");
    loop{
        println!("Guess a number:");
        let mut guess = String::new();
        io::stdin()
            .read_line(&mut guess)
            .expect("Couldn't read line!");
        let guess:u32 = match guess.trim().parse(){
            Ok(num)=>num,
            Err(_)=> continue,
        };
        println!("Your guess: {guess}");
        match guess.cmp(&rand_num){
            Ordering::Less => println!("Your guess is too small!"),
            Ordering::Greater => println!("Your guess is too big!"),
            Ordering::Equal => {
                println!("Your guess is correct!");
                break;
            },
        }
    }
}
