#[macro_use] extern crate text_io;

// https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true

fn taumBday(b: i64, w: i64, bc: i64, wc: i64, z: i64) -> i64 {
    let mut cost: i64 = 0;
    
    if bc < wc {
        cost += b * bc;
        if bc + z < wc {
            cost += w * (bc + z);
        } else {
            cost += w * wc;
        }
    } else if wc < bc {
        cost += w * wc;
        if wc + z < bc {
            cost += b * (wc + z);
        } else {
            cost += b * bc;
        }
    } else {
        cost += b * bc + w * wc;
    }
    
    cost
}

fn main() {
    let t: i32;
    scan!("{}\n", t);
    
    for _ in 0..t {
        let b: i64;
        let w: i64;
        let bc: i64;
        let wc: i64;
        let z: i64;
        
        scan!("{} {}\n", b, w);
        scan!("{} {} {}\n", bc, wc, z);
        
        print!("{}\n", taumBday(b, w, bc, wc, z));
    }
}
