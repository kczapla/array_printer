#include <vector>
#include "array_printer.hpp"

int main(int argc, char const* argv[])
{
    std::vector<int> array1 {1, 2, 3, 4, 5, 6, 7777777};
    RowPrinter ap = RowPrinter(4);
    ap.print(array1);
    std::vector<int> array2 {1, 22, 333, 4444, 55555, 666666, 7777777, 88888888};
    ap.print(array2);

    return 0;
}



