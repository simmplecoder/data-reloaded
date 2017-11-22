#ifndef DATA_GENERATORS_ID_GENERATOR_HPP
#define DATA_GENERATORS_ID_GENERATOR_HPP

#include <random>
#include <set>

namespace data_generation
{
    class id_generator
    {
    public:
        using id_type = unsigned long long;

    private:
        std::mt19937_64 twister;
        std::uniform_int_distribution<unsigned long> distribution;
        std::set<id_type> prev_ids;
    public:
        id_generator();

        id_type operator()();
    };
}

#endif //DATA_GENERATORS_ID_GENERATOR_HPP
