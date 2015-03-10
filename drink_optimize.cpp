
#include <iostream>
#include <vector>

struct Drink
{
    int32_t volume;
    int32_t capacity;
    int32_t number;
    int32_t benefit;
};

int32_t optimize(std::vector<Drink> &drinks, int32_t total_volume)
{
    assert(!drinks.empty() && total_volume != 0);
    std::vector<std::vector<int32_t> > opt(drinks.size() + 1,
            std::vector<int32_t>(total_volume + 1, 0));
    for(std::vector<Drink>::reverse_iterator rit = drinks.rbegin();
            rit != drinks.rend();
            rit++)
    {
        std::vector<Drink>::size_type index = drinks.size() - (rit - drinks.rbegin()) - 1;
        for(int32_t volume = 0; volume <= total_volume; volume++)
        {
            for(int32_t number = 0; number <= rit->capacity; number++)
            {
                if(number * rit->volume > volume)
                {
                    break;
                }
                int32_t cur_benefit =
                    opt[index + 1][volume - number * rit->volume] + number * rit->benefit;
                if(cur_benefit > opt[index][volume])
                {
                    opt[index][volume] = cur_benefit;
                    rit->number = number;
                }
            }
        }
    }
    return opt[0][total_volume];
}

int32_t main()
{
    std::vector<Drink> drinks;
    const int32_t SIZE = 3;
    for(int32_t i = 0; i < SIZE; i++)
    {
        Drink d;
        d.volume = 10;
        d.capacity = 1;
        d.number = 0;
        d.benefit = i + 1;
        drinks.push_back(d);
    }
    int32_t total_volume = 30;
    std::cout << optimize(drinks, total_volume) << std::endl;
    for(std::vector<Drink>::iterator it = drinks.begin();
            it != drinks.end();
            it++)
    {
        std::cout << it->number << std::endl;
    }
    return 0;
}
