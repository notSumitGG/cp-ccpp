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

// https://www.hackerrank.com/challenges/organizing-containers-of-balls/problem?isFullScreen=true

fn main() {
    let mut input = Scanner::new();
    let q: i8 = input.next();
    
    for _ in 0..q {
        let n: usize;
        let mut m: [[i32; 100]; 100] = [[0; 100]; 100];
        let mut cap: [i64; 100] = [0; 100];
        let mut c: [i64; 100] = [0; 100];
        
        n = input.next();
        for i in 0usize..n {
            for j in 0usize..n {
                m[i][j] = input.next();
                cap[i] += m[i][j] as i64;
                c[j] += m[i][j] as i64;
            }
        }
        
        let mut flag: bool = true;
        for i in 0usize..n {
            let mut index: i8 = -1;
            for j in 0usize..n {
                if cap[i] == c[j] {
                    index = j as i8;
                    break;
                }
            }
            if index != -1 {
                c[index as usize] = -1;
            } else {
                flag = false;
                break;
            }
        }
        
        if flag == true {
            println!("Possible");
        } else {
            println!("Impossible");
        }
    }
}

