#ifndef GRID_H
#define GRID_H

#include <vector>

class Grid {
    private:
        int rows;
        int columns;
        int cellSize;
        std::vector<std::vector<int>> cells;
        bool IsWithinBounds (int row, int column);
    public:
        ~Grid();
        Grid(int width, int height, int cellSize);
        void Draw ();
        void SetValue(int row, int column, int value);
        int GetValue(int row, int column);
        int GetRows();
        int GetColumns();
        void FillRandom();
        void Clear();
        void ToggleCell(int row, int column);
        
};

#endif