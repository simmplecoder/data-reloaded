#ifndef UNTITLED_ALGORITHMS_HPP
#define UNTITLED_ALGORITHMS_HPP

#include <string>
#include <algorithm>
#include "entity.hpp"
#include "id_generator.hpp"
#include "random_selector.hpp"

namespace core
{
    class entity;
}

namespace algo
{
    void mangle_ids(core::entity& entity, const std::string& id_name = "ID")
    {
        auto [id_first, id_last] = entity.property_range(id_name);
        data_generation::id_generator generator;
        auto id_generator = [&generator](const auto& elem)
                            {return std::to_string(generator());};

        std::transform(id_first, id_last, id_first, id_generator);
    }
    void associate(core::entity& target, core::entity& source,
                   const std::string& reference_name = "LabID")
    {
        auto [source_first, source_last] = source.property_range("ID");
        auto [target_first, target_last] = target.property_range(reference_name);
        shino::random_selector<std::string> random_selector{source_first, source_last};
        while (target_first != target_last)
        {
            *target_first++ = random_selector();
        }
    }
}

#endif //UNTITLED_ALGORITHMS_HPP
