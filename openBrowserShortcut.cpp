#include <iostream>
#include <windows.h>

int main() {
    // Path to Firefox executable, change this if needed.
    const char* firefoxPath = "C:\\Program Files\\Mozilla Firefox\\firefox.exe";
    
    std::cout << "Press Windows + Left Control + B to open Firefox." << std::endl;
    std::cout << "Press Windows + Left Control + Q to quit the program." << std::endl;
    
    while (true) {
        // Check if the Left Windows key, Left Control key, and B key are pressed.
        if ((GetAsyncKeyState(VK_LWIN) & 0x8000) && 
            (GetAsyncKeyState(VK_LCONTROL) & 0x8000) && 
            (GetAsyncKeyState(0x42) & 0x8000)) {
            
            // If Windows + Left Control + B is pressed, open Firefox
            std::cout << "Left Control + B pressed, opening Firefox..." << std::endl;
            ShellExecute(0, "open", firefoxPath, 0, 0, SW_SHOWNORMAL);
            
            Sleep(1000); // 1 second delay to prevent repeated launches
        }
        
        // Check if the Left Windows key, Left Control key, and Q key are pressed to quit.
        if ((GetAsyncKeyState(VK_LWIN) & 0x8000) && 
            (GetAsyncKeyState(VK_LCONTROL) & 0x8000) && 
            (GetAsyncKeyState(0x51) & 0x8000)) {
            
            // If Windows + Left Control + Q is pressed, exit the program
            std::cout << "Left Control + Q pressed, quitting program..." << std::endl;
            break;  // Exit the loop and terminate the program
        }

        // Small delay to reduce CPU usage
        Sleep(100);
    }

    return 0;
}
