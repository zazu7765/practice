fn print_country_no_reference(country_name: String) {
    println!("{country_name}");
}

// with return value
// fn print_and_return_country(country_name: String)-> String{
//     println!("{country_name}");
//     country_name
// }

fn print_country_reference(country_name: &String){
    println!("{country_name}");
}

fn add_country_reference(country_name: &mut String){
    country_name.push_str("-Hungary");
    println!("Now this says {country_name}");
}

// fn add_country_mutable(mut country: String){
//     country.push_str("-Hungary");
//     println!("Now this says {country}");
// }

fn main() {
    let country = String::from("Canada");
    let mut country_two = String::from("Austria");
    print_country_reference(&country);
    print_country_reference(&country_two);
    add_country_reference(&mut country_two);
    // string has clone 'trait' to give copies of itself out
    print_country_no_reference(country.clone());
    print_country_no_reference(country);
}
