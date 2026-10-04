#include<iostream>
#include<random>
using namespace std;
int main(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1,100);
    int randomnumber = dist(gen);
    string rematch;
    do{
            cout << "************************* Even Odd challenge ******************************\n";
            int rounds;
            int temp1;
            do{
                cout << "\nEnter the rounds want to play : ";
                cin >> rounds;
                temp1 = rounds;
                if(rounds == 0){
                    cout << "\nInvalid ! Enter again";
                }
            }while(rounds == 0);
            int pscore = 0;
            int cscore = 0;
            int correct = 0;
            int incorrect = 0;
            while(rounds--){
                label:
                cout << "\nGuess (Even/Odd) : ";
                string check;
                string guess;
                string temp;
                cin >> guess;
                temp = guess;
                if(guess == "Even" || guess == "Odd"){
                       int randomnumber = dist(gen);
                       if(randomnumber % 2 == 0){
                             check = "Even";
                       }
                       else{
                        check = "Odd";
                       }
                       if(temp == check){
                        cout << "\nCorrect!";
                        pscore++;
                        correct++;
                       }
                       else{
                        cout << "\nIncorrect!";
                        cscore++;
                        incorrect++;
                       }
                       cout << "\nThe generated number is " << randomnumber ;
                       cout << "\nThe result is " << check;
                       cout << "\nYour prediction " << guess;
                       cout << "\nYour score is " << pscore;
                       cout << "\nComputer score is " << cscore << endl; 
                }
                else{
                    cout << "\nInvalid! Enter again.";
                    goto label;
                }
                   
            }
            cout << "\nTotal rounds played : " << temp1;
            cout << "\nCorrect answered : " << correct;
            cout << "\nIncorrect answer : " << incorrect;
            cout << "\nYours score : " << pscore;
            cout << "\nComputer score : " << cscore;
            float accuracy = (float)correct / rounds * 100;
            cout << "\nAccuracy percentage : " << accuracy << "%" << endl;
            if(pscore > cscore){
                cout << "\nCongratulation You won!";
            }
            else if(pscore < cscore){
                cout << "\nComputer Won!";
            }
            else{
                cout << "Match drawn!";
            }
            cout << "\n\n Want to play again(Yes/No) : ";
            cin >> rematch;
    }while(rematch == "Yes" || rematch == "yes" || rematch == "YES");
    cout << "\nThankyou for playing!";
}