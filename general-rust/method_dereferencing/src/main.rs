// when using references you have to dereference the variable
// however rust will automatically dereference when using a method (aka dot operator)
struct Number {
    number: u8,
}
impl Number {
    fn compare(&self, other_number: u8) {
        println!(
            "Are {} and {} the same number? {}",
            self.number,
            other_number,
            self.number == other_number
        );
    }
}
fn main() {
    let eight = Number { number: 8 };
    let reference_to_eight = &eight;
    reference_to_eight.compare(8);
}
