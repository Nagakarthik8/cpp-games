#include <iostream>
#include <random>
using namespace std;
void playGame(int chances, int maxnumber)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, maxnumber);
    int randomnumber = dist(gen);
    int enterednumber;
    cout << "You have " << chances << " chances." << endl;
    cout << "Guess a number between 1 and " << maxnumber << endl;
    while (chances > 0)
    {
        cout << "Enter the number: ";
        cin >> enterednumber;
        if (enterednumber == randomnumber)
        {
            cout << "Your number " << enterednumber
                 << " is equal to the random number." << endl;
            cout << "You Won!" << endl;
            return;
        }
        if (enterednumber < randomnumber)
        {
            cout << "The number is greater than your entered number." << endl;
        }
        else
        {
            cout << "The number is lesser than your entered number." << endl;
        }
        chances--;
        cout << "You have " << chances << " turns left." << endl;
    }
    cout << "You lost the game." << endl;
    cout << "The random number was " << randomnumber << endl;
    cout << "Better luck next time!" << endl;
}
int main()
{
    string rematch;
    do{
    int n;
    cout << "--------- NUMBER GUESS GAME -----------" << endl;
    cout << "1. Easy" << endl;
    cout << "2. Medium" << endl;
    cout << "3. Hard" << endl;
    cout << "4. Advanced " << endl;
    cout << "Enter the game level: ";
    cin >> n;
    switch (n)
    {
        case 1:
            playGame(12, 25);
            break;
        case 2:
            playGame(10, 50);
            break;
        case 3:
            playGame(7, 75);
            break;
        case 4:
            playGame(5, 100);
            break;
        default:
            cout << "Enter a valid level." << endl;
    }
    cout << "Do you want to play again(Yes/No):";
    cin >> rematch;
}while(rematch == "Yes");
cout << "Thankyou for playing." << endl;
    return 0;
}