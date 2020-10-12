#include <iostream>
#include <string>
using namespace std;

void drawGrid();
void getMove(int player);
bool checkValid(int pos);
int checkWin();

void ClearScreen()
{
cout << string( 100, '\n' );
}

char square[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

int main()
{
    int hasWon = 0;
    int turnCounter = 0;
    drawGrid();
    while (hasWon == 0) 
    {
        int currentPlayer = 0;
        if ((turnCounter % 2) != 0)
        {
            currentPlayer = 1;
        }
        getMove(currentPlayer);
        drawGrid();
        hasWon = checkWin();
        if (hasWon == 1)
        {
            if (currentPlayer == 0)
            {
                cout << "Congratulations Player One! You have won in " << turnCounter+1 << " moves!" << endl;
            }
            if (currentPlayer == 1)
            {
                cout << "Congratulations Player Two! You have won in " << turnCounter+1 << " moves!" << endl;
            }
            break;
        }
        turnCounter++;

    }
    return 0;
}

void getMove(int player)
{
    string playerName = "";
    int pos;
    char playerPiece;
    if (player == 0) {
        playerName = "Player One";
        playerPiece = 'X';
    } else if (player == 1) {
        playerName = "Player Two";
        playerPiece = 'O';
    }
    do {
        cout << playerName << " enter your move position.";
        cin >> pos;
    } while (!checkValid(pos));
    square[pos-1] = playerPiece;
    return;
}

void drawGrid()
{
    ClearScreen();
    cout << "     |     |" << endl;
    cout << "  " << square[0] << "  |  " << square[1] << "  |  " << square[2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |" << endl;
    cout << "  " << square[3] << "  |  " << square[4] << "  |  " << square[5] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |" << endl;
    cout << "  " << square[6] << "  |  " << square[7] << "  |  " << square[8] << endl;
    cout << "     |     |" << endl;
    return;
}

bool checkValid(int pos)
{
    if (square[pos-1] == 'X' || square[pos-1] == 'O')
    {
        cout << "Invalid move!" << endl;
        return false;
    } else {
        return true;
    }
}

int checkWin()
{
    // TODO: only check the current player's moves to see if a win occurred.
    // Check for horizontal X wins
    if (((square[0] == 'X') && (square[1] == 'X') && (square[2] == 'X')) || ((square[3] == 'X') && (square[4] == 'X') && (square[5] == 'X')) || ((square[6] == 'X') && (square[7] == 'X') && (square[8] == 'X')))
    {
        return 1;
    }
    // Check for horizontal O wins
    if (((square[0] == 'O') && (square[1] == 'O') && (square[2] == 'O')) || ((square[3] == 'O') && (square[4] == 'O') && (square[5] == 'O')) || ((square[6] == 'O') && (square[7] == 'O') && (square[8] == 'O')))
    {
        return 1;
    }
    // Check for vertical X wins
    if (((square[0] == 'X') && (square[3] == 'X') && (square[6] == 'X')) || ((square[1] == 'X') && (square [4] == 'X') && (square[7] == 'X')) || ((square[2] == 'X') && (square[5] == 'X') && (square[8] == 'X')))
    {
        return 1;
    }
    // Check for vertical O wins
    if (((square[0] == 'O') && (square[3] == 'O') && (square[6] == 'O')) || ((square[1] == 'O') && (square [4] == 'O') && (square[7] == 'O')) || ((square[2] == 'O') && (square[5] == 'O') && (square[8] == 'O')))
    {
        return 1;
    }
    // Check for diagonal X wins
    if (((square[0] == 'X') && (square[4] == 'X') && (square[8] == 'X')) || ((square[2] == 'X') && (square[4] == 'X') && (square[6] == 'X')))
    {
        return 1;
    }
    // Check for diagonal O wins
    if (((square[0] == 'O') && (square[4] == 'O') && (square[8] == 'O')) || ((square[2] == 'O') && (square[4] == 'O') && (square[6] == 'O')))
    {
        return 1;
    }
    return 0;
}
