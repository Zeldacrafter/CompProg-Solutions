#include <bits/stdc++.h>
using namespace std;

#define SIZE 6

void updateDigits(int n, int digits[SIZE]) {
    // Get the digits of n into digits[]
    int index = 0;
    while(n) {
        digits[index++] = n % 10;
        n /= 10;
    }
}

int main() {

    int from;
    int to;
    scanf("%d-%d", &from, &to);

    int digits[SIZE];
    int count = 0;
    for(int i = from; i <= to; ++i) {
        updateDigits(i, digits);
        if(is_sorted(digits, digits + SIZE, greater<int>()) && 
                adjacent_find(digits, digits + SIZE) != digits + SIZE)
            count++;
    }

    printf("%d\n", count);

    return 0;
}