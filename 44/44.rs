impl Solution {
    pub fn is_match(s: String, p: String) -> bool {
        let m = s.len();
        let n = p.len();
        let mut dp = vec![vec![false; n+1]; m+1];
        dp[0][0] = true;
        for i in 1..n+1 {
            if &p[i-1..i] == "*" {
                dp[0][i] = true;
            } else {
                break;
            }
        }

        for i in 1..(m+1) {
            for j in 1..(n+1) {
                if &p[j-1..j] == "*" {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else if &p[j-1..j] == "?" || &s[i-1..i] == &p[j-1..j] {
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }

        dp[m][n]
    }
}