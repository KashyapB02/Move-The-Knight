#include <bits/stdc++.h>
using namespace std;

void GeneralRules();
void Toss();
void ChessBoardDisplay();
void Start();
void PlayGame();

struct Moves
{
    int row;
    int column;
} M[8];

string TossWinner, P1, P2, Active;
int lastRow, lastColumn, mistakes = 0;

int Board[8][8] = {0};
int End = 0;

int main()
{
    system("cls");
    
    cout << "!!..... KNIGHT - RIDER .....!!" << endl;
    cout << endl;

    GeneralRules();
    cout << endl;

    system("cls");

    Toss();
    cout << endl;

    system("cls");

    ChessBoardDisplay();
    Start();
    if (mistakes == 3)
    {
        return 0;
    }
    cout << endl;

    while (!(End))
    {
        PlayGame();

        if (Active == P1)
        {
            Active = P2;
        }
        else
        {
            Active = P1;
        }
    }
    cout << endl;

    return 0;
}

void GeneralRules()
{
    cout << "General Playing Rules :";
    cout << endl;

    cout << "\n1.  This game is played on chess board, but only with KNIGHT.";
    cout << "\n2.  This game is played between two players only.";
    cout << "\n3.  Toss will be done before starting of the game by the computer.";
    cout << "\n4.  Player who wins the toss will be 'PLAYER 1' and will start the game.";
    cout << "\n5.  PLAYER 1 will have to select a valid position on chess board.";
    cout << "\n6.  Knight will be placed on the selected position by PLAYER 1.";
    cout << "\n7.  Starting from PLAYER 1, both player will have their chance in alternating sequence.";
    cout << "\n8.  Player who currently holds the chance is called 'ACTIVE PLAYER'.";
    cout << "\n9.  The current position of KNIGHT will be indicated by 'XX'.";
    cout << "\n10. All invalid positions will be indicated by '--'.";
    cout << "\n11. All valid positions will be indicated by their co-ordinate in the formate - 'ROW , COLUMN'";
    cout << "\n12. Black co-ordinates will be shown inside '[ ]' (Big Bracket).";
    cout << "\n13. White co-ordinates will be shown inside '( )' (Small Bracket).";
    cout << "\n14. In each chance, ACTIVE PLAYER move the KNIGHT according to the rules of chess to a valid positon.";
    cout << "\n15. Once a place is visited by the KNIGHT, it will be considered as INVALID POSITION.";
    cout << "\n16. The KNIGHT can only be moved to a valid postion by ACTIVE PLAYER.";
    cout << "\n17. For each move, ACTIVE PLAYER will be given maximum '3' chances to select a valid position.";
    cout << "\n18. If a player does not select a valid postion in '3' chances, the game will be over.";
    cout << "\n19. As the game will proceed, the valid positions for KNIGHT will start becoming invalid one by one.";
    cout << "\n20. When a player did not have any valid position to move the KNIGHT, the game will be over.";
    cout << "\n21. And finally, the player who did not have any position to move the KNIGHT will loose the game.\n";

    cout << endl;
    system("pause");
    return;
}

void Toss()
{
    char Name1[100] = {'\0'};
    char Name2[100] = {'\0'};

    cout << "Enter name of player 1: ";
    cin.getline(Name1, 100);

    cout << "Enter name of player 2: ";
    cin.getline(Name2, 100);

    cout << "\nToss is in progress... ";

    system("pause");

    srand(time(0));

    if ((rand() % 2))
    {
        TossWinner = Name1;
        Active = Name1;
        P1 = Name1;
        P2 = Name2;
    }
    else
    {
        TossWinner = Name2;
        Active = Name2;
        P1 = Name2;
        P2 = Name1;
    }

    cout << "\nToss won by " << TossWinner << endl;
    cout << "\nPLAYER 1: " << P1 << endl;
    cout << "PLAYER 2: " << P2 << endl;

    cout << endl;
    system("pause");
    return;
}

void ChessBoardDisplay()
{
    cout << "Showing Chess Board:" << endl;

    cout << " ";

    for (int i = 1; i < 104; i++)
    {
        cout << "_";
    }

    cout << endl;
    int r = 0;

    for (int i = 0; i <= 23; i++)
    {
        if (i % 3 == 1)
        {
            r = r + 1;
        }

        for (int j = 0; j <= 8; j++)
        {
            if ((i % 3 == 0))
            {
                cout << "|            ";
            }
            else if ((i % 3 == 2) && j != 8)
            {
                cout << "|____________";
            }
            else if (j == 8)
            {
                cout << "|";
            }
            else if (!((i + j) % 2))
            {
                cout << "|  [" << (r) << " , " << (j + 1) << "]   ";
            }
            else
            {
                cout << "|  (" << (r) << " , " << (j + 1) << ")   ";
            }
        }

        cout << endl;
    }

    return;
}

void Start()
{
Entry:
    if (mistakes == 3)
    {
        cout << "\n\nAll valid attempts exhausted..." << endl;
        cout << "\n"
             << Active << " lost the game... Better luck next time...";

        if (Active == P1)
        {
            cout << "\nCongratulations " << P2 << "... You won the game..." << endl;
        }
        else
        {
            cout << "\nCongratulations " << P1 << "... You won the game..." << endl;
        }

        cout << endl
             << "\n!! GAME OVER !!" << endl
             << endl;

        system("pause");
        return;
    }
    else if (mistakes)
    {
        ChessBoardDisplay();
    }

    cout << "\nACTIVE PLAYER: " << Active << endl;

    cout << "\nSelect a valid position on Chess Board to start..." << endl;

    cout << "\nRow (1 - 8)   : ";
    cin >> lastRow;
    cout << "Column (1 - 8): ";
    cin >> lastColumn;

    system("cls");

    if ((lastRow >= 1 && lastRow <= 8) && (lastColumn >= 1 && lastColumn <= 8))
    {
        cout << "Showing Chess Board:" << endl;

        cout << " ";

        for (int i = 1; i < 104; i++)
        {
            cout << "_";
        }

        cout << endl;
        int r = -1;

        for (int i = 0; i <= 23; i++)
        {
            if (i % 3 == 1)
            {
                r = r + 1;
            }

            for (int j = 0; j <= 8; j++)
            {
                if ((i % 3 == 0))
                {
                    cout << "|            ";
                }
                else if ((i % 3 == 2) && j != 8)
                {
                    cout << "|____________";
                }
                else if (j == 8)
                {
                    cout << "|";
                }
                else if (!((i + j) % 2))
                {
                    if ((r == lastRow - 1) && (j == lastColumn - 1))
                    {
                        cout << "|     XX     ";
                    }
                    else
                    {
                        cout << "|  [" << (r + 1) << " , " << (j + 1) << "]   ";
                    }
                }
                else
                {
                    if ((r == lastRow - 1) && (j == lastColumn - 1))
                    {
                        cout << "|     XX     ";
                    }
                    else
                    {
                        cout << "|  (" << (r + 1) << " , " << (j + 1) << ")   ";
                    }
                }
            }

            cout << endl;
        }

        Board[lastRow - 1][lastColumn - 1] = 1;
    }
    else
    {
        mistakes++;

        if ((3 - mistakes))
        {
            cout << "Invalid position selected... Select again...";
            cout << "\nRemaining attempts: " << (3 - mistakes) << endl;
        }

        goto Entry;
    }

    return;
}

void PlayGame()
{
    mistakes = 0;

Move:
    if (mistakes == 3)
    {
        cout << "\n\nInvalid Move... All valid attempts exhausted..." << endl;
        cout << "\n"
             << Active << " lost the game... Better luck next time...";

        if (Active == P1)
        {
            cout << "\nCongratulations " << P2 << "... You won the game..." << endl;
        }
        else
        {
            cout << "\nCongratulations " << P1 << "... You won the game..." << endl;
        }

        cout << endl
             << "\n!! GAME OVER !!" << endl
             << endl;

        End = 1;

        system("pause");
        return;
    }
    else if (mistakes)
    {
        cout << "Showing Chess Board:" << endl;

        cout << " ";

        for (int i = 1; i < 104; i++)
        {
            cout << "_";
        }

        cout << endl;
        int r = -1;

        for (int i = 0; i <= 23; i++)
        {
            if (i % 3 == 1)
            {
                r = r + 1;
            }

            for (int j = 0; j <= 8; j++)
            {
                if ((i % 3 == 0))
                {
                    cout << "|            ";
                }
                else if ((i % 3 == 2) && j != 8)
                {
                    cout << "|____________";
                }
                else if (j == 8)
                {
                    cout << "|";
                }
                else if (!((i + j) % 2))
                {
                    if ((r == lastRow - 1) && (j == lastColumn - 1))
                    {
                        cout << "|     XX     ";
                    }
                    else if (Board[r][j])
                    {
                        cout << "|     --     ";
                    }
                    else
                    {
                        cout << "|  [" << (r + 1) << " , " << (j + 1) << "]   ";
                    }
                }
                else
                {
                    if ((r == lastRow - 1) && (j == lastColumn - 1))
                    {
                        cout << "|     XX     ";
                    }
                    else if (Board[r][j])
                    {
                        cout << "|     --     ";
                    }
                    else
                    {
                        cout << "|  (" << (r + 1) << " , " << (j + 1) << ")   ";
                    }
                }
            }

            cout << endl;
        }
    }

    cout << "\nACTIVE PLAYER: " << Active;
    cout << "\nPlease make a move..." << endl;

    cout << "\nAvailable VALID Positions:" << endl;

    int positions = 0;

    for (int i = -2; i <= 2; i++)
    {
        if (i)
        {
            int TempRow = lastRow + i;
            if ((i == 2) || i == -2)
            {
                for (int j = -1; j <= 1; j += 2)
                {
                    int TempColumn = lastColumn + j;
                    if ((TempRow >= 1 && TempRow <= 8) && (TempColumn >= 1 && TempColumn <= 8))
                    {
                        if (!(Board[TempRow - 1][TempColumn - 1]))
                        {
                            M[positions].row = TempRow;
                            M[positions].column = TempColumn;

                            positions++;

                            if (!((TempRow + TempColumn) % 2))
                            {
                                cout << "\n"
                                     << positions << ". ";
                                cout << "(" << (TempRow) << " , " << (TempColumn) << ")   ";
                            }
                            else
                            {
                                cout << "\n"
                                     << positions << ". ";
                                cout << "[" << (TempRow) << " , " << (TempColumn) << "]   ";
                            }
                        }
                    }
                }
            }
            else
            {
                for (int j = -2; j <= 2; j += 4)
                {
                    int TempColumn = lastColumn + j;
                    if ((TempRow >= 1 && TempRow <= 8) && (TempColumn >= 1 && TempColumn <= 8))
                    {
                        if (!(Board[TempRow - 1][TempColumn - 1]))
                        {
                            M[positions].row = TempRow;
                            M[positions].column = TempColumn;

                            positions++;

                            if (!((TempRow + TempColumn) % 2))
                            {
                                cout << "\n"
                                     << positions << ". ";
                                cout << "(" << (TempRow) << " , " << (TempColumn) << ")   ";
                            }
                            else
                            {
                                cout << "\n"
                                     << positions << ". ";
                                cout << "[" << (TempRow) << " , " << (TempColumn) << "]   ";
                            }
                        }
                    }
                }
            }
        }
    }

    cout << endl;

    if (!(positions))
    {
        cout << "Total VALID Positions Available: " << positions << endl;
        cout << "\nAll valid positions on the board is exhausted... " << endl;
        cout << "\n"
             << Active << " lost the game... Better luck next time...";

        cout << endl;

        if (Active == P1)
        {
            cout << "\nCongratulations " << P2 << "... You won the game..." << endl;
        }
        else
        {
            cout << "\nCongratulations " << P1 << "... You won the game..." << endl;
        }

        cout << endl
             << "\n!! GAME OVER !!" << endl
             << endl;

        End = 1;

        system("pause");
        return;
    }

    cout << endl;
    cout << "Total VALID Positions Available: " << positions << endl;

    int move;

    cout << "\nEnter a VALID move (1 - " << positions << " ): ";
    cin >> move;

    if ((move < 1) || (move > positions))
    {
        mistakes++;
        if ((3 - mistakes))
        {
            system("cls");
            cout << "Invalid Move... Please Enter a VALID move..." << endl;
            cout << "Remaining attempts: " << (3 - mistakes) << endl
                 << endl;
        }

        goto Move;
    }

    system("cls");

    cout << "Showing Chess Board:" << endl;

    cout << " ";

    for (int i = 1; i < 104; i++)
    {
        cout << "_";
    }

    cout << endl;
    int r = -1;

    for (int i = 0; i <= 23; i++)
    {
        if (i % 3 == 1)
        {
            r = r + 1;
        }

        for (int j = 0; j <= 8; j++)
        {
            if ((i % 3 == 0))
            {
                cout << "|            ";
            }
            else if ((i % 3 == 2) && j != 8)
            {
                cout << "|____________";
            }
            else if (j == 8)
            {
                cout << "|";
            }
            else if (!((i + j) % 2))
            {
                if ((r == M[move - 1].row - 1) && (j == M[move - 1].column - 1))
                {
                    cout << "|     XX     ";
                }
                else if (Board[r][j])
                {
                    cout << "|     --     ";
                }
                else
                {
                    cout << "|  [" << (r + 1) << " , " << (j + 1) << "]   ";
                }
            }
            else
            {
                if ((r == M[move - 1].row - 1) && (j == M[move - 1].column - 1))
                {
                    cout << "|     XX     ";
                }
                else if (Board[r][j])
                {
                    cout << "|     --     ";
                }
                else
                {
                    cout << "|  (" << (r + 1) << " , " << (j + 1) << ")   ";
                }
            }
        }

        cout << endl;
    }

    Board[M[move - 1].row - 1][M[move - 1].column - 1] = 1;
    lastRow = M[move - 1].row;
    lastColumn = M[move - 1].column;

    return;
}