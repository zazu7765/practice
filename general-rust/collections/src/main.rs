fn main() {
    basic_array_print();
    arr_slicing();
    string_vector();
    vector_slicing();
    vector_capacity();
    tuple_as_args();
}

fn basic_array_print(){
    println!("\nArray Printing");
    let array1 = ["one", "two"];
    let myarray = ["a";50];
    println!("Test array: {:?}",array1);
    println!("Char repeating array: {:?}", myarray);
}

fn arr_slicing(){
    println!("\nArray Slicing");
    // Indexes start at 0 (thank god)
    // Index ranges are exclusive by default
    let one_to_ten = [1,2,3,4,5,6,7,8,9,10];
    let three_to_five = &one_to_ten[2..5];
    let three_to_six = &one_to_ten[2..=5];
    let start_at_two = &one_to_ten[1..];
    let cut_at_five = &one_to_ten[..5];
    let everything_back = &one_to_ten[..];
    println!("Whole array: {:?}\n3 to 5: {:?}\nStarting from 2: {:?}\nCut off at 5: {:?}\nBack to everything: {:?}", one_to_ten,three_to_five,start_at_two,cut_at_five,everything_back);
    println!("Inclusive three to five: {:?}", three_to_six);
}

fn string_vector(){
    println!("\nString Vectors:");
    let name1 = String::from("Banana");
    let name2 = String::from("Potato");
    let banana = String::from("banana");
    let potato = String::from("potato");
    // vec type not declared in initialization
    let mut food_vec = Vec::new();
    let mut better_food_vec: Vec<String> = Vec::new();
    food_vec.push(name1);
    food_vec.push(name2);
    better_food_vec.push(banana);
    better_food_vec.push(potato);
    println!("String vector no type @ init: {:?}", food_vec);
    println!("String vector typed @ init: {:?}", better_food_vec);
}

fn vector_slicing(){
    println!("\nVector Slicing");
    // can also make vector with macros and other datatypes
    // usually declare vector mutable but in this case using it just to contain not to push to
    let /*mut*/ ten_to_twenty = vec![10,11,12,13,14,15,16,17,18,19,20];
    let thirteen_to_fifteen = &ten_to_twenty[2..5];
    let thirteen_to_sixteen = &ten_to_twenty[2..=5];
    let start_at_twelve = &ten_to_twenty[1..];
    let cut_at_fifteen = &ten_to_twenty[..5];
    let everything_back = &ten_to_twenty[..];
    println!("Whole vector: {:?}\n13 to 15: {:?}\nStarting from twelve: {:?}\nCut off at 15: {:?}\nBack to everything: {:?}",ten_to_twenty, thirteen_to_fifteen, start_at_twelve, cut_at_fifteen, everything_back);
    println!("Inclusive thirteen to fifteen (2nd to 5th index): {:?}",thirteen_to_sixteen);
}

fn vector_capacity(){
    println!("\nDynamic Vector Resizing");
    /*
    Vectors start at a capacity of 0 elements
    Once one element is pushed, the capacity is set to 4 to accomodate 3 more elements before resizing.
    After you hit 4 elements the vector resizes again (this time to 8) to have enough capacity for more elements to be stored.
    */
    let mut num_vec:Vec<i32> = Vec::new();
    println!("Initial Capacity: {}",num_vec.capacity());
    num_vec.push(1);
    println!("After one push: {}",num_vec.capacity());
    num_vec.push(1);
    num_vec.push(1);
    num_vec.push(1);
    println!("After three more pushes (4 total): {}",num_vec.capacity());
    num_vec.push(1);
    println!("After one more push: {}",num_vec.capacity());
}

// tuples are passed and returned in arg functions in rust
fn tuple_as_args(){
    println!("\nTuples As Arguments:");
    let str_vec = vec!["one","two","three"];
    let(one, two, three) = (str_vec[0],str_vec[1],str_vec[2]);
    println!("First element is {:?}\nSecond element is {:?}\nThird element is {:?}",one,two,three);
    let discard_vec = vec!["never touched","i love puppies","potato"];
    let(_,two, three) = (discard_vec[0], discard_vec[1], discard_vec[2]);
    println!("First element taken is {:?}\nSecond element taken is {:?}",two, three);
}