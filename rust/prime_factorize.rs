fn prime_factorize(n: u64) -> Vec<(u64, usize)> {
    let mut i = 2;
    let mut ansvec = vec![];
    let mut n2 = n;
    while i * i <= n {
        let mut b = 0;
        while n2 % i == 0 {
            n2 /= i;
            b += 1;
        }
        if b > 0 {
            ansvec.push((i, b));
        }
        i += 1;
    }
    if n2 > 1 {
        ansvec.push((n2, 1));
    }
    ansvec
}
