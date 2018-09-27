#include <iostream>
#include "./array_printer.hpp"


RowPrinter::RowPrinter(int col) {
    this->columns_no = col;
}


void RowPrinter::print(std::vector<int> arr) {
    int col_counter = 0;
    for (auto&& var : arr) {
        this->print_cell(var);
        if (col_counter + 1 == this->columns_no) {
            col_counter = 0;
        }
        col_counter++;
    }
}


void RowPrinter::print_cell(int x) {
    auto ns = this->get_number_size(x);
    auto adjusted_cell_size(this->cell_size);
    auto spaces_inside_cell = 0;
    if (ns > this->cell_size) {
        adjusted_cell_size = ns;
    }
    else {
        spaces_inside_cell = this->cell_size - ns;
    }

    this->print_cell_plus_side(adjusted_cell_size);
    std::cout << std::endl;

    std::cout << "|";

    for (int i = 0; i < spaces_inside_cell; i++) {
        std::cout << " ";
    }
    std::cout << x;
    std::cout << "|";

    std::cout << std::endl;
    this->print_cell_plus_side(adjusted_cell_size);
}

int RowPrinter::get_number_size(int x) {
    int number_size = 1;
    while (1) {
        x /= 10;
        if (x == 0) {
            break;
        }
        number_size++;
    }
    return number_size;
}


void RowPrinter::print_cell_plus_side(int cell_size) {
    std::cout << "+";
    for (int i = 0; i < cell_size; i++) {
        std::cout << "-";
    }
    std::cout << "+";
}
