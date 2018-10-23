#include <algorithm>
#include <iostream>
#include <vector>

#include "counters.hpp"

void print_vector(std::vector<int> v);
std::vector<int> get_columns_size(int number_of_columns, std::vector<int> numbers);
void print(std::vector<int> size_of_columns, std::vector<int> numbers);
void print_horizontal_line(int size);
void print_cell_content(int value, int columns_size);
void print_horizontal_lines(std::vector<int> size_of_columns);


int main(int argc, char const* argv[])
{
    std::vector<int> array1 {1, 2, 3, 4, 5, 6, 7777777, 1234, 856};
    auto columns = 4;
    auto columns_size = get_columns_size(columns, array1);
    print_vector(columns_size);
    print(columns_size, array1);

    std::vector<int> array2 {1, 22, 333, 4444, 55555, 666666, 7777777, 88888888};

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
        columns_size[index] = std::max(count_number_size(val), columns_size[index]);
        index++;
    }
    return columns_size;
}


void print(std::vector<int> size_of_columns, std::vector<int> numbers)
{
    auto col = 0;
    auto first_row = true;
    print_horizontal_lines(size_of_columns);
    std::cout << "|";
    for (auto&& var : numbers) {
        print_cell_content(var, size_of_columns[col]);
        std::cout << "|";
        if (col == size_of_columns.size() - 1) {
            std::cout << std::endl;
            print_horizontal_lines(size_of_columns);
            std::cout << "|";
            col = 0;
            continue;
        }
        col++;
    }
}


void print_horizontal_lines(std::vector<int> size_of_columns)
{
    std::cout << "+";
    for (auto&& var : size_of_columns) {
        print_horizontal_line(var);
    }
    std::cout << std::endl;
}


void print_horizontal_line(int size)
{
    for (int i = 0; i < size; i++) {
        std::cout << "-";
    }
    std::cout << "+";
}


void print_cell_content(int value, int columns_size)
{
    auto spaces = columns_size - count_number_size(value);
    for (int i = 0; i < spaces; i++) {
        std::cout << " ";
    }
    std::cout << value;
}


void print_vector(std::vector<int> v)
{
    for (auto var : v) {
        std::cout << var << ", ";
    }
    std::cout << std::endl;
}
