use std::collections::HashMap;
#[allow(unused_variables)]

fn main() {
    let mut memo: HashMap<usize, i32> = HashMap::new();

    let inputs = ["12", "06", "226"];
    for input in inputs.iter() {
        println!(
            "For {input}: output is {}",
            num_decodings(0, &input.to_string(), &mut memo)
        );
    }
}

pub fn num_decodings(start: usize, s: &String, memo: &mut HashMap<usize, i32>) -> i32 {
    let n = s.len();

    if start == n {
        return 1;
    }

    if s.chars().nth(start).unwrap() == '0' {
        return 0;
    }

    if let Some(&x) = memo.get(&start) {
        return x;
    }

    let mut ways = num_decodings(start + 1, s, memo);

    if start + 2 <= n {
        let slice = &s[start..start + 2];
        if let Ok(num) = slice.parse::<i32>() {
            if num <= 26 {
                ways += num_decodings(start + 2, s, memo);
            }
        }
    }

    memo.insert(start, ways);
    ways
}
