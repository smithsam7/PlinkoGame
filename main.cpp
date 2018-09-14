/*
 Sam Smith, sec 2, smittysport7@gmail.com
 Purpose: A game of chance and winnings. User can chose a single or multiple chips to drop in the board, then they choose what slot to drop it in and if multiple chips how many chips to drop, through chance they win money!
 Inputs: menu option (quit, single chip, multiple chips), number of chips, which slot to drop them.
 Outputs: Menu options, statement saying dropping single or multiple chips, the path of the chip(if single chip), how much money won on the drop, if multiple chips total winnings of all chips and average winnings per chip, message of goodbye.
 Test Cases:
 Test 1:
 Input: The following are to test the re-request of menu after an incorrect input value: -4, 6, 1, -4, 9, 5, 2, -500, 1000, -4, 9, 2, 3, 1000, 0.
 Output: Check to see if the appropriate messages for errors are outputted and until a valued input is inputted.
 Test 2:
 Input: Using a fixed seed of 4: 1, 4, 1, 8, 1, 1, 0.
 Output:
 [4.0 4.5 5.0 4.5 4.0 4.5 5.0 5.5 6.0 6.5 6.0 5.5 6.0] Winnings: $1000.00
 [8.0 7.5 8.0 7.5 8.0 7.5 8.0 7.5 7.0 7.5 7.0 6.5 6.0] Winnings: $1000.00
 [1.0 1.5 1.0 1.5 1.0 0.5 0.0 0.5 1.0 0.5 1.0 0.5 1.0] Winnings: $500.00
 Test 3:
 Input: Using a fixed seed of 4: 2, 5, 5, 3, 5, 0.
 Output: Total Winnings- $2000.00, Average per chip- $400.00
 Total winnings on slot 0 chips: 2200
 Average winnings per chip: 440.00
 Total winnings on slot 1 chips: 2100
 Average winnings per chip: 420.00
 Total winnings on slot 2 chips: 1100
 Average winnings per chip: 220.00
 Total winnings on slot 3 chips: 20600
 Average winnings per chip: 4120.00
 Total winnings on slot 4 chips: 2000
 Average winnings per chip: 400.00
 Total winnings on slot 5 chips: 1500
 Average winnings per chip: 300.00
 Total winnings on slot 6 chips: 2700
 Average winnings per chip: 540.00
 Total winnings on slot 7 chips: 1700
 Average winnings per chip: 340.00
 Total winnings on slot 8 chips: 1700
 Average winnings per chip: 340.00
 */

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;

const int QUIT = 0;
const int SINGLE_CHIP = 1;
const int MULTIPLE_CHIPS = 2;
const int MULTIPLE_SLOTS_CHIPS = 3;
const int LEFT_BOUNDRAY = 0;
const int RIGHT_BOUNDRAY = 8;
const int PATH = 1;
const int PEG_FALL = 12;
const double RIGHT = 0.5;
const double LEFT = 0.5;
const double SLOT_0 = 0;
const double PRIZE_0 = 100.0;
const double SLOT_1 = 1;
const double PRIZE_1 = 500.0;
const double SLOT_2 = 2;
const double PRIZE_2 = 1000.0;
const double SLOT_3 = 3;
const double PRIZE_3 = 0.0;
const double SLOT_4 = 4;
const double PRIZE_4 = 10000.0;
const double SLOT_5 = 5;
const double PRIZE_5 = 0.0;
const double SLOT_6 = 6;
const double PRIZE_6 = 1000.0;
const double SLOT_7 = 7;
const double PRIZE_7 = 500.0;
const double SLOT_8 = 8;
const double PRIZE_8 = 100.0;
const int MONEY = 2;
const int INVALID_INPUT = -1;

int menuInput(){
    int menu_option = 0;
    do{
        cout << "MENU: Please select one of the following options:" << endl << endl;
        cout << "0 - Quit the program" << endl << endl;
        cout << "1 - Drop a single chip into one slot" << endl << endl;
        cout << "2 - Drop multiple chips into one slot" << endl << endl;
        cout << "3 - Drop multiple chips into each slot" << endl << endl;
        cout << "Enter your selection now: ";
        cin >> menu_option;
        cout << endl;
    
        if(menu_option < 0 || menu_option > 3 || cin.fail()){
            cin.clear();
            cin.ignore(10000,'\n');
            menu_option = INVALID_INPUT;
            cout << "INVALID SELECTION.  Please enter 0, 1, or 2" << endl << endl;
        }
    }while(menu_option < 0 || menu_option > 3);
    return menu_option;
}

int getInitialSlot(){
    int slot = 0;
    do{
        cout << "Which slot do you want to drop the chip in (0-8)? ";
        cin >> slot;
        cout << endl;
        if((slot < LEFT_BOUNDRAY) || (slot > RIGHT_BOUNDRAY || cin.fail())){
            cin.clear();
            cin.ignore(1000, '\n');
            slot = INVALID_INPUT;
            cout << "INVALID SLOT, please try again." << endl << endl;
            continue;
        }
    }while(slot < LEFT_BOUNDRAY || slot > RIGHT_BOUNDRAY);
    return slot;
}

double computeWinnings(int slot){
    
    if(slot == SLOT_0){
       return PRIZE_0;
    }
    else if(slot == SLOT_1){
        return PRIZE_1;
    }
    else if(slot == SLOT_2){
        return PRIZE_2;
    }
    else if(slot == SLOT_3){
        return PRIZE_3;
    }
    else if(slot == SLOT_4){
        return PRIZE_4;
    }
    else if(slot == SLOT_5){
        return PRIZE_5;
    }
    else if(slot == SLOT_6){
        return PRIZE_6;
    }
    else if(slot == SLOT_7){
        return PRIZE_7;
    }
    else if(slot == SLOT_8){
        return PRIZE_8;
    }
    return 0;
}

int dropSinglechip(double position, bool printPath){
    if(printPath){
        cout << fixed << setprecision(PATH);
        cout << "PATH: [" << position;
    }
    for(int j = 0; j < PEG_FALL ; j++){
        if(printPath){
            cout << " ";
        }
        if(position == LEFT_BOUNDRAY){
            position = position + RIGHT;
        }
        else if(position == RIGHT_BOUNDRAY){
            position = position - LEFT;
        }
        else if(rand() % 2 < 1){
            position += RIGHT;
        }
        else{
            position -= LEFT;
        }
        if(printPath){
        cout << position;
        }
    }
    if(printPath){
    cout << "]" << endl << endl;
    }
    
    return position;
}

int numberChips(){
    int number_of_chips = 0;
    
    do{
    cout << "How many chips do you want to drop (>0)? ";
    cin >> number_of_chips;
    cout << endl;
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            number_of_chips = INVALID_INPUT;
            cout << "INVALID NUMBER OF CHIPS, Please try again.";
            cout << endl << endl;
        }
    }while(number_of_chips <= 0);
    return number_of_chips;
}

int dropMultipleChips(int startingSlot, int numberOfChips){
    int totalWinnings = 0;
    for(int i = 0; i < numberOfChips; i++){
        int final_slot = dropSinglechip(startingSlot, false);
        totalWinnings += computeWinnings(final_slot);
    }
    return totalWinnings;
}

void printMultipleWinnings(int totalWinnings, int numberOfChips){
    double averageWinnings = (double)totalWinnings / numberOfChips;
    cout << fixed << setprecision(MONEY);
    cout << "Total winnings on " << numberOfChips << " chips: " << totalWinnings;
    cout << endl << endl;
    cout << "Average winnings per chip: " << averageWinnings;
    cout << endl << endl;
}

int main(){
    srand(4);
    cout << "Welcome to the plinko simulator!" << endl << endl;
    int userSelection = 0;
    do{
        userSelection = menuInput();
        if(userSelection == QUIT){
            break;
        }
        else if(userSelection == SINGLE_CHIP){
            cout << "*** DROP SINGLE CHIP ***" << endl << endl;
            int startingSlot = getInitialSlot();
            int final_slot = dropSinglechip(startingSlot, true);
            int winnings = computeWinnings(final_slot);
            cout << "Winnings: " << winnings << endl << endl;
        }
        else if(userSelection == MULTIPLE_CHIPS){
            cout << "*** DROP MULTIPLE CHIPS ***" << endl << endl;
            int numberOfChips = numberChips();
            int slot = getInitialSlot();
            int totalWinnings = dropMultipleChips(slot, numberOfChips);
            double averageWinnings = (double)totalWinnings / numberOfChips;
            cout << fixed << setprecision(MONEY);
            cout << "Total winnings on " << numberOfChips << " chips: " << totalWinnings;
            cout << endl << endl;
            cout << "Average winnings per chip: " << averageWinnings;
            cout << endl << endl;
        }
        else if(userSelection == MULTIPLE_SLOTS_CHIPS){
            cout << "*** SEQUENTIALLY DROP MULTIPLE CHIPS ***" << endl << endl;
            int numberOfChips = numberChips();
            for( int startingSlot = 0; startingSlot < 9; startingSlot++){
                int totalWinnings = dropMultipleChips(startingSlot, numberOfChips);
                double averageWinnings = (double)totalWinnings / numberOfChips;
                cout << fixed << setprecision(MONEY);
                cout << "Total winnings on slot " << startingSlot << " chips: " << totalWinnings;
                cout << endl << endl;
                cout << "Average winnings per chip: " << averageWinnings;
                cout << endl << endl;
            }
        }
    }while(userSelection != QUIT);
    return 0;
}





