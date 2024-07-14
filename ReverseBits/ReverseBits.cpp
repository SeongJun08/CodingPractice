#include <iostream>
#include <bitset>

uint32_t ReverseBits(uint32_t n)
{
    uint32_t result = 0;

    for (int i = 0; i < 32; i++)
    {
        result |= ((n >> i) & 1) << (31 - i);
    }
    return result;
}

int main()
{
    uint32_t num = 43261596;
    uint32_t reverse = ReverseBits(num);

    std::cout << "Original : " << std::bitset<32>(num) << std::endl;
    std::cout << "Reversed : " << std::bitset<32>(reverse) << std::endl;

}
