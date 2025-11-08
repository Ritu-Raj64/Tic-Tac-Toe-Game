#include<iostream>
using namespace std;

char board[3][3]={ {'1','2','3'},{'4','5','6'},{'7','8','9'} };
char turn = 'X';
int raw,col,choise;
void showboard()
{
    cout<<"\n";
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout<<" "<<board[i][j]<<" ";
            if(j<2)
            cout<<"|";
        }
        if(i<2)
        cout<<"\n---|---|---\n";
    }
}
void playerturn()
{
    cout<<"\n\nPlayer '"<<turn<<"' enter position(1-9) =";
    cin>>choise;

    raw=(choise-1)/3;
    col=(choise-1)%3;

    if((board[raw][col]!='X') && (board[raw][col]!='O'))
    {
        board[raw][col]=turn;
        turn=(turn=='X')? 'O' : 'X';
    }
    else{
        cout << "Invalid move, try again!\n";
        playerturn();

    }
    
}
bool checkwin()
{
    for(int i=0;i<3;i++)
    {
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2])
            return true;
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i])
            return true;
    }

        if(board[0][0]==board[1][1] && board[1][1]==board[2][2])
            return true;
        if(board[0][2]==board[1][1] && board[1][1]==board[2][0])
            return true;
    return false;  
}
int main()
{
    cout<<"\n===Welcome to Tic Tac Toe Game===\n";
    while(!checkwin())
    {
        showboard();
        playerturn();
        checkwin();

    }
    showboard();
    if(checkwin())
    {
        cout<<"\n\nCongrulations PLayer '"<<(turn=='X'? 'O': 'X')<<"' Win!\n";
    }
}