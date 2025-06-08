#include<iostream>
#include<string>
#include<thread>
#include<chrono>
#include<climits> 
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"

using namespace std::chrono ;
using namespace std;

int main() {
    cout << RED << "=====================================" << RESET << endl;
cout << GREEN << "      WELCOME TO THE ULTIMATE         " << RESET << endl;
cout << BLUE << "        NUMBER GUESSING GAME          " << RESET << endl;
cout << YELLOW << "    Player vs Player Battle Mode!     " << RESET << endl;
cout << MAGENTA << "   Who will be the Fastest Guesser?   " << RESET << endl;
cout << CYAN << "    Let's find out... Get Ready!      " << RESET << endl;
cout << RED << "=====================================" << RESET << endl << endl;

cin.ignore() ;
cout << " Press ENTER to start the game" <<endl ;
cin.get() ;

int player1wins =0 ;
int player2wins =0 ;
int FastestTime = INT_MAX ;
string FastestPlayer =  "(none)";
string player1name , player2name;
cout << "Player 1 enter your name : " ;
cin >> player1name ;
cout << "Player 2 enter your name : " ;
cin >> player2name ;

char playagain ='y';  
 int turnsetter = 1 ; //start with player 1;

    while (playagain =='y' || playagain=='Y') {
        int secretnumber;
        int guess;
        int MaxAttempts = 10 ;
        bool guessed = false;
if (turnsetter == 1){
        cout << player2name << " please look away" << endl;
        cout <<player1name <<" please enter a secret number(1-100): " ;
        cin >> secretnumber;
        system("CLS"); //to clear screen so player 2 cannot see number
        cout << player2name  << " " << "you can look now " << endl;
        cout << player2name << " press enter when you are ready to start guessing " ;
}
else {
    cout << player1name << " please look away" << endl;
    cout << player2name << " enter secret number: ";
    cin >> secretnumber;
    system("CLS");
    cout << player1name << " you can look now" << endl;
    cout << player1name << " press enter when ready to guess" << endl;
}
        cin.ignore() ; 
        cin.get() ;
        auto start = high_resolution_clock ::now() ;

        if(turnsetter == 1) {
        cout << player2name << " guess your number. You have " << MaxAttempts << " attempts." << endl;
}        else {
    cout << player1name << " guess your number. You have " << MaxAttempts << " attempts." << endl;
}
         for (int i=0 ; i<MaxAttempts ; i++) {
             cin >> guess;
            if (secretnumber == guess) {
                cout << "you guessed it right in " << i+1 << " tries " << endl;
                guessed = true;
                break ;
            }

            else if (secretnumber > guess) {
                cout << "too low " << endl;
            }

            else if (secretnumber < guess) {
                cout << "too big " << endl;
            }

        }

        auto stop = high_resolution_clock ::now() ;
        auto duration = duration_cast < milliseconds > (stop - start) ;
cout << "You took " << duration.count() / 1000.0 << " seconds to guess." << endl;

double timeTaken = duration.count() / 1000.0;

if (guessed) {
    if (timeTaken < 1) {
    cout << RED << " Godlike reflexes! Impossible speed!" << RESET << endl;
}
    else if  (timeTaken < 3) {
        cout << GREEN << " Wow! Lightning fast!" << RESET << endl;
    } else if (timeTaken < 6) {
        cout << BLUE << " Great job! You're quick!" << RESET << endl;
    } else if (timeTaken < 15) {
        cout << YELLOW << " Good effort! Keep it up!" << RESET << endl;
    } else {
        cout << MAGENTA << "You are a tortoise ." << " You made it... finally! But you did it!" << RESET << endl;
    }
}


        if(guessed && duration.count() < FastestTime ) {
            FastestTime = duration.count() ;
            if (turnsetter ==1 ) {
                FastestPlayer = player2name ;
            }
            else {
                FastestPlayer = player1name ;
            }
        }
            if(guessed == true){
                if(turnsetter == 1) {
                    player2wins++ ;
                }
              else {
                player1wins++ ;
              }  
            }
            else{
                if(turnsetter == 1) {
                    player1wins++ ;
                }
                else{
                    player2wins++ ;
                }
            }
        if(!guessed) {
           if (turnsetter == 1) {
                cout << RED << "Sorry " << player2name << ", you lose :(  " << player1name << " wins! The number was " << secretnumber << RESET << endl;
    }      else {
                cout << RED << "Sorry " << player1name << ", you lose :(  " << player2name << " wins! The number was " << secretnumber << RESET << endl;
}
  }
        cout << BLUE << "Do you want to play again (y/n): " << RESET ;
        cin >> playagain ;
        cout << endl;

        if(turnsetter ==1){
            turnsetter = 2 ;
        }
        else {
            turnsetter = 1 ;
        }

    }

    cout << BLUE << "Thanks for playing" << RESET <<"\n" "\n" ;
    cout << GREEN << player1name << " wins : " <<" "  << player1wins << " rounds " << RESET <<endl;
    cout << MAGENTA << player2name << " wins : " << " "  << player2wins << " rounds " << RESET <<"\n" "\n" ;

    if (player1wins> player2wins) {
        cout << YELLOW << player1name << " , You are a champion " << RESET << endl ;
    }

    else if (player2wins > player1wins) {
        cout << CYAN << player2name << " , You are a champion " << RESET << endl ;
     }

     else {
        cout << GREEN << " It's a tie " << endl << " Well done both of you ! :) " << endl << "Now you both are champions ! " << RESET  << endl ;
     }

     if ( FastestTime != INT_MAX) { //if someone guessed it atleast once
        cout << YELLOW << " Fastest guess of the game : " << FastestTime / 1000.0 << " seconds by " << FastestPlayer << " ! " << RESET << endl;
     } else {
        cout << "No one guessed correctly this game!" << endl; 
     }
    return 0;

}