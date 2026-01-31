#include "Common.h"

// ---------- Declaring states ----------
State CurrentState = MENU;     // Initial game state
State PendingState;
State PreviousState;

Vector2 MousePosition;        // Vector position of mouse
