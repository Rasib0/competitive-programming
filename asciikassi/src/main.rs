use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Error 1");
    let num: usize = input.trim().parse().expect("Error 2");

    // Print the top border
    println!("+{}+", "-".repeat(num));

    // Print the sides with spaces
    for _ in 0..num {
        println!("|{}|", " ".repeat(num));
    }

    // Print the bottom border
    println!("+{}+", "-".repeat(num));
}
