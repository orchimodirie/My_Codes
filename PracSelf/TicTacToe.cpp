#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void BoardGame(const vector<vector<char>> &tiles)
{
    // OPTIONAL: Clears the terminal so the board stays in one place
    // Use "cls" for Windows, "clear" for Mac/Linux
    system("cls");

    cout << "\n\n"; // Add top margin
    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << tiles[0][0] << "  |  " << tiles[0][1] << "  |  " << tiles[0][2] << "  " << endl;
    cout << "\t\t_____|_____|_____" << endl;
    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << tiles[1][0] << "  |  " << tiles[1][1] << "  |  " << tiles[1][2] << "  " << endl;
    cout << "\t\t_____|_____|_____" << endl;
    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << tiles[2][0] << "  |  " << tiles[2][1] << "  |  " << tiles[2][2] << "  " << endl;
    cout << "\t\t     |     |     " << endl;
    cout << "\n\n"; // Add bottom margin
}
void tiles(vector<vector<char>> &tilesData, int coord, char &pamato)
{
    if (pamato == 'O')
        pamato = 'X';
    else
        pamato = 'O';

    int col = (coord - 1) % 3;
    int row = (coord - 1) / 3;

    tilesData[row][col] = pamato;
}

bool gameChecker(const vector<vector<char>> &tilesData, bool &gamewinner)
{

    // A == B == C --> A == B, B == C
    // the other equailty is to check for blank space cuz same black space means wins also
    if (tilesData[0][0] == tilesData[1][1] && tilesData[1][1] == tilesData[2][2] && tilesData[0][0] != ' ')
    {
        gamewinner = true;
        return true;
    }

    if (tilesData[0][2] == tilesData[1][1] && tilesData[1][1] == tilesData[2][0] && tilesData[0][2] != ' ')
    {
        gamewinner = true;
        return true;
    }

    for (int i = 0; i < 3; i++)
    {
        // row
        if (tilesData[i][0] == tilesData[i][1] && tilesData[i][1] == tilesData[i][2] && tilesData[i][0] != ' ')
        {
            gamewinner = true;
            return true;
        }

        if (tilesData[0][i] == tilesData[1][i] && tilesData[1][i] == tilesData[2][i] && tilesData[0][i] != ' ')
        {
            gamewinner = true;
            return true;
        }
    }

    return false;
}

void tileschecker(const vector<vector<char>> &tiles, int &coord)
{

    while (true)
    {

        int col = (coord - 1) % 3;
        int row = (coord - 1) / 3;

        if (tiles[row][col] == 'X' || tiles[row][col] == 'O')
        {
            cout << "Try different tiles: ";
            cin >> coord;
        }
        else
        {
            break;
        }
    }
}

int main()
{
    bool gameWinner = false;

    vector<vector<char>> tilesData{
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '},

    };
    char pamato = 'O';
    int coord;
    int loopcounter = 0;

    while (!(gameChecker(tilesData, gameWinner)) && loopcounter != 9)
    {
        system("cls");

        BoardGame(tilesData);
        cout << "Enter the coordinates: ";

        // constraint inputs
        cin >> coord;

        if (coord < 1 || coord > 9)
        {
            cout << "Invalid coordinate! Enter 1-9 "<<endl;
            system("pause");
            continue; // Restart the loop immediately
        }

        tileschecker(tilesData, coord);
        tiles(tilesData, coord, pamato);
        loopcounter++;
    }
    system("cls");
    BoardGame(tilesData);

    if (gameWinner == true)
    {
        cout << "The player " << pamato << " wins" << endl;
    }
    else
    {
        cout << "Out of moves";
    }

    return 0;
}