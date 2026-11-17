#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>

// Clears the terminal screen.
void clearScreen();

// Displays the startup animation.
void showStartup();

// Displays the main menu.
void showMainMenu();

// Displays a calculation result.
void showResult(const std::string &message);

// Displays the menu after a calculation.
void showNextStepMenu();

// Displays the shutdown animation.
void showExit();

#endif