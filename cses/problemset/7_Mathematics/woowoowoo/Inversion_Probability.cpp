#include <iostream>
#include <vector>
#include <iomanip>
#include <numeric>
#include <algorithm>
#include <cstdint> // 補上這個標頭檔以定義 uint32_t 與 uint64_t

using namespace std;

// 輕量級大數類別，專為精確分數運算設計
struct BigInt {
    uint32_t d[60]; // 60 * 32 bits = 1920 bits，足以儲存 10^500 的天文數字
    int sz;

    BigInt(uint64_t v = 0) {
        sz = 0;
        while (v) {
            d[sz++] = v & 0xFFFFFFFF;
            v >>= 32;
        }
    }

    // 支援大數乘上 64-bit 整數
    void mul(uint64_t v) {
        if (v == 0) { sz = 0; return; }
        if (v == 1) return;
        
        uint32_t v_low = v & 0xFFFFFFFF;
        uint32_t v_high = v >> 32;
        
        uint32_t res_d[60] = {0};
        int res_sz = 0;
        
        uint64_t carry = 0;
        for (int i = 0; i < sz; i++) {
            carry += (uint64_t)d[i] * v_low;
            res_d[res_sz++] = carry & 0xFFFFFFFF;
            carry >>= 32;
        }
        while (carry) {
            res_d[res_sz++] = carry & 0xFFFFFFFF;
            carry >>= 32;
        }
        
        if (v_high > 0) {
            carry = 0;
            for (int i = 0; i < sz; i++) {
                carry += (uint64_t)d[i] * v_high;
                if (i + 1 < res_sz) {
                    carry += res_d[i + 1];
                    res_d[i + 1] = carry & 0xFFFFFFFF;
                } else {
                    res_d[res_sz++] = carry & 0xFFFFFFFF;
                }
                carry >>= 32;
            }
            while (carry) {
                res_d[res_sz++] = carry & 0xFFFFFFFF;
                carry >>= 32;
            }
        }
        
        sz = res_sz;
        for (int i = 0; i < sz; i++) d[i] = res_d[i];
        trim();
    }

    // 大數加法
    void add(const BigInt& o) {
        uint64_t carry = 0;
        int n = max(sz, o.sz);
        for (int i = 0; i < n; i++) {
            carry += (i < sz ? d[i] : 0);
            carry += (i < o.sz ? o.d[i] : 0);
            d[i] = carry & 0xFFFFFFFF;
            carry >>= 32;
        }
        sz = n;
        while (carry) {
            d[sz++] = carry & 0xFFFFFFFF;
            carry >>= 32;
        }
        trim();
    }

    // 大數減法 (保證 this >= o)
    void sub(const BigInt& o) {
        uint64_t borrow = 0;
        for (int i = 0; i < sz; i++) {
            uint64_t sub_val = borrow + (i < o.sz ? o.d[i] : 0);
            if (d[i] < sub_val) {
                d[i] = d[i] + (1ULL << 32) - sub_val;
                borrow = 1;
            } else {
                d[i] -= sub_val;
                borrow = 0;
            }
        }
        trim();
    }

    void trim() {
        while (sz > 0 && d[sz - 1] == 0) sz--;
    }

    // 大數比較：小於回傳 -1，等於回傳 0，大於回傳 1
    int cmp(const BigInt& o) const {
        if (sz != o.sz) return sz < o.sz ? -1 : 1;
        for (int i = sz - 1; i >= 0; i--) {
            if (d[i] != o.d[i]) return d[i] < o.d[i] ? -1 : 1;
        }
        return 0;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> r(n);
    for (int i = 0; i < n; ++i) {
        cin >> r[i];
    }

    // 將分子依照分母分組
    long long num_arr[105] = {0};
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (r[i] <= r[j]) {
                num_arr[r[j]] += (r[i] - 1);
            } else {
                num_arr[r[i]] += (2 * r[i] - r[j] - 1);
            }
        }
    }

    // 建立精確分數：num 為分子，den 為分母 (皆為 BigInt)
    BigInt num(0);
    BigInt den(1);

    for (int d = 1; d <= 100; ++d) {
        if (num_arr[d] > 0) {
            long long n_i = num_arr[d];
            long long d_i = 2LL * d;
            
            // 約分，讓大數成長慢一點
            long long g = std::gcd(n_i, d_i);
            n_i /= g;
            d_i /= g;
            
            // 套用分數加法公式：N/D + n/d = (N*d + D*n) / (D*d)
            BigInt next_num = num;
            next_num.mul(d_i);
            
            BigInt term = den;
            term.mul(n_i);
            
            next_num.add(term);
            den.mul(d_i);
            
            num = next_num;
        }
    }

    // 將分子放大 10^6 倍，這樣整數除法的商就是我們需要的 6 位小數點數值
    BigInt N_prime = num;
    N_prime.mul(1000000ULL);

    // 二分搜尋求精確商 Q (因為 Q 最大不過 5*10^9，直接二分搜最快最省事)
    uint64_t low = 0, high = 5000000000ULL;
    uint64_t Q = 0;
    while (low <= high) {
        uint64_t mid = low + (high - low) / 2;
        BigInt guess = den;
        guess.mul(mid);
        if (guess.cmp(N_prime) <= 0) {
            Q = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    // 求出精確餘數 R = N' - Q * D
    BigInt guess = den;
    guess.mul(Q);
    BigInt R = N_prime;
    R.sub(guess);

    // 透過 2*R 與 D 的關係，完美實作 Round half to even
    R.mul(2);
    int cmp_res = R.cmp(den);
    
    if (cmp_res > 0) {
        Q++; // R/D > 0.5，無條件進位
    } else if (cmp_res == 0) {
        // R/D == 0.5，極度完美的平手，遇到奇數才進位
        if (Q % 2 != 0) {
            Q++;
        }
    }

    // 輸出處理：手動切分整數部與小數部
    cout << Q / 1000000 << "." 
         << setfill('0') << setw(6) << Q % 1000000 << "\n";

    return 0;
}