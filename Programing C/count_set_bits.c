#include<stdio.h>

#define H(x, n) ((x) >> (n) & 1)
#define H2(x, n) H(x, 4*(n)) + H(x, 4*(n)+1) + H(x, 4*(n)+2) + H(x, 4*(n)+3)
#define H3(x, n) H2(x, n) + H2(x, n + 1)

#define CALL5(x) H3(x, 0)
#define CALL4(x) CALL5(4*(x)), CALL5(4*(x)+1), CALL5(4*(x)+2), CALL5(4*(x)+3)
#define CALL3(x) CALL4(4*(x)), CALL4(4*(x)+1), CALL4(4*(x)+2), CALL4(4*(x)+3)
#define CALL2(x) CALL3(4*(x)), CALL3(4*(x)+1), CALL3(4*(x)+2), CALL3(4*(x)+3)
#define CALL1(x) CALL2(4*(x)), CALL2(4*(x)+1), CALL2(4*(x)+2), CALL2(4*(x)+3)

unsigned count_set_bits[256] = { CALL1(0) };

int main()
{
    return 0;
}

