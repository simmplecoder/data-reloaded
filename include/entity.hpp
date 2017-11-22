#ifndef UNTITLED_ENTITY_HPP
#define UNTITLED_ENTITY_HPP

#include <unordered_map>
#include <vector>
#include <string>
#include <iosfwd>
#include <utility>

namespace core {
    template <typename Iterator>
    using iterator_range = std::pair<Iterator, Iterator>;

    class entity {
        using row = std::unordered_map<std::string, std::string>;
        std::vector<row> instances;
        std::vector<std::string> header;
    public:
        using header_iterator = std::vector<std::string>::iterator;
        iterator_range<header_iterator> header_range();

        class property_iterator
        {
            friend entity;
            using row = std::unordered_map<std::string, std::string>;
            std::vector<row>::iterator current_row;
            std::string  property_name;
        public:
            using iterator_category = std::forward_iterator_tag;
            using value_type = std::string;
            using difference_type = std::vector<row>::iterator::difference_type;
            using pointer = value_type*;
            using reference = value_type&;

            std::string& operator*()
            {
                return (*current_row)[property_name];
            }

            std::string& operator*() const
            {
                return (*current_row)[property_name];
            }

            property_iterator& operator++()
            {
                ++current_row;
                return *this;
            }

            property_iterator operator++(int)
            {
                auto old = *this;
                ++current_row;
                return old;
            }
            friend bool operator==(const property_iterator& lhs, const property_iterator& rhs);
            friend bool operator!=(const property_iterator& lhs, const property_iterator& rhs);

        private:
            property_iterator(std::vector<row>::iterator current,
                              const std::string& property_name);
        };

        iterator_range<property_iterator> property_range(const std::string& property_name);

        friend std::istream &operator>>(std::istream &is, entity &ent);
    };

    std::istream& operator>>(std::istream& is, entity& ent);
}

#endif //UNTITLED_ENTITY_HPP