// adapted from TestU01 manual

#include "TestU01.h"

// example PRNG: xorshift 32

static unsigned int y = 2463534242U;
unsigned int xorshift(void)
{
    y ^= (y << 13);
    y ^= (y >> 17);
    return y ^= (y << 5);
}

int main()
{
    // Create TestU01 PRNG object for our generator
    unif01_Gen *gen = unif01_CreateExternGenBits("Xorshift 32", xorshift);

    // Run the tests.
    bbattery_SmallCrush(gen);

    // Clean up.
    unif01_DeleteExternGenBits(gen);

    return 0;
}