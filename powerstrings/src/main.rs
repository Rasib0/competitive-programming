use std::io::{self, BufRead};

fn get_input() -> Vec<String> {
    let stdin = io::stdin();
    let lines: Vec<String> = stdin.lock().lines().map(|line| line.unwrap()).collect();
    lines
}

fn main() {
    for text in get_input() {
        println!("{}", text)
    }
}
