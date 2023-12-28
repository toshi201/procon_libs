use ac_library::ModInt1000000007 as Mint;

// N!
fn fact_mod(N: i64) -> Mint {
    (1..=N).fold(Mint::new(1), |sum, x| sum*x)
}

// nCr
// n! / (r!*(n - r)!)
fn comb_mod(n: i64, r: i64) -> Mint {
    fact_mod(n) / (fact_mod(r) * fact_mod(n - r))
}
