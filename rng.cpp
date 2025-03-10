#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int user_input() {

    int userVal;
    do{
        cout << endl << "Enter number between 1-100" << endl;
        cin >> userVal;
    }while((userVal < 1) || (userVal > 100));

    return userVal;
}


int main(){

    int userGuess, compNum, guessCount;
    int score = 0;
    
    bool play = true;
    
    srand(time(NULL)); //seed for random

    do{

        compNum = rand() % 100 + 1;
        guessCount = 1;
        cout << endl << "Guess the number between 1-100" << endl;
        cout << "---------------------------------" << endl;

        userGuess = user_input();
        while(userGuess != compNum){
            cout << "\nThe guess " << userGuess << " is ";
            if(userGuess > compNum) {
                cout << "too high. Try again." << endl;
            } else {
                cout << "too low. Try again" << endl;
            }
            cout << "\n---------------------------------";
            userGuess = user_input();
            guessCount++;
        }
        score++;
        cout << "Congratulations! You figured out my number in " << guessCount << " guesses!" << endl << "Your score for this run is: " << score << endl;
        cout << endl << "Want to play again?" << endl << "Press 1 to play or 2 to quit" << endl;

        cin >> userGuess;
        if(userGuess != 1){
            play = false;
        }

    } while(play);

    return 0;
}