/*
    * raygui-cmake-template - A simple template for creating raylib applications with raygui.
    *
    * This template provides a basic structure for creating raylib applications with raygui.
    * It includes a simple example of how to use raygui with raylib and demonstrates how to
    * render UI elements to the screen.
    *
    * This template is intended to be used with raylib and raygui, which are both included
    * as submodules in the project. The template is designed to be built using CMake.
    *
    * This has been made as simple as possible for the current template
    * this can obviously be fittet to your need based on size of project. 
    * 
    * To build the project, run the following command:
    *     make
    *
    * This will generate an executable named `mbn-raygui-cmake-template.exe` in the build directory.
    * The executable can be run from the command line or by double-clicking on it.
    *
    * The template is licensed under the MIT License. See LICENSE for more information.
*/

#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

/**
 * @brief Renders the user interface elements to the screen.
 *        Just a simple example of how to use raygui with raylib.
 *
 * This function handles the drawing of UI components using raygui.
 * It scales the font size relative to the window height and centers
 * a text label in the middle of the window.
 *
 * Features:
 * - Dynamic font scaling based on window height
 * - Centered text positioning
 * - Uses raygui's GuiLabel for text rendering
 *
 * @note The function automatically adjusts to window resizing since it uses
 *       GetScreenWidth() and GetScreenHeight()
 */
void drawUI(void) 
{
    int windowWidth = GetScreenWidth();
    int windowHeight = GetScreenHeight();
    float fontSize = windowHeight * 0.05f;

    GuiSetStyle(DEFAULT, TEXT_SIZE, fontSize);

    // Example label
    const char *labelText = "raygui-cmake-template!";
    Vector2 textSize = MeasureTextEx(GetFontDefault(), labelText, fontSize, 1);
    GuiLabel(
        (Rectangle)
        {
            (windowWidth - textSize.x) / 2,
            (windowHeight - textSize.y) / 2,
            textSize.x,
            textSize.y
        },
        labelText
    );
}

/**
 * @brief Updates the GUI elements and handles user interactions. 
 *        This is simply just an exmaple and can be modified to suit your needs.
 * 
 * This function is responsible for:
 * - Getting current window dimensions
 * - Creating and handling a centered button
 * - Displaying a label when button is clicked
 * - Logging button click events
 * 
 * The button is positioned relative to the window center and triggers
 * both a trace log message and a GUI label when clicked.
 * 
 * @note Function is expected to be called every frame
 */
void update(void) 
{
    int windowWidth = GetScreenWidth();
    int windowHeight = GetScreenHeight();

    // Example button
    if (GuiButton
    (
        (Rectangle){
            windowWidth / 2 - 50,
            windowHeight / 2 + 40,
            100,
            30
        },
        "Click Me")) 
    {
        TraceLog(LOG_INFO, "Button clicked!");
        GuiLabel
        (
            (Rectangle)
            {
                windowWidth / 2 - 50,
                windowHeight / 2 + 80,
                100,
                30
            },
            "Button clicked!"
        );
    }
}

/**
 * @brief Main entry point of the RayGui application
 *
 * Initializes a window with 800x450 resolution titled "RayGui Template".
 * Sets the target frame rate to 60 FPS and runs the main game loop.
 * The loop handles drawing the UI and updating the application state
 * until the window is closed.
 *
 * @return Returns 0 on successful execution
 */

/* MAIN */
int main(void)
{
    InitWindow(800, 450, "mbn-raygui-cmake-template");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            drawUI();
            update();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
