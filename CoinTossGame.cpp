#include<iostream>
#include<random>
#include<vector>
using namespace std;
int main(){
    cout << "************************* CoinToss Game ******************************\n";
    string rematch;
    random_device rd;
    mt19937 gen(rd());
    vector<string> computer = {"Heads", "Tails"};
    vector<string> result = {"Heads", "Tails"};
    uniform_int_distribution<int> computerDist(0, computer.size() - 1);
    uniform_int_distribution<int> resultDist(0, result.size() - 1);
    do{
        int rounds;
        cout << "Enter number of rounds: ";
        cin >> rounds;
        int temp = rounds;
        int pscore = 0;
        int cscore = 0;
        while(rounds--){
            string player;
            do{
                cout << "\nPlayer turn" << endl;
                cout << "Enter (Heads) or (Tails): ";
                cin >> player;
                if(player != "Heads" && player != "Tails"){
                    cout << "Invalid! Please enter again." << endl;
                }
            }while(player != "Heads" && player != "Tails");
            cout << "\nComputer turn: ";
            string computers = computer[computerDist(gen)];
            cout << computers << endl;
            string result1 = result[resultDist(gen)];
            cout << "The result of this round is: "
                 << result1 << endl;
            if(result1 == "Heads"){
                if(player == "Heads" && computers == "Heads"){
                    cout << "Both tied!" << endl;
                }
                else if(player == "Heads" && computers == "Tails"){
                    cout << "Player Won!" << endl;
                    pscore++;
                }
                else{
                    cout << "Computer won!" << endl;
                    cscore++;
                }
            }
            else if(result1 == "Tails"){

                if(player == "Tails" && computers == "Tails"){
                    cout << "Both tied!" << endl;
                }
                else if(player == "Tails" && computers == "Heads"){
                    cout << "Player Won!" << endl;
                    pscore++;
                }
                else{
                    cout << "Computer won!" << endl;
                    cscore++;
                }
            }

            cout << "Current Player Score: " << pscore << endl;
            cout << "Current Computer Score: " << cscore << endl;
        }
        cout << "\n========== FINAL RESULT ==========" << endl;

        if(pscore == cscore){
            cout << "Both are tied with the score "
                 << pscore << endl;
        }
        else if(pscore > cscore){
            cout << "Player won the " << temp
                 << " rounds with the score "
                 << pscore << endl;
        }
        else{
            cout << "Computer won the " << temp
                 << " rounds with the score "
                 << cscore << endl;
        }
        cout << "\nDo you want to play again? (Yes/No): ";
        cin >> rematch;
    }while(rematch == "Yes" || rematch == "yes");
    return 0;
}