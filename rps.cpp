#include<iostream>
#include<random>
#include<vector>
#include<string>
using namespace std;
int main(){
    int per;
    int comp,rounds;
    string rematch;
    vector<string> computer = {"rock","paper","scissors"};
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0 , computer.size()-1);
    do{
        per = 0;
        comp = 0;
    cout << "----------Welcome to this ROCK - PAPER - SCISSORS game--------" << endl;
    cout << "Want to play how many rounds:";
    cin >> rounds;
    int temp = rounds;
    while(rounds--){
    string person;
    cout << "Your turn" << endl;
    k:
    cout << " Enter (rock or paper or scissors): ";
    cin >> person;
    if(person != "rock" && person != "scissors" && person != "paper"){
        cout << "Invalid choice re-enter." << endl;
        goto k;
    }
    cout << "You entered : " << person << endl; 
    cout << "Computer turn :";
    string computers = computer[dist(gen)];
    cout << computers << endl;
    if(person == computers){
        cout << "You and computer get tied" << endl;
    }
    else if((person == "scissors" && computers == "paper" )|| (person == "rock" && computers == "scissors" )|| (person == "paper" && computers == "rock")){
        cout << "You won the game." << endl;
        cout << "your score: " << ++per << endl;
    }
    else{
        cout << "Computer Won." << endl;
        cout << "Computer score: " << ++comp << endl;
    }
    }
    if(per > comp) {
        cout << "You won the " << temp << " rounds with the score " << per << " so you won the game." << endl;  
    }
    else if(per == comp){
        cout << "Both tied" << endl;
    }
    else{
         cout << "computer won the " << temp << " rounds with the score " << comp << " so computer won the game." << endl; 
    }
    cout << "Want to play again(Yes/No):" ;
    cin >> rematch;
}while(rematch == "Yes" || rematch == "yes" || rematch == "YES");
cout << "Thank you for playing" << endl;
return 0;
}