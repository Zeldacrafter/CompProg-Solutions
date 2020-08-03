#include <bits/stdc++.h>
using namespace std;

#define SIZE 6

void updateDigits(int n, int digits[SIZE]) {
    int index = 0;
    while(n) {
        digits[index++] = n % 10;
        n /= 10;
    }
}

bool exactly2Adj(int digits[SIZE]) {
    for(int i = 1; i < SIZE - 1; i++) {
        // Check to left
        if(digits[i] == digits[i - 1] && digits[i] != digits[i + 1])
            // Digits 2 left must be border or different digit
            if((i - 2) < 0 || digits[i - 2] != digits[i]) 
                return true;
        // Check to right
        if(digits[i] == digits[i + 1] && digits[i] != digits[i - 1])
            // Digit 2 right must be border or different digit
            if(i + 2 >= SIZE || digits[i + 2] != digits[i]) 
                return true;
    }
    return false;
}

int main() {

    int from;
    int to;
    scanf("%d-%d", &from, &to);

    int digits[SIZE];
    int count = 0;
    for(int i = from; i <= to; ++i) {
        updateDigits(i, digits);
        if(is_sorted(digits, digits + SIZE, greater<int>()) && exactly2Adj(digits)) 
            count++;
    }

    printf("%d\n", count);

    return 0;
}