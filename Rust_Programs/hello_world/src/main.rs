fn main() {
    println!("Hello, world!");
    let x = 25;
    println!{"the answer is {}", answer(x)}
}

fn answer(x: u64) -> u64 {
    let ret = 17 + x;
    ret
}
