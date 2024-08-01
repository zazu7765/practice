#![allow(dead_code)]
// unit struct example
struct UnitStruct;
// unnamed / tuple struct example
#[derive(Debug)]
struct Colour(u8, u8, u8);
// named / c struct example
struct SizeAndColour {
    size: u32,
    colour: Colour,
}
// country struct example
struct Country {
    population: u32,
    capital: String,
    leader_name: String,
}
fn main() {
    size_and_colour();
    country_test();
}

fn size_and_colour() {
    let red = Colour(255, 0, 0);
    let big_red = SizeAndColour {
        size: 200,
        colour: red,
    };
    println!(
        "The big red is of size {}\nand has a colour of {:?}",
        big_red.size, big_red.colour
    );
}

fn country_test() {
    let population = 1_000_000;
    let capital = String::from("Bananaopolis");
    let leader_name = String::from("Banana Man");
    let banana_land = Country {
        population,
        capital,
        leader_name,
    };
    println!(
        "The population of banana land is {}\nCapital is {}\nLeader is {}",
        banana_land.population, banana_land.capital, banana_land.leader_name
    );
}
