#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }

    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int N, num = 2;
    scanf("%d", &N);

    while (num <= N) {
        int flag = 1;
        for (int i = 2; i <= num; i++) {
            if (num % i == 0 && isPrime(i) && (num % (i * i) != 0)) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            printf("%d ", num);
        }
        num++;
    }

    return 0;
}
