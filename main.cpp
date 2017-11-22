#include <entity.hpp>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <iostream>

int main() {
    core::entity lab;
    std::fstream input{"labs.txt"};
    input >> lab;
    auto [header_first, header_last] = lab.header_range();
    std::cout << "Column names:"
    std::copy(header_first, header_last, std::ostream_iterator<std::string>{std::cout, " "});

    auto [id_first, id_last] = lab.property_range("ID");
    std::cout << "\nIDs: ";
    std::copy(id_first, id_last, std::ostream_iterator<std::string>{std::cout, " "});
    std::cout << "\nNames: ";


}