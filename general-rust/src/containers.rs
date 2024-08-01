mod tests {
    #[test]
    fn assert_array() {
        let array1 = ["one", "two"];
        let myarray = ["a"; 5];
        assert_eq!(array1, ["one", "two"]);
        assert_eq!(myarray, ["a", "a", "a", "a", "a"]);
    }

    #[test]
    fn assert_array_slices() {
        let one_to_ten = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
        let three_to_five = [3, 4, 5];
        let three_to_six = [3, 4, 5, 6];
        let start_at_two = [2, 3, 4, 5, 6, 7, 8, 9, 10];
        let cut_at_five = [1, 2, 3, 4, 5];
        assert_eq!(one_to_ten, &one_to_ten[..]);
        assert_eq!(three_to_five, &one_to_ten[2..5]);
        assert_eq!(three_to_six, &one_to_ten[2..=5]);
        assert_eq!(start_at_two, &one_to_ten[1..]);
        assert_eq!(cut_at_five, &one_to_ten[..5]);
    }

    #[test]
    fn assert_string_vec() {
        let banana1 = String::from("banana");
        let potato1 = String::from("potato");
        let banana2 = String::from("banana");
        let potato2 = String::from("potato");
        let mut food_vec = Vec::new(); // inferred vector
        let mut better_food_vec: Vec<String> = Vec::new(); // typed vector
        food_vec.push(banana1);
        food_vec.push(potato1);
        better_food_vec.push(banana2);
        better_food_vec.push(potato2);
        assert_eq!(food_vec, better_food_vec);
    }

    #[test]
    fn assert_vec_slices() {
        // can also make vector with macros and other datatypes
        // usually declare vector mutable but in this case using it just to contain not to push to
        let /*mut*/ ten_to_twenty = vec![10,11,12,13,14,15,16,17,18,19,20];
        let twelve_to_fourteen = [12, 13, 14];
        let twelve_to_fifteen = [12, 13, 14, 15];
        let start_at_twelve = [12, 13, 14, 15, 16, 17, 18, 19, 20];
        let cut_at_fifteen = [10, 11, 12, 13, 14];
        assert_eq!(ten_to_twenty, &ten_to_twenty[..]);
        assert_eq!(twelve_to_fourteen, &ten_to_twenty[2..5]);
        assert_eq!(twelve_to_fifteen, &ten_to_twenty[2..=5]);
        assert_eq!(start_at_twelve, &ten_to_twenty[2..]);
        assert_eq!(cut_at_fifteen, &ten_to_twenty[..5]);
    }

    #[test]
    // Vectors resize their capacity in increments of 4 by default
    fn assert_vec_capacity() {
        let mut numvec: Vec<i32> = Vec::new();
        assert_eq!(numvec.capacity(), 0);
        numvec.push(1);
        assert_eq!(numvec.capacity(), 4);
        numvec.push(1);
        numvec.push(1);
        numvec.push(1);
        assert_eq!(numvec.capacity(), 4);
        numvec.push(1);
        assert_eq!(numvec.capacity(), 8);
    }

    #[test]
    fn assigning_with_tuples() {
        let str_vec = vec!["one", "two", "three"];
        let (one, twotwo, threethree) = (str_vec[0], str_vec[1], str_vec[2]);
        let discard_vec = vec!["never touched", "i love puppies", "potato"];
        let (_, two, three) = (discard_vec[0], discard_vec[1], discard_vec[2]);
        assert!((one, twotwo, threethree) == (str_vec[0], str_vec[1], str_vec[2]));
        assert!((two, three) == (discard_vec[1], discard_vec[2]));
    }
}
