struct Human {
    name: String,
    height: u8,
    happy: bool,
}
struct City {
    name: String,
    name2: String,
    population: u32,
    founded: u32,
}
impl City {
    fn new(name: String, name2: String, population: u32, founded: u32) -> Self {
        Self {
            name,
            name2,
            population,
            founded,
        }
    }
}
fn main() {
    destructuring_one();
    constructor_destructuring();
}
fn destructuring_one() {
    let mark = Human {
        name: String::from("Mark"),
        height: 63,
        happy: false,
    };
    let Human {
        name: m_name,
        height: m_height,
        happy: m_happy,
    } = mark;
    println!(
        "the human's name is: {}, he is {} cm tall, and is he happy? {}",
        m_name, m_height, m_happy
    )
}
fn constructor_destructuring() {
    fn process(city: &City) {
        let City {
            name,
            name2,
            population,
            founded,
        } = city;
        let namepopvec = vec![name, name2];
        println!("The city name and motto is {:?}, respectively", namepopvec);
    }
    let best_city_ever = City::new(
        "markland".to_string(),
        "land of the mark".to_string(),
        169_000_000,
        2023,
    );
    process(&best_city_ever);
}
