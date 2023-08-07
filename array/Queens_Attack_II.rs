// use std::env;
// use std::fs::File;
// use std::io::{self, BufRead, Write};
// use core::cmp;
// // use std::cmp::{min, max};

// // https://www.hackerrank.com/challenges/queens-attack-2/problem?isFullScreen=true

// fn queensAttack(n: i32, k: i32, r_q: i32, c_q: i32, obstacles: &[Vec<i32>]) -> i32 {
//     let mut l_row = 1;
//     let mut r_row = n;
//     let mut d_col = 1;
//     let mut u_col = n;
//     let mut bl = (r_q-(cmp::min(r_q, c_q)-1), c_q-(cmp::min(r_q, c_q)-1));
//     let mut tr = (r_q+(n-cmp::max(r_q, c_q)), c_q+(n-cmp::max(r_q, c_q)));
//     let mut tl = (r_q+cmp::min(n-r_q, c_q-1), c_q-cmp::min(n-r_q, c_q-1));
//     let mut br = (r_q-cmp::min(r_q-1, n-c_q), c_q+cmp::min(r_q-1, n-c_q));
//     println!("{} {} {} {} {:?} {:?} {:?} {:?}", l_row, r_row, d_col, u_col, bl, tr, tl, br);
    
//     for (i, v) in obstacles.iter().enumerate() {
//         // row
//         if obstacles[i][0] == r_q {
//             print!("hi1 ");
//             if obstacles[i][1] < c_q && obstacles[i][1] > l_row {
//                 print!("hello1 ");
//                 l_row = obstacles[i][1] + 1;
//             } else if obstacles[i][1] > c_q && obstacles[i][1] < r_row {
//                 print!("hello2 ");
//                 r_row = obstacles[i][1] - 1;
//             }
//         } // column
//         else if obstacles[i][1] == c_q {
//             print!("hi2 ");
//             if obstacles[i][0] < r_q && obstacles[i][0] > d_col {
//                 print!("hello3 ");
//                 d_col = obstacles[i][0] + 1;
//             } else if obstacles[i][0] > r_q && obstacles[i][0] < u_col {
//                 print!("hello4 ");
//                 u_col = obstacles[i][0] - 1;
//             }
//         } // slash
//         else if obstacles[i][0] - r_q == obstacles[i][1] - c_q {
//             print!("hi3 ");
//             if obstacles[i][0] < r_q && obstacles[i][0] > bl.0 {
//                 print!("hello5 ");
//                 bl.0 = obstacles[i][0] + 1;
//             } else if obstacles[i][0] > r_q && obstacles[i][0] < tr.0 {
//                 print!("hello6 ");
//                 tr.0 = obstacles[i][0] - 1;
//             }
//         } // backslash
//         else if obstacles[i][0] + obstacles[i][1] == r_q + c_q {
//             print!("hi4 ");
//             if obstacles[i][0] < r_q && obstacles[i][0] > tl.0 {
//                 print!("hello7 ");
//                 tl.0 = obstacles[i][0] + 1;
//             } else if obstacles[i][0] > r_q && obstacles[i][0] < br.0 {
//                 print!("hello8 ");
//                 br.0 = obstacles[i][0] - 1;
//             }
//         } else {
//             print!("wtf ");
//         }
//         println!("{} {:?}", i, v);
//     }
    
//     println!("{} {} {} {} {:?} {:?} {:?} {:?}", l_row, r_row, d_col, u_col, bl, tr, tl, br);
//     (r_row-l_row) + (u_col-d_col) + num::abs(tr.0-bl.0) + num::abs(br.0-tl.0)
// }

// fn main() {
//     let stdin = io::stdin();
//     let mut stdin_iterator = stdin.lock().lines();

//     let mut fptr = File::create(env::var("OUTPUT_PATH").unwrap()).unwrap();

//     let first_multiple_input: Vec<String> = stdin_iterator.next().unwrap().unwrap()
//         .split(' ')
//         .map(|s| s.to_string())
//         .collect();

//     let n = first_multiple_input[0].trim().parse::<i32>().unwrap();

//     let k = first_multiple_input[1].trim().parse::<i32>().unwrap();

//     let second_multiple_input: Vec<String> = stdin_iterator.next().unwrap().unwrap()
//         .split(' ')
//         .map(|s| s.to_string())
//         .collect();

//     let r_q = second_multiple_input[0].trim().parse::<i32>().unwrap();

//     let c_q = second_multiple_input[1].trim().parse::<i32>().unwrap();

//     let mut obstacles: Vec<Vec<i32>> = Vec::with_capacity(k as usize);

//     for i in 0..k as usize {
//         obstacles.push(Vec::with_capacity(2_usize));

//         obstacles[i] = stdin_iterator.next().unwrap().unwrap()
//             .trim_end()
//             .split(' ')
//             .map(|s| s.to_string().parse::<i32>().unwrap())
//             .collect();
//     }

//     let result = queensAttack(n, k, r_q, c_q, &obstacles);

//     writeln!(&mut fptr, "{}", result).ok();
// }
#[macro_use] extern crate text_io;

use std::collections::HashSet;

fn main() {
    let n: i32;
    let k: i32;
    scan!("{} {}\n", n, k);
    
    let mut queen: (i32, i32) = (0, 0);
    scan!("{} {}\n", queen.0, queen.1);
    
    let mut obstacles = HashSet::new();
    for _ in 0..k {
        let mut tmp: (i32, i32) = (0, 0);
        scan!("{} {}\n", tmp.0, tmp.1);
        obstacles.insert(tmp);
    }

    let mut counter = 0;
    for &(dx, dy) in [(1, 0), (1, 1), (0, 1), (-1, 1), (-1, 0), (-1, -1), (0, -1), (1, -1)].into_iter() {
        let (mut x, mut y) = (queen.0 + dx, queen.1 + dy);
        while 0 < x && x <= n && 0 < y && y <= n && !obstacles.contains(&(x, y)) {
            counter += 1;
            x += dx;
            y += dy;
        }
    }
    println!("{}", counter);
}

