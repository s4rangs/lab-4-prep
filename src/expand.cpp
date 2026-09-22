#include <cassert>  // assert
#include <cstddef>  // size_t
#include <cstdint>  // uint64_t, uint32_t

// Expands the binary representation of input by a factor of scale.
// e.g., expand(0b1111ull, 3) == 0b001001001001
uint64_t expand(uint64_t input, uint32_t scale) {
    assert(scale >= 1);

    uint64_t output = 0;

    for (uint32_t i = 0; i < 64; ++i) {
        if ((input & (uint64_t{1} << i)) != 0) {
            uint32_t position = i * scale;

            if (position < 64) {
                output |= uint64_t{1} << position;
            }
        }
    }

    return output;
}

int main() {
    // test here...
    assert(expand(0b1111ull, 3) == 0b001001001001ull);
    assert(expand(0b0101ull, 2) == 0b00010001ull);
    return 0;
}
