#include <entity.hpp>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <algorithms.hpp>

void print_ids(core::entity& entity)
{
    auto [id_first, id_last] = entity.property_range("ID");
    std::copy(id_first, id_last, std::ostream_iterator<std::string>{std::cout, " "});
}

void print_property(core::entity& entity, const std::string& property_name)
{
    auto [first, last] = entity.property_range(property_name);
    std::copy(first, last, std::ostream_iterator<std::string>{std::cout, " "});
}

int main() {
    core::entity lab;
    std::fstream input{"labs.txt"};
    input >> lab;
    auto [header_first, header_last] = lab.header_range();
    std::cout << "Column names:";
    std::copy(header_first, header_last, std::ostream_iterator<std::string>{std::cout, " "});

    std::cout << "\nIDs: ";
    print_ids(lab);
    //std::copy(id_first, id_last, std::ostream_iterator<std::string>{std::cout, " "});

    std::cout << "\nNames: ";
    auto [names_first, names_last] = lab.property_range("Name");
    std::copy(names_first, names_last, std::ostream_iterator<std::string>{std::cout, " "});

    std::cout << "\nMangled IDs: ";
    algo::mangle_ids(lab);
    print_ids(lab);
    //std::copy(id_first, id_last, std::ostream_iterator<std::string>{std::cout, " "});


}