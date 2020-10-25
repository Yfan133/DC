#include<iostream>
using namespace std;
char* replaceSpace(char* s)
{
    int space = 0;
    int i = 0;
    while (s[i] != '\0')
        if (s[i++] == ' ')
            ++space;
    int j = i + 2 * space+1;
    /*char* arr = (char*)malloc(j);
    memcpy(arr, s, i + 1);
    free(s);
    s = arr;*/
    s=(char*)realloc(s,j);
    j--;
    while (i >= 0)
    {
        if (s[i] == ' ')
        {
            s[j--] = '0';
            s[j--] = '2';
            s[j--] = '%';
        }
        else
            s[j--] = s[i];
        --i;
    }
    return s;
}
bool search(char** board, int i, int j, char* word, int boardSize, int boardColSize, int pos)
{
    if (i < 0 || i >= boardSize || j < 0 || j >= boardColSize || board[i][j] != word[pos])
        return false;
    if (word[pos] == 0)
        return true;
    board[i][j] = '/';
    bool tmp = (search(board, i - 1, j, word, boardSize, boardColSize, pos + 1) || search(board, i + 1, j, word, boardSize, boardColSize, pos + 1)
        || search(board, i, j - 1, word, boardSize, boardColSize, pos + 1) || search(board, i, j + 1, word, boardSize, boardColSize, pos + 1));
    board[i][j] = word[pos];
    return tmp;
}
bool exist(char** board, int boardSize, int* boardColSize, char* word)
{
    if (!strlen(word))
        return false;
    for (int i = 0; i < boardSize; ++i)
    {
        for (int j = 0; j < *boardColSize; ++j)
        {
            if (search(board, i, j, word, boardSize, *boardColSize, 0))
                return true;
        }
    }
    return false;
}
int main()
{
    char arr[3][5]= { "ABCE","SFCS","ADEE" };
    char** p = c;
    char word[] = "ABBCCED";
    int b = 4;
    int* a = &b;
    exist(p, 3, a, word);
   /* char* s = (char*)malloc(sizeof(char) * 5);
    s[0] = 'a';
    s[1] = ' ';
    s[2] = 'b';
    s[3] = ' ';
    s[4] = '\0';
    s = replaceSpace(s);
    printf("%s", s);*/
    /*for (int i = 0; i < 9; i++)
        printf("%c", s[i]);*/
	return 0;
}