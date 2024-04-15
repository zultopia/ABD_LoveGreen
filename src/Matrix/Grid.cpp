// #include "Grid.hpp"

// template<class T>
// Grid<T>::Grid() {}

// template<class T>
// Grid<T>::Grid(int numRows, int numCols) : grid(numRows, vector<T*>(numCols)) {}

// template<class T>
// void Grid<T>::updateCell(int row, int col, T* value) {
//     if (row >= 0 && row < grid.size() && col >= 0 && col < grid[row].size()) {
//         grid[row][col] = value;
//     }
// }

// template<class T>
// T* Grid<T>::getCell(int row, int col) const {
//     return grid[row][col];
// }

// template<class T>
// void Grid<T>::removeItem(int row, int col) {
//     if (row >= 0 && row < grid.size() && col >= 0 && col < grid[row].size()) {
//         delete grid[row][col];
//         grid[row][col] = nullptr;
//     }
// }

// template<class T>
// vector<vector<T*> > Grid<T>::getGrid() const {
//     return grid;
// }

// template<class T>
// int Grid<T>::getRows() const {
//     return grid.size();
// }

// template<class T>
// int Grid<T>::getCols() const {
//     return grid.empty() ? 0 : grid[0].size();
// }