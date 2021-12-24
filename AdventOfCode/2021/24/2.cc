#include "../utils.cc"

void solve() {
    // z: Base 26 variable
    // If last digit is input: Nothing changes
    // Else:                   New last digit is added
    ll z = 0;
    auto calc = [&](int w, int inp1, int inp2, bool cutOff) {
        int rem = z % 26;
        if(cutOff) z /= 26;

        if(rem + inp1 != w) {
            z = z*27 + (w + inp2);
        }
    };
    vi inp(14);
    // Set input here
    calc( 10,  1, false);
    calc( 11,  9, false);
    calc( 14, 12, false);
    calc( 13,  6, false);
    calc(- 6,  9,  true);
    calc(-14, 15,  true);
    calc( 14,  7, false);
    calc( 13, 12, false);
    calc(- 8, 15,  true);
    calc(-15,  3,  true);
    calc( 10,  6, false);
    calc(-11,  2,  true);
    calc(-13, 10,  true);
    calc(- 4, 12,  true);
    
    // Did the calculations by hand:

    // x[4]     = x[5]
    // x[3]     = x[6] + 2
    // x[8] + 4 = x[9]
    // x[7]     = x[10] + 8
    // x[11]    = x[12] + 5
    // x[2]     = x[13] + 4
    // x[1]     = x[14] + 3
    //
    // 1_2_3_4_5_6_7_8_9_10_11_12_13_14
    //
    // 4_5_3_1_1_1_9_1_5_ 1_ 6_ 1_ 1_ 1
    // 45311191516111
    //
    // 9_9_9_9_9_7_9_5_9_ 1_ 9_ 4_ 5_ 6
    // 99999795919456
}

