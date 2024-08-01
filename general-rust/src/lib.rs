pub mod structs;
pub mod containers;
pub mod control_flow;
pub fn hello_world() -> String {
    "Hello, world!".to_string()
}
#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn print_hello_world() {
        let result = hello_world();
        println!("{}", result);
        assert_eq!(result, "Hello, world!");
    }
}
