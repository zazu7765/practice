#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32,
}
impl Rectangle {
    fn area(&self) -> u32 {
        self.width * self.height
    }
}
fn main() {
    let square = Rectangle {
        width: 50,
        height: 50,
    };
    let area = square.area();
    println!("Area of the square is: {}", area);
}
