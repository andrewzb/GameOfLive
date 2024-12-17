#ifndef SIMULATION_H
#define SIMULATION_H

#include "./Grid.hpp"


class Simulation {
    private:
        Grid grid;
        Grid tempGrid;
        bool isRunning;
    public:
        ~Simulation();
        Simulation(int width, int height, int cellSize);
        void Draw();
        void SetCellValue(int row, int column, int value);
        int CountLiveNeighbors(int row, int column);
        void Update();
        bool IsRunning();
        void Start();
        void Stop();
        void ClearGrid();
        void CreateRandomState();
        void ToggleCell(int row, int column);
};

#endif