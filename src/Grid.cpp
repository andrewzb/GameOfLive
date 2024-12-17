#include <raylib.h>
#include <iostream>
#include "./Grid.hpp"

Grid::Grid(int width, int height, int cellSize)
        : rows(height/cellSize), columns(width/cellSize), cellSize(cellSize), cells(rows, std::vector<int>(columns,0)) {}

Grid::~Grid() {}

void Grid::Draw() {
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            Color color = cells[row][column] ? Color {0,255,0,255}: Color {55,55,55,255};
            DrawRectangle(column * cellSize, row * cellSize, cellSize - 1, cellSize - 1 , color);
        }
    }
}

void Grid::SetValue(int row, int column, int value) {
    if (row >= 0 && row < rows && column >= 0 && column < columns) {
        cells[row][column] = value;
    }
}

int Grid::GetValue(int row, int column) {
    if (IsWithinBounds(row, column)) {
        return cells[row][column];
    }
    return 0;
}

bool Grid::IsWithinBounds(int row, int column) {
    return row >= 0 && row < rows && column >= 0 && column < columns;
}

int Grid::GetRows() {
    return rows;
}

int Grid::GetColumns() {
    return columns;
}

void Grid::FillRandom() {
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            int randomValue = GetRandomValue(0, 4);
            cells[row][column] = randomValue == 4 ? 1 : 0;
        }
    }
}

void Grid::Clear() {
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            cells[row][column] = 0;
        }
    }
}

void Grid::ToggleCell(int row, int column) {
    if (IsWithinBounds(row, column)) {
        cells[row][column] = !cells[row][column];
    }
}
