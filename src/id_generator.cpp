#include <id_generator.hpp>
#include <limits>

namespace data_generation
{
    id_generator::id_generator() :
            distribution{10'000'000, 99'999'999}
    {}

    id_generator::id_type id_generator::operator()()
    {
        static_assert(std::numeric_limits<id_type>::digits10 > 8,
                      "unsigned long on this platform is too short");
        id_type new_id = distribution(twister);
        while (prev_ids.find(new_id) != prev_ids.end())
        {
            new_id = distribution(twister);
        }

        prev_ids.insert(new_id);
        return new_id;
    }
}