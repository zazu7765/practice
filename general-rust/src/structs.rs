pub struct Unit;
pub struct Colour(pub u8, pub u8, pub u8);
pub struct SizeAndColour {
    pub size: u32,
    pub colour: Colour,
}

pub struct Country {
    pub population: u32,
    pub capital: String,
    pub leader_name: String,
}

mod tests {

    #[test]
    fn tuple_colour_struct() {
        let color = crate::structs::Colour(255, 255, 255);
        assert_eq!((color.0, color.1, color.2), (255, 255, 255));
    }
    #[test]
    fn size_colour_struct() {
        let red = crate::structs::Colour(255, 0, 0);
        let big_red = crate::structs::SizeAndColour {
            size: 200,
            colour: red,
        };
        assert_eq!(big_red.size, 200);
        assert_eq!(
            (big_red.colour.0, big_red.colour.1, big_red.colour.2),
            (255, 0, 0)
        );
    }
    #[test]
    fn country_test() {
        let population = 1_000_000;
        let capital = String::from("Bananopolis");
        let leader_name = String::from("Banana Jim");
        let banana_land = crate::structs::Country {
            population,
            capital,
            leader_name,
        };
        assert_eq!(banana_land.population, 1_000_000);
        assert_eq!(banana_land.capital, "Bananopolis");
        assert_eq!(banana_land.leader_name, "Banana Jim");
    }
}
