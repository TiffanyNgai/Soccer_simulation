//
//  Tiffany Ngai
//  20900617
//  121 assignment3 q1
//
//  I hereby declare that this code, submitted for credit for the course SYDE121, is a product of my own efforts. This coded solution has not been plagiarized from other sources and has not been knowingly plagiarized by others.
//
//  Project: Soccer simulation
//  Due Date: 30/10/2020

/* Ran the program several times and all event types can occur, and no particular game scenario is frequently repeated
   The outputted stats are correct
   
   e.g.
   Program output(with --> as manual caluculation):
   The game has started! First half begins!
   Team A shot!
   Oh no, the shot was off goal. --> shots off goal + 1

   Team A got a penalty kick! --> fouls + 1
   Goal!!!!!!! --> score of Team A + 1, shots on goal + 1


   First half is over
   The current score of Team A is: 1
   The current score of Team B is: 0
   The current number of shots on goal is: 1
   The current number of shots off goal is: 1
   The current number of blocked shots is: 0
   The current number of fouls is: 1
   The current number of yellow cards is: 0
   The current number of red cards is: 0
   Second half starts now.

   Team A got a penalty kick! --> fouls + 1
   Nice save, that was close. --> shots on goal + 1

   Team A shot!
   Nice save, that was close. --> shots on goal + 1

   Team A shot!
   Goal!!!!!!! --> score of Team A + 1, shots on goal + 1
   Team A is amazing!

   Team A shot!
   Wow, nice block! --> blocked shots + 1

   Team B shot!
   Oh no, the shot was off goal. --> shots off goal + 1

   Team A got a free kick! --> fouls + 1
   Oh no, the shot was off goal. --> shots off goal + 1

   Team A shot!
   Oh no, the shot was off goal. --> shots off goal + 1

   Team B got a free kick! --> fouls + 1
   Goal!!!!!!! --> score of Team B + 1, shots on goal + 1


   The game is over
   The score of Team A is: 2
   The score of Team B is: 1
   The number of shots on goal is: 5
   The number of shots off goal is: 4
   The number of blocked shots is: 1
   The number of fouls is: 4
   The number of yellow cards is: 0
   The number of red cards is: 0

   Program ended with exit code: 0
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
using namespace std;

//PURPOSE: check to see if the shot has scored
// INPUT: shot_on_goal - number of shot on goal, shot_off_goal - number of shot off goal,
//        blocked_shot - number of blocked shot, event_indicator - event that is occuring
// OUTPUT: corresponding statement for different events; updated shot_on_goal, updated shot_off_goal,
//         updated blocked_shot, scored - if the shot scored
void is_scored(int& shot_on_goal, int& shot_off_goal, int& blocked_shot, bool& scored, int event_indicator) {
    //declare and initialize variables
    int indicator = 0;
    scored = false;
    //generate random value
    if (event_indicator < 5) {
        indicator = rand() % 4;
    }
    else {
        indicator = rand() % 3;
    }
    
    //output corresponding statement and keep track on the number of shots and goals
    if (indicator == 0) {
        scored = true;
        shot_on_goal++;
        cout << "Goal!!!!!!!" << endl;
    }
    else if (indicator == 1) {
        shot_on_goal++;
        cout << "Nice save, that was close." << endl;
    }
    else if (indicator == 2) {
        shot_off_goal++;
        cout << "Oh no, the shot was off goal." << endl;
    }
    else if (indicator == 3) {
        blocked_shot++;
        cout << "Wow, nice block!" << endl;
    }
}

//PURPOSE: check if any card is given to Team A or Team B
// INPUT: yellow_card - number of current yellow card, red_card - number of current red card,
//        event_indicator - the event that is occuring
// OUTPUT: updated yellow_card, and updated red_card
void card(int& yellow_card, int& red_card, int event_indicator) {
    //declare and initialize variables
    int indicator = 0;
    //generate random value
    indicator = rand() % 3;
    //output corresponding statement and keep track on the number of cards
    if (indicator == 1) {
        yellow_card++;
        if (event_indicator == 3 || event_indicator == 5) {
            cout << "Team B got a yellow card." << endl;
        }
        else if (event_indicator == 4 || event_indicator == 6) {
            cout << "Team A got a yellow card. " << endl;
        }
    }
    else if (indicator == 2) {
        red_card++;
        if (event_indicator == 3 || event_indicator == 5) {
            cout << "Team B got a red card." << endl;
        }
        else if (event_indicator == 4 || event_indicator == 6) {
            cout << "Team A got a red card. " << endl;
        }
    }
}

//PURPOSE: generate the number of events occur during the game and call functions if needed
// INPUT: none
// OUTPUT: game stats at the end of each half, including the current score, number of shots on goal,
//         shots off goal, blocked shots, fouls, yellow cards, and red cards
void soccer_simulation() {
    //set the radomization seed
    srand(unsigned(time(0)));
    //declare and initialize variables
    int total_event_num = 0, first_event_num = 0;
    int event_indicator = 0;
    int team_a_goal = 0, team_b_goal = 0;
    int shot_on_goal = 0, shot_off_goal = 0, blocked_shot = 0;
    int foul_num = 0, yellow_card = 0, red_card = 0;
    //generate the number of events in first and second half
    total_event_num = rand() % 20 + 1;
    first_event_num = total_event_num - (rand() % total_event_num + 1);
    
    cout << "The game has started! First half begins!" << endl;
    for (int i = 1; i <= total_event_num; i++) {
        //generate random value for the event occured
        event_indicator = rand() % 6 + 1;
        //calling functions and output corresponding statement for the specified event
        if (event_indicator == 1) {
            sleep(rand() % 4 + 1);
            cout << "Team A shot!" << endl;
            bool scored = false;
            is_scored(shot_on_goal, shot_off_goal, blocked_shot, scored, event_indicator);
            if (scored) {
                team_a_goal++;
                cout << "Team A is amazing!" << endl;
            }
            cout << endl;
        }
        else if (event_indicator == 2) {
            sleep(rand() % 4 + 1);
            cout << "Team B shot!" << endl;
            bool scored = false;
            is_scored(shot_on_goal, shot_off_goal, blocked_shot, scored, event_indicator);
            if (scored) {
                team_b_goal++;
                cout << "Team B is unstoppable!" << endl;
            }
            cout << endl;
        }
        else if (event_indicator == 3) {
            sleep(rand() % 4 + 1);
            card(yellow_card, red_card, event_indicator);
            foul_num++;
            cout << "Team A got a free kick!" << endl;
            bool scored = false;
            is_scored(shot_on_goal, shot_off_goal, blocked_shot, scored, event_indicator);
            if (scored) {
                team_a_goal++;
            }
            cout << endl;
        }
        else if (event_indicator == 4) {
            sleep(rand() % 4 + 1);
            card(yellow_card, red_card, event_indicator);
            foul_num++;
            cout << "Team B got a free kick!" << endl;
            bool scored = false;
            is_scored(shot_on_goal, shot_off_goal, blocked_shot, scored, event_indicator);
            if (scored) {
                team_b_goal++;
            }
            cout << endl;
        }
        else if (event_indicator == 5) {
            sleep(rand() % 4 + 1);
            card(yellow_card, red_card, event_indicator);
            foul_num++;
            cout << "Team A got a penalty kick!" << endl;
            bool scored = false;
            is_scored(shot_on_goal, shot_off_goal, blocked_shot, scored, event_indicator);
            if (scored) {
                team_a_goal++;
            }
            cout << endl;
        }
        else if (event_indicator == 6) {
            sleep(rand() % 4 + 1);
            card(yellow_card, red_card, event_indicator);
            foul_num++;
            cout << "Team B got a penalty kick!" << endl;
            bool scored = false;
            is_scored(shot_on_goal, shot_off_goal, blocked_shot, scored, event_indicator);
            if (scored) {
                team_b_goal++;
            }
            cout << endl;
        }
        //check if the first half has finished and output the game stats when each half have finished
        if (i == first_event_num) {
            cout << endl << "First half is over" << endl
            << "The current score of Team A is: " << team_a_goal << endl
            << "The current score of Team B is: " << team_b_goal << endl
            << "The current number of shots on goal is: " << shot_on_goal << endl
            << "The current number of shots off goal is: " << shot_off_goal << endl
            << "The current number of blocked shots is: " << blocked_shot << endl
            << "The current number of fouls is: " << foul_num << endl
            << "The current number of yellow cards is: " << yellow_card << endl
            << "The current number of red cards is: " << red_card << endl
            << "Second half starts now." << endl << endl;
        }
        else if (i == total_event_num) {
            cout << endl << "The game is over" << endl
            << "The score of Team A is: " << team_a_goal << endl
            << "The score of Team B is: " << team_b_goal << endl
            << "The number of shots on goal is: " << shot_on_goal << endl
            << "The number of shots off goal is: " << shot_off_goal << endl
            << "The number of blocked shots is: " << blocked_shot << endl
            << "The number of fouls is: " << foul_num << endl
            << "The number of yellow cards is: " << yellow_card << endl
            << "The number of red cards is: " << red_card << endl << endl;
        }
    }
}


int main() {
    soccer_simulation();
    return 0;
}
