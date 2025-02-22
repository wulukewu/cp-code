import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

def mod_exponentiation(base, exp, mod):
    result = 1
    while exp > 0:
        if exp % 2 == 1:
            result = (result * base) % mod
        base = (base * base) % mod
        exp //= 2
    return result

def find_remainder(N):
    MOD = 998244353
    
    # Convert N to string and find its length
    N_str = str(N)
    d = len(N_str)
    
    # Calculate 10^d % MOD
    ten_pow_d = mod_exponentiation(10, d, MOD)
    
    # Calculate (ten_pow_d^N - 1) % MOD
    numerator = mod_exponentiation(ten_pow_d, N, MOD) - 1
    if numerator < 0:
        numerator += MOD
    
    # Calculate (ten_pow_d - 1) % MOD
    denominator = ten_pow_d - 1
    if denominator < 0:
        denominator += MOD
    
    # Calculate the modular inverse of the denominator
    denominator_inv = mod_exponentiation(denominator, MOD - 2, MOD)
    
    # Calculate the geometric series sum modulo MOD
    sum_geometric_series = (numerator * denominator_inv) % MOD
    
    # Final result is (N % MOD) * sum_geometric_series % MOD
    result = (N % MOD) * sum_geometric_series % MOD
    return result

# Read input
N = int(input().strip())

# Compute the remainder
remainder = find_remainder(N)

# Print the result
print(remainder)
