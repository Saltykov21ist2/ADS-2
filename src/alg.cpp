// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    uint64_t i;
    double y = 1;
    for (i = 1; i <= n; i++)
        y *= value;
    return y;
}

uint64_t fact(uint16_t n) {
    if (n == 0)
        return 1;
    return fact(n-1)*n;
}

double calcItem(double y, uint16_t n) {
    return pown(y, n)/fact(n);
}

double expn(double y, uint16_t count) {
    uint16_t i;
    double y;
    for (i = 0; i <= count; i++) {
        y += calcItem(y, i);
    }
    return y;
}

double sinn(double y, uint16_t count) {
    uint16_t i;
    double y = 0;
    for (i = 1; i <= count; i++) {
        y += pown(-1, i-1)*calcItem(y, 2*i-1);
    }
    return y;
}

double cosn(double y, uint16_t count) {
    uint16_t i;
    double y = 0;
    for (i = 1; i <= count; i++) {
        y += pown(-1, i-1)*calcItem(y, 2*i-2);
    }
    return y;
}
