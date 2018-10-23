#include <algorithm>
#include <iostream>
#include <vector>

#include "counters.hpp"

void print_vector(std::vector<int> v);
std::vector<int> get_columns_size(int number_of_columns, std::vector<int> numbers);
void print(std::vector<int> numbers);
void print_plus_minus_line(std::vector<int> spaces_between_plus_sign, int number_of_cells);
void print_values_line(std::vector<int> size_between_separators, std::vector<int> values);
std::vector<std::vector<int>> divide_values_range_into_subrange(std::vector<int> values_range, int subrange_size);


int main(int argc, char const* argv[])
{
    std::vector<int> array1 {1, 2, 3, 4, 5, 6, 7777777, 1234};
    print(array1);

    std::vector<int> array3 {1, 22, 333, 4444, 55555, 666666, 7777777, 88888888, 89};
    print(array3);

    return 0;
}


std::vector<int> get_columns_size(int number_of_columns, std::vector<int> numbers)
{
    std::vector<int> columns_size(number_of_columns, 0);
    auto index = 0;
    for (auto&& val : numbers) {
        if (index == number_of_columns) {
            index = 0;
        }
        columns_size[index] = std::max(number_of_digits(val), columns_size[index]);
        index++;
    }
    return columns_size;
}


void print(std::vector<int> numbers)
{
    auto x = divide_values_range_into_subrange(numbers, 4);
    auto columns_size = get_columns_size(4, numbers);

    print_plus_minus_line(columns_size, x[0].size());
    for (auto&& var : x) {
        print_values_line(columns_size, var);
        print_plus_minus_line(columns_size, var.size());
    }
}


void print_plus_minus_line(std::vector<int> spaces_between_plus_sign, int number_of_cells)
{
    auto cell_counter = 0;
    for (auto&& var : spaces_between_plus_sign) {
        if (cell_counter == number_of_cells) {
            break;
        }
        std::cout << "+";
        for (int i = 0; i < var; i++) {
            std::cout << "-";
        }
        cell_counter++;
    }
    std::cout << "+" << std::endl;
}

void print_values_line(std::vector<int> size_between_separators, std::vector<int> values)
{
    for (int i = 0; i < values.size(); i++) {
        std::cout << "|";
        auto spaces = size_between_separators[i] - number_of_digits(values[i]);
        for (int j = 0; j < spaces; j++) {
            std::cout << " ";
        }
        std::cout << values[i];
    }
    std::cout << "|" << std::endl;
}


std::vector<std::vector<int>>
divide_values_range_into_subrange(std::vector<int> values_range, int subrange_size)
{
    std::vector<std::vector<int>> subranges;
    std::vector<int> subrange;
    auto subrange_counter = 1; 
    auto range_counter = 0;
    for (auto&& var : values_range) {
        subrange.push_back(var);
        range_counter++;
        if ((subrange_counter % subrange_size == 0) or (range_counter % values_range.size() == 0)) {
            subranges.push_back(subrange);
            subrange.clear();
            subrange_counter = 1;
            continue;
        }
        subrange_counter++;
    }
    return subranges;
}


void print_vector(std::vector<int> v)
{
    for (auto var : v) {
        std::cout << var << ", ";
    }
    std::cout << std::endl;
}
