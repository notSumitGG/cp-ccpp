use std::{
    collections::VecDeque,
    fmt,
    io::{self, BufRead},
    str::FromStr,
};
 
struct Scanner {
    tokens: VecDeque<String>,
}

impl Scanner {
    pub fn new() -> Self {
        let stdin = io::stdin();
        let mut tokens = VecDeque::new();
        for line in stdin.lock().lines() {
            for token in line.unwrap().split_ascii_whitespace() {
                tokens.push_back(token.to_owned());
            }
        }
        Self { tokens }
    }
 
    pub fn next<T: FromStr>(&mut self) -> T
    where
        <T as FromStr>::Err: fmt::Debug,
    {
        T::from_str(&self.tokens.pop_front().unwrap()).unwrap()
    }
}

fn main() {
    let mut input = Scanner::new();
    let s: String = input.next();
    
    let row = (s.len() as f64).sqrt().ceil() as usize;
    let mut op = vec![String::from(""); row];
    
    let mut opi = 0;
    for i in s.chars() {
        op[opi].push(i);
        opi += 1;
        if opi == row {
            opi = 0;
        }
    }
    
    for i in op.iter() {
        print!("{} ", i);
    }
}

