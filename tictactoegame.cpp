#include <iostream>
#include <time.h>

using namespace std;

void displayBoard(char* game)
{
    cout << "                 Tic tac toe      " << endl << endl << endl;
    cout << game[0] << " | " << game[1] << " | " << game[2] << endl;
    cout << "---------" << endl;
    cout << game[3] << " | " << game[4] << " | " << game[5] << endl;
    cout << "---------" << endl;
    cout << game[6] << " | " << game[7] << " | " << game[8] << endl << endl;
}

int getPlayFromUser()
{
    cout << "Enter number: " << endl;
    int a;
    cin >> a;
    return a;
}

bool isValidPlay(char* game, int& marknum)
{
    bool a = true;
    if(game[marknum - 1] == 'X' || game[marknum - 1] == 'O' || marknum > 9 || marknum < 1)
    {
        a = false;
    }
    return a;
}

void applyPlay(char* game, int& counter, int& marknum, char& mark)
{
    mark = counter % 2 == 0 ? 'O' : 'X';
    game[marknum - 1] = mark;
}

bool didSomebodyWin(char* game, char& mark)
{
    bool a = false;
    if( (game[0] == game[3] && game[3] == game[6]) ||
        (game[1] == game[4] && game[4] == game[7]) ||
        (game[2] == game[5] && game[5] == game[8]) ||
        (game[0] == game[1] && game[1] == game[2]) ||
        (game[3] == game[4] && game[4] == game[5]) ||
        (game[6] == game[7] && game[7] == game[8]) ||
        (game[8] == game[4] && game[4] == game[0]) ||
        (game[6] == game[4] && game[4] == game[2])  )
    {
        if(mark == 'X')
        {
            cout << "X win. " << endl;
            a = true;
        }
        else
        {
            cout << "O win. " << endl;
            a = true;
        }
    }
    else if(game[0] != '1' &&
            game[1] != '2' &&
            game[2] != '3' &&
            game[3] != '4' &&
            game[4] != '5' &&
            game[5] != '6' &&
            game[6] != '7' &&
            game[7] != '8' &&
            game[8] != '9')
    {
        cout << "Draw. " << endl;
        a = true;
    }

    return a;
}

int generate_random_play(char* game)
{
    int a;

    if((game[1] == game[2] ||
        game[3] == game[6] ||
        game[4] == game[8] ) && game[0] == '1')
    {
        a = 0;
    }
    else if((game[0] == game[1] ||
                game[5] == game[8] ||
                game[4] == game[6]) && game[2] == '3')
    {
        a = 2;
    }
    else if((game[0] == game[4] ||
                game[2] == game[5] ||
                game[6] == game[7]) && game[8] == '9')
    {
        a = 8;
    }
    else if((game[2] == game[4] ||
                game[0] == game[3] ||
                game[7] == game[8]) && game[6] == '7')
    {
        a = 6;
    }
    else if((game[0] == game[2] ||
                game[4] == game[7]) && game[1] == '2')
    {
        a = 1;
    }
    else if((game[2] == game[8] ||
                game[3] == game[4]) && game[5] == '6')
    {
        a = 5;
    }
    else if((game[1] == game[4] ||
                game[6] == game[8]) && game[7] == '8')
    {
        a = 7;
    }
    else if((game[0] == game[6] ||
                game[4] == game[5] ) && game[3] == '4' )
    {
        a = 3;
    }
    else if(game[4] == '5' )
    {
        a = 4;
    }
    else if(game[1] == '2' )
    {
        a = 1;
    }
    else if(game[5] == '6')
    {
        a = 5;
    }
    else if(game[7] == '8')
    {
        a = 7;
    }
    else if(game[3] == '4')
    {
        a = 3;
    }
    else if(game[1] == 'O' && game[0] == '1')
    {
        a = 0;
    }
    else if(game[1] == 'O' && game[2] == '3')
    {
        a = 2;
    }
    else if(game[1] == 'O' && game[4] == '5')
    {
        a = 4;
    }
    else if(game[5] == 'O' && game[2] == '3')
    {
        a = 2;
    }
    else if(game[5] == 'O' && game[8] == '9')
    {
        a = 8;
    }
    else if(game[5] == 'O' && game[4] == '5')
    {
        a = 4;
    }
    else if(game[7] == 'O' && game[6] == '7')
    {
        a = 7;
    }
    else if(game[7] == 'O' && game[4] == '5')
    {
        a = 4;
    }
    else if(game[7] == 'O' && game[8] == '9')
    {
        a = 8;
    }
    else if(game[3] == 'O' && game[1] == '2')
    {
        a = 2;
    }
    else if(game[3] == 'O' && game[6] == '7')
    {
        a = 6;
    }
    else if(game[3] == 'O' && game[4] == '5')
    {
        a = 4;
    }
    return a;
}

int main()
{
    srand(time(NULL));


    char game[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char mark;
    int  marknum, counter = 0;

    displayBoard(game);
    
    while(1)
    {
        marknum = getPlayFromUser();
        while(!isValidPlay(game, marknum))
        {
            cout << "Wrong number. Enter correct number : " << endl;
            marknum = getPlayFromUser();
        }
        counter++;
        
        applyPlay(game, counter, marknum, mark);
        displayBoard(game);
        if(didSomebodyWin(game, mark))
        {
            break;
        }

        marknum = generate_random_play(game);
        while(!isValidPlay(game, marknum))
        {
            marknum = rand() % 10;
        }
        counter++;

        applyPlay(game, counter, marknum, mark);
        displayBoard(game);
        if(didSomebodyWin(game, mark))
        {
            break;
        }
        
    }
    return 0;
}