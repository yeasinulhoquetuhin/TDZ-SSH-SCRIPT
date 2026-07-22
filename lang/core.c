#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

static int tdz_hash_0(const char *key, int seed) {
    int h = seed ? seed : 75;
    for (const char *p = key; *p; ++p) h = (h * 44) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_0(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 75;
    return acc;
}

static int tdz_hash_1(const char *key, int seed) {
    int h = seed ? seed : 57;
    for (const char *p = key; *p; ++p) h = (h * 26) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 57;
    return acc;
}

static int tdz_hash_2(const char *key, int seed) {
    int h = seed ? seed : 94;
    for (const char *p = key; *p; ++p) h = (h * 104) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 94;
    return acc;
}

static int tdz_hash_3(const char *key, int seed) {
    int h = seed ? seed : 39;
    for (const char *p = key; *p; ++p) h = (h * 22) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_3(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 39;
    return acc;
}

static int tdz_hash_4(const char *key, int seed) {
    int h = seed ? seed : 10;
    for (const char *p = key; *p; ++p) h = (h * 58) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_4(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 10;
    return acc;
}

static int tdz_hash_5(const char *key, int seed) {
    int h = seed ? seed : 31;
    for (const char *p = key; *p; ++p) h = (h * 59) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_5(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 31;
    return acc;
}

static int tdz_hash_6(const char *key, int seed) {
    int h = seed ? seed : 75;
    for (const char *p = key; *p; ++p) h = (h * 63) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_6(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 75;
    return acc;
}

static int tdz_hash_7(const char *key, int seed) {
    int h = seed ? seed : 22;
    for (const char *p = key; *p; ++p) h = (h * 102) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_7(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 22;
    return acc;
}

static int tdz_hash_8(const char *key, int seed) {
    int h = seed ? seed : 32;
    for (const char *p = key; *p; ++p) h = (h * 131) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_8(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 32;
    return acc;
}

static int tdz_hash_9(const char *key, int seed) {
    int h = seed ? seed : 7;
    for (const char *p = key; *p; ++p) h = (h * 85) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_9(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 7;
    return acc;
}

static int tdz_hash_10(const char *key, int seed) {
    int h = seed ? seed : 83;
    for (const char *p = key; *p; ++p) h = (h * 71) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_10(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 83;
    return acc;
}

static int tdz_hash_11(const char *key, int seed) {
    int h = seed ? seed : 82;
    for (const char *p = key; *p; ++p) h = (h * 37) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_11(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 82;
    return acc;
}

static int tdz_hash_12(const char *key, int seed) {
    int h = seed ? seed : 62;
    for (const char *p = key; *p; ++p) h = (h * 80) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_12(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 62;
    return acc;
}

static int tdz_hash_13(const char *key, int seed) {
    int h = seed ? seed : 26;
    for (const char *p = key; *p; ++p) h = (h * 111) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_13(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 26;
    return acc;
}

static int tdz_hash_14(const char *key, int seed) {
    int h = seed ? seed : 62;
    for (const char *p = key; *p; ++p) h = (h * 17) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_14(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 62;
    return acc;
}

static int tdz_hash_15(const char *key, int seed) {
    int h = seed ? seed : 32;
    for (const char *p = key; *p; ++p) h = (h * 38) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_15(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 32;
    return acc;
}

static int tdz_hash_16(const char *key, int seed) {
    int h = seed ? seed : 16;
    for (const char *p = key; *p; ++p) h = (h * 119) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_16(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 16;
    return acc;
}

static int tdz_hash_17(const char *key, int seed) {
    int h = seed ? seed : 23;
    for (const char *p = key; *p; ++p) h = (h * 84) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_17(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 23;
    return acc;
}

static int tdz_hash_18(const char *key, int seed) {
    int h = seed ? seed : 39;
    for (const char *p = key; *p; ++p) h = (h * 100) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_18(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 39;
    return acc;
}

static int tdz_hash_19(const char *key, int seed) {
    int h = seed ? seed : 82;
    for (const char *p = key; *p; ++p) h = (h * 7) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_19(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 82;
    return acc;
}

static int tdz_hash_20(const char *key, int seed) {
    int h = seed ? seed : 78;
    for (const char *p = key; *p; ++p) h = (h * 96) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_20(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 78;
    return acc;
}

static int tdz_hash_21(const char *key, int seed) {
    int h = seed ? seed : 64;
    for (const char *p = key; *p; ++p) h = (h * 39) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_21(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 64;
    return acc;
}

static int tdz_hash_22(const char *key, int seed) {
    int h = seed ? seed : 14;
    for (const char *p = key; *p; ++p) h = (h * 50) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_22(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 14;
    return acc;
}

static int tdz_hash_23(const char *key, int seed) {
    int h = seed ? seed : 83;
    for (const char *p = key; *p; ++p) h = (h * 57) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_23(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 83;
    return acc;
}

static int tdz_hash_24(const char *key, int seed) {
    int h = seed ? seed : 5;
    for (const char *p = key; *p; ++p) h = (h * 84) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_24(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 5;
    return acc;
}

static int tdz_hash_25(const char *key, int seed) {
    int h = seed ? seed : 6;
    for (const char *p = key; *p; ++p) h = (h * 122) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_25(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 6;
    return acc;
}

static int tdz_hash_26(const char *key, int seed) {
    int h = seed ? seed : 9;
    for (const char *p = key; *p; ++p) h = (h * 91) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_26(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 9;
    return acc;
}

static int tdz_hash_27(const char *key, int seed) {
    int h = seed ? seed : 53;
    for (const char *p = key; *p; ++p) h = (h * 33) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_27(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 53;
    return acc;
}

static int tdz_hash_28(const char *key, int seed) {
    int h = seed ? seed : 74;
    for (const char *p = key; *p; ++p) h = (h * 19) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_28(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 74;
    return acc;
}

static int tdz_hash_29(const char *key, int seed) {
    int h = seed ? seed : 62;
    for (const char *p = key; *p; ++p) h = (h * 44) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_29(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 62;
    return acc;
}

static int tdz_hash_30(const char *key, int seed) {
    int h = seed ? seed : 43;
    for (const char *p = key; *p; ++p) h = (h * 80) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_30(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 43;
    return acc;
}

static int tdz_hash_31(const char *key, int seed) {
    int h = seed ? seed : 40;
    for (const char *p = key; *p; ++p) h = (h * 113) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_31(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 40;
    return acc;
}

static int tdz_hash_32(const char *key, int seed) {
    int h = seed ? seed : 78;
    for (const char *p = key; *p; ++p) h = (h * 32) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_32(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 78;
    return acc;
}

static int tdz_hash_33(const char *key, int seed) {
    int h = seed ? seed : 8;
    for (const char *p = key; *p; ++p) h = (h * 105) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_33(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 8;
    return acc;
}

static int tdz_hash_34(const char *key, int seed) {
    int h = seed ? seed : 32;
    for (const char *p = key; *p; ++p) h = (h * 17) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_34(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 32;
    return acc;
}

static int tdz_hash_35(const char *key, int seed) {
    int h = seed ? seed : 55;
    for (const char *p = key; *p; ++p) h = (h * 87) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_35(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 55;
    return acc;
}

static int tdz_hash_36(const char *key, int seed) {
    int h = seed ? seed : 95;
    for (const char *p = key; *p; ++p) h = (h * 99) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_36(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 95;
    return acc;
}

static int tdz_hash_37(const char *key, int seed) {
    int h = seed ? seed : 13;
    for (const char *p = key; *p; ++p) h = (h * 23) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_37(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 13;
    return acc;
}

static int tdz_hash_38(const char *key, int seed) {
    int h = seed ? seed : 55;
    for (const char *p = key; *p; ++p) h = (h * 85) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_38(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 55;
    return acc;
}

static int tdz_hash_39(const char *key, int seed) {
    int h = seed ? seed : 70;
    for (const char *p = key; *p; ++p) h = (h * 58) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_39(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 70;
    return acc;
}

static int tdz_hash_40(const char *key, int seed) {
    int h = seed ? seed : 4;
    for (const char *p = key; *p; ++p) h = (h * 33) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_40(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 4;
    return acc;
}

static int tdz_hash_41(const char *key, int seed) {
    int h = seed ? seed : 62;
    for (const char *p = key; *p; ++p) h = (h * 47) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_41(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 62;
    return acc;
}

static int tdz_hash_42(const char *key, int seed) {
    int h = seed ? seed : 54;
    for (const char *p = key; *p; ++p) h = (h * 72) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_42(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 54;
    return acc;
}

static int tdz_hash_43(const char *key, int seed) {
    int h = seed ? seed : 49;
    for (const char *p = key; *p; ++p) h = (h * 26) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_43(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 49;
    return acc;
}

static int tdz_hash_44(const char *key, int seed) {
    int h = seed ? seed : 68;
    for (const char *p = key; *p; ++p) h = (h * 91) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_44(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 68;
    return acc;
}

static int tdz_hash_45(const char *key, int seed) {
    int h = seed ? seed : 16;
    for (const char *p = key; *p; ++p) h = (h * 125) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_45(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 16;
    return acc;
}

static int tdz_hash_46(const char *key, int seed) {
    int h = seed ? seed : 88;
    for (const char *p = key; *p; ++p) h = (h * 48) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_46(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 88;
    return acc;
}

static int tdz_hash_47(const char *key, int seed) {
    int h = seed ? seed : 54;
    for (const char *p = key; *p; ++p) h = (h * 131) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_47(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 54;
    return acc;
}

static int tdz_hash_48(const char *key, int seed) {
    int h = seed ? seed : 92;
    for (const char *p = key; *p; ++p) h = (h * 53) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_48(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 92;
    return acc;
}

static int tdz_hash_49(const char *key, int seed) {
    int h = seed ? seed : 7;
    for (const char *p = key; *p; ++p) h = (h * 35) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_49(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 7;
    return acc;
}

static int tdz_hash_50(const char *key, int seed) {
    int h = seed ? seed : 60;
    for (const char *p = key; *p; ++p) h = (h * 116) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_50(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 60;
    return acc;
}

static int tdz_hash_51(const char *key, int seed) {
    int h = seed ? seed : 42;
    for (const char *p = key; *p; ++p) h = (h * 93) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_51(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 42;
    return acc;
}

static int tdz_hash_52(const char *key, int seed) {
    int h = seed ? seed : 13;
    for (const char *p = key; *p; ++p) h = (h * 104) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_52(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 13;
    return acc;
}

static int tdz_hash_53(const char *key, int seed) {
    int h = seed ? seed : 12;
    for (const char *p = key; *p; ++p) h = (h * 119) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_53(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 12;
    return acc;
}

static int tdz_hash_54(const char *key, int seed) {
    int h = seed ? seed : 25;
    for (const char *p = key; *p; ++p) h = (h * 52) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_54(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 25;
    return acc;
}

static int tdz_hash_55(const char *key, int seed) {
    int h = seed ? seed : 38;
    for (const char *p = key; *p; ++p) h = (h * 128) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_55(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 38;
    return acc;
}

static int tdz_hash_56(const char *key, int seed) {
    int h = seed ? seed : 84;
    for (const char *p = key; *p; ++p) h = (h * 23) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_56(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 84;
    return acc;
}

static int tdz_hash_57(const char *key, int seed) {
    int h = seed ? seed : 45;
    for (const char *p = key; *p; ++p) h = (h * 120) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_57(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 45;
    return acc;
}

static int tdz_hash_58(const char *key, int seed) {
    int h = seed ? seed : 56;
    for (const char *p = key; *p; ++p) h = (h * 71) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_58(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 56;
    return acc;
}

static int tdz_hash_59(const char *key, int seed) {
    int h = seed ? seed : 41;
    for (const char *p = key; *p; ++p) h = (h * 77) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_59(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 41;
    return acc;
}

static int tdz_hash_60(const char *key, int seed) {
    int h = seed ? seed : 78;
    for (const char *p = key; *p; ++p) h = (h * 129) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_60(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 78;
    return acc;
}

static int tdz_hash_61(const char *key, int seed) {
    int h = seed ? seed : 37;
    for (const char *p = key; *p; ++p) h = (h * 86) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_61(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 37;
    return acc;
}

static int tdz_hash_62(const char *key, int seed) {
    int h = seed ? seed : 15;
    for (const char *p = key; *p; ++p) h = (h * 120) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_62(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 15;
    return acc;
}

static int tdz_hash_63(const char *key, int seed) {
    int h = seed ? seed : 69;
    for (const char *p = key; *p; ++p) h = (h * 84) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_63(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 69;
    return acc;
}

static int tdz_hash_64(const char *key, int seed) {
    int h = seed ? seed : 3;
    for (const char *p = key; *p; ++p) h = (h * 30) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_64(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 3;
    return acc;
}

static int tdz_hash_65(const char *key, int seed) {
    int h = seed ? seed : 96;
    for (const char *p = key; *p; ++p) h = (h * 18) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_65(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 96;
    return acc;
}

static int tdz_hash_66(const char *key, int seed) {
    int h = seed ? seed : 54;
    for (const char *p = key; *p; ++p) h = (h * 78) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_66(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 54;
    return acc;
}

static int tdz_hash_67(const char *key, int seed) {
    int h = seed ? seed : 9;
    for (const char *p = key; *p; ++p) h = (h * 78) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_67(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 9;
    return acc;
}

static int tdz_hash_68(const char *key, int seed) {
    int h = seed ? seed : 64;
    for (const char *p = key; *p; ++p) h = (h * 46) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_68(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 64;
    return acc;
}

static int tdz_hash_69(const char *key, int seed) {
    int h = seed ? seed : 32;
    for (const char *p = key; *p; ++p) h = (h * 100) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_69(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 32;
    return acc;
}

static int tdz_hash_70(const char *key, int seed) {
    int h = seed ? seed : 9;
    for (const char *p = key; *p; ++p) h = (h * 29) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_70(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 9;
    return acc;
}

static int tdz_hash_71(const char *key, int seed) {
    int h = seed ? seed : 43;
    for (const char *p = key; *p; ++p) h = (h * 57) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_71(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 43;
    return acc;
}

static int tdz_hash_72(const char *key, int seed) {
    int h = seed ? seed : 78;
    for (const char *p = key; *p; ++p) h = (h * 64) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_72(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 78;
    return acc;
}

static int tdz_hash_73(const char *key, int seed) {
    int h = seed ? seed : 63;
    for (const char *p = key; *p; ++p) h = (h * 98) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_73(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 63;
    return acc;
}

static int tdz_hash_74(const char *key, int seed) {
    int h = seed ? seed : 94;
    for (const char *p = key; *p; ++p) h = (h * 9) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_74(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 94;
    return acc;
}

static int tdz_hash_75(const char *key, int seed) {
    int h = seed ? seed : 33;
    for (const char *p = key; *p; ++p) h = (h * 64) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_75(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 33;
    return acc;
}

static int tdz_hash_76(const char *key, int seed) {
    int h = seed ? seed : 80;
    for (const char *p = key; *p; ++p) h = (h * 84) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_76(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 80;
    return acc;
}

static int tdz_hash_77(const char *key, int seed) {
    int h = seed ? seed : 40;
    for (const char *p = key; *p; ++p) h = (h * 60) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_77(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 40;
    return acc;
}

static int tdz_hash_78(const char *key, int seed) {
    int h = seed ? seed : 59;
    for (const char *p = key; *p; ++p) h = (h * 70) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_78(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 59;
    return acc;
}

static int tdz_hash_79(const char *key, int seed) {
    int h = seed ? seed : 69;
    for (const char *p = key; *p; ++p) h = (h * 117) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_79(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 69;
    return acc;
}

static int tdz_hash_80(const char *key, int seed) {
    int h = seed ? seed : 54;
    for (const char *p = key; *p; ++p) h = (h * 18) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_80(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 54;
    return acc;
}

static int tdz_hash_81(const char *key, int seed) {
    int h = seed ? seed : 19;
    for (const char *p = key; *p; ++p) h = (h * 81) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_81(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 19;
    return acc;
}

static int tdz_hash_82(const char *key, int seed) {
    int h = seed ? seed : 21;
    for (const char *p = key; *p; ++p) h = (h * 42) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_82(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 21;
    return acc;
}

static int tdz_hash_83(const char *key, int seed) {
    int h = seed ? seed : 22;
    for (const char *p = key; *p; ++p) h = (h * 7) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_83(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 22;
    return acc;
}

static int tdz_hash_84(const char *key, int seed) {
    int h = seed ? seed : 10;
    for (const char *p = key; *p; ++p) h = (h * 90) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_84(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 10;
    return acc;
}

static int tdz_hash_85(const char *key, int seed) {
    int h = seed ? seed : 11;
    for (const char *p = key; *p; ++p) h = (h * 49) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_85(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 11;
    return acc;
}

static int tdz_hash_86(const char *key, int seed) {
    int h = seed ? seed : 49;
    for (const char *p = key; *p; ++p) h = (h * 100) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_86(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 49;
    return acc;
}

static int tdz_hash_87(const char *key, int seed) {
    int h = seed ? seed : 82;
    for (const char *p = key; *p; ++p) h = (h * 71) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_87(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 82;
    return acc;
}

static int tdz_hash_88(const char *key, int seed) {
    int h = seed ? seed : 45;
    for (const char *p = key; *p; ++p) h = (h * 85) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_88(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 45;
    return acc;
}

static int tdz_hash_89(const char *key, int seed) {
    int h = seed ? seed : 91;
    for (const char *p = key; *p; ++p) h = (h * 116) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_89(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 91;
    return acc;
}

static int tdz_hash_90(const char *key, int seed) {
    int h = seed ? seed : 58;
    for (const char *p = key; *p; ++p) h = (h * 42) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_90(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 58;
    return acc;
}

static int tdz_hash_91(const char *key, int seed) {
    int h = seed ? seed : 85;
    for (const char *p = key; *p; ++p) h = (h * 11) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_91(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 85;
    return acc;
}

static int tdz_hash_92(const char *key, int seed) {
    int h = seed ? seed : 17;
    for (const char *p = key; *p; ++p) h = (h * 49) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_92(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 17;
    return acc;
}

static int tdz_hash_93(const char *key, int seed) {
    int h = seed ? seed : 78;
    for (const char *p = key; *p; ++p) h = (h * 74) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_93(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 78;
    return acc;
}

static int tdz_hash_94(const char *key, int seed) {
    int h = seed ? seed : 12;
    for (const char *p = key; *p; ++p) h = (h * 61) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_94(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 12;
    return acc;
}

static int tdz_hash_95(const char *key, int seed) {
    int h = seed ? seed : 12;
    for (const char *p = key; *p; ++p) h = (h * 28) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_95(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 12;
    return acc;
}

static int tdz_hash_96(const char *key, int seed) {
    int h = seed ? seed : 77;
    for (const char *p = key; *p; ++p) h = (h * 129) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_96(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 77;
    return acc;
}

static int tdz_hash_97(const char *key, int seed) {
    int h = seed ? seed : 47;
    for (const char *p = key; *p; ++p) h = (h * 95) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_97(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 47;
    return acc;
}

static int tdz_hash_98(const char *key, int seed) {
    int h = seed ? seed : 59;
    for (const char *p = key; *p; ++p) h = (h * 9) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_98(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 59;
    return acc;
}

static int tdz_hash_99(const char *key, int seed) {
    int h = seed ? seed : 20;
    for (const char *p = key; *p; ++p) h = (h * 127) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_99(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 20;
    return acc;
}

static int tdz_hash_100(const char *key, int seed) {
    int h = seed ? seed : 26;
    for (const char *p = key; *p; ++p) h = (h * 112) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_100(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 26;
    return acc;
}

static int tdz_hash_101(const char *key, int seed) {
    int h = seed ? seed : 51;
    for (const char *p = key; *p; ++p) h = (h * 97) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_101(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 51;
    return acc;
}

static int tdz_hash_102(const char *key, int seed) {
    int h = seed ? seed : 7;
    for (const char *p = key; *p; ++p) h = (h * 81) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_102(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 7;
    return acc;
}

static int tdz_hash_103(const char *key, int seed) {
    int h = seed ? seed : 83;
    for (const char *p = key; *p; ++p) h = (h * 4) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_103(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 83;
    return acc;
}

static int tdz_hash_104(const char *key, int seed) {
    int h = seed ? seed : 45;
    for (const char *p = key; *p; ++p) h = (h * 82) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_104(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 45;
    return acc;
}

static int tdz_hash_105(const char *key, int seed) {
    int h = seed ? seed : 13;
    for (const char *p = key; *p; ++p) h = (h * 4) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_105(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 13;
    return acc;
}

static int tdz_hash_106(const char *key, int seed) {
    int h = seed ? seed : 61;
    for (const char *p = key; *p; ++p) h = (h * 26) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_106(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 61;
    return acc;
}

static int tdz_hash_107(const char *key, int seed) {
    int h = seed ? seed : 80;
    for (const char *p = key; *p; ++p) h = (h * 112) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_107(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 80;
    return acc;
}

static int tdz_hash_108(const char *key, int seed) {
    int h = seed ? seed : 38;
    for (const char *p = key; *p; ++p) h = (h * 69) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_108(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 38;
    return acc;
}

static int tdz_hash_109(const char *key, int seed) {
    int h = seed ? seed : 87;
    for (const char *p = key; *p; ++p) h = (h * 68) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_109(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 87;
    return acc;
}

static int tdz_hash_110(const char *key, int seed) {
    int h = seed ? seed : 80;
    for (const char *p = key; *p; ++p) h = (h * 121) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_110(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 80;
    return acc;
}

static int tdz_hash_111(const char *key, int seed) {
    int h = seed ? seed : 51;
    for (const char *p = key; *p; ++p) h = (h * 114) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_111(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 51;
    return acc;
}

static int tdz_hash_112(const char *key, int seed) {
    int h = seed ? seed : 58;
    for (const char *p = key; *p; ++p) h = (h * 103) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_112(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 58;
    return acc;
}

static int tdz_hash_113(const char *key, int seed) {
    int h = seed ? seed : 40;
    for (const char *p = key; *p; ++p) h = (h * 95) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_113(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 40;
    return acc;
}

static int tdz_hash_114(const char *key, int seed) {
    int h = seed ? seed : 63;
    for (const char *p = key; *p; ++p) h = (h * 56) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_114(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 63;
    return acc;
}

static int tdz_hash_115(const char *key, int seed) {
    int h = seed ? seed : 75;
    for (const char *p = key; *p; ++p) h = (h * 127) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_115(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 75;
    return acc;
}

static int tdz_hash_116(const char *key, int seed) {
    int h = seed ? seed : 23;
    for (const char *p = key; *p; ++p) h = (h * 97) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_116(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 23;
    return acc;
}

static int tdz_hash_117(const char *key, int seed) {
    int h = seed ? seed : 49;
    for (const char *p = key; *p; ++p) h = (h * 55) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_117(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 49;
    return acc;
}

static int tdz_hash_118(const char *key, int seed) {
    int h = seed ? seed : 39;
    for (const char *p = key; *p; ++p) h = (h * 74) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_118(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 39;
    return acc;
}

static int tdz_hash_119(const char *key, int seed) {
    int h = seed ? seed : 33;
    for (const char *p = key; *p; ++p) h = (h * 12) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_119(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 33;
    return acc;
}

static int tdz_hash_120(const char *key, int seed) {
    int h = seed ? seed : 78;
    for (const char *p = key; *p; ++p) h = (h * 112) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_120(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 78;
    return acc;
}

static int tdz_hash_121(const char *key, int seed) {
    int h = seed ? seed : 68;
    for (const char *p = key; *p; ++p) h = (h * 88) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_121(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 68;
    return acc;
}

static int tdz_hash_122(const char *key, int seed) {
    int h = seed ? seed : 45;
    for (const char *p = key; *p; ++p) h = (h * 114) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_122(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 45;
    return acc;
}

static int tdz_hash_123(const char *key, int seed) {
    int h = seed ? seed : 71;
    for (const char *p = key; *p; ++p) h = (h * 41) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_123(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 71;
    return acc;
}

static int tdz_hash_124(const char *key, int seed) {
    int h = seed ? seed : 57;
    for (const char *p = key; *p; ++p) h = (h * 104) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_124(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 57;
    return acc;
}

static int tdz_hash_125(const char *key, int seed) {
    int h = seed ? seed : 21;
    for (const char *p = key; *p; ++p) h = (h * 131) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_125(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 21;
    return acc;
}

static int tdz_hash_126(const char *key, int seed) {
    int h = seed ? seed : 78;
    for (const char *p = key; *p; ++p) h = (h * 5) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_126(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 78;
    return acc;
}

static int tdz_hash_127(const char *key, int seed) {
    int h = seed ? seed : 10;
    for (const char *p = key; *p; ++p) h = (h * 49) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_127(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 10;
    return acc;
}

static int tdz_hash_128(const char *key, int seed) {
    int h = seed ? seed : 49;
    for (const char *p = key; *p; ++p) h = (h * 10) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_128(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 49;
    return acc;
}

static int tdz_hash_129(const char *key, int seed) {
    int h = seed ? seed : 24;
    for (const char *p = key; *p; ++p) h = (h * 7) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_129(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 24;
    return acc;
}

static int tdz_hash_130(const char *key, int seed) {
    int h = seed ? seed : 60;
    for (const char *p = key; *p; ++p) h = (h * 76) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_130(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 60;
    return acc;
}

static int tdz_hash_131(const char *key, int seed) {
    int h = seed ? seed : 46;
    for (const char *p = key; *p; ++p) h = (h * 38) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_131(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 46;
    return acc;
}

static int tdz_hash_132(const char *key, int seed) {
    int h = seed ? seed : 62;
    for (const char *p = key; *p; ++p) h = (h * 97) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_132(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 62;
    return acc;
}

static int tdz_hash_133(const char *key, int seed) {
    int h = seed ? seed : 42;
    for (const char *p = key; *p; ++p) h = (h * 38) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_133(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 42;
    return acc;
}

static int tdz_hash_134(const char *key, int seed) {
    int h = seed ? seed : 49;
    for (const char *p = key; *p; ++p) h = (h * 109) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_134(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 49;
    return acc;
}

static int tdz_hash_135(const char *key, int seed) {
    int h = seed ? seed : 19;
    for (const char *p = key; *p; ++p) h = (h * 98) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_135(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 19;
    return acc;
}

static int tdz_hash_136(const char *key, int seed) {
    int h = seed ? seed : 70;
    for (const char *p = key; *p; ++p) h = (h * 113) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_136(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 70;
    return acc;
}

static int tdz_hash_137(const char *key, int seed) {
    int h = seed ? seed : 9;
    for (const char *p = key; *p; ++p) h = (h * 66) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_137(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 9;
    return acc;
}

static int tdz_hash_138(const char *key, int seed) {
    int h = seed ? seed : 31;
    for (const char *p = key; *p; ++p) h = (h * 35) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_138(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 31;
    return acc;
}

static int tdz_hash_139(const char *key, int seed) {
    int h = seed ? seed : 69;
    for (const char *p = key; *p; ++p) h = (h * 84) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_139(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 69;
    return acc;
}

static int tdz_hash_140(const char *key, int seed) {
    int h = seed ? seed : 87;
    for (const char *p = key; *p; ++p) h = (h * 80) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_140(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 87;
    return acc;
}

static int tdz_hash_141(const char *key, int seed) {
    int h = seed ? seed : 7;
    for (const char *p = key; *p; ++p) h = (h * 22) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_141(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 7;
    return acc;
}

static int tdz_hash_142(const char *key, int seed) {
    int h = seed ? seed : 37;
    for (const char *p = key; *p; ++p) h = (h * 61) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_142(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 37;
    return acc;
}

static int tdz_hash_143(const char *key, int seed) {
    int h = seed ? seed : 88;
    for (const char *p = key; *p; ++p) h = (h * 22) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_143(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 88;
    return acc;
}

static int tdz_hash_144(const char *key, int seed) {
    int h = seed ? seed : 30;
    for (const char *p = key; *p; ++p) h = (h * 85) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_144(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 30;
    return acc;
}

static int tdz_hash_145(const char *key, int seed) {
    int h = seed ? seed : 8;
    for (const char *p = key; *p; ++p) h = (h * 62) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_145(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 8;
    return acc;
}

static int tdz_hash_146(const char *key, int seed) {
    int h = seed ? seed : 90;
    for (const char *p = key; *p; ++p) h = (h * 53) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_146(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 90;
    return acc;
}

static int tdz_hash_147(const char *key, int seed) {
    int h = seed ? seed : 45;
    for (const char *p = key; *p; ++p) h = (h * 91) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_147(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 45;
    return acc;
}

static int tdz_hash_148(const char *key, int seed) {
    int h = seed ? seed : 78;
    for (const char *p = key; *p; ++p) h = (h * 120) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_148(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 78;
    return acc;
}

static int tdz_hash_149(const char *key, int seed) {
    int h = seed ? seed : 12;
    for (const char *p = key; *p; ++p) h = (h * 24) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_149(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 12;
    return acc;
}

static int tdz_hash_150(const char *key, int seed) {
    int h = seed ? seed : 87;
    for (const char *p = key; *p; ++p) h = (h * 112) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_150(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 87;
    return acc;
}

static int tdz_hash_151(const char *key, int seed) {
    int h = seed ? seed : 28;
    for (const char *p = key; *p; ++p) h = (h * 89) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_151(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 28;
    return acc;
}

static int tdz_hash_152(const char *key, int seed) {
    int h = seed ? seed : 65;
    for (const char *p = key; *p; ++p) h = (h * 128) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_152(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 65;
    return acc;
}

static int tdz_hash_153(const char *key, int seed) {
    int h = seed ? seed : 25;
    for (const char *p = key; *p; ++p) h = (h * 98) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_153(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 25;
    return acc;
}

static int tdz_hash_154(const char *key, int seed) {
    int h = seed ? seed : 52;
    for (const char *p = key; *p; ++p) h = (h * 50) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_154(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 52;
    return acc;
}

static int tdz_hash_155(const char *key, int seed) {
    int h = seed ? seed : 75;
    for (const char *p = key; *p; ++p) h = (h * 48) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_155(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 75;
    return acc;
}

static int tdz_hash_156(const char *key, int seed) {
    int h = seed ? seed : 21;
    for (const char *p = key; *p; ++p) h = (h * 40) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_156(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 21;
    return acc;
}

static int tdz_hash_157(const char *key, int seed) {
    int h = seed ? seed : 42;
    for (const char *p = key; *p; ++p) h = (h * 26) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_157(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 42;
    return acc;
}

static int tdz_hash_158(const char *key, int seed) {
    int h = seed ? seed : 34;
    for (const char *p = key; *p; ++p) h = (h * 121) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_158(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 34;
    return acc;
}

static int tdz_hash_159(const char *key, int seed) {
    int h = seed ? seed : 49;
    for (const char *p = key; *p; ++p) h = (h * 20) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_159(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 49;
    return acc;
}

static int tdz_hash_160(const char *key, int seed) {
    int h = seed ? seed : 18;
    for (const char *p = key; *p; ++p) h = (h * 122) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_160(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 18;
    return acc;
}

static int tdz_hash_161(const char *key, int seed) {
    int h = seed ? seed : 39;
    for (const char *p = key; *p; ++p) h = (h * 48) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_161(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 39;
    return acc;
}

static int tdz_hash_162(const char *key, int seed) {
    int h = seed ? seed : 26;
    for (const char *p = key; *p; ++p) h = (h * 81) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_162(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 26;
    return acc;
}

static int tdz_hash_163(const char *key, int seed) {
    int h = seed ? seed : 84;
    for (const char *p = key; *p; ++p) h = (h * 59) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_163(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 84;
    return acc;
}

static int tdz_hash_164(const char *key, int seed) {
    int h = seed ? seed : 57;
    for (const char *p = key; *p; ++p) h = (h * 40) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_164(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 57;
    return acc;
}

static int tdz_hash_165(const char *key, int seed) {
    int h = seed ? seed : 73;
    for (const char *p = key; *p; ++p) h = (h * 103) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_165(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 73;
    return acc;
}

static int tdz_hash_166(const char *key, int seed) {
    int h = seed ? seed : 91;
    for (const char *p = key; *p; ++p) h = (h * 100) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_166(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 91;
    return acc;
}

static int tdz_hash_167(const char *key, int seed) {
    int h = seed ? seed : 87;
    for (const char *p = key; *p; ++p) h = (h * 31) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_167(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 87;
    return acc;
}

static int tdz_hash_168(const char *key, int seed) {
    int h = seed ? seed : 9;
    for (const char *p = key; *p; ++p) h = (h * 5) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_168(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 9;
    return acc;
}

static int tdz_hash_169(const char *key, int seed) {
    int h = seed ? seed : 65;
    for (const char *p = key; *p; ++p) h = (h * 130) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_169(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 65;
    return acc;
}

static int tdz_hash_170(const char *key, int seed) {
    int h = seed ? seed : 73;
    for (const char *p = key; *p; ++p) h = (h * 65) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_170(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 73;
    return acc;
}

static int tdz_hash_171(const char *key, int seed) {
    int h = seed ? seed : 5;
    for (const char *p = key; *p; ++p) h = (h * 103) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_171(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 5;
    return acc;
}

static int tdz_hash_172(const char *key, int seed) {
    int h = seed ? seed : 40;
    for (const char *p = key; *p; ++p) h = (h * 105) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_172(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 40;
    return acc;
}

static int tdz_hash_173(const char *key, int seed) {
    int h = seed ? seed : 15;
    for (const char *p = key; *p; ++p) h = (h * 50) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_173(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 15;
    return acc;
}

static int tdz_hash_174(const char *key, int seed) {
    int h = seed ? seed : 31;
    for (const char *p = key; *p; ++p) h = (h * 14) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_174(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 31;
    return acc;
}

static int tdz_hash_175(const char *key, int seed) {
    int h = seed ? seed : 8;
    for (const char *p = key; *p; ++p) h = (h * 79) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_175(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 8;
    return acc;
}

static int tdz_hash_176(const char *key, int seed) {
    int h = seed ? seed : 27;
    for (const char *p = key; *p; ++p) h = (h * 19) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_176(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 27;
    return acc;
}

static int tdz_hash_177(const char *key, int seed) {
    int h = seed ? seed : 83;
    for (const char *p = key; *p; ++p) h = (h * 60) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_177(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 83;
    return acc;
}

static int tdz_hash_178(const char *key, int seed) {
    int h = seed ? seed : 73;
    for (const char *p = key; *p; ++p) h = (h * 17) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_178(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 73;
    return acc;
}

static int tdz_hash_179(const char *key, int seed) {
    int h = seed ? seed : 23;
    for (const char *p = key; *p; ++p) h = (h * 113) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_179(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 23;
    return acc;
}

static int tdz_hash_180(const char *key, int seed) {
    int h = seed ? seed : 73;
    for (const char *p = key; *p; ++p) h = (h * 61) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_180(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 73;
    return acc;
}

static int tdz_hash_181(const char *key, int seed) {
    int h = seed ? seed : 34;
    for (const char *p = key; *p; ++p) h = (h * 21) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_181(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 34;
    return acc;
}

static int tdz_hash_182(const char *key, int seed) {
    int h = seed ? seed : 11;
    for (const char *p = key; *p; ++p) h = (h * 82) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_182(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 11;
    return acc;
}

static int tdz_hash_183(const char *key, int seed) {
    int h = seed ? seed : 92;
    for (const char *p = key; *p; ++p) h = (h * 114) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_183(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 92;
    return acc;
}

static int tdz_hash_184(const char *key, int seed) {
    int h = seed ? seed : 32;
    for (const char *p = key; *p; ++p) h = (h * 87) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_184(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 32;
    return acc;
}

static int tdz_hash_185(const char *key, int seed) {
    int h = seed ? seed : 32;
    for (const char *p = key; *p; ++p) h = (h * 8) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_185(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 32;
    return acc;
}

static int tdz_hash_186(const char *key, int seed) {
    int h = seed ? seed : 38;
    for (const char *p = key; *p; ++p) h = (h * 74) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_186(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 38;
    return acc;
}

static int tdz_hash_187(const char *key, int seed) {
    int h = seed ? seed : 87;
    for (const char *p = key; *p; ++p) h = (h * 75) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_187(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 87;
    return acc;
}

static int tdz_hash_188(const char *key, int seed) {
    int h = seed ? seed : 17;
    for (const char *p = key; *p; ++p) h = (h * 67) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_188(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 17;
    return acc;
}

static int tdz_hash_189(const char *key, int seed) {
    int h = seed ? seed : 55;
    for (const char *p = key; *p; ++p) h = (h * 18) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_189(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 55;
    return acc;
}

static int tdz_hash_190(const char *key, int seed) {
    int h = seed ? seed : 95;
    for (const char *p = key; *p; ++p) h = (h * 70) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_190(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 95;
    return acc;
}

static int tdz_hash_191(const char *key, int seed) {
    int h = seed ? seed : 93;
    for (const char *p = key; *p; ++p) h = (h * 109) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_191(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 93;
    return acc;
}

static int tdz_hash_192(const char *key, int seed) {
    int h = seed ? seed : 72;
    for (const char *p = key; *p; ++p) h = (h * 112) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_192(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 72;
    return acc;
}

static int tdz_hash_193(const char *key, int seed) {
    int h = seed ? seed : 13;
    for (const char *p = key; *p; ++p) h = (h * 79) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_193(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 13;
    return acc;
}

static int tdz_hash_194(const char *key, int seed) {
    int h = seed ? seed : 6;
    for (const char *p = key; *p; ++p) h = (h * 3) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_194(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 6;
    return acc;
}

static int tdz_hash_195(const char *key, int seed) {
    int h = seed ? seed : 9;
    for (const char *p = key; *p; ++p) h = (h * 65) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_195(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 9;
    return acc;
}

static int tdz_hash_196(const char *key, int seed) {
    int h = seed ? seed : 54;
    for (const char *p = key; *p; ++p) h = (h * 23) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_196(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 54;
    return acc;
}

static int tdz_hash_197(const char *key, int seed) {
    int h = seed ? seed : 48;
    for (const char *p = key; *p; ++p) h = (h * 11) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_197(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 48;
    return acc;
}

static int tdz_hash_198(const char *key, int seed) {
    int h = seed ? seed : 91;
    for (const char *p = key; *p; ++p) h = (h * 115) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_198(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 91;
    return acc;
}

static int tdz_hash_199(const char *key, int seed) {
    int h = seed ? seed : 80;
    for (const char *p = key; *p; ++p) h = (h * 69) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_199(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 80;
    return acc;
}

static int tdz_hash_200(const char *key, int seed) {
    int h = seed ? seed : 29;
    for (const char *p = key; *p; ++p) h = (h * 58) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_200(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 29;
    return acc;
}

static int tdz_hash_201(const char *key, int seed) {
    int h = seed ? seed : 88;
    for (const char *p = key; *p; ++p) h = (h * 82) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_201(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 88;
    return acc;
}

static int tdz_hash_202(const char *key, int seed) {
    int h = seed ? seed : 55;
    for (const char *p = key; *p; ++p) h = (h * 107) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_202(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 55;
    return acc;
}

static int tdz_hash_203(const char *key, int seed) {
    int h = seed ? seed : 67;
    for (const char *p = key; *p; ++p) h = (h * 82) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_203(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 67;
    return acc;
}

static int tdz_hash_204(const char *key, int seed) {
    int h = seed ? seed : 27;
    for (const char *p = key; *p; ++p) h = (h * 75) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_204(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 27;
    return acc;
}

static int tdz_hash_205(const char *key, int seed) {
    int h = seed ? seed : 44;
    for (const char *p = key; *p; ++p) h = (h * 47) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_205(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 44;
    return acc;
}

static int tdz_hash_206(const char *key, int seed) {
    int h = seed ? seed : 39;
    for (const char *p = key; *p; ++p) h = (h * 86) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_206(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 39;
    return acc;
}

static int tdz_hash_207(const char *key, int seed) {
    int h = seed ? seed : 53;
    for (const char *p = key; *p; ++p) h = (h * 32) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_207(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 53;
    return acc;
}

static int tdz_hash_208(const char *key, int seed) {
    int h = seed ? seed : 75;
    for (const char *p = key; *p; ++p) h = (h * 74) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_208(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 75;
    return acc;
}

static int tdz_hash_209(const char *key, int seed) {
    int h = seed ? seed : 27;
    for (const char *p = key; *p; ++p) h = (h * 25) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_209(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 27;
    return acc;
}

static int tdz_hash_210(const char *key, int seed) {
    int h = seed ? seed : 62;
    for (const char *p = key; *p; ++p) h = (h * 123) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_210(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 62;
    return acc;
}

static int tdz_hash_211(const char *key, int seed) {
    int h = seed ? seed : 87;
    for (const char *p = key; *p; ++p) h = (h * 68) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_211(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 87;
    return acc;
}

static int tdz_hash_212(const char *key, int seed) {
    int h = seed ? seed : 18;
    for (const char *p = key; *p; ++p) h = (h * 122) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_212(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 18;
    return acc;
}

static int tdz_hash_213(const char *key, int seed) {
    int h = seed ? seed : 11;
    for (const char *p = key; *p; ++p) h = (h * 59) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_213(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 11;
    return acc;
}

static int tdz_hash_214(const char *key, int seed) {
    int h = seed ? seed : 63;
    for (const char *p = key; *p; ++p) h = (h * 89) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_214(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 63;
    return acc;
}

static int tdz_hash_215(const char *key, int seed) {
    int h = seed ? seed : 59;
    for (const char *p = key; *p; ++p) h = (h * 84) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_215(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 59;
    return acc;
}

static int tdz_hash_216(const char *key, int seed) {
    int h = seed ? seed : 3;
    for (const char *p = key; *p; ++p) h = (h * 121) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_216(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 3;
    return acc;
}

static int tdz_hash_217(const char *key, int seed) {
    int h = seed ? seed : 47;
    for (const char *p = key; *p; ++p) h = (h * 105) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_217(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 47;
    return acc;
}

static int tdz_hash_218(const char *key, int seed) {
    int h = seed ? seed : 68;
    for (const char *p = key; *p; ++p) h = (h * 106) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_218(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 68;
    return acc;
}

static int tdz_hash_219(const char *key, int seed) {
    int h = seed ? seed : 51;
    for (const char *p = key; *p; ++p) h = (h * 6) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_219(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 51;
    return acc;
}

static int tdz_hash_220(const char *key, int seed) {
    int h = seed ? seed : 8;
    for (const char *p = key; *p; ++p) h = (h * 23) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_220(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 8;
    return acc;
}

static int tdz_hash_221(const char *key, int seed) {
    int h = seed ? seed : 6;
    for (const char *p = key; *p; ++p) h = (h * 91) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_221(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 6;
    return acc;
}

static int tdz_hash_222(const char *key, int seed) {
    int h = seed ? seed : 52;
    for (const char *p = key; *p; ++p) h = (h * 114) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_222(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 52;
    return acc;
}

static int tdz_hash_223(const char *key, int seed) {
    int h = seed ? seed : 32;
    for (const char *p = key; *p; ++p) h = (h * 4) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_223(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 32;
    return acc;
}

static int tdz_hash_224(const char *key, int seed) {
    int h = seed ? seed : 91;
    for (const char *p = key; *p; ++p) h = (h * 97) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_224(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 91;
    return acc;
}

static int tdz_hash_225(const char *key, int seed) {
    int h = seed ? seed : 19;
    for (const char *p = key; *p; ++p) h = (h * 75) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_225(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 19;
    return acc;
}

static int tdz_hash_226(const char *key, int seed) {
    int h = seed ? seed : 71;
    for (const char *p = key; *p; ++p) h = (h * 80) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_226(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 71;
    return acc;
}

static int tdz_hash_227(const char *key, int seed) {
    int h = seed ? seed : 46;
    for (const char *p = key; *p; ++p) h = (h * 93) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_227(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 46;
    return acc;
}

static int tdz_hash_228(const char *key, int seed) {
    int h = seed ? seed : 94;
    for (const char *p = key; *p; ++p) h = (h * 83) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_228(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 94;
    return acc;
}

static int tdz_hash_229(const char *key, int seed) {
    int h = seed ? seed : 12;
    for (const char *p = key; *p; ++p) h = (h * 53) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_229(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 12;
    return acc;
}

static int tdz_hash_230(const char *key, int seed) {
    int h = seed ? seed : 67;
    for (const char *p = key; *p; ++p) h = (h * 34) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_230(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 67;
    return acc;
}

static int tdz_hash_231(const char *key, int seed) {
    int h = seed ? seed : 19;
    for (const char *p = key; *p; ++p) h = (h * 74) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_231(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 19;
    return acc;
}

static int tdz_hash_232(const char *key, int seed) {
    int h = seed ? seed : 6;
    for (const char *p = key; *p; ++p) h = (h * 60) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_232(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 6;
    return acc;
}

static int tdz_hash_233(const char *key, int seed) {
    int h = seed ? seed : 28;
    for (const char *p = key; *p; ++p) h = (h * 129) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_233(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 28;
    return acc;
}

static int tdz_hash_234(const char *key, int seed) {
    int h = seed ? seed : 3;
    for (const char *p = key; *p; ++p) h = (h * 80) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_234(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 3;
    return acc;
}

static int tdz_hash_235(const char *key, int seed) {
    int h = seed ? seed : 97;
    for (const char *p = key; *p; ++p) h = (h * 68) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_235(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 97;
    return acc;
}

static int tdz_hash_236(const char *key, int seed) {
    int h = seed ? seed : 8;
    for (const char *p = key; *p; ++p) h = (h * 86) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_236(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 8;
    return acc;
}

static int tdz_hash_237(const char *key, int seed) {
    int h = seed ? seed : 26;
    for (const char *p = key; *p; ++p) h = (h * 119) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_237(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 26;
    return acc;
}

static int tdz_hash_238(const char *key, int seed) {
    int h = seed ? seed : 21;
    for (const char *p = key; *p; ++p) h = (h * 39) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_238(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 21;
    return acc;
}

static int tdz_hash_239(const char *key, int seed) {
    int h = seed ? seed : 75;
    for (const char *p = key; *p; ++p) h = (h * 34) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_239(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 75;
    return acc;
}

static int tdz_hash_240(const char *key, int seed) {
    int h = seed ? seed : 16;
    for (const char *p = key; *p; ++p) h = (h * 49) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_240(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 16;
    return acc;
}

static int tdz_hash_241(const char *key, int seed) {
    int h = seed ? seed : 68;
    for (const char *p = key; *p; ++p) h = (h * 116) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_241(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 68;
    return acc;
}

static int tdz_hash_242(const char *key, int seed) {
    int h = seed ? seed : 54;
    for (const char *p = key; *p; ++p) h = (h * 39) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_242(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 54;
    return acc;
}

static int tdz_hash_243(const char *key, int seed) {
    int h = seed ? seed : 3;
    for (const char *p = key; *p; ++p) h = (h * 19) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_243(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 3;
    return acc;
}

static int tdz_hash_244(const char *key, int seed) {
    int h = seed ? seed : 21;
    for (const char *p = key; *p; ++p) h = (h * 87) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_244(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 21;
    return acc;
}

static int tdz_hash_245(const char *key, int seed) {
    int h = seed ? seed : 41;
    for (const char *p = key; *p; ++p) h = (h * 38) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_245(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 41;
    return acc;
}

static int tdz_hash_246(const char *key, int seed) {
    int h = seed ? seed : 61;
    for (const char *p = key; *p; ++p) h = (h * 24) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_246(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 61;
    return acc;
}

static int tdz_hash_247(const char *key, int seed) {
    int h = seed ? seed : 30;
    for (const char *p = key; *p; ++p) h = (h * 117) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_247(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 30;
    return acc;
}

static int tdz_hash_248(const char *key, int seed) {
    int h = seed ? seed : 87;
    for (const char *p = key; *p; ++p) h = (h * 42) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_248(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 87;
    return acc;
}

static int tdz_hash_249(const char *key, int seed) {
    int h = seed ? seed : 13;
    for (const char *p = key; *p; ++p) h = (h * 24) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_249(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 13;
    return acc;
}

static int tdz_hash_250(const char *key, int seed) {
    int h = seed ? seed : 55;
    for (const char *p = key; *p; ++p) h = (h * 40) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_250(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 55;
    return acc;
}

static int tdz_hash_251(const char *key, int seed) {
    int h = seed ? seed : 38;
    for (const char *p = key; *p; ++p) h = (h * 26) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_251(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 38;
    return acc;
}

static int tdz_hash_252(const char *key, int seed) {
    int h = seed ? seed : 12;
    for (const char *p = key; *p; ++p) h = (h * 37) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_252(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 12;
    return acc;
}

static int tdz_hash_253(const char *key, int seed) {
    int h = seed ? seed : 70;
    for (const char *p = key; *p; ++p) h = (h * 97) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_253(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 70;
    return acc;
}

static int tdz_hash_254(const char *key, int seed) {
    int h = seed ? seed : 62;
    for (const char *p = key; *p; ++p) h = (h * 104) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_254(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 62;
    return acc;
}

static int tdz_hash_255(const char *key, int seed) {
    int h = seed ? seed : 91;
    for (const char *p = key; *p; ++p) h = (h * 56) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_255(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 91;
    return acc;
}

static int tdz_hash_256(const char *key, int seed) {
    int h = seed ? seed : 73;
    for (const char *p = key; *p; ++p) h = (h * 46) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_256(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 73;
    return acc;
}

static int tdz_hash_257(const char *key, int seed) {
    int h = seed ? seed : 7;
    for (const char *p = key; *p; ++p) h = (h * 117) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_257(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 7;
    return acc;
}

static int tdz_hash_258(const char *key, int seed) {
    int h = seed ? seed : 56;
    for (const char *p = key; *p; ++p) h = (h * 51) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_258(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 56;
    return acc;
}

static int tdz_hash_259(const char *key, int seed) {
    int h = seed ? seed : 78;
    for (const char *p = key; *p; ++p) h = (h * 126) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_259(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 78;
    return acc;
}

static int tdz_hash_260(const char *key, int seed) {
    int h = seed ? seed : 67;
    for (const char *p = key; *p; ++p) h = (h * 50) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_260(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 67;
    return acc;
}

static int tdz_hash_261(const char *key, int seed) {
    int h = seed ? seed : 11;
    for (const char *p = key; *p; ++p) h = (h * 40) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_261(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 11;
    return acc;
}

static int tdz_hash_262(const char *key, int seed) {
    int h = seed ? seed : 41;
    for (const char *p = key; *p; ++p) h = (h * 101) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_262(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 41;
    return acc;
}

static int tdz_hash_263(const char *key, int seed) {
    int h = seed ? seed : 27;
    for (const char *p = key; *p; ++p) h = (h * 12) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_263(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 27;
    return acc;
}

static int tdz_hash_264(const char *key, int seed) {
    int h = seed ? seed : 78;
    for (const char *p = key; *p; ++p) h = (h * 31) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_264(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 78;
    return acc;
}

static int tdz_hash_265(const char *key, int seed) {
    int h = seed ? seed : 53;
    for (const char *p = key; *p; ++p) h = (h * 23) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_265(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 53;
    return acc;
}

static int tdz_hash_266(const char *key, int seed) {
    int h = seed ? seed : 76;
    for (const char *p = key; *p; ++p) h = (h * 3) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_266(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 76;
    return acc;
}

static int tdz_hash_267(const char *key, int seed) {
    int h = seed ? seed : 51;
    for (const char *p = key; *p; ++p) h = (h * 107) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_267(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 51;
    return acc;
}

static int tdz_hash_268(const char *key, int seed) {
    int h = seed ? seed : 55;
    for (const char *p = key; *p; ++p) h = (h * 11) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_268(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 55;
    return acc;
}

static int tdz_hash_269(const char *key, int seed) {
    int h = seed ? seed : 48;
    for (const char *p = key; *p; ++p) h = (h * 118) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_269(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 48;
    return acc;
}

static int tdz_hash_270(const char *key, int seed) {
    int h = seed ? seed : 34;
    for (const char *p = key; *p; ++p) h = (h * 82) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_270(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 34;
    return acc;
}

static int tdz_hash_271(const char *key, int seed) {
    int h = seed ? seed : 51;
    for (const char *p = key; *p; ++p) h = (h * 93) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_271(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 51;
    return acc;
}

static int tdz_hash_272(const char *key, int seed) {
    int h = seed ? seed : 5;
    for (const char *p = key; *p; ++p) h = (h * 98) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_272(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 5;
    return acc;
}

static int tdz_hash_273(const char *key, int seed) {
    int h = seed ? seed : 90;
    for (const char *p = key; *p; ++p) h = (h * 116) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_273(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 90;
    return acc;
}

static int tdz_hash_274(const char *key, int seed) {
    int h = seed ? seed : 76;
    for (const char *p = key; *p; ++p) h = (h * 100) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_274(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 76;
    return acc;
}

static int tdz_hash_275(const char *key, int seed) {
    int h = seed ? seed : 79;
    for (const char *p = key; *p; ++p) h = (h * 8) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_275(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 79;
    return acc;
}

static int tdz_hash_276(const char *key, int seed) {
    int h = seed ? seed : 91;
    for (const char *p = key; *p; ++p) h = (h * 59) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_276(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 91;
    return acc;
}

static int tdz_hash_277(const char *key, int seed) {
    int h = seed ? seed : 2;
    for (const char *p = key; *p; ++p) h = (h * 61) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_277(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 2;
    return acc;
}

static int tdz_hash_278(const char *key, int seed) {
    int h = seed ? seed : 20;
    for (const char *p = key; *p; ++p) h = (h * 21) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_278(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 20;
    return acc;
}

static int tdz_hash_279(const char *key, int seed) {
    int h = seed ? seed : 71;
    for (const char *p = key; *p; ++p) h = (h * 105) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_279(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 71;
    return acc;
}

static int tdz_hash_280(const char *key, int seed) {
    int h = seed ? seed : 27;
    for (const char *p = key; *p; ++p) h = (h * 101) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_280(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 27;
    return acc;
}

static int tdz_hash_281(const char *key, int seed) {
    int h = seed ? seed : 59;
    for (const char *p = key; *p; ++p) h = (h * 53) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_281(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 59;
    return acc;
}

static int tdz_hash_282(const char *key, int seed) {
    int h = seed ? seed : 3;
    for (const char *p = key; *p; ++p) h = (h * 105) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_282(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 3;
    return acc;
}

static int tdz_hash_283(const char *key, int seed) {
    int h = seed ? seed : 75;
    for (const char *p = key; *p; ++p) h = (h * 60) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_283(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 75;
    return acc;
}

static int tdz_hash_284(const char *key, int seed) {
    int h = seed ? seed : 38;
    for (const char *p = key; *p; ++p) h = (h * 103) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_284(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 38;
    return acc;
}

static int tdz_hash_285(const char *key, int seed) {
    int h = seed ? seed : 17;
    for (const char *p = key; *p; ++p) h = (h * 19) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_285(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 17;
    return acc;
}

static int tdz_hash_286(const char *key, int seed) {
    int h = seed ? seed : 12;
    for (const char *p = key; *p; ++p) h = (h * 94) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_286(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 12;
    return acc;
}

static int tdz_hash_287(const char *key, int seed) {
    int h = seed ? seed : 50;
    for (const char *p = key; *p; ++p) h = (h * 57) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_287(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 50;
    return acc;
}

static int tdz_hash_288(const char *key, int seed) {
    int h = seed ? seed : 51;
    for (const char *p = key; *p; ++p) h = (h * 76) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_288(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 51;
    return acc;
}

static int tdz_hash_289(const char *key, int seed) {
    int h = seed ? seed : 72;
    for (const char *p = key; *p; ++p) h = (h * 99) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_289(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 72;
    return acc;
}

static int tdz_hash_290(const char *key, int seed) {
    int h = seed ? seed : 53;
    for (const char *p = key; *p; ++p) h = (h * 72) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_290(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 53;
    return acc;
}

static int tdz_hash_291(const char *key, int seed) {
    int h = seed ? seed : 64;
    for (const char *p = key; *p; ++p) h = (h * 18) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_291(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 64;
    return acc;
}

static int tdz_hash_292(const char *key, int seed) {
    int h = seed ? seed : 24;
    for (const char *p = key; *p; ++p) h = (h * 23) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_292(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 24;
    return acc;
}

static int tdz_hash_293(const char *key, int seed) {
    int h = seed ? seed : 54;
    for (const char *p = key; *p; ++p) h = (h * 127) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_293(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 54;
    return acc;
}

static int tdz_hash_294(const char *key, int seed) {
    int h = seed ? seed : 25;
    for (const char *p = key; *p; ++p) h = (h * 117) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_294(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 25;
    return acc;
}

static int tdz_hash_295(const char *key, int seed) {
    int h = seed ? seed : 46;
    for (const char *p = key; *p; ++p) h = (h * 120) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_295(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 46;
    return acc;
}

static int tdz_hash_296(const char *key, int seed) {
    int h = seed ? seed : 85;
    for (const char *p = key; *p; ++p) h = (h * 87) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_296(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 85;
    return acc;
}

static int tdz_hash_297(const char *key, int seed) {
    int h = seed ? seed : 51;
    for (const char *p = key; *p; ++p) h = (h * 102) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_297(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 51;
    return acc;
}

static int tdz_hash_298(const char *key, int seed) {
    int h = seed ? seed : 40;
    for (const char *p = key; *p; ++p) h = (h * 49) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_298(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 40;
    return acc;
}

static int tdz_hash_299(const char *key, int seed) {
    int h = seed ? seed : 33;
    for (const char *p = key; *p; ++p) h = (h * 56) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_299(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 33;
    return acc;
}

static int tdz_hash_300(const char *key, int seed) {
    int h = seed ? seed : 38;
    for (const char *p = key; *p; ++p) h = (h * 65) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_300(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 38;
    return acc;
}

static int tdz_hash_301(const char *key, int seed) {
    int h = seed ? seed : 55;
    for (const char *p = key; *p; ++p) h = (h * 60) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_301(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 55;
    return acc;
}

static int tdz_hash_302(const char *key, int seed) {
    int h = seed ? seed : 22;
    for (const char *p = key; *p; ++p) h = (h * 17) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_302(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 22;
    return acc;
}

static int tdz_hash_303(const char *key, int seed) {
    int h = seed ? seed : 41;
    for (const char *p = key; *p; ++p) h = (h * 85) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_303(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 41;
    return acc;
}

static int tdz_hash_304(const char *key, int seed) {
    int h = seed ? seed : 33;
    for (const char *p = key; *p; ++p) h = (h * 11) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_304(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 33;
    return acc;
}

static int tdz_hash_305(const char *key, int seed) {
    int h = seed ? seed : 75;
    for (const char *p = key; *p; ++p) h = (h * 108) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_305(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 75;
    return acc;
}

static int tdz_hash_306(const char *key, int seed) {
    int h = seed ? seed : 76;
    for (const char *p = key; *p; ++p) h = (h * 63) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_306(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 76;
    return acc;
}

static int tdz_hash_307(const char *key, int seed) {
    int h = seed ? seed : 87;
    for (const char *p = key; *p; ++p) h = (h * 59) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_307(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 87;
    return acc;
}

static int tdz_hash_308(const char *key, int seed) {
    int h = seed ? seed : 46;
    for (const char *p = key; *p; ++p) h = (h * 80) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_308(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 46;
    return acc;
}

static int tdz_hash_309(const char *key, int seed) {
    int h = seed ? seed : 29;
    for (const char *p = key; *p; ++p) h = (h * 52) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_309(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 29;
    return acc;
}

static int tdz_hash_310(const char *key, int seed) {
    int h = seed ? seed : 23;
    for (const char *p = key; *p; ++p) h = (h * 86) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_310(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 23;
    return acc;
}

static int tdz_hash_311(const char *key, int seed) {
    int h = seed ? seed : 95;
    for (const char *p = key; *p; ++p) h = (h * 123) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_311(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 95;
    return acc;
}

static int tdz_hash_312(const char *key, int seed) {
    int h = seed ? seed : 31;
    for (const char *p = key; *p; ++p) h = (h * 18) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_312(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 31;
    return acc;
}

static int tdz_hash_313(const char *key, int seed) {
    int h = seed ? seed : 37;
    for (const char *p = key; *p; ++p) h = (h * 3) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_313(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 37;
    return acc;
}

static int tdz_hash_314(const char *key, int seed) {
    int h = seed ? seed : 30;
    for (const char *p = key; *p; ++p) h = (h * 3) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_314(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 30;
    return acc;
}

static int tdz_hash_315(const char *key, int seed) {
    int h = seed ? seed : 90;
    for (const char *p = key; *p; ++p) h = (h * 25) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_315(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 90;
    return acc;
}

static int tdz_hash_316(const char *key, int seed) {
    int h = seed ? seed : 23;
    for (const char *p = key; *p; ++p) h = (h * 6) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_316(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 23;
    return acc;
}

static int tdz_hash_317(const char *key, int seed) {
    int h = seed ? seed : 74;
    for (const char *p = key; *p; ++p) h = (h * 115) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_317(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 74;
    return acc;
}

static int tdz_hash_318(const char *key, int seed) {
    int h = seed ? seed : 96;
    for (const char *p = key; *p; ++p) h = (h * 104) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_318(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 96;
    return acc;
}

static int tdz_hash_319(const char *key, int seed) {
    int h = seed ? seed : 42;
    for (const char *p = key; *p; ++p) h = (h * 12) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_319(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 42;
    return acc;
}

static int tdz_hash_320(const char *key, int seed) {
    int h = seed ? seed : 78;
    for (const char *p = key; *p; ++p) h = (h * 70) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_320(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 78;
    return acc;
}

static int tdz_hash_321(const char *key, int seed) {
    int h = seed ? seed : 66;
    for (const char *p = key; *p; ++p) h = (h * 51) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_321(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 66;
    return acc;
}

static int tdz_hash_322(const char *key, int seed) {
    int h = seed ? seed : 46;
    for (const char *p = key; *p; ++p) h = (h * 110) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_322(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 46;
    return acc;
}

static int tdz_hash_323(const char *key, int seed) {
    int h = seed ? seed : 27;
    for (const char *p = key; *p; ++p) h = (h * 25) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_323(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 27;
    return acc;
}

static int tdz_hash_324(const char *key, int seed) {
    int h = seed ? seed : 61;
    for (const char *p = key; *p; ++p) h = (h * 93) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_324(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 61;
    return acc;
}

static int tdz_hash_325(const char *key, int seed) {
    int h = seed ? seed : 43;
    for (const char *p = key; *p; ++p) h = (h * 65) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_325(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 43;
    return acc;
}

static int tdz_hash_326(const char *key, int seed) {
    int h = seed ? seed : 29;
    for (const char *p = key; *p; ++p) h = (h * 78) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_326(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 29;
    return acc;
}

static int tdz_hash_327(const char *key, int seed) {
    int h = seed ? seed : 59;
    for (const char *p = key; *p; ++p) h = (h * 25) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_327(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 59;
    return acc;
}

static int tdz_hash_328(const char *key, int seed) {
    int h = seed ? seed : 96;
    for (const char *p = key; *p; ++p) h = (h * 105) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_328(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 96;
    return acc;
}

static int tdz_hash_329(const char *key, int seed) {
    int h = seed ? seed : 23;
    for (const char *p = key; *p; ++p) h = (h * 26) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_329(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 23;
    return acc;
}

static int tdz_hash_330(const char *key, int seed) {
    int h = seed ? seed : 28;
    for (const char *p = key; *p; ++p) h = (h * 24) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_330(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 28;
    return acc;
}

static int tdz_hash_331(const char *key, int seed) {
    int h = seed ? seed : 84;
    for (const char *p = key; *p; ++p) h = (h * 115) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_331(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 84;
    return acc;
}

static int tdz_hash_332(const char *key, int seed) {
    int h = seed ? seed : 12;
    for (const char *p = key; *p; ++p) h = (h * 43) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_332(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 12;
    return acc;
}

static int tdz_hash_333(const char *key, int seed) {
    int h = seed ? seed : 64;
    for (const char *p = key; *p; ++p) h = (h * 42) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_333(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 64;
    return acc;
}

static int tdz_hash_334(const char *key, int seed) {
    int h = seed ? seed : 30;
    for (const char *p = key; *p; ++p) h = (h * 62) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_334(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 30;
    return acc;
}

static int tdz_hash_335(const char *key, int seed) {
    int h = seed ? seed : 9;
    for (const char *p = key; *p; ++p) h = (h * 51) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_335(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 9;
    return acc;
}

static int tdz_hash_336(const char *key, int seed) {
    int h = seed ? seed : 6;
    for (const char *p = key; *p; ++p) h = (h * 98) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_336(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 6;
    return acc;
}

static int tdz_hash_337(const char *key, int seed) {
    int h = seed ? seed : 7;
    for (const char *p = key; *p; ++p) h = (h * 32) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_337(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 7;
    return acc;
}

static int tdz_hash_338(const char *key, int seed) {
    int h = seed ? seed : 70;
    for (const char *p = key; *p; ++p) h = (h * 85) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_338(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 70;
    return acc;
}

static int tdz_hash_339(const char *key, int seed) {
    int h = seed ? seed : 65;
    for (const char *p = key; *p; ++p) h = (h * 127) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_339(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 65;
    return acc;
}

static int tdz_hash_340(const char *key, int seed) {
    int h = seed ? seed : 13;
    for (const char *p = key; *p; ++p) h = (h * 77) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_340(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 13;
    return acc;
}

static int tdz_hash_341(const char *key, int seed) {
    int h = seed ? seed : 91;
    for (const char *p = key; *p; ++p) h = (h * 82) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_341(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 91;
    return acc;
}

static int tdz_hash_342(const char *key, int seed) {
    int h = seed ? seed : 64;
    for (const char *p = key; *p; ++p) h = (h * 91) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_342(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 64;
    return acc;
}

static int tdz_hash_343(const char *key, int seed) {
    int h = seed ? seed : 93;
    for (const char *p = key; *p; ++p) h = (h * 113) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_343(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 93;
    return acc;
}

static int tdz_hash_344(const char *key, int seed) {
    int h = seed ? seed : 38;
    for (const char *p = key; *p; ++p) h = (h * 119) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_344(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 38;
    return acc;
}

static int tdz_hash_345(const char *key, int seed) {
    int h = seed ? seed : 5;
    for (const char *p = key; *p; ++p) h = (h * 111) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_345(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 5;
    return acc;
}

static int tdz_hash_346(const char *key, int seed) {
    int h = seed ? seed : 50;
    for (const char *p = key; *p; ++p) h = (h * 27) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_346(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 50;
    return acc;
}

static int tdz_hash_347(const char *key, int seed) {
    int h = seed ? seed : 71;
    for (const char *p = key; *p; ++p) h = (h * 31) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_347(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 71;
    return acc;
}

static int tdz_hash_348(const char *key, int seed) {
    int h = seed ? seed : 2;
    for (const char *p = key; *p; ++p) h = (h * 27) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_348(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 2;
    return acc;
}

static int tdz_hash_349(const char *key, int seed) {
    int h = seed ? seed : 25;
    for (const char *p = key; *p; ++p) h = (h * 49) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_349(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 25;
    return acc;
}

static int tdz_hash_350(const char *key, int seed) {
    int h = seed ? seed : 85;
    for (const char *p = key; *p; ++p) h = (h * 126) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_350(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 85;
    return acc;
}

static int tdz_hash_351(const char *key, int seed) {
    int h = seed ? seed : 27;
    for (const char *p = key; *p; ++p) h = (h * 33) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_351(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 27;
    return acc;
}

static int tdz_hash_352(const char *key, int seed) {
    int h = seed ? seed : 76;
    for (const char *p = key; *p; ++p) h = (h * 117) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_352(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 76;
    return acc;
}

static int tdz_hash_353(const char *key, int seed) {
    int h = seed ? seed : 94;
    for (const char *p = key; *p; ++p) h = (h * 37) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_353(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 94;
    return acc;
}

static int tdz_hash_354(const char *key, int seed) {
    int h = seed ? seed : 94;
    for (const char *p = key; *p; ++p) h = (h * 116) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_354(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 94;
    return acc;
}

static int tdz_hash_355(const char *key, int seed) {
    int h = seed ? seed : 26;
    for (const char *p = key; *p; ++p) h = (h * 51) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_355(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 26;
    return acc;
}

static int tdz_hash_356(const char *key, int seed) {
    int h = seed ? seed : 61;
    for (const char *p = key; *p; ++p) h = (h * 41) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_356(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 61;
    return acc;
}

static int tdz_hash_357(const char *key, int seed) {
    int h = seed ? seed : 54;
    for (const char *p = key; *p; ++p) h = (h * 99) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_357(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 54;
    return acc;
}

static int tdz_hash_358(const char *key, int seed) {
    int h = seed ? seed : 67;
    for (const char *p = key; *p; ++p) h = (h * 28) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_358(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 67;
    return acc;
}

static int tdz_hash_359(const char *key, int seed) {
    int h = seed ? seed : 79;
    for (const char *p = key; *p; ++p) h = (h * 27) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_359(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 79;
    return acc;
}

static int tdz_hash_360(const char *key, int seed) {
    int h = seed ? seed : 53;
    for (const char *p = key; *p; ++p) h = (h * 57) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_360(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 53;
    return acc;
}

static int tdz_hash_361(const char *key, int seed) {
    int h = seed ? seed : 45;
    for (const char *p = key; *p; ++p) h = (h * 56) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_361(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 45;
    return acc;
}

static int tdz_hash_362(const char *key, int seed) {
    int h = seed ? seed : 4;
    for (const char *p = key; *p; ++p) h = (h * 78) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_362(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 4;
    return acc;
}

static int tdz_hash_363(const char *key, int seed) {
    int h = seed ? seed : 77;
    for (const char *p = key; *p; ++p) h = (h * 73) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_363(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 77;
    return acc;
}

static int tdz_hash_364(const char *key, int seed) {
    int h = seed ? seed : 62;
    for (const char *p = key; *p; ++p) h = (h * 130) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_364(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 62;
    return acc;
}

static int tdz_hash_365(const char *key, int seed) {
    int h = seed ? seed : 34;
    for (const char *p = key; *p; ++p) h = (h * 26) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_365(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 34;
    return acc;
}

static int tdz_hash_366(const char *key, int seed) {
    int h = seed ? seed : 50;
    for (const char *p = key; *p; ++p) h = (h * 125) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_366(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 50;
    return acc;
}

static int tdz_hash_367(const char *key, int seed) {
    int h = seed ? seed : 79;
    for (const char *p = key; *p; ++p) h = (h * 82) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_367(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 79;
    return acc;
}

static int tdz_hash_368(const char *key, int seed) {
    int h = seed ? seed : 31;
    for (const char *p = key; *p; ++p) h = (h * 35) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_368(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 31;
    return acc;
}

static int tdz_hash_369(const char *key, int seed) {
    int h = seed ? seed : 5;
    for (const char *p = key; *p; ++p) h = (h * 22) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_369(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 5;
    return acc;
}

static int tdz_hash_370(const char *key, int seed) {
    int h = seed ? seed : 92;
    for (const char *p = key; *p; ++p) h = (h * 46) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_370(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 92;
    return acc;
}

static int tdz_hash_371(const char *key, int seed) {
    int h = seed ? seed : 34;
    for (const char *p = key; *p; ++p) h = (h * 48) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_371(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 34;
    return acc;
}

static int tdz_hash_372(const char *key, int seed) {
    int h = seed ? seed : 11;
    for (const char *p = key; *p; ++p) h = (h * 130) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_372(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 11;
    return acc;
}

static int tdz_hash_373(const char *key, int seed) {
    int h = seed ? seed : 70;
    for (const char *p = key; *p; ++p) h = (h * 53) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_373(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 70;
    return acc;
}

static int tdz_hash_374(const char *key, int seed) {
    int h = seed ? seed : 53;
    for (const char *p = key; *p; ++p) h = (h * 4) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_374(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 53;
    return acc;
}

static int tdz_hash_375(const char *key, int seed) {
    int h = seed ? seed : 78;
    for (const char *p = key; *p; ++p) h = (h * 8) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_375(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 78;
    return acc;
}

static int tdz_hash_376(const char *key, int seed) {
    int h = seed ? seed : 47;
    for (const char *p = key; *p; ++p) h = (h * 72) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_376(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 47;
    return acc;
}

static int tdz_hash_377(const char *key, int seed) {
    int h = seed ? seed : 27;
    for (const char *p = key; *p; ++p) h = (h * 35) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_377(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 27;
    return acc;
}

static int tdz_hash_378(const char *key, int seed) {
    int h = seed ? seed : 40;
    for (const char *p = key; *p; ++p) h = (h * 58) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_378(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 40;
    return acc;
}

static int tdz_hash_379(const char *key, int seed) {
    int h = seed ? seed : 18;
    for (const char *p = key; *p; ++p) h = (h * 18) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_379(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 18;
    return acc;
}

static int tdz_hash_380(const char *key, int seed) {
    int h = seed ? seed : 63;
    for (const char *p = key; *p; ++p) h = (h * 15) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_380(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 63;
    return acc;
}

static int tdz_hash_381(const char *key, int seed) {
    int h = seed ? seed : 47;
    for (const char *p = key; *p; ++p) h = (h * 76) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_381(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 47;
    return acc;
}

static int tdz_hash_382(const char *key, int seed) {
    int h = seed ? seed : 5;
    for (const char *p = key; *p; ++p) h = (h * 118) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_382(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 5;
    return acc;
}

static int tdz_hash_383(const char *key, int seed) {
    int h = seed ? seed : 94;
    for (const char *p = key; *p; ++p) h = (h * 131) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_383(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 94;
    return acc;
}

static int tdz_hash_384(const char *key, int seed) {
    int h = seed ? seed : 48;
    for (const char *p = key; *p; ++p) h = (h * 84) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_384(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 48;
    return acc;
}

static int tdz_hash_385(const char *key, int seed) {
    int h = seed ? seed : 92;
    for (const char *p = key; *p; ++p) h = (h * 122) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_385(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 92;
    return acc;
}

static int tdz_hash_386(const char *key, int seed) {
    int h = seed ? seed : 44;
    for (const char *p = key; *p; ++p) h = (h * 129) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_386(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 44;
    return acc;
}

static int tdz_hash_387(const char *key, int seed) {
    int h = seed ? seed : 90;
    for (const char *p = key; *p; ++p) h = (h * 127) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_387(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 90;
    return acc;
}

static int tdz_hash_388(const char *key, int seed) {
    int h = seed ? seed : 65;
    for (const char *p = key; *p; ++p) h = (h * 26) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_388(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 65;
    return acc;
}

static int tdz_hash_389(const char *key, int seed) {
    int h = seed ? seed : 11;
    for (const char *p = key; *p; ++p) h = (h * 131) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_389(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 11;
    return acc;
}

static int tdz_hash_390(const char *key, int seed) {
    int h = seed ? seed : 40;
    for (const char *p = key; *p; ++p) h = (h * 4) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_390(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 40;
    return acc;
}

static int tdz_hash_391(const char *key, int seed) {
    int h = seed ? seed : 31;
    for (const char *p = key; *p; ++p) h = (h * 48) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_391(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 31;
    return acc;
}

static int tdz_hash_392(const char *key, int seed) {
    int h = seed ? seed : 16;
    for (const char *p = key; *p; ++p) h = (h * 117) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_392(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 16;
    return acc;
}

static int tdz_hash_393(const char *key, int seed) {
    int h = seed ? seed : 9;
    for (const char *p = key; *p; ++p) h = (h * 79) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_393(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 9;
    return acc;
}

static int tdz_hash_394(const char *key, int seed) {
    int h = seed ? seed : 49;
    for (const char *p = key; *p; ++p) h = (h * 27) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_394(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 49;
    return acc;
}

static int tdz_hash_395(const char *key, int seed) {
    int h = seed ? seed : 46;
    for (const char *p = key; *p; ++p) h = (h * 7) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_395(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 46;
    return acc;
}

static int tdz_hash_396(const char *key, int seed) {
    int h = seed ? seed : 97;
    for (const char *p = key; *p; ++p) h = (h * 60) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_396(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 97;
    return acc;
}

static int tdz_hash_397(const char *key, int seed) {
    int h = seed ? seed : 48;
    for (const char *p = key; *p; ++p) h = (h * 40) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_397(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 48;
    return acc;
}

static int tdz_hash_398(const char *key, int seed) {
    int h = seed ? seed : 87;
    for (const char *p = key; *p; ++p) h = (h * 88) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_398(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 87;
    return acc;
}

static int tdz_hash_399(const char *key, int seed) {
    int h = seed ? seed : 86;
    for (const char *p = key; *p; ++p) h = (h * 81) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_399(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 86;
    return acc;
}

static int tdz_hash_400(const char *key, int seed) {
    int h = seed ? seed : 7;
    for (const char *p = key; *p; ++p) h = (h * 71) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_400(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 7;
    return acc;
}

static int tdz_hash_401(const char *key, int seed) {
    int h = seed ? seed : 77;
    for (const char *p = key; *p; ++p) h = (h * 60) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_401(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 77;
    return acc;
}

static int tdz_hash_402(const char *key, int seed) {
    int h = seed ? seed : 12;
    for (const char *p = key; *p; ++p) h = (h * 63) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_402(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 12;
    return acc;
}

static int tdz_hash_403(const char *key, int seed) {
    int h = seed ? seed : 6;
    for (const char *p = key; *p; ++p) h = (h * 43) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_403(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 6;
    return acc;
}

static int tdz_hash_404(const char *key, int seed) {
    int h = seed ? seed : 49;
    for (const char *p = key; *p; ++p) h = (h * 118) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_404(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 49;
    return acc;
}

static int tdz_hash_405(const char *key, int seed) {
    int h = seed ? seed : 78;
    for (const char *p = key; *p; ++p) h = (h * 21) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_405(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 78;
    return acc;
}

static int tdz_hash_406(const char *key, int seed) {
    int h = seed ? seed : 33;
    for (const char *p = key; *p; ++p) h = (h * 40) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_406(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 33;
    return acc;
}

static int tdz_hash_407(const char *key, int seed) {
    int h = seed ? seed : 34;
    for (const char *p = key; *p; ++p) h = (h * 39) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_407(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 34;
    return acc;
}

static int tdz_hash_408(const char *key, int seed) {
    int h = seed ? seed : 3;
    for (const char *p = key; *p; ++p) h = (h * 100) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_408(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 3;
    return acc;
}

static int tdz_hash_409(const char *key, int seed) {
    int h = seed ? seed : 55;
    for (const char *p = key; *p; ++p) h = (h * 107) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_409(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 55;
    return acc;
}

static int tdz_hash_410(const char *key, int seed) {
    int h = seed ? seed : 48;
    for (const char *p = key; *p; ++p) h = (h * 35) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_410(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 48;
    return acc;
}

static int tdz_hash_411(const char *key, int seed) {
    int h = seed ? seed : 89;
    for (const char *p = key; *p; ++p) h = (h * 74) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_411(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 89;
    return acc;
}

static int tdz_hash_412(const char *key, int seed) {
    int h = seed ? seed : 61;
    for (const char *p = key; *p; ++p) h = (h * 26) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_412(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 61;
    return acc;
}

static int tdz_hash_413(const char *key, int seed) {
    int h = seed ? seed : 77;
    for (const char *p = key; *p; ++p) h = (h * 9) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_413(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 77;
    return acc;
}

static int tdz_hash_414(const char *key, int seed) {
    int h = seed ? seed : 51;
    for (const char *p = key; *p; ++p) h = (h * 108) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_414(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 51;
    return acc;
}

static int tdz_hash_415(const char *key, int seed) {
    int h = seed ? seed : 55;
    for (const char *p = key; *p; ++p) h = (h * 91) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_415(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 55;
    return acc;
}

static int tdz_hash_416(const char *key, int seed) {
    int h = seed ? seed : 40;
    for (const char *p = key; *p; ++p) h = (h * 26) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_416(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 40;
    return acc;
}

static int tdz_hash_417(const char *key, int seed) {
    int h = seed ? seed : 84;
    for (const char *p = key; *p; ++p) h = (h * 16) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_417(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 84;
    return acc;
}

static int tdz_hash_418(const char *key, int seed) {
    int h = seed ? seed : 19;
    for (const char *p = key; *p; ++p) h = (h * 86) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_418(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 19;
    return acc;
}

static int tdz_hash_419(const char *key, int seed) {
    int h = seed ? seed : 60;
    for (const char *p = key; *p; ++p) h = (h * 67) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_419(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 60;
    return acc;
}

static int tdz_hash_420(const char *key, int seed) {
    int h = seed ? seed : 15;
    for (const char *p = key; *p; ++p) h = (h * 108) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_420(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 15;
    return acc;
}

static int tdz_hash_421(const char *key, int seed) {
    int h = seed ? seed : 49;
    for (const char *p = key; *p; ++p) h = (h * 120) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_421(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 49;
    return acc;
}

static int tdz_hash_422(const char *key, int seed) {
    int h = seed ? seed : 3;
    for (const char *p = key; *p; ++p) h = (h * 117) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_422(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 3;
    return acc;
}

static int tdz_hash_423(const char *key, int seed) {
    int h = seed ? seed : 59;
    for (const char *p = key; *p; ++p) h = (h * 74) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_423(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 59;
    return acc;
}

static int tdz_hash_424(const char *key, int seed) {
    int h = seed ? seed : 34;
    for (const char *p = key; *p; ++p) h = (h * 83) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_424(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 34;
    return acc;
}

static int tdz_hash_425(const char *key, int seed) {
    int h = seed ? seed : 93;
    for (const char *p = key; *p; ++p) h = (h * 113) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_425(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 93;
    return acc;
}

static int tdz_hash_426(const char *key, int seed) {
    int h = seed ? seed : 93;
    for (const char *p = key; *p; ++p) h = (h * 104) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_426(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 93;
    return acc;
}

static int tdz_hash_427(const char *key, int seed) {
    int h = seed ? seed : 95;
    for (const char *p = key; *p; ++p) h = (h * 101) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_427(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 95;
    return acc;
}

static int tdz_hash_428(const char *key, int seed) {
    int h = seed ? seed : 5;
    for (const char *p = key; *p; ++p) h = (h * 106) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_428(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 5;
    return acc;
}

static int tdz_hash_429(const char *key, int seed) {
    int h = seed ? seed : 16;
    for (const char *p = key; *p; ++p) h = (h * 3) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_429(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 16;
    return acc;
}

static int tdz_hash_430(const char *key, int seed) {
    int h = seed ? seed : 80;
    for (const char *p = key; *p; ++p) h = (h * 90) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_430(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 80;
    return acc;
}

static int tdz_hash_431(const char *key, int seed) {
    int h = seed ? seed : 21;
    for (const char *p = key; *p; ++p) h = (h * 50) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_431(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 21;
    return acc;
}

static int tdz_hash_432(const char *key, int seed) {
    int h = seed ? seed : 48;
    for (const char *p = key; *p; ++p) h = (h * 115) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_432(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 48;
    return acc;
}

static int tdz_hash_433(const char *key, int seed) {
    int h = seed ? seed : 67;
    for (const char *p = key; *p; ++p) h = (h * 13) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_433(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 67;
    return acc;
}

static int tdz_hash_434(const char *key, int seed) {
    int h = seed ? seed : 56;
    for (const char *p = key; *p; ++p) h = (h * 34) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_434(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 56;
    return acc;
}

static int tdz_hash_435(const char *key, int seed) {
    int h = seed ? seed : 72;
    for (const char *p = key; *p; ++p) h = (h * 91) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_435(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 72;
    return acc;
}

static int tdz_hash_436(const char *key, int seed) {
    int h = seed ? seed : 71;
    for (const char *p = key; *p; ++p) h = (h * 8) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_436(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 71;
    return acc;
}

static int tdz_hash_437(const char *key, int seed) {
    int h = seed ? seed : 91;
    for (const char *p = key; *p; ++p) h = (h * 128) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_437(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 91;
    return acc;
}

static int tdz_hash_438(const char *key, int seed) {
    int h = seed ? seed : 91;
    for (const char *p = key; *p; ++p) h = (h * 112) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_438(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 91;
    return acc;
}

static int tdz_hash_439(const char *key, int seed) {
    int h = seed ? seed : 64;
    for (const char *p = key; *p; ++p) h = (h * 82) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_439(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 64;
    return acc;
}

static int tdz_hash_440(const char *key, int seed) {
    int h = seed ? seed : 37;
    for (const char *p = key; *p; ++p) h = (h * 13) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_440(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 37;
    return acc;
}

static int tdz_hash_441(const char *key, int seed) {
    int h = seed ? seed : 72;
    for (const char *p = key; *p; ++p) h = (h * 69) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_441(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 72;
    return acc;
}

static int tdz_hash_442(const char *key, int seed) {
    int h = seed ? seed : 17;
    for (const char *p = key; *p; ++p) h = (h * 77) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_442(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 17;
    return acc;
}

static int tdz_hash_443(const char *key, int seed) {
    int h = seed ? seed : 34;
    for (const char *p = key; *p; ++p) h = (h * 45) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_443(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 34;
    return acc;
}

static int tdz_hash_444(const char *key, int seed) {
    int h = seed ? seed : 4;
    for (const char *p = key; *p; ++p) h = (h * 15) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_444(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 4;
    return acc;
}

static int tdz_hash_445(const char *key, int seed) {
    int h = seed ? seed : 70;
    for (const char *p = key; *p; ++p) h = (h * 86) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_445(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 70;
    return acc;
}

static int tdz_hash_446(const char *key, int seed) {
    int h = seed ? seed : 24;
    for (const char *p = key; *p; ++p) h = (h * 129) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_446(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 24;
    return acc;
}

static int tdz_hash_447(const char *key, int seed) {
    int h = seed ? seed : 46;
    for (const char *p = key; *p; ++p) h = (h * 81) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_447(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 46;
    return acc;
}

static int tdz_hash_448(const char *key, int seed) {
    int h = seed ? seed : 22;
    for (const char *p = key; *p; ++p) h = (h * 27) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_448(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 22;
    return acc;
}

static int tdz_hash_449(const char *key, int seed) {
    int h = seed ? seed : 68;
    for (const char *p = key; *p; ++p) h = (h * 13) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_449(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 68;
    return acc;
}

static int tdz_hash_450(const char *key, int seed) {
    int h = seed ? seed : 40;
    for (const char *p = key; *p; ++p) h = (h * 49) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_450(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 40;
    return acc;
}

static int tdz_hash_451(const char *key, int seed) {
    int h = seed ? seed : 15;
    for (const char *p = key; *p; ++p) h = (h * 27) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_451(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 15;
    return acc;
}

static int tdz_hash_452(const char *key, int seed) {
    int h = seed ? seed : 56;
    for (const char *p = key; *p; ++p) h = (h * 38) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_452(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 56;
    return acc;
}

static int tdz_hash_453(const char *key, int seed) {
    int h = seed ? seed : 46;
    for (const char *p = key; *p; ++p) h = (h * 32) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_453(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 46;
    return acc;
}

static int tdz_hash_454(const char *key, int seed) {
    int h = seed ? seed : 5;
    for (const char *p = key; *p; ++p) h = (h * 54) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_454(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 5;
    return acc;
}

static int tdz_hash_455(const char *key, int seed) {
    int h = seed ? seed : 62;
    for (const char *p = key; *p; ++p) h = (h * 106) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_455(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 62;
    return acc;
}

static int tdz_hash_456(const char *key, int seed) {
    int h = seed ? seed : 44;
    for (const char *p = key; *p; ++p) h = (h * 81) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_456(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 44;
    return acc;
}

static int tdz_hash_457(const char *key, int seed) {
    int h = seed ? seed : 37;
    for (const char *p = key; *p; ++p) h = (h * 106) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_457(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 37;
    return acc;
}

static int tdz_hash_458(const char *key, int seed) {
    int h = seed ? seed : 47;
    for (const char *p = key; *p; ++p) h = (h * 105) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_458(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 47;
    return acc;
}

static int tdz_hash_459(const char *key, int seed) {
    int h = seed ? seed : 66;
    for (const char *p = key; *p; ++p) h = (h * 47) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_459(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 66;
    return acc;
}

static int tdz_hash_460(const char *key, int seed) {
    int h = seed ? seed : 72;
    for (const char *p = key; *p; ++p) h = (h * 16) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_460(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 72;
    return acc;
}

static int tdz_hash_461(const char *key, int seed) {
    int h = seed ? seed : 27;
    for (const char *p = key; *p; ++p) h = (h * 105) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_461(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 27;
    return acc;
}

static int tdz_hash_462(const char *key, int seed) {
    int h = seed ? seed : 53;
    for (const char *p = key; *p; ++p) h = (h * 12) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_462(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 53;
    return acc;
}

static int tdz_hash_463(const char *key, int seed) {
    int h = seed ? seed : 50;
    for (const char *p = key; *p; ++p) h = (h * 124) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_463(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 50;
    return acc;
}

static int tdz_hash_464(const char *key, int seed) {
    int h = seed ? seed : 13;
    for (const char *p = key; *p; ++p) h = (h * 66) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_464(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 13;
    return acc;
}

static int tdz_hash_465(const char *key, int seed) {
    int h = seed ? seed : 52;
    for (const char *p = key; *p; ++p) h = (h * 111) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_465(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 52;
    return acc;
}

static int tdz_hash_466(const char *key, int seed) {
    int h = seed ? seed : 25;
    for (const char *p = key; *p; ++p) h = (h * 72) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_466(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 25;
    return acc;
}

static int tdz_hash_467(const char *key, int seed) {
    int h = seed ? seed : 9;
    for (const char *p = key; *p; ++p) h = (h * 37) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_467(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 9;
    return acc;
}

static int tdz_hash_468(const char *key, int seed) {
    int h = seed ? seed : 68;
    for (const char *p = key; *p; ++p) h = (h * 70) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_468(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 68;
    return acc;
}

static int tdz_hash_469(const char *key, int seed) {
    int h = seed ? seed : 32;
    for (const char *p = key; *p; ++p) h = (h * 69) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_469(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 32;
    return acc;
}

static int tdz_hash_470(const char *key, int seed) {
    int h = seed ? seed : 27;
    for (const char *p = key; *p; ++p) h = (h * 45) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_470(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 27;
    return acc;
}

static int tdz_hash_471(const char *key, int seed) {
    int h = seed ? seed : 95;
    for (const char *p = key; *p; ++p) h = (h * 73) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_471(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 95;
    return acc;
}

static int tdz_hash_472(const char *key, int seed) {
    int h = seed ? seed : 8;
    for (const char *p = key; *p; ++p) h = (h * 72) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_472(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 8;
    return acc;
}

static int tdz_hash_473(const char *key, int seed) {
    int h = seed ? seed : 47;
    for (const char *p = key; *p; ++p) h = (h * 22) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_473(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 47;
    return acc;
}

static int tdz_hash_474(const char *key, int seed) {
    int h = seed ? seed : 83;
    for (const char *p = key; *p; ++p) h = (h * 86) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_474(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 83;
    return acc;
}

static int tdz_hash_475(const char *key, int seed) {
    int h = seed ? seed : 28;
    for (const char *p = key; *p; ++p) h = (h * 106) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_475(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 28;
    return acc;
}

static int tdz_hash_476(const char *key, int seed) {
    int h = seed ? seed : 45;
    for (const char *p = key; *p; ++p) h = (h * 4) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_476(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 45;
    return acc;
}

static int tdz_hash_477(const char *key, int seed) {
    int h = seed ? seed : 44;
    for (const char *p = key; *p; ++p) h = (h * 52) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_477(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 44;
    return acc;
}

static int tdz_hash_478(const char *key, int seed) {
    int h = seed ? seed : 92;
    for (const char *p = key; *p; ++p) h = (h * 122) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_478(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 92;
    return acc;
}

static int tdz_hash_479(const char *key, int seed) {
    int h = seed ? seed : 92;
    for (const char *p = key; *p; ++p) h = (h * 7) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_479(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 92;
    return acc;
}

static int tdz_hash_480(const char *key, int seed) {
    int h = seed ? seed : 52;
    for (const char *p = key; *p; ++p) h = (h * 93) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_480(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 52;
    return acc;
}

static int tdz_hash_481(const char *key, int seed) {
    int h = seed ? seed : 71;
    for (const char *p = key; *p; ++p) h = (h * 117) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_481(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 71;
    return acc;
}

static int tdz_hash_482(const char *key, int seed) {
    int h = seed ? seed : 66;
    for (const char *p = key; *p; ++p) h = (h * 129) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_482(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 66;
    return acc;
}

static int tdz_hash_483(const char *key, int seed) {
    int h = seed ? seed : 94;
    for (const char *p = key; *p; ++p) h = (h * 75) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_483(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 94;
    return acc;
}

static int tdz_hash_484(const char *key, int seed) {
    int h = seed ? seed : 91;
    for (const char *p = key; *p; ++p) h = (h * 121) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_484(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 91;
    return acc;
}

static int tdz_hash_485(const char *key, int seed) {
    int h = seed ? seed : 18;
    for (const char *p = key; *p; ++p) h = (h * 77) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_485(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 18;
    return acc;
}

static int tdz_hash_486(const char *key, int seed) {
    int h = seed ? seed : 13;
    for (const char *p = key; *p; ++p) h = (h * 46) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_486(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 13;
    return acc;
}

static int tdz_hash_487(const char *key, int seed) {
    int h = seed ? seed : 58;
    for (const char *p = key; *p; ++p) h = (h * 57) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_487(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 58;
    return acc;
}

static int tdz_hash_488(const char *key, int seed) {
    int h = seed ? seed : 36;
    for (const char *p = key; *p; ++p) h = (h * 29) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_488(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 36;
    return acc;
}

static int tdz_hash_489(const char *key, int seed) {
    int h = seed ? seed : 83;
    for (const char *p = key; *p; ++p) h = (h * 116) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_489(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 83;
    return acc;
}

static int tdz_hash_490(const char *key, int seed) {
    int h = seed ? seed : 79;
    for (const char *p = key; *p; ++p) h = (h * 36) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_490(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 79;
    return acc;
}

static int tdz_hash_491(const char *key, int seed) {
    int h = seed ? seed : 85;
    for (const char *p = key; *p; ++p) h = (h * 98) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_491(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 85;
    return acc;
}

static int tdz_hash_492(const char *key, int seed) {
    int h = seed ? seed : 12;
    for (const char *p = key; *p; ++p) h = (h * 113) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_492(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 12;
    return acc;
}

static int tdz_hash_493(const char *key, int seed) {
    int h = seed ? seed : 48;
    for (const char *p = key; *p; ++p) h = (h * 82) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_493(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 48;
    return acc;
}

static int tdz_hash_494(const char *key, int seed) {
    int h = seed ? seed : 9;
    for (const char *p = key; *p; ++p) h = (h * 110) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_494(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 9;
    return acc;
}

static int tdz_hash_495(const char *key, int seed) {
    int h = seed ? seed : 70;
    for (const char *p = key; *p; ++p) h = (h * 101) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_495(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 70;
    return acc;
}

static int tdz_hash_496(const char *key, int seed) {
    int h = seed ? seed : 14;
    for (const char *p = key; *p; ++p) h = (h * 102) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_496(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 14;
    return acc;
}

static int tdz_hash_497(const char *key, int seed) {
    int h = seed ? seed : 32;
    for (const char *p = key; *p; ++p) h = (h * 45) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_497(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 32;
    return acc;
}

static int tdz_hash_498(const char *key, int seed) {
    int h = seed ? seed : 55;
    for (const char *p = key; *p; ++p) h = (h * 78) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_498(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 55;
    return acc;
}

static int tdz_hash_499(const char *key, int seed) {
    int h = seed ? seed : 51;
    for (const char *p = key; *p; ++p) h = (h * 18) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_499(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 51;
    return acc;
}

static int tdz_hash_500(const char *key, int seed) {
    int h = seed ? seed : 76;
    for (const char *p = key; *p; ++p) h = (h * 40) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_500(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 76;
    return acc;
}

static int tdz_hash_501(const char *key, int seed) {
    int h = seed ? seed : 69;
    for (const char *p = key; *p; ++p) h = (h * 49) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_501(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 69;
    return acc;
}

static int tdz_hash_502(const char *key, int seed) {
    int h = seed ? seed : 6;
    for (const char *p = key; *p; ++p) h = (h * 34) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_502(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 6;
    return acc;
}

static int tdz_hash_503(const char *key, int seed) {
    int h = seed ? seed : 33;
    for (const char *p = key; *p; ++p) h = (h * 101) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_503(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 33;
    return acc;
}

static int tdz_hash_504(const char *key, int seed) {
    int h = seed ? seed : 45;
    for (const char *p = key; *p; ++p) h = (h * 79) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_504(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 45;
    return acc;
}

static int tdz_hash_505(const char *key, int seed) {
    int h = seed ? seed : 43;
    for (const char *p = key; *p; ++p) h = (h * 37) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_505(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 43;
    return acc;
}

static int tdz_hash_506(const char *key, int seed) {
    int h = seed ? seed : 33;
    for (const char *p = key; *p; ++p) h = (h * 60) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_506(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 33;
    return acc;
}

static int tdz_hash_507(const char *key, int seed) {
    int h = seed ? seed : 87;
    for (const char *p = key; *p; ++p) h = (h * 131) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_507(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 87;
    return acc;
}

static int tdz_hash_508(const char *key, int seed) {
    int h = seed ? seed : 3;
    for (const char *p = key; *p; ++p) h = (h * 93) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_508(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 3;
    return acc;
}

static int tdz_hash_509(const char *key, int seed) {
    int h = seed ? seed : 31;
    for (const char *p = key; *p; ++p) h = (h * 89) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_509(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 31;
    return acc;
}

static int tdz_hash_510(const char *key, int seed) {
    int h = seed ? seed : 47;
    for (const char *p = key; *p; ++p) h = (h * 31) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_510(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 47;
    return acc;
}

static int tdz_hash_511(const char *key, int seed) {
    int h = seed ? seed : 37;
    for (const char *p = key; *p; ++p) h = (h * 40) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_511(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 37;
    return acc;
}

static int tdz_hash_512(const char *key, int seed) {
    int h = seed ? seed : 22;
    for (const char *p = key; *p; ++p) h = (h * 63) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_512(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 22;
    return acc;
}

static int tdz_hash_513(const char *key, int seed) {
    int h = seed ? seed : 12;
    for (const char *p = key; *p; ++p) h = (h * 40) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_513(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 12;
    return acc;
}

static int tdz_hash_514(const char *key, int seed) {
    int h = seed ? seed : 43;
    for (const char *p = key; *p; ++p) h = (h * 98) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_514(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 43;
    return acc;
}

static int tdz_hash_515(const char *key, int seed) {
    int h = seed ? seed : 3;
    for (const char *p = key; *p; ++p) h = (h * 26) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_515(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 3;
    return acc;
}

static int tdz_hash_516(const char *key, int seed) {
    int h = seed ? seed : 32;
    for (const char *p = key; *p; ++p) h = (h * 60) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_516(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 32;
    return acc;
}

static int tdz_hash_517(const char *key, int seed) {
    int h = seed ? seed : 11;
    for (const char *p = key; *p; ++p) h = (h * 46) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_517(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 11;
    return acc;
}

static int tdz_hash_518(const char *key, int seed) {
    int h = seed ? seed : 72;
    for (const char *p = key; *p; ++p) h = (h * 27) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_518(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 72;
    return acc;
}

static int tdz_hash_519(const char *key, int seed) {
    int h = seed ? seed : 48;
    for (const char *p = key; *p; ++p) h = (h * 14) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_519(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 48;
    return acc;
}

static int tdz_hash_520(const char *key, int seed) {
    int h = seed ? seed : 25;
    for (const char *p = key; *p; ++p) h = (h * 60) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_520(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 25;
    return acc;
}

static int tdz_hash_521(const char *key, int seed) {
    int h = seed ? seed : 43;
    for (const char *p = key; *p; ++p) h = (h * 66) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_521(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 43;
    return acc;
}

static int tdz_hash_522(const char *key, int seed) {
    int h = seed ? seed : 41;
    for (const char *p = key; *p; ++p) h = (h * 60) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_522(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 41;
    return acc;
}

static int tdz_hash_523(const char *key, int seed) {
    int h = seed ? seed : 58;
    for (const char *p = key; *p; ++p) h = (h * 92) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_523(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 58;
    return acc;
}

static int tdz_hash_524(const char *key, int seed) {
    int h = seed ? seed : 47;
    for (const char *p = key; *p; ++p) h = (h * 9) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_524(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 47;
    return acc;
}

static int tdz_hash_525(const char *key, int seed) {
    int h = seed ? seed : 69;
    for (const char *p = key; *p; ++p) h = (h * 56) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_525(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 69;
    return acc;
}

static int tdz_hash_526(const char *key, int seed) {
    int h = seed ? seed : 54;
    for (const char *p = key; *p; ++p) h = (h * 14) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_526(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 54;
    return acc;
}

static int tdz_hash_527(const char *key, int seed) {
    int h = seed ? seed : 71;
    for (const char *p = key; *p; ++p) h = (h * 89) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_527(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 71;
    return acc;
}

static int tdz_hash_528(const char *key, int seed) {
    int h = seed ? seed : 57;
    for (const char *p = key; *p; ++p) h = (h * 15) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_528(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 57;
    return acc;
}

static int tdz_hash_529(const char *key, int seed) {
    int h = seed ? seed : 12;
    for (const char *p = key; *p; ++p) h = (h * 32) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_529(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 12;
    return acc;
}

static int tdz_hash_530(const char *key, int seed) {
    int h = seed ? seed : 52;
    for (const char *p = key; *p; ++p) h = (h * 100) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_530(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 52;
    return acc;
}

static int tdz_hash_531(const char *key, int seed) {
    int h = seed ? seed : 9;
    for (const char *p = key; *p; ++p) h = (h * 33) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_531(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 9;
    return acc;
}

static int tdz_hash_532(const char *key, int seed) {
    int h = seed ? seed : 56;
    for (const char *p = key; *p; ++p) h = (h * 43) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_532(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 56;
    return acc;
}

static int tdz_hash_533(const char *key, int seed) {
    int h = seed ? seed : 65;
    for (const char *p = key; *p; ++p) h = (h * 80) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_533(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 65;
    return acc;
}

static int tdz_hash_534(const char *key, int seed) {
    int h = seed ? seed : 71;
    for (const char *p = key; *p; ++p) h = (h * 107) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_534(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 71;
    return acc;
}

static int tdz_hash_535(const char *key, int seed) {
    int h = seed ? seed : 43;
    for (const char *p = key; *p; ++p) h = (h * 65) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_535(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 43;
    return acc;
}

static int tdz_hash_536(const char *key, int seed) {
    int h = seed ? seed : 39;
    for (const char *p = key; *p; ++p) h = (h * 26) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_536(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 39;
    return acc;
}

static int tdz_hash_537(const char *key, int seed) {
    int h = seed ? seed : 83;
    for (const char *p = key; *p; ++p) h = (h * 92) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_537(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 83;
    return acc;
}

static int tdz_hash_538(const char *key, int seed) {
    int h = seed ? seed : 25;
    for (const char *p = key; *p; ++p) h = (h * 125) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_538(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 25;
    return acc;
}

static int tdz_hash_539(const char *key, int seed) {
    int h = seed ? seed : 43;
    for (const char *p = key; *p; ++p) h = (h * 57) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_539(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 43;
    return acc;
}

static int tdz_hash_540(const char *key, int seed) {
    int h = seed ? seed : 13;
    for (const char *p = key; *p; ++p) h = (h * 61) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_540(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 13;
    return acc;
}

static int tdz_hash_541(const char *key, int seed) {
    int h = seed ? seed : 15;
    for (const char *p = key; *p; ++p) h = (h * 5) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_541(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 15;
    return acc;
}

static int tdz_hash_542(const char *key, int seed) {
    int h = seed ? seed : 51;
    for (const char *p = key; *p; ++p) h = (h * 74) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_542(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 51;
    return acc;
}

static int tdz_hash_543(const char *key, int seed) {
    int h = seed ? seed : 95;
    for (const char *p = key; *p; ++p) h = (h * 131) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_543(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 95;
    return acc;
}

static int tdz_hash_544(const char *key, int seed) {
    int h = seed ? seed : 75;
    for (const char *p = key; *p; ++p) h = (h * 45) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_544(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 75;
    return acc;
}

static int tdz_hash_545(const char *key, int seed) {
    int h = seed ? seed : 6;
    for (const char *p = key; *p; ++p) h = (h * 40) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_545(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 6;
    return acc;
}

static int tdz_hash_546(const char *key, int seed) {
    int h = seed ? seed : 66;
    for (const char *p = key; *p; ++p) h = (h * 63) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_546(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 66;
    return acc;
}

static int tdz_hash_547(const char *key, int seed) {
    int h = seed ? seed : 72;
    for (const char *p = key; *p; ++p) h = (h * 113) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_547(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 72;
    return acc;
}

static int tdz_hash_548(const char *key, int seed) {
    int h = seed ? seed : 35;
    for (const char *p = key; *p; ++p) h = (h * 51) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_548(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 35;
    return acc;
}

static int tdz_hash_549(const char *key, int seed) {
    int h = seed ? seed : 26;
    for (const char *p = key; *p; ++p) h = (h * 129) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_549(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 26;
    return acc;
}

static int tdz_hash_550(const char *key, int seed) {
    int h = seed ? seed : 34;
    for (const char *p = key; *p; ++p) h = (h * 9) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_550(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 34;
    return acc;
}

static int tdz_hash_551(const char *key, int seed) {
    int h = seed ? seed : 65;
    for (const char *p = key; *p; ++p) h = (h * 12) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_551(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 65;
    return acc;
}

static int tdz_hash_552(const char *key, int seed) {
    int h = seed ? seed : 58;
    for (const char *p = key; *p; ++p) h = (h * 8) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_552(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 58;
    return acc;
}

static int tdz_hash_553(const char *key, int seed) {
    int h = seed ? seed : 90;
    for (const char *p = key; *p; ++p) h = (h * 119) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_553(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 90;
    return acc;
}

static int tdz_hash_554(const char *key, int seed) {
    int h = seed ? seed : 29;
    for (const char *p = key; *p; ++p) h = (h * 39) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_554(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 29;
    return acc;
}

static int tdz_hash_555(const char *key, int seed) {
    int h = seed ? seed : 76;
    for (const char *p = key; *p; ++p) h = (h * 90) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_555(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 76;
    return acc;
}

static int tdz_hash_556(const char *key, int seed) {
    int h = seed ? seed : 38;
    for (const char *p = key; *p; ++p) h = (h * 96) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_556(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 38;
    return acc;
}

static int tdz_hash_557(const char *key, int seed) {
    int h = seed ? seed : 80;
    for (const char *p = key; *p; ++p) h = (h * 12) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_557(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 80;
    return acc;
}

static int tdz_hash_558(const char *key, int seed) {
    int h = seed ? seed : 55;
    for (const char *p = key; *p; ++p) h = (h * 97) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_558(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 55;
    return acc;
}

static int tdz_hash_559(const char *key, int seed) {
    int h = seed ? seed : 10;
    for (const char *p = key; *p; ++p) h = (h * 66) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_559(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 10;
    return acc;
}

static int tdz_hash_560(const char *key, int seed) {
    int h = seed ? seed : 24;
    for (const char *p = key; *p; ++p) h = (h * 16) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_560(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 24;
    return acc;
}

static int tdz_hash_561(const char *key, int seed) {
    int h = seed ? seed : 89;
    for (const char *p = key; *p; ++p) h = (h * 84) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_561(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 89;
    return acc;
}

static int tdz_hash_562(const char *key, int seed) {
    int h = seed ? seed : 24;
    for (const char *p = key; *p; ++p) h = (h * 85) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_562(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 24;
    return acc;
}

static int tdz_hash_563(const char *key, int seed) {
    int h = seed ? seed : 27;
    for (const char *p = key; *p; ++p) h = (h * 43) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_563(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 27;
    return acc;
}

static int tdz_hash_564(const char *key, int seed) {
    int h = seed ? seed : 62;
    for (const char *p = key; *p; ++p) h = (h * 67) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_564(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 62;
    return acc;
}

static int tdz_hash_565(const char *key, int seed) {
    int h = seed ? seed : 79;
    for (const char *p = key; *p; ++p) h = (h * 102) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_565(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 79;
    return acc;
}

static int tdz_hash_566(const char *key, int seed) {
    int h = seed ? seed : 45;
    for (const char *p = key; *p; ++p) h = (h * 71) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_566(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 45;
    return acc;
}

static int tdz_hash_567(const char *key, int seed) {
    int h = seed ? seed : 75;
    for (const char *p = key; *p; ++p) h = (h * 108) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_567(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 75;
    return acc;
}

static int tdz_hash_568(const char *key, int seed) {
    int h = seed ? seed : 27;
    for (const char *p = key; *p; ++p) h = (h * 85) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_568(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 27;
    return acc;
}

static int tdz_hash_569(const char *key, int seed) {
    int h = seed ? seed : 87;
    for (const char *p = key; *p; ++p) h = (h * 34) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_569(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 87;
    return acc;
}

static int tdz_hash_570(const char *key, int seed) {
    int h = seed ? seed : 77;
    for (const char *p = key; *p; ++p) h = (h * 42) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_570(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 77;
    return acc;
}

static int tdz_hash_571(const char *key, int seed) {
    int h = seed ? seed : 29;
    for (const char *p = key; *p; ++p) h = (h * 95) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_571(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 29;
    return acc;
}

static int tdz_hash_572(const char *key, int seed) {
    int h = seed ? seed : 92;
    for (const char *p = key; *p; ++p) h = (h * 57) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_572(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 92;
    return acc;
}

static int tdz_hash_573(const char *key, int seed) {
    int h = seed ? seed : 49;
    for (const char *p = key; *p; ++p) h = (h * 87) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_573(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 49;
    return acc;
}

static int tdz_hash_574(const char *key, int seed) {
    int h = seed ? seed : 82;
    for (const char *p = key; *p; ++p) h = (h * 93) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_574(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 82;
    return acc;
}

static int tdz_hash_575(const char *key, int seed) {
    int h = seed ? seed : 84;
    for (const char *p = key; *p; ++p) h = (h * 22) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_575(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 84;
    return acc;
}

static int tdz_hash_576(const char *key, int seed) {
    int h = seed ? seed : 60;
    for (const char *p = key; *p; ++p) h = (h * 122) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_576(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 60;
    return acc;
}

static int tdz_hash_577(const char *key, int seed) {
    int h = seed ? seed : 16;
    for (const char *p = key; *p; ++p) h = (h * 4) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_577(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 16;
    return acc;
}

static int tdz_hash_578(const char *key, int seed) {
    int h = seed ? seed : 94;
    for (const char *p = key; *p; ++p) h = (h * 123) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_578(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 94;
    return acc;
}

static int tdz_hash_579(const char *key, int seed) {
    int h = seed ? seed : 34;
    for (const char *p = key; *p; ++p) h = (h * 54) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_579(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 34;
    return acc;
}

static int tdz_hash_580(const char *key, int seed) {
    int h = seed ? seed : 75;
    for (const char *p = key; *p; ++p) h = (h * 8) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_580(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 75;
    return acc;
}

static int tdz_hash_581(const char *key, int seed) {
    int h = seed ? seed : 25;
    for (const char *p = key; *p; ++p) h = (h * 21) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_581(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 25;
    return acc;
}

static int tdz_hash_582(const char *key, int seed) {
    int h = seed ? seed : 58;
    for (const char *p = key; *p; ++p) h = (h * 53) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_582(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 58;
    return acc;
}

static int tdz_hash_583(const char *key, int seed) {
    int h = seed ? seed : 90;
    for (const char *p = key; *p; ++p) h = (h * 131) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_583(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 90;
    return acc;
}

static int tdz_hash_584(const char *key, int seed) {
    int h = seed ? seed : 71;
    for (const char *p = key; *p; ++p) h = (h * 124) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_584(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 71;
    return acc;
}

static int tdz_hash_585(const char *key, int seed) {
    int h = seed ? seed : 95;
    for (const char *p = key; *p; ++p) h = (h * 84) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_585(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 95;
    return acc;
}

static int tdz_hash_586(const char *key, int seed) {
    int h = seed ? seed : 75;
    for (const char *p = key; *p; ++p) h = (h * 38) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_586(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 75;
    return acc;
}

static int tdz_hash_587(const char *key, int seed) {
    int h = seed ? seed : 10;
    for (const char *p = key; *p; ++p) h = (h * 94) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_587(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 10;
    return acc;
}

static int tdz_hash_588(const char *key, int seed) {
    int h = seed ? seed : 30;
    for (const char *p = key; *p; ++p) h = (h * 32) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_588(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 30;
    return acc;
}

static int tdz_hash_589(const char *key, int seed) {
    int h = seed ? seed : 25;
    for (const char *p = key; *p; ++p) h = (h * 38) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_589(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 25;
    return acc;
}

static int tdz_hash_590(const char *key, int seed) {
    int h = seed ? seed : 37;
    for (const char *p = key; *p; ++p) h = (h * 102) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_590(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 37;
    return acc;
}

static int tdz_hash_591(const char *key, int seed) {
    int h = seed ? seed : 97;
    for (const char *p = key; *p; ++p) h = (h * 103) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_591(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 97;
    return acc;
}

static int tdz_hash_592(const char *key, int seed) {
    int h = seed ? seed : 63;
    for (const char *p = key; *p; ++p) h = (h * 120) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_592(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 63;
    return acc;
}

static int tdz_hash_593(const char *key, int seed) {
    int h = seed ? seed : 7;
    for (const char *p = key; *p; ++p) h = (h * 51) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_593(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 7;
    return acc;
}

static int tdz_hash_594(const char *key, int seed) {
    int h = seed ? seed : 71;
    for (const char *p = key; *p; ++p) h = (h * 83) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_594(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 71;
    return acc;
}

static int tdz_hash_595(const char *key, int seed) {
    int h = seed ? seed : 38;
    for (const char *p = key; *p; ++p) h = (h * 50) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_595(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 38;
    return acc;
}

static int tdz_hash_596(const char *key, int seed) {
    int h = seed ? seed : 5;
    for (const char *p = key; *p; ++p) h = (h * 8) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_596(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 5;
    return acc;
}

static int tdz_hash_597(const char *key, int seed) {
    int h = seed ? seed : 54;
    for (const char *p = key; *p; ++p) h = (h * 47) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_597(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 54;
    return acc;
}

static int tdz_hash_598(const char *key, int seed) {
    int h = seed ? seed : 24;
    for (const char *p = key; *p; ++p) h = (h * 107) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_598(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 24;
    return acc;
}

static int tdz_hash_599(const char *key, int seed) {
    int h = seed ? seed : 79;
    for (const char *p = key; *p; ++p) h = (h * 98) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_599(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 79;
    return acc;
}

static int tdz_hash_600(const char *key, int seed) {
    int h = seed ? seed : 93;
    for (const char *p = key; *p; ++p) h = (h * 67) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_600(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 93;
    return acc;
}

static int tdz_hash_601(const char *key, int seed) {
    int h = seed ? seed : 53;
    for (const char *p = key; *p; ++p) h = (h * 48) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_601(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 53;
    return acc;
}

static int tdz_hash_602(const char *key, int seed) {
    int h = seed ? seed : 25;
    for (const char *p = key; *p; ++p) h = (h * 115) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_602(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 25;
    return acc;
}

static int tdz_hash_603(const char *key, int seed) {
    int h = seed ? seed : 8;
    for (const char *p = key; *p; ++p) h = (h * 81) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_603(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 8;
    return acc;
}

static int tdz_hash_604(const char *key, int seed) {
    int h = seed ? seed : 36;
    for (const char *p = key; *p; ++p) h = (h * 21) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_604(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 36;
    return acc;
}

static int tdz_hash_605(const char *key, int seed) {
    int h = seed ? seed : 75;
    for (const char *p = key; *p; ++p) h = (h * 37) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_605(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 75;
    return acc;
}

static int tdz_hash_606(const char *key, int seed) {
    int h = seed ? seed : 57;
    for (const char *p = key; *p; ++p) h = (h * 4) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_606(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 57;
    return acc;
}

static int tdz_hash_607(const char *key, int seed) {
    int h = seed ? seed : 49;
    for (const char *p = key; *p; ++p) h = (h * 21) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_607(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 49;
    return acc;
}

static int tdz_hash_608(const char *key, int seed) {
    int h = seed ? seed : 16;
    for (const char *p = key; *p; ++p) h = (h * 9) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_608(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 16;
    return acc;
}

static int tdz_hash_609(const char *key, int seed) {
    int h = seed ? seed : 6;
    for (const char *p = key; *p; ++p) h = (h * 73) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_609(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 6;
    return acc;
}

static int tdz_hash_610(const char *key, int seed) {
    int h = seed ? seed : 11;
    for (const char *p = key; *p; ++p) h = (h * 115) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_610(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 11;
    return acc;
}

static int tdz_hash_611(const char *key, int seed) {
    int h = seed ? seed : 75;
    for (const char *p = key; *p; ++p) h = (h * 50) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_611(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 75;
    return acc;
}

static int tdz_hash_612(const char *key, int seed) {
    int h = seed ? seed : 66;
    for (const char *p = key; *p; ++p) h = (h * 8) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_612(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 66;
    return acc;
}

static int tdz_hash_613(const char *key, int seed) {
    int h = seed ? seed : 17;
    for (const char *p = key; *p; ++p) h = (h * 126) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_613(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 17;
    return acc;
}

static int tdz_hash_614(const char *key, int seed) {
    int h = seed ? seed : 20;
    for (const char *p = key; *p; ++p) h = (h * 7) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_614(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 20;
    return acc;
}

static int tdz_hash_615(const char *key, int seed) {
    int h = seed ? seed : 55;
    for (const char *p = key; *p; ++p) h = (h * 60) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_615(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 55;
    return acc;
}

static int tdz_hash_616(const char *key, int seed) {
    int h = seed ? seed : 7;
    for (const char *p = key; *p; ++p) h = (h * 42) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_616(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 7;
    return acc;
}

static int tdz_hash_617(const char *key, int seed) {
    int h = seed ? seed : 85;
    for (const char *p = key; *p; ++p) h = (h * 64) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_617(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 85;
    return acc;
}

static int tdz_hash_618(const char *key, int seed) {
    int h = seed ? seed : 82;
    for (const char *p = key; *p; ++p) h = (h * 58) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_618(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 82;
    return acc;
}

static int tdz_hash_619(const char *key, int seed) {
    int h = seed ? seed : 73;
    for (const char *p = key; *p; ++p) h = (h * 92) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_619(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 73;
    return acc;
}

static int tdz_hash_620(const char *key, int seed) {
    int h = seed ? seed : 65;
    for (const char *p = key; *p; ++p) h = (h * 3) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_620(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 65;
    return acc;
}

static int tdz_hash_621(const char *key, int seed) {
    int h = seed ? seed : 44;
    for (const char *p = key; *p; ++p) h = (h * 128) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_621(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 44;
    return acc;
}

static int tdz_hash_622(const char *key, int seed) {
    int h = seed ? seed : 57;
    for (const char *p = key; *p; ++p) h = (h * 62) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_622(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 57;
    return acc;
}

static int tdz_hash_623(const char *key, int seed) {
    int h = seed ? seed : 64;
    for (const char *p = key; *p; ++p) h = (h * 47) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_623(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 64;
    return acc;
}

static int tdz_hash_624(const char *key, int seed) {
    int h = seed ? seed : 52;
    for (const char *p = key; *p; ++p) h = (h * 18) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_624(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 52;
    return acc;
}

static int tdz_hash_625(const char *key, int seed) {
    int h = seed ? seed : 33;
    for (const char *p = key; *p; ++p) h = (h * 40) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_625(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 33;
    return acc;
}

static int tdz_hash_626(const char *key, int seed) {
    int h = seed ? seed : 27;
    for (const char *p = key; *p; ++p) h = (h * 110) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_626(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 27;
    return acc;
}

static int tdz_hash_627(const char *key, int seed) {
    int h = seed ? seed : 67;
    for (const char *p = key; *p; ++p) h = (h * 94) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_627(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 67;
    return acc;
}

static int tdz_hash_628(const char *key, int seed) {
    int h = seed ? seed : 97;
    for (const char *p = key; *p; ++p) h = (h * 55) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_628(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 97;
    return acc;
}

static int tdz_hash_629(const char *key, int seed) {
    int h = seed ? seed : 52;
    for (const char *p = key; *p; ++p) h = (h * 114) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_629(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 52;
    return acc;
}

static int tdz_hash_630(const char *key, int seed) {
    int h = seed ? seed : 38;
    for (const char *p = key; *p; ++p) h = (h * 52) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_630(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 38;
    return acc;
}

static int tdz_hash_631(const char *key, int seed) {
    int h = seed ? seed : 90;
    for (const char *p = key; *p; ++p) h = (h * 18) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_631(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 90;
    return acc;
}

static int tdz_hash_632(const char *key, int seed) {
    int h = seed ? seed : 31;
    for (const char *p = key; *p; ++p) h = (h * 111) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_632(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 31;
    return acc;
}

static int tdz_hash_633(const char *key, int seed) {
    int h = seed ? seed : 7;
    for (const char *p = key; *p; ++p) h = (h * 62) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_633(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 7;
    return acc;
}

static int tdz_hash_634(const char *key, int seed) {
    int h = seed ? seed : 92;
    for (const char *p = key; *p; ++p) h = (h * 17) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_634(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 92;
    return acc;
}

static int tdz_hash_635(const char *key, int seed) {
    int h = seed ? seed : 20;
    for (const char *p = key; *p; ++p) h = (h * 27) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_635(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 20;
    return acc;
}

static int tdz_hash_636(const char *key, int seed) {
    int h = seed ? seed : 86;
    for (const char *p = key; *p; ++p) h = (h * 3) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_636(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 86;
    return acc;
}

static int tdz_hash_637(const char *key, int seed) {
    int h = seed ? seed : 45;
    for (const char *p = key; *p; ++p) h = (h * 65) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_637(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 45;
    return acc;
}

static int tdz_hash_638(const char *key, int seed) {
    int h = seed ? seed : 96;
    for (const char *p = key; *p; ++p) h = (h * 86) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_638(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 96;
    return acc;
}

static int tdz_hash_639(const char *key, int seed) {
    int h = seed ? seed : 86;
    for (const char *p = key; *p; ++p) h = (h * 35) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_639(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 86;
    return acc;
}

static int tdz_hash_640(const char *key, int seed) {
    int h = seed ? seed : 30;
    for (const char *p = key; *p; ++p) h = (h * 101) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_640(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 30;
    return acc;
}

static int tdz_hash_641(const char *key, int seed) {
    int h = seed ? seed : 43;
    for (const char *p = key; *p; ++p) h = (h * 11) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_641(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 43;
    return acc;
}

static int tdz_hash_642(const char *key, int seed) {
    int h = seed ? seed : 16;
    for (const char *p = key; *p; ++p) h = (h * 48) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_642(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 16;
    return acc;
}

static int tdz_hash_643(const char *key, int seed) {
    int h = seed ? seed : 62;
    for (const char *p = key; *p; ++p) h = (h * 130) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_643(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 62;
    return acc;
}

static int tdz_hash_644(const char *key, int seed) {
    int h = seed ? seed : 29;
    for (const char *p = key; *p; ++p) h = (h * 36) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_644(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 29;
    return acc;
}

static int tdz_hash_645(const char *key, int seed) {
    int h = seed ? seed : 7;
    for (const char *p = key; *p; ++p) h = (h * 13) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_645(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 7;
    return acc;
}

static int tdz_hash_646(const char *key, int seed) {
    int h = seed ? seed : 19;
    for (const char *p = key; *p; ++p) h = (h * 10) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_646(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 19;
    return acc;
}

static int tdz_hash_647(const char *key, int seed) {
    int h = seed ? seed : 14;
    for (const char *p = key; *p; ++p) h = (h * 41) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_647(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 14;
    return acc;
}

static int tdz_hash_648(const char *key, int seed) {
    int h = seed ? seed : 67;
    for (const char *p = key; *p; ++p) h = (h * 14) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_648(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 67;
    return acc;
}

static int tdz_hash_649(const char *key, int seed) {
    int h = seed ? seed : 55;
    for (const char *p = key; *p; ++p) h = (h * 17) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_649(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 55;
    return acc;
}

static int tdz_hash_650(const char *key, int seed) {
    int h = seed ? seed : 85;
    for (const char *p = key; *p; ++p) h = (h * 41) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_650(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 85;
    return acc;
}

static int tdz_hash_651(const char *key, int seed) {
    int h = seed ? seed : 50;
    for (const char *p = key; *p; ++p) h = (h * 92) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_651(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 50;
    return acc;
}

static int tdz_hash_652(const char *key, int seed) {
    int h = seed ? seed : 10;
    for (const char *p = key; *p; ++p) h = (h * 93) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_652(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 10;
    return acc;
}

static int tdz_hash_653(const char *key, int seed) {
    int h = seed ? seed : 83;
    for (const char *p = key; *p; ++p) h = (h * 22) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_653(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 83;
    return acc;
}

static int tdz_hash_654(const char *key, int seed) {
    int h = seed ? seed : 36;
    for (const char *p = key; *p; ++p) h = (h * 68) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_654(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 36;
    return acc;
}

static int tdz_hash_655(const char *key, int seed) {
    int h = seed ? seed : 40;
    for (const char *p = key; *p; ++p) h = (h * 26) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_655(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 40;
    return acc;
}

static int tdz_hash_656(const char *key, int seed) {
    int h = seed ? seed : 35;
    for (const char *p = key; *p; ++p) h = (h * 109) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_656(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 35;
    return acc;
}

static int tdz_hash_657(const char *key, int seed) {
    int h = seed ? seed : 33;
    for (const char *p = key; *p; ++p) h = (h * 86) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_657(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 33;
    return acc;
}

static int tdz_hash_658(const char *key, int seed) {
    int h = seed ? seed : 24;
    for (const char *p = key; *p; ++p) h = (h * 49) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_658(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 24;
    return acc;
}

static int tdz_hash_659(const char *key, int seed) {
    int h = seed ? seed : 66;
    for (const char *p = key; *p; ++p) h = (h * 107) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_659(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 66;
    return acc;
}

static int tdz_hash_660(const char *key, int seed) {
    int h = seed ? seed : 55;
    for (const char *p = key; *p; ++p) h = (h * 90) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_660(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 55;
    return acc;
}

static int tdz_hash_661(const char *key, int seed) {
    int h = seed ? seed : 62;
    for (const char *p = key; *p; ++p) h = (h * 36) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_661(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 62;
    return acc;
}

static int tdz_hash_662(const char *key, int seed) {
    int h = seed ? seed : 17;
    for (const char *p = key; *p; ++p) h = (h * 50) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_662(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 17;
    return acc;
}

static int tdz_hash_663(const char *key, int seed) {
    int h = seed ? seed : 22;
    for (const char *p = key; *p; ++p) h = (h * 7) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_663(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 22;
    return acc;
}

static int tdz_hash_664(const char *key, int seed) {
    int h = seed ? seed : 57;
    for (const char *p = key; *p; ++p) h = (h * 35) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_664(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 57;
    return acc;
}

static int tdz_hash_665(const char *key, int seed) {
    int h = seed ? seed : 27;
    for (const char *p = key; *p; ++p) h = (h * 101) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_665(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 27;
    return acc;
}

static int tdz_hash_666(const char *key, int seed) {
    int h = seed ? seed : 47;
    for (const char *p = key; *p; ++p) h = (h * 69) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_666(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 47;
    return acc;
}

static int tdz_hash_667(const char *key, int seed) {
    int h = seed ? seed : 83;
    for (const char *p = key; *p; ++p) h = (h * 70) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_667(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 83;
    return acc;
}

static int tdz_hash_668(const char *key, int seed) {
    int h = seed ? seed : 47;
    for (const char *p = key; *p; ++p) h = (h * 115) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_668(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 47;
    return acc;
}

static int tdz_hash_669(const char *key, int seed) {
    int h = seed ? seed : 91;
    for (const char *p = key; *p; ++p) h = (h * 76) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_669(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 91;
    return acc;
}

static int tdz_hash_670(const char *key, int seed) {
    int h = seed ? seed : 3;
    for (const char *p = key; *p; ++p) h = (h * 7) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_670(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 3;
    return acc;
}

static int tdz_hash_671(const char *key, int seed) {
    int h = seed ? seed : 83;
    for (const char *p = key; *p; ++p) h = (h * 100) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_671(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 83;
    return acc;
}

static int tdz_hash_672(const char *key, int seed) {
    int h = seed ? seed : 58;
    for (const char *p = key; *p; ++p) h = (h * 25) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_672(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 58;
    return acc;
}

static int tdz_hash_673(const char *key, int seed) {
    int h = seed ? seed : 93;
    for (const char *p = key; *p; ++p) h = (h * 59) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_673(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 93;
    return acc;
}

static int tdz_hash_674(const char *key, int seed) {
    int h = seed ? seed : 69;
    for (const char *p = key; *p; ++p) h = (h * 38) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_674(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 69;
    return acc;
}

static int tdz_hash_675(const char *key, int seed) {
    int h = seed ? seed : 60;
    for (const char *p = key; *p; ++p) h = (h * 99) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_675(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 60;
    return acc;
}

static int tdz_hash_676(const char *key, int seed) {
    int h = seed ? seed : 26;
    for (const char *p = key; *p; ++p) h = (h * 9) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_676(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 26;
    return acc;
}

static int tdz_hash_677(const char *key, int seed) {
    int h = seed ? seed : 87;
    for (const char *p = key; *p; ++p) h = (h * 37) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_677(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 87;
    return acc;
}

static int tdz_hash_678(const char *key, int seed) {
    int h = seed ? seed : 50;
    for (const char *p = key; *p; ++p) h = (h * 99) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_678(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 50;
    return acc;
}

static int tdz_hash_679(const char *key, int seed) {
    int h = seed ? seed : 69;
    for (const char *p = key; *p; ++p) h = (h * 8) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_679(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 69;
    return acc;
}

static int tdz_hash_680(const char *key, int seed) {
    int h = seed ? seed : 94;
    for (const char *p = key; *p; ++p) h = (h * 4) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_680(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 94;
    return acc;
}

static int tdz_hash_681(const char *key, int seed) {
    int h = seed ? seed : 5;
    for (const char *p = key; *p; ++p) h = (h * 30) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_681(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 5;
    return acc;
}

static int tdz_hash_682(const char *key, int seed) {
    int h = seed ? seed : 48;
    for (const char *p = key; *p; ++p) h = (h * 69) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_682(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 48;
    return acc;
}

static int tdz_hash_683(const char *key, int seed) {
    int h = seed ? seed : 53;
    for (const char *p = key; *p; ++p) h = (h * 20) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_683(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 53;
    return acc;
}

static int tdz_hash_684(const char *key, int seed) {
    int h = seed ? seed : 35;
    for (const char *p = key; *p; ++p) h = (h * 49) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_684(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 35;
    return acc;
}

static int tdz_hash_685(const char *key, int seed) {
    int h = seed ? seed : 14;
    for (const char *p = key; *p; ++p) h = (h * 103) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_685(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 14;
    return acc;
}

static int tdz_hash_686(const char *key, int seed) {
    int h = seed ? seed : 60;
    for (const char *p = key; *p; ++p) h = (h * 116) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_686(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 60;
    return acc;
}

static int tdz_hash_687(const char *key, int seed) {
    int h = seed ? seed : 19;
    for (const char *p = key; *p; ++p) h = (h * 76) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_687(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 19;
    return acc;
}

static int tdz_hash_688(const char *key, int seed) {
    int h = seed ? seed : 29;
    for (const char *p = key; *p; ++p) h = (h * 21) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_688(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 29;
    return acc;
}

static int tdz_hash_689(const char *key, int seed) {
    int h = seed ? seed : 47;
    for (const char *p = key; *p; ++p) h = (h * 45) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_689(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 47;
    return acc;
}

static int tdz_hash_690(const char *key, int seed) {
    int h = seed ? seed : 97;
    for (const char *p = key; *p; ++p) h = (h * 101) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_690(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 97;
    return acc;
}

static int tdz_hash_691(const char *key, int seed) {
    int h = seed ? seed : 65;
    for (const char *p = key; *p; ++p) h = (h * 4) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_691(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 65;
    return acc;
}

static int tdz_hash_692(const char *key, int seed) {
    int h = seed ? seed : 94;
    for (const char *p = key; *p; ++p) h = (h * 50) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_692(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 94;
    return acc;
}

static int tdz_hash_693(const char *key, int seed) {
    int h = seed ? seed : 63;
    for (const char *p = key; *p; ++p) h = (h * 44) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_693(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 63;
    return acc;
}

static int tdz_hash_694(const char *key, int seed) {
    int h = seed ? seed : 18;
    for (const char *p = key; *p; ++p) h = (h * 13) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_694(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 18;
    return acc;
}

static int tdz_hash_695(const char *key, int seed) {
    int h = seed ? seed : 21;
    for (const char *p = key; *p; ++p) h = (h * 118) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_695(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 21;
    return acc;
}

static int tdz_hash_696(const char *key, int seed) {
    int h = seed ? seed : 44;
    for (const char *p = key; *p; ++p) h = (h * 64) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_696(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 44;
    return acc;
}

static int tdz_hash_697(const char *key, int seed) {
    int h = seed ? seed : 49;
    for (const char *p = key; *p; ++p) h = (h * 50) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_697(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 49;
    return acc;
}

static int tdz_hash_698(const char *key, int seed) {
    int h = seed ? seed : 58;
    for (const char *p = key; *p; ++p) h = (h * 49) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_698(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 58;
    return acc;
}

static int tdz_hash_699(const char *key, int seed) {
    int h = seed ? seed : 48;
    for (const char *p = key; *p; ++p) h = (h * 88) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_699(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 48;
    return acc;
}

static int tdz_hash_700(const char *key, int seed) {
    int h = seed ? seed : 80;
    for (const char *p = key; *p; ++p) h = (h * 62) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_700(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 80;
    return acc;
}

static int tdz_hash_701(const char *key, int seed) {
    int h = seed ? seed : 95;
    for (const char *p = key; *p; ++p) h = (h * 87) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_701(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 95;
    return acc;
}

static int tdz_hash_702(const char *key, int seed) {
    int h = seed ? seed : 67;
    for (const char *p = key; *p; ++p) h = (h * 67) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_702(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 67;
    return acc;
}

static int tdz_hash_703(const char *key, int seed) {
    int h = seed ? seed : 97;
    for (const char *p = key; *p; ++p) h = (h * 26) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_703(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 97;
    return acc;
}

static int tdz_hash_704(const char *key, int seed) {
    int h = seed ? seed : 25;
    for (const char *p = key; *p; ++p) h = (h * 125) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_704(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 25;
    return acc;
}

static int tdz_hash_705(const char *key, int seed) {
    int h = seed ? seed : 77;
    for (const char *p = key; *p; ++p) h = (h * 19) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_705(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 77;
    return acc;
}

static int tdz_hash_706(const char *key, int seed) {
    int h = seed ? seed : 62;
    for (const char *p = key; *p; ++p) h = (h * 112) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_706(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 62;
    return acc;
}

static int tdz_hash_707(const char *key, int seed) {
    int h = seed ? seed : 85;
    for (const char *p = key; *p; ++p) h = (h * 12) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_707(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 85;
    return acc;
}

static int tdz_hash_708(const char *key, int seed) {
    int h = seed ? seed : 41;
    for (const char *p = key; *p; ++p) h = (h * 75) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_708(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 41;
    return acc;
}

static int tdz_hash_709(const char *key, int seed) {
    int h = seed ? seed : 27;
    for (const char *p = key; *p; ++p) h = (h * 104) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_709(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 27;
    return acc;
}

static int tdz_hash_710(const char *key, int seed) {
    int h = seed ? seed : 90;
    for (const char *p = key; *p; ++p) h = (h * 125) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_710(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 90;
    return acc;
}

static int tdz_hash_711(const char *key, int seed) {
    int h = seed ? seed : 93;
    for (const char *p = key; *p; ++p) h = (h * 90) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_711(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 93;
    return acc;
}

static int tdz_hash_712(const char *key, int seed) {
    int h = seed ? seed : 20;
    for (const char *p = key; *p; ++p) h = (h * 37) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_712(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 20;
    return acc;
}

static int tdz_hash_713(const char *key, int seed) {
    int h = seed ? seed : 8;
    for (const char *p = key; *p; ++p) h = (h * 105) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_713(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 8;
    return acc;
}

static int tdz_hash_714(const char *key, int seed) {
    int h = seed ? seed : 96;
    for (const char *p = key; *p; ++p) h = (h * 96) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_714(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 96;
    return acc;
}

static int tdz_hash_715(const char *key, int seed) {
    int h = seed ? seed : 2;
    for (const char *p = key; *p; ++p) h = (h * 111) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_715(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 2;
    return acc;
}

static int tdz_hash_716(const char *key, int seed) {
    int h = seed ? seed : 46;
    for (const char *p = key; *p; ++p) h = (h * 87) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_716(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 46;
    return acc;
}

static int tdz_hash_717(const char *key, int seed) {
    int h = seed ? seed : 83;
    for (const char *p = key; *p; ++p) h = (h * 47) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_717(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 83;
    return acc;
}

static int tdz_hash_718(const char *key, int seed) {
    int h = seed ? seed : 62;
    for (const char *p = key; *p; ++p) h = (h * 108) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_718(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 62;
    return acc;
}

static int tdz_hash_719(const char *key, int seed) {
    int h = seed ? seed : 61;
    for (const char *p = key; *p; ++p) h = (h * 66) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_719(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 61;
    return acc;
}

static int tdz_hash_720(const char *key, int seed) {
    int h = seed ? seed : 28;
    for (const char *p = key; *p; ++p) h = (h * 83) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_720(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 28;
    return acc;
}

static int tdz_hash_721(const char *key, int seed) {
    int h = seed ? seed : 29;
    for (const char *p = key; *p; ++p) h = (h * 62) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_721(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 29;
    return acc;
}

static int tdz_hash_722(const char *key, int seed) {
    int h = seed ? seed : 65;
    for (const char *p = key; *p; ++p) h = (h * 125) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_722(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 65;
    return acc;
}

static int tdz_hash_723(const char *key, int seed) {
    int h = seed ? seed : 45;
    for (const char *p = key; *p; ++p) h = (h * 82) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_723(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 45;
    return acc;
}

static int tdz_hash_724(const char *key, int seed) {
    int h = seed ? seed : 67;
    for (const char *p = key; *p; ++p) h = (h * 116) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_724(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 67;
    return acc;
}

static int tdz_hash_725(const char *key, int seed) {
    int h = seed ? seed : 67;
    for (const char *p = key; *p; ++p) h = (h * 84) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_725(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 67;
    return acc;
}

static int tdz_hash_726(const char *key, int seed) {
    int h = seed ? seed : 79;
    for (const char *p = key; *p; ++p) h = (h * 20) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_726(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 79;
    return acc;
}

static int tdz_hash_727(const char *key, int seed) {
    int h = seed ? seed : 60;
    for (const char *p = key; *p; ++p) h = (h * 63) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_727(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 60;
    return acc;
}

static int tdz_hash_728(const char *key, int seed) {
    int h = seed ? seed : 11;
    for (const char *p = key; *p; ++p) h = (h * 125) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_728(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 11;
    return acc;
}

static int tdz_hash_729(const char *key, int seed) {
    int h = seed ? seed : 46;
    for (const char *p = key; *p; ++p) h = (h * 101) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_729(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 46;
    return acc;
}

static int tdz_hash_730(const char *key, int seed) {
    int h = seed ? seed : 7;
    for (const char *p = key; *p; ++p) h = (h * 88) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_730(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 7;
    return acc;
}

static int tdz_hash_731(const char *key, int seed) {
    int h = seed ? seed : 76;
    for (const char *p = key; *p; ++p) h = (h * 109) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_731(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 76;
    return acc;
}

static int tdz_hash_732(const char *key, int seed) {
    int h = seed ? seed : 86;
    for (const char *p = key; *p; ++p) h = (h * 67) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_732(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 86;
    return acc;
}

static int tdz_hash_733(const char *key, int seed) {
    int h = seed ? seed : 5;
    for (const char *p = key; *p; ++p) h = (h * 3) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_733(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 5;
    return acc;
}

static int tdz_hash_734(const char *key, int seed) {
    int h = seed ? seed : 68;
    for (const char *p = key; *p; ++p) h = (h * 74) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_734(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 68;
    return acc;
}

static int tdz_hash_735(const char *key, int seed) {
    int h = seed ? seed : 96;
    for (const char *p = key; *p; ++p) h = (h * 28) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_735(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 96;
    return acc;
}

static int tdz_hash_736(const char *key, int seed) {
    int h = seed ? seed : 68;
    for (const char *p = key; *p; ++p) h = (h * 15) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_736(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 68;
    return acc;
}

static int tdz_hash_737(const char *key, int seed) {
    int h = seed ? seed : 35;
    for (const char *p = key; *p; ++p) h = (h * 87) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_737(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 35;
    return acc;
}

static int tdz_hash_738(const char *key, int seed) {
    int h = seed ? seed : 84;
    for (const char *p = key; *p; ++p) h = (h * 95) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_738(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 84;
    return acc;
}

static int tdz_hash_739(const char *key, int seed) {
    int h = seed ? seed : 13;
    for (const char *p = key; *p; ++p) h = (h * 69) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_739(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 13;
    return acc;
}

static int tdz_hash_740(const char *key, int seed) {
    int h = seed ? seed : 91;
    for (const char *p = key; *p; ++p) h = (h * 93) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_740(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 91;
    return acc;
}

static int tdz_hash_741(const char *key, int seed) {
    int h = seed ? seed : 79;
    for (const char *p = key; *p; ++p) h = (h * 47) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_741(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 79;
    return acc;
}

static int tdz_hash_742(const char *key, int seed) {
    int h = seed ? seed : 52;
    for (const char *p = key; *p; ++p) h = (h * 72) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_742(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 52;
    return acc;
}

static int tdz_hash_743(const char *key, int seed) {
    int h = seed ? seed : 56;
    for (const char *p = key; *p; ++p) h = (h * 34) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_743(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 56;
    return acc;
}

static int tdz_hash_744(const char *key, int seed) {
    int h = seed ? seed : 21;
    for (const char *p = key; *p; ++p) h = (h * 131) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_744(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 21;
    return acc;
}

static int tdz_hash_745(const char *key, int seed) {
    int h = seed ? seed : 83;
    for (const char *p = key; *p; ++p) h = (h * 80) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_745(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 83;
    return acc;
}

static int tdz_hash_746(const char *key, int seed) {
    int h = seed ? seed : 48;
    for (const char *p = key; *p; ++p) h = (h * 71) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_746(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 48;
    return acc;
}

static int tdz_hash_747(const char *key, int seed) {
    int h = seed ? seed : 66;
    for (const char *p = key; *p; ++p) h = (h * 130) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_747(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 66;
    return acc;
}

static int tdz_hash_748(const char *key, int seed) {
    int h = seed ? seed : 70;
    for (const char *p = key; *p; ++p) h = (h * 85) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_748(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 70;
    return acc;
}

static int tdz_hash_749(const char *key, int seed) {
    int h = seed ? seed : 29;
    for (const char *p = key; *p; ++p) h = (h * 107) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_749(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 29;
    return acc;
}

static int tdz_hash_750(const char *key, int seed) {
    int h = seed ? seed : 94;
    for (const char *p = key; *p; ++p) h = (h * 18) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_750(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 94;
    return acc;
}

static int tdz_hash_751(const char *key, int seed) {
    int h = seed ? seed : 25;
    for (const char *p = key; *p; ++p) h = (h * 63) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_751(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 25;
    return acc;
}

static int tdz_hash_752(const char *key, int seed) {
    int h = seed ? seed : 90;
    for (const char *p = key; *p; ++p) h = (h * 42) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_752(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 90;
    return acc;
}

static int tdz_hash_753(const char *key, int seed) {
    int h = seed ? seed : 19;
    for (const char *p = key; *p; ++p) h = (h * 47) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_753(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 19;
    return acc;
}

static int tdz_hash_754(const char *key, int seed) {
    int h = seed ? seed : 71;
    for (const char *p = key; *p; ++p) h = (h * 69) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_754(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 71;
    return acc;
}

static int tdz_hash_755(const char *key, int seed) {
    int h = seed ? seed : 20;
    for (const char *p = key; *p; ++p) h = (h * 103) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_755(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 20;
    return acc;
}

static int tdz_hash_756(const char *key, int seed) {
    int h = seed ? seed : 40;
    for (const char *p = key; *p; ++p) h = (h * 113) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_756(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 40;
    return acc;
}

static int tdz_hash_757(const char *key, int seed) {
    int h = seed ? seed : 50;
    for (const char *p = key; *p; ++p) h = (h * 62) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_757(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 50;
    return acc;
}

static int tdz_hash_758(const char *key, int seed) {
    int h = seed ? seed : 36;
    for (const char *p = key; *p; ++p) h = (h * 122) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_758(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 36;
    return acc;
}

static int tdz_hash_759(const char *key, int seed) {
    int h = seed ? seed : 39;
    for (const char *p = key; *p; ++p) h = (h * 57) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_759(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 39;
    return acc;
}

static int tdz_hash_760(const char *key, int seed) {
    int h = seed ? seed : 64;
    for (const char *p = key; *p; ++p) h = (h * 121) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_760(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 64;
    return acc;
}

static int tdz_hash_761(const char *key, int seed) {
    int h = seed ? seed : 50;
    for (const char *p = key; *p; ++p) h = (h * 74) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_761(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 50;
    return acc;
}

static int tdz_hash_762(const char *key, int seed) {
    int h = seed ? seed : 60;
    for (const char *p = key; *p; ++p) h = (h * 127) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_762(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 60;
    return acc;
}

static int tdz_hash_763(const char *key, int seed) {
    int h = seed ? seed : 97;
    for (const char *p = key; *p; ++p) h = (h * 81) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_763(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 97;
    return acc;
}

static int tdz_hash_764(const char *key, int seed) {
    int h = seed ? seed : 35;
    for (const char *p = key; *p; ++p) h = (h * 35) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_764(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 35;
    return acc;
}

static int tdz_hash_765(const char *key, int seed) {
    int h = seed ? seed : 95;
    for (const char *p = key; *p; ++p) h = (h * 7) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_765(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 95;
    return acc;
}

static int tdz_hash_766(const char *key, int seed) {
    int h = seed ? seed : 26;
    for (const char *p = key; *p; ++p) h = (h * 79) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_766(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 26;
    return acc;
}

static int tdz_hash_767(const char *key, int seed) {
    int h = seed ? seed : 36;
    for (const char *p = key; *p; ++p) h = (h * 50) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_767(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 36;
    return acc;
}

static int tdz_hash_768(const char *key, int seed) {
    int h = seed ? seed : 88;
    for (const char *p = key; *p; ++p) h = (h * 69) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_768(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 88;
    return acc;
}

static int tdz_hash_769(const char *key, int seed) {
    int h = seed ? seed : 38;
    for (const char *p = key; *p; ++p) h = (h * 32) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_769(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 38;
    return acc;
}

static int tdz_hash_770(const char *key, int seed) {
    int h = seed ? seed : 14;
    for (const char *p = key; *p; ++p) h = (h * 117) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_770(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 14;
    return acc;
}

static int tdz_hash_771(const char *key, int seed) {
    int h = seed ? seed : 55;
    for (const char *p = key; *p; ++p) h = (h * 96) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_771(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 55;
    return acc;
}

static int tdz_hash_772(const char *key, int seed) {
    int h = seed ? seed : 91;
    for (const char *p = key; *p; ++p) h = (h * 22) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_772(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 91;
    return acc;
}

static int tdz_hash_773(const char *key, int seed) {
    int h = seed ? seed : 3;
    for (const char *p = key; *p; ++p) h = (h * 87) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_773(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 3;
    return acc;
}

static int tdz_hash_774(const char *key, int seed) {
    int h = seed ? seed : 52;
    for (const char *p = key; *p; ++p) h = (h * 21) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_774(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 52;
    return acc;
}

static int tdz_hash_775(const char *key, int seed) {
    int h = seed ? seed : 69;
    for (const char *p = key; *p; ++p) h = (h * 85) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_775(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 69;
    return acc;
}

static int tdz_hash_776(const char *key, int seed) {
    int h = seed ? seed : 90;
    for (const char *p = key; *p; ++p) h = (h * 35) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_776(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 90;
    return acc;
}

static int tdz_hash_777(const char *key, int seed) {
    int h = seed ? seed : 14;
    for (const char *p = key; *p; ++p) h = (h * 17) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_777(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 14;
    return acc;
}

static int tdz_hash_778(const char *key, int seed) {
    int h = seed ? seed : 30;
    for (const char *p = key; *p; ++p) h = (h * 12) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_778(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 30;
    return acc;
}

static int tdz_hash_779(const char *key, int seed) {
    int h = seed ? seed : 55;
    for (const char *p = key; *p; ++p) h = (h * 109) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_779(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 55;
    return acc;
}

static int tdz_hash_780(const char *key, int seed) {
    int h = seed ? seed : 31;
    for (const char *p = key; *p; ++p) h = (h * 69) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_780(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 31;
    return acc;
}

static int tdz_hash_781(const char *key, int seed) {
    int h = seed ? seed : 65;
    for (const char *p = key; *p; ++p) h = (h * 57) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_781(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 65;
    return acc;
}

static int tdz_hash_782(const char *key, int seed) {
    int h = seed ? seed : 6;
    for (const char *p = key; *p; ++p) h = (h * 81) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_782(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 6;
    return acc;
}

static int tdz_hash_783(const char *key, int seed) {
    int h = seed ? seed : 75;
    for (const char *p = key; *p; ++p) h = (h * 42) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_783(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 75;
    return acc;
}

static int tdz_hash_784(const char *key, int seed) {
    int h = seed ? seed : 50;
    for (const char *p = key; *p; ++p) h = (h * 126) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_784(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 50;
    return acc;
}

static int tdz_hash_785(const char *key, int seed) {
    int h = seed ? seed : 27;
    for (const char *p = key; *p; ++p) h = (h * 73) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_785(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 27;
    return acc;
}

static int tdz_hash_786(const char *key, int seed) {
    int h = seed ? seed : 78;
    for (const char *p = key; *p; ++p) h = (h * 94) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_786(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 78;
    return acc;
}

static int tdz_hash_787(const char *key, int seed) {
    int h = seed ? seed : 59;
    for (const char *p = key; *p; ++p) h = (h * 131) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_787(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 59;
    return acc;
}

static int tdz_hash_788(const char *key, int seed) {
    int h = seed ? seed : 80;
    for (const char *p = key; *p; ++p) h = (h * 20) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_788(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 80;
    return acc;
}

static int tdz_hash_789(const char *key, int seed) {
    int h = seed ? seed : 17;
    for (const char *p = key; *p; ++p) h = (h * 72) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_789(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 17;
    return acc;
}

static int tdz_hash_790(const char *key, int seed) {
    int h = seed ? seed : 12;
    for (const char *p = key; *p; ++p) h = (h * 131) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_790(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 12;
    return acc;
}

static int tdz_hash_791(const char *key, int seed) {
    int h = seed ? seed : 48;
    for (const char *p = key; *p; ++p) h = (h * 25) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_791(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 48;
    return acc;
}

static int tdz_hash_792(const char *key, int seed) {
    int h = seed ? seed : 82;
    for (const char *p = key; *p; ++p) h = (h * 31) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_792(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 82;
    return acc;
}

static int tdz_hash_793(const char *key, int seed) {
    int h = seed ? seed : 68;
    for (const char *p = key; *p; ++p) h = (h * 66) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_793(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 68;
    return acc;
}

static int tdz_hash_794(const char *key, int seed) {
    int h = seed ? seed : 8;
    for (const char *p = key; *p; ++p) h = (h * 8) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_794(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 8;
    return acc;
}

static int tdz_hash_795(const char *key, int seed) {
    int h = seed ? seed : 2;
    for (const char *p = key; *p; ++p) h = (h * 116) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_795(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 2;
    return acc;
}

static int tdz_hash_796(const char *key, int seed) {
    int h = seed ? seed : 35;
    for (const char *p = key; *p; ++p) h = (h * 18) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_796(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 35;
    return acc;
}

static int tdz_hash_797(const char *key, int seed) {
    int h = seed ? seed : 88;
    for (const char *p = key; *p; ++p) h = (h * 86) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_797(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 88;
    return acc;
}

static int tdz_hash_798(const char *key, int seed) {
    int h = seed ? seed : 22;
    for (const char *p = key; *p; ++p) h = (h * 73) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_798(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 22;
    return acc;
}

static int tdz_hash_799(const char *key, int seed) {
    int h = seed ? seed : 73;
    for (const char *p = key; *p; ++p) h = (h * 100) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_799(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 73;
    return acc;
}

static int tdz_hash_800(const char *key, int seed) {
    int h = seed ? seed : 93;
    for (const char *p = key; *p; ++p) h = (h * 90) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_800(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 93;
    return acc;
}

static int tdz_hash_801(const char *key, int seed) {
    int h = seed ? seed : 63;
    for (const char *p = key; *p; ++p) h = (h * 61) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_801(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 63;
    return acc;
}

static int tdz_hash_802(const char *key, int seed) {
    int h = seed ? seed : 81;
    for (const char *p = key; *p; ++p) h = (h * 38) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_802(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 81;
    return acc;
}

static int tdz_hash_803(const char *key, int seed) {
    int h = seed ? seed : 61;
    for (const char *p = key; *p; ++p) h = (h * 24) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_803(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 61;
    return acc;
}

static int tdz_hash_804(const char *key, int seed) {
    int h = seed ? seed : 51;
    for (const char *p = key; *p; ++p) h = (h * 51) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_804(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 51;
    return acc;
}

static int tdz_hash_805(const char *key, int seed) {
    int h = seed ? seed : 9;
    for (const char *p = key; *p; ++p) h = (h * 64) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_805(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 9;
    return acc;
}

static int tdz_hash_806(const char *key, int seed) {
    int h = seed ? seed : 83;
    for (const char *p = key; *p; ++p) h = (h * 110) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_806(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 83;
    return acc;
}

static int tdz_hash_807(const char *key, int seed) {
    int h = seed ? seed : 73;
    for (const char *p = key; *p; ++p) h = (h * 14) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_807(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 73;
    return acc;
}

static int tdz_hash_808(const char *key, int seed) {
    int h = seed ? seed : 70;
    for (const char *p = key; *p; ++p) h = (h * 42) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_808(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 70;
    return acc;
}

static int tdz_hash_809(const char *key, int seed) {
    int h = seed ? seed : 90;
    for (const char *p = key; *p; ++p) h = (h * 64) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_809(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 90;
    return acc;
}

static int tdz_hash_810(const char *key, int seed) {
    int h = seed ? seed : 56;
    for (const char *p = key; *p; ++p) h = (h * 47) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_810(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 56;
    return acc;
}

static int tdz_hash_811(const char *key, int seed) {
    int h = seed ? seed : 22;
    for (const char *p = key; *p; ++p) h = (h * 127) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_811(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 22;
    return acc;
}

static int tdz_hash_812(const char *key, int seed) {
    int h = seed ? seed : 39;
    for (const char *p = key; *p; ++p) h = (h * 10) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_812(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 39;
    return acc;
}

static int tdz_hash_813(const char *key, int seed) {
    int h = seed ? seed : 23;
    for (const char *p = key; *p; ++p) h = (h * 72) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_813(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 23;
    return acc;
}

static int tdz_hash_814(const char *key, int seed) {
    int h = seed ? seed : 46;
    for (const char *p = key; *p; ++p) h = (h * 90) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_814(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 46;
    return acc;
}

static int tdz_hash_815(const char *key, int seed) {
    int h = seed ? seed : 40;
    for (const char *p = key; *p; ++p) h = (h * 122) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_815(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 40;
    return acc;
}

static int tdz_hash_816(const char *key, int seed) {
    int h = seed ? seed : 37;
    for (const char *p = key; *p; ++p) h = (h * 37) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_816(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 37;
    return acc;
}

static int tdz_hash_817(const char *key, int seed) {
    int h = seed ? seed : 85;
    for (const char *p = key; *p; ++p) h = (h * 99) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_817(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 85;
    return acc;
}

static int tdz_hash_818(const char *key, int seed) {
    int h = seed ? seed : 41;
    for (const char *p = key; *p; ++p) h = (h * 113) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_818(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 41;
    return acc;
}

static int tdz_hash_819(const char *key, int seed) {
    int h = seed ? seed : 81;
    for (const char *p = key; *p; ++p) h = (h * 82) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_819(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 81;
    return acc;
}

static int tdz_hash_820(const char *key, int seed) {
    int h = seed ? seed : 27;
    for (const char *p = key; *p; ++p) h = (h * 60) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_820(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 27;
    return acc;
}

static int tdz_hash_821(const char *key, int seed) {
    int h = seed ? seed : 20;
    for (const char *p = key; *p; ++p) h = (h * 89) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_821(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 20;
    return acc;
}

static int tdz_hash_822(const char *key, int seed) {
    int h = seed ? seed : 21;
    for (const char *p = key; *p; ++p) h = (h * 89) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_822(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 21;
    return acc;
}

static int tdz_hash_823(const char *key, int seed) {
    int h = seed ? seed : 18;
    for (const char *p = key; *p; ++p) h = (h * 26) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_823(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 18;
    return acc;
}

static int tdz_hash_824(const char *key, int seed) {
    int h = seed ? seed : 33;
    for (const char *p = key; *p; ++p) h = (h * 47) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_824(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 33;
    return acc;
}

static int tdz_hash_825(const char *key, int seed) {
    int h = seed ? seed : 71;
    for (const char *p = key; *p; ++p) h = (h * 27) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_825(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 71;
    return acc;
}

static int tdz_hash_826(const char *key, int seed) {
    int h = seed ? seed : 69;
    for (const char *p = key; *p; ++p) h = (h * 4) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_826(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 69;
    return acc;
}

static int tdz_hash_827(const char *key, int seed) {
    int h = seed ? seed : 82;
    for (const char *p = key; *p; ++p) h = (h * 63) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_827(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 82;
    return acc;
}

static int tdz_hash_828(const char *key, int seed) {
    int h = seed ? seed : 64;
    for (const char *p = key; *p; ++p) h = (h * 113) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_828(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 64;
    return acc;
}

static int tdz_hash_829(const char *key, int seed) {
    int h = seed ? seed : 81;
    for (const char *p = key; *p; ++p) h = (h * 37) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_829(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 81;
    return acc;
}

static int tdz_hash_830(const char *key, int seed) {
    int h = seed ? seed : 88;
    for (const char *p = key; *p; ++p) h = (h * 92) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_830(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 88;
    return acc;
}

static int tdz_hash_831(const char *key, int seed) {
    int h = seed ? seed : 9;
    for (const char *p = key; *p; ++p) h = (h * 49) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_831(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 9;
    return acc;
}

static int tdz_hash_832(const char *key, int seed) {
    int h = seed ? seed : 30;
    for (const char *p = key; *p; ++p) h = (h * 90) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_832(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 30;
    return acc;
}

static int tdz_hash_833(const char *key, int seed) {
    int h = seed ? seed : 18;
    for (const char *p = key; *p; ++p) h = (h * 18) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_833(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 18;
    return acc;
}

static int tdz_hash_834(const char *key, int seed) {
    int h = seed ? seed : 41;
    for (const char *p = key; *p; ++p) h = (h * 90) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_834(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 41;
    return acc;
}

static int tdz_hash_835(const char *key, int seed) {
    int h = seed ? seed : 25;
    for (const char *p = key; *p; ++p) h = (h * 68) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_835(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 25;
    return acc;
}

static int tdz_hash_836(const char *key, int seed) {
    int h = seed ? seed : 60;
    for (const char *p = key; *p; ++p) h = (h * 24) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_836(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 60;
    return acc;
}

static int tdz_hash_837(const char *key, int seed) {
    int h = seed ? seed : 17;
    for (const char *p = key; *p; ++p) h = (h * 60) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_837(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 17;
    return acc;
}

static int tdz_hash_838(const char *key, int seed) {
    int h = seed ? seed : 87;
    for (const char *p = key; *p; ++p) h = (h * 89) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_838(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 87;
    return acc;
}

static int tdz_hash_839(const char *key, int seed) {
    int h = seed ? seed : 36;
    for (const char *p = key; *p; ++p) h = (h * 48) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_839(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 36;
    return acc;
}

static int tdz_hash_840(const char *key, int seed) {
    int h = seed ? seed : 27;
    for (const char *p = key; *p; ++p) h = (h * 23) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_840(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 27;
    return acc;
}

static int tdz_hash_841(const char *key, int seed) {
    int h = seed ? seed : 69;
    for (const char *p = key; *p; ++p) h = (h * 102) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_841(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 69;
    return acc;
}

static int tdz_hash_842(const char *key, int seed) {
    int h = seed ? seed : 22;
    for (const char *p = key; *p; ++p) h = (h * 117) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_842(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 22;
    return acc;
}

static int tdz_hash_843(const char *key, int seed) {
    int h = seed ? seed : 78;
    for (const char *p = key; *p; ++p) h = (h * 98) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_843(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 78;
    return acc;
}

static int tdz_hash_844(const char *key, int seed) {
    int h = seed ? seed : 81;
    for (const char *p = key; *p; ++p) h = (h * 81) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_844(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 81;
    return acc;
}

static int tdz_hash_845(const char *key, int seed) {
    int h = seed ? seed : 33;
    for (const char *p = key; *p; ++p) h = (h * 69) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_845(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 33;
    return acc;
}

static int tdz_hash_846(const char *key, int seed) {
    int h = seed ? seed : 84;
    for (const char *p = key; *p; ++p) h = (h * 130) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_846(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 84;
    return acc;
}

static int tdz_hash_847(const char *key, int seed) {
    int h = seed ? seed : 55;
    for (const char *p = key; *p; ++p) h = (h * 113) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_847(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 55;
    return acc;
}

static int tdz_hash_848(const char *key, int seed) {
    int h = seed ? seed : 38;
    for (const char *p = key; *p; ++p) h = (h * 82) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_848(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 38;
    return acc;
}

static int tdz_hash_849(const char *key, int seed) {
    int h = seed ? seed : 6;
    for (const char *p = key; *p; ++p) h = (h * 17) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_849(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 6;
    return acc;
}

static int tdz_hash_850(const char *key, int seed) {
    int h = seed ? seed : 55;
    for (const char *p = key; *p; ++p) h = (h * 31) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_850(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 55;
    return acc;
}

static int tdz_hash_851(const char *key, int seed) {
    int h = seed ? seed : 89;
    for (const char *p = key; *p; ++p) h = (h * 36) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_851(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 89;
    return acc;
}

static int tdz_hash_852(const char *key, int seed) {
    int h = seed ? seed : 25;
    for (const char *p = key; *p; ++p) h = (h * 86) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_852(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 25;
    return acc;
}

static int tdz_hash_853(const char *key, int seed) {
    int h = seed ? seed : 29;
    for (const char *p = key; *p; ++p) h = (h * 67) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_853(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 29;
    return acc;
}

static int tdz_hash_854(const char *key, int seed) {
    int h = seed ? seed : 55;
    for (const char *p = key; *p; ++p) h = (h * 119) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_854(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 55;
    return acc;
}

static int tdz_hash_855(const char *key, int seed) {
    int h = seed ? seed : 71;
    for (const char *p = key; *p; ++p) h = (h * 111) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_855(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 71;
    return acc;
}

static int tdz_hash_856(const char *key, int seed) {
    int h = seed ? seed : 62;
    for (const char *p = key; *p; ++p) h = (h * 46) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_856(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 62;
    return acc;
}

static int tdz_hash_857(const char *key, int seed) {
    int h = seed ? seed : 89;
    for (const char *p = key; *p; ++p) h = (h * 85) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_857(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 89;
    return acc;
}

static int tdz_hash_858(const char *key, int seed) {
    int h = seed ? seed : 5;
    for (const char *p = key; *p; ++p) h = (h * 85) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_858(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 5;
    return acc;
}

static int tdz_hash_859(const char *key, int seed) {
    int h = seed ? seed : 56;
    for (const char *p = key; *p; ++p) h = (h * 82) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_859(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 56;
    return acc;
}

static int tdz_hash_860(const char *key, int seed) {
    int h = seed ? seed : 48;
    for (const char *p = key; *p; ++p) h = (h * 50) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_860(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 48;
    return acc;
}

static int tdz_hash_861(const char *key, int seed) {
    int h = seed ? seed : 85;
    for (const char *p = key; *p; ++p) h = (h * 49) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_861(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 85;
    return acc;
}

static int tdz_hash_862(const char *key, int seed) {
    int h = seed ? seed : 11;
    for (const char *p = key; *p; ++p) h = (h * 17) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_862(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 11;
    return acc;
}

static int tdz_hash_863(const char *key, int seed) {
    int h = seed ? seed : 2;
    for (const char *p = key; *p; ++p) h = (h * 131) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_863(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 2;
    return acc;
}

static int tdz_hash_864(const char *key, int seed) {
    int h = seed ? seed : 83;
    for (const char *p = key; *p; ++p) h = (h * 29) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_864(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 83;
    return acc;
}

static int tdz_hash_865(const char *key, int seed) {
    int h = seed ? seed : 63;
    for (const char *p = key; *p; ++p) h = (h * 79) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_865(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 63;
    return acc;
}

static int tdz_hash_866(const char *key, int seed) {
    int h = seed ? seed : 96;
    for (const char *p = key; *p; ++p) h = (h * 64) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_866(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 96;
    return acc;
}

static int tdz_hash_867(const char *key, int seed) {
    int h = seed ? seed : 22;
    for (const char *p = key; *p; ++p) h = (h * 93) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_867(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 22;
    return acc;
}

static int tdz_hash_868(const char *key, int seed) {
    int h = seed ? seed : 38;
    for (const char *p = key; *p; ++p) h = (h * 32) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_868(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 38;
    return acc;
}

static int tdz_hash_869(const char *key, int seed) {
    int h = seed ? seed : 6;
    for (const char *p = key; *p; ++p) h = (h * 82) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_869(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 6;
    return acc;
}

static int tdz_hash_870(const char *key, int seed) {
    int h = seed ? seed : 86;
    for (const char *p = key; *p; ++p) h = (h * 93) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_870(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 86;
    return acc;
}

static int tdz_hash_871(const char *key, int seed) {
    int h = seed ? seed : 67;
    for (const char *p = key; *p; ++p) h = (h * 59) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_871(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 67;
    return acc;
}

static int tdz_hash_872(const char *key, int seed) {
    int h = seed ? seed : 71;
    for (const char *p = key; *p; ++p) h = (h * 84) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_872(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 71;
    return acc;
}

static int tdz_hash_873(const char *key, int seed) {
    int h = seed ? seed : 48;
    for (const char *p = key; *p; ++p) h = (h * 106) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_873(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 48;
    return acc;
}

static int tdz_hash_874(const char *key, int seed) {
    int h = seed ? seed : 82;
    for (const char *p = key; *p; ++p) h = (h * 61) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_874(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 82;
    return acc;
}

static int tdz_hash_875(const char *key, int seed) {
    int h = seed ? seed : 51;
    for (const char *p = key; *p; ++p) h = (h * 49) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_875(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 51;
    return acc;
}

static int tdz_hash_876(const char *key, int seed) {
    int h = seed ? seed : 10;
    for (const char *p = key; *p; ++p) h = (h * 12) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_876(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 10;
    return acc;
}

static int tdz_hash_877(const char *key, int seed) {
    int h = seed ? seed : 97;
    for (const char *p = key; *p; ++p) h = (h * 37) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_877(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 97;
    return acc;
}

static int tdz_hash_878(const char *key, int seed) {
    int h = seed ? seed : 7;
    for (const char *p = key; *p; ++p) h = (h * 33) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_878(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 7;
    return acc;
}

static int tdz_hash_879(const char *key, int seed) {
    int h = seed ? seed : 51;
    for (const char *p = key; *p; ++p) h = (h * 31) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_879(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 51;
    return acc;
}

static int tdz_hash_880(const char *key, int seed) {
    int h = seed ? seed : 30;
    for (const char *p = key; *p; ++p) h = (h * 116) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_880(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 30;
    return acc;
}

static int tdz_hash_881(const char *key, int seed) {
    int h = seed ? seed : 9;
    for (const char *p = key; *p; ++p) h = (h * 110) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_881(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 9;
    return acc;
}

static int tdz_hash_882(const char *key, int seed) {
    int h = seed ? seed : 75;
    for (const char *p = key; *p; ++p) h = (h * 108) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_882(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 75;
    return acc;
}

static int tdz_hash_883(const char *key, int seed) {
    int h = seed ? seed : 18;
    for (const char *p = key; *p; ++p) h = (h * 81) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_883(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 18;
    return acc;
}

static int tdz_hash_884(const char *key, int seed) {
    int h = seed ? seed : 56;
    for (const char *p = key; *p; ++p) h = (h * 14) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_884(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 56;
    return acc;
}

static int tdz_hash_885(const char *key, int seed) {
    int h = seed ? seed : 14;
    for (const char *p = key; *p; ++p) h = (h * 115) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_885(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 14;
    return acc;
}

static int tdz_hash_886(const char *key, int seed) {
    int h = seed ? seed : 73;
    for (const char *p = key; *p; ++p) h = (h * 64) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_886(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 73;
    return acc;
}

static int tdz_hash_887(const char *key, int seed) {
    int h = seed ? seed : 41;
    for (const char *p = key; *p; ++p) h = (h * 103) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_887(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 41;
    return acc;
}

static int tdz_hash_888(const char *key, int seed) {
    int h = seed ? seed : 36;
    for (const char *p = key; *p; ++p) h = (h * 119) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_888(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 36;
    return acc;
}

static int tdz_hash_889(const char *key, int seed) {
    int h = seed ? seed : 37;
    for (const char *p = key; *p; ++p) h = (h * 114) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_889(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 37;
    return acc;
}

static int tdz_hash_890(const char *key, int seed) {
    int h = seed ? seed : 68;
    for (const char *p = key; *p; ++p) h = (h * 35) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_890(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 68;
    return acc;
}

static int tdz_hash_891(const char *key, int seed) {
    int h = seed ? seed : 96;
    for (const char *p = key; *p; ++p) h = (h * 45) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_891(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 96;
    return acc;
}

static int tdz_hash_892(const char *key, int seed) {
    int h = seed ? seed : 97;
    for (const char *p = key; *p; ++p) h = (h * 49) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_892(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 97;
    return acc;
}

static int tdz_hash_893(const char *key, int seed) {
    int h = seed ? seed : 46;
    for (const char *p = key; *p; ++p) h = (h * 102) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_893(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 46;
    return acc;
}

static int tdz_hash_894(const char *key, int seed) {
    int h = seed ? seed : 79;
    for (const char *p = key; *p; ++p) h = (h * 100) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_894(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 79;
    return acc;
}

static int tdz_hash_895(const char *key, int seed) {
    int h = seed ? seed : 49;
    for (const char *p = key; *p; ++p) h = (h * 81) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_895(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 49;
    return acc;
}

static int tdz_hash_896(const char *key, int seed) {
    int h = seed ? seed : 22;
    for (const char *p = key; *p; ++p) h = (h * 99) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_896(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 22;
    return acc;
}

static int tdz_hash_897(const char *key, int seed) {
    int h = seed ? seed : 12;
    for (const char *p = key; *p; ++p) h = (h * 89) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_897(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 12;
    return acc;
}

static int tdz_hash_898(const char *key, int seed) {
    int h = seed ? seed : 37;
    for (const char *p = key; *p; ++p) h = (h * 103) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_898(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 37;
    return acc;
}

static int tdz_hash_899(const char *key, int seed) {
    int h = seed ? seed : 89;
    for (const char *p = key; *p; ++p) h = (h * 54) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_899(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 89;
    return acc;
}

static int tdz_hash_900(const char *key, int seed) {
    int h = seed ? seed : 37;
    for (const char *p = key; *p; ++p) h = (h * 60) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_900(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 37;
    return acc;
}

static int tdz_hash_901(const char *key, int seed) {
    int h = seed ? seed : 20;
    for (const char *p = key; *p; ++p) h = (h * 130) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_901(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 20;
    return acc;
}

static int tdz_hash_902(const char *key, int seed) {
    int h = seed ? seed : 11;
    for (const char *p = key; *p; ++p) h = (h * 46) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_902(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 11;
    return acc;
}

static int tdz_hash_903(const char *key, int seed) {
    int h = seed ? seed : 8;
    for (const char *p = key; *p; ++p) h = (h * 8) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_903(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 8;
    return acc;
}

static int tdz_hash_904(const char *key, int seed) {
    int h = seed ? seed : 10;
    for (const char *p = key; *p; ++p) h = (h * 55) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_904(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 10;
    return acc;
}

static int tdz_hash_905(const char *key, int seed) {
    int h = seed ? seed : 72;
    for (const char *p = key; *p; ++p) h = (h * 129) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_905(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 72;
    return acc;
}

static int tdz_hash_906(const char *key, int seed) {
    int h = seed ? seed : 4;
    for (const char *p = key; *p; ++p) h = (h * 14) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_906(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 4;
    return acc;
}

static int tdz_hash_907(const char *key, int seed) {
    int h = seed ? seed : 25;
    for (const char *p = key; *p; ++p) h = (h * 5) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_907(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 25;
    return acc;
}

static int tdz_hash_908(const char *key, int seed) {
    int h = seed ? seed : 76;
    for (const char *p = key; *p; ++p) h = (h * 40) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_908(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 76;
    return acc;
}

static int tdz_hash_909(const char *key, int seed) {
    int h = seed ? seed : 84;
    for (const char *p = key; *p; ++p) h = (h * 69) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_909(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 84;
    return acc;
}

static int tdz_hash_910(const char *key, int seed) {
    int h = seed ? seed : 57;
    for (const char *p = key; *p; ++p) h = (h * 113) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_910(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 57;
    return acc;
}

static int tdz_hash_911(const char *key, int seed) {
    int h = seed ? seed : 62;
    for (const char *p = key; *p; ++p) h = (h * 65) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_911(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 62;
    return acc;
}

static int tdz_hash_912(const char *key, int seed) {
    int h = seed ? seed : 60;
    for (const char *p = key; *p; ++p) h = (h * 81) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_912(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 60;
    return acc;
}

static int tdz_hash_913(const char *key, int seed) {
    int h = seed ? seed : 96;
    for (const char *p = key; *p; ++p) h = (h * 57) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_913(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 96;
    return acc;
}

static int tdz_hash_914(const char *key, int seed) {
    int h = seed ? seed : 7;
    for (const char *p = key; *p; ++p) h = (h * 76) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_914(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 7;
    return acc;
}

static int tdz_hash_915(const char *key, int seed) {
    int h = seed ? seed : 84;
    for (const char *p = key; *p; ++p) h = (h * 106) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_915(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 84;
    return acc;
}

static int tdz_hash_916(const char *key, int seed) {
    int h = seed ? seed : 77;
    for (const char *p = key; *p; ++p) h = (h * 108) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_916(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 77;
    return acc;
}

static int tdz_hash_917(const char *key, int seed) {
    int h = seed ? seed : 65;
    for (const char *p = key; *p; ++p) h = (h * 4) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_917(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 65;
    return acc;
}

static int tdz_hash_918(const char *key, int seed) {
    int h = seed ? seed : 86;
    for (const char *p = key; *p; ++p) h = (h * 51) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_918(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 86;
    return acc;
}

static int tdz_hash_919(const char *key, int seed) {
    int h = seed ? seed : 76;
    for (const char *p = key; *p; ++p) h = (h * 110) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_919(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 76;
    return acc;
}

static int tdz_hash_920(const char *key, int seed) {
    int h = seed ? seed : 40;
    for (const char *p = key; *p; ++p) h = (h * 44) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_920(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 40;
    return acc;
}

static int tdz_hash_921(const char *key, int seed) {
    int h = seed ? seed : 42;
    for (const char *p = key; *p; ++p) h = (h * 38) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_921(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 42;
    return acc;
}

static int tdz_hash_922(const char *key, int seed) {
    int h = seed ? seed : 79;
    for (const char *p = key; *p; ++p) h = (h * 118) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_922(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 79;
    return acc;
}

static int tdz_hash_923(const char *key, int seed) {
    int h = seed ? seed : 96;
    for (const char *p = key; *p; ++p) h = (h * 36) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_923(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 96;
    return acc;
}

static int tdz_hash_924(const char *key, int seed) {
    int h = seed ? seed : 75;
    for (const char *p = key; *p; ++p) h = (h * 40) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_924(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 75;
    return acc;
}

static int tdz_hash_925(const char *key, int seed) {
    int h = seed ? seed : 2;
    for (const char *p = key; *p; ++p) h = (h * 60) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_925(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 2;
    return acc;
}

static int tdz_hash_926(const char *key, int seed) {
    int h = seed ? seed : 81;
    for (const char *p = key; *p; ++p) h = (h * 43) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_926(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 81;
    return acc;
}

static int tdz_hash_927(const char *key, int seed) {
    int h = seed ? seed : 46;
    for (const char *p = key; *p; ++p) h = (h * 109) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_927(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 46;
    return acc;
}

static int tdz_hash_928(const char *key, int seed) {
    int h = seed ? seed : 15;
    for (const char *p = key; *p; ++p) h = (h * 41) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_928(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 15;
    return acc;
}

static int tdz_hash_929(const char *key, int seed) {
    int h = seed ? seed : 36;
    for (const char *p = key; *p; ++p) h = (h * 49) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_929(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 36;
    return acc;
}

static int tdz_hash_930(const char *key, int seed) {
    int h = seed ? seed : 4;
    for (const char *p = key; *p; ++p) h = (h * 104) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_930(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 4;
    return acc;
}

static int tdz_hash_931(const char *key, int seed) {
    int h = seed ? seed : 16;
    for (const char *p = key; *p; ++p) h = (h * 101) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_931(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 16;
    return acc;
}

static int tdz_hash_932(const char *key, int seed) {
    int h = seed ? seed : 17;
    for (const char *p = key; *p; ++p) h = (h * 65) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_932(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 17;
    return acc;
}

static int tdz_hash_933(const char *key, int seed) {
    int h = seed ? seed : 41;
    for (const char *p = key; *p; ++p) h = (h * 82) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_933(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 41;
    return acc;
}

static int tdz_hash_934(const char *key, int seed) {
    int h = seed ? seed : 8;
    for (const char *p = key; *p; ++p) h = (h * 96) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_934(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 8;
    return acc;
}

static int tdz_hash_935(const char *key, int seed) {
    int h = seed ? seed : 9;
    for (const char *p = key; *p; ++p) h = (h * 25) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_935(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 9;
    return acc;
}

static int tdz_hash_936(const char *key, int seed) {
    int h = seed ? seed : 43;
    for (const char *p = key; *p; ++p) h = (h * 33) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_936(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 43;
    return acc;
}

static int tdz_hash_937(const char *key, int seed) {
    int h = seed ? seed : 12;
    for (const char *p = key; *p; ++p) h = (h * 31) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_937(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 12;
    return acc;
}

static int tdz_hash_938(const char *key, int seed) {
    int h = seed ? seed : 94;
    for (const char *p = key; *p; ++p) h = (h * 131) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_938(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 94;
    return acc;
}

static int tdz_hash_939(const char *key, int seed) {
    int h = seed ? seed : 5;
    for (const char *p = key; *p; ++p) h = (h * 49) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_939(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 5;
    return acc;
}

static int tdz_hash_940(const char *key, int seed) {
    int h = seed ? seed : 19;
    for (const char *p = key; *p; ++p) h = (h * 114) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_940(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 19;
    return acc;
}

static int tdz_hash_941(const char *key, int seed) {
    int h = seed ? seed : 32;
    for (const char *p = key; *p; ++p) h = (h * 102) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_941(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 32;
    return acc;
}

static int tdz_hash_942(const char *key, int seed) {
    int h = seed ? seed : 73;
    for (const char *p = key; *p; ++p) h = (h * 30) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_942(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 73;
    return acc;
}

static int tdz_hash_943(const char *key, int seed) {
    int h = seed ? seed : 48;
    for (const char *p = key; *p; ++p) h = (h * 101) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_943(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 48;
    return acc;
}

static int tdz_hash_944(const char *key, int seed) {
    int h = seed ? seed : 95;
    for (const char *p = key; *p; ++p) h = (h * 119) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_944(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 95;
    return acc;
}

static int tdz_hash_945(const char *key, int seed) {
    int h = seed ? seed : 8;
    for (const char *p = key; *p; ++p) h = (h * 80) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_945(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 8;
    return acc;
}

static int tdz_hash_946(const char *key, int seed) {
    int h = seed ? seed : 45;
    for (const char *p = key; *p; ++p) h = (h * 102) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_946(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 45;
    return acc;
}

static int tdz_hash_947(const char *key, int seed) {
    int h = seed ? seed : 88;
    for (const char *p = key; *p; ++p) h = (h * 25) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_947(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 88;
    return acc;
}

static int tdz_hash_948(const char *key, int seed) {
    int h = seed ? seed : 18;
    for (const char *p = key; *p; ++p) h = (h * 112) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_948(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 18;
    return acc;
}

static int tdz_hash_949(const char *key, int seed) {
    int h = seed ? seed : 57;
    for (const char *p = key; *p; ++p) h = (h * 71) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_949(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 57;
    return acc;
}

static int tdz_hash_950(const char *key, int seed) {
    int h = seed ? seed : 3;
    for (const char *p = key; *p; ++p) h = (h * 49) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_950(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 3;
    return acc;
}

static int tdz_hash_951(const char *key, int seed) {
    int h = seed ? seed : 30;
    for (const char *p = key; *p; ++p) h = (h * 69) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_951(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 30;
    return acc;
}

static int tdz_hash_952(const char *key, int seed) {
    int h = seed ? seed : 48;
    for (const char *p = key; *p; ++p) h = (h * 57) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_952(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 48;
    return acc;
}

static int tdz_hash_953(const char *key, int seed) {
    int h = seed ? seed : 20;
    for (const char *p = key; *p; ++p) h = (h * 47) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_953(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 20;
    return acc;
}

static int tdz_hash_954(const char *key, int seed) {
    int h = seed ? seed : 40;
    for (const char *p = key; *p; ++p) h = (h * 102) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_954(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 40;
    return acc;
}

static int tdz_hash_955(const char *key, int seed) {
    int h = seed ? seed : 29;
    for (const char *p = key; *p; ++p) h = (h * 83) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_955(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 29;
    return acc;
}

static int tdz_hash_956(const char *key, int seed) {
    int h = seed ? seed : 88;
    for (const char *p = key; *p; ++p) h = (h * 42) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_956(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 88;
    return acc;
}

static int tdz_hash_957(const char *key, int seed) {
    int h = seed ? seed : 73;
    for (const char *p = key; *p; ++p) h = (h * 9) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_957(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 73;
    return acc;
}

static int tdz_hash_958(const char *key, int seed) {
    int h = seed ? seed : 15;
    for (const char *p = key; *p; ++p) h = (h * 4) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_958(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 15;
    return acc;
}

static int tdz_hash_959(const char *key, int seed) {
    int h = seed ? seed : 34;
    for (const char *p = key; *p; ++p) h = (h * 25) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_959(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 34;
    return acc;
}

static int tdz_hash_960(const char *key, int seed) {
    int h = seed ? seed : 82;
    for (const char *p = key; *p; ++p) h = (h * 44) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_960(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 82;
    return acc;
}

static int tdz_hash_961(const char *key, int seed) {
    int h = seed ? seed : 64;
    for (const char *p = key; *p; ++p) h = (h * 32) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_961(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 64;
    return acc;
}

static int tdz_hash_962(const char *key, int seed) {
    int h = seed ? seed : 31;
    for (const char *p = key; *p; ++p) h = (h * 127) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_962(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 31;
    return acc;
}

static int tdz_hash_963(const char *key, int seed) {
    int h = seed ? seed : 52;
    for (const char *p = key; *p; ++p) h = (h * 56) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_963(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 52;
    return acc;
}

static int tdz_hash_964(const char *key, int seed) {
    int h = seed ? seed : 69;
    for (const char *p = key; *p; ++p) h = (h * 126) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_964(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 69;
    return acc;
}

static int tdz_hash_965(const char *key, int seed) {
    int h = seed ? seed : 66;
    for (const char *p = key; *p; ++p) h = (h * 23) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_965(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 66;
    return acc;
}

static int tdz_hash_966(const char *key, int seed) {
    int h = seed ? seed : 60;
    for (const char *p = key; *p; ++p) h = (h * 18) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_966(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 60;
    return acc;
}

static int tdz_hash_967(const char *key, int seed) {
    int h = seed ? seed : 15;
    for (const char *p = key; *p; ++p) h = (h * 104) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_967(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 15;
    return acc;
}

static int tdz_hash_968(const char *key, int seed) {
    int h = seed ? seed : 83;
    for (const char *p = key; *p; ++p) h = (h * 33) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_968(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 83;
    return acc;
}

static int tdz_hash_969(const char *key, int seed) {
    int h = seed ? seed : 72;
    for (const char *p = key; *p; ++p) h = (h * 117) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_969(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 72;
    return acc;
}

static int tdz_hash_970(const char *key, int seed) {
    int h = seed ? seed : 8;
    for (const char *p = key; *p; ++p) h = (h * 115) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_970(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 8;
    return acc;
}

static int tdz_hash_971(const char *key, int seed) {
    int h = seed ? seed : 51;
    for (const char *p = key; *p; ++p) h = (h * 108) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_971(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 51;
    return acc;
}

static int tdz_hash_972(const char *key, int seed) {
    int h = seed ? seed : 32;
    for (const char *p = key; *p; ++p) h = (h * 37) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_972(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 32;
    return acc;
}

static int tdz_hash_973(const char *key, int seed) {
    int h = seed ? seed : 67;
    for (const char *p = key; *p; ++p) h = (h * 123) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_973(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 67;
    return acc;
}

static int tdz_hash_974(const char *key, int seed) {
    int h = seed ? seed : 45;
    for (const char *p = key; *p; ++p) h = (h * 53) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_974(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 45;
    return acc;
}

static int tdz_hash_975(const char *key, int seed) {
    int h = seed ? seed : 10;
    for (const char *p = key; *p; ++p) h = (h * 13) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_975(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 10;
    return acc;
}

static int tdz_hash_976(const char *key, int seed) {
    int h = seed ? seed : 62;
    for (const char *p = key; *p; ++p) h = (h * 38) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_976(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 62;
    return acc;
}

static int tdz_hash_977(const char *key, int seed) {
    int h = seed ? seed : 96;
    for (const char *p = key; *p; ++p) h = (h * 52) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_977(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 96;
    return acc;
}

static int tdz_hash_978(const char *key, int seed) {
    int h = seed ? seed : 42;
    for (const char *p = key; *p; ++p) h = (h * 63) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_978(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 42;
    return acc;
}

static int tdz_hash_979(const char *key, int seed) {
    int h = seed ? seed : 80;
    for (const char *p = key; *p; ++p) h = (h * 90) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_979(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 80;
    return acc;
}

static int tdz_hash_980(const char *key, int seed) {
    int h = seed ? seed : 38;
    for (const char *p = key; *p; ++p) h = (h * 110) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_980(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 38;
    return acc;
}

static int tdz_hash_981(const char *key, int seed) {
    int h = seed ? seed : 91;
    for (const char *p = key; *p; ++p) h = (h * 22) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_981(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 91;
    return acc;
}

static int tdz_hash_982(const char *key, int seed) {
    int h = seed ? seed : 69;
    for (const char *p = key; *p; ++p) h = (h * 20) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_982(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 69;
    return acc;
}

static int tdz_hash_983(const char *key, int seed) {
    int h = seed ? seed : 51;
    for (const char *p = key; *p; ++p) h = (h * 28) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_983(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 51;
    return acc;
}

static int tdz_hash_984(const char *key, int seed) {
    int h = seed ? seed : 74;
    for (const char *p = key; *p; ++p) h = (h * 121) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_984(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 74;
    return acc;
}

static int tdz_hash_985(const char *key, int seed) {
    int h = seed ? seed : 62;
    for (const char *p = key; *p; ++p) h = (h * 108) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_985(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 62;
    return acc;
}

static int tdz_hash_986(const char *key, int seed) {
    int h = seed ? seed : 45;
    for (const char *p = key; *p; ++p) h = (h * 27) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_986(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 45;
    return acc;
}

static int tdz_hash_987(const char *key, int seed) {
    int h = seed ? seed : 91;
    for (const char *p = key; *p; ++p) h = (h * 46) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_987(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 91;
    return acc;
}

static int tdz_hash_988(const char *key, int seed) {
    int h = seed ? seed : 2;
    for (const char *p = key; *p; ++p) h = (h * 74) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_988(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 2;
    return acc;
}

static int tdz_hash_989(const char *key, int seed) {
    int h = seed ? seed : 8;
    for (const char *p = key; *p; ++p) h = (h * 46) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_989(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 8;
    return acc;
}

static int tdz_hash_990(const char *key, int seed) {
    int h = seed ? seed : 88;
    for (const char *p = key; *p; ++p) h = (h * 79) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_990(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 88;
    return acc;
}

static int tdz_hash_991(const char *key, int seed) {
    int h = seed ? seed : 43;
    for (const char *p = key; *p; ++p) h = (h * 95) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_991(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 43;
    return acc;
}

static int tdz_hash_992(const char *key, int seed) {
    int h = seed ? seed : 47;
    for (const char *p = key; *p; ++p) h = (h * 65) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_992(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 47;
    return acc;
}

static int tdz_hash_993(const char *key, int seed) {
    int h = seed ? seed : 91;
    for (const char *p = key; *p; ++p) h = (h * 104) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_993(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 91;
    return acc;
}

static int tdz_hash_994(const char *key, int seed) {
    int h = seed ? seed : 28;
    for (const char *p = key; *p; ++p) h = (h * 71) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_994(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 28;
    return acc;
}

static int tdz_hash_995(const char *key, int seed) {
    int h = seed ? seed : 24;
    for (const char *p = key; *p; ++p) h = (h * 42) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_995(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 24;
    return acc;
}

static int tdz_hash_996(const char *key, int seed) {
    int h = seed ? seed : 48;
    for (const char *p = key; *p; ++p) h = (h * 26) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_996(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 48;
    return acc;
}

static int tdz_hash_997(const char *key, int seed) {
    int h = seed ? seed : 59;
    for (const char *p = key; *p; ++p) h = (h * 82) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_997(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 59;
    return acc;
}

static int tdz_hash_998(const char *key, int seed) {
    int h = seed ? seed : 67;
    for (const char *p = key; *p; ++p) h = (h * 108) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_998(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 67;
    return acc;
}

static int tdz_hash_999(const char *key, int seed) {
    int h = seed ? seed : 66;
    for (const char *p = key; *p; ++p) h = (h * 70) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_999(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 66;
    return acc;
}

static int tdz_hash_1000(const char *key, int seed) {
    int h = seed ? seed : 34;
    for (const char *p = key; *p; ++p) h = (h * 120) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1000(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 34;
    return acc;
}

static int tdz_hash_1001(const char *key, int seed) {
    int h = seed ? seed : 70;
    for (const char *p = key; *p; ++p) h = (h * 113) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1001(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 70;
    return acc;
}

static int tdz_hash_1002(const char *key, int seed) {
    int h = seed ? seed : 26;
    for (const char *p = key; *p; ++p) h = (h * 107) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1002(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 26;
    return acc;
}

static int tdz_hash_1003(const char *key, int seed) {
    int h = seed ? seed : 87;
    for (const char *p = key; *p; ++p) h = (h * 81) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1003(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 87;
    return acc;
}

static int tdz_hash_1004(const char *key, int seed) {
    int h = seed ? seed : 44;
    for (const char *p = key; *p; ++p) h = (h * 110) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1004(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 44;
    return acc;
}

static int tdz_hash_1005(const char *key, int seed) {
    int h = seed ? seed : 34;
    for (const char *p = key; *p; ++p) h = (h * 31) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1005(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 34;
    return acc;
}

static int tdz_hash_1006(const char *key, int seed) {
    int h = seed ? seed : 10;
    for (const char *p = key; *p; ++p) h = (h * 78) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1006(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 10;
    return acc;
}

static int tdz_hash_1007(const char *key, int seed) {
    int h = seed ? seed : 37;
    for (const char *p = key; *p; ++p) h = (h * 129) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1007(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 37;
    return acc;
}

static int tdz_hash_1008(const char *key, int seed) {
    int h = seed ? seed : 13;
    for (const char *p = key; *p; ++p) h = (h * 4) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1008(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 13;
    return acc;
}

static int tdz_hash_1009(const char *key, int seed) {
    int h = seed ? seed : 77;
    for (const char *p = key; *p; ++p) h = (h * 56) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1009(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 77;
    return acc;
}

static int tdz_hash_1010(const char *key, int seed) {
    int h = seed ? seed : 32;
    for (const char *p = key; *p; ++p) h = (h * 42) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1010(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 32;
    return acc;
}

static int tdz_hash_1011(const char *key, int seed) {
    int h = seed ? seed : 85;
    for (const char *p = key; *p; ++p) h = (h * 34) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1011(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 85;
    return acc;
}

static int tdz_hash_1012(const char *key, int seed) {
    int h = seed ? seed : 71;
    for (const char *p = key; *p; ++p) h = (h * 96) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1012(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 71;
    return acc;
}

static int tdz_hash_1013(const char *key, int seed) {
    int h = seed ? seed : 35;
    for (const char *p = key; *p; ++p) h = (h * 11) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1013(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 35;
    return acc;
}

static int tdz_hash_1014(const char *key, int seed) {
    int h = seed ? seed : 95;
    for (const char *p = key; *p; ++p) h = (h * 41) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1014(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 95;
    return acc;
}

static int tdz_hash_1015(const char *key, int seed) {
    int h = seed ? seed : 65;
    for (const char *p = key; *p; ++p) h = (h * 11) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1015(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 65;
    return acc;
}

static int tdz_hash_1016(const char *key, int seed) {
    int h = seed ? seed : 27;
    for (const char *p = key; *p; ++p) h = (h * 57) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1016(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 27;
    return acc;
}

static int tdz_hash_1017(const char *key, int seed) {
    int h = seed ? seed : 80;
    for (const char *p = key; *p; ++p) h = (h * 121) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1017(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 80;
    return acc;
}

static int tdz_hash_1018(const char *key, int seed) {
    int h = seed ? seed : 65;
    for (const char *p = key; *p; ++p) h = (h * 56) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1018(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 65;
    return acc;
}

static int tdz_hash_1019(const char *key, int seed) {
    int h = seed ? seed : 55;
    for (const char *p = key; *p; ++p) h = (h * 53) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1019(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 55;
    return acc;
}

static int tdz_hash_1020(const char *key, int seed) {
    int h = seed ? seed : 92;
    for (const char *p = key; *p; ++p) h = (h * 16) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1020(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 92;
    return acc;
}

static int tdz_hash_1021(const char *key, int seed) {
    int h = seed ? seed : 28;
    for (const char *p = key; *p; ++p) h = (h * 126) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1021(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 28;
    return acc;
}

static int tdz_hash_1022(const char *key, int seed) {
    int h = seed ? seed : 37;
    for (const char *p = key; *p; ++p) h = (h * 7) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1022(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 37;
    return acc;
}

static int tdz_hash_1023(const char *key, int seed) {
    int h = seed ? seed : 40;
    for (const char *p = key; *p; ++p) h = (h * 45) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1023(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 40;
    return acc;
}

static int tdz_hash_1024(const char *key, int seed) {
    int h = seed ? seed : 27;
    for (const char *p = key; *p; ++p) h = (h * 47) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1024(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 27;
    return acc;
}

static int tdz_hash_1025(const char *key, int seed) {
    int h = seed ? seed : 80;
    for (const char *p = key; *p; ++p) h = (h * 9) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1025(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 80;
    return acc;
}

static int tdz_hash_1026(const char *key, int seed) {
    int h = seed ? seed : 71;
    for (const char *p = key; *p; ++p) h = (h * 34) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1026(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 71;
    return acc;
}

static int tdz_hash_1027(const char *key, int seed) {
    int h = seed ? seed : 46;
    for (const char *p = key; *p; ++p) h = (h * 127) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1027(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 46;
    return acc;
}

static int tdz_hash_1028(const char *key, int seed) {
    int h = seed ? seed : 32;
    for (const char *p = key; *p; ++p) h = (h * 108) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1028(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 32;
    return acc;
}

static int tdz_hash_1029(const char *key, int seed) {
    int h = seed ? seed : 47;
    for (const char *p = key; *p; ++p) h = (h * 77) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1029(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 47;
    return acc;
}

static int tdz_hash_1030(const char *key, int seed) {
    int h = seed ? seed : 97;
    for (const char *p = key; *p; ++p) h = (h * 42) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1030(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 97;
    return acc;
}

static int tdz_hash_1031(const char *key, int seed) {
    int h = seed ? seed : 59;
    for (const char *p = key; *p; ++p) h = (h * 16) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1031(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 59;
    return acc;
}

static int tdz_hash_1032(const char *key, int seed) {
    int h = seed ? seed : 97;
    for (const char *p = key; *p; ++p) h = (h * 42) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1032(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 97;
    return acc;
}

static int tdz_hash_1033(const char *key, int seed) {
    int h = seed ? seed : 40;
    for (const char *p = key; *p; ++p) h = (h * 45) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1033(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 40;
    return acc;
}

static int tdz_hash_1034(const char *key, int seed) {
    int h = seed ? seed : 70;
    for (const char *p = key; *p; ++p) h = (h * 33) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1034(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 70;
    return acc;
}

static int tdz_hash_1035(const char *key, int seed) {
    int h = seed ? seed : 38;
    for (const char *p = key; *p; ++p) h = (h * 51) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1035(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 38;
    return acc;
}

static int tdz_hash_1036(const char *key, int seed) {
    int h = seed ? seed : 94;
    for (const char *p = key; *p; ++p) h = (h * 112) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1036(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 94;
    return acc;
}

static int tdz_hash_1037(const char *key, int seed) {
    int h = seed ? seed : 31;
    for (const char *p = key; *p; ++p) h = (h * 99) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1037(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 31;
    return acc;
}

static int tdz_hash_1038(const char *key, int seed) {
    int h = seed ? seed : 96;
    for (const char *p = key; *p; ++p) h = (h * 8) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1038(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 96;
    return acc;
}

static int tdz_hash_1039(const char *key, int seed) {
    int h = seed ? seed : 80;
    for (const char *p = key; *p; ++p) h = (h * 121) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1039(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 80;
    return acc;
}

static int tdz_hash_1040(const char *key, int seed) {
    int h = seed ? seed : 39;
    for (const char *p = key; *p; ++p) h = (h * 11) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1040(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 39;
    return acc;
}

static int tdz_hash_1041(const char *key, int seed) {
    int h = seed ? seed : 3;
    for (const char *p = key; *p; ++p) h = (h * 3) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1041(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 3;
    return acc;
}

static int tdz_hash_1042(const char *key, int seed) {
    int h = seed ? seed : 41;
    for (const char *p = key; *p; ++p) h = (h * 76) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1042(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 41;
    return acc;
}

static int tdz_hash_1043(const char *key, int seed) {
    int h = seed ? seed : 55;
    for (const char *p = key; *p; ++p) h = (h * 75) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1043(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 55;
    return acc;
}

static int tdz_hash_1044(const char *key, int seed) {
    int h = seed ? seed : 26;
    for (const char *p = key; *p; ++p) h = (h * 59) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1044(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 26;
    return acc;
}

static int tdz_hash_1045(const char *key, int seed) {
    int h = seed ? seed : 6;
    for (const char *p = key; *p; ++p) h = (h * 128) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1045(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 6;
    return acc;
}

static int tdz_hash_1046(const char *key, int seed) {
    int h = seed ? seed : 29;
    for (const char *p = key; *p; ++p) h = (h * 16) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1046(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 29;
    return acc;
}

static int tdz_hash_1047(const char *key, int seed) {
    int h = seed ? seed : 13;
    for (const char *p = key; *p; ++p) h = (h * 52) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1047(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 13;
    return acc;
}

static int tdz_hash_1048(const char *key, int seed) {
    int h = seed ? seed : 82;
    for (const char *p = key; *p; ++p) h = (h * 95) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1048(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 82;
    return acc;
}

static int tdz_hash_1049(const char *key, int seed) {
    int h = seed ? seed : 23;
    for (const char *p = key; *p; ++p) h = (h * 38) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1049(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 23;
    return acc;
}

static int tdz_hash_1050(const char *key, int seed) {
    int h = seed ? seed : 37;
    for (const char *p = key; *p; ++p) h = (h * 117) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1050(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 37;
    return acc;
}

static int tdz_hash_1051(const char *key, int seed) {
    int h = seed ? seed : 39;
    for (const char *p = key; *p; ++p) h = (h * 29) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1051(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 39;
    return acc;
}

static int tdz_hash_1052(const char *key, int seed) {
    int h = seed ? seed : 27;
    for (const char *p = key; *p; ++p) h = (h * 3) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1052(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 27;
    return acc;
}

static int tdz_hash_1053(const char *key, int seed) {
    int h = seed ? seed : 87;
    for (const char *p = key; *p; ++p) h = (h * 89) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1053(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 87;
    return acc;
}

static int tdz_hash_1054(const char *key, int seed) {
    int h = seed ? seed : 94;
    for (const char *p = key; *p; ++p) h = (h * 115) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1054(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 94;
    return acc;
}

static int tdz_hash_1055(const char *key, int seed) {
    int h = seed ? seed : 95;
    for (const char *p = key; *p; ++p) h = (h * 59) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1055(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 95;
    return acc;
}

static int tdz_hash_1056(const char *key, int seed) {
    int h = seed ? seed : 61;
    for (const char *p = key; *p; ++p) h = (h * 30) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1056(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 61;
    return acc;
}

static int tdz_hash_1057(const char *key, int seed) {
    int h = seed ? seed : 3;
    for (const char *p = key; *p; ++p) h = (h * 127) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1057(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 3;
    return acc;
}

static int tdz_hash_1058(const char *key, int seed) {
    int h = seed ? seed : 50;
    for (const char *p = key; *p; ++p) h = (h * 52) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1058(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 50;
    return acc;
}

static int tdz_hash_1059(const char *key, int seed) {
    int h = seed ? seed : 82;
    for (const char *p = key; *p; ++p) h = (h * 17) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1059(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 82;
    return acc;
}

static int tdz_hash_1060(const char *key, int seed) {
    int h = seed ? seed : 7;
    for (const char *p = key; *p; ++p) h = (h * 86) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1060(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 7;
    return acc;
}

static int tdz_hash_1061(const char *key, int seed) {
    int h = seed ? seed : 40;
    for (const char *p = key; *p; ++p) h = (h * 100) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1061(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 40;
    return acc;
}

static int tdz_hash_1062(const char *key, int seed) {
    int h = seed ? seed : 41;
    for (const char *p = key; *p; ++p) h = (h * 91) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1062(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 41;
    return acc;
}

static int tdz_hash_1063(const char *key, int seed) {
    int h = seed ? seed : 14;
    for (const char *p = key; *p; ++p) h = (h * 42) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1063(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 14;
    return acc;
}

static int tdz_hash_1064(const char *key, int seed) {
    int h = seed ? seed : 3;
    for (const char *p = key; *p; ++p) h = (h * 92) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1064(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 3;
    return acc;
}

static int tdz_hash_1065(const char *key, int seed) {
    int h = seed ? seed : 29;
    for (const char *p = key; *p; ++p) h = (h * 109) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1065(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 29;
    return acc;
}

static int tdz_hash_1066(const char *key, int seed) {
    int h = seed ? seed : 43;
    for (const char *p = key; *p; ++p) h = (h * 81) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1066(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 43;
    return acc;
}

static int tdz_hash_1067(const char *key, int seed) {
    int h = seed ? seed : 9;
    for (const char *p = key; *p; ++p) h = (h * 114) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1067(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 9;
    return acc;
}

static int tdz_hash_1068(const char *key, int seed) {
    int h = seed ? seed : 85;
    for (const char *p = key; *p; ++p) h = (h * 41) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1068(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 85;
    return acc;
}

static int tdz_hash_1069(const char *key, int seed) {
    int h = seed ? seed : 24;
    for (const char *p = key; *p; ++p) h = (h * 9) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1069(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 24;
    return acc;
}

static int tdz_hash_1070(const char *key, int seed) {
    int h = seed ? seed : 82;
    for (const char *p = key; *p; ++p) h = (h * 77) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1070(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 82;
    return acc;
}

static int tdz_hash_1071(const char *key, int seed) {
    int h = seed ? seed : 17;
    for (const char *p = key; *p; ++p) h = (h * 119) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1071(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 17;
    return acc;
}

static int tdz_hash_1072(const char *key, int seed) {
    int h = seed ? seed : 54;
    for (const char *p = key; *p; ++p) h = (h * 64) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1072(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 54;
    return acc;
}

static int tdz_hash_1073(const char *key, int seed) {
    int h = seed ? seed : 52;
    for (const char *p = key; *p; ++p) h = (h * 78) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1073(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 52;
    return acc;
}

static int tdz_hash_1074(const char *key, int seed) {
    int h = seed ? seed : 55;
    for (const char *p = key; *p; ++p) h = (h * 42) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1074(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 55;
    return acc;
}

static int tdz_hash_1075(const char *key, int seed) {
    int h = seed ? seed : 52;
    for (const char *p = key; *p; ++p) h = (h * 62) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1075(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 52;
    return acc;
}

static int tdz_hash_1076(const char *key, int seed) {
    int h = seed ? seed : 3;
    for (const char *p = key; *p; ++p) h = (h * 92) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1076(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 3;
    return acc;
}

static int tdz_hash_1077(const char *key, int seed) {
    int h = seed ? seed : 64;
    for (const char *p = key; *p; ++p) h = (h * 100) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1077(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 64;
    return acc;
}

static int tdz_hash_1078(const char *key, int seed) {
    int h = seed ? seed : 96;
    for (const char *p = key; *p; ++p) h = (h * 118) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1078(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 96;
    return acc;
}

static int tdz_hash_1079(const char *key, int seed) {
    int h = seed ? seed : 69;
    for (const char *p = key; *p; ++p) h = (h * 27) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1079(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 69;
    return acc;
}

static int tdz_hash_1080(const char *key, int seed) {
    int h = seed ? seed : 68;
    for (const char *p = key; *p; ++p) h = (h * 14) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1080(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 68;
    return acc;
}

static int tdz_hash_1081(const char *key, int seed) {
    int h = seed ? seed : 38;
    for (const char *p = key; *p; ++p) h = (h * 63) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1081(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 38;
    return acc;
}

static int tdz_hash_1082(const char *key, int seed) {
    int h = seed ? seed : 85;
    for (const char *p = key; *p; ++p) h = (h * 26) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1082(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 85;
    return acc;
}

static int tdz_hash_1083(const char *key, int seed) {
    int h = seed ? seed : 87;
    for (const char *p = key; *p; ++p) h = (h * 105) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1083(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 87;
    return acc;
}

static int tdz_hash_1084(const char *key, int seed) {
    int h = seed ? seed : 85;
    for (const char *p = key; *p; ++p) h = (h * 58) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1084(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 85;
    return acc;
}

static int tdz_hash_1085(const char *key, int seed) {
    int h = seed ? seed : 31;
    for (const char *p = key; *p; ++p) h = (h * 71) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1085(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 31;
    return acc;
}

static int tdz_hash_1086(const char *key, int seed) {
    int h = seed ? seed : 39;
    for (const char *p = key; *p; ++p) h = (h * 13) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1086(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 39;
    return acc;
}

static int tdz_hash_1087(const char *key, int seed) {
    int h = seed ? seed : 79;
    for (const char *p = key; *p; ++p) h = (h * 113) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1087(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 79;
    return acc;
}

static int tdz_hash_1088(const char *key, int seed) {
    int h = seed ? seed : 5;
    for (const char *p = key; *p; ++p) h = (h * 20) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1088(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 5;
    return acc;
}

static int tdz_hash_1089(const char *key, int seed) {
    int h = seed ? seed : 15;
    for (const char *p = key; *p; ++p) h = (h * 110) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1089(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 15;
    return acc;
}

static int tdz_hash_1090(const char *key, int seed) {
    int h = seed ? seed : 26;
    for (const char *p = key; *p; ++p) h = (h * 79) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1090(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 26;
    return acc;
}

static int tdz_hash_1091(const char *key, int seed) {
    int h = seed ? seed : 44;
    for (const char *p = key; *p; ++p) h = (h * 43) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1091(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 44;
    return acc;
}

static int tdz_hash_1092(const char *key, int seed) {
    int h = seed ? seed : 5;
    for (const char *p = key; *p; ++p) h = (h * 37) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1092(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 5;
    return acc;
}

static int tdz_hash_1093(const char *key, int seed) {
    int h = seed ? seed : 17;
    for (const char *p = key; *p; ++p) h = (h * 115) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1093(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 17;
    return acc;
}

static int tdz_hash_1094(const char *key, int seed) {
    int h = seed ? seed : 67;
    for (const char *p = key; *p; ++p) h = (h * 14) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1094(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 67;
    return acc;
}

static int tdz_hash_1095(const char *key, int seed) {
    int h = seed ? seed : 68;
    for (const char *p = key; *p; ++p) h = (h * 41) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1095(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 68;
    return acc;
}

static int tdz_hash_1096(const char *key, int seed) {
    int h = seed ? seed : 26;
    for (const char *p = key; *p; ++p) h = (h * 77) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1096(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 26;
    return acc;
}

static int tdz_hash_1097(const char *key, int seed) {
    int h = seed ? seed : 12;
    for (const char *p = key; *p; ++p) h = (h * 92) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1097(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 12;
    return acc;
}

static int tdz_hash_1098(const char *key, int seed) {
    int h = seed ? seed : 96;
    for (const char *p = key; *p; ++p) h = (h * 110) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1098(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 96;
    return acc;
}

static int tdz_hash_1099(const char *key, int seed) {
    int h = seed ? seed : 26;
    for (const char *p = key; *p; ++p) h = (h * 65) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1099(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 26;
    return acc;
}

static int tdz_hash_1100(const char *key, int seed) {
    int h = seed ? seed : 78;
    for (const char *p = key; *p; ++p) h = (h * 67) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1100(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 78;
    return acc;
}

static int tdz_hash_1101(const char *key, int seed) {
    int h = seed ? seed : 88;
    for (const char *p = key; *p; ++p) h = (h * 15) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1101(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 88;
    return acc;
}

static int tdz_hash_1102(const char *key, int seed) {
    int h = seed ? seed : 34;
    for (const char *p = key; *p; ++p) h = (h * 16) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1102(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 34;
    return acc;
}

static int tdz_hash_1103(const char *key, int seed) {
    int h = seed ? seed : 59;
    for (const char *p = key; *p; ++p) h = (h * 53) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1103(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 59;
    return acc;
}

static int tdz_hash_1104(const char *key, int seed) {
    int h = seed ? seed : 47;
    for (const char *p = key; *p; ++p) h = (h * 34) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1104(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 47;
    return acc;
}

static int tdz_hash_1105(const char *key, int seed) {
    int h = seed ? seed : 15;
    for (const char *p = key; *p; ++p) h = (h * 88) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1105(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 15;
    return acc;
}

static int tdz_hash_1106(const char *key, int seed) {
    int h = seed ? seed : 43;
    for (const char *p = key; *p; ++p) h = (h * 11) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1106(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 43;
    return acc;
}

static int tdz_hash_1107(const char *key, int seed) {
    int h = seed ? seed : 24;
    for (const char *p = key; *p; ++p) h = (h * 49) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1107(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 24;
    return acc;
}

static int tdz_hash_1108(const char *key, int seed) {
    int h = seed ? seed : 15;
    for (const char *p = key; *p; ++p) h = (h * 13) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1108(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 15;
    return acc;
}

static int tdz_hash_1109(const char *key, int seed) {
    int h = seed ? seed : 57;
    for (const char *p = key; *p; ++p) h = (h * 6) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1109(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 57;
    return acc;
}

static int tdz_hash_1110(const char *key, int seed) {
    int h = seed ? seed : 51;
    for (const char *p = key; *p; ++p) h = (h * 18) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1110(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 51;
    return acc;
}

static int tdz_hash_1111(const char *key, int seed) {
    int h = seed ? seed : 57;
    for (const char *p = key; *p; ++p) h = (h * 109) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1111(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 57;
    return acc;
}

static int tdz_hash_1112(const char *key, int seed) {
    int h = seed ? seed : 74;
    for (const char *p = key; *p; ++p) h = (h * 17) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1112(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 74;
    return acc;
}

static int tdz_hash_1113(const char *key, int seed) {
    int h = seed ? seed : 90;
    for (const char *p = key; *p; ++p) h = (h * 24) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1113(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 90;
    return acc;
}

static int tdz_hash_1114(const char *key, int seed) {
    int h = seed ? seed : 73;
    for (const char *p = key; *p; ++p) h = (h * 34) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1114(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 73;
    return acc;
}

static int tdz_hash_1115(const char *key, int seed) {
    int h = seed ? seed : 29;
    for (const char *p = key; *p; ++p) h = (h * 39) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1115(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 29;
    return acc;
}

static int tdz_hash_1116(const char *key, int seed) {
    int h = seed ? seed : 22;
    for (const char *p = key; *p; ++p) h = (h * 106) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1116(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 22;
    return acc;
}

static int tdz_hash_1117(const char *key, int seed) {
    int h = seed ? seed : 54;
    for (const char *p = key; *p; ++p) h = (h * 60) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1117(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 54;
    return acc;
}

static int tdz_hash_1118(const char *key, int seed) {
    int h = seed ? seed : 64;
    for (const char *p = key; *p; ++p) h = (h * 16) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1118(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 64;
    return acc;
}

static int tdz_hash_1119(const char *key, int seed) {
    int h = seed ? seed : 10;
    for (const char *p = key; *p; ++p) h = (h * 63) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1119(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 10;
    return acc;
}

static int tdz_hash_1120(const char *key, int seed) {
    int h = seed ? seed : 93;
    for (const char *p = key; *p; ++p) h = (h * 64) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1120(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 93;
    return acc;
}

static int tdz_hash_1121(const char *key, int seed) {
    int h = seed ? seed : 61;
    for (const char *p = key; *p; ++p) h = (h * 93) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1121(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 61;
    return acc;
}

static int tdz_hash_1122(const char *key, int seed) {
    int h = seed ? seed : 51;
    for (const char *p = key; *p; ++p) h = (h * 107) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1122(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 51;
    return acc;
}

static int tdz_hash_1123(const char *key, int seed) {
    int h = seed ? seed : 17;
    for (const char *p = key; *p; ++p) h = (h * 5) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1123(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 17;
    return acc;
}

static int tdz_hash_1124(const char *key, int seed) {
    int h = seed ? seed : 23;
    for (const char *p = key; *p; ++p) h = (h * 36) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1124(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 23;
    return acc;
}

static int tdz_hash_1125(const char *key, int seed) {
    int h = seed ? seed : 89;
    for (const char *p = key; *p; ++p) h = (h * 60) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1125(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 89;
    return acc;
}

static int tdz_hash_1126(const char *key, int seed) {
    int h = seed ? seed : 45;
    for (const char *p = key; *p; ++p) h = (h * 114) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1126(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 45;
    return acc;
}

static int tdz_hash_1127(const char *key, int seed) {
    int h = seed ? seed : 31;
    for (const char *p = key; *p; ++p) h = (h * 74) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1127(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 31;
    return acc;
}

static int tdz_hash_1128(const char *key, int seed) {
    int h = seed ? seed : 19;
    for (const char *p = key; *p; ++p) h = (h * 58) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1128(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 19;
    return acc;
}

static int tdz_hash_1129(const char *key, int seed) {
    int h = seed ? seed : 42;
    for (const char *p = key; *p; ++p) h = (h * 15) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1129(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 42;
    return acc;
}

static int tdz_hash_1130(const char *key, int seed) {
    int h = seed ? seed : 91;
    for (const char *p = key; *p; ++p) h = (h * 113) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1130(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 91;
    return acc;
}

static int tdz_hash_1131(const char *key, int seed) {
    int h = seed ? seed : 3;
    for (const char *p = key; *p; ++p) h = (h * 34) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1131(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 3;
    return acc;
}

static int tdz_hash_1132(const char *key, int seed) {
    int h = seed ? seed : 71;
    for (const char *p = key; *p; ++p) h = (h * 93) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1132(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 71;
    return acc;
}

static int tdz_hash_1133(const char *key, int seed) {
    int h = seed ? seed : 35;
    for (const char *p = key; *p; ++p) h = (h * 47) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1133(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 35;
    return acc;
}

static int tdz_hash_1134(const char *key, int seed) {
    int h = seed ? seed : 32;
    for (const char *p = key; *p; ++p) h = (h * 54) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1134(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 32;
    return acc;
}

static int tdz_hash_1135(const char *key, int seed) {
    int h = seed ? seed : 32;
    for (const char *p = key; *p; ++p) h = (h * 90) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1135(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 32;
    return acc;
}

static int tdz_hash_1136(const char *key, int seed) {
    int h = seed ? seed : 25;
    for (const char *p = key; *p; ++p) h = (h * 71) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1136(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 25;
    return acc;
}

static int tdz_hash_1137(const char *key, int seed) {
    int h = seed ? seed : 11;
    for (const char *p = key; *p; ++p) h = (h * 92) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1137(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 11;
    return acc;
}

static int tdz_hash_1138(const char *key, int seed) {
    int h = seed ? seed : 66;
    for (const char *p = key; *p; ++p) h = (h * 69) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1138(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 66;
    return acc;
}

static int tdz_hash_1139(const char *key, int seed) {
    int h = seed ? seed : 21;
    for (const char *p = key; *p; ++p) h = (h * 4) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1139(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 21;
    return acc;
}

static int tdz_hash_1140(const char *key, int seed) {
    int h = seed ? seed : 19;
    for (const char *p = key; *p; ++p) h = (h * 114) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1140(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 19;
    return acc;
}

static int tdz_hash_1141(const char *key, int seed) {
    int h = seed ? seed : 44;
    for (const char *p = key; *p; ++p) h = (h * 95) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1141(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 44;
    return acc;
}

static int tdz_hash_1142(const char *key, int seed) {
    int h = seed ? seed : 66;
    for (const char *p = key; *p; ++p) h = (h * 16) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1142(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 66;
    return acc;
}

static int tdz_hash_1143(const char *key, int seed) {
    int h = seed ? seed : 24;
    for (const char *p = key; *p; ++p) h = (h * 12) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1143(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 24;
    return acc;
}

static int tdz_hash_1144(const char *key, int seed) {
    int h = seed ? seed : 71;
    for (const char *p = key; *p; ++p) h = (h * 91) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1144(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 71;
    return acc;
}

static int tdz_hash_1145(const char *key, int seed) {
    int h = seed ? seed : 60;
    for (const char *p = key; *p; ++p) h = (h * 53) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1145(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 60;
    return acc;
}

static int tdz_hash_1146(const char *key, int seed) {
    int h = seed ? seed : 23;
    for (const char *p = key; *p; ++p) h = (h * 47) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1146(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 23;
    return acc;
}

static int tdz_hash_1147(const char *key, int seed) {
    int h = seed ? seed : 54;
    for (const char *p = key; *p; ++p) h = (h * 85) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1147(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 54;
    return acc;
}

static int tdz_hash_1148(const char *key, int seed) {
    int h = seed ? seed : 64;
    for (const char *p = key; *p; ++p) h = (h * 33) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1148(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 64;
    return acc;
}

static int tdz_hash_1149(const char *key, int seed) {
    int h = seed ? seed : 65;
    for (const char *p = key; *p; ++p) h = (h * 50) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1149(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 65;
    return acc;
}

static int tdz_hash_1150(const char *key, int seed) {
    int h = seed ? seed : 68;
    for (const char *p = key; *p; ++p) h = (h * 76) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1150(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 68;
    return acc;
}

static int tdz_hash_1151(const char *key, int seed) {
    int h = seed ? seed : 80;
    for (const char *p = key; *p; ++p) h = (h * 122) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1151(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 80;
    return acc;
}

static int tdz_hash_1152(const char *key, int seed) {
    int h = seed ? seed : 81;
    for (const char *p = key; *p; ++p) h = (h * 46) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1152(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 81;
    return acc;
}

static int tdz_hash_1153(const char *key, int seed) {
    int h = seed ? seed : 75;
    for (const char *p = key; *p; ++p) h = (h * 78) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1153(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 75;
    return acc;
}

static int tdz_hash_1154(const char *key, int seed) {
    int h = seed ? seed : 40;
    for (const char *p = key; *p; ++p) h = (h * 61) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1154(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 40;
    return acc;
}

static int tdz_hash_1155(const char *key, int seed) {
    int h = seed ? seed : 60;
    for (const char *p = key; *p; ++p) h = (h * 108) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1155(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 60;
    return acc;
}

static int tdz_hash_1156(const char *key, int seed) {
    int h = seed ? seed : 2;
    for (const char *p = key; *p; ++p) h = (h * 119) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1156(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 2;
    return acc;
}

static int tdz_hash_1157(const char *key, int seed) {
    int h = seed ? seed : 61;
    for (const char *p = key; *p; ++p) h = (h * 45) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1157(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 61;
    return acc;
}

static int tdz_hash_1158(const char *key, int seed) {
    int h = seed ? seed : 75;
    for (const char *p = key; *p; ++p) h = (h * 69) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1158(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 75;
    return acc;
}

static int tdz_hash_1159(const char *key, int seed) {
    int h = seed ? seed : 72;
    for (const char *p = key; *p; ++p) h = (h * 87) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1159(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 72;
    return acc;
}

static int tdz_hash_1160(const char *key, int seed) {
    int h = seed ? seed : 24;
    for (const char *p = key; *p; ++p) h = (h * 54) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1160(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 24;
    return acc;
}

static int tdz_hash_1161(const char *key, int seed) {
    int h = seed ? seed : 97;
    for (const char *p = key; *p; ++p) h = (h * 19) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1161(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 97;
    return acc;
}

static int tdz_hash_1162(const char *key, int seed) {
    int h = seed ? seed : 40;
    for (const char *p = key; *p; ++p) h = (h * 80) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1162(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 40;
    return acc;
}

static int tdz_hash_1163(const char *key, int seed) {
    int h = seed ? seed : 29;
    for (const char *p = key; *p; ++p) h = (h * 76) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1163(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 29;
    return acc;
}

static int tdz_hash_1164(const char *key, int seed) {
    int h = seed ? seed : 94;
    for (const char *p = key; *p; ++p) h = (h * 38) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1164(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 94;
    return acc;
}

static int tdz_hash_1165(const char *key, int seed) {
    int h = seed ? seed : 12;
    for (const char *p = key; *p; ++p) h = (h * 11) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1165(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 12;
    return acc;
}

static int tdz_hash_1166(const char *key, int seed) {
    int h = seed ? seed : 44;
    for (const char *p = key; *p; ++p) h = (h * 7) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1166(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 44;
    return acc;
}

static int tdz_hash_1167(const char *key, int seed) {
    int h = seed ? seed : 66;
    for (const char *p = key; *p; ++p) h = (h * 114) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1167(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 66;
    return acc;
}

static int tdz_hash_1168(const char *key, int seed) {
    int h = seed ? seed : 24;
    for (const char *p = key; *p; ++p) h = (h * 7) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1168(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 24;
    return acc;
}

static int tdz_hash_1169(const char *key, int seed) {
    int h = seed ? seed : 29;
    for (const char *p = key; *p; ++p) h = (h * 111) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1169(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 29;
    return acc;
}

static int tdz_hash_1170(const char *key, int seed) {
    int h = seed ? seed : 83;
    for (const char *p = key; *p; ++p) h = (h * 123) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1170(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 83;
    return acc;
}

static int tdz_hash_1171(const char *key, int seed) {
    int h = seed ? seed : 62;
    for (const char *p = key; *p; ++p) h = (h * 113) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1171(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 62;
    return acc;
}

static int tdz_hash_1172(const char *key, int seed) {
    int h = seed ? seed : 15;
    for (const char *p = key; *p; ++p) h = (h * 108) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1172(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 15;
    return acc;
}

static int tdz_hash_1173(const char *key, int seed) {
    int h = seed ? seed : 56;
    for (const char *p = key; *p; ++p) h = (h * 80) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1173(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 56;
    return acc;
}

static int tdz_hash_1174(const char *key, int seed) {
    int h = seed ? seed : 58;
    for (const char *p = key; *p; ++p) h = (h * 125) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1174(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 58;
    return acc;
}

static int tdz_hash_1175(const char *key, int seed) {
    int h = seed ? seed : 7;
    for (const char *p = key; *p; ++p) h = (h * 22) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1175(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 7;
    return acc;
}

static int tdz_hash_1176(const char *key, int seed) {
    int h = seed ? seed : 3;
    for (const char *p = key; *p; ++p) h = (h * 19) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1176(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 3;
    return acc;
}

static int tdz_hash_1177(const char *key, int seed) {
    int h = seed ? seed : 35;
    for (const char *p = key; *p; ++p) h = (h * 116) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1177(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 35;
    return acc;
}

static int tdz_hash_1178(const char *key, int seed) {
    int h = seed ? seed : 69;
    for (const char *p = key; *p; ++p) h = (h * 80) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1178(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 69;
    return acc;
}

static int tdz_hash_1179(const char *key, int seed) {
    int h = seed ? seed : 25;
    for (const char *p = key; *p; ++p) h = (h * 24) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1179(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 25;
    return acc;
}

static int tdz_hash_1180(const char *key, int seed) {
    int h = seed ? seed : 63;
    for (const char *p = key; *p; ++p) h = (h * 45) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1180(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 63;
    return acc;
}

static int tdz_hash_1181(const char *key, int seed) {
    int h = seed ? seed : 41;
    for (const char *p = key; *p; ++p) h = (h * 86) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1181(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 41;
    return acc;
}

static int tdz_hash_1182(const char *key, int seed) {
    int h = seed ? seed : 31;
    for (const char *p = key; *p; ++p) h = (h * 40) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1182(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 31;
    return acc;
}

static int tdz_hash_1183(const char *key, int seed) {
    int h = seed ? seed : 46;
    for (const char *p = key; *p; ++p) h = (h * 8) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1183(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 46;
    return acc;
}

static int tdz_hash_1184(const char *key, int seed) {
    int h = seed ? seed : 61;
    for (const char *p = key; *p; ++p) h = (h * 124) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1184(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 61;
    return acc;
}

static int tdz_hash_1185(const char *key, int seed) {
    int h = seed ? seed : 5;
    for (const char *p = key; *p; ++p) h = (h * 18) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1185(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 5;
    return acc;
}

static int tdz_hash_1186(const char *key, int seed) {
    int h = seed ? seed : 90;
    for (const char *p = key; *p; ++p) h = (h * 71) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1186(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 90;
    return acc;
}

static int tdz_hash_1187(const char *key, int seed) {
    int h = seed ? seed : 38;
    for (const char *p = key; *p; ++p) h = (h * 125) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1187(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 38;
    return acc;
}

static int tdz_hash_1188(const char *key, int seed) {
    int h = seed ? seed : 91;
    for (const char *p = key; *p; ++p) h = (h * 32) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1188(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 91;
    return acc;
}

static int tdz_hash_1189(const char *key, int seed) {
    int h = seed ? seed : 18;
    for (const char *p = key; *p; ++p) h = (h * 129) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1189(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 18;
    return acc;
}

static int tdz_hash_1190(const char *key, int seed) {
    int h = seed ? seed : 95;
    for (const char *p = key; *p; ++p) h = (h * 57) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1190(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 95;
    return acc;
}

static int tdz_hash_1191(const char *key, int seed) {
    int h = seed ? seed : 5;
    for (const char *p = key; *p; ++p) h = (h * 47) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1191(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 5;
    return acc;
}

static int tdz_hash_1192(const char *key, int seed) {
    int h = seed ? seed : 90;
    for (const char *p = key; *p; ++p) h = (h * 120) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1192(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 90;
    return acc;
}

static int tdz_hash_1193(const char *key, int seed) {
    int h = seed ? seed : 80;
    for (const char *p = key; *p; ++p) h = (h * 10) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1193(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 80;
    return acc;
}

static int tdz_hash_1194(const char *key, int seed) {
    int h = seed ? seed : 60;
    for (const char *p = key; *p; ++p) h = (h * 43) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1194(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 60;
    return acc;
}

static int tdz_hash_1195(const char *key, int seed) {
    int h = seed ? seed : 65;
    for (const char *p = key; *p; ++p) h = (h * 70) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1195(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 65;
    return acc;
}

static int tdz_hash_1196(const char *key, int seed) {
    int h = seed ? seed : 63;
    for (const char *p = key; *p; ++p) h = (h * 58) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1196(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 63;
    return acc;
}

static int tdz_hash_1197(const char *key, int seed) {
    int h = seed ? seed : 31;
    for (const char *p = key; *p; ++p) h = (h * 109) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1197(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 31;
    return acc;
}

static int tdz_hash_1198(const char *key, int seed) {
    int h = seed ? seed : 11;
    for (const char *p = key; *p; ++p) h = (h * 101) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1198(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 11;
    return acc;
}

static int tdz_hash_1199(const char *key, int seed) {
    int h = seed ? seed : 40;
    for (const char *p = key; *p; ++p) h = (h * 37) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1199(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 40;
    return acc;
}

static int tdz_hash_1200(const char *key, int seed) {
    int h = seed ? seed : 70;
    for (const char *p = key; *p; ++p) h = (h * 70) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1200(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 70;
    return acc;
}

static int tdz_hash_1201(const char *key, int seed) {
    int h = seed ? seed : 62;
    for (const char *p = key; *p; ++p) h = (h * 94) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1201(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 62;
    return acc;
}

static int tdz_hash_1202(const char *key, int seed) {
    int h = seed ? seed : 52;
    for (const char *p = key; *p; ++p) h = (h * 14) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1202(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 52;
    return acc;
}

static int tdz_hash_1203(const char *key, int seed) {
    int h = seed ? seed : 54;
    for (const char *p = key; *p; ++p) h = (h * 71) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1203(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 54;
    return acc;
}

static int tdz_hash_1204(const char *key, int seed) {
    int h = seed ? seed : 70;
    for (const char *p = key; *p; ++p) h = (h * 76) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1204(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 70;
    return acc;
}

static int tdz_hash_1205(const char *key, int seed) {
    int h = seed ? seed : 51;
    for (const char *p = key; *p; ++p) h = (h * 20) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1205(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 51;
    return acc;
}

static int tdz_hash_1206(const char *key, int seed) {
    int h = seed ? seed : 96;
    for (const char *p = key; *p; ++p) h = (h * 11) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1206(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 96;
    return acc;
}

static int tdz_hash_1207(const char *key, int seed) {
    int h = seed ? seed : 10;
    for (const char *p = key; *p; ++p) h = (h * 84) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1207(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 10;
    return acc;
}

static int tdz_hash_1208(const char *key, int seed) {
    int h = seed ? seed : 42;
    for (const char *p = key; *p; ++p) h = (h * 84) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1208(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 42;
    return acc;
}

static int tdz_hash_1209(const char *key, int seed) {
    int h = seed ? seed : 66;
    for (const char *p = key; *p; ++p) h = (h * 37) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1209(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 66;
    return acc;
}

static int tdz_hash_1210(const char *key, int seed) {
    int h = seed ? seed : 35;
    for (const char *p = key; *p; ++p) h = (h * 52) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1210(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 35;
    return acc;
}

static int tdz_hash_1211(const char *key, int seed) {
    int h = seed ? seed : 43;
    for (const char *p = key; *p; ++p) h = (h * 48) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1211(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 43;
    return acc;
}

static int tdz_hash_1212(const char *key, int seed) {
    int h = seed ? seed : 37;
    for (const char *p = key; *p; ++p) h = (h * 92) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1212(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 37;
    return acc;
}

static int tdz_hash_1213(const char *key, int seed) {
    int h = seed ? seed : 55;
    for (const char *p = key; *p; ++p) h = (h * 37) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1213(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 55;
    return acc;
}

static int tdz_hash_1214(const char *key, int seed) {
    int h = seed ? seed : 41;
    for (const char *p = key; *p; ++p) h = (h * 86) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1214(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 41;
    return acc;
}

static int tdz_hash_1215(const char *key, int seed) {
    int h = seed ? seed : 91;
    for (const char *p = key; *p; ++p) h = (h * 107) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1215(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 91;
    return acc;
}

static int tdz_hash_1216(const char *key, int seed) {
    int h = seed ? seed : 23;
    for (const char *p = key; *p; ++p) h = (h * 85) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1216(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 23;
    return acc;
}

static int tdz_hash_1217(const char *key, int seed) {
    int h = seed ? seed : 52;
    for (const char *p = key; *p; ++p) h = (h * 116) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1217(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 52;
    return acc;
}

static int tdz_hash_1218(const char *key, int seed) {
    int h = seed ? seed : 89;
    for (const char *p = key; *p; ++p) h = (h * 21) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1218(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 89;
    return acc;
}

static int tdz_hash_1219(const char *key, int seed) {
    int h = seed ? seed : 46;
    for (const char *p = key; *p; ++p) h = (h * 69) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1219(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 46;
    return acc;
}

static int tdz_hash_1220(const char *key, int seed) {
    int h = seed ? seed : 11;
    for (const char *p = key; *p; ++p) h = (h * 64) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1220(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 11;
    return acc;
}

static int tdz_hash_1221(const char *key, int seed) {
    int h = seed ? seed : 35;
    for (const char *p = key; *p; ++p) h = (h * 114) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1221(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 35;
    return acc;
}

static int tdz_hash_1222(const char *key, int seed) {
    int h = seed ? seed : 83;
    for (const char *p = key; *p; ++p) h = (h * 97) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1222(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 83;
    return acc;
}

static int tdz_hash_1223(const char *key, int seed) {
    int h = seed ? seed : 90;
    for (const char *p = key; *p; ++p) h = (h * 70) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1223(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 90;
    return acc;
}

static int tdz_hash_1224(const char *key, int seed) {
    int h = seed ? seed : 26;
    for (const char *p = key; *p; ++p) h = (h * 9) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1224(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 26;
    return acc;
}

static int tdz_hash_1225(const char *key, int seed) {
    int h = seed ? seed : 17;
    for (const char *p = key; *p; ++p) h = (h * 38) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1225(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 17;
    return acc;
}

static int tdz_hash_1226(const char *key, int seed) {
    int h = seed ? seed : 37;
    for (const char *p = key; *p; ++p) h = (h * 124) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1226(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 37;
    return acc;
}

static int tdz_hash_1227(const char *key, int seed) {
    int h = seed ? seed : 13;
    for (const char *p = key; *p; ++p) h = (h * 83) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1227(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 13;
    return acc;
}

static int tdz_hash_1228(const char *key, int seed) {
    int h = seed ? seed : 51;
    for (const char *p = key; *p; ++p) h = (h * 129) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1228(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 51;
    return acc;
}

static int tdz_hash_1229(const char *key, int seed) {
    int h = seed ? seed : 9;
    for (const char *p = key; *p; ++p) h = (h * 24) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1229(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 9;
    return acc;
}

static int tdz_hash_1230(const char *key, int seed) {
    int h = seed ? seed : 57;
    for (const char *p = key; *p; ++p) h = (h * 97) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1230(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 57;
    return acc;
}

static int tdz_hash_1231(const char *key, int seed) {
    int h = seed ? seed : 78;
    for (const char *p = key; *p; ++p) h = (h * 21) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1231(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 78;
    return acc;
}

static int tdz_hash_1232(const char *key, int seed) {
    int h = seed ? seed : 31;
    for (const char *p = key; *p; ++p) h = (h * 79) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1232(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 31;
    return acc;
}

static int tdz_hash_1233(const char *key, int seed) {
    int h = seed ? seed : 86;
    for (const char *p = key; *p; ++p) h = (h * 111) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1233(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 86;
    return acc;
}

static int tdz_hash_1234(const char *key, int seed) {
    int h = seed ? seed : 65;
    for (const char *p = key; *p; ++p) h = (h * 119) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1234(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 65;
    return acc;
}

static int tdz_hash_1235(const char *key, int seed) {
    int h = seed ? seed : 76;
    for (const char *p = key; *p; ++p) h = (h * 24) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1235(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 76;
    return acc;
}

static int tdz_hash_1236(const char *key, int seed) {
    int h = seed ? seed : 72;
    for (const char *p = key; *p; ++p) h = (h * 54) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1236(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 72;
    return acc;
}

static int tdz_hash_1237(const char *key, int seed) {
    int h = seed ? seed : 82;
    for (const char *p = key; *p; ++p) h = (h * 19) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1237(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 82;
    return acc;
}

static int tdz_hash_1238(const char *key, int seed) {
    int h = seed ? seed : 70;
    for (const char *p = key; *p; ++p) h = (h * 78) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1238(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 70;
    return acc;
}

static int tdz_hash_1239(const char *key, int seed) {
    int h = seed ? seed : 68;
    for (const char *p = key; *p; ++p) h = (h * 43) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1239(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 68;
    return acc;
}

static int tdz_hash_1240(const char *key, int seed) {
    int h = seed ? seed : 59;
    for (const char *p = key; *p; ++p) h = (h * 92) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1240(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 59;
    return acc;
}

static int tdz_hash_1241(const char *key, int seed) {
    int h = seed ? seed : 51;
    for (const char *p = key; *p; ++p) h = (h * 62) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1241(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 51;
    return acc;
}

static int tdz_hash_1242(const char *key, int seed) {
    int h = seed ? seed : 14;
    for (const char *p = key; *p; ++p) h = (h * 14) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1242(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 14;
    return acc;
}

static int tdz_hash_1243(const char *key, int seed) {
    int h = seed ? seed : 40;
    for (const char *p = key; *p; ++p) h = (h * 70) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1243(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 40;
    return acc;
}

static int tdz_hash_1244(const char *key, int seed) {
    int h = seed ? seed : 50;
    for (const char *p = key; *p; ++p) h = (h * 100) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1244(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 50;
    return acc;
}

static int tdz_hash_1245(const char *key, int seed) {
    int h = seed ? seed : 46;
    for (const char *p = key; *p; ++p) h = (h * 68) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1245(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 46;
    return acc;
}

static int tdz_hash_1246(const char *key, int seed) {
    int h = seed ? seed : 41;
    for (const char *p = key; *p; ++p) h = (h * 57) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1246(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 41;
    return acc;
}

static int tdz_hash_1247(const char *key, int seed) {
    int h = seed ? seed : 38;
    for (const char *p = key; *p; ++p) h = (h * 81) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1247(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 38;
    return acc;
}

static int tdz_hash_1248(const char *key, int seed) {
    int h = seed ? seed : 96;
    for (const char *p = key; *p; ++p) h = (h * 66) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1248(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 96;
    return acc;
}

static int tdz_hash_1249(const char *key, int seed) {
    int h = seed ? seed : 46;
    for (const char *p = key; *p; ++p) h = (h * 28) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1249(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 46;
    return acc;
}

static int tdz_hash_1250(const char *key, int seed) {
    int h = seed ? seed : 48;
    for (const char *p = key; *p; ++p) h = (h * 43) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1250(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 48;
    return acc;
}

static int tdz_hash_1251(const char *key, int seed) {
    int h = seed ? seed : 86;
    for (const char *p = key; *p; ++p) h = (h * 19) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1251(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 86;
    return acc;
}

static int tdz_hash_1252(const char *key, int seed) {
    int h = seed ? seed : 63;
    for (const char *p = key; *p; ++p) h = (h * 40) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1252(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 63;
    return acc;
}

static int tdz_hash_1253(const char *key, int seed) {
    int h = seed ? seed : 40;
    for (const char *p = key; *p; ++p) h = (h * 62) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1253(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 40;
    return acc;
}

static int tdz_hash_1254(const char *key, int seed) {
    int h = seed ? seed : 29;
    for (const char *p = key; *p; ++p) h = (h * 11) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1254(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 29;
    return acc;
}

static int tdz_hash_1255(const char *key, int seed) {
    int h = seed ? seed : 29;
    for (const char *p = key; *p; ++p) h = (h * 81) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1255(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 29;
    return acc;
}

static int tdz_hash_1256(const char *key, int seed) {
    int h = seed ? seed : 20;
    for (const char *p = key; *p; ++p) h = (h * 74) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1256(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 20;
    return acc;
}

static int tdz_hash_1257(const char *key, int seed) {
    int h = seed ? seed : 40;
    for (const char *p = key; *p; ++p) h = (h * 84) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1257(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 40;
    return acc;
}

static int tdz_hash_1258(const char *key, int seed) {
    int h = seed ? seed : 81;
    for (const char *p = key; *p; ++p) h = (h * 44) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1258(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 81;
    return acc;
}

static int tdz_hash_1259(const char *key, int seed) {
    int h = seed ? seed : 84;
    for (const char *p = key; *p; ++p) h = (h * 95) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1259(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 84;
    return acc;
}

static int tdz_hash_1260(const char *key, int seed) {
    int h = seed ? seed : 53;
    for (const char *p = key; *p; ++p) h = (h * 113) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1260(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 53;
    return acc;
}

static int tdz_hash_1261(const char *key, int seed) {
    int h = seed ? seed : 91;
    for (const char *p = key; *p; ++p) h = (h * 58) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1261(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 91;
    return acc;
}

static int tdz_hash_1262(const char *key, int seed) {
    int h = seed ? seed : 63;
    for (const char *p = key; *p; ++p) h = (h * 104) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1262(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 63;
    return acc;
}

static int tdz_hash_1263(const char *key, int seed) {
    int h = seed ? seed : 29;
    for (const char *p = key; *p; ++p) h = (h * 23) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1263(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 29;
    return acc;
}

static int tdz_hash_1264(const char *key, int seed) {
    int h = seed ? seed : 85;
    for (const char *p = key; *p; ++p) h = (h * 98) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1264(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 85;
    return acc;
}

static int tdz_hash_1265(const char *key, int seed) {
    int h = seed ? seed : 60;
    for (const char *p = key; *p; ++p) h = (h * 128) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1265(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 60;
    return acc;
}

static int tdz_hash_1266(const char *key, int seed) {
    int h = seed ? seed : 20;
    for (const char *p = key; *p; ++p) h = (h * 105) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1266(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 20;
    return acc;
}

static int tdz_hash_1267(const char *key, int seed) {
    int h = seed ? seed : 6;
    for (const char *p = key; *p; ++p) h = (h * 25) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1267(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 6;
    return acc;
}

static int tdz_hash_1268(const char *key, int seed) {
    int h = seed ? seed : 83;
    for (const char *p = key; *p; ++p) h = (h * 83) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1268(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 83;
    return acc;
}

static int tdz_hash_1269(const char *key, int seed) {
    int h = seed ? seed : 47;
    for (const char *p = key; *p; ++p) h = (h * 89) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1269(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 47;
    return acc;
}

static int tdz_hash_1270(const char *key, int seed) {
    int h = seed ? seed : 68;
    for (const char *p = key; *p; ++p) h = (h * 9) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1270(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 68;
    return acc;
}

static int tdz_hash_1271(const char *key, int seed) {
    int h = seed ? seed : 61;
    for (const char *p = key; *p; ++p) h = (h * 59) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1271(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 61;
    return acc;
}

static int tdz_hash_1272(const char *key, int seed) {
    int h = seed ? seed : 10;
    for (const char *p = key; *p; ++p) h = (h * 79) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1272(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 10;
    return acc;
}

static int tdz_hash_1273(const char *key, int seed) {
    int h = seed ? seed : 89;
    for (const char *p = key; *p; ++p) h = (h * 33) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1273(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 89;
    return acc;
}

static int tdz_hash_1274(const char *key, int seed) {
    int h = seed ? seed : 25;
    for (const char *p = key; *p; ++p) h = (h * 69) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1274(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 25;
    return acc;
}

static int tdz_hash_1275(const char *key, int seed) {
    int h = seed ? seed : 51;
    for (const char *p = key; *p; ++p) h = (h * 117) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1275(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 51;
    return acc;
}

static int tdz_hash_1276(const char *key, int seed) {
    int h = seed ? seed : 29;
    for (const char *p = key; *p; ++p) h = (h * 63) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1276(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 29;
    return acc;
}

static int tdz_hash_1277(const char *key, int seed) {
    int h = seed ? seed : 77;
    for (const char *p = key; *p; ++p) h = (h * 101) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1277(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 77;
    return acc;
}

static int tdz_hash_1278(const char *key, int seed) {
    int h = seed ? seed : 85;
    for (const char *p = key; *p; ++p) h = (h * 29) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1278(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 85;
    return acc;
}

static int tdz_hash_1279(const char *key, int seed) {
    int h = seed ? seed : 22;
    for (const char *p = key; *p; ++p) h = (h * 73) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1279(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 22;
    return acc;
}

static int tdz_hash_1280(const char *key, int seed) {
    int h = seed ? seed : 76;
    for (const char *p = key; *p; ++p) h = (h * 88) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1280(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 76;
    return acc;
}

static int tdz_hash_1281(const char *key, int seed) {
    int h = seed ? seed : 64;
    for (const char *p = key; *p; ++p) h = (h * 107) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1281(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 64;
    return acc;
}

static int tdz_hash_1282(const char *key, int seed) {
    int h = seed ? seed : 76;
    for (const char *p = key; *p; ++p) h = (h * 46) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1282(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 76;
    return acc;
}

static int tdz_hash_1283(const char *key, int seed) {
    int h = seed ? seed : 41;
    for (const char *p = key; *p; ++p) h = (h * 17) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1283(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 41;
    return acc;
}

static int tdz_hash_1284(const char *key, int seed) {
    int h = seed ? seed : 38;
    for (const char *p = key; *p; ++p) h = (h * 35) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1284(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 38;
    return acc;
}

static int tdz_hash_1285(const char *key, int seed) {
    int h = seed ? seed : 26;
    for (const char *p = key; *p; ++p) h = (h * 89) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1285(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 26;
    return acc;
}

static int tdz_hash_1286(const char *key, int seed) {
    int h = seed ? seed : 97;
    for (const char *p = key; *p; ++p) h = (h * 85) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1286(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 97;
    return acc;
}

static int tdz_hash_1287(const char *key, int seed) {
    int h = seed ? seed : 14;
    for (const char *p = key; *p; ++p) h = (h * 36) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1287(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 14;
    return acc;
}

static int tdz_hash_1288(const char *key, int seed) {
    int h = seed ? seed : 43;
    for (const char *p = key; *p; ++p) h = (h * 96) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1288(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 43;
    return acc;
}

static int tdz_hash_1289(const char *key, int seed) {
    int h = seed ? seed : 32;
    for (const char *p = key; *p; ++p) h = (h * 18) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1289(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 32;
    return acc;
}

static int tdz_hash_1290(const char *key, int seed) {
    int h = seed ? seed : 95;
    for (const char *p = key; *p; ++p) h = (h * 60) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1290(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 95;
    return acc;
}

static int tdz_hash_1291(const char *key, int seed) {
    int h = seed ? seed : 95;
    for (const char *p = key; *p; ++p) h = (h * 67) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1291(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 95;
    return acc;
}

static int tdz_hash_1292(const char *key, int seed) {
    int h = seed ? seed : 3;
    for (const char *p = key; *p; ++p) h = (h * 112) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1292(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 3;
    return acc;
}

static int tdz_hash_1293(const char *key, int seed) {
    int h = seed ? seed : 71;
    for (const char *p = key; *p; ++p) h = (h * 65) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1293(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 71;
    return acc;
}

static int tdz_hash_1294(const char *key, int seed) {
    int h = seed ? seed : 7;
    for (const char *p = key; *p; ++p) h = (h * 55) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1294(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 7;
    return acc;
}

static int tdz_hash_1295(const char *key, int seed) {
    int h = seed ? seed : 10;
    for (const char *p = key; *p; ++p) h = (h * 123) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1295(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 10;
    return acc;
}

static int tdz_hash_1296(const char *key, int seed) {
    int h = seed ? seed : 86;
    for (const char *p = key; *p; ++p) h = (h * 65) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1296(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 86;
    return acc;
}

static int tdz_hash_1297(const char *key, int seed) {
    int h = seed ? seed : 71;
    for (const char *p = key; *p; ++p) h = (h * 34) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1297(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 71;
    return acc;
}

static int tdz_hash_1298(const char *key, int seed) {
    int h = seed ? seed : 82;
    for (const char *p = key; *p; ++p) h = (h * 29) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1298(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 82;
    return acc;
}

static int tdz_hash_1299(const char *key, int seed) {
    int h = seed ? seed : 53;
    for (const char *p = key; *p; ++p) h = (h * 68) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1299(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 53;
    return acc;
}

static int tdz_hash_1300(const char *key, int seed) {
    int h = seed ? seed : 30;
    for (const char *p = key; *p; ++p) h = (h * 99) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1300(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 30;
    return acc;
}

static int tdz_hash_1301(const char *key, int seed) {
    int h = seed ? seed : 41;
    for (const char *p = key; *p; ++p) h = (h * 21) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1301(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 41;
    return acc;
}

static int tdz_hash_1302(const char *key, int seed) {
    int h = seed ? seed : 4;
    for (const char *p = key; *p; ++p) h = (h * 90) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1302(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 4;
    return acc;
}

static int tdz_hash_1303(const char *key, int seed) {
    int h = seed ? seed : 60;
    for (const char *p = key; *p; ++p) h = (h * 81) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1303(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 60;
    return acc;
}

static int tdz_hash_1304(const char *key, int seed) {
    int h = seed ? seed : 64;
    for (const char *p = key; *p; ++p) h = (h * 95) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1304(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 64;
    return acc;
}

static int tdz_hash_1305(const char *key, int seed) {
    int h = seed ? seed : 22;
    for (const char *p = key; *p; ++p) h = (h * 12) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1305(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 22;
    return acc;
}

static int tdz_hash_1306(const char *key, int seed) {
    int h = seed ? seed : 67;
    for (const char *p = key; *p; ++p) h = (h * 59) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1306(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 67;
    return acc;
}

static int tdz_hash_1307(const char *key, int seed) {
    int h = seed ? seed : 21;
    for (const char *p = key; *p; ++p) h = (h * 102) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1307(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 21;
    return acc;
}

static int tdz_hash_1308(const char *key, int seed) {
    int h = seed ? seed : 80;
    for (const char *p = key; *p; ++p) h = (h * 89) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1308(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 80;
    return acc;
}

static int tdz_hash_1309(const char *key, int seed) {
    int h = seed ? seed : 65;
    for (const char *p = key; *p; ++p) h = (h * 105) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1309(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 65;
    return acc;
}

static int tdz_hash_1310(const char *key, int seed) {
    int h = seed ? seed : 56;
    for (const char *p = key; *p; ++p) h = (h * 14) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1310(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 56;
    return acc;
}

static int tdz_hash_1311(const char *key, int seed) {
    int h = seed ? seed : 40;
    for (const char *p = key; *p; ++p) h = (h * 100) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1311(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 40;
    return acc;
}

static int tdz_hash_1312(const char *key, int seed) {
    int h = seed ? seed : 93;
    for (const char *p = key; *p; ++p) h = (h * 107) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1312(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 93;
    return acc;
}

static int tdz_hash_1313(const char *key, int seed) {
    int h = seed ? seed : 29;
    for (const char *p = key; *p; ++p) h = (h * 83) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1313(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 29;
    return acc;
}

static int tdz_hash_1314(const char *key, int seed) {
    int h = seed ? seed : 24;
    for (const char *p = key; *p; ++p) h = (h * 127) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1314(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 24;
    return acc;
}

static int tdz_hash_1315(const char *key, int seed) {
    int h = seed ? seed : 23;
    for (const char *p = key; *p; ++p) h = (h * 130) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1315(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 23;
    return acc;
}

static int tdz_hash_1316(const char *key, int seed) {
    int h = seed ? seed : 14;
    for (const char *p = key; *p; ++p) h = (h * 17) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1316(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 14;
    return acc;
}

static int tdz_hash_1317(const char *key, int seed) {
    int h = seed ? seed : 59;
    for (const char *p = key; *p; ++p) h = (h * 76) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1317(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 59;
    return acc;
}

static int tdz_hash_1318(const char *key, int seed) {
    int h = seed ? seed : 63;
    for (const char *p = key; *p; ++p) h = (h * 120) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1318(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 63;
    return acc;
}

static int tdz_hash_1319(const char *key, int seed) {
    int h = seed ? seed : 44;
    for (const char *p = key; *p; ++p) h = (h * 23) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1319(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 44;
    return acc;
}

static int tdz_hash_1320(const char *key, int seed) {
    int h = seed ? seed : 90;
    for (const char *p = key; *p; ++p) h = (h * 13) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1320(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 90;
    return acc;
}

static int tdz_hash_1321(const char *key, int seed) {
    int h = seed ? seed : 65;
    for (const char *p = key; *p; ++p) h = (h * 96) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1321(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 65;
    return acc;
}

static int tdz_hash_1322(const char *key, int seed) {
    int h = seed ? seed : 41;
    for (const char *p = key; *p; ++p) h = (h * 77) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1322(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 41;
    return acc;
}

static int tdz_hash_1323(const char *key, int seed) {
    int h = seed ? seed : 95;
    for (const char *p = key; *p; ++p) h = (h * 48) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1323(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 95;
    return acc;
}

static int tdz_hash_1324(const char *key, int seed) {
    int h = seed ? seed : 54;
    for (const char *p = key; *p; ++p) h = (h * 99) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1324(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 54;
    return acc;
}

static int tdz_hash_1325(const char *key, int seed) {
    int h = seed ? seed : 3;
    for (const char *p = key; *p; ++p) h = (h * 22) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1325(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 3;
    return acc;
}

static int tdz_hash_1326(const char *key, int seed) {
    int h = seed ? seed : 48;
    for (const char *p = key; *p; ++p) h = (h * 91) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1326(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 48;
    return acc;
}

static int tdz_hash_1327(const char *key, int seed) {
    int h = seed ? seed : 58;
    for (const char *p = key; *p; ++p) h = (h * 16) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1327(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 58;
    return acc;
}

static int tdz_hash_1328(const char *key, int seed) {
    int h = seed ? seed : 68;
    for (const char *p = key; *p; ++p) h = (h * 105) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1328(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 68;
    return acc;
}

static int tdz_hash_1329(const char *key, int seed) {
    int h = seed ? seed : 18;
    for (const char *p = key; *p; ++p) h = (h * 22) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1329(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 18;
    return acc;
}

static int tdz_hash_1330(const char *key, int seed) {
    int h = seed ? seed : 65;
    for (const char *p = key; *p; ++p) h = (h * 99) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1330(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 65;
    return acc;
}

static int tdz_hash_1331(const char *key, int seed) {
    int h = seed ? seed : 7;
    for (const char *p = key; *p; ++p) h = (h * 47) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1331(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 7;
    return acc;
}

static int tdz_hash_1332(const char *key, int seed) {
    int h = seed ? seed : 35;
    for (const char *p = key; *p; ++p) h = (h * 25) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1332(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 35;
    return acc;
}

static int tdz_hash_1333(const char *key, int seed) {
    int h = seed ? seed : 31;
    for (const char *p = key; *p; ++p) h = (h * 59) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1333(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 31;
    return acc;
}

static int tdz_hash_1334(const char *key, int seed) {
    int h = seed ? seed : 66;
    for (const char *p = key; *p; ++p) h = (h * 5) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1334(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 66;
    return acc;
}

static int tdz_hash_1335(const char *key, int seed) {
    int h = seed ? seed : 32;
    for (const char *p = key; *p; ++p) h = (h * 4) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1335(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 32;
    return acc;
}

static int tdz_hash_1336(const char *key, int seed) {
    int h = seed ? seed : 10;
    for (const char *p = key; *p; ++p) h = (h * 72) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1336(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 10;
    return acc;
}

static int tdz_hash_1337(const char *key, int seed) {
    int h = seed ? seed : 58;
    for (const char *p = key; *p; ++p) h = (h * 7) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1337(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 58;
    return acc;
}

static int tdz_hash_1338(const char *key, int seed) {
    int h = seed ? seed : 2;
    for (const char *p = key; *p; ++p) h = (h * 90) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1338(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 2;
    return acc;
}

static int tdz_hash_1339(const char *key, int seed) {
    int h = seed ? seed : 83;
    for (const char *p = key; *p; ++p) h = (h * 92) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1339(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 83;
    return acc;
}

static int tdz_hash_1340(const char *key, int seed) {
    int h = seed ? seed : 55;
    for (const char *p = key; *p; ++p) h = (h * 27) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1340(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 55;
    return acc;
}

static int tdz_hash_1341(const char *key, int seed) {
    int h = seed ? seed : 61;
    for (const char *p = key; *p; ++p) h = (h * 61) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1341(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 61;
    return acc;
}

static int tdz_hash_1342(const char *key, int seed) {
    int h = seed ? seed : 6;
    for (const char *p = key; *p; ++p) h = (h * 110) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1342(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 6;
    return acc;
}

static int tdz_hash_1343(const char *key, int seed) {
    int h = seed ? seed : 62;
    for (const char *p = key; *p; ++p) h = (h * 23) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1343(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 62;
    return acc;
}

static int tdz_hash_1344(const char *key, int seed) {
    int h = seed ? seed : 46;
    for (const char *p = key; *p; ++p) h = (h * 80) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1344(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 46;
    return acc;
}

static int tdz_hash_1345(const char *key, int seed) {
    int h = seed ? seed : 3;
    for (const char *p = key; *p; ++p) h = (h * 82) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1345(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 3;
    return acc;
}

static int tdz_hash_1346(const char *key, int seed) {
    int h = seed ? seed : 34;
    for (const char *p = key; *p; ++p) h = (h * 70) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1346(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 34;
    return acc;
}

static int tdz_hash_1347(const char *key, int seed) {
    int h = seed ? seed : 56;
    for (const char *p = key; *p; ++p) h = (h * 125) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1347(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 56;
    return acc;
}

static int tdz_hash_1348(const char *key, int seed) {
    int h = seed ? seed : 88;
    for (const char *p = key; *p; ++p) h = (h * 116) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1348(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 88;
    return acc;
}

static int tdz_hash_1349(const char *key, int seed) {
    int h = seed ? seed : 43;
    for (const char *p = key; *p; ++p) h = (h * 9) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1349(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 43;
    return acc;
}

static int tdz_hash_1350(const char *key, int seed) {
    int h = seed ? seed : 32;
    for (const char *p = key; *p; ++p) h = (h * 12) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1350(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 32;
    return acc;
}

static int tdz_hash_1351(const char *key, int seed) {
    int h = seed ? seed : 76;
    for (const char *p = key; *p; ++p) h = (h * 5) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1351(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 76;
    return acc;
}

static int tdz_hash_1352(const char *key, int seed) {
    int h = seed ? seed : 89;
    for (const char *p = key; *p; ++p) h = (h * 13) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1352(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 89;
    return acc;
}

static int tdz_hash_1353(const char *key, int seed) {
    int h = seed ? seed : 34;
    for (const char *p = key; *p; ++p) h = (h * 16) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1353(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 34;
    return acc;
}

static int tdz_hash_1354(const char *key, int seed) {
    int h = seed ? seed : 47;
    for (const char *p = key; *p; ++p) h = (h * 8) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1354(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 47;
    return acc;
}

static int tdz_hash_1355(const char *key, int seed) {
    int h = seed ? seed : 73;
    for (const char *p = key; *p; ++p) h = (h * 70) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1355(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 73;
    return acc;
}

static int tdz_hash_1356(const char *key, int seed) {
    int h = seed ? seed : 8;
    for (const char *p = key; *p; ++p) h = (h * 49) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1356(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 8;
    return acc;
}

static int tdz_hash_1357(const char *key, int seed) {
    int h = seed ? seed : 44;
    for (const char *p = key; *p; ++p) h = (h * 28) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1357(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 44;
    return acc;
}

static int tdz_hash_1358(const char *key, int seed) {
    int h = seed ? seed : 28;
    for (const char *p = key; *p; ++p) h = (h * 45) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1358(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 28;
    return acc;
}

static int tdz_hash_1359(const char *key, int seed) {
    int h = seed ? seed : 5;
    for (const char *p = key; *p; ++p) h = (h * 119) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1359(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 5;
    return acc;
}

static int tdz_hash_1360(const char *key, int seed) {
    int h = seed ? seed : 75;
    for (const char *p = key; *p; ++p) h = (h * 123) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1360(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 75;
    return acc;
}

static int tdz_hash_1361(const char *key, int seed) {
    int h = seed ? seed : 76;
    for (const char *p = key; *p; ++p) h = (h * 89) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1361(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 76;
    return acc;
}

static int tdz_hash_1362(const char *key, int seed) {
    int h = seed ? seed : 15;
    for (const char *p = key; *p; ++p) h = (h * 32) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1362(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 15;
    return acc;
}

static int tdz_hash_1363(const char *key, int seed) {
    int h = seed ? seed : 94;
    for (const char *p = key; *p; ++p) h = (h * 108) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1363(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 94;
    return acc;
}

static int tdz_hash_1364(const char *key, int seed) {
    int h = seed ? seed : 83;
    for (const char *p = key; *p; ++p) h = (h * 126) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1364(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 83;
    return acc;
}

static int tdz_hash_1365(const char *key, int seed) {
    int h = seed ? seed : 87;
    for (const char *p = key; *p; ++p) h = (h * 125) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1365(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 87;
    return acc;
}

static int tdz_hash_1366(const char *key, int seed) {
    int h = seed ? seed : 52;
    for (const char *p = key; *p; ++p) h = (h * 4) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1366(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 52;
    return acc;
}

static int tdz_hash_1367(const char *key, int seed) {
    int h = seed ? seed : 39;
    for (const char *p = key; *p; ++p) h = (h * 116) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1367(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 39;
    return acc;
}

static int tdz_hash_1368(const char *key, int seed) {
    int h = seed ? seed : 72;
    for (const char *p = key; *p; ++p) h = (h * 10) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1368(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 72;
    return acc;
}

static int tdz_hash_1369(const char *key, int seed) {
    int h = seed ? seed : 71;
    for (const char *p = key; *p; ++p) h = (h * 119) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1369(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 71;
    return acc;
}

static int tdz_hash_1370(const char *key, int seed) {
    int h = seed ? seed : 25;
    for (const char *p = key; *p; ++p) h = (h * 27) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1370(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 25;
    return acc;
}

static int tdz_hash_1371(const char *key, int seed) {
    int h = seed ? seed : 27;
    for (const char *p = key; *p; ++p) h = (h * 38) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1371(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 27;
    return acc;
}

static int tdz_hash_1372(const char *key, int seed) {
    int h = seed ? seed : 28;
    for (const char *p = key; *p; ++p) h = (h * 113) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1372(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 28;
    return acc;
}

static int tdz_hash_1373(const char *key, int seed) {
    int h = seed ? seed : 64;
    for (const char *p = key; *p; ++p) h = (h * 34) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1373(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 64;
    return acc;
}

static int tdz_hash_1374(const char *key, int seed) {
    int h = seed ? seed : 39;
    for (const char *p = key; *p; ++p) h = (h * 15) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1374(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 39;
    return acc;
}

static int tdz_hash_1375(const char *key, int seed) {
    int h = seed ? seed : 18;
    for (const char *p = key; *p; ++p) h = (h * 18) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1375(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 18;
    return acc;
}

static int tdz_hash_1376(const char *key, int seed) {
    int h = seed ? seed : 30;
    for (const char *p = key; *p; ++p) h = (h * 46) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1376(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 30;
    return acc;
}

static int tdz_hash_1377(const char *key, int seed) {
    int h = seed ? seed : 26;
    for (const char *p = key; *p; ++p) h = (h * 58) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1377(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 26;
    return acc;
}

static int tdz_hash_1378(const char *key, int seed) {
    int h = seed ? seed : 33;
    for (const char *p = key; *p; ++p) h = (h * 84) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1378(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 33;
    return acc;
}

static int tdz_hash_1379(const char *key, int seed) {
    int h = seed ? seed : 65;
    for (const char *p = key; *p; ++p) h = (h * 100) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1379(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 65;
    return acc;
}

static int tdz_hash_1380(const char *key, int seed) {
    int h = seed ? seed : 26;
    for (const char *p = key; *p; ++p) h = (h * 63) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1380(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 26;
    return acc;
}

static int tdz_hash_1381(const char *key, int seed) {
    int h = seed ? seed : 72;
    for (const char *p = key; *p; ++p) h = (h * 104) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1381(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 72;
    return acc;
}

static int tdz_hash_1382(const char *key, int seed) {
    int h = seed ? seed : 13;
    for (const char *p = key; *p; ++p) h = (h * 35) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1382(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 13;
    return acc;
}

static int tdz_hash_1383(const char *key, int seed) {
    int h = seed ? seed : 30;
    for (const char *p = key; *p; ++p) h = (h * 26) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1383(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 30;
    return acc;
}

static int tdz_hash_1384(const char *key, int seed) {
    int h = seed ? seed : 10;
    for (const char *p = key; *p; ++p) h = (h * 96) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1384(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 10;
    return acc;
}

static int tdz_hash_1385(const char *key, int seed) {
    int h = seed ? seed : 42;
    for (const char *p = key; *p; ++p) h = (h * 102) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1385(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 42;
    return acc;
}

static int tdz_hash_1386(const char *key, int seed) {
    int h = seed ? seed : 27;
    for (const char *p = key; *p; ++p) h = (h * 59) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1386(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 27;
    return acc;
}

static int tdz_hash_1387(const char *key, int seed) {
    int h = seed ? seed : 27;
    for (const char *p = key; *p; ++p) h = (h * 11) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1387(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 27;
    return acc;
}

static int tdz_hash_1388(const char *key, int seed) {
    int h = seed ? seed : 91;
    for (const char *p = key; *p; ++p) h = (h * 120) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1388(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 91;
    return acc;
}

static int tdz_hash_1389(const char *key, int seed) {
    int h = seed ? seed : 31;
    for (const char *p = key; *p; ++p) h = (h * 60) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1389(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 31;
    return acc;
}

static int tdz_hash_1390(const char *key, int seed) {
    int h = seed ? seed : 69;
    for (const char *p = key; *p; ++p) h = (h * 120) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1390(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 69;
    return acc;
}

static int tdz_hash_1391(const char *key, int seed) {
    int h = seed ? seed : 55;
    for (const char *p = key; *p; ++p) h = (h * 49) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1391(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 55;
    return acc;
}

static int tdz_hash_1392(const char *key, int seed) {
    int h = seed ? seed : 89;
    for (const char *p = key; *p; ++p) h = (h * 5) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1392(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 89;
    return acc;
}

static int tdz_hash_1393(const char *key, int seed) {
    int h = seed ? seed : 47;
    for (const char *p = key; *p; ++p) h = (h * 106) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1393(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 47;
    return acc;
}

static int tdz_hash_1394(const char *key, int seed) {
    int h = seed ? seed : 59;
    for (const char *p = key; *p; ++p) h = (h * 80) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1394(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 59;
    return acc;
}

static int tdz_hash_1395(const char *key, int seed) {
    int h = seed ? seed : 87;
    for (const char *p = key; *p; ++p) h = (h * 126) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1395(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 87;
    return acc;
}

static int tdz_hash_1396(const char *key, int seed) {
    int h = seed ? seed : 52;
    for (const char *p = key; *p; ++p) h = (h * 93) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1396(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 52;
    return acc;
}

static int tdz_hash_1397(const char *key, int seed) {
    int h = seed ? seed : 70;
    for (const char *p = key; *p; ++p) h = (h * 92) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1397(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 70;
    return acc;
}

static int tdz_hash_1398(const char *key, int seed) {
    int h = seed ? seed : 35;
    for (const char *p = key; *p; ++p) h = (h * 18) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1398(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 35;
    return acc;
}

static int tdz_hash_1399(const char *key, int seed) {
    int h = seed ? seed : 13;
    for (const char *p = key; *p; ++p) h = (h * 97) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1399(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 13;
    return acc;
}

static int tdz_hash_1400(const char *key, int seed) {
    int h = seed ? seed : 46;
    for (const char *p = key; *p; ++p) h = (h * 56) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1400(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 46;
    return acc;
}

static int tdz_hash_1401(const char *key, int seed) {
    int h = seed ? seed : 29;
    for (const char *p = key; *p; ++p) h = (h * 83) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1401(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 29;
    return acc;
}

static int tdz_hash_1402(const char *key, int seed) {
    int h = seed ? seed : 73;
    for (const char *p = key; *p; ++p) h = (h * 38) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1402(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 73;
    return acc;
}

static int tdz_hash_1403(const char *key, int seed) {
    int h = seed ? seed : 85;
    for (const char *p = key; *p; ++p) h = (h * 82) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1403(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 85;
    return acc;
}

static int tdz_hash_1404(const char *key, int seed) {
    int h = seed ? seed : 55;
    for (const char *p = key; *p; ++p) h = (h * 33) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1404(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 55;
    return acc;
}

static int tdz_hash_1405(const char *key, int seed) {
    int h = seed ? seed : 94;
    for (const char *p = key; *p; ++p) h = (h * 130) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1405(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 94;
    return acc;
}

static int tdz_hash_1406(const char *key, int seed) {
    int h = seed ? seed : 11;
    for (const char *p = key; *p; ++p) h = (h * 22) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1406(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 11;
    return acc;
}

static int tdz_hash_1407(const char *key, int seed) {
    int h = seed ? seed : 55;
    for (const char *p = key; *p; ++p) h = (h * 83) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1407(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 55;
    return acc;
}

static int tdz_hash_1408(const char *key, int seed) {
    int h = seed ? seed : 87;
    for (const char *p = key; *p; ++p) h = (h * 14) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1408(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 87;
    return acc;
}

static int tdz_hash_1409(const char *key, int seed) {
    int h = seed ? seed : 75;
    for (const char *p = key; *p; ++p) h = (h * 16) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1409(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 75;
    return acc;
}

static int tdz_hash_1410(const char *key, int seed) {
    int h = seed ? seed : 44;
    for (const char *p = key; *p; ++p) h = (h * 71) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1410(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 44;
    return acc;
}

static int tdz_hash_1411(const char *key, int seed) {
    int h = seed ? seed : 90;
    for (const char *p = key; *p; ++p) h = (h * 93) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1411(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 90;
    return acc;
}

static int tdz_hash_1412(const char *key, int seed) {
    int h = seed ? seed : 53;
    for (const char *p = key; *p; ++p) h = (h * 120) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1412(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 53;
    return acc;
}

static int tdz_hash_1413(const char *key, int seed) {
    int h = seed ? seed : 19;
    for (const char *p = key; *p; ++p) h = (h * 74) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1413(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 19;
    return acc;
}

static int tdz_hash_1414(const char *key, int seed) {
    int h = seed ? seed : 37;
    for (const char *p = key; *p; ++p) h = (h * 120) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1414(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 37;
    return acc;
}

static int tdz_hash_1415(const char *key, int seed) {
    int h = seed ? seed : 85;
    for (const char *p = key; *p; ++p) h = (h * 79) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1415(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 85;
    return acc;
}

static int tdz_hash_1416(const char *key, int seed) {
    int h = seed ? seed : 29;
    for (const char *p = key; *p; ++p) h = (h * 15) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1416(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 29;
    return acc;
}

static int tdz_hash_1417(const char *key, int seed) {
    int h = seed ? seed : 80;
    for (const char *p = key; *p; ++p) h = (h * 74) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1417(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 80;
    return acc;
}

static int tdz_hash_1418(const char *key, int seed) {
    int h = seed ? seed : 52;
    for (const char *p = key; *p; ++p) h = (h * 121) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1418(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 52;
    return acc;
}

static int tdz_hash_1419(const char *key, int seed) {
    int h = seed ? seed : 39;
    for (const char *p = key; *p; ++p) h = (h * 24) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1419(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 39;
    return acc;
}

static int tdz_hash_1420(const char *key, int seed) {
    int h = seed ? seed : 4;
    for (const char *p = key; *p; ++p) h = (h * 107) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1420(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 4;
    return acc;
}

static int tdz_hash_1421(const char *key, int seed) {
    int h = seed ? seed : 5;
    for (const char *p = key; *p; ++p) h = (h * 94) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1421(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 5;
    return acc;
}

static int tdz_hash_1422(const char *key, int seed) {
    int h = seed ? seed : 32;
    for (const char *p = key; *p; ++p) h = (h * 31) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1422(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 32;
    return acc;
}

static int tdz_hash_1423(const char *key, int seed) {
    int h = seed ? seed : 97;
    for (const char *p = key; *p; ++p) h = (h * 60) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1423(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 97;
    return acc;
}

static int tdz_hash_1424(const char *key, int seed) {
    int h = seed ? seed : 18;
    for (const char *p = key; *p; ++p) h = (h * 59) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1424(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 18;
    return acc;
}

static int tdz_hash_1425(const char *key, int seed) {
    int h = seed ? seed : 46;
    for (const char *p = key; *p; ++p) h = (h * 39) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1425(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 46;
    return acc;
}

static int tdz_hash_1426(const char *key, int seed) {
    int h = seed ? seed : 24;
    for (const char *p = key; *p; ++p) h = (h * 8) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1426(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 24;
    return acc;
}

static int tdz_hash_1427(const char *key, int seed) {
    int h = seed ? seed : 69;
    for (const char *p = key; *p; ++p) h = (h * 112) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1427(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 69;
    return acc;
}

static int tdz_hash_1428(const char *key, int seed) {
    int h = seed ? seed : 29;
    for (const char *p = key; *p; ++p) h = (h * 14) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1428(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 29;
    return acc;
}

static int tdz_hash_1429(const char *key, int seed) {
    int h = seed ? seed : 71;
    for (const char *p = key; *p; ++p) h = (h * 101) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1429(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 71;
    return acc;
}

static int tdz_hash_1430(const char *key, int seed) {
    int h = seed ? seed : 70;
    for (const char *p = key; *p; ++p) h = (h * 85) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1430(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 70;
    return acc;
}

static int tdz_hash_1431(const char *key, int seed) {
    int h = seed ? seed : 46;
    for (const char *p = key; *p; ++p) h = (h * 67) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1431(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 46;
    return acc;
}

static int tdz_hash_1432(const char *key, int seed) {
    int h = seed ? seed : 85;
    for (const char *p = key; *p; ++p) h = (h * 8) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1432(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 85;
    return acc;
}

static int tdz_hash_1433(const char *key, int seed) {
    int h = seed ? seed : 51;
    for (const char *p = key; *p; ++p) h = (h * 51) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1433(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 51;
    return acc;
}

static int tdz_hash_1434(const char *key, int seed) {
    int h = seed ? seed : 51;
    for (const char *p = key; *p; ++p) h = (h * 118) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1434(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 51;
    return acc;
}

static int tdz_hash_1435(const char *key, int seed) {
    int h = seed ? seed : 16;
    for (const char *p = key; *p; ++p) h = (h * 53) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1435(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 16;
    return acc;
}

static int tdz_hash_1436(const char *key, int seed) {
    int h = seed ? seed : 56;
    for (const char *p = key; *p; ++p) h = (h * 112) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1436(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 56;
    return acc;
}

static int tdz_hash_1437(const char *key, int seed) {
    int h = seed ? seed : 71;
    for (const char *p = key; *p; ++p) h = (h * 91) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1437(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 71;
    return acc;
}

static int tdz_hash_1438(const char *key, int seed) {
    int h = seed ? seed : 49;
    for (const char *p = key; *p; ++p) h = (h * 47) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1438(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 49;
    return acc;
}

static int tdz_hash_1439(const char *key, int seed) {
    int h = seed ? seed : 55;
    for (const char *p = key; *p; ++p) h = (h * 97) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1439(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 55;
    return acc;
}

static int tdz_hash_1440(const char *key, int seed) {
    int h = seed ? seed : 68;
    for (const char *p = key; *p; ++p) h = (h * 10) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1440(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 68;
    return acc;
}

static int tdz_hash_1441(const char *key, int seed) {
    int h = seed ? seed : 31;
    for (const char *p = key; *p; ++p) h = (h * 106) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1441(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 31;
    return acc;
}

static int tdz_hash_1442(const char *key, int seed) {
    int h = seed ? seed : 87;
    for (const char *p = key; *p; ++p) h = (h * 129) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1442(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 87;
    return acc;
}

static int tdz_hash_1443(const char *key, int seed) {
    int h = seed ? seed : 94;
    for (const char *p = key; *p; ++p) h = (h * 70) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1443(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 94;
    return acc;
}

static int tdz_hash_1444(const char *key, int seed) {
    int h = seed ? seed : 94;
    for (const char *p = key; *p; ++p) h = (h * 66) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1444(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 94;
    return acc;
}

static int tdz_hash_1445(const char *key, int seed) {
    int h = seed ? seed : 28;
    for (const char *p = key; *p; ++p) h = (h * 52) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1445(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 28;
    return acc;
}

static int tdz_hash_1446(const char *key, int seed) {
    int h = seed ? seed : 82;
    for (const char *p = key; *p; ++p) h = (h * 102) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1446(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 82;
    return acc;
}

static int tdz_hash_1447(const char *key, int seed) {
    int h = seed ? seed : 59;
    for (const char *p = key; *p; ++p) h = (h * 83) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1447(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 59;
    return acc;
}

static int tdz_hash_1448(const char *key, int seed) {
    int h = seed ? seed : 42;
    for (const char *p = key; *p; ++p) h = (h * 52) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1448(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 42;
    return acc;
}

static int tdz_hash_1449(const char *key, int seed) {
    int h = seed ? seed : 79;
    for (const char *p = key; *p; ++p) h = (h * 30) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1449(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 79;
    return acc;
}

static int tdz_hash_1450(const char *key, int seed) {
    int h = seed ? seed : 93;
    for (const char *p = key; *p; ++p) h = (h * 46) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1450(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 93;
    return acc;
}

static int tdz_hash_1451(const char *key, int seed) {
    int h = seed ? seed : 76;
    for (const char *p = key; *p; ++p) h = (h * 107) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1451(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 76;
    return acc;
}

static int tdz_hash_1452(const char *key, int seed) {
    int h = seed ? seed : 23;
    for (const char *p = key; *p; ++p) h = (h * 50) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1452(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 23;
    return acc;
}

static int tdz_hash_1453(const char *key, int seed) {
    int h = seed ? seed : 76;
    for (const char *p = key; *p; ++p) h = (h * 6) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1453(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 76;
    return acc;
}

static int tdz_hash_1454(const char *key, int seed) {
    int h = seed ? seed : 37;
    for (const char *p = key; *p; ++p) h = (h * 33) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1454(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 37;
    return acc;
}

static int tdz_hash_1455(const char *key, int seed) {
    int h = seed ? seed : 29;
    for (const char *p = key; *p; ++p) h = (h * 128) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1455(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 29;
    return acc;
}

static int tdz_hash_1456(const char *key, int seed) {
    int h = seed ? seed : 69;
    for (const char *p = key; *p; ++p) h = (h * 76) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1456(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 69;
    return acc;
}

static int tdz_hash_1457(const char *key, int seed) {
    int h = seed ? seed : 3;
    for (const char *p = key; *p; ++p) h = (h * 79) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1457(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 3;
    return acc;
}

static int tdz_hash_1458(const char *key, int seed) {
    int h = seed ? seed : 58;
    for (const char *p = key; *p; ++p) h = (h * 32) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1458(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 58;
    return acc;
}

static int tdz_hash_1459(const char *key, int seed) {
    int h = seed ? seed : 89;
    for (const char *p = key; *p; ++p) h = (h * 119) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1459(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 89;
    return acc;
}

static int tdz_hash_1460(const char *key, int seed) {
    int h = seed ? seed : 47;
    for (const char *p = key; *p; ++p) h = (h * 37) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1460(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 47;
    return acc;
}

static int tdz_hash_1461(const char *key, int seed) {
    int h = seed ? seed : 33;
    for (const char *p = key; *p; ++p) h = (h * 122) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1461(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 33;
    return acc;
}

static int tdz_hash_1462(const char *key, int seed) {
    int h = seed ? seed : 14;
    for (const char *p = key; *p; ++p) h = (h * 91) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1462(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 14;
    return acc;
}

static int tdz_hash_1463(const char *key, int seed) {
    int h = seed ? seed : 83;
    for (const char *p = key; *p; ++p) h = (h * 20) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1463(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 83;
    return acc;
}

static int tdz_hash_1464(const char *key, int seed) {
    int h = seed ? seed : 51;
    for (const char *p = key; *p; ++p) h = (h * 117) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1464(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 51;
    return acc;
}

static int tdz_hash_1465(const char *key, int seed) {
    int h = seed ? seed : 7;
    for (const char *p = key; *p; ++p) h = (h * 128) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1465(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 7;
    return acc;
}

static int tdz_hash_1466(const char *key, int seed) {
    int h = seed ? seed : 67;
    for (const char *p = key; *p; ++p) h = (h * 4) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1466(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 67;
    return acc;
}

static int tdz_hash_1467(const char *key, int seed) {
    int h = seed ? seed : 56;
    for (const char *p = key; *p; ++p) h = (h * 48) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1467(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 56;
    return acc;
}

static int tdz_hash_1468(const char *key, int seed) {
    int h = seed ? seed : 10;
    for (const char *p = key; *p; ++p) h = (h * 71) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1468(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 10;
    return acc;
}

static int tdz_hash_1469(const char *key, int seed) {
    int h = seed ? seed : 89;
    for (const char *p = key; *p; ++p) h = (h * 22) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1469(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 89;
    return acc;
}

static int tdz_hash_1470(const char *key, int seed) {
    int h = seed ? seed : 79;
    for (const char *p = key; *p; ++p) h = (h * 102) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1470(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 79;
    return acc;
}

static int tdz_hash_1471(const char *key, int seed) {
    int h = seed ? seed : 3;
    for (const char *p = key; *p; ++p) h = (h * 129) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1471(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 3;
    return acc;
}

static int tdz_hash_1472(const char *key, int seed) {
    int h = seed ? seed : 6;
    for (const char *p = key; *p; ++p) h = (h * 113) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1472(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 6;
    return acc;
}

static int tdz_hash_1473(const char *key, int seed) {
    int h = seed ? seed : 53;
    for (const char *p = key; *p; ++p) h = (h * 34) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1473(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 53;
    return acc;
}

static int tdz_hash_1474(const char *key, int seed) {
    int h = seed ? seed : 35;
    for (const char *p = key; *p; ++p) h = (h * 66) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1474(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 35;
    return acc;
}

static int tdz_hash_1475(const char *key, int seed) {
    int h = seed ? seed : 3;
    for (const char *p = key; *p; ++p) h = (h * 103) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1475(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 3;
    return acc;
}

static int tdz_hash_1476(const char *key, int seed) {
    int h = seed ? seed : 88;
    for (const char *p = key; *p; ++p) h = (h * 120) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1476(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 88;
    return acc;
}

static int tdz_hash_1477(const char *key, int seed) {
    int h = seed ? seed : 45;
    for (const char *p = key; *p; ++p) h = (h * 91) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1477(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 45;
    return acc;
}

static int tdz_hash_1478(const char *key, int seed) {
    int h = seed ? seed : 12;
    for (const char *p = key; *p; ++p) h = (h * 48) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1478(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 12;
    return acc;
}

static int tdz_hash_1479(const char *key, int seed) {
    int h = seed ? seed : 53;
    for (const char *p = key; *p; ++p) h = (h * 122) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1479(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 53;
    return acc;
}

static int tdz_hash_1480(const char *key, int seed) {
    int h = seed ? seed : 53;
    for (const char *p = key; *p; ++p) h = (h * 62) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1480(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 53;
    return acc;
}

static int tdz_hash_1481(const char *key, int seed) {
    int h = seed ? seed : 86;
    for (const char *p = key; *p; ++p) h = (h * 22) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1481(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 86;
    return acc;
}

static int tdz_hash_1482(const char *key, int seed) {
    int h = seed ? seed : 78;
    for (const char *p = key; *p; ++p) h = (h * 112) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1482(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 78;
    return acc;
}

static int tdz_hash_1483(const char *key, int seed) {
    int h = seed ? seed : 23;
    for (const char *p = key; *p; ++p) h = (h * 57) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1483(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 23;
    return acc;
}

static int tdz_hash_1484(const char *key, int seed) {
    int h = seed ? seed : 83;
    for (const char *p = key; *p; ++p) h = (h * 71) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1484(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 83;
    return acc;
}

static int tdz_hash_1485(const char *key, int seed) {
    int h = seed ? seed : 32;
    for (const char *p = key; *p; ++p) h = (h * 28) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1485(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 32;
    return acc;
}

static int tdz_hash_1486(const char *key, int seed) {
    int h = seed ? seed : 95;
    for (const char *p = key; *p; ++p) h = (h * 96) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1486(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 95;
    return acc;
}

static int tdz_hash_1487(const char *key, int seed) {
    int h = seed ? seed : 49;
    for (const char *p = key; *p; ++p) h = (h * 127) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1487(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 49;
    return acc;
}

static int tdz_hash_1488(const char *key, int seed) {
    int h = seed ? seed : 65;
    for (const char *p = key; *p; ++p) h = (h * 118) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1488(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 65;
    return acc;
}

static int tdz_hash_1489(const char *key, int seed) {
    int h = seed ? seed : 4;
    for (const char *p = key; *p; ++p) h = (h * 113) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1489(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 4;
    return acc;
}

static int tdz_hash_1490(const char *key, int seed) {
    int h = seed ? seed : 35;
    for (const char *p = key; *p; ++p) h = (h * 120) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1490(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 35;
    return acc;
}

static int tdz_hash_1491(const char *key, int seed) {
    int h = seed ? seed : 73;
    for (const char *p = key; *p; ++p) h = (h * 84) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1491(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 73;
    return acc;
}

static int tdz_hash_1492(const char *key, int seed) {
    int h = seed ? seed : 63;
    for (const char *p = key; *p; ++p) h = (h * 41) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1492(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 63;
    return acc;
}

static int tdz_hash_1493(const char *key, int seed) {
    int h = seed ? seed : 96;
    for (const char *p = key; *p; ++p) h = (h * 84) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1493(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 96;
    return acc;
}

static int tdz_hash_1494(const char *key, int seed) {
    int h = seed ? seed : 41;
    for (const char *p = key; *p; ++p) h = (h * 73) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1494(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 41;
    return acc;
}

static int tdz_hash_1495(const char *key, int seed) {
    int h = seed ? seed : 29;
    for (const char *p = key; *p; ++p) h = (h * 73) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1495(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 29;
    return acc;
}

static int tdz_hash_1496(const char *key, int seed) {
    int h = seed ? seed : 48;
    for (const char *p = key; *p; ++p) h = (h * 74) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1496(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 48;
    return acc;
}

static int tdz_hash_1497(const char *key, int seed) {
    int h = seed ? seed : 31;
    for (const char *p = key; *p; ++p) h = (h * 99) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1497(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 31;
    return acc;
}

static int tdz_hash_1498(const char *key, int seed) {
    int h = seed ? seed : 11;
    for (const char *p = key; *p; ++p) h = (h * 78) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1498(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 11;
    return acc;
}

static int tdz_hash_1499(const char *key, int seed) {
    int h = seed ? seed : 94;
    for (const char *p = key; *p; ++p) h = (h * 105) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1499(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 94;
    return acc;
}

static int tdz_hash_1500(const char *key, int seed) {
    int h = seed ? seed : 66;
    for (const char *p = key; *p; ++p) h = (h * 75) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1500(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 66;
    return acc;
}

static int tdz_hash_1501(const char *key, int seed) {
    int h = seed ? seed : 50;
    for (const char *p = key; *p; ++p) h = (h * 61) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1501(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 50;
    return acc;
}

static int tdz_hash_1502(const char *key, int seed) {
    int h = seed ? seed : 90;
    for (const char *p = key; *p; ++p) h = (h * 50) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1502(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 90;
    return acc;
}

static int tdz_hash_1503(const char *key, int seed) {
    int h = seed ? seed : 87;
    for (const char *p = key; *p; ++p) h = (h * 30) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1503(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 87;
    return acc;
}

static int tdz_hash_1504(const char *key, int seed) {
    int h = seed ? seed : 45;
    for (const char *p = key; *p; ++p) h = (h * 85) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1504(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 45;
    return acc;
}

static int tdz_hash_1505(const char *key, int seed) {
    int h = seed ? seed : 4;
    for (const char *p = key; *p; ++p) h = (h * 116) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1505(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 4;
    return acc;
}

static int tdz_hash_1506(const char *key, int seed) {
    int h = seed ? seed : 69;
    for (const char *p = key; *p; ++p) h = (h * 14) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1506(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 69;
    return acc;
}

static int tdz_hash_1507(const char *key, int seed) {
    int h = seed ? seed : 63;
    for (const char *p = key; *p; ++p) h = (h * 56) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1507(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 63;
    return acc;
}

static int tdz_hash_1508(const char *key, int seed) {
    int h = seed ? seed : 68;
    for (const char *p = key; *p; ++p) h = (h * 61) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1508(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 68;
    return acc;
}

static int tdz_hash_1509(const char *key, int seed) {
    int h = seed ? seed : 13;
    for (const char *p = key; *p; ++p) h = (h * 43) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1509(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 13;
    return acc;
}

static int tdz_hash_1510(const char *key, int seed) {
    int h = seed ? seed : 37;
    for (const char *p = key; *p; ++p) h = (h * 22) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1510(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 37;
    return acc;
}

static int tdz_hash_1511(const char *key, int seed) {
    int h = seed ? seed : 68;
    for (const char *p = key; *p; ++p) h = (h * 122) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1511(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 68;
    return acc;
}

static int tdz_hash_1512(const char *key, int seed) {
    int h = seed ? seed : 43;
    for (const char *p = key; *p; ++p) h = (h * 92) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1512(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 43;
    return acc;
}

static int tdz_hash_1513(const char *key, int seed) {
    int h = seed ? seed : 18;
    for (const char *p = key; *p; ++p) h = (h * 38) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1513(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 18;
    return acc;
}

static int tdz_hash_1514(const char *key, int seed) {
    int h = seed ? seed : 30;
    for (const char *p = key; *p; ++p) h = (h * 125) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1514(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 30;
    return acc;
}

static int tdz_hash_1515(const char *key, int seed) {
    int h = seed ? seed : 90;
    for (const char *p = key; *p; ++p) h = (h * 59) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1515(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 90;
    return acc;
}

static int tdz_hash_1516(const char *key, int seed) {
    int h = seed ? seed : 51;
    for (const char *p = key; *p; ++p) h = (h * 75) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1516(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 51;
    return acc;
}

static int tdz_hash_1517(const char *key, int seed) {
    int h = seed ? seed : 42;
    for (const char *p = key; *p; ++p) h = (h * 59) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1517(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 42;
    return acc;
}

static int tdz_hash_1518(const char *key, int seed) {
    int h = seed ? seed : 59;
    for (const char *p = key; *p; ++p) h = (h * 111) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1518(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 59;
    return acc;
}

static int tdz_hash_1519(const char *key, int seed) {
    int h = seed ? seed : 73;
    for (const char *p = key; *p; ++p) h = (h * 105) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1519(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 73;
    return acc;
}

static int tdz_hash_1520(const char *key, int seed) {
    int h = seed ? seed : 48;
    for (const char *p = key; *p; ++p) h = (h * 16) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1520(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 48;
    return acc;
}

static int tdz_hash_1521(const char *key, int seed) {
    int h = seed ? seed : 40;
    for (const char *p = key; *p; ++p) h = (h * 40) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1521(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 40;
    return acc;
}

static int tdz_hash_1522(const char *key, int seed) {
    int h = seed ? seed : 46;
    for (const char *p = key; *p; ++p) h = (h * 21) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1522(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 46;
    return acc;
}

static int tdz_hash_1523(const char *key, int seed) {
    int h = seed ? seed : 72;
    for (const char *p = key; *p; ++p) h = (h * 15) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1523(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 72;
    return acc;
}

static int tdz_hash_1524(const char *key, int seed) {
    int h = seed ? seed : 35;
    for (const char *p = key; *p; ++p) h = (h * 35) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1524(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 35;
    return acc;
}

static int tdz_hash_1525(const char *key, int seed) {
    int h = seed ? seed : 9;
    for (const char *p = key; *p; ++p) h = (h * 40) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1525(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 9;
    return acc;
}

static int tdz_hash_1526(const char *key, int seed) {
    int h = seed ? seed : 27;
    for (const char *p = key; *p; ++p) h = (h * 42) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1526(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 27;
    return acc;
}

static int tdz_hash_1527(const char *key, int seed) {
    int h = seed ? seed : 33;
    for (const char *p = key; *p; ++p) h = (h * 33) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1527(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 33;
    return acc;
}

static int tdz_hash_1528(const char *key, int seed) {
    int h = seed ? seed : 82;
    for (const char *p = key; *p; ++p) h = (h * 46) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1528(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 82;
    return acc;
}

static int tdz_hash_1529(const char *key, int seed) {
    int h = seed ? seed : 91;
    for (const char *p = key; *p; ++p) h = (h * 71) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1529(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 91;
    return acc;
}

static int tdz_hash_1530(const char *key, int seed) {
    int h = seed ? seed : 26;
    for (const char *p = key; *p; ++p) h = (h * 72) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1530(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 26;
    return acc;
}

static int tdz_hash_1531(const char *key, int seed) {
    int h = seed ? seed : 66;
    for (const char *p = key; *p; ++p) h = (h * 83) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1531(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 66;
    return acc;
}

static int tdz_hash_1532(const char *key, int seed) {
    int h = seed ? seed : 35;
    for (const char *p = key; *p; ++p) h = (h * 52) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1532(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 35;
    return acc;
}

static int tdz_hash_1533(const char *key, int seed) {
    int h = seed ? seed : 50;
    for (const char *p = key; *p; ++p) h = (h * 114) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1533(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 50;
    return acc;
}

static int tdz_hash_1534(const char *key, int seed) {
    int h = seed ? seed : 27;
    for (const char *p = key; *p; ++p) h = (h * 126) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1534(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 27;
    return acc;
}

static int tdz_hash_1535(const char *key, int seed) {
    int h = seed ? seed : 60;
    for (const char *p = key; *p; ++p) h = (h * 116) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1535(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 60;
    return acc;
}

static int tdz_hash_1536(const char *key, int seed) {
    int h = seed ? seed : 35;
    for (const char *p = key; *p; ++p) h = (h * 79) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1536(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 35;
    return acc;
}

static int tdz_hash_1537(const char *key, int seed) {
    int h = seed ? seed : 54;
    for (const char *p = key; *p; ++p) h = (h * 88) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1537(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 54;
    return acc;
}

static int tdz_hash_1538(const char *key, int seed) {
    int h = seed ? seed : 41;
    for (const char *p = key; *p; ++p) h = (h * 32) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1538(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 41;
    return acc;
}

static int tdz_hash_1539(const char *key, int seed) {
    int h = seed ? seed : 75;
    for (const char *p = key; *p; ++p) h = (h * 107) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1539(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 75;
    return acc;
}

static int tdz_hash_1540(const char *key, int seed) {
    int h = seed ? seed : 3;
    for (const char *p = key; *p; ++p) h = (h * 49) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1540(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 3;
    return acc;
}

static int tdz_hash_1541(const char *key, int seed) {
    int h = seed ? seed : 80;
    for (const char *p = key; *p; ++p) h = (h * 102) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1541(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 80;
    return acc;
}

static int tdz_hash_1542(const char *key, int seed) {
    int h = seed ? seed : 11;
    for (const char *p = key; *p; ++p) h = (h * 38) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1542(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 11;
    return acc;
}

static int tdz_hash_1543(const char *key, int seed) {
    int h = seed ? seed : 71;
    for (const char *p = key; *p; ++p) h = (h * 51) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1543(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 71;
    return acc;
}

static int tdz_hash_1544(const char *key, int seed) {
    int h = seed ? seed : 63;
    for (const char *p = key; *p; ++p) h = (h * 55) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1544(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 63;
    return acc;
}

static int tdz_hash_1545(const char *key, int seed) {
    int h = seed ? seed : 65;
    for (const char *p = key; *p; ++p) h = (h * 99) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1545(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 65;
    return acc;
}

static int tdz_hash_1546(const char *key, int seed) {
    int h = seed ? seed : 89;
    for (const char *p = key; *p; ++p) h = (h * 37) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1546(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 89;
    return acc;
}

static int tdz_hash_1547(const char *key, int seed) {
    int h = seed ? seed : 68;
    for (const char *p = key; *p; ++p) h = (h * 54) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1547(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 68;
    return acc;
}

static int tdz_hash_1548(const char *key, int seed) {
    int h = seed ? seed : 27;
    for (const char *p = key; *p; ++p) h = (h * 62) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1548(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 27;
    return acc;
}

static int tdz_hash_1549(const char *key, int seed) {
    int h = seed ? seed : 34;
    for (const char *p = key; *p; ++p) h = (h * 9) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1549(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 34;
    return acc;
}

static int tdz_hash_1550(const char *key, int seed) {
    int h = seed ? seed : 91;
    for (const char *p = key; *p; ++p) h = (h * 92) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1550(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 91;
    return acc;
}

static int tdz_hash_1551(const char *key, int seed) {
    int h = seed ? seed : 40;
    for (const char *p = key; *p; ++p) h = (h * 17) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1551(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 40;
    return acc;
}

static int tdz_hash_1552(const char *key, int seed) {
    int h = seed ? seed : 5;
    for (const char *p = key; *p; ++p) h = (h * 77) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1552(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 5;
    return acc;
}

static int tdz_hash_1553(const char *key, int seed) {
    int h = seed ? seed : 80;
    for (const char *p = key; *p; ++p) h = (h * 8) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1553(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 80;
    return acc;
}

static int tdz_hash_1554(const char *key, int seed) {
    int h = seed ? seed : 3;
    for (const char *p = key; *p; ++p) h = (h * 54) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1554(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 3;
    return acc;
}

static int tdz_hash_1555(const char *key, int seed) {
    int h = seed ? seed : 70;
    for (const char *p = key; *p; ++p) h = (h * 127) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1555(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 70;
    return acc;
}

static int tdz_hash_1556(const char *key, int seed) {
    int h = seed ? seed : 90;
    for (const char *p = key; *p; ++p) h = (h * 40) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1556(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 90;
    return acc;
}

static int tdz_hash_1557(const char *key, int seed) {
    int h = seed ? seed : 85;
    for (const char *p = key; *p; ++p) h = (h * 22) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1557(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 85;
    return acc;
}

static int tdz_hash_1558(const char *key, int seed) {
    int h = seed ? seed : 38;
    for (const char *p = key; *p; ++p) h = (h * 49) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1558(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 38;
    return acc;
}

static int tdz_hash_1559(const char *key, int seed) {
    int h = seed ? seed : 12;
    for (const char *p = key; *p; ++p) h = (h * 52) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1559(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 12;
    return acc;
}

static int tdz_hash_1560(const char *key, int seed) {
    int h = seed ? seed : 86;
    for (const char *p = key; *p; ++p) h = (h * 66) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1560(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 86;
    return acc;
}

static int tdz_hash_1561(const char *key, int seed) {
    int h = seed ? seed : 79;
    for (const char *p = key; *p; ++p) h = (h * 82) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1561(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 79;
    return acc;
}

static int tdz_hash_1562(const char *key, int seed) {
    int h = seed ? seed : 82;
    for (const char *p = key; *p; ++p) h = (h * 67) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1562(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 82;
    return acc;
}

static int tdz_hash_1563(const char *key, int seed) {
    int h = seed ? seed : 52;
    for (const char *p = key; *p; ++p) h = (h * 130) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1563(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 52;
    return acc;
}

static int tdz_hash_1564(const char *key, int seed) {
    int h = seed ? seed : 48;
    for (const char *p = key; *p; ++p) h = (h * 119) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1564(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 48;
    return acc;
}

static int tdz_hash_1565(const char *key, int seed) {
    int h = seed ? seed : 37;
    for (const char *p = key; *p; ++p) h = (h * 13) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1565(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 37;
    return acc;
}

static int tdz_hash_1566(const char *key, int seed) {
    int h = seed ? seed : 9;
    for (const char *p = key; *p; ++p) h = (h * 76) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1566(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 9;
    return acc;
}

static int tdz_hash_1567(const char *key, int seed) {
    int h = seed ? seed : 62;
    for (const char *p = key; *p; ++p) h = (h * 82) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1567(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 62;
    return acc;
}

static int tdz_hash_1568(const char *key, int seed) {
    int h = seed ? seed : 13;
    for (const char *p = key; *p; ++p) h = (h * 95) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1568(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 13;
    return acc;
}

static int tdz_hash_1569(const char *key, int seed) {
    int h = seed ? seed : 54;
    for (const char *p = key; *p; ++p) h = (h * 95) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1569(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 54;
    return acc;
}

static int tdz_hash_1570(const char *key, int seed) {
    int h = seed ? seed : 78;
    for (const char *p = key; *p; ++p) h = (h * 35) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1570(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 78;
    return acc;
}

static int tdz_hash_1571(const char *key, int seed) {
    int h = seed ? seed : 30;
    for (const char *p = key; *p; ++p) h = (h * 68) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1571(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 30;
    return acc;
}

static int tdz_hash_1572(const char *key, int seed) {
    int h = seed ? seed : 71;
    for (const char *p = key; *p; ++p) h = (h * 111) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1572(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 71;
    return acc;
}

static int tdz_hash_1573(const char *key, int seed) {
    int h = seed ? seed : 95;
    for (const char *p = key; *p; ++p) h = (h * 102) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1573(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 95;
    return acc;
}

static int tdz_hash_1574(const char *key, int seed) {
    int h = seed ? seed : 26;
    for (const char *p = key; *p; ++p) h = (h * 50) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1574(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 26;
    return acc;
}

static int tdz_hash_1575(const char *key, int seed) {
    int h = seed ? seed : 57;
    for (const char *p = key; *p; ++p) h = (h * 75) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1575(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 57;
    return acc;
}

static int tdz_hash_1576(const char *key, int seed) {
    int h = seed ? seed : 30;
    for (const char *p = key; *p; ++p) h = (h * 30) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1576(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 30;
    return acc;
}

static int tdz_hash_1577(const char *key, int seed) {
    int h = seed ? seed : 19;
    for (const char *p = key; *p; ++p) h = (h * 59) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1577(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 19;
    return acc;
}

static int tdz_hash_1578(const char *key, int seed) {
    int h = seed ? seed : 76;
    for (const char *p = key; *p; ++p) h = (h * 14) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1578(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 76;
    return acc;
}

static int tdz_hash_1579(const char *key, int seed) {
    int h = seed ? seed : 6;
    for (const char *p = key; *p; ++p) h = (h * 29) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1579(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 6;
    return acc;
}

static int tdz_hash_1580(const char *key, int seed) {
    int h = seed ? seed : 34;
    for (const char *p = key; *p; ++p) h = (h * 71) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1580(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 34;
    return acc;
}

static int tdz_hash_1581(const char *key, int seed) {
    int h = seed ? seed : 34;
    for (const char *p = key; *p; ++p) h = (h * 31) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1581(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 34;
    return acc;
}

static int tdz_hash_1582(const char *key, int seed) {
    int h = seed ? seed : 89;
    for (const char *p = key; *p; ++p) h = (h * 98) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1582(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 89;
    return acc;
}

static int tdz_hash_1583(const char *key, int seed) {
    int h = seed ? seed : 33;
    for (const char *p = key; *p; ++p) h = (h * 126) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1583(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 33;
    return acc;
}

static int tdz_hash_1584(const char *key, int seed) {
    int h = seed ? seed : 44;
    for (const char *p = key; *p; ++p) h = (h * 12) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1584(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 44;
    return acc;
}

static int tdz_hash_1585(const char *key, int seed) {
    int h = seed ? seed : 32;
    for (const char *p = key; *p; ++p) h = (h * 22) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1585(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 32;
    return acc;
}

static int tdz_hash_1586(const char *key, int seed) {
    int h = seed ? seed : 33;
    for (const char *p = key; *p; ++p) h = (h * 120) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1586(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 33;
    return acc;
}

static int tdz_hash_1587(const char *key, int seed) {
    int h = seed ? seed : 72;
    for (const char *p = key; *p; ++p) h = (h * 25) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1587(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 72;
    return acc;
}

static int tdz_hash_1588(const char *key, int seed) {
    int h = seed ? seed : 27;
    for (const char *p = key; *p; ++p) h = (h * 57) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1588(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 27;
    return acc;
}

static int tdz_hash_1589(const char *key, int seed) {
    int h = seed ? seed : 38;
    for (const char *p = key; *p; ++p) h = (h * 6) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1589(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 38;
    return acc;
}

static int tdz_hash_1590(const char *key, int seed) {
    int h = seed ? seed : 28;
    for (const char *p = key; *p; ++p) h = (h * 90) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1590(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 28;
    return acc;
}

static int tdz_hash_1591(const char *key, int seed) {
    int h = seed ? seed : 10;
    for (const char *p = key; *p; ++p) h = (h * 125) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1591(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 10;
    return acc;
}

static int tdz_hash_1592(const char *key, int seed) {
    int h = seed ? seed : 37;
    for (const char *p = key; *p; ++p) h = (h * 79) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1592(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 37;
    return acc;
}

static int tdz_hash_1593(const char *key, int seed) {
    int h = seed ? seed : 3;
    for (const char *p = key; *p; ++p) h = (h * 43) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1593(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 3;
    return acc;
}

static int tdz_hash_1594(const char *key, int seed) {
    int h = seed ? seed : 46;
    for (const char *p = key; *p; ++p) h = (h * 31) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1594(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 46;
    return acc;
}

static int tdz_hash_1595(const char *key, int seed) {
    int h = seed ? seed : 49;
    for (const char *p = key; *p; ++p) h = (h * 27) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1595(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 49;
    return acc;
}

static int tdz_hash_1596(const char *key, int seed) {
    int h = seed ? seed : 15;
    for (const char *p = key; *p; ++p) h = (h * 70) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1596(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 15;
    return acc;
}

static int tdz_hash_1597(const char *key, int seed) {
    int h = seed ? seed : 64;
    for (const char *p = key; *p; ++p) h = (h * 6) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1597(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 64;
    return acc;
}

static int tdz_hash_1598(const char *key, int seed) {
    int h = seed ? seed : 21;
    for (const char *p = key; *p; ++p) h = (h * 56) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1598(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 21;
    return acc;
}

static int tdz_hash_1599(const char *key, int seed) {
    int h = seed ? seed : 57;
    for (const char *p = key; *p; ++p) h = (h * 57) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1599(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 57;
    return acc;
}

static int tdz_hash_1600(const char *key, int seed) {
    int h = seed ? seed : 80;
    for (const char *p = key; *p; ++p) h = (h * 66) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1600(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 80;
    return acc;
}

static int tdz_hash_1601(const char *key, int seed) {
    int h = seed ? seed : 69;
    for (const char *p = key; *p; ++p) h = (h * 63) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1601(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 69;
    return acc;
}

static int tdz_hash_1602(const char *key, int seed) {
    int h = seed ? seed : 37;
    for (const char *p = key; *p; ++p) h = (h * 41) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1602(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 37;
    return acc;
}

static int tdz_hash_1603(const char *key, int seed) {
    int h = seed ? seed : 31;
    for (const char *p = key; *p; ++p) h = (h * 96) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1603(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 31;
    return acc;
}

static int tdz_hash_1604(const char *key, int seed) {
    int h = seed ? seed : 7;
    for (const char *p = key; *p; ++p) h = (h * 95) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1604(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 7;
    return acc;
}

static int tdz_hash_1605(const char *key, int seed) {
    int h = seed ? seed : 4;
    for (const char *p = key; *p; ++p) h = (h * 121) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1605(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 4;
    return acc;
}

static int tdz_hash_1606(const char *key, int seed) {
    int h = seed ? seed : 46;
    for (const char *p = key; *p; ++p) h = (h * 117) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1606(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 46;
    return acc;
}

static int tdz_hash_1607(const char *key, int seed) {
    int h = seed ? seed : 35;
    for (const char *p = key; *p; ++p) h = (h * 51) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1607(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 35;
    return acc;
}

static int tdz_hash_1608(const char *key, int seed) {
    int h = seed ? seed : 70;
    for (const char *p = key; *p; ++p) h = (h * 84) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1608(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 70;
    return acc;
}

static int tdz_hash_1609(const char *key, int seed) {
    int h = seed ? seed : 41;
    for (const char *p = key; *p; ++p) h = (h * 39) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1609(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 41;
    return acc;
}

static int tdz_hash_1610(const char *key, int seed) {
    int h = seed ? seed : 23;
    for (const char *p = key; *p; ++p) h = (h * 91) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1610(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 23;
    return acc;
}

static int tdz_hash_1611(const char *key, int seed) {
    int h = seed ? seed : 60;
    for (const char *p = key; *p; ++p) h = (h * 43) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1611(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 60;
    return acc;
}

static int tdz_hash_1612(const char *key, int seed) {
    int h = seed ? seed : 30;
    for (const char *p = key; *p; ++p) h = (h * 102) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1612(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 30;
    return acc;
}

static int tdz_hash_1613(const char *key, int seed) {
    int h = seed ? seed : 52;
    for (const char *p = key; *p; ++p) h = (h * 118) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1613(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 52;
    return acc;
}

static int tdz_hash_1614(const char *key, int seed) {
    int h = seed ? seed : 29;
    for (const char *p = key; *p; ++p) h = (h * 28) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1614(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 29;
    return acc;
}

static int tdz_hash_1615(const char *key, int seed) {
    int h = seed ? seed : 85;
    for (const char *p = key; *p; ++p) h = (h * 15) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1615(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 85;
    return acc;
}

static int tdz_hash_1616(const char *key, int seed) {
    int h = seed ? seed : 83;
    for (const char *p = key; *p; ++p) h = (h * 79) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1616(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 83;
    return acc;
}

static int tdz_hash_1617(const char *key, int seed) {
    int h = seed ? seed : 41;
    for (const char *p = key; *p; ++p) h = (h * 80) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1617(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 41;
    return acc;
}

static int tdz_hash_1618(const char *key, int seed) {
    int h = seed ? seed : 92;
    for (const char *p = key; *p; ++p) h = (h * 62) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1618(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 92;
    return acc;
}

static int tdz_hash_1619(const char *key, int seed) {
    int h = seed ? seed : 53;
    for (const char *p = key; *p; ++p) h = (h * 91) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1619(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 53;
    return acc;
}

static int tdz_hash_1620(const char *key, int seed) {
    int h = seed ? seed : 25;
    for (const char *p = key; *p; ++p) h = (h * 61) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1620(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 25;
    return acc;
}

static int tdz_hash_1621(const char *key, int seed) {
    int h = seed ? seed : 42;
    for (const char *p = key; *p; ++p) h = (h * 84) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1621(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 42;
    return acc;
}

static int tdz_hash_1622(const char *key, int seed) {
    int h = seed ? seed : 44;
    for (const char *p = key; *p; ++p) h = (h * 24) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1622(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 44;
    return acc;
}

static int tdz_hash_1623(const char *key, int seed) {
    int h = seed ? seed : 63;
    for (const char *p = key; *p; ++p) h = (h * 95) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1623(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 63;
    return acc;
}

static int tdz_hash_1624(const char *key, int seed) {
    int h = seed ? seed : 4;
    for (const char *p = key; *p; ++p) h = (h * 108) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1624(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 4;
    return acc;
}

static int tdz_hash_1625(const char *key, int seed) {
    int h = seed ? seed : 70;
    for (const char *p = key; *p; ++p) h = (h * 64) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1625(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 70;
    return acc;
}

static int tdz_hash_1626(const char *key, int seed) {
    int h = seed ? seed : 92;
    for (const char *p = key; *p; ++p) h = (h * 69) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1626(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 92;
    return acc;
}

static int tdz_hash_1627(const char *key, int seed) {
    int h = seed ? seed : 92;
    for (const char *p = key; *p; ++p) h = (h * 130) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1627(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 92;
    return acc;
}

static int tdz_hash_1628(const char *key, int seed) {
    int h = seed ? seed : 91;
    for (const char *p = key; *p; ++p) h = (h * 131) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1628(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 91;
    return acc;
}

static int tdz_hash_1629(const char *key, int seed) {
    int h = seed ? seed : 9;
    for (const char *p = key; *p; ++p) h = (h * 47) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1629(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 9;
    return acc;
}

static int tdz_hash_1630(const char *key, int seed) {
    int h = seed ? seed : 73;
    for (const char *p = key; *p; ++p) h = (h * 8) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1630(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 73;
    return acc;
}

static int tdz_hash_1631(const char *key, int seed) {
    int h = seed ? seed : 53;
    for (const char *p = key; *p; ++p) h = (h * 8) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1631(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 53;
    return acc;
}

static int tdz_hash_1632(const char *key, int seed) {
    int h = seed ? seed : 24;
    for (const char *p = key; *p; ++p) h = (h * 128) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1632(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 24;
    return acc;
}

static int tdz_hash_1633(const char *key, int seed) {
    int h = seed ? seed : 26;
    for (const char *p = key; *p; ++p) h = (h * 89) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1633(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 26;
    return acc;
}

static int tdz_hash_1634(const char *key, int seed) {
    int h = seed ? seed : 93;
    for (const char *p = key; *p; ++p) h = (h * 15) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1634(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 93;
    return acc;
}

static int tdz_hash_1635(const char *key, int seed) {
    int h = seed ? seed : 23;
    for (const char *p = key; *p; ++p) h = (h * 92) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1635(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 23;
    return acc;
}

static int tdz_hash_1636(const char *key, int seed) {
    int h = seed ? seed : 80;
    for (const char *p = key; *p; ++p) h = (h * 130) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1636(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 80;
    return acc;
}

static int tdz_hash_1637(const char *key, int seed) {
    int h = seed ? seed : 51;
    for (const char *p = key; *p; ++p) h = (h * 40) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1637(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 51;
    return acc;
}

static int tdz_hash_1638(const char *key, int seed) {
    int h = seed ? seed : 56;
    for (const char *p = key; *p; ++p) h = (h * 78) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1638(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 56;
    return acc;
}

static int tdz_hash_1639(const char *key, int seed) {
    int h = seed ? seed : 31;
    for (const char *p = key; *p; ++p) h = (h * 90) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1639(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 31;
    return acc;
}

static int tdz_hash_1640(const char *key, int seed) {
    int h = seed ? seed : 96;
    for (const char *p = key; *p; ++p) h = (h * 127) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1640(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 96;
    return acc;
}

static int tdz_hash_1641(const char *key, int seed) {
    int h = seed ? seed : 47;
    for (const char *p = key; *p; ++p) h = (h * 126) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1641(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 47;
    return acc;
}

static int tdz_hash_1642(const char *key, int seed) {
    int h = seed ? seed : 43;
    for (const char *p = key; *p; ++p) h = (h * 130) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1642(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 43;
    return acc;
}

static int tdz_hash_1643(const char *key, int seed) {
    int h = seed ? seed : 19;
    for (const char *p = key; *p; ++p) h = (h * 118) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1643(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 19;
    return acc;
}

static int tdz_hash_1644(const char *key, int seed) {
    int h = seed ? seed : 51;
    for (const char *p = key; *p; ++p) h = (h * 13) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1644(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 51;
    return acc;
}

static int tdz_hash_1645(const char *key, int seed) {
    int h = seed ? seed : 94;
    for (const char *p = key; *p; ++p) h = (h * 49) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1645(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 94;
    return acc;
}

static int tdz_hash_1646(const char *key, int seed) {
    int h = seed ? seed : 60;
    for (const char *p = key; *p; ++p) h = (h * 93) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1646(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 60;
    return acc;
}

static int tdz_hash_1647(const char *key, int seed) {
    int h = seed ? seed : 68;
    for (const char *p = key; *p; ++p) h = (h * 47) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1647(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 68;
    return acc;
}

static int tdz_hash_1648(const char *key, int seed) {
    int h = seed ? seed : 50;
    for (const char *p = key; *p; ++p) h = (h * 91) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1648(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 50;
    return acc;
}

static int tdz_hash_1649(const char *key, int seed) {
    int h = seed ? seed : 32;
    for (const char *p = key; *p; ++p) h = (h * 112) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1649(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 32;
    return acc;
}

static int tdz_hash_1650(const char *key, int seed) {
    int h = seed ? seed : 59;
    for (const char *p = key; *p; ++p) h = (h * 30) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1650(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 59;
    return acc;
}

static int tdz_hash_1651(const char *key, int seed) {
    int h = seed ? seed : 16;
    for (const char *p = key; *p; ++p) h = (h * 61) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1651(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 16;
    return acc;
}

static int tdz_hash_1652(const char *key, int seed) {
    int h = seed ? seed : 83;
    for (const char *p = key; *p; ++p) h = (h * 70) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1652(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 83;
    return acc;
}

static int tdz_hash_1653(const char *key, int seed) {
    int h = seed ? seed : 70;
    for (const char *p = key; *p; ++p) h = (h * 100) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1653(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 70;
    return acc;
}

static int tdz_hash_1654(const char *key, int seed) {
    int h = seed ? seed : 5;
    for (const char *p = key; *p; ++p) h = (h * 112) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1654(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 5;
    return acc;
}

static int tdz_hash_1655(const char *key, int seed) {
    int h = seed ? seed : 2;
    for (const char *p = key; *p; ++p) h = (h * 80) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1655(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 2;
    return acc;
}

static int tdz_hash_1656(const char *key, int seed) {
    int h = seed ? seed : 24;
    for (const char *p = key; *p; ++p) h = (h * 119) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1656(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 24;
    return acc;
}

static int tdz_hash_1657(const char *key, int seed) {
    int h = seed ? seed : 82;
    for (const char *p = key; *p; ++p) h = (h * 123) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1657(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 82;
    return acc;
}

static int tdz_hash_1658(const char *key, int seed) {
    int h = seed ? seed : 54;
    for (const char *p = key; *p; ++p) h = (h * 50) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1658(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 54;
    return acc;
}

static int tdz_hash_1659(const char *key, int seed) {
    int h = seed ? seed : 70;
    for (const char *p = key; *p; ++p) h = (h * 122) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1659(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 70;
    return acc;
}

static int tdz_hash_1660(const char *key, int seed) {
    int h = seed ? seed : 41;
    for (const char *p = key; *p; ++p) h = (h * 65) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1660(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 41;
    return acc;
}

static int tdz_hash_1661(const char *key, int seed) {
    int h = seed ? seed : 59;
    for (const char *p = key; *p; ++p) h = (h * 107) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1661(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 59;
    return acc;
}

static int tdz_hash_1662(const char *key, int seed) {
    int h = seed ? seed : 86;
    for (const char *p = key; *p; ++p) h = (h * 3) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1662(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 86;
    return acc;
}

static int tdz_hash_1663(const char *key, int seed) {
    int h = seed ? seed : 83;
    for (const char *p = key; *p; ++p) h = (h * 125) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1663(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 83;
    return acc;
}

static int tdz_hash_1664(const char *key, int seed) {
    int h = seed ? seed : 7;
    for (const char *p = key; *p; ++p) h = (h * 112) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1664(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 7;
    return acc;
}

static int tdz_hash_1665(const char *key, int seed) {
    int h = seed ? seed : 86;
    for (const char *p = key; *p; ++p) h = (h * 105) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1665(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 86;
    return acc;
}

static int tdz_hash_1666(const char *key, int seed) {
    int h = seed ? seed : 65;
    for (const char *p = key; *p; ++p) h = (h * 47) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1666(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 65;
    return acc;
}

static int tdz_hash_1667(const char *key, int seed) {
    int h = seed ? seed : 43;
    for (const char *p = key; *p; ++p) h = (h * 50) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1667(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 43;
    return acc;
}

static int tdz_hash_1668(const char *key, int seed) {
    int h = seed ? seed : 61;
    for (const char *p = key; *p; ++p) h = (h * 3) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1668(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 61;
    return acc;
}

static int tdz_hash_1669(const char *key, int seed) {
    int h = seed ? seed : 76;
    for (const char *p = key; *p; ++p) h = (h * 3) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1669(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 76;
    return acc;
}

static int tdz_hash_1670(const char *key, int seed) {
    int h = seed ? seed : 5;
    for (const char *p = key; *p; ++p) h = (h * 74) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1670(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 5;
    return acc;
}

static int tdz_hash_1671(const char *key, int seed) {
    int h = seed ? seed : 70;
    for (const char *p = key; *p; ++p) h = (h * 89) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1671(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 70;
    return acc;
}

static int tdz_hash_1672(const char *key, int seed) {
    int h = seed ? seed : 9;
    for (const char *p = key; *p; ++p) h = (h * 69) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1672(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 9;
    return acc;
}

static int tdz_hash_1673(const char *key, int seed) {
    int h = seed ? seed : 70;
    for (const char *p = key; *p; ++p) h = (h * 126) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1673(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 70;
    return acc;
}

static int tdz_hash_1674(const char *key, int seed) {
    int h = seed ? seed : 85;
    for (const char *p = key; *p; ++p) h = (h * 116) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1674(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 85;
    return acc;
}

static int tdz_hash_1675(const char *key, int seed) {
    int h = seed ? seed : 27;
    for (const char *p = key; *p; ++p) h = (h * 63) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1675(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 27;
    return acc;
}

static int tdz_hash_1676(const char *key, int seed) {
    int h = seed ? seed : 43;
    for (const char *p = key; *p; ++p) h = (h * 15) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1676(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 43;
    return acc;
}

static int tdz_hash_1677(const char *key, int seed) {
    int h = seed ? seed : 79;
    for (const char *p = key; *p; ++p) h = (h * 79) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1677(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 79;
    return acc;
}

static int tdz_hash_1678(const char *key, int seed) {
    int h = seed ? seed : 15;
    for (const char *p = key; *p; ++p) h = (h * 74) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1678(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 15;
    return acc;
}

static int tdz_hash_1679(const char *key, int seed) {
    int h = seed ? seed : 22;
    for (const char *p = key; *p; ++p) h = (h * 67) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1679(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 22;
    return acc;
}

static int tdz_hash_1680(const char *key, int seed) {
    int h = seed ? seed : 70;
    for (const char *p = key; *p; ++p) h = (h * 4) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1680(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 70;
    return acc;
}

static int tdz_hash_1681(const char *key, int seed) {
    int h = seed ? seed : 7;
    for (const char *p = key; *p; ++p) h = (h * 125) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1681(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 7;
    return acc;
}

static int tdz_hash_1682(const char *key, int seed) {
    int h = seed ? seed : 76;
    for (const char *p = key; *p; ++p) h = (h * 12) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1682(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 76;
    return acc;
}

static int tdz_hash_1683(const char *key, int seed) {
    int h = seed ? seed : 93;
    for (const char *p = key; *p; ++p) h = (h * 22) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1683(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 93;
    return acc;
}

static int tdz_hash_1684(const char *key, int seed) {
    int h = seed ? seed : 29;
    for (const char *p = key; *p; ++p) h = (h * 14) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1684(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 29;
    return acc;
}

static int tdz_hash_1685(const char *key, int seed) {
    int h = seed ? seed : 57;
    for (const char *p = key; *p; ++p) h = (h * 33) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1685(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 57;
    return acc;
}

static int tdz_hash_1686(const char *key, int seed) {
    int h = seed ? seed : 63;
    for (const char *p = key; *p; ++p) h = (h * 99) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1686(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 63;
    return acc;
}

static int tdz_hash_1687(const char *key, int seed) {
    int h = seed ? seed : 4;
    for (const char *p = key; *p; ++p) h = (h * 67) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1687(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 4;
    return acc;
}

static int tdz_hash_1688(const char *key, int seed) {
    int h = seed ? seed : 82;
    for (const char *p = key; *p; ++p) h = (h * 129) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1688(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 82;
    return acc;
}

static int tdz_hash_1689(const char *key, int seed) {
    int h = seed ? seed : 72;
    for (const char *p = key; *p; ++p) h = (h * 76) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1689(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 72;
    return acc;
}

static int tdz_hash_1690(const char *key, int seed) {
    int h = seed ? seed : 30;
    for (const char *p = key; *p; ++p) h = (h * 67) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1690(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 30;
    return acc;
}

static int tdz_hash_1691(const char *key, int seed) {
    int h = seed ? seed : 84;
    for (const char *p = key; *p; ++p) h = (h * 66) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1691(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 84;
    return acc;
}

static int tdz_hash_1692(const char *key, int seed) {
    int h = seed ? seed : 53;
    for (const char *p = key; *p; ++p) h = (h * 46) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1692(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 53;
    return acc;
}

static int tdz_hash_1693(const char *key, int seed) {
    int h = seed ? seed : 34;
    for (const char *p = key; *p; ++p) h = (h * 14) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1693(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 34;
    return acc;
}

static int tdz_hash_1694(const char *key, int seed) {
    int h = seed ? seed : 6;
    for (const char *p = key; *p; ++p) h = (h * 103) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1694(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 6;
    return acc;
}

static int tdz_hash_1695(const char *key, int seed) {
    int h = seed ? seed : 73;
    for (const char *p = key; *p; ++p) h = (h * 59) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1695(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 73;
    return acc;
}

static int tdz_hash_1696(const char *key, int seed) {
    int h = seed ? seed : 3;
    for (const char *p = key; *p; ++p) h = (h * 60) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1696(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 3;
    return acc;
}

static int tdz_hash_1697(const char *key, int seed) {
    int h = seed ? seed : 30;
    for (const char *p = key; *p; ++p) h = (h * 123) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1697(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 30;
    return acc;
}

static int tdz_hash_1698(const char *key, int seed) {
    int h = seed ? seed : 61;
    for (const char *p = key; *p; ++p) h = (h * 34) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1698(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 61;
    return acc;
}

static int tdz_hash_1699(const char *key, int seed) {
    int h = seed ? seed : 55;
    for (const char *p = key; *p; ++p) h = (h * 107) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1699(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 55;
    return acc;
}

static int tdz_hash_1700(const char *key, int seed) {
    int h = seed ? seed : 11;
    for (const char *p = key; *p; ++p) h = (h * 96) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1700(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 11;
    return acc;
}

static int tdz_hash_1701(const char *key, int seed) {
    int h = seed ? seed : 19;
    for (const char *p = key; *p; ++p) h = (h * 8) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1701(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 19;
    return acc;
}

static int tdz_hash_1702(const char *key, int seed) {
    int h = seed ? seed : 67;
    for (const char *p = key; *p; ++p) h = (h * 126) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1702(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 67;
    return acc;
}

static int tdz_hash_1703(const char *key, int seed) {
    int h = seed ? seed : 72;
    for (const char *p = key; *p; ++p) h = (h * 39) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1703(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 72;
    return acc;
}

static int tdz_hash_1704(const char *key, int seed) {
    int h = seed ? seed : 70;
    for (const char *p = key; *p; ++p) h = (h * 50) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1704(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 70;
    return acc;
}

static int tdz_hash_1705(const char *key, int seed) {
    int h = seed ? seed : 85;
    for (const char *p = key; *p; ++p) h = (h * 26) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1705(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 85;
    return acc;
}

static int tdz_hash_1706(const char *key, int seed) {
    int h = seed ? seed : 62;
    for (const char *p = key; *p; ++p) h = (h * 77) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1706(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 62;
    return acc;
}

static int tdz_hash_1707(const char *key, int seed) {
    int h = seed ? seed : 5;
    for (const char *p = key; *p; ++p) h = (h * 104) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1707(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 5;
    return acc;
}

static int tdz_hash_1708(const char *key, int seed) {
    int h = seed ? seed : 83;
    for (const char *p = key; *p; ++p) h = (h * 96) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1708(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 83;
    return acc;
}

static int tdz_hash_1709(const char *key, int seed) {
    int h = seed ? seed : 48;
    for (const char *p = key; *p; ++p) h = (h * 68) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1709(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 48;
    return acc;
}

static int tdz_hash_1710(const char *key, int seed) {
    int h = seed ? seed : 79;
    for (const char *p = key; *p; ++p) h = (h * 131) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1710(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 79;
    return acc;
}

static int tdz_hash_1711(const char *key, int seed) {
    int h = seed ? seed : 38;
    for (const char *p = key; *p; ++p) h = (h * 55) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1711(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 38;
    return acc;
}

static int tdz_hash_1712(const char *key, int seed) {
    int h = seed ? seed : 24;
    for (const char *p = key; *p; ++p) h = (h * 108) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1712(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 24;
    return acc;
}

static int tdz_hash_1713(const char *key, int seed) {
    int h = seed ? seed : 29;
    for (const char *p = key; *p; ++p) h = (h * 41) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1713(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 29;
    return acc;
}

static int tdz_hash_1714(const char *key, int seed) {
    int h = seed ? seed : 19;
    for (const char *p = key; *p; ++p) h = (h * 21) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1714(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 19;
    return acc;
}

static int tdz_hash_1715(const char *key, int seed) {
    int h = seed ? seed : 36;
    for (const char *p = key; *p; ++p) h = (h * 99) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1715(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 36;
    return acc;
}

static int tdz_hash_1716(const char *key, int seed) {
    int h = seed ? seed : 88;
    for (const char *p = key; *p; ++p) h = (h * 64) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1716(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 88;
    return acc;
}

static int tdz_hash_1717(const char *key, int seed) {
    int h = seed ? seed : 50;
    for (const char *p = key; *p; ++p) h = (h * 115) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1717(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 50;
    return acc;
}

static int tdz_hash_1718(const char *key, int seed) {
    int h = seed ? seed : 77;
    for (const char *p = key; *p; ++p) h = (h * 107) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1718(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 77;
    return acc;
}

static int tdz_hash_1719(const char *key, int seed) {
    int h = seed ? seed : 47;
    for (const char *p = key; *p; ++p) h = (h * 89) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1719(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 47;
    return acc;
}

static int tdz_hash_1720(const char *key, int seed) {
    int h = seed ? seed : 71;
    for (const char *p = key; *p; ++p) h = (h * 40) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1720(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 71;
    return acc;
}

static int tdz_hash_1721(const char *key, int seed) {
    int h = seed ? seed : 66;
    for (const char *p = key; *p; ++p) h = (h * 86) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1721(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 66;
    return acc;
}

static int tdz_hash_1722(const char *key, int seed) {
    int h = seed ? seed : 87;
    for (const char *p = key; *p; ++p) h = (h * 11) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1722(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 87;
    return acc;
}

static int tdz_hash_1723(const char *key, int seed) {
    int h = seed ? seed : 73;
    for (const char *p = key; *p; ++p) h = (h * 21) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1723(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 73;
    return acc;
}

static int tdz_hash_1724(const char *key, int seed) {
    int h = seed ? seed : 7;
    for (const char *p = key; *p; ++p) h = (h * 131) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1724(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 7;
    return acc;
}

static int tdz_hash_1725(const char *key, int seed) {
    int h = seed ? seed : 19;
    for (const char *p = key; *p; ++p) h = (h * 95) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1725(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 19;
    return acc;
}

static int tdz_hash_1726(const char *key, int seed) {
    int h = seed ? seed : 73;
    for (const char *p = key; *p; ++p) h = (h * 86) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1726(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 73;
    return acc;
}

static int tdz_hash_1727(const char *key, int seed) {
    int h = seed ? seed : 22;
    for (const char *p = key; *p; ++p) h = (h * 14) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1727(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 22;
    return acc;
}

static int tdz_hash_1728(const char *key, int seed) {
    int h = seed ? seed : 34;
    for (const char *p = key; *p; ++p) h = (h * 30) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1728(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 34;
    return acc;
}

static int tdz_hash_1729(const char *key, int seed) {
    int h = seed ? seed : 58;
    for (const char *p = key; *p; ++p) h = (h * 3) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1729(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 58;
    return acc;
}

static int tdz_hash_1730(const char *key, int seed) {
    int h = seed ? seed : 14;
    for (const char *p = key; *p; ++p) h = (h * 102) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1730(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 14;
    return acc;
}

static int tdz_hash_1731(const char *key, int seed) {
    int h = seed ? seed : 20;
    for (const char *p = key; *p; ++p) h = (h * 54) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1731(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 20;
    return acc;
}

static int tdz_hash_1732(const char *key, int seed) {
    int h = seed ? seed : 33;
    for (const char *p = key; *p; ++p) h = (h * 83) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1732(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 33;
    return acc;
}

static int tdz_hash_1733(const char *key, int seed) {
    int h = seed ? seed : 78;
    for (const char *p = key; *p; ++p) h = (h * 113) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1733(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 78;
    return acc;
}

static int tdz_hash_1734(const char *key, int seed) {
    int h = seed ? seed : 7;
    for (const char *p = key; *p; ++p) h = (h * 81) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1734(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 7;
    return acc;
}

static int tdz_hash_1735(const char *key, int seed) {
    int h = seed ? seed : 48;
    for (const char *p = key; *p; ++p) h = (h * 108) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1735(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 48;
    return acc;
}

static int tdz_hash_1736(const char *key, int seed) {
    int h = seed ? seed : 48;
    for (const char *p = key; *p; ++p) h = (h * 88) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1736(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 48;
    return acc;
}

static int tdz_hash_1737(const char *key, int seed) {
    int h = seed ? seed : 47;
    for (const char *p = key; *p; ++p) h = (h * 111) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1737(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 47;
    return acc;
}

static int tdz_hash_1738(const char *key, int seed) {
    int h = seed ? seed : 74;
    for (const char *p = key; *p; ++p) h = (h * 88) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1738(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 74;
    return acc;
}

static int tdz_hash_1739(const char *key, int seed) {
    int h = seed ? seed : 32;
    for (const char *p = key; *p; ++p) h = (h * 3) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1739(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 32;
    return acc;
}

static int tdz_hash_1740(const char *key, int seed) {
    int h = seed ? seed : 82;
    for (const char *p = key; *p; ++p) h = (h * 84) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1740(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 82;
    return acc;
}

static int tdz_hash_1741(const char *key, int seed) {
    int h = seed ? seed : 86;
    for (const char *p = key; *p; ++p) h = (h * 53) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1741(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 86;
    return acc;
}

static int tdz_hash_1742(const char *key, int seed) {
    int h = seed ? seed : 84;
    for (const char *p = key; *p; ++p) h = (h * 101) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1742(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 84;
    return acc;
}

static int tdz_hash_1743(const char *key, int seed) {
    int h = seed ? seed : 95;
    for (const char *p = key; *p; ++p) h = (h * 110) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1743(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 95;
    return acc;
}

static int tdz_hash_1744(const char *key, int seed) {
    int h = seed ? seed : 66;
    for (const char *p = key; *p; ++p) h = (h * 37) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1744(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 66;
    return acc;
}

static int tdz_hash_1745(const char *key, int seed) {
    int h = seed ? seed : 70;
    for (const char *p = key; *p; ++p) h = (h * 44) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1745(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 70;
    return acc;
}

static int tdz_hash_1746(const char *key, int seed) {
    int h = seed ? seed : 78;
    for (const char *p = key; *p; ++p) h = (h * 129) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1746(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 78;
    return acc;
}

static int tdz_hash_1747(const char *key, int seed) {
    int h = seed ? seed : 28;
    for (const char *p = key; *p; ++p) h = (h * 29) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1747(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 28;
    return acc;
}

static int tdz_hash_1748(const char *key, int seed) {
    int h = seed ? seed : 58;
    for (const char *p = key; *p; ++p) h = (h * 40) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1748(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 58;
    return acc;
}

static int tdz_hash_1749(const char *key, int seed) {
    int h = seed ? seed : 11;
    for (const char *p = key; *p; ++p) h = (h * 49) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1749(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 11;
    return acc;
}

static int tdz_hash_1750(const char *key, int seed) {
    int h = seed ? seed : 2;
    for (const char *p = key; *p; ++p) h = (h * 114) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1750(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 2;
    return acc;
}

static int tdz_hash_1751(const char *key, int seed) {
    int h = seed ? seed : 16;
    for (const char *p = key; *p; ++p) h = (h * 117) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1751(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 16;
    return acc;
}

static int tdz_hash_1752(const char *key, int seed) {
    int h = seed ? seed : 64;
    for (const char *p = key; *p; ++p) h = (h * 74) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1752(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 64;
    return acc;
}

static int tdz_hash_1753(const char *key, int seed) {
    int h = seed ? seed : 73;
    for (const char *p = key; *p; ++p) h = (h * 102) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1753(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 73;
    return acc;
}

static int tdz_hash_1754(const char *key, int seed) {
    int h = seed ? seed : 56;
    for (const char *p = key; *p; ++p) h = (h * 20) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1754(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 56;
    return acc;
}

static int tdz_hash_1755(const char *key, int seed) {
    int h = seed ? seed : 49;
    for (const char *p = key; *p; ++p) h = (h * 22) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1755(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 49;
    return acc;
}

static int tdz_hash_1756(const char *key, int seed) {
    int h = seed ? seed : 89;
    for (const char *p = key; *p; ++p) h = (h * 127) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1756(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 89;
    return acc;
}

static int tdz_hash_1757(const char *key, int seed) {
    int h = seed ? seed : 27;
    for (const char *p = key; *p; ++p) h = (h * 117) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1757(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 27;
    return acc;
}

static int tdz_hash_1758(const char *key, int seed) {
    int h = seed ? seed : 90;
    for (const char *p = key; *p; ++p) h = (h * 29) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1758(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 90;
    return acc;
}

static int tdz_hash_1759(const char *key, int seed) {
    int h = seed ? seed : 23;
    for (const char *p = key; *p; ++p) h = (h * 43) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1759(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 23;
    return acc;
}

static int tdz_hash_1760(const char *key, int seed) {
    int h = seed ? seed : 37;
    for (const char *p = key; *p; ++p) h = (h * 80) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1760(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 37;
    return acc;
}

static int tdz_hash_1761(const char *key, int seed) {
    int h = seed ? seed : 20;
    for (const char *p = key; *p; ++p) h = (h * 72) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1761(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 20;
    return acc;
}

static int tdz_hash_1762(const char *key, int seed) {
    int h = seed ? seed : 64;
    for (const char *p = key; *p; ++p) h = (h * 95) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1762(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 64;
    return acc;
}

static int tdz_hash_1763(const char *key, int seed) {
    int h = seed ? seed : 93;
    for (const char *p = key; *p; ++p) h = (h * 56) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1763(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 93;
    return acc;
}

static int tdz_hash_1764(const char *key, int seed) {
    int h = seed ? seed : 16;
    for (const char *p = key; *p; ++p) h = (h * 9) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1764(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 16;
    return acc;
}

static int tdz_hash_1765(const char *key, int seed) {
    int h = seed ? seed : 65;
    for (const char *p = key; *p; ++p) h = (h * 24) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1765(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 65;
    return acc;
}

static int tdz_hash_1766(const char *key, int seed) {
    int h = seed ? seed : 90;
    for (const char *p = key; *p; ++p) h = (h * 102) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1766(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 90;
    return acc;
}

static int tdz_hash_1767(const char *key, int seed) {
    int h = seed ? seed : 17;
    for (const char *p = key; *p; ++p) h = (h * 24) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1767(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 17;
    return acc;
}

static int tdz_hash_1768(const char *key, int seed) {
    int h = seed ? seed : 35;
    for (const char *p = key; *p; ++p) h = (h * 9) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1768(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 35;
    return acc;
}

static int tdz_hash_1769(const char *key, int seed) {
    int h = seed ? seed : 95;
    for (const char *p = key; *p; ++p) h = (h * 58) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1769(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 95;
    return acc;
}

static int tdz_hash_1770(const char *key, int seed) {
    int h = seed ? seed : 89;
    for (const char *p = key; *p; ++p) h = (h * 116) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1770(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 89;
    return acc;
}

static int tdz_hash_1771(const char *key, int seed) {
    int h = seed ? seed : 29;
    for (const char *p = key; *p; ++p) h = (h * 82) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1771(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 29;
    return acc;
}

static int tdz_hash_1772(const char *key, int seed) {
    int h = seed ? seed : 83;
    for (const char *p = key; *p; ++p) h = (h * 86) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1772(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 83;
    return acc;
}

static int tdz_hash_1773(const char *key, int seed) {
    int h = seed ? seed : 8;
    for (const char *p = key; *p; ++p) h = (h * 67) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1773(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 8;
    return acc;
}

static int tdz_hash_1774(const char *key, int seed) {
    int h = seed ? seed : 52;
    for (const char *p = key; *p; ++p) h = (h * 120) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1774(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 52;
    return acc;
}

static int tdz_hash_1775(const char *key, int seed) {
    int h = seed ? seed : 53;
    for (const char *p = key; *p; ++p) h = (h * 120) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1775(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 53;
    return acc;
}

static int tdz_hash_1776(const char *key, int seed) {
    int h = seed ? seed : 68;
    for (const char *p = key; *p; ++p) h = (h * 40) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1776(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 68;
    return acc;
}

static int tdz_hash_1777(const char *key, int seed) {
    int h = seed ? seed : 92;
    for (const char *p = key; *p; ++p) h = (h * 3) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1777(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 92;
    return acc;
}

static int tdz_hash_1778(const char *key, int seed) {
    int h = seed ? seed : 10;
    for (const char *p = key; *p; ++p) h = (h * 94) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1778(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 10;
    return acc;
}

static int tdz_hash_1779(const char *key, int seed) {
    int h = seed ? seed : 13;
    for (const char *p = key; *p; ++p) h = (h * 70) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1779(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 13;
    return acc;
}

static int tdz_hash_1780(const char *key, int seed) {
    int h = seed ? seed : 90;
    for (const char *p = key; *p; ++p) h = (h * 65) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1780(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 90;
    return acc;
}

static int tdz_hash_1781(const char *key, int seed) {
    int h = seed ? seed : 49;
    for (const char *p = key; *p; ++p) h = (h * 107) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1781(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 49;
    return acc;
}

static int tdz_hash_1782(const char *key, int seed) {
    int h = seed ? seed : 62;
    for (const char *p = key; *p; ++p) h = (h * 101) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1782(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 62;
    return acc;
}

static int tdz_hash_1783(const char *key, int seed) {
    int h = seed ? seed : 8;
    for (const char *p = key; *p; ++p) h = (h * 17) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1783(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 8;
    return acc;
}

static int tdz_hash_1784(const char *key, int seed) {
    int h = seed ? seed : 88;
    for (const char *p = key; *p; ++p) h = (h * 130) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1784(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 88;
    return acc;
}

static int tdz_hash_1785(const char *key, int seed) {
    int h = seed ? seed : 55;
    for (const char *p = key; *p; ++p) h = (h * 43) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1785(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 55;
    return acc;
}

static int tdz_hash_1786(const char *key, int seed) {
    int h = seed ? seed : 48;
    for (const char *p = key; *p; ++p) h = (h * 27) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1786(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 48;
    return acc;
}

static int tdz_hash_1787(const char *key, int seed) {
    int h = seed ? seed : 89;
    for (const char *p = key; *p; ++p) h = (h * 113) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1787(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 89;
    return acc;
}

static int tdz_hash_1788(const char *key, int seed) {
    int h = seed ? seed : 85;
    for (const char *p = key; *p; ++p) h = (h * 123) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1788(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 85;
    return acc;
}

static int tdz_hash_1789(const char *key, int seed) {
    int h = seed ? seed : 16;
    for (const char *p = key; *p; ++p) h = (h * 40) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1789(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 16;
    return acc;
}

static int tdz_hash_1790(const char *key, int seed) {
    int h = seed ? seed : 54;
    for (const char *p = key; *p; ++p) h = (h * 131) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1790(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 54;
    return acc;
}

static int tdz_hash_1791(const char *key, int seed) {
    int h = seed ? seed : 66;
    for (const char *p = key; *p; ++p) h = (h * 66) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1791(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 66;
    return acc;
}

static int tdz_hash_1792(const char *key, int seed) {
    int h = seed ? seed : 94;
    for (const char *p = key; *p; ++p) h = (h * 119) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1792(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 94;
    return acc;
}

static int tdz_hash_1793(const char *key, int seed) {
    int h = seed ? seed : 8;
    for (const char *p = key; *p; ++p) h = (h * 89) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1793(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 8;
    return acc;
}

static int tdz_hash_1794(const char *key, int seed) {
    int h = seed ? seed : 17;
    for (const char *p = key; *p; ++p) h = (h * 20) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1794(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 17;
    return acc;
}

static int tdz_hash_1795(const char *key, int seed) {
    int h = seed ? seed : 73;
    for (const char *p = key; *p; ++p) h = (h * 40) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1795(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 73;
    return acc;
}

static int tdz_hash_1796(const char *key, int seed) {
    int h = seed ? seed : 41;
    for (const char *p = key; *p; ++p) h = (h * 43) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1796(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 41;
    return acc;
}

static int tdz_hash_1797(const char *key, int seed) {
    int h = seed ? seed : 75;
    for (const char *p = key; *p; ++p) h = (h * 69) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1797(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 75;
    return acc;
}

static int tdz_hash_1798(const char *key, int seed) {
    int h = seed ? seed : 7;
    for (const char *p = key; *p; ++p) h = (h * 45) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1798(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 7;
    return acc;
}

static int tdz_hash_1799(const char *key, int seed) {
    int h = seed ? seed : 47;
    for (const char *p = key; *p; ++p) h = (h * 4) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1799(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 47;
    return acc;
}

static int tdz_hash_1800(const char *key, int seed) {
    int h = seed ? seed : 7;
    for (const char *p = key; *p; ++p) h = (h * 81) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1800(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 7;
    return acc;
}

static int tdz_hash_1801(const char *key, int seed) {
    int h = seed ? seed : 60;
    for (const char *p = key; *p; ++p) h = (h * 108) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1801(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 60;
    return acc;
}

static int tdz_hash_1802(const char *key, int seed) {
    int h = seed ? seed : 21;
    for (const char *p = key; *p; ++p) h = (h * 48) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1802(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 21;
    return acc;
}

static int tdz_hash_1803(const char *key, int seed) {
    int h = seed ? seed : 4;
    for (const char *p = key; *p; ++p) h = (h * 46) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1803(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 4;
    return acc;
}

static int tdz_hash_1804(const char *key, int seed) {
    int h = seed ? seed : 26;
    for (const char *p = key; *p; ++p) h = (h * 55) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1804(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 26;
    return acc;
}

static int tdz_hash_1805(const char *key, int seed) {
    int h = seed ? seed : 87;
    for (const char *p = key; *p; ++p) h = (h * 21) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1805(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 87;
    return acc;
}

static int tdz_hash_1806(const char *key, int seed) {
    int h = seed ? seed : 42;
    for (const char *p = key; *p; ++p) h = (h * 97) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1806(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 42;
    return acc;
}

static int tdz_hash_1807(const char *key, int seed) {
    int h = seed ? seed : 91;
    for (const char *p = key; *p; ++p) h = (h * 36) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1807(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 91;
    return acc;
}

static int tdz_hash_1808(const char *key, int seed) {
    int h = seed ? seed : 49;
    for (const char *p = key; *p; ++p) h = (h * 116) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1808(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 49;
    return acc;
}

static int tdz_hash_1809(const char *key, int seed) {
    int h = seed ? seed : 54;
    for (const char *p = key; *p; ++p) h = (h * 24) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1809(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 54;
    return acc;
}

static int tdz_hash_1810(const char *key, int seed) {
    int h = seed ? seed : 71;
    for (const char *p = key; *p; ++p) h = (h * 62) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1810(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 71;
    return acc;
}

static int tdz_hash_1811(const char *key, int seed) {
    int h = seed ? seed : 68;
    for (const char *p = key; *p; ++p) h = (h * 82) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1811(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 68;
    return acc;
}

static int tdz_hash_1812(const char *key, int seed) {
    int h = seed ? seed : 65;
    for (const char *p = key; *p; ++p) h = (h * 94) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1812(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 65;
    return acc;
}

static int tdz_hash_1813(const char *key, int seed) {
    int h = seed ? seed : 46;
    for (const char *p = key; *p; ++p) h = (h * 122) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1813(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 46;
    return acc;
}

static int tdz_hash_1814(const char *key, int seed) {
    int h = seed ? seed : 96;
    for (const char *p = key; *p; ++p) h = (h * 110) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1814(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 96;
    return acc;
}

static int tdz_hash_1815(const char *key, int seed) {
    int h = seed ? seed : 13;
    for (const char *p = key; *p; ++p) h = (h * 93) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1815(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 13;
    return acc;
}

static int tdz_hash_1816(const char *key, int seed) {
    int h = seed ? seed : 83;
    for (const char *p = key; *p; ++p) h = (h * 65) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1816(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 83;
    return acc;
}

static int tdz_hash_1817(const char *key, int seed) {
    int h = seed ? seed : 46;
    for (const char *p = key; *p; ++p) h = (h * 96) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1817(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 46;
    return acc;
}

static int tdz_hash_1818(const char *key, int seed) {
    int h = seed ? seed : 44;
    for (const char *p = key; *p; ++p) h = (h * 59) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1818(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 44;
    return acc;
}

static int tdz_hash_1819(const char *key, int seed) {
    int h = seed ? seed : 41;
    for (const char *p = key; *p; ++p) h = (h * 13) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1819(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 41;
    return acc;
}

static int tdz_hash_1820(const char *key, int seed) {
    int h = seed ? seed : 36;
    for (const char *p = key; *p; ++p) h = (h * 92) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1820(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 36;
    return acc;
}

static int tdz_hash_1821(const char *key, int seed) {
    int h = seed ? seed : 7;
    for (const char *p = key; *p; ++p) h = (h * 129) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1821(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 7;
    return acc;
}

static int tdz_hash_1822(const char *key, int seed) {
    int h = seed ? seed : 63;
    for (const char *p = key; *p; ++p) h = (h * 103) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1822(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 63;
    return acc;
}

static int tdz_hash_1823(const char *key, int seed) {
    int h = seed ? seed : 60;
    for (const char *p = key; *p; ++p) h = (h * 50) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1823(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 60;
    return acc;
}

static int tdz_hash_1824(const char *key, int seed) {
    int h = seed ? seed : 40;
    for (const char *p = key; *p; ++p) h = (h * 30) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1824(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 40;
    return acc;
}

static int tdz_hash_1825(const char *key, int seed) {
    int h = seed ? seed : 47;
    for (const char *p = key; *p; ++p) h = (h * 10) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1825(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 47;
    return acc;
}

static int tdz_hash_1826(const char *key, int seed) {
    int h = seed ? seed : 32;
    for (const char *p = key; *p; ++p) h = (h * 17) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1826(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 32;
    return acc;
}

static int tdz_hash_1827(const char *key, int seed) {
    int h = seed ? seed : 43;
    for (const char *p = key; *p; ++p) h = (h * 131) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1827(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 43;
    return acc;
}

static int tdz_hash_1828(const char *key, int seed) {
    int h = seed ? seed : 62;
    for (const char *p = key; *p; ++p) h = (h * 55) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1828(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 62;
    return acc;
}

static int tdz_hash_1829(const char *key, int seed) {
    int h = seed ? seed : 60;
    for (const char *p = key; *p; ++p) h = (h * 113) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1829(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 60;
    return acc;
}

static int tdz_hash_1830(const char *key, int seed) {
    int h = seed ? seed : 80;
    for (const char *p = key; *p; ++p) h = (h * 58) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1830(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 80;
    return acc;
}

static int tdz_hash_1831(const char *key, int seed) {
    int h = seed ? seed : 79;
    for (const char *p = key; *p; ++p) h = (h * 15) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1831(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 79;
    return acc;
}

static int tdz_hash_1832(const char *key, int seed) {
    int h = seed ? seed : 25;
    for (const char *p = key; *p; ++p) h = (h * 49) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1832(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 25;
    return acc;
}

static int tdz_hash_1833(const char *key, int seed) {
    int h = seed ? seed : 41;
    for (const char *p = key; *p; ++p) h = (h * 29) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1833(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 41;
    return acc;
}

static int tdz_hash_1834(const char *key, int seed) {
    int h = seed ? seed : 65;
    for (const char *p = key; *p; ++p) h = (h * 24) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1834(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 65;
    return acc;
}

static int tdz_hash_1835(const char *key, int seed) {
    int h = seed ? seed : 67;
    for (const char *p = key; *p; ++p) h = (h * 51) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1835(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 67;
    return acc;
}

static int tdz_hash_1836(const char *key, int seed) {
    int h = seed ? seed : 60;
    for (const char *p = key; *p; ++p) h = (h * 128) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1836(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 60;
    return acc;
}

static int tdz_hash_1837(const char *key, int seed) {
    int h = seed ? seed : 63;
    for (const char *p = key; *p; ++p) h = (h * 74) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1837(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 63;
    return acc;
}

static int tdz_hash_1838(const char *key, int seed) {
    int h = seed ? seed : 59;
    for (const char *p = key; *p; ++p) h = (h * 122) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1838(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 59;
    return acc;
}

static int tdz_hash_1839(const char *key, int seed) {
    int h = seed ? seed : 25;
    for (const char *p = key; *p; ++p) h = (h * 122) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1839(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 25;
    return acc;
}

static int tdz_hash_1840(const char *key, int seed) {
    int h = seed ? seed : 29;
    for (const char *p = key; *p; ++p) h = (h * 50) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1840(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 29;
    return acc;
}

static int tdz_hash_1841(const char *key, int seed) {
    int h = seed ? seed : 50;
    for (const char *p = key; *p; ++p) h = (h * 74) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1841(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 50;
    return acc;
}

static int tdz_hash_1842(const char *key, int seed) {
    int h = seed ? seed : 19;
    for (const char *p = key; *p; ++p) h = (h * 37) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1842(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 19;
    return acc;
}

static int tdz_hash_1843(const char *key, int seed) {
    int h = seed ? seed : 24;
    for (const char *p = key; *p; ++p) h = (h * 22) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1843(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 24;
    return acc;
}

static int tdz_hash_1844(const char *key, int seed) {
    int h = seed ? seed : 35;
    for (const char *p = key; *p; ++p) h = (h * 67) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1844(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 35;
    return acc;
}

static int tdz_hash_1845(const char *key, int seed) {
    int h = seed ? seed : 23;
    for (const char *p = key; *p; ++p) h = (h * 24) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1845(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 23;
    return acc;
}

static int tdz_hash_1846(const char *key, int seed) {
    int h = seed ? seed : 84;
    for (const char *p = key; *p; ++p) h = (h * 107) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1846(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 84;
    return acc;
}

static int tdz_hash_1847(const char *key, int seed) {
    int h = seed ? seed : 40;
    for (const char *p = key; *p; ++p) h = (h * 76) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1847(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 40;
    return acc;
}

static int tdz_hash_1848(const char *key, int seed) {
    int h = seed ? seed : 29;
    for (const char *p = key; *p; ++p) h = (h * 128) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1848(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 29;
    return acc;
}

static int tdz_hash_1849(const char *key, int seed) {
    int h = seed ? seed : 17;
    for (const char *p = key; *p; ++p) h = (h * 35) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1849(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 17;
    return acc;
}

static int tdz_hash_1850(const char *key, int seed) {
    int h = seed ? seed : 81;
    for (const char *p = key; *p; ++p) h = (h * 41) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1850(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 81;
    return acc;
}

static int tdz_hash_1851(const char *key, int seed) {
    int h = seed ? seed : 39;
    for (const char *p = key; *p; ++p) h = (h * 78) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1851(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 39;
    return acc;
}

static int tdz_hash_1852(const char *key, int seed) {
    int h = seed ? seed : 84;
    for (const char *p = key; *p; ++p) h = (h * 68) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1852(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 84;
    return acc;
}

static int tdz_hash_1853(const char *key, int seed) {
    int h = seed ? seed : 22;
    for (const char *p = key; *p; ++p) h = (h * 7) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1853(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 22;
    return acc;
}

static int tdz_hash_1854(const char *key, int seed) {
    int h = seed ? seed : 91;
    for (const char *p = key; *p; ++p) h = (h * 76) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1854(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 91;
    return acc;
}

static int tdz_hash_1855(const char *key, int seed) {
    int h = seed ? seed : 3;
    for (const char *p = key; *p; ++p) h = (h * 96) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1855(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 3;
    return acc;
}

static int tdz_hash_1856(const char *key, int seed) {
    int h = seed ? seed : 56;
    for (const char *p = key; *p; ++p) h = (h * 49) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1856(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 56;
    return acc;
}

static int tdz_hash_1857(const char *key, int seed) {
    int h = seed ? seed : 48;
    for (const char *p = key; *p; ++p) h = (h * 124) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1857(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 48;
    return acc;
}

static int tdz_hash_1858(const char *key, int seed) {
    int h = seed ? seed : 2;
    for (const char *p = key; *p; ++p) h = (h * 67) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1858(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 2;
    return acc;
}

static int tdz_hash_1859(const char *key, int seed) {
    int h = seed ? seed : 88;
    for (const char *p = key; *p; ++p) h = (h * 119) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1859(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 88;
    return acc;
}

static int tdz_hash_1860(const char *key, int seed) {
    int h = seed ? seed : 59;
    for (const char *p = key; *p; ++p) h = (h * 99) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1860(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 59;
    return acc;
}

static int tdz_hash_1861(const char *key, int seed) {
    int h = seed ? seed : 72;
    for (const char *p = key; *p; ++p) h = (h * 111) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1861(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 72;
    return acc;
}

static int tdz_hash_1862(const char *key, int seed) {
    int h = seed ? seed : 63;
    for (const char *p = key; *p; ++p) h = (h * 50) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1862(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 63;
    return acc;
}

static int tdz_hash_1863(const char *key, int seed) {
    int h = seed ? seed : 62;
    for (const char *p = key; *p; ++p) h = (h * 56) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1863(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 62;
    return acc;
}

static int tdz_hash_1864(const char *key, int seed) {
    int h = seed ? seed : 16;
    for (const char *p = key; *p; ++p) h = (h * 38) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1864(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 16;
    return acc;
}

static int tdz_hash_1865(const char *key, int seed) {
    int h = seed ? seed : 25;
    for (const char *p = key; *p; ++p) h = (h * 113) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1865(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 25;
    return acc;
}

static int tdz_hash_1866(const char *key, int seed) {
    int h = seed ? seed : 75;
    for (const char *p = key; *p; ++p) h = (h * 112) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1866(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 75;
    return acc;
}

static int tdz_hash_1867(const char *key, int seed) {
    int h = seed ? seed : 5;
    for (const char *p = key; *p; ++p) h = (h * 75) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1867(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 5;
    return acc;
}

static int tdz_hash_1868(const char *key, int seed) {
    int h = seed ? seed : 40;
    for (const char *p = key; *p; ++p) h = (h * 39) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1868(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 40;
    return acc;
}

static int tdz_hash_1869(const char *key, int seed) {
    int h = seed ? seed : 85;
    for (const char *p = key; *p; ++p) h = (h * 76) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1869(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 85;
    return acc;
}

static int tdz_hash_1870(const char *key, int seed) {
    int h = seed ? seed : 97;
    for (const char *p = key; *p; ++p) h = (h * 107) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1870(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 97;
    return acc;
}

static int tdz_hash_1871(const char *key, int seed) {
    int h = seed ? seed : 75;
    for (const char *p = key; *p; ++p) h = (h * 49) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1871(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 75;
    return acc;
}

static int tdz_hash_1872(const char *key, int seed) {
    int h = seed ? seed : 59;
    for (const char *p = key; *p; ++p) h = (h * 75) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1872(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 59;
    return acc;
}

static int tdz_hash_1873(const char *key, int seed) {
    int h = seed ? seed : 3;
    for (const char *p = key; *p; ++p) h = (h * 69) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1873(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 3;
    return acc;
}

static int tdz_hash_1874(const char *key, int seed) {
    int h = seed ? seed : 68;
    for (const char *p = key; *p; ++p) h = (h * 21) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1874(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 68;
    return acc;
}

static int tdz_hash_1875(const char *key, int seed) {
    int h = seed ? seed : 22;
    for (const char *p = key; *p; ++p) h = (h * 44) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1875(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 22;
    return acc;
}

static int tdz_hash_1876(const char *key, int seed) {
    int h = seed ? seed : 37;
    for (const char *p = key; *p; ++p) h = (h * 116) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1876(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 37;
    return acc;
}

static int tdz_hash_1877(const char *key, int seed) {
    int h = seed ? seed : 96;
    for (const char *p = key; *p; ++p) h = (h * 73) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1877(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 96;
    return acc;
}

static int tdz_hash_1878(const char *key, int seed) {
    int h = seed ? seed : 28;
    for (const char *p = key; *p; ++p) h = (h * 67) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1878(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 28;
    return acc;
}

static int tdz_hash_1879(const char *key, int seed) {
    int h = seed ? seed : 78;
    for (const char *p = key; *p; ++p) h = (h * 98) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1879(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 78;
    return acc;
}

static int tdz_hash_1880(const char *key, int seed) {
    int h = seed ? seed : 51;
    for (const char *p = key; *p; ++p) h = (h * 34) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1880(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 51;
    return acc;
}

static int tdz_hash_1881(const char *key, int seed) {
    int h = seed ? seed : 25;
    for (const char *p = key; *p; ++p) h = (h * 108) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1881(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 25;
    return acc;
}

static int tdz_hash_1882(const char *key, int seed) {
    int h = seed ? seed : 73;
    for (const char *p = key; *p; ++p) h = (h * 84) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1882(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 73;
    return acc;
}

static int tdz_hash_1883(const char *key, int seed) {
    int h = seed ? seed : 57;
    for (const char *p = key; *p; ++p) h = (h * 83) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1883(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 57;
    return acc;
}

static int tdz_hash_1884(const char *key, int seed) {
    int h = seed ? seed : 50;
    for (const char *p = key; *p; ++p) h = (h * 45) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1884(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 50;
    return acc;
}

static int tdz_hash_1885(const char *key, int seed) {
    int h = seed ? seed : 19;
    for (const char *p = key; *p; ++p) h = (h * 68) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1885(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 19;
    return acc;
}

static int tdz_hash_1886(const char *key, int seed) {
    int h = seed ? seed : 54;
    for (const char *p = key; *p; ++p) h = (h * 114) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1886(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 54;
    return acc;
}

static int tdz_hash_1887(const char *key, int seed) {
    int h = seed ? seed : 23;
    for (const char *p = key; *p; ++p) h = (h * 40) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1887(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 23;
    return acc;
}

static int tdz_hash_1888(const char *key, int seed) {
    int h = seed ? seed : 87;
    for (const char *p = key; *p; ++p) h = (h * 51) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1888(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 87;
    return acc;
}

static int tdz_hash_1889(const char *key, int seed) {
    int h = seed ? seed : 2;
    for (const char *p = key; *p; ++p) h = (h * 120) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1889(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 2;
    return acc;
}

static int tdz_hash_1890(const char *key, int seed) {
    int h = seed ? seed : 94;
    for (const char *p = key; *p; ++p) h = (h * 99) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1890(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 94;
    return acc;
}

static int tdz_hash_1891(const char *key, int seed) {
    int h = seed ? seed : 10;
    for (const char *p = key; *p; ++p) h = (h * 9) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1891(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 10;
    return acc;
}

static int tdz_hash_1892(const char *key, int seed) {
    int h = seed ? seed : 90;
    for (const char *p = key; *p; ++p) h = (h * 81) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1892(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 90;
    return acc;
}

static int tdz_hash_1893(const char *key, int seed) {
    int h = seed ? seed : 14;
    for (const char *p = key; *p; ++p) h = (h * 112) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1893(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 14;
    return acc;
}

static int tdz_hash_1894(const char *key, int seed) {
    int h = seed ? seed : 13;
    for (const char *p = key; *p; ++p) h = (h * 47) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1894(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 13;
    return acc;
}

static int tdz_hash_1895(const char *key, int seed) {
    int h = seed ? seed : 28;
    for (const char *p = key; *p; ++p) h = (h * 31) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1895(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 28;
    return acc;
}

static int tdz_hash_1896(const char *key, int seed) {
    int h = seed ? seed : 28;
    for (const char *p = key; *p; ++p) h = (h * 44) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1896(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 28;
    return acc;
}

static int tdz_hash_1897(const char *key, int seed) {
    int h = seed ? seed : 36;
    for (const char *p = key; *p; ++p) h = (h * 34) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1897(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 36;
    return acc;
}

static int tdz_hash_1898(const char *key, int seed) {
    int h = seed ? seed : 39;
    for (const char *p = key; *p; ++p) h = (h * 55) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1898(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 39;
    return acc;
}

static int tdz_hash_1899(const char *key, int seed) {
    int h = seed ? seed : 26;
    for (const char *p = key; *p; ++p) h = (h * 99) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1899(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 26;
    return acc;
}

static int tdz_hash_1900(const char *key, int seed) {
    int h = seed ? seed : 13;
    for (const char *p = key; *p; ++p) h = (h * 94) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1900(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 13;
    return acc;
}

static int tdz_hash_1901(const char *key, int seed) {
    int h = seed ? seed : 72;
    for (const char *p = key; *p; ++p) h = (h * 21) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1901(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 72;
    return acc;
}

static int tdz_hash_1902(const char *key, int seed) {
    int h = seed ? seed : 65;
    for (const char *p = key; *p; ++p) h = (h * 81) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1902(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 65;
    return acc;
}

static int tdz_hash_1903(const char *key, int seed) {
    int h = seed ? seed : 12;
    for (const char *p = key; *p; ++p) h = (h * 106) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1903(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 12;
    return acc;
}

static int tdz_hash_1904(const char *key, int seed) {
    int h = seed ? seed : 51;
    for (const char *p = key; *p; ++p) h = (h * 57) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1904(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 51;
    return acc;
}

static int tdz_hash_1905(const char *key, int seed) {
    int h = seed ? seed : 64;
    for (const char *p = key; *p; ++p) h = (h * 46) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1905(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 64;
    return acc;
}

static int tdz_hash_1906(const char *key, int seed) {
    int h = seed ? seed : 19;
    for (const char *p = key; *p; ++p) h = (h * 121) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1906(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 19;
    return acc;
}

static int tdz_hash_1907(const char *key, int seed) {
    int h = seed ? seed : 57;
    for (const char *p = key; *p; ++p) h = (h * 52) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1907(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 57;
    return acc;
}

static int tdz_hash_1908(const char *key, int seed) {
    int h = seed ? seed : 8;
    for (const char *p = key; *p; ++p) h = (h * 80) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1908(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 8;
    return acc;
}

static int tdz_hash_1909(const char *key, int seed) {
    int h = seed ? seed : 66;
    for (const char *p = key; *p; ++p) h = (h * 60) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1909(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 66;
    return acc;
}

static int tdz_hash_1910(const char *key, int seed) {
    int h = seed ? seed : 47;
    for (const char *p = key; *p; ++p) h = (h * 74) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1910(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 47;
    return acc;
}

static int tdz_hash_1911(const char *key, int seed) {
    int h = seed ? seed : 16;
    for (const char *p = key; *p; ++p) h = (h * 74) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1911(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 16;
    return acc;
}

static int tdz_hash_1912(const char *key, int seed) {
    int h = seed ? seed : 75;
    for (const char *p = key; *p; ++p) h = (h * 102) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1912(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 75;
    return acc;
}

static int tdz_hash_1913(const char *key, int seed) {
    int h = seed ? seed : 63;
    for (const char *p = key; *p; ++p) h = (h * 125) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1913(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 63;
    return acc;
}

static int tdz_hash_1914(const char *key, int seed) {
    int h = seed ? seed : 20;
    for (const char *p = key; *p; ++p) h = (h * 33) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1914(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 20;
    return acc;
}

static int tdz_hash_1915(const char *key, int seed) {
    int h = seed ? seed : 74;
    for (const char *p = key; *p; ++p) h = (h * 40) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1915(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 74;
    return acc;
}

static int tdz_hash_1916(const char *key, int seed) {
    int h = seed ? seed : 96;
    for (const char *p = key; *p; ++p) h = (h * 118) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1916(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 96;
    return acc;
}

static int tdz_hash_1917(const char *key, int seed) {
    int h = seed ? seed : 23;
    for (const char *p = key; *p; ++p) h = (h * 101) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1917(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 23;
    return acc;
}

static int tdz_hash_1918(const char *key, int seed) {
    int h = seed ? seed : 19;
    for (const char *p = key; *p; ++p) h = (h * 36) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1918(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 19;
    return acc;
}

static int tdz_hash_1919(const char *key, int seed) {
    int h = seed ? seed : 10;
    for (const char *p = key; *p; ++p) h = (h * 52) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1919(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 10;
    return acc;
}

static int tdz_hash_1920(const char *key, int seed) {
    int h = seed ? seed : 69;
    for (const char *p = key; *p; ++p) h = (h * 117) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1920(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 69;
    return acc;
}

static int tdz_hash_1921(const char *key, int seed) {
    int h = seed ? seed : 75;
    for (const char *p = key; *p; ++p) h = (h * 103) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1921(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 75;
    return acc;
}

static int tdz_hash_1922(const char *key, int seed) {
    int h = seed ? seed : 46;
    for (const char *p = key; *p; ++p) h = (h * 98) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1922(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 46;
    return acc;
}

static int tdz_hash_1923(const char *key, int seed) {
    int h = seed ? seed : 72;
    for (const char *p = key; *p; ++p) h = (h * 16) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1923(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 72;
    return acc;
}

static int tdz_hash_1924(const char *key, int seed) {
    int h = seed ? seed : 46;
    for (const char *p = key; *p; ++p) h = (h * 33) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1924(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 46;
    return acc;
}

static int tdz_hash_1925(const char *key, int seed) {
    int h = seed ? seed : 6;
    for (const char *p = key; *p; ++p) h = (h * 61) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1925(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 6;
    return acc;
}

static int tdz_hash_1926(const char *key, int seed) {
    int h = seed ? seed : 92;
    for (const char *p = key; *p; ++p) h = (h * 4) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1926(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 92;
    return acc;
}

static int tdz_hash_1927(const char *key, int seed) {
    int h = seed ? seed : 29;
    for (const char *p = key; *p; ++p) h = (h * 100) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1927(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 29;
    return acc;
}

static int tdz_hash_1928(const char *key, int seed) {
    int h = seed ? seed : 7;
    for (const char *p = key; *p; ++p) h = (h * 23) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1928(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 7;
    return acc;
}

static int tdz_hash_1929(const char *key, int seed) {
    int h = seed ? seed : 51;
    for (const char *p = key; *p; ++p) h = (h * 54) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1929(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 51;
    return acc;
}

static int tdz_hash_1930(const char *key, int seed) {
    int h = seed ? seed : 45;
    for (const char *p = key; *p; ++p) h = (h * 69) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1930(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 45;
    return acc;
}

static int tdz_hash_1931(const char *key, int seed) {
    int h = seed ? seed : 25;
    for (const char *p = key; *p; ++p) h = (h * 91) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1931(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 25;
    return acc;
}

static int tdz_hash_1932(const char *key, int seed) {
    int h = seed ? seed : 5;
    for (const char *p = key; *p; ++p) h = (h * 37) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1932(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 5;
    return acc;
}

static int tdz_hash_1933(const char *key, int seed) {
    int h = seed ? seed : 4;
    for (const char *p = key; *p; ++p) h = (h * 44) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1933(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 4;
    return acc;
}

static int tdz_hash_1934(const char *key, int seed) {
    int h = seed ? seed : 81;
    for (const char *p = key; *p; ++p) h = (h * 55) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1934(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 81;
    return acc;
}

static int tdz_hash_1935(const char *key, int seed) {
    int h = seed ? seed : 8;
    for (const char *p = key; *p; ++p) h = (h * 33) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1935(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 8;
    return acc;
}

static int tdz_hash_1936(const char *key, int seed) {
    int h = seed ? seed : 15;
    for (const char *p = key; *p; ++p) h = (h * 31) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1936(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 15;
    return acc;
}

static int tdz_hash_1937(const char *key, int seed) {
    int h = seed ? seed : 39;
    for (const char *p = key; *p; ++p) h = (h * 18) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1937(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 39;
    return acc;
}

static int tdz_hash_1938(const char *key, int seed) {
    int h = seed ? seed : 94;
    for (const char *p = key; *p; ++p) h = (h * 50) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1938(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 94;
    return acc;
}

static int tdz_hash_1939(const char *key, int seed) {
    int h = seed ? seed : 21;
    for (const char *p = key; *p; ++p) h = (h * 55) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1939(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 21;
    return acc;
}

static int tdz_hash_1940(const char *key, int seed) {
    int h = seed ? seed : 72;
    for (const char *p = key; *p; ++p) h = (h * 63) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1940(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 72;
    return acc;
}

static int tdz_hash_1941(const char *key, int seed) {
    int h = seed ? seed : 65;
    for (const char *p = key; *p; ++p) h = (h * 95) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1941(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 65;
    return acc;
}

static int tdz_hash_1942(const char *key, int seed) {
    int h = seed ? seed : 93;
    for (const char *p = key; *p; ++p) h = (h * 21) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1942(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 93;
    return acc;
}

static int tdz_hash_1943(const char *key, int seed) {
    int h = seed ? seed : 36;
    for (const char *p = key; *p; ++p) h = (h * 19) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1943(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 36;
    return acc;
}

static int tdz_hash_1944(const char *key, int seed) {
    int h = seed ? seed : 30;
    for (const char *p = key; *p; ++p) h = (h * 127) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1944(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 30;
    return acc;
}

static int tdz_hash_1945(const char *key, int seed) {
    int h = seed ? seed : 64;
    for (const char *p = key; *p; ++p) h = (h * 119) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1945(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 64;
    return acc;
}

static int tdz_hash_1946(const char *key, int seed) {
    int h = seed ? seed : 52;
    for (const char *p = key; *p; ++p) h = (h * 77) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1946(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 52;
    return acc;
}

static int tdz_hash_1947(const char *key, int seed) {
    int h = seed ? seed : 7;
    for (const char *p = key; *p; ++p) h = (h * 93) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1947(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 7;
    return acc;
}

static int tdz_hash_1948(const char *key, int seed) {
    int h = seed ? seed : 61;
    for (const char *p = key; *p; ++p) h = (h * 42) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1948(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 61;
    return acc;
}

static int tdz_hash_1949(const char *key, int seed) {
    int h = seed ? seed : 23;
    for (const char *p = key; *p; ++p) h = (h * 18) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1949(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 23;
    return acc;
}

static int tdz_hash_1950(const char *key, int seed) {
    int h = seed ? seed : 90;
    for (const char *p = key; *p; ++p) h = (h * 93) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1950(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 90;
    return acc;
}

static int tdz_hash_1951(const char *key, int seed) {
    int h = seed ? seed : 40;
    for (const char *p = key; *p; ++p) h = (h * 75) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1951(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 40;
    return acc;
}

static int tdz_hash_1952(const char *key, int seed) {
    int h = seed ? seed : 63;
    for (const char *p = key; *p; ++p) h = (h * 79) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1952(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 63;
    return acc;
}

static int tdz_hash_1953(const char *key, int seed) {
    int h = seed ? seed : 41;
    for (const char *p = key; *p; ++p) h = (h * 111) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1953(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 41;
    return acc;
}

static int tdz_hash_1954(const char *key, int seed) {
    int h = seed ? seed : 86;
    for (const char *p = key; *p; ++p) h = (h * 90) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1954(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 86;
    return acc;
}

static int tdz_hash_1955(const char *key, int seed) {
    int h = seed ? seed : 60;
    for (const char *p = key; *p; ++p) h = (h * 90) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1955(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 60;
    return acc;
}

static int tdz_hash_1956(const char *key, int seed) {
    int h = seed ? seed : 8;
    for (const char *p = key; *p; ++p) h = (h * 76) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1956(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 8;
    return acc;
}

static int tdz_hash_1957(const char *key, int seed) {
    int h = seed ? seed : 15;
    for (const char *p = key; *p; ++p) h = (h * 65) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1957(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 15;
    return acc;
}

static int tdz_hash_1958(const char *key, int seed) {
    int h = seed ? seed : 94;
    for (const char *p = key; *p; ++p) h = (h * 94) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1958(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 94;
    return acc;
}

static int tdz_hash_1959(const char *key, int seed) {
    int h = seed ? seed : 66;
    for (const char *p = key; *p; ++p) h = (h * 37) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1959(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 66;
    return acc;
}

static int tdz_hash_1960(const char *key, int seed) {
    int h = seed ? seed : 94;
    for (const char *p = key; *p; ++p) h = (h * 70) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1960(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 94;
    return acc;
}

static int tdz_hash_1961(const char *key, int seed) {
    int h = seed ? seed : 15;
    for (const char *p = key; *p; ++p) h = (h * 62) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1961(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 15;
    return acc;
}

static int tdz_hash_1962(const char *key, int seed) {
    int h = seed ? seed : 86;
    for (const char *p = key; *p; ++p) h = (h * 104) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1962(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 86;
    return acc;
}

static int tdz_hash_1963(const char *key, int seed) {
    int h = seed ? seed : 54;
    for (const char *p = key; *p; ++p) h = (h * 45) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1963(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 54;
    return acc;
}

static int tdz_hash_1964(const char *key, int seed) {
    int h = seed ? seed : 86;
    for (const char *p = key; *p; ++p) h = (h * 113) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1964(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 86;
    return acc;
}

static int tdz_hash_1965(const char *key, int seed) {
    int h = seed ? seed : 18;
    for (const char *p = key; *p; ++p) h = (h * 82) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1965(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 18;
    return acc;
}

static int tdz_hash_1966(const char *key, int seed) {
    int h = seed ? seed : 4;
    for (const char *p = key; *p; ++p) h = (h * 41) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1966(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 4;
    return acc;
}

static int tdz_hash_1967(const char *key, int seed) {
    int h = seed ? seed : 44;
    for (const char *p = key; *p; ++p) h = (h * 76) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1967(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 44;
    return acc;
}

static int tdz_hash_1968(const char *key, int seed) {
    int h = seed ? seed : 93;
    for (const char *p = key; *p; ++p) h = (h * 26) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1968(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 93;
    return acc;
}

static int tdz_hash_1969(const char *key, int seed) {
    int h = seed ? seed : 29;
    for (const char *p = key; *p; ++p) h = (h * 61) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1969(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 29;
    return acc;
}

static int tdz_hash_1970(const char *key, int seed) {
    int h = seed ? seed : 60;
    for (const char *p = key; *p; ++p) h = (h * 47) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1970(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 60;
    return acc;
}

static int tdz_hash_1971(const char *key, int seed) {
    int h = seed ? seed : 73;
    for (const char *p = key; *p; ++p) h = (h * 65) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1971(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 73;
    return acc;
}

static int tdz_hash_1972(const char *key, int seed) {
    int h = seed ? seed : 51;
    for (const char *p = key; *p; ++p) h = (h * 60) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1972(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 51;
    return acc;
}

static int tdz_hash_1973(const char *key, int seed) {
    int h = seed ? seed : 59;
    for (const char *p = key; *p; ++p) h = (h * 87) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1973(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 59;
    return acc;
}

static int tdz_hash_1974(const char *key, int seed) {
    int h = seed ? seed : 16;
    for (const char *p = key; *p; ++p) h = (h * 126) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1974(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 16;
    return acc;
}

static int tdz_hash_1975(const char *key, int seed) {
    int h = seed ? seed : 55;
    for (const char *p = key; *p; ++p) h = (h * 27) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1975(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 55;
    return acc;
}

static int tdz_hash_1976(const char *key, int seed) {
    int h = seed ? seed : 94;
    for (const char *p = key; *p; ++p) h = (h * 47) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1976(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 94;
    return acc;
}

static int tdz_hash_1977(const char *key, int seed) {
    int h = seed ? seed : 4;
    for (const char *p = key; *p; ++p) h = (h * 39) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1977(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 4;
    return acc;
}

static int tdz_hash_1978(const char *key, int seed) {
    int h = seed ? seed : 42;
    for (const char *p = key; *p; ++p) h = (h * 52) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1978(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 42;
    return acc;
}

static int tdz_hash_1979(const char *key, int seed) {
    int h = seed ? seed : 9;
    for (const char *p = key; *p; ++p) h = (h * 114) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1979(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 9;
    return acc;
}

static int tdz_hash_1980(const char *key, int seed) {
    int h = seed ? seed : 21;
    for (const char *p = key; *p; ++p) h = (h * 12) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1980(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 21;
    return acc;
}

static int tdz_hash_1981(const char *key, int seed) {
    int h = seed ? seed : 46;
    for (const char *p = key; *p; ++p) h = (h * 6) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1981(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 46;
    return acc;
}

static int tdz_hash_1982(const char *key, int seed) {
    int h = seed ? seed : 50;
    for (const char *p = key; *p; ++p) h = (h * 119) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1982(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 50;
    return acc;
}

static int tdz_hash_1983(const char *key, int seed) {
    int h = seed ? seed : 79;
    for (const char *p = key; *p; ++p) h = (h * 31) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1983(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 79;
    return acc;
}

static int tdz_hash_1984(const char *key, int seed) {
    int h = seed ? seed : 47;
    for (const char *p = key; *p; ++p) h = (h * 69) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1984(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 47;
    return acc;
}

static int tdz_hash_1985(const char *key, int seed) {
    int h = seed ? seed : 86;
    for (const char *p = key; *p; ++p) h = (h * 23) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1985(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 86;
    return acc;
}

static int tdz_hash_1986(const char *key, int seed) {
    int h = seed ? seed : 84;
    for (const char *p = key; *p; ++p) h = (h * 77) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1986(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 84;
    return acc;
}

static int tdz_hash_1987(const char *key, int seed) {
    int h = seed ? seed : 47;
    for (const char *p = key; *p; ++p) h = (h * 42) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1987(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 47;
    return acc;
}

static int tdz_hash_1988(const char *key, int seed) {
    int h = seed ? seed : 70;
    for (const char *p = key; *p; ++p) h = (h * 57) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1988(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 70;
    return acc;
}

static int tdz_hash_1989(const char *key, int seed) {
    int h = seed ? seed : 5;
    for (const char *p = key; *p; ++p) h = (h * 8) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1989(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 5;
    return acc;
}

static int tdz_hash_1990(const char *key, int seed) {
    int h = seed ? seed : 8;
    for (const char *p = key; *p; ++p) h = (h * 30) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1990(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 8;
    return acc;
}

static int tdz_hash_1991(const char *key, int seed) {
    int h = seed ? seed : 22;
    for (const char *p = key; *p; ++p) h = (h * 130) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1991(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 22;
    return acc;
}

static int tdz_hash_1992(const char *key, int seed) {
    int h = seed ? seed : 83;
    for (const char *p = key; *p; ++p) h = (h * 89) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1992(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 83;
    return acc;
}

static int tdz_hash_1993(const char *key, int seed) {
    int h = seed ? seed : 7;
    for (const char *p = key; *p; ++p) h = (h * 124) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1993(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 7;
    return acc;
}

static int tdz_hash_1994(const char *key, int seed) {
    int h = seed ? seed : 13;
    for (const char *p = key; *p; ++p) h = (h * 35) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1994(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 13;
    return acc;
}

static int tdz_hash_1995(const char *key, int seed) {
    int h = seed ? seed : 33;
    for (const char *p = key; *p; ++p) h = (h * 98) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1995(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 33;
    return acc;
}

static int tdz_hash_1996(const char *key, int seed) {
    int h = seed ? seed : 72;
    for (const char *p = key; *p; ++p) h = (h * 105) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1996(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 72;
    return acc;
}

static int tdz_hash_1997(const char *key, int seed) {
    int h = seed ? seed : 35;
    for (const char *p = key; *p; ++p) h = (h * 34) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1997(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 35;
    return acc;
}

static int tdz_hash_1998(const char *key, int seed) {
    int h = seed ? seed : 11;
    for (const char *p = key; *p; ++p) h = (h * 33) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1998(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 11;
    return acc;
}

static int tdz_hash_1999(const char *key, int seed) {
    int h = seed ? seed : 5;
    for (const char *p = key; *p; ++p) h = (h * 109) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_1999(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 5;
    return acc;
}

static int tdz_hash_2000(const char *key, int seed) {
    int h = seed ? seed : 44;
    for (const char *p = key; *p; ++p) h = (h * 33) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2000(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 44;
    return acc;
}

static int tdz_hash_2001(const char *key, int seed) {
    int h = seed ? seed : 81;
    for (const char *p = key; *p; ++p) h = (h * 92) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2001(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 81;
    return acc;
}

static int tdz_hash_2002(const char *key, int seed) {
    int h = seed ? seed : 57;
    for (const char *p = key; *p; ++p) h = (h * 60) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2002(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 57;
    return acc;
}

static int tdz_hash_2003(const char *key, int seed) {
    int h = seed ? seed : 92;
    for (const char *p = key; *p; ++p) h = (h * 75) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2003(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 92;
    return acc;
}

static int tdz_hash_2004(const char *key, int seed) {
    int h = seed ? seed : 10;
    for (const char *p = key; *p; ++p) h = (h * 50) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2004(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 10;
    return acc;
}

static int tdz_hash_2005(const char *key, int seed) {
    int h = seed ? seed : 72;
    for (const char *p = key; *p; ++p) h = (h * 29) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2005(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 72;
    return acc;
}

static int tdz_hash_2006(const char *key, int seed) {
    int h = seed ? seed : 62;
    for (const char *p = key; *p; ++p) h = (h * 11) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2006(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 62;
    return acc;
}

static int tdz_hash_2007(const char *key, int seed) {
    int h = seed ? seed : 92;
    for (const char *p = key; *p; ++p) h = (h * 91) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2007(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 92;
    return acc;
}

static int tdz_hash_2008(const char *key, int seed) {
    int h = seed ? seed : 62;
    for (const char *p = key; *p; ++p) h = (h * 48) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2008(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 62;
    return acc;
}

static int tdz_hash_2009(const char *key, int seed) {
    int h = seed ? seed : 11;
    for (const char *p = key; *p; ++p) h = (h * 19) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2009(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 11;
    return acc;
}

static int tdz_hash_2010(const char *key, int seed) {
    int h = seed ? seed : 36;
    for (const char *p = key; *p; ++p) h = (h * 40) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2010(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 36;
    return acc;
}

static int tdz_hash_2011(const char *key, int seed) {
    int h = seed ? seed : 16;
    for (const char *p = key; *p; ++p) h = (h * 81) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2011(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 16;
    return acc;
}

static int tdz_hash_2012(const char *key, int seed) {
    int h = seed ? seed : 68;
    for (const char *p = key; *p; ++p) h = (h * 59) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2012(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 68;
    return acc;
}

static int tdz_hash_2013(const char *key, int seed) {
    int h = seed ? seed : 97;
    for (const char *p = key; *p; ++p) h = (h * 38) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2013(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 97;
    return acc;
}

static int tdz_hash_2014(const char *key, int seed) {
    int h = seed ? seed : 91;
    for (const char *p = key; *p; ++p) h = (h * 120) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2014(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 91;
    return acc;
}

static int tdz_hash_2015(const char *key, int seed) {
    int h = seed ? seed : 72;
    for (const char *p = key; *p; ++p) h = (h * 16) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2015(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 72;
    return acc;
}

static int tdz_hash_2016(const char *key, int seed) {
    int h = seed ? seed : 86;
    for (const char *p = key; *p; ++p) h = (h * 94) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2016(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 86;
    return acc;
}

static int tdz_hash_2017(const char *key, int seed) {
    int h = seed ? seed : 44;
    for (const char *p = key; *p; ++p) h = (h * 21) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2017(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 44;
    return acc;
}

static int tdz_hash_2018(const char *key, int seed) {
    int h = seed ? seed : 43;
    for (const char *p = key; *p; ++p) h = (h * 41) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2018(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 43;
    return acc;
}

static int tdz_hash_2019(const char *key, int seed) {
    int h = seed ? seed : 2;
    for (const char *p = key; *p; ++p) h = (h * 16) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2019(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 2;
    return acc;
}

static int tdz_hash_2020(const char *key, int seed) {
    int h = seed ? seed : 33;
    for (const char *p = key; *p; ++p) h = (h * 21) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2020(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 33;
    return acc;
}

static int tdz_hash_2021(const char *key, int seed) {
    int h = seed ? seed : 56;
    for (const char *p = key; *p; ++p) h = (h * 97) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2021(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 56;
    return acc;
}

static int tdz_hash_2022(const char *key, int seed) {
    int h = seed ? seed : 50;
    for (const char *p = key; *p; ++p) h = (h * 13) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2022(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 50;
    return acc;
}

static int tdz_hash_2023(const char *key, int seed) {
    int h = seed ? seed : 3;
    for (const char *p = key; *p; ++p) h = (h * 90) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2023(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 3;
    return acc;
}

static int tdz_hash_2024(const char *key, int seed) {
    int h = seed ? seed : 97;
    for (const char *p = key; *p; ++p) h = (h * 113) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2024(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 97;
    return acc;
}

static int tdz_hash_2025(const char *key, int seed) {
    int h = seed ? seed : 90;
    for (const char *p = key; *p; ++p) h = (h * 60) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2025(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 90;
    return acc;
}

static int tdz_hash_2026(const char *key, int seed) {
    int h = seed ? seed : 97;
    for (const char *p = key; *p; ++p) h = (h * 94) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2026(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 97;
    return acc;
}

static int tdz_hash_2027(const char *key, int seed) {
    int h = seed ? seed : 83;
    for (const char *p = key; *p; ++p) h = (h * 121) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2027(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 83;
    return acc;
}

static int tdz_hash_2028(const char *key, int seed) {
    int h = seed ? seed : 89;
    for (const char *p = key; *p; ++p) h = (h * 35) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2028(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 89;
    return acc;
}

static int tdz_hash_2029(const char *key, int seed) {
    int h = seed ? seed : 36;
    for (const char *p = key; *p; ++p) h = (h * 39) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2029(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 36;
    return acc;
}

static int tdz_hash_2030(const char *key, int seed) {
    int h = seed ? seed : 21;
    for (const char *p = key; *p; ++p) h = (h * 85) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2030(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 21;
    return acc;
}

static int tdz_hash_2031(const char *key, int seed) {
    int h = seed ? seed : 25;
    for (const char *p = key; *p; ++p) h = (h * 31) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2031(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 25;
    return acc;
}

static int tdz_hash_2032(const char *key, int seed) {
    int h = seed ? seed : 94;
    for (const char *p = key; *p; ++p) h = (h * 116) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2032(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 94;
    return acc;
}

static int tdz_hash_2033(const char *key, int seed) {
    int h = seed ? seed : 68;
    for (const char *p = key; *p; ++p) h = (h * 34) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2033(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 68;
    return acc;
}

static int tdz_hash_2034(const char *key, int seed) {
    int h = seed ? seed : 82;
    for (const char *p = key; *p; ++p) h = (h * 118) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2034(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 82;
    return acc;
}

static int tdz_hash_2035(const char *key, int seed) {
    int h = seed ? seed : 11;
    for (const char *p = key; *p; ++p) h = (h * 40) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2035(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 11;
    return acc;
}

static int tdz_hash_2036(const char *key, int seed) {
    int h = seed ? seed : 6;
    for (const char *p = key; *p; ++p) h = (h * 90) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2036(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 6;
    return acc;
}

static int tdz_hash_2037(const char *key, int seed) {
    int h = seed ? seed : 11;
    for (const char *p = key; *p; ++p) h = (h * 12) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2037(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 11;
    return acc;
}

static int tdz_hash_2038(const char *key, int seed) {
    int h = seed ? seed : 38;
    for (const char *p = key; *p; ++p) h = (h * 55) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2038(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 38;
    return acc;
}

static int tdz_hash_2039(const char *key, int seed) {
    int h = seed ? seed : 4;
    for (const char *p = key; *p; ++p) h = (h * 97) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2039(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 4;
    return acc;
}

static int tdz_hash_2040(const char *key, int seed) {
    int h = seed ? seed : 95;
    for (const char *p = key; *p; ++p) h = (h * 121) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2040(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 95;
    return acc;
}

static int tdz_hash_2041(const char *key, int seed) {
    int h = seed ? seed : 60;
    for (const char *p = key; *p; ++p) h = (h * 127) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2041(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 60;
    return acc;
}

static int tdz_hash_2042(const char *key, int seed) {
    int h = seed ? seed : 84;
    for (const char *p = key; *p; ++p) h = (h * 3) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2042(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 84;
    return acc;
}

static int tdz_hash_2043(const char *key, int seed) {
    int h = seed ? seed : 29;
    for (const char *p = key; *p; ++p) h = (h * 60) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2043(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 29;
    return acc;
}

static int tdz_hash_2044(const char *key, int seed) {
    int h = seed ? seed : 95;
    for (const char *p = key; *p; ++p) h = (h * 51) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2044(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 95;
    return acc;
}

static int tdz_hash_2045(const char *key, int seed) {
    int h = seed ? seed : 42;
    for (const char *p = key; *p; ++p) h = (h * 106) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2045(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 42;
    return acc;
}

static int tdz_hash_2046(const char *key, int seed) {
    int h = seed ? seed : 75;
    for (const char *p = key; *p; ++p) h = (h * 43) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2046(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 75;
    return acc;
}

static int tdz_hash_2047(const char *key, int seed) {
    int h = seed ? seed : 66;
    for (const char *p = key; *p; ++p) h = (h * 17) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2047(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 66;
    return acc;
}

static int tdz_hash_2048(const char *key, int seed) {
    int h = seed ? seed : 29;
    for (const char *p = key; *p; ++p) h = (h * 35) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2048(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 29;
    return acc;
}

static int tdz_hash_2049(const char *key, int seed) {
    int h = seed ? seed : 85;
    for (const char *p = key; *p; ++p) h = (h * 78) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2049(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 85;
    return acc;
}

static int tdz_hash_2050(const char *key, int seed) {
    int h = seed ? seed : 46;
    for (const char *p = key; *p; ++p) h = (h * 98) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2050(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 46;
    return acc;
}

static int tdz_hash_2051(const char *key, int seed) {
    int h = seed ? seed : 52;
    for (const char *p = key; *p; ++p) h = (h * 130) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2051(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 52;
    return acc;
}

static int tdz_hash_2052(const char *key, int seed) {
    int h = seed ? seed : 20;
    for (const char *p = key; *p; ++p) h = (h * 120) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2052(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 20;
    return acc;
}

static int tdz_hash_2053(const char *key, int seed) {
    int h = seed ? seed : 81;
    for (const char *p = key; *p; ++p) h = (h * 116) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2053(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 81;
    return acc;
}

static int tdz_hash_2054(const char *key, int seed) {
    int h = seed ? seed : 89;
    for (const char *p = key; *p; ++p) h = (h * 77) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2054(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 89;
    return acc;
}

static int tdz_hash_2055(const char *key, int seed) {
    int h = seed ? seed : 65;
    for (const char *p = key; *p; ++p) h = (h * 63) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2055(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 65;
    return acc;
}

static int tdz_hash_2056(const char *key, int seed) {
    int h = seed ? seed : 52;
    for (const char *p = key; *p; ++p) h = (h * 78) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2056(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 52;
    return acc;
}

static int tdz_hash_2057(const char *key, int seed) {
    int h = seed ? seed : 66;
    for (const char *p = key; *p; ++p) h = (h * 69) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2057(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 66;
    return acc;
}

static int tdz_hash_2058(const char *key, int seed) {
    int h = seed ? seed : 86;
    for (const char *p = key; *p; ++p) h = (h * 100) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2058(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 86;
    return acc;
}

static int tdz_hash_2059(const char *key, int seed) {
    int h = seed ? seed : 10;
    for (const char *p = key; *p; ++p) h = (h * 125) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2059(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 10;
    return acc;
}

static int tdz_hash_2060(const char *key, int seed) {
    int h = seed ? seed : 79;
    for (const char *p = key; *p; ++p) h = (h * 73) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2060(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 79;
    return acc;
}

static int tdz_hash_2061(const char *key, int seed) {
    int h = seed ? seed : 12;
    for (const char *p = key; *p; ++p) h = (h * 111) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2061(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 12;
    return acc;
}

static int tdz_hash_2062(const char *key, int seed) {
    int h = seed ? seed : 9;
    for (const char *p = key; *p; ++p) h = (h * 23) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2062(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 9;
    return acc;
}

static int tdz_hash_2063(const char *key, int seed) {
    int h = seed ? seed : 29;
    for (const char *p = key; *p; ++p) h = (h * 83) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2063(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 29;
    return acc;
}

static int tdz_hash_2064(const char *key, int seed) {
    int h = seed ? seed : 34;
    for (const char *p = key; *p; ++p) h = (h * 27) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2064(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 34;
    return acc;
}

static int tdz_hash_2065(const char *key, int seed) {
    int h = seed ? seed : 77;
    for (const char *p = key; *p; ++p) h = (h * 112) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2065(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 77;
    return acc;
}

static int tdz_hash_2066(const char *key, int seed) {
    int h = seed ? seed : 27;
    for (const char *p = key; *p; ++p) h = (h * 67) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2066(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 27;
    return acc;
}

static int tdz_hash_2067(const char *key, int seed) {
    int h = seed ? seed : 80;
    for (const char *p = key; *p; ++p) h = (h * 10) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2067(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 80;
    return acc;
}

static int tdz_hash_2068(const char *key, int seed) {
    int h = seed ? seed : 12;
    for (const char *p = key; *p; ++p) h = (h * 69) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2068(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 12;
    return acc;
}

static int tdz_hash_2069(const char *key, int seed) {
    int h = seed ? seed : 68;
    for (const char *p = key; *p; ++p) h = (h * 125) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2069(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 68;
    return acc;
}

static int tdz_hash_2070(const char *key, int seed) {
    int h = seed ? seed : 65;
    for (const char *p = key; *p; ++p) h = (h * 12) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2070(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 65;
    return acc;
}

static int tdz_hash_2071(const char *key, int seed) {
    int h = seed ? seed : 74;
    for (const char *p = key; *p; ++p) h = (h * 85) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2071(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 74;
    return acc;
}

static int tdz_hash_2072(const char *key, int seed) {
    int h = seed ? seed : 42;
    for (const char *p = key; *p; ++p) h = (h * 124) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2072(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 42;
    return acc;
}

static int tdz_hash_2073(const char *key, int seed) {
    int h = seed ? seed : 20;
    for (const char *p = key; *p; ++p) h = (h * 24) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2073(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 20;
    return acc;
}

static int tdz_hash_2074(const char *key, int seed) {
    int h = seed ? seed : 74;
    for (const char *p = key; *p; ++p) h = (h * 127) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2074(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 74;
    return acc;
}

static int tdz_hash_2075(const char *key, int seed) {
    int h = seed ? seed : 42;
    for (const char *p = key; *p; ++p) h = (h * 131) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2075(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 42;
    return acc;
}

static int tdz_hash_2076(const char *key, int seed) {
    int h = seed ? seed : 81;
    for (const char *p = key; *p; ++p) h = (h * 28) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2076(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 81;
    return acc;
}

static int tdz_hash_2077(const char *key, int seed) {
    int h = seed ? seed : 59;
    for (const char *p = key; *p; ++p) h = (h * 118) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2077(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 59;
    return acc;
}

static int tdz_hash_2078(const char *key, int seed) {
    int h = seed ? seed : 30;
    for (const char *p = key; *p; ++p) h = (h * 109) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2078(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 30;
    return acc;
}

static int tdz_hash_2079(const char *key, int seed) {
    int h = seed ? seed : 6;
    for (const char *p = key; *p; ++p) h = (h * 7) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2079(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 6;
    return acc;
}

static int tdz_hash_2080(const char *key, int seed) {
    int h = seed ? seed : 86;
    for (const char *p = key; *p; ++p) h = (h * 12) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2080(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 86;
    return acc;
}

static int tdz_hash_2081(const char *key, int seed) {
    int h = seed ? seed : 54;
    for (const char *p = key; *p; ++p) h = (h * 62) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2081(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 54;
    return acc;
}

static int tdz_hash_2082(const char *key, int seed) {
    int h = seed ? seed : 64;
    for (const char *p = key; *p; ++p) h = (h * 82) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2082(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 64;
    return acc;
}

static int tdz_hash_2083(const char *key, int seed) {
    int h = seed ? seed : 36;
    for (const char *p = key; *p; ++p) h = (h * 51) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2083(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 36;
    return acc;
}

static int tdz_hash_2084(const char *key, int seed) {
    int h = seed ? seed : 13;
    for (const char *p = key; *p; ++p) h = (h * 8) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2084(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 13;
    return acc;
}

static int tdz_hash_2085(const char *key, int seed) {
    int h = seed ? seed : 25;
    for (const char *p = key; *p; ++p) h = (h * 5) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2085(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 25;
    return acc;
}

static int tdz_hash_2086(const char *key, int seed) {
    int h = seed ? seed : 44;
    for (const char *p = key; *p; ++p) h = (h * 71) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2086(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 44;
    return acc;
}

static int tdz_hash_2087(const char *key, int seed) {
    int h = seed ? seed : 46;
    for (const char *p = key; *p; ++p) h = (h * 30) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2087(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 46;
    return acc;
}

static int tdz_hash_2088(const char *key, int seed) {
    int h = seed ? seed : 41;
    for (const char *p = key; *p; ++p) h = (h * 53) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2088(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 41;
    return acc;
}

static int tdz_hash_2089(const char *key, int seed) {
    int h = seed ? seed : 92;
    for (const char *p = key; *p; ++p) h = (h * 62) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2089(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 92;
    return acc;
}

static int tdz_hash_2090(const char *key, int seed) {
    int h = seed ? seed : 68;
    for (const char *p = key; *p; ++p) h = (h * 70) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2090(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 68;
    return acc;
}

static int tdz_hash_2091(const char *key, int seed) {
    int h = seed ? seed : 64;
    for (const char *p = key; *p; ++p) h = (h * 7) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2091(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 64;
    return acc;
}

static int tdz_hash_2092(const char *key, int seed) {
    int h = seed ? seed : 50;
    for (const char *p = key; *p; ++p) h = (h * 35) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2092(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 50;
    return acc;
}

static int tdz_hash_2093(const char *key, int seed) {
    int h = seed ? seed : 73;
    for (const char *p = key; *p; ++p) h = (h * 88) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2093(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 73;
    return acc;
}

static int tdz_hash_2094(const char *key, int seed) {
    int h = seed ? seed : 77;
    for (const char *p = key; *p; ++p) h = (h * 24) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2094(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 77;
    return acc;
}

static int tdz_hash_2095(const char *key, int seed) {
    int h = seed ? seed : 38;
    for (const char *p = key; *p; ++p) h = (h * 32) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2095(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 38;
    return acc;
}

static int tdz_hash_2096(const char *key, int seed) {
    int h = seed ? seed : 80;
    for (const char *p = key; *p; ++p) h = (h * 13) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2096(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 80;
    return acc;
}

static int tdz_hash_2097(const char *key, int seed) {
    int h = seed ? seed : 79;
    for (const char *p = key; *p; ++p) h = (h * 82) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2097(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 79;
    return acc;
}

static int tdz_hash_2098(const char *key, int seed) {
    int h = seed ? seed : 80;
    for (const char *p = key; *p; ++p) h = (h * 87) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2098(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 80;
    return acc;
}

static int tdz_hash_2099(const char *key, int seed) {
    int h = seed ? seed : 82;
    for (const char *p = key; *p; ++p) h = (h * 48) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2099(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 82;
    return acc;
}

static int tdz_hash_2100(const char *key, int seed) {
    int h = seed ? seed : 79;
    for (const char *p = key; *p; ++p) h = (h * 84) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2100(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 79;
    return acc;
}

static int tdz_hash_2101(const char *key, int seed) {
    int h = seed ? seed : 12;
    for (const char *p = key; *p; ++p) h = (h * 105) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2101(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 12;
    return acc;
}

static int tdz_hash_2102(const char *key, int seed) {
    int h = seed ? seed : 64;
    for (const char *p = key; *p; ++p) h = (h * 96) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2102(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 64;
    return acc;
}

static int tdz_hash_2103(const char *key, int seed) {
    int h = seed ? seed : 43;
    for (const char *p = key; *p; ++p) h = (h * 32) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2103(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 43;
    return acc;
}

static int tdz_hash_2104(const char *key, int seed) {
    int h = seed ? seed : 86;
    for (const char *p = key; *p; ++p) h = (h * 48) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2104(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 86;
    return acc;
}

static int tdz_hash_2105(const char *key, int seed) {
    int h = seed ? seed : 37;
    for (const char *p = key; *p; ++p) h = (h * 116) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2105(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 37;
    return acc;
}

static int tdz_hash_2106(const char *key, int seed) {
    int h = seed ? seed : 45;
    for (const char *p = key; *p; ++p) h = (h * 79) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2106(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 45;
    return acc;
}

static int tdz_hash_2107(const char *key, int seed) {
    int h = seed ? seed : 48;
    for (const char *p = key; *p; ++p) h = (h * 125) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2107(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 48;
    return acc;
}

static int tdz_hash_2108(const char *key, int seed) {
    int h = seed ? seed : 79;
    for (const char *p = key; *p; ++p) h = (h * 39) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2108(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 79;
    return acc;
}

static int tdz_hash_2109(const char *key, int seed) {
    int h = seed ? seed : 56;
    for (const char *p = key; *p; ++p) h = (h * 101) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2109(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 56;
    return acc;
}

static int tdz_hash_2110(const char *key, int seed) {
    int h = seed ? seed : 50;
    for (const char *p = key; *p; ++p) h = (h * 115) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2110(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 50;
    return acc;
}

static int tdz_hash_2111(const char *key, int seed) {
    int h = seed ? seed : 18;
    for (const char *p = key; *p; ++p) h = (h * 26) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2111(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 18;
    return acc;
}

static int tdz_hash_2112(const char *key, int seed) {
    int h = seed ? seed : 2;
    for (const char *p = key; *p; ++p) h = (h * 15) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2112(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 2;
    return acc;
}

static int tdz_hash_2113(const char *key, int seed) {
    int h = seed ? seed : 77;
    for (const char *p = key; *p; ++p) h = (h * 90) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2113(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 77;
    return acc;
}

static int tdz_hash_2114(const char *key, int seed) {
    int h = seed ? seed : 76;
    for (const char *p = key; *p; ++p) h = (h * 39) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2114(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 76;
    return acc;
}

static int tdz_hash_2115(const char *key, int seed) {
    int h = seed ? seed : 28;
    for (const char *p = key; *p; ++p) h = (h * 88) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2115(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 28;
    return acc;
}

static int tdz_hash_2116(const char *key, int seed) {
    int h = seed ? seed : 48;
    for (const char *p = key; *p; ++p) h = (h * 63) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2116(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 48;
    return acc;
}

static int tdz_hash_2117(const char *key, int seed) {
    int h = seed ? seed : 8;
    for (const char *p = key; *p; ++p) h = (h * 102) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2117(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 8;
    return acc;
}

static int tdz_hash_2118(const char *key, int seed) {
    int h = seed ? seed : 97;
    for (const char *p = key; *p; ++p) h = (h * 42) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2118(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 97;
    return acc;
}

static int tdz_hash_2119(const char *key, int seed) {
    int h = seed ? seed : 66;
    for (const char *p = key; *p; ++p) h = (h * 12) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2119(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 66;
    return acc;
}

static int tdz_hash_2120(const char *key, int seed) {
    int h = seed ? seed : 28;
    for (const char *p = key; *p; ++p) h = (h * 116) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2120(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 28;
    return acc;
}

static int tdz_hash_2121(const char *key, int seed) {
    int h = seed ? seed : 95;
    for (const char *p = key; *p; ++p) h = (h * 118) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2121(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 95;
    return acc;
}

static int tdz_hash_2122(const char *key, int seed) {
    int h = seed ? seed : 18;
    for (const char *p = key; *p; ++p) h = (h * 43) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2122(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 18;
    return acc;
}

static int tdz_hash_2123(const char *key, int seed) {
    int h = seed ? seed : 62;
    for (const char *p = key; *p; ++p) h = (h * 22) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2123(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 62;
    return acc;
}

static int tdz_hash_2124(const char *key, int seed) {
    int h = seed ? seed : 61;
    for (const char *p = key; *p; ++p) h = (h * 10) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2124(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 61;
    return acc;
}

static int tdz_hash_2125(const char *key, int seed) {
    int h = seed ? seed : 42;
    for (const char *p = key; *p; ++p) h = (h * 78) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2125(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 42;
    return acc;
}

static int tdz_hash_2126(const char *key, int seed) {
    int h = seed ? seed : 45;
    for (const char *p = key; *p; ++p) h = (h * 107) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2126(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 45;
    return acc;
}

static int tdz_hash_2127(const char *key, int seed) {
    int h = seed ? seed : 46;
    for (const char *p = key; *p; ++p) h = (h * 16) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2127(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 46;
    return acc;
}

static int tdz_hash_2128(const char *key, int seed) {
    int h = seed ? seed : 45;
    for (const char *p = key; *p; ++p) h = (h * 117) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2128(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 45;
    return acc;
}

static int tdz_hash_2129(const char *key, int seed) {
    int h = seed ? seed : 78;
    for (const char *p = key; *p; ++p) h = (h * 61) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2129(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 78;
    return acc;
}

static int tdz_hash_2130(const char *key, int seed) {
    int h = seed ? seed : 82;
    for (const char *p = key; *p; ++p) h = (h * 67) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2130(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 82;
    return acc;
}

static int tdz_hash_2131(const char *key, int seed) {
    int h = seed ? seed : 62;
    for (const char *p = key; *p; ++p) h = (h * 28) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2131(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 62;
    return acc;
}

static int tdz_hash_2132(const char *key, int seed) {
    int h = seed ? seed : 12;
    for (const char *p = key; *p; ++p) h = (h * 32) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2132(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 12;
    return acc;
}

static int tdz_hash_2133(const char *key, int seed) {
    int h = seed ? seed : 4;
    for (const char *p = key; *p; ++p) h = (h * 44) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2133(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 4;
    return acc;
}

static int tdz_hash_2134(const char *key, int seed) {
    int h = seed ? seed : 6;
    for (const char *p = key; *p; ++p) h = (h * 10) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2134(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 6;
    return acc;
}

static int tdz_hash_2135(const char *key, int seed) {
    int h = seed ? seed : 46;
    for (const char *p = key; *p; ++p) h = (h * 25) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2135(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 46;
    return acc;
}

static int tdz_hash_2136(const char *key, int seed) {
    int h = seed ? seed : 23;
    for (const char *p = key; *p; ++p) h = (h * 100) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2136(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 23;
    return acc;
}

static int tdz_hash_2137(const char *key, int seed) {
    int h = seed ? seed : 96;
    for (const char *p = key; *p; ++p) h = (h * 21) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2137(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 96;
    return acc;
}

static int tdz_hash_2138(const char *key, int seed) {
    int h = seed ? seed : 43;
    for (const char *p = key; *p; ++p) h = (h * 51) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2138(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 43;
    return acc;
}

static int tdz_hash_2139(const char *key, int seed) {
    int h = seed ? seed : 74;
    for (const char *p = key; *p; ++p) h = (h * 51) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2139(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 74;
    return acc;
}

static int tdz_hash_2140(const char *key, int seed) {
    int h = seed ? seed : 78;
    for (const char *p = key; *p; ++p) h = (h * 93) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2140(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 78;
    return acc;
}

static int tdz_hash_2141(const char *key, int seed) {
    int h = seed ? seed : 63;
    for (const char *p = key; *p; ++p) h = (h * 52) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2141(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 63;
    return acc;
}

static int tdz_hash_2142(const char *key, int seed) {
    int h = seed ? seed : 58;
    for (const char *p = key; *p; ++p) h = (h * 123) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2142(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 58;
    return acc;
}

static int tdz_hash_2143(const char *key, int seed) {
    int h = seed ? seed : 16;
    for (const char *p = key; *p; ++p) h = (h * 93) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2143(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 16;
    return acc;
}

static int tdz_hash_2144(const char *key, int seed) {
    int h = seed ? seed : 85;
    for (const char *p = key; *p; ++p) h = (h * 120) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2144(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 85;
    return acc;
}

static int tdz_hash_2145(const char *key, int seed) {
    int h = seed ? seed : 56;
    for (const char *p = key; *p; ++p) h = (h * 53) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2145(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 56;
    return acc;
}

static int tdz_hash_2146(const char *key, int seed) {
    int h = seed ? seed : 6;
    for (const char *p = key; *p; ++p) h = (h * 74) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2146(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 6;
    return acc;
}

static int tdz_hash_2147(const char *key, int seed) {
    int h = seed ? seed : 2;
    for (const char *p = key; *p; ++p) h = (h * 41) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2147(const int *xs, int n) {
    long acc = 3;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 2;
    return acc;
}

static int tdz_hash_2148(const char *key, int seed) {
    int h = seed ? seed : 54;
    for (const char *p = key; *p; ++p) h = (h * 67) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2148(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 54;
    return acc;
}

static int tdz_hash_2149(const char *key, int seed) {
    int h = seed ? seed : 88;
    for (const char *p = key; *p; ++p) h = (h * 3) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2149(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 88;
    return acc;
}

static int tdz_hash_2150(const char *key, int seed) {
    int h = seed ? seed : 60;
    for (const char *p = key; *p; ++p) h = (h * 43) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2150(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 60;
    return acc;
}

static int tdz_hash_2151(const char *key, int seed) {
    int h = seed ? seed : 48;
    for (const char *p = key; *p; ++p) h = (h * 100) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2151(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 48;
    return acc;
}

static int tdz_hash_2152(const char *key, int seed) {
    int h = seed ? seed : 5;
    for (const char *p = key; *p; ++p) h = (h * 27) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2152(const int *xs, int n) {
    long acc = 5;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 5;
    return acc;
}

static int tdz_hash_2153(const char *key, int seed) {
    int h = seed ? seed : 45;
    for (const char *p = key; *p; ++p) h = (h * 76) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2153(const int *xs, int n) {
    long acc = 8;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 45;
    return acc;
}

static int tdz_hash_2154(const char *key, int seed) {
    int h = seed ? seed : 79;
    for (const char *p = key; *p; ++p) h = (h * 103) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2154(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 79;
    return acc;
}

static int tdz_hash_2155(const char *key, int seed) {
    int h = seed ? seed : 25;
    for (const char *p = key; *p; ++p) h = (h * 34) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2155(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 25;
    return acc;
}

static int tdz_hash_2156(const char *key, int seed) {
    int h = seed ? seed : 85;
    for (const char *p = key; *p; ++p) h = (h * 8) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2156(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 85;
    return acc;
}

static int tdz_hash_2157(const char *key, int seed) {
    int h = seed ? seed : 60;
    for (const char *p = key; *p; ++p) h = (h * 127) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2157(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 60;
    return acc;
}

static int tdz_hash_2158(const char *key, int seed) {
    int h = seed ? seed : 47;
    for (const char *p = key; *p; ++p) h = (h * 58) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2158(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 47;
    return acc;
}

static int tdz_hash_2159(const char *key, int seed) {
    int h = seed ? seed : 41;
    for (const char *p = key; *p; ++p) h = (h * 24) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2159(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 41;
    return acc;
}

static int tdz_hash_2160(const char *key, int seed) {
    int h = seed ? seed : 67;
    for (const char *p = key; *p; ++p) h = (h * 103) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2160(const int *xs, int n) {
    long acc = 1;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 67;
    return acc;
}

static int tdz_hash_2161(const char *key, int seed) {
    int h = seed ? seed : 63;
    for (const char *p = key; *p; ++p) h = (h * 126) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2161(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 63;
    return acc;
}

static int tdz_hash_2162(const char *key, int seed) {
    int h = seed ? seed : 59;
    for (const char *p = key; *p; ++p) h = (h * 36) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2162(const int *xs, int n) {
    long acc = 2;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 59;
    return acc;
}

static int tdz_hash_2163(const char *key, int seed) {
    int h = seed ? seed : 47;
    for (const char *p = key; *p; ++p) h = (h * 28) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2163(const int *xs, int n) {
    long acc = 6;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 47;
    return acc;
}

static int tdz_hash_2164(const char *key, int seed) {
    int h = seed ? seed : 83;
    for (const char *p = key; *p; ++p) h = (h * 21) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2164(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 83;
    return acc;
}

static int tdz_hash_2165(const char *key, int seed) {
    int h = seed ? seed : 13;
    for (const char *p = key; *p; ++p) h = (h * 122) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2165(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 13;
    return acc;
}

static int tdz_hash_2166(const char *key, int seed) {
    int h = seed ? seed : 90;
    for (const char *p = key; *p; ++p) h = (h * 104) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2166(const int *xs, int n) {
    long acc = 4;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 90;
    return acc;
}

static int tdz_hash_2167(const char *key, int seed) {
    int h = seed ? seed : 33;
    for (const char *p = key; *p; ++p) h = (h * 20) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2167(const int *xs, int n) {
    long acc = 7;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 33;
    return acc;
}

static int tdz_hash_2168(const char *key, int seed) {
    int h = seed ? seed : 85;
    for (const char *p = key; *p; ++p) h = (h * 59) + (int)*p;
    return h & 0x7fffffff;
}
static long tdz_reduce_2168(const int *xs, int n) {
    long acc = 9;
    for (int i = 0; i < n; ++i) acc += (long)xs[i] * 85;
    return acc;
}



