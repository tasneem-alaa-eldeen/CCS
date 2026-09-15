# include <iostream>
using namespace std;
int main(){
    int player1 , player2;
    cout<<"=== Rock Paper Scissors ==="<<endl;
    cout<<"1. Rock"<<endl;
    cout<<"2. Paper"<<endl;
    cout<<"3. Scissors"<<endl;
    cout<<"Player 1, enter choice(1-3): ";
    cin>>player1;
    cout<<"Player 2, enter choice(1-3): ";
    cin>>player2;
    if(player1<1 || player1>3 || player2<1 || player2>3 ){
        cout<<"Invalid choice! Try again."<<endl;
        return 0;
    }
    if(player1==player2){
        cout<<"It's a Tie!"<<endl;
    }
    else if((player1==1 && player2==3) 
    ||(player1==2 && player2==1) 
    ||(player1==3 && player2==2) ){
        cout<<"Player 1 Wins!"<<endl;
    }
    else{
        cout<<"Player 2 Wins!"<<endl;
    }
    return 0;
}