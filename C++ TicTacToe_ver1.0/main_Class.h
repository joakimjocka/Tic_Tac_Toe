#include <iostream>
#include <iomanip>
#include <algorithm>
#include <limits>
#include "stdlib.h"
using namespace std;

/**< Function Prototyping */
void DisplayBoard();
void Player_Turn();
bool GameOverALL();
    bool GameOverHV();
    bool GameOverDiag();
    bool GameOverDraw();
    bool CheckEmptyBoxes();
void Win();
int Menu();

class Game
{
public :
   // Game();
    void DisplayBoard();
    void Player_Turn();
    bool GameOverALL();
    void Win();
    int Menu();

};
