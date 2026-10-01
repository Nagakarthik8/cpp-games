#include<iostream>
#include<random>
using namespace std;
int main(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dice(1,6);
    string player;
    string rematch;
    do{
        int rounds;
        int pscore = 0;
        int cscore = 0;
        cout << "Enter number of rounds:";
        cin >> rounds;
        int temp = rounds;
        while(rounds--){
            do{
            cout << "Player turn:" << endl;
            cout << "Enter (Roll/roll) to roll the dice:" ;
            cin >> player;
            if(player != "Roll" && player != "roll"){
                cout << "Invalid!" << endl;
            }
        }while(player != "Roll" && player != "roll");
        cout << "Player number :";
        int player = dice(gen);
        cout << player << endl;
        cout << "Computer turn:" << endl;
        cout << "Computer number :";
        int computer = dice(gen);
        cout << computer << endl;

        if(player > computer) {
            cout << "Player Won." << endl;
            cout << "Player score :" << ++pscore << endl;
        }
        else if(player < computer){
            cout << "Computer Won." << endl;
            cout << "Computer score :" << ++cscore << endl;
        }
        else{
            cout << "Both tied With the number: " << computer <<endl; 
        }
        }
        cout << "\n============  Final Result  ==================" << endl;
        cout << "Final score of the Person is " << pscore << endl;
        cout << "Final score of the Computer is " << cscore << endl;
        if(pscore > cscore) {
            cout << "Player won the game with the score " << pscore << endl;
        }
        else if(cscore > pscore){
            cout << "Computer won the game with the score " << cscore << endl;
        }
        else{
            cout << "Both tied! " << temp << " rounds." << endl;
        }
        cout << "Want to play again(YES/NO):" ;
        cin >> rematch;
    }while(rematch == "YES" || rematch == "yes" || rematch == "Yes");
    cout << "Thankyou for playing.";
    return 0;
}