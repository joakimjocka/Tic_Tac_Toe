#include "main_Class.h"

int main()
{
    /**< Create Instance of Game Object */
    Game TicTacToe;

    switch(TicTacToe.Menu())
    {
        case 1:
           while( TicTacToe.GameOverALL() )
            {
                TicTacToe.DisplayBoard();
                TicTacToe.Player_Turn();
                TicTacToe.GameOverALL();
            }
            TicTacToe.Win();
            break;

        case 2:
            break;

        case 3:
            cout << "\t>>>>>>EXIT<<<<<<\n";
            exit(1);
            break;

        default:
            cout << "Invalid Option, Try Again\n";
    }

    return 0;
}





