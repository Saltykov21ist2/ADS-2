// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
double pown(double value, uint16_t n) {
    uint64_t in;
    double xs = 1;
    for (in = 1; in <= n; in++)
        xs *= value;
    return xs;
}
uint64_t fact(uint16_t n) {
    if (n == 0)
        return 1;
    return fact(n-1)*n;
}
double calcItem(double xs, uint16_t n) {
    return pown(xs, n)/fact(n);
}
double expn(double xs, uint16_t count) {
    uint16_t in;
    double d;
    for (in = 0; in <= count; in++) {
        d += calcItem(xs, in);
    }
    return d;
}

double sinn(double xs, uint16_t count) {
    uint16_t in;
    double d = 0;
    for (in = 1; in <= count; in++) {
        d += pown(-1, in-1)*calcItem(xs, 2*in-1);
    }
    return d;
}

double cosn(double xs, uint16_t count) {
    uint16_t in;
    double d = 0;
    for (in = 1; in <= count; in++) {
        d += pown(-1, in-1)*calcItem(xs, 2*in-2);
    }
    return d;
}
