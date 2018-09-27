#include <vector>


class RowPrinter {
    private:
        int columns_no;
        int cell_size = 6;

        void print_cell(int x);
        void print_cell_plus_side(int cell_size);
        void print_cell_side();
        int get_number_size(int x);
        
    public:
        RowPrinter(int col);
        void print(std::vector<int> arr);
};


class CellPrinter {
    private:
        int cell_size = 6;
        void print_top_edge();

    public:
        CellPrinter(int size);
        void print(int val);
};
