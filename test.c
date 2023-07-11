#include <stdio.h>

typedef __uint8_t u8;
typedef __uint16_t u16;
typedef __uint32_t u32;

u16 CRC16(u8 *data, size_t length, u16 CRC_register, u16 polynomial)
{
    for (size_t i = 0; i < length; i++)
    {
        CRC_register ^= data[i];
        for (size_t j = 0; j < 8; j++)
        {
            if (CRC_register & 0x0001)
            {
                CRC_register >>= 1;
                CRC_register ^= polynomial;
            }
            else
                CRC_register >>= 1;
        }
    }
    return CRC_register;
}

int main(void)
{
    u8 data[5] = {1, 4, 2, 0xff,0xff};
    printf("%x", CRC16(data, sizeof(data), 0xFFFF, 0xA001));
    return 0;
}
