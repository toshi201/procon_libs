fn divisor_enume(n: u64) -> Vec<u64> {
    let mut i = 1;
    let mut ansvec = vec![];
    while i * i <= n {
        if n % i == 0 {
            ansvec.push(i);
            let b = n / i;
            if i != b {
                ansvec.push(b);
            }
        }
        i += 1;
    }
    ansvec.sort();
    ansvec
}
