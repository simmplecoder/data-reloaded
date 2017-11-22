#include "../include/entity.hpp"
#include <sstream>
#include <algorithm>
#include <iterator>
#include <iostream>

std::vector<std::string> parse_header(std::istream& is)
{
    std::vector<std::string> header;
    std::string header_buffer;
    std::getline(is, header_buffer);
    std::istringstream iss{header_buffer};
    std::copy(std::istream_iterator<std::string>{iss}, {},
              std::back_inserter(header));

    return header;
}

namespace core
{
    std::istream& operator>>(std::istream& is, entity& ent)
    {
        ent.header = parse_header(is);

        std::string line;
        while (std::getline(is, line))
        {
            std::istringstream iss{line};
            std::unordered_map<std::string, std::string> instance;
            for (const auto& column_name: ent.header)
            {
                iss >> instance[column_name];
            }

            if (!iss.eof())
            {
                std::cerr << "all column values are read, but line did not end yet.\n";
            }

            ent.instances.push_back(std::move(instance));
        }

        return is;
    }

    iterator_range<entity::header_iterator> entity::header_range()
    {
        return {header.begin(), header.end()};
    }

    iterator_range<entity::property_iterator> entity::property_range(const std::string &property_name)
    {
        if (std::find(header.begin(), header.end(), property_name) == header.end())
        {
            throw std::invalid_argument{"the property does not exist"};
        }

        property_iterator first{instances.begin(), property_name};
        property_iterator last{instances.end(), property_name};
        return {first, last};
    }

    entity::property_iterator::property_iterator(std::vector<row>::iterator current,
                                                 const std::string &property_name):
            current_row{current},
            property_name{property_name}
    {}

    bool operator==(const entity::property_iterator& lhs,
                    const entity::property_iterator& rhs)
    {
        return lhs.current_row == rhs.current_row &&
               lhs.property_name == rhs.property_name;
    }

    bool operator!=(const entity::property_iterator& lhs,
                    const entity::property_iterator& rhs)
    {
        return !(lhs == rhs);
    }
}