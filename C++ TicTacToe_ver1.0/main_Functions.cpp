#include "main_Class.h"

/**< Global Variables */
char BoardArr[3][3] = {{'1','2','3'},
                       {'4','5','6'},
                       {'7','8','9'}};
int choice;
char turn = 'X';
int row,column;
bool draw = false;
int Score , Current_Score, Menu_Option;

/**< Functions */
void Game::DisplayBoard()
{
    system("cls");
    cout << "\t\t T I C T A C T O E" << endl;

    cout << " Player 1 [X]: \n";
    cout << " Player 2 [O]: \n";

    cout << "\t\t      |     |     \n";
    cout << "\t\t   "<<BoardArr[0][0]<<"  |  "<<BoardArr[0][1]<<"  |  "<<BoardArr[0][2]<<"\n";
    cout << "\t\t-----------------\n";
    cout << "\t\t      |     |     \n";
    cout << "\t\t   "<<BoardArr[1][0]<<"  |  "<<BoardArr[1][1]<<"  |  "<<BoardArr[1][2]<<"\n";
    cout << "\t\t-----------------\n";
    cout << "\t\t      |     |     \n";
    cout << "\t\t   "<<BoardArr[2][0]<<"  |  "<<BoardArr[2][1]<<"  |  "<<BoardArr[2][2]<<"\n";
}

void Game::Player_Turn()
{
    if(turn == 'X')
    cout << "Player 1 [X] Turn : ";
    if(turn == 'O')
    cout << "Player 2 [O] Turn : ";

    cin >> choice;
    switch(choice)
    {
        case 1: row = 0;column = 0; break;
        case 2: row = 0;column = 1; break;
        case 3: row = 0;column = 2; break;
        case 4: row = 1;column = 0; break;
        case 5: row = 1;column = 1; break;
        case 6: row = 1;column = 2; break;
        case 7: row = 2;column = 0; break;
        case 8: row = 2;column = 1; break;
        case 9: row = 2;column = 2; break;

        default:
            cout <<" ErRoR" <<endl;
            break;
    }

        if(turn == 'X' && BoardArr[row][column]!= 'X' && BoardArr[row][column]!= 'O')
    {
        BoardArr[row][column] = 'X';
        turn = 'O';
    }
    else if(turn == 'O' && BoardArr[row][column]!= 'X' && BoardArr[row][column]!= 'O')
    {
        BoardArr[row][column] = 'O';
        turn = 'X';
    }
    else
    {
        cout << "Box Occupied,Try Again\n";
        Player_Turn();
    }
    DisplayBoard();
}

bool Game::GameOverALL()
{
    //check for horizontal or vertical win
    for(int i = 0;i < 3 ;i++)
    if( (BoardArr[i][0] == BoardArr[i][1] && BoardArr[i][0] == BoardArr[i][2]) ||
        (BoardArr[0][i] == BoardArr[1][i] && BoardArr[0][i] == BoardArr[2][i])   )
    {
        return false;
    }

    //check for diagonal win

    if(BoardArr[0][0] == BoardArr[1][1] && BoardArr[0][0] == BoardArr[2][2])
    {
        return false;
    }

    if(BoardArr[0][2] == BoardArr[1][1] && BoardArr[0][2] == BoardArr[2][0])
    {
        return false;
    }

    //check if there's empty boxes
    for(int i = 0;i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(BoardArr[i][j] != 'X' && BoardArr[i][j] != 'O')
            {
                return true;
            }

    //when the game draws
    draw = true;
    return false;
}


void Game::Win()
{
    if(turn == 'X' && draw == false)
    {
        cout << "Player 2 [O] Wins!\n";
        Current_Score = Score - 10;
        cout << Current_Score << " Points\n";
    }
    else if(turn == 'O' && draw == false)
    {
        cout << "Player 1 [X] Wins!\n";
        Current_Score = Score + 10;
        cout << Current_Score << " Points\n";
    }
    else
        cout <<"\n\t\tDraw\n";
}

int Game::Menu()
{
    cout << "\t\t T I C T A C T O E MENU" << endl;
    cout << "\t>>>>>>SELECT<<<<<<    \n";
    cout << "<1> Play Multi-player : \n";
    cout << "<2> Play vs AI        : \n";
    cout << "<3> Exit              : \n";

    cin >> Menu_Option;
    if(Menu_Option == 1)
        return 1;
    else if(Menu_Option == 2)
        return 2;
    else if(Menu_Option == 3)
        return 3;
    else
        cout << "ErRoR\n";
}

/**< UNUSED FUNCTIONS */
/*
        bool Game::GameOverHV()
        {
            //check for horizontal or vertical win
            for(int i = 0;i < 3 ;i++)
            if(BoardArr[i][0] == BoardArr[i][1] && BoardArr[i][0] == BoardArr[i][2] ||  BoardArr[0][i] == BoardArr[1][i] && BoardArr[0][i] == BoardArr[2][i] )
            {
                return false;
            }

        }

        bool Game::GameOverDiag()
        {
            //check for diagonal win

            if(BoardArr[0][0] == BoardArr[1][1] && BoardArr[0][0] == BoardArr[2][2] && BoardArr[0][2] == BoardArr[1][1] || BoardArr[0][2] == BoardArr[2][0])
            {
                return false;
            }
        }

        bool Game::CheckEmptyBoxes()
        {
            //check if there's empty boxes
            for(int i = 0;i < 3; i++)
                for(int j = 0; j < 3; j++)
                    if(BoardArr[i][j] != 'X' && BoardArr[i][j] != 'O')
                    {
                        return true;
                    }
        }

        bool Game::GameOverDraw()
        {
            //when the game draws
            draw = true;
            return false;
        }
*/
