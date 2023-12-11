use std::io::{self, BufRead};

fn get_input() -> Vec<String> {
    let stdin = io::stdin();
    let lines: Vec<String> = stdin.lines().map(|line| line.unwrap()).collect();
    lines
}

fn main() {
    for text in get_input() {
        println!("{}", text)
    }
}
