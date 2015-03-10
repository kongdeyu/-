
#include <iostream>

const int32_t WIDTH = 4;
const unsigned char MASK = 0xff;
const unsigned char LMASK = MASK << WIDTH;
const unsigned char RMASK = MASK >> WIDTH;
const int32_t ROW = 3;

#define LGET(num) ((num & LMASK) >> WIDTH)
#define RGET(num) (num & RMASK)
#define LSET(num, res) (num = (((num & RMASK) | (res << WIDTH))))
#define RSET(num, res) (num = ((num & LMASK) | res))

void get_available_pos_1()
{
    unsigned char num;
    for(LSET(num, 0); LGET(num) < ROW * ROW; LSET(num, LGET(num) + 1))
    {
        for(RSET(num, 0); RGET(num) < ROW * ROW; RSET(num, RGET(num) + 1))
        {
            if(LGET(num) % ROW != RGET(num) % ROW)
            {
                std::cout << "("
                    << LGET(num)
                    << ", "
                    << RGET(num)
                    << ") ";
            }
        }
    }
}

void get_available_pos_2()
{
    const unsigned char SIZE = 81;
    for(unsigned char pos = 0; pos < SIZE; pos++)
    {
        if(pos / (ROW * ROW) % ROW != pos % (ROW * ROW) % ROW)
        {
            std::cout << "("
                << pos / (ROW * ROW)
                << ", "
                << pos % (ROW * ROW)
                << ") ";
        }
    }
}

int32_t main()
{
    get_available_pos_1();
    std::cout << std::endl;
    get_available_pos_2();
    std::cout << std::endl;
    return 0;
}
