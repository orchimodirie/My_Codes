#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

// Define the boundaries of our console "window"
const int WIDTH = 40;
const int HEIGHT = 15;

int main() {
    // 1. Initial State (Position)
    int x = WIDTH / 2;
    int y = HEIGHT / 2;

    // 2. Kinematics (Velocity)
    // vx = movement on the X-axis, vy = movement on the Y-axis
    int vx = 1;
    int vy = 1;

    // Infinite loop for our simulation
    while (true) {
        
        // --- PHYSICS UPDATE ---
        // Update position based on velocity
        x += vx;
        y += vy;

        // Check for collisions with the walls
        // If it hits a wall, reverse the velocity (bounce)
        if (x <= 0 || x >= WIDTH - 1) {
            vx = -vx; 
        }
        if (y <= 0 || y >= HEIGHT - 1) {
            vy = -vy; 
        }

        // --- RENDER (DRAWING) ---
        // Move the cursor to the top-left (1,1) instead of completely clearing the screen.
        // This prevents the screen from flickering violently at higher framerates!
        cout << "\033[1;1H"; 

        // Draw the grid
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                // If the current grid coordinate matches our circle's position, draw it
                if (i == y && j == x) {
                    cout << 'O'; // The moving circle
                } 
                // Draw the walls
                else if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {
                    cout << '#'; 
                } 
                // Draw empty space
                else {
                    cout << ' '; 
                }
            }
            cout << endl; // Next line of the grid
        }

        // Print current stats below the box
        cout << "Kinematics Status:" << endl;
        cout << "Position: (x=" << x << ", y=" << y << ")" << endl;
        cout << "Velocity: (vx=" << vx << ", vy=" << vy << ")" << endl;
        cout << "\nPress Ctrl+C to exit." << endl;

        // --- TIME DELAY ---
        // Sleep for 33 milliseconds to create a ~30 FPS frame rate (1000ms / 30 = 33.3ms)
        this_thread::sleep_for(chrono::milliseconds(33));
    }

    return 0;
}