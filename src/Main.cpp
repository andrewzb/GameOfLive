#include <iostream>
#include <raylib.h>
#include <raymath.h>
#include "./Simulation.hpp"

int main () {
    Color GREY = { 29, 29, 29, 255 };
    const int WINDOW_WIDTH = 750;
    const int WINDOW_HEIGHT = 750;
    const int CELL_SIZE = 10;
    int FPS = 12;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "GAME OF LIFE");
    SetTargetFPS(FPS);

    Simulation simulation { WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE };

    while(WindowShouldClose() == false) {

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            Vector2 mousePosition = GetMousePosition();
            int row = mousePosition.y / CELL_SIZE;
            int column = mousePosition.x / CELL_SIZE;
            simulation.ToggleCell(row, column);

        }

        if (IsKeyPressed(KEY_SPACE)) {
            if (simulation.IsRunning()) {
                simulation.Stop();
                SetWindowTitle("GAME OF LIFE is stoped ...");
            } else {
                simulation.Start();
                SetWindowTitle("GAME OF LIFE is running ...");
            }
        }

        if (IsKeyPressed(KEY_W)) {
            FPS += 2;
            SetTargetFPS(FPS);
        } else if (IsKeyPressed(KEY_S)) {
            if (FPS > 5) {
                FPS -= 2;
                SetTargetFPS(FPS);
            }
        } else if (IsKeyPressed(KEY_R)) {
            simulation.CreateRandomState();
        } else if (IsKeyPressed(KEY_C)) {
            simulation.ClearGrid();
        }

        simulation.Update();

        BeginDrawing();
        ClearBackground(GREY);
        simulation.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}