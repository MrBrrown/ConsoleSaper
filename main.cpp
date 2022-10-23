#include <iostream>
#include <ctime>

using namespace std;

const int FIELD_SIZE_X = 8;
const int FIELD_SIZE_Y = 8;

void OpenField(char field[][FIELD_SIZE_X], int yIndex, int xIndex)
{
    int bombCount = 0;
    if (field[yIndex][xIndex] != '!' && (yIndex >= 0 && yIndex < FIELD_SIZE_Y) && (xIndex >= 0 && xIndex < FIELD_SIZE_X))
    {
        if (yIndex == 0 && xIndex == 0)
        {
            (field[yIndex + 1][xIndex + 1] == '!') ? bombCount++ : 0;
            (field[yIndex][xIndex + 1] == '!') ? bombCount++ : 0;
            (field[yIndex + 1][xIndex] == '!') ? bombCount++ : 0;
            field[yIndex][xIndex] = char(bombCount + 48);
            if (bombCount == 0)
            {
                OpenField(field, yIndex, xIndex + 1);
                OpenField(field, yIndex + 1, xIndex + 1);
                OpenField(field, yIndex + 1, xIndex);
            }
        }
        else if (yIndex == 0 && xIndex < FIELD_SIZE_X - 1)
        {
            (field[yIndex][xIndex + 1] == '!') ? bombCount++ : 0;
            (field[yIndex + 1][xIndex + 1] == '!') ? bombCount++ : 0;
            (field[yIndex + 1][xIndex] == '!') ? bombCount++ : 0;
            (field[yIndex + 1][xIndex - 1] == '!') ? bombCount++ : 0;
            (field[yIndex][xIndex - 1] == '!') ? bombCount++ : 0;
            field[yIndex][xIndex] = char(bombCount + 48);
            if (bombCount == 0)
            {
                if (field[yIndex + 1][xIndex] != '0')
                    OpenField(field, yIndex + 1, xIndex);
                if (field[yIndex][xIndex + 1] != '0')
                    OpenField(field, yIndex, xIndex + 1);
                if (field[yIndex][xIndex - 1] != '0')
                    OpenField(field, yIndex, xIndex - 1);
            }
        }
        else if (yIndex == 0 && xIndex == FIELD_SIZE_X - 1)
        {
            (field[yIndex + 1][xIndex - 1] == '!') ? bombCount++ : 0;
            (field[yIndex][xIndex - 1] == '!') ? bombCount++ : 0;
            (field[yIndex + 1][xIndex] == '!') ? bombCount++ : 0;
            field[yIndex][xIndex] = char(bombCount + 48);
            if (bombCount == 0)
            {
                OpenField(field, yIndex, xIndex - 1);
                OpenField(field, yIndex + 1, xIndex - 1);
                OpenField(field, yIndex + 1, xIndex);
            }
        }
        else if (yIndex < FIELD_SIZE_Y - 1 && xIndex == FIELD_SIZE_X - 1)
        {
            (field[yIndex - 1][xIndex] == '!') ? bombCount++ : 0;
            (field[yIndex - 1][xIndex - 1] == '!') ? bombCount++ : 0;
            (field[yIndex][xIndex - 1] == '!') ? bombCount++ : 0;
            (field[yIndex + 1][xIndex - 1] == '!') ? bombCount++ : 0;
            (field[yIndex + 1][xIndex] == '!') ? bombCount++ : 0;
            field[yIndex][xIndex] = char(bombCount + 48);
            if (bombCount == 0)
            {
                if (field[yIndex - 1][xIndex] != '0')
                    OpenField(field, yIndex - 1, xIndex);
                if (field[yIndex + 1][xIndex] != '0')
                    OpenField(field, yIndex + 1, xIndex);
                if (field[yIndex][xIndex - 1] != '0')
                    OpenField(field, yIndex, xIndex - 1);
            }
        }
        else if (yIndex == FIELD_SIZE_Y - 1 && xIndex == FIELD_SIZE_X - 1)
        {
            (field[yIndex - 1][xIndex - 1] == '!') ? bombCount++ : 0;
            (field[yIndex][xIndex - 1] == '!') ? bombCount++ : 0;
            (field[yIndex - 1][xIndex] == '!') ? bombCount++ : 0;
            field[yIndex][xIndex] = char(bombCount + 48);
            if (bombCount == 0)
            {
                OpenField(field, yIndex, xIndex - 1);
                OpenField(field, yIndex - 1, xIndex - 1);
                OpenField(field, yIndex - 1, xIndex);
            }
        }
        else if (yIndex == FIELD_SIZE_Y - 1 && xIndex < FIELD_SIZE_X - 1)
        {
            (field[yIndex + 1][xIndex] == '!') ? bombCount++ : 0;
            (field[yIndex - 1][xIndex + 1] == '!') ? bombCount++ : 0;
            (field[yIndex][xIndex + 1] == '!') ? bombCount++ : 0;
            (field[yIndex][xIndex - 1] == '!') ? bombCount++ : 0;
            (field[yIndex - 1][xIndex - 1] == '!') ? bombCount++ : 0;
            field[yIndex][xIndex] = char(bombCount + 48);
            if (bombCount == 0)
            {
                if (field[yIndex][xIndex + 1] != '0')
                    OpenField(field, yIndex, xIndex + 1);
                if (field[yIndex][xIndex - 1] != '0')
                    OpenField(field, yIndex, xIndex - 1);
                if (field[yIndex - 1][xIndex] != '0')
                    OpenField(field, yIndex - 1, xIndex);
            }
        }
        else if (yIndex == FIELD_SIZE_Y - 1 && xIndex == 0)
        {
            (field[yIndex - 1][xIndex + 1] == '!') ? bombCount++ : 0;
            (field[yIndex][xIndex + 1] == '!') ? bombCount++ : 0;
            (field[yIndex - 1][xIndex] == '!') ? bombCount++ : 0;
            field[yIndex][xIndex] = char(bombCount + 48);
            if (bombCount == 0)
            {
                OpenField(field, yIndex, xIndex + 1);
                OpenField(field, yIndex - 1, xIndex + 1);
                OpenField(field, yIndex - 1, xIndex);
            }
        }
        else if (yIndex < FIELD_SIZE_Y - 1 && xIndex == 0)
        {
            (field[yIndex + 1][xIndex] == '!') ? bombCount++ : 0;
            (field[yIndex + 1][xIndex + 1] == '!') ? bombCount++ : 0;
            (field[yIndex][xIndex + 1] == '!') ? bombCount++ : 0;
            (field[yIndex - 1][xIndex + 1] == '!') ? bombCount++ : 0;
            (field[yIndex - 1][xIndex] == '!') ? bombCount++ : 0;
            field[yIndex][xIndex] = char(bombCount + 48);
            if (bombCount == 0)
            {
                if (field[yIndex - 1][xIndex] != '0')
                    OpenField(field, yIndex - 1, xIndex);
                if (field[yIndex + 1][xIndex] != '0')
                    OpenField(field, yIndex + 1, xIndex);
                if (field[yIndex][xIndex + 1] != '0')
                    OpenField(field, yIndex, xIndex + 1);
            }
        }
        else
        {
            (field[yIndex - 1][xIndex] == '!') ? bombCount++ : 0;
            (field[yIndex - 1][xIndex + 1] == '!') ? bombCount++ : 0;

            (field[yIndex][xIndex + 1] == '!') ? bombCount++ : 0;
            (field[yIndex + 1][xIndex + 1] == '!') ? bombCount++ : 0;

            (field[yIndex + 1][xIndex] == '!') ? bombCount++ : 0;
            (field[yIndex + 1][xIndex - 1] == '!') ? bombCount++ : 0;

            (field[yIndex][xIndex - 1] == '!') ? bombCount++ : 0;
            (field[yIndex - 1][xIndex - 1] == '!') ? bombCount++ : 0;
            field[yIndex][xIndex] = char(bombCount + 48);
            if (bombCount == 0)
            {
                if (field[yIndex - 1][xIndex] != '0') //ВВЕРХ
                    OpenField(field, yIndex - 1, xIndex);
                if (field[yIndex + 1][xIndex] != '0') //ВНИЗ
                    OpenField(field, yIndex + 1, xIndex);

                if (field[yIndex][xIndex + 1] != '0') //ВПРАВО
                    OpenField(field, yIndex, xIndex + 1);
                if (field[yIndex][xIndex - 1] != '0') //ВЛЕВО
                    OpenField(field, yIndex, xIndex - 1);
            }
        }
    }
}

void BombGenirator(char field[][FIELD_SIZE_X])
{
    char bomb = '!';
    int bombCounter = 10;
    srand(time(NULL));
    while (bombCounter > 0)
    {
        for (int i = 0; i < FIELD_SIZE_Y; i++)
        {
            for (int j = 0; j < FIELD_SIZE_X; j++)
            {
                bool isBomb = ((rand() % 10) == 1);
                if (bombCounter == 0)
                    break;
                if (isBomb && field[i][j] != bomb)
                {
                    field[i][j] = bomb;
                    bombCounter--;
                }
            }
            if (bombCounter == 0)
                break;
        }
    }
}

void SetFieldEmpty(char field[][FIELD_SIZE_X])
{
    char emptySquare = '&';
    for (int i = 0; i < FIELD_SIZE_Y; i++)
        for (int j = 0; j < FIELD_SIZE_X; j++)
            field[i][j] = emptySquare;
}

void PrintGameField(char field[][FIELD_SIZE_X])
{
    cout << ' ';
    for (int j = 0; j < FIELD_SIZE_X + 1; j++)
        cout << j << "__";
    cout << endl;
    for (int i = 0; i < FIELD_SIZE_Y; i++)
    {
        (i < 9) ? cout << ' ' << i + 1 << "| " : cout << i + 1 << "| ";

        for (int j = 0; j < FIELD_SIZE_X; j++)
        {
            if (field[i][j] != '!' && field[i][j] != '&')
                cout << field[i][j] << "  ";
            else
                cout << '@' << "  ";
        }
        cout << endl;
    }
}

int main()
{
    int xIndex, yIndex;
    char field[FIELD_SIZE_Y][FIELD_SIZE_X];
    SetFieldEmpty(field);
    BombGenirator(field);
    PrintGameField(field);
    while (true)
    {
        cout << "Введите кооридинаты точки: " << endl;
        cin >> yIndex >> xIndex;
        if (field[yIndex - 1][xIndex - 1] == '!')
        {
            cout << "Братан, Это Бомба" << endl;
            for (int i = 0; i < FIELD_SIZE_Y; i++)
            {
                for (int j = 0; j < FIELD_SIZE_X; j++)
                    cout << field[i][j] << ' ';
                cout << endl;
            }
            return 0;
        }
        bool isWin = true;
        for (int i = 0; i < FIELD_SIZE_Y; i++)
            for (int j = 0; j < FIELD_SIZE_X; j++)
                (field[i][j] == '&') ? isWin = false : 0;
        if (isWin)
        {
            cout << "ЭТО ВРЕМЯ БОЛЬШОГО МОЗГА. ТЫ ПОБЕДИЛ!!!" << endl;
            return 0;
        }
        OpenField(field, yIndex - 1, xIndex - 1);
        system("clear");
        PrintGameField(field);
    }
}
