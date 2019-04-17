/*
 * Project Title:
 * - Prison Escape
 * Description: (should be a few sentences)
 * This program is a text based, zork-style prison escape game. You start in a cell block room and based on the description
 * of the room, and clues from the walls, it is your goal to escape the prison. You can pickup items, navigate rooms, and
 * use items. The prison has nine rooms but that is not disclosed to the player.
 *
 * Developers:
 * - Joshua Sutton - suttonju@mail.uc.edu
 * - Andrew Dillon - dillonal@mail.uc.edu
 *
 * Help Received:
 * - N/A
 *
 * Special Instructions: // optional
 * - All special instructions are given in the controls screen in game
 *
 * Developer comments: // Not optional
 *
 * Everything preformed to make this program was done together and the work was split 50/50.
 * Everything that involved logic and constructing the structure of the program was a mutual
 * effort.
 *
 * Joshua Sutton:
 * I learned how to work with a partner to make something and I learned how other people
 * think when they program which expands my knowledge
 * Andrew Dillon:
 * I learned that if you lay out and plan a program beforehand it makes it alot easier to
 * program and decreases the chances of having bugs
 */


#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

/* Function Name: Inventory
 *
 * Function Description:
 * This function outputs the updated inventory at all times to the player
 *
 * Parameters:
 * The (&inventory)[7] parameter is the array of integers that corresponds
 * to what items the player has at that time
 *
 * return value:
 * void - (couts the inventory)
 */

void Inventory(int (&inventory)[7]){
    cout << endl << "Inventory [ ";
    for (int i = 0; i < 7; i++){
        if (inventory[i] == 1) {
            cout << i + 1 << " - paperclip ";
        }
        else if (inventory[i] == 2) {
            cout <<  i + 1 << " - id_card ";
        }
        else if (inventory[i] == 3) {
            cout << i + 1 << " - wrench ";
        }
        else if (inventory[i] == 4) {
            cout << i + 1 << " - rope ";
        }
        else if (inventory[i] == 5) {
            cout << i + 1 << " - flashlight ";
        }
        else if (inventory[i] == 6) {
            cout << i + 1 << " - backpack ";
        }
        else if (inventory[i] == 7) {
            cout << i + 1 << " - scissors ";
        }
        else if (inventory[i] == 10) {
            cout << i + 1 << " - blanket ";
        }
        else if (inventory[i] == 11) {
            cout << i + 1 << " - plastic_spoon ";
        }
        else if (inventory[i] == 12) {
            cout << i + 1 << " - revolver ";
        }
        else if (inventory[i] == 13) {
            cout << i + 1 << " - food_tray ";
        }
        else if (inventory[i] == 14) {
            cout << i + 1 << " - cell_phone ";
        }
        else if (inventory[i] == 15) {
            cout << i + 1 << " - candle ";
        }
        else if (inventory[i] == 16) {
            cout << i + 1 << " - soap ";
        }
        }
    cout << "]" << endl << endl;
}

/* Function Name: Controls
 *
 * Function Description:
 * This function outputs the controls panel to the player
 *
 * Parameters:
 * N/A
 *
 * return value:
 * void - (couts the controls)
 */

void Controls(){

    cout << endl << endl;
    cout << "         Controls: " << endl;
    cout << "      W - Faces NORTH in current location" << endl;
    cout << "      A - Faces WEST in current location" << endl;
    cout << "      S - Faces SOUTH in current location" << endl;
    cout << "      D - Faces EAST in current location" << endl << endl;
    cout << "         Commands: " << endl;
    cout << "      Type 'pickup_' followed by the name of an item if you wish to obtain an item" << endl;
    cout << "      Type 'use_' followed by the name of the item in your inventory to use an item" << endl;
    cout << "      Type 'inventory' to view what you have in your inventory" << endl;
    cout << "      Type 'controls' to view the controls panel" << endl << endl;
    cout << "         Disclamiers: " << endl;
    cout << "      If 'That is not a valid command / Invalid Order of Commands' is displayed, your orientation" << endl;
    cout << "      in the room will reset" << endl;
    cout << "      All entries inputted should be completely lowercase & spaces should have an underscore (_)" << endl << endl;
}

/* Function Name: Cell
 *
 * Function Description:
 * This function preforms all the actions needed that the player can make within
 * this room
 *
 * Parameters:
 * The (&inventory)[7] parameter is the array of integers that corresponds
 * to what items the player has at that time
 * The &cellCnt parameter keeps track of how many times they've been in this room
 * The &location parameter passes in the string location variable which is used in main
 *
 * return value:
 * string (This value gets assigned to the updated location variable in main which will call the new room function)
 */

string Cell(int (&inventory)[7], int &cellCnt, string &location){
    string action = "";
    string useItem;
    int inventoryFlag = 0;
    int idCard = 2;
    int blanket = 10;
    int inventorySwap;
    int moveCount = 0;
    int randGaurdAlert = rand() % 3 + 4;


    cout << endl << "You are in the Cell Blocks" << endl << endl;

    if (cellCnt == 0){                                                  // Gives detailed description of the room first time the player enters the room
        cout << "It is 3AM, you have been up all night after months of preparation to escape the prison." << endl;
        cout << "For some reason, you can't remember any of your plans, but you have no choice. You must" << endl;
        cout << "try to escape while guards roam through the prison. Before you try and leave the cell blocks," << endl;
        cout << "I would take some supplies. On your bed, you see an id_card, and a blanket. It is up to you " << endl;
        cout << "now, Good Luck!" << endl << endl;

        cellCnt++;
    }

    if (cellCnt != 0) {                                                 // Gives no detailed description any other time the player enters the room
        cin >> action;
        do {

            cout << endl;

        if (action == "pickup_id_card" || action == "pickup_ID_Card"){  // Initiates picking up the ID Card

            for (int i = 0; i < 7; i++){                                // Puts the item into the players first open inventory slot
                inventoryFlag = 0;
                if (inventory[i] == 0) {
                    cout << "You have collected an ID Card" << endl << endl;
                    inventory[i] = idCard;
                    inventoryFlag = 1;
                    cin >> action;
                    break;
                }
            }

            if (inventoryFlag == 0)  {                                                                      // If the inventory is filled, asks the user which slot they want to replace
                Inventory(inventory);
                cout << "Which slot in your inventory do you want to replace with this item (Enter 1-7)?" << endl;
                do  {
                    cin >> inventorySwap;
                    if (inventorySwap >= 1 && inventorySwap <= 7)  {            // Checks to make sure the inputed inventory slot is a valid slot
                        cout << "You have collected an ID Card" << endl << endl;
                        inventory[inventorySwap - 1] = idCard;
                        cin >> action;
                    }
                    else {
                        cout << "Enter a valid inventory slot" << endl << endl;
                    }
                } while (inventorySwap < 1 || inventorySwap > 7);
            }

        }
        else if (action == "pickup_blanket" || action == "pickup_Blanket") {  // Initiates picking up the Blanket

            for (int i = 0; i < 7; i++){                                      // Puts the item into the players first open inventory slot
                inventoryFlag = 0;
                if (inventory[i] == 0) {
                    cout << "You have collected a Blanket" << endl << endl;
                    inventory[i] = blanket;
                    inventoryFlag = 1;
                    cin >> action;
                    break;
                }
            }

            if (inventoryFlag == 0)  {                                                                     // If the inventory is filled, asks the user which slot they want to replace
                Inventory(inventory);
                cout << "Which slot in your inventory do you want to replace with this item?" << endl;
                do  {
                    cin >> inventorySwap;
                    if (inventorySwap >= 1 && inventorySwap <= 7)  {            // Checks to make sure the inputed inventory slot is valid
                        cout << "You have collected a Blanket" << endl << endl;
                        inventory[inventorySwap - 1] = blanket;
                        cin >> action;
                    }
                    else {
                        cout << "Enter a valid inventory slot" << endl << endl;
                    }
                } while (inventorySwap < 1 || inventorySwap > 7);
            }
        }
        else if (action == "inventory") {                                       // Shows the player their current inventory
            Inventory(inventory);
            cin >> action;
            }

        else if (action == "controls") {                                        // Displays control panel to the user
            Controls();
            cin >> action;
        }

        else if (action == "a" || action == "A"){                                    // Player looks at the west wall
            moveCount++;
            if (randGaurdAlert == moveCount){
                cout << "You accidentally make a loud noise banging into the cell bars, and you" << endl;       // Player triggers guard and warns them to get out of the room
                cout << "are afraid a prison guard heard you. He is likely on his way now!" << endl << endl;
            }
            else if (moveCount == 7) {
                return "lose";
            }
            cout << "On the west wall, you see lots of sleeping inmates in their cells." << endl << endl;                                    // Description of the west wall

            do  {
                cin >> action;
                if (action == "use_id_card" || action == "use_blanket" || action == "use_plastic_spoon" || action == "use_food_tray" || action == "use_scissors" || action == "use_revolver" || action == "use_backpack" || action == "use_cell_phone" || action == "use_candle" || action == "use_wrench" || action == "use_soap" || action == "use_rope" || action == "use_flashlight" || action == "use_paperclip")  {
                    cout << "That item cannot be used here" << endl;
                }
                else if (action != "w" || action != "W" || action != "a" || action != "A" || action != "s" || action != "S" || action != "d" || action != "D") {
                    break;
                }
            } while (1);
        }
        else if (action == "s" || action == "S"){                               // Player looks at the south wall
            moveCount++;
            if (randGaurdAlert == moveCount){
                cout << "You accidentally make a loud noise banging into the cell bars, and you" << endl;       // Player triggers guard and warns them to get out of the room
                cout << "are afraid a prison guard heard you. He is likely on his way now!" << endl << endl;
            }
            else if (moveCount == 7) {
                return "lose";
            }
            cout << "On the south wall, you can only see a few things for it is very dark." << endl;            // Description of the south wall
            cout << "Of those very few things, you see a sink, a large one-way mirror, and a" << endl;
            cout << "large high tech door with which you know prison guards use from time to time" << endl << endl;

            do  {
                cin >> action;
                if (action == "use_id_card" && (inventory[0] == 2 || inventory[1] == 2 || inventory[2] == 2 || inventory[3] == 2 || inventory[4] == 2 || inventory[5] == 2 || inventory[6] == 2))   {
                    cout << endl << "You have successfully used the id_card to get through the high tech door. " << endl;
                    return "Library";       // Returns the new location of the player
                }
                else if (action == "use_blanket" || action == "use_plastic_spoon" || action == "use_food_tray" || action == "use_scissors" || action == "use_revolver" || action == "use_backpack" || action == "use_cell_phone" || action == "use_candle" || action == "use_wrench" || action == "use_soap" || action == "use_rope" || action == "use_flashlight" || action == "use_paperclip") {
                    cout << "That item cannot be used here" << endl;
                }
                else if (action != "w" || action != "W" || action != "a" || action != "A" || action != "s" || action != "S" || action != "d" || action != "D") {
                    break;
                }
            } while(1);
        }
        else if (action == "w" || action == "W"){                               // Player looks at the north wall
            moveCount++;
            if (randGaurdAlert == moveCount){
                cout << "You accidentally make a loud noise banging into the cell bars, and you" << endl;       // Player triggers guard and warns them to get out of the room
                cout << "are afraid a prison guard heard you. He is likely on his way now!" << endl << endl;
            }
            else if (moveCount == 7) {
                return "lose";
            }
            cout << "On the north wall, you see a large garage-like door with a red light to the left" << endl;            // Description of the north wall
            cout << "of it. You know that this is the door you and the other inmates leave out of" << endl;
            cout << "whenever you get time out of your cell." << endl << endl;

            do  {
                cin >> action;
                if (action == "use_id_card" && (inventory[0] == 2 || inventory[1] == 2 || inventory[2] == 2 || inventory[3] == 2 || inventory[4] == 2 || inventory[5] == 2 || inventory[6] == 2))   {
                    cout << endl << "You used the id_card to traverse the garage-like door" << endl;
                    return "messHall";      // Returns the new location of the player
                }
                else if (action == "use_blanket" || action == "use_plastic_spoon" || action == "use_food_tray" || action == "use_scissors" || action == "use_revolver" || action == "use_backpack" || action == "use_cell_phone" || action == "use_candle" || action == "use_wrench" || action == "use_soap" || action == "use_rope" || action == "use_flashlight" || action == "use_paperclip") {
                    cout << "That item cannot be used here" << endl;
                }
                else if (action != "w" || action != "W" || action != "a" || action != "A" || action != "s" || action != "S" || action != "d" || action != "D") {
                    break;
                }
            } while(1);
        }
        else if (action == "d" || action == "D"){                               // Player looks at the east wall
            moveCount++;
            if (randGaurdAlert == moveCount){
                cout << "You accidentally make a loud noise banging into the cell bars, and you" << endl;       // Player triggers guard and warns them to get out of the room
                cout << "are afraid a prison guard heard you. He is likely on his way now!" << endl << endl;
            }
            else if (moveCount == 7) {
                return "lose";
            }
            cout << "On the east wall, you see lots of sleeping inmates in their cells." << endl << endl;                                    // Description of the east wall

            do  {
                cin >> action;
                if (action == "use_id_card" || action == "use_blanket" || action == "use_plastic_spoon" || action == "use_food_tray" || action == "use_scissors" || action == "use_revolver" || action == "use_backpack" || action == "use_cell_phone" || action == "use_candle" || action == "use_wrench" || action == "use_soap" || action == "use_rope" || action == "use_flashlight" || action == "use_paperclip")  {
                    cout << "That item cannot be used here" << endl;
                }
                else if (action != "w" || action != "W" || action != "a" || action != "A" || action != "s" || action != "S" || action != "d" || action != "D") {
                    break;
                }
            } while (1);
        }

        else {                                                              // Checks the users input statement to see if it is valid
            cout << "That is not a valid command / Invalid Order of Commands" << endl;
            cin >> action;
        }

        } while  (location == "Cell");
    }
}

/* Function Name: messHall
 *
 * Function Description:
 * This function preforms all the actions needed that the player can make within
 * this room
 *
 * Parameters:
 * The (&inventory)[7] parameter is the array of integers that corresponds
 * to what items the player has at that time
 * The &messHallCnt parameter keeps track of how many times they've been in this room
 * The &location parameter passes in the string location variable which is used in main
 *
 * return value:
 * string (This value gets assigned to the updated location variable in main which will call the new room function)
 */

string messHall(int (&inventory)[7], int &messHallCnt, string &location){
    string action = "";
    string useItem;
    int inventoryFlag = 0;
    int plastic_spoon = 11;
    int inventorySwap;
    int moveCount = 0;
    int randGaurdAlert = rand() % 3 + 4;


    cout << endl << "You are in the Mess Hall" << endl << endl;

    if (messHallCnt == 0){                                                                      // Gives detailed description of the room first time the player enters the room
        cout << "You succesfully entered the Mess Hall. After looking around " << endl;
        cout << "you realize you made it into the Mess Hall. You notice that the room has rows of tables" << endl;
        cout << "and chairs. On one of the tables, you see a plastic_spoon." << endl << endl;

        messHallCnt++;
    }

    if (messHallCnt != 0) {                                                                     // Gives no detailed description any other time the player enters the room
        cin >> action;
        do {

            cout << endl;

        if (action == "pickup_plastic_spoon"){                                                 // Initiates picking up the Plastic Spoon

            for (int i = 0; i < 6; i++){                                                       // Puts the item into the players first open inventory slot
                inventoryFlag = 0;
                if (inventory[i] == 0) {
                    cout << "You have collected a Plastic Spoon" << endl << endl;
                    inventory[i] = plastic_spoon;
                    inventoryFlag = 1;
                    cin >> action;
                    break;
                }
            }

            if (inventoryFlag == 0)  {                                                         // If the inventory is filled, asks the user which slot they want to replace
                Inventory(inventory);
                cout << "Which slot in your inventory do you want to replace with this item (Enter 1-7)?" << endl;
                do  {
                    cin >> inventorySwap;
                    if (inventorySwap >= 1 && inventorySwap <= 7)  {                           // Checks to make sure the inputed inventory slot is a valid slot
                        cout << "You have collected a Plastic Spoon" << endl << endl;
                        inventory[inventorySwap - 1] = plastic_spoon;
                        cin >> action;
                    }
                    else {
                        cout << "Enter a valid inventory slot" << endl << endl;
                    }
                } while (inventorySwap < 1 || inventorySwap > 7);
            }

        }

        else if (action == "inventory") {                                                      // Shows the player their current inventory
            Inventory(inventory);
            cin >> action;
            }

        else if (action == "controls") {                                                         // Displays control panel to the user
            Controls();
            cin >> action;
        }

        else if (action == "a" || action == "A"){                                                // Player looks at the west wall
            moveCount++;
            if (randGaurdAlert == moveCount){
                cout << "While walking around you accidentally walk through a turnstile and it makes a loud beep. You" << endl;       // Player triggers guard and warns them to get out of the room
                cout << "are afraid a prison guard heard you, and he is likely on his way now!" << endl << endl;
            }
            else if (moveCount == 7) {
                return "lose";
            }
            cout << "After turning to the west, you see a large white cinderblock wall that only contains" << endl;                   // Description of the west wall
            cout << "a large built-in fan, and an old looking door with a picklock" << endl << endl;

            do  {
                cin >> action;
                if (action == "use_paperclip" && (inventory[0] == 1 || inventory[1] == 1 || inventory[2] == 1 || inventory[3] == 1 || inventory[4] == 1 || inventory[5] == 1 || inventory[6] == 1))   {
                    cout << endl << "You picked the lock using the paperclip" << endl;
                    return "Kitchen";       // Returns the new location of the player
                }
                if (action == "use_id_card" || action == "use_blanket" || action == "use_plastic_spoon" || action == "use_food_tray" || action == "use_scissors" || action == "use_revolver" || action == "use_backpack" || action == "use_cell_phone" || action == "use_candle" || action == "use_wrench" || action == "use_soap" || action == "use_rope" || action == "use_flashlight")  {
                    cout << "That item cannot be used here" << endl;
                }
                else if (action != "w" || action != "W" || action != "a" || action != "A" || action != "s" || action != "S" || action != "d" || action != "D") {
                    break;
                }
            } while (1);
        }
        else if (action == "s" || action == "S"){                                                                                           // Player looks at the south wall
            moveCount++;
            if (randGaurdAlert == moveCount){
                cout << "While walking around you accidentally walk through a turnstile and it makes a loud beep. You" << endl;       // Player triggers guard and warns them to get out of the room
                cout << "are afraid a prison guard heard you, and he is likely on his way now!" << endl << endl;
            }
            else if (moveCount == 7) {
                return "lose";
            }
            cout << "On the south wall, you see a large garage-like door with a red light to the right of it." << endl << endl;            // Description of the south wall

            do  {
                cin >> action;
                if (action == "use_id_card" && (inventory[0] == 2 || inventory[1] == 2 || inventory[2] == 2 || inventory[3] == 2 || inventory[4] == 2 || inventory[5] == 2 || inventory[6] == 2))   {
                    cout << endl << "You used the id_card to traverse the garage-like door" << endl;
                    return "Cell";       // Returns the new location of the player
                }
                else if (action == "use_blanket" || action == "use_plastic_spoon" || action == "use_food_tray" || action == "use_scissors" || action == "use_revolver" || action == "use_backpack" || action == "use_cell_phone" || action == "use_candle" || action == "use_wrench" || action == "use_soap" || action == "use_rope" || action == "use_flashlight" || action == "use_paperclip") {
                    cout << "That item cannot be used here" << endl;
                }
                else if (action != "w" || action != "W" || action != "a" || action != "A" || action != "s" || action != "S" || action != "d" || action != "D") {
                    break;
                }
            } while(1);
        }
        else if (action == "w" || action == "W"){                               // Player looks at the north wall
            moveCount++;
            if (randGaurdAlert == moveCount){
                cout << "While walking around you accidentally walk through a turnstile and it makes a loud beep. You" << endl;       // Player triggers guard and warns them to get out of the room
                cout << "are afraid a prison guard heard you, and he is likely on his way now!" << endl << endl;
            }
            else if (moveCount == 7) {
                return "lose";
            }
            cout << "On the north wall, you see a large, baren cinder-block wall. At the top of the" << endl;                                   // Description of the north wall
            cout << "wall, moonlight seems to show through, but it seems out of sight." << endl << endl;

            do  {
                cin >> action;
                if (action == "use_id_card" || action == "use_blanket" || action == "use_plastic_spoon" || action == "use_food_tray" || action == "use_scissors" || action == "use_revolver" || action == "use_backpack" || action == "use_cell_phone" || action == "use_candle" || action == "use_wrench" || action == "use_soap" || action == "use_rope" || action == "use_flashlight" || action == "use_paperclip")  {
                    cout << "That item cannot be used here" << endl;
                }
                else if (action != "w" || action != "W" || action != "a" || action != "A" || action != "s" || action != "S" || action != "d" || action != "D") {
                    break;
                }
            } while (1);
        }
        else if (action == "d" || action == "D"){                               // Player looks at the east wall
            moveCount++;
            if (randGaurdAlert == moveCount){
                cout << "While walking around you accidentally walk through a turnstile and it makes a loud beep. You" << endl;       // Player triggers guard and warns them to get out of the room
                cout << "are afraid a prison guard heard you, and he is likely on his way now!" << endl << endl;
            }
            else if (moveCount == 7) {
                return "lose";
            }
            cout << "On the east wall, you see what seems to be an open double" << endl;                                    // Description of the east wall
            cout << "door leading outside... It can't be this easy, can it?" << endl;
            cout << "Would you like to proceed?" << endl << endl;

            do  {
                cin >> action;
                if (action == "yes" || action == "y"){
                    return "Yard";
                }
                else if (action == "no" || action == "n") {
                    cout << endl << "Whats your next move?" << endl;
                    cin >> action;
                    break;
                }
                else if (action == "use_id_card" || action == "use_blanket" || action == "use_plastic_spoon" || action == "use_food_tray" || action == "use_scissors" || action == "use_revolver" || action == "use_backpack" || action == "use_cell_phone" || action == "use_candle" || action == "use_wrench" || action == "use_soap" || action == "use_rope" || action == "use_flashlight" || action == "use_paperclip")  {
                    cout << "That item cannot be used here" << endl;
                }
                else if (action != "w" || action != "W" || action != "a" || action != "A" || action != "s" || action != "S" || action != "d" || action != "D") {
                    break;
                }
            } while (1);
        }

        else {                                                              // Checks the users input statement to see if it is valid
            cout << "That is not a valid command / Invalid Order of Commands" << endl;
            cin >> action;
        }

        } while  (location == "messHall");
    }
}

/* Function Name: Yard
 *
 * Function Description:
 * This function preforms all the actions needed that the player can make within
 * this room
 *
 * Parameters:
 * The (&inventory)[7] parameter is the array of integers that corresponds
 * to what items the player has at that time
 *
 * return value:
 * string (This value gets assigned to the updated location variable in main which will call the new room function)
 * This room could also include string "win" as location to break the infinite loop in main and win the game.
 */

string Yard(int (&inventory)[7]){
    bool backpackBool = 0;
    bool scissorsBool = 0;
    bool ropeBool = 0;
    for (int i = 0; i < 7; i++){                                // Puts the item into the players first open inventory slot
        if (inventory[i] == 6) {
            backpackBool = 1;
        }
        else if (inventory[i] == 7) {
            scissorsBool = 1;
        }
        else if (inventory[i] == 4) {
            ropeBool = 1;
        }
    }
    if ((backpackBool == 0 && scissorsBool == 0 && ropeBool == 0) || (backpackBool == 0 && scissorsBool == 1 && ropeBool == 0) || (backpackBool == 0 && scissorsBool == 1 && ropeBool == 1) || (backpackBool == 0 && scissorsBool == 0 && ropeBool == 1) )  {
        cout << "You walk outside into the yard and realize if you stay out here any longer " << endl;
        cout << "the watch tower will spot you. You run back insde!" << endl << endl;
        return "messHall";
    }
    else if ((backpackBool == 1 && scissorsBool == 0 && ropeBool == 0) || (backpackBool == 1 && scissorsBool == 1 && ropeBool == 0))  {
        cout << "You walk outside and quickly slip into the guard uniform from the backpack. " << endl;
        cout << "After walking around for a few minutes, you realize theres no way for you " << endl;
        cout << "to make it over the wall, so you go back inside." << endl << endl;
        return "messHall";
    }
    else if (backpackBool == 1 && scissorsBool == 0 && ropeBool == 1)  {
        cout << "You walk outside and quickly slip into the guard uniform from the backpack. " << endl;
        cout << "After walking around for a few minutes, you use the rope to climb up the wall." << endl;
        cout << "Once you get to the top of the wall, you realize you don't have any way to" << endl;
        cout << "get around the barbed wire. You climb back down and go back inside." << endl << endl;
        return "messHall";
    }
    else {
        return "win";
    }

}

/* Function Name: wardensOffice
 *
 * Function Description:
 * This function preforms all the actions needed that the player can make within
 * this room
 *
 * Parameters:
 * The (&inventory)[7] parameter is the array of integers that corresponds
 * to what items the player has at that time
 * The &officeCnt parameter keeps track of how many times they've been in this room
 * The &location parameter passes in the string location variable which is used in main
 *
 * return value:
 * string (This value gets assigned to the updated location variable in main which will call the new room function)
 */

string wardensOffice(int (&inventory)[7], int &officeCnt, string &location){
    string action = "";
    string useItem;
    int inventoryFlag = 0;
    int revolver = 12;
    int backpack = 6;
    int inventorySwap;
    int moveCount = 0;
    int randGaurdAlert = rand() % 3 + 4;


    cout << endl << "You are in the Warden's Office" << endl << endl;

    if (officeCnt == 0){                                                  // Gives detailed description of the room first time the player enters the room
        cout << "You were able to get in the ultra secret Warden's office. Like a typical office, the room" << endl;
        cout << "is large with cedar desk, two couches, and a bookshelf. You start going through the Warden's" << endl;
        cout << "belongings, attempting to find something useful. You open up the first drawer and see a revolver." << endl;
        cout << "On the couch, you see two straps dangling lossely, but you can't really see what the object is." << endl << endl;

        officeCnt++;
    }

    if (officeCnt != 0) {                                                 // Gives no detailed description any other time the player enters the room
        cin >> action;
        do {

            cout << endl;

        if (action == "pickup_backpack" || action == "pickup_Backpack" || action == "pickup_bag" || action == "pickup_Bag"){  // Initiates picking up the Backpack

            for (int i = 0; i < 7; i++){                                // Puts the item into the players first open inventory slot
                inventoryFlag = 0;
                if (inventory[i] == 0) {
                    cout << "You have collected a Backpack. Upon opening the bag, you see a wrinkled " << endl;
                    cout << "guard uniform. You then put it on because it seemed like a good idea." << endl << endl;
                    inventory[i] = backpack;
                    inventoryFlag = 1;
                    cin >> action;
                    break;
                }
            }

            if (inventoryFlag == 0)  {                                                                      // If the inventory is filled, asks the user which slot they want to replace
                Inventory(inventory);
                cout << "Which slot in your inventory do you want to replace with this item (Enter 1-7)?" << endl;
                do  {
                    cin >> inventorySwap;
                    if (inventorySwap >= 1 && inventorySwap <= 7)  {            // Checks to make sure the inputed inventory slot is a valid slot
                        cout << "You have collected a Backpack. Upon opening the bag, you see a wrinkled " << endl;
                        cout << "guard uniform. You then put it on because it seemed like a good idea." << endl << endl;
                        inventory[inventorySwap - 1] = backpack;
                        cin >> action;
                    }
                    else {
                        cout << "Enter a valid inventory slot" << endl << endl;
                    }
                } while (inventorySwap < 1 || inventorySwap > 7);
            }

        }
        else if (action == "pickup_revolver" || action == "pickup_Revolver") {  // Initiates picking up the Revolver

            for (int i = 0; i < 7; i++){                                      // Puts the item into the players first open inventory slot
                inventoryFlag = 0;
                if (inventory[i] == 0) {
                    cout << "You have collected a Revolver" << endl << endl;
                    inventory[i] = revolver;
                    inventoryFlag = 1;
                    cin >> action;
                    break;
                }
            }

            if (inventoryFlag == 0)  {                                                                     // If the inventory is filled, asks the user which slot they want to replace
                Inventory(inventory);
                cout << "Which slot in your inventory do you want to replace with this item?" << endl;
                do  {
                    cin >> inventorySwap;
                    if (inventorySwap >= 1 && inventorySwap <= 7)  {            // Checks to make sure the inputed inventory slot is valid
                        cout << "You have collected a Revolver" << endl << endl;
                        inventory[inventorySwap - 1] = revolver;
                        cin >> action;
                    }
                    else {
                        cout << "Enter a valid inventory slot" << endl << endl;
                    }
                } while (inventorySwap < 1 || inventorySwap > 7);
            }
        }
        else if (action == "inventory") {                                       // Shows the player their current inventory
            Inventory(inventory);
            cin >> action;
            }

        else if (action == "controls") {                                        // Displays control panel to the user
            Controls();
            cin >> action;
        }

        else if (action == "a" || action == "A"){                                    // Player looks at the west wall
            moveCount++;
            if (randGaurdAlert == moveCount){
                cout << "While walking through the office, you accidentally pressed a panic button" << endl;       // Player triggers guard and warns them to get out of the room
                cout << "sounding an alarm, but you quickly turn it off. Luckily, you didn't leave it" << endl;
                cout << "on long enough to cause too much panic, but guards are now on alert. Hurry!" << endl << endl;
            }
            else if (moveCount == 7) {
                return "lose";
            }
            cout << "On the west wall, you see windows looking out over the lanscape." << endl << endl;                                    // Description of the west wall

            do  {
                cin >> action;
                if (action == "use_id_card" || action == "use_blanket" || action == "use_plastic_spoon" || action == "use_food_tray" || action == "use_scissors" || action == "use_backpack" || action == "use_cell_phone" || action == "use_candle" || action == "use_wrench" || action == "use_soap" || action == "use_rope" || action == "use_flashlight" || action == "use_paperclip")  {
                    cout << "That item cannot be used here" << endl;
                }
                else if (action == "use_revolver") {
                    cout << "You try to use the revolver and break the window, but you have no ammuntion" << endl;
                }
                else if (action != "w" || action != "W" || action != "a" || action != "A" || action != "s" || action != "S" || action != "d" || action != "D") {
                    break;
                }
            } while (1);
        }
        else if (action == "s" || action == "S"){                               // Player looks at the south wall
            moveCount++;
            if (randGaurdAlert == moveCount){
                cout << "While walking through the office, you accidentally pressed a panic button" << endl;       // Player triggers guard and warns them to get out of the room
                cout << "sounding an alarm, but you quickly turn it off. Luckily, you didn't leave it" << endl;
                cout << "on long enough to cause too much panic, but guards are now on alert. Hurry!" << endl << endl;
            }
            else if (moveCount == 7) {
                return "lose";
            }
            cout << "On the south wall, you see a wall of bookshelves and file cabinets. In the" << endl;            // Description of the south wall
            cout << "bottom corner of the wall you see an oversized air vent." << endl << endl;


            do  {
                cin >> action;
                if (action == "use_wrench" && (inventory[0] == 3 || inventory[1] == 3 || inventory[2] == 3 || inventory[3] == 3 || inventory[4] == 3 || inventory[5] == 3 || inventory[6] == 3))   {
                    cout << endl << "You have successfully used the wrench to get through the air vent. " << endl;
                    return "breakRoom";       // Returns the new location of the player
                }
                else if (action == "use_blanket" || action == "use_plastic_spoon" || action == "use_food_tray" || action == "use_scissors" || action == "use_revolver" || action == "use_backpack" || action == "use_cell_phone" || action == "use_candle" || action == "use_id_card" || action == "use_soap" || action == "use_rope" || action == "use_flashlight" || action == "use_paperclip") {
                    cout << "That item cannot be used here" << endl;
                }
                else if (action != "w" || action != "W" || action != "a" || action != "A" || action != "s" || action != "S" || action != "d" || action != "D") {
                    break;
                }
            } while(1);
        }
        else if (action == "w" || action == "W"){                               // Player looks at the north wall
            moveCount++;
            if (randGaurdAlert == moveCount){
                cout << "While walking through the office, you accidentally pressed a panic button" << endl;       // Player triggers guard and warns them to get out of the room
                cout << "sounding an alarm, but you quickly turn it off. Luckily, you didn't leave it" << endl;
                cout << "on long enough to cause too much panic, but guards are now on alert. Hurry!" << endl << endl;
            }
            else if (moveCount == 7) {
                return "lose";
            }
            cout << "On the north wall, you see a bookshelf and a dumbwaiter without anything to lower yourself" << endl << endl;            // Description of the north wall

            do  {
                cin >> action;
                if (action == "use_rope" && (inventory[0] == 4 || inventory[1] == 4 || inventory[2] == 4 || inventory[3] == 4 || inventory[4] == 4 || inventory[5] == 4 || inventory[6] == 4))   {
                    cout << endl << "You used the rope to descend the dumbwaiter" << endl;
                    return "Kitchen";      // Returns the new location of the player
                }
                else if (action == "use_blanket" || action == "use_plastic_spoon" || action == "use_food_tray" || action == "use_scissors" || action == "use_revolver" || action == "use_backpack" || action == "use_cell_phone" || action == "use_candle" || action == "use_wrench" || action == "use_soap" || action == "use_id_card" || action == "use_flashlight" || action == "use_paperclip") {
                    cout << "That item cannot be used here" << endl;
                }
                else if (action != "w" || action != "W" || action != "a" || action != "A" || action != "s" || action != "S" || action != "d" || action != "D") {
                    break;
                }
            } while(1);
        }
        else if (action == "d" || action == "D"){                               // Player looks at the east wall
            moveCount++;
            if (randGaurdAlert == moveCount){
                cout << "While walking through the office, you accidentally pressed a panic button" << endl;       // Player triggers guard and warns them to get out of the room
                cout << "sounding an alarm, but you quickly turn it off. Luckily, you didn't leave it" << endl;
                cout << "on long enough to cause too much panic, but guards are now on alert. Hurry!" << endl << endl;
            }
            else if (moveCount == 7) {
                return "lose";
            }
            cout << "On the east wall, you see an open wall with a large mural of the prison from the outside." << endl << endl;                                    // Description of the east wall

            do  {
                cin >> action;
                if (action == "use_id_card" || action == "use_blanket" || action == "use_plastic_spoon" || action == "use_food_tray" || action == "use_scissors" || action == "use_revolver" || action == "use_backpack" || action == "use_cell_phone" || action == "use_candle" || action == "use_wrench" || action == "use_soap" || action == "use_rope" || action == "use_flashlight" || action == "use_paperclip")  {
                    cout << "That item cannot be used here" << endl;
                }
                else if (action != "w" || action != "W" || action != "a" || action != "A" || action != "s" || action != "S" || action != "d" || action != "D") {
                    break;
                }
            } while (1);
        }

        else {                                                              // Checks the users input statement to see if it is valid
            cout << "That is not a valid command / Invalid Order of Commands" << endl;
            cin >> action;
        }

        } while  (location == "wardensOffice");
    }
}

/* Function Name: Kitchen
 *
 * Function Description:
 * This function preforms all the actions needed that the player can make within
 * this room
 *
 * Parameters:
 * The (&inventory)[7] parameter is the array of integers that corresponds
 * to what items the player has at that time
 * The &kitchenCnt parameter keeps track of how many times they've been in this room
 * The &location parameter passes in the string location variable which is used in main
 *
 * return value:
 * string (This value gets assigned to the updated location variable in main which will call the new room function)
 */

string Kitchen(int (&inventory)[7], int &kitchenCnt, string &location){
    string action = "";
    string useItem;
    int inventoryFlag = 0;
    int scissors = 7;
    int food_tray = 13;
    int inventorySwap;
    int moveCount = 0;
    int randGaurdAlert = rand() % 3 + 4;


    cout << endl << "You are in the Kitchen" << endl << endl;

    if (kitchenCnt == 0){                                                  // Gives detailed description of the room first time the player enters the room
        cout << "You have succesfully made it into the Kitchen. Nobody is in the" << endl;
        cout << "room so you flip the lightswitch in order to look around. As you go through the kitchen, it" << endl;
        cout << "seems like the cooks have already cleaned up and locked everything away. While looking for" << endl;
        cout << "an escape rout you open a cabinet and see a food_tray and some scissors. Who knows..." << endl;
        cout << "maybe they'll be useful." << endl << endl;

        kitchenCnt++;
    }

    if (kitchenCnt != 0) {                                                 // Gives no detailed description any other time the player enters the room
        cin >> action;
        do {

            cout << endl;

        if (action == "pickup_scissors" || action == "pickup_Scissors"){                            // Initiates picking up the Scissors

            for (int i = 0; i < 7; i++){                                // Puts the item into the players first open inventory slot
                inventoryFlag = 0;
                if (inventory[i] == 0) {
                    cout << "You have collected a pair of scissors" << endl << endl;
                    inventory[i] = scissors;
                    inventoryFlag = 1;
                    cin >> action;
                    break;
                }
            }

            if (inventoryFlag == 0)  {                                                                      // If the inventory is filled, asks the user which slot they want to replace
                Inventory(inventory);
                cout << "Which slot in your inventory do you want to replace with this item (Enter 1-7)?" << endl;
                do  {
                    cin >> inventorySwap;
                    if (inventorySwap >= 1 && inventorySwap <= 7)  {            // Checks to make sure the inputed inventory slot is a valid slot
                        cout << "You have collected aa pair of scissors" << endl << endl;
                        inventory[inventorySwap - 1] = scissors;
                        cin >> action;
                    }
                    else {
                        cout << "Enter a valid inventory slot" << endl << endl;
                    }
                } while (inventorySwap < 1 || inventorySwap > 7);
            }

        }
        else if (action == "pickup_food_tray" || action == "pickup_Food_Tray") {                    // Initiates picking up the food tray

            for (int i = 0; i < 7; i++){                                                            // Puts the item into the players first open inventory slot
                inventoryFlag = 0;
                if (inventory[i] == 0) {
                    cout << "You have collected a Food Tray" << endl << endl;
                    inventory[i] = food_tray;
                    inventoryFlag = 1;
                    cin >> action;
                    break;
                }
            }

            if (inventoryFlag == 0)  {                                                              // If the inventory is filled, asks the user which slot they want to replace
                Inventory(inventory);
                cout << "Which slot in your inventory do you want to replace with this item?" << endl;
                do  {
                    cin >> inventorySwap;
                    if (inventorySwap >= 1 && inventorySwap <= 7)  {                                // Checks to make sure the inputed inventory slot is valid
                        cout << "You have collected a Food Tray" << endl << endl;
                        inventory[inventorySwap - 1] = food_tray;
                        cin >> action;
                    }
                    else {
                        cout << "Enter a valid inventory slot" << endl << endl;
                    }
                } while (inventorySwap < 1 || inventorySwap > 7);
            }
        }
        else if (action == "inventory") {                                       // Shows the player their current inventory
            Inventory(inventory);
            cin >> action;
            }

        else if (action == "controls") {                                        // Displays control panel to the user
            Controls();
            cin >> action;
        }

        else if (action == "a" || action == "A"){                               // Player looks at the west wall
            moveCount++;
            if (randGaurdAlert == moveCount){
                cout << "While searching through the kitchen, you hear a guard outside one of the doors." << endl;       // Player triggers guard and warns them to get out of the room
                cout << "You aren't sure if he knows you are inside but he is likely to come in soon!" << endl << endl;
            }
            else if (moveCount == 7) {
                return "lose";
            }
            cout << "On the west wall, you see large oven doors and a prep area for food." << endl << endl;                        // Description of the west wall

            do  {
                cin >> action;
                if (action == "use_id_card" || action == "use_blanket" || action == "use_plastic_spoon" || action == "use_food_tray" || action == "use_scissors" || action == "use_revolver" || action == "use_backpack" || action == "use_cell_phone" || action == "use_candle" || action == "use_wrench" || action == "use_soap" || action == "use_rope" || action == "use_flashlight" || action == "use_paperclip")  {
                    cout << "That item cannot be used here" << endl;
                }
                else if (action != "w" || action != "W" || action != "a" || action != "A" || action != "s" || action != "S" || action != "d" || action != "D") {
                    break;
                }
            } while (1);
        }
        else if (action == "s" || action == "S"){                               // Player looks at the south wall
            moveCount++;
            if (randGaurdAlert == moveCount){
                cout << "While searching through the kitchen, you hear a guard outside one of the doors." << endl;       // Player triggers guard and warns them to get out of the room
                cout << "You aren't sure if he knows you are inside but he is likely to come in soon!" << endl << endl;
            }
            else if (moveCount == 7) {
                return "lose";
            }
            cout << "On the south wall, you see shelves with a variey of cooking supplies and" << endl;            // Description of the south wall
            cout << "a small square opening in the wall. After inspecting it more closely, you" << endl;
            cout << "realize it is a dubwaiter leading down, and just big enough to fit a person." << endl;
            cout << "Though, it seems to be missing something. If only you had something to pull" << endl;
            cout << "yourself down" << endl << endl;

            do  {
                cin >> action;
                if (action == "use_rope" && (inventory[0] == 4 || inventory[1] == 4 || inventory[2] == 4 || inventory[3] == 4 || inventory[4] == 4 || inventory[5] == 4 || inventory[6] == 4))   {
                    cout << endl << "You used the rope to climb up the dumbwaiter" << endl;
                    return "wardensOffice";       // Returns the new location of the player
                }
                else if (action == "use_blanket" || action == "use_plastic_spoon" || action == "use_food_tray" || action == "use_scissors" || action == "use_revolver" || action == "use_backpack" || action == "use_cell_phone" || action == "use_candle" || action == "use_wrench" || action == "use_soap" || action == "use_id_card" || action == "use_flashlight" || action == "use_paperclip") {
                    cout << "That item cannot be used here" << endl;
                }
                else if (action != "w" || action != "W" || action != "a" || action != "A" || action != "s" || action != "S" || action != "d" || action != "D") {
                    break;
                }
            } while(1);
        }
        else if (action == "w" || action == "W"){                               // Player looks at the north wall
            moveCount++;
            if (randGaurdAlert == moveCount){
                cout << "While searching through the kitchen, you hear a guard outside one of the doors." << endl;       // Player triggers guard and warns them to get out of the room
                cout << "You aren't sure if he knows you are inside but he is likely to come in soon!" << endl << endl;
            }
            else if (moveCount == 7) {
                return "lose";
            }
            cout << "On the west wall, you see chest freezers, stove tops, refrigerators, and other common" << endl;                        // Description of the north wall
            cout << "kitchen appliances. Unless you can move through walls, this doesn't look like your best bet" << endl << endl;


            do  {
                cin >> action;
                if (action == "use_id_card" || action == "use_blanket" || action == "use_plastic_spoon" || action == "use_food_tray" || action == "use_scissors" || action == "use_revolver" || action == "use_backpack" || action == "use_cell_phone" || action == "use_candle" || action == "use_wrench" || action == "use_soap" || action == "use_rope" || action == "use_flashlight" || action == "use_paperclip")  {
                    cout << "That item cannot be used here" << endl;
                }
                else if (action != "w" || action != "W" || action != "a" || action != "A" || action != "s" || action != "S" || action != "d" || action != "D") {
                    break;
                }
            } while (1);
        }
        else if (action == "d" || action == "D"){                               // Player looks at the east wall
            moveCount++;
            if (randGaurdAlert == moveCount){
                cout << "While searching through the kitchen, you hear a guard outside one of the doors." << endl;       // Player triggers guard and warns them to get out of the room
                cout << "You aren't sure if he knows you are inside but he is likely to come in soon!" << endl << endl;
            }
            else if (moveCount == 7) {
                return "lose";
            }
            cout << "On the east wall, you see a door leading out of the kitchen. It is an old looking" << endl;            // Description of the east wall
            cout << "door that has a classic picklock under the handle" << endl << endl;

            do  {
                cin >> action;
                if (action == "use_paperclip" && (inventory[0] == 1 || inventory[1] == 1 || inventory[2] == 1 || inventory[3] == 1 || inventory[4] == 1 || inventory[5] == 1 || inventory[6] == 1))   {
                    cout << endl << "You picked the lock using the paperclip" << endl;
                    return "messHall";       // Returns the new location of the player
                }
                else if (action == "use_blanket" || action == "use_plastic_spoon" || action == "use_food_tray" || action == "use_scissors" || action == "use_revolver" || action == "use_backpack" || action == "use_cell_phone" || action == "use_candle" || action == "use_wrench" || action == "use_soap" || action == "use_id_card" || action == "use_flashlight" || action == "use_paperclip") {
                    cout << "That item cannot be used here" << endl;
                }
                else if (action != "w" || action != "W" || action != "a" || action != "A" || action != "s" || action != "S" || action != "d" || action != "D") {
                    break;
                }
            } while(1);
        }

        else {                                                              // Checks the users input statement to see if it is valid
            cout << "That is not a valid command / Invalid Order of Commands" << endl;
            cin >> action;
        }

        } while  (location == "Kitchen");
    }
}

/* Function Name: Storage
 *
 * Function Description:
 * This function preforms all the actions needed that the player can make within
 * this room
 *
 * Parameters:
 * The (&inventory)[7] parameter is the array of integers that corresponds
 * to what items the player has at that time
 * The &storageCnt parameter keeps track of how many times they've been in this room
 * The &location parameter passes in the string location variable which is used in main
 *
 * return value:
 * string (This value gets assigned to the updated location variable in main which will call the new room function)
 */

string Storage(int (&inventory)[7], int &storageCnt, string &location){
    string action = "";
    string useItem;
    int inventoryFlag = 0;
    int flashlight = 5;
    int rope = 4;
    int inventorySwap;
    int moveCount = 0;
    int randGaurdAlert = rand() % 3 + 4;


    cout << endl << "You are in the Storage Room" << endl << endl;

    if (storageCnt == 0){                                                  // Gives detailed description of the room first time the player enters the room
        cout << "Looking around the room, you see shelves, storage bins, and various mechanical supplies." << endl;
        cout << "Unfortunately, almost all the useful supplies are locked securely away, however, there is one." << endl;
        cout << "unlocked bin in the corner. Opening the bin, you see it contains a black, cylindrical object with" << endl;
        cout << "with a button. At one end of the object, it has a circle layer of glass. You also see a rope." << endl << endl;

        storageCnt++;
    }

    if (storageCnt != 0) {                                                 // Gives no detailed description any other time the player enters the room
        cin >> action;
        do {

            cout << endl;

        if (action == "pickup_rope" || action == "pickup_Rope"){  // Initiates picking up the rope

            for (int i = 0; i < 7; i++){                                // Puts the item into the players first open inventory slot
                inventoryFlag = 0;
                if (inventory[i] == 0) {
                    cout << "You have collected a rope" << endl << endl;
                    inventory[i] = rope;
                    inventoryFlag = 1;
                    cin >> action;
                    break;
                }
            }

            if (inventoryFlag == 0)  {                                                                      // If the inventory is filled, asks the user which slot they want to replace
                Inventory(inventory);
                cout << "Which slot in your inventory do you want to replace with this item (Enter 1-7)?" << endl;
                do  {
                    cin >> inventorySwap;
                    if (inventorySwap >= 1 && inventorySwap <= 7)  {            // Checks to make sure the inputed inventory slot is a valid slot
                        cout << "You have collected a rope" << endl << endl;
                        inventory[inventorySwap - 1] = rope;
                        cin >> action;
                    }
                    else {
                        cout << "Enter a valid inventory slot" << endl << endl;
                    }
                } while (inventorySwap < 1 || inventorySwap > 7);
            }

        }
        else if (action == "pickup_flashlight" || action == "pickup_Flashlight") {  // Initiates picking up the flashlight

            for (int i = 0; i < 7; i++){                                      // Puts the item into the players first open inventory slot
                inventoryFlag = 0;
                if (inventory[i] == 0) {
                    cout << "You have collected a flashlight" << endl << endl;
                    inventory[i] = flashlight;
                    inventoryFlag = 1;
                    cin >> action;
                    break;
                }
            }

            if (inventoryFlag == 0)  {                                                                     // If the inventory is filled, asks the user which slot they want to replace
                Inventory(inventory);
                cout << "Which slot in your inventory do you want to replace with this item?" << endl;
                do  {
                    cin >> inventorySwap;
                    if (inventorySwap >= 1 && inventorySwap <= 7)  {            // Checks to make sure the inputed inventory slot is valid
                        cout << "You have collected a flashlight" << endl << endl;
                        inventory[inventorySwap - 1] = flashlight;
                        cin >> action;
                    }
                    else {
                        cout << "Enter a valid inventory slot" << endl << endl;
                    }
                } while (inventorySwap < 1 || inventorySwap > 7);
            }
        }
        else if (action == "inventory") {                                       // Shows the player their current inventory
            Inventory(inventory);
            cin >> action;
            }

        else if (action == "controls") {                                        // Displays control panel to the user
            Controls();
            cin >> action;
        }

        else if (action == "a" || action == "A"){                                    // Player looks at the west wall
            moveCount++;
            if (randGaurdAlert == moveCount){
                cout << "You stub your toe against one of the bins, emitting a loud yelp that echos through the vents." << endl;       // Player triggers guard and warns them to get out of the room
                cout << "One of the guards surely heard the yelp, you better get going before he comes!" << endl << endl;
            }
            else if (moveCount == 7) {
                return "lose";
            }
            cout << "The west wall is covered soley with locked file cabinets." << endl << endl;                                    // Description of the west wall

            do  {
                cin >> action;
                if (action == "use_paperclip"){
                    cout << endl << "You opened the file cabinet with the paperclip, and inside you see a flashlight" << endl;
                }
                else if (action == "use_id_card" || action == "use_blanket" || action == "use_plastic_spoon" || action == "use_food_tray" || action == "use_scissors" || action == "use_revolver" || action == "use_backpack" || action == "use_cell_phone" || action == "use_candle" || action == "use_wrench" || action == "use_soap" || action == "use_rope" || action == "use_flashlight")  {
                    cout << "That item cannot be used here" << endl;
                }
                else if (action != "w" || action != "W" || action != "a" || action != "A" || action != "s" || action != "S" || action != "d" || action != "D") {
                    break;
                }
            } while (1);
        }
        else if (action == "s" || action == "S"){                               // Player looks at the south wall
            moveCount++;
            if (randGaurdAlert == moveCount){
                cout << "You stub your toe against one of the bins, emitting a loud yelp that echos through the vents." << endl;       // Player triggers guard and warns them to get out of the room
                cout << "One of the guards surely heard the yelp, you better get going before he comes!" << endl << endl;
            }
            else if (moveCount == 7) {
                return "lose";
            }
            cout << "On the south wall, you see a locked door, but this one is different then the others." << endl;            // Description of the south wall
            cout << "Looking down, you see the open grate you came through. Would you like to go back?" << endl;


            do  {
                cin >> action;
                if (action == "yes" || action == "y")  {
                    cout << endl << "You began down into the open grate" << endl;
                    return "Showers";
                }
                else if (action == "no" || action == "n")  {
                    cout << endl << "Whats your next move?" << endl;
                    cin >> action;
                    break;
                }
                else if (action == "use_blanket" || action == "use_plastic_spoon" || action == "use_food_tray" || action == "use_scissors" || action == "use_revolver" || action == "use_backpack" || action == "use_cell_phone" || action == "use_candle" || action == "use_wrench" || action == "use_soap" || action == "use_rope" || action == "use_flashlight" || action == "use_paperclip") {
                    cout << "That item cannot be used here" << endl;
                }
                else if (action != "w" || action != "W" || action != "a" || action != "A" || action != "s" || action != "S" || action != "d" || action != "D") {
                    break;
                }
            } while(1);
        }
        else if (action == "w" || action == "W"){                               // Player looks at the north wall
            moveCount++;
            if (randGaurdAlert == moveCount){
                cout << "You stub your toe against one of the bins, emitting a loud yelp that echos through the vents." << endl;       // Player triggers guard and warns them to get out of the room
                cout << "One of the guards surely heard the yelp, you better get going before he comes!" << endl << endl;
            }
            else if (moveCount == 7) {
                return "lose";
            }
            cout << "The north wall is covered with various sized bins, along with some shelves containing cleaning supplies." << endl << endl;                                    // Description of the west wall

            do  {
                cin >> action;
                if (action == "use_id_card" || action == "use_blanket" || action == "use_plastic_spoon" || action == "use_food_tray" || action == "use_scissors" || action == "use_revolver" || action == "use_backpack" || action == "use_cell_phone" || action == "use_candle" || action == "use_wrench" || action == "use_soap" || action == "use_rope" || action == "use_flashlight" || action == "use_paperclip")  {
                    cout << "That item cannot be used here" << endl;
                }
                else if (action != "w" || action != "W" || action != "a" || action != "A" || action != "s" || action != "S" || action != "d" || action != "D") {
                    break;
                }
            } while (1);
        }
        else if (action == "d" || action == "D"){                               // Player looks at the east wall
            moveCount++;
            if (randGaurdAlert == moveCount){
                cout << "You stub your toe against one of the bins, emitting a loud yelp that echos through the vents." << endl;       // Player triggers guard and warns them to get out of the room
                cout << "One of the guards surely heard the yelp, you better get going before he comes!" << endl << endl;
            }
            else if (moveCount == 7) {
                return "lose";
            }
            cout << "On the east wall, numerous mechanical parts and machines can be found." << endl << endl;                                    // Description of the east wall

            do  {
                cin >> action;
                if (action == "use_id_card" || action == "use_blanket" || action == "use_plastic_spoon" || action == "use_food_tray" || action == "use_scissors" || action == "use_revolver" || action == "use_backpack" || action == "use_cell_phone" || action == "use_candle" || action == "use_wrench" || action == "use_soap" || action == "use_rope" || action == "use_flashlight" || action == "use_paperclip")  {
                    cout << "That item cannot be used here" << endl;
                }
                else if (action != "w" || action != "W" || action != "a" || action != "A" || action != "s" || action != "S" || action != "d" || action != "D") {
                    break;
                }
            } while (1);
        }

        else {                                                              // Checks the users input statement to see if it is valid
            cout << "That is not a valid command / Invalid Order of Commands" << endl;
            cin >> action;
        }

        } while  (location == "Storage");
    }
}

/* Function Name: breakRoom
 *
 * Function Description:
 * This function preforms all the actions needed that the player can make within
 * this room
 *
 * Parameters:
 * The (&inventory)[7] parameter is the array of integers that corresponds
 * to what items the player has at that time
 * The &breakRoomCnt parameter keeps track of how many times they've been in this room
 * The &location parameter passes in the string location variable which is used in main
 *
 * return value:
 * string (This value gets assigned to the updated location variable in main which will call the new room function)
 */

string breakRoom(int (&inventory)[7], int &breakRoomCnt, string &location){
    string action = "";
    string useItem;
    int inventoryFlag = 0;
    int cell_phone = 14;
    int inventorySwap;
    int moveCount = 0;
    int randGaurdAlert = rand() % 3 + 4;


    cout << endl << "You are in the Guards Break Room" << endl << endl;

    if (breakRoomCnt == 0){                                                  // Gives detailed description of the room first time the player enters the room
        cout << "You successfully entered the guards break room, where you see lots of ." << endl;
        cout << "donuts and coffee. Scattered around the room are various personal belongings " << endl;
        cout << "of the guards. Most of them seem useless, and only have value to the guard that " << endl;
        cout << "owns the item, however, out of the corner of your eye you see the reflection " << endl;
        cout << "of a cell_phone screen." << endl;

        breakRoomCnt++;
    }

    if (breakRoomCnt != 0) {                                                 // Gives no detailed description any other time the player enters the room
        cin >> action;
        do {

            cout << endl;

        if (action == "pickup_cell_phone"){  // Initiates picking up the Cell Phone

            for (int i = 0; i < 7; i++){                                // Puts the item into the players first open inventory slot
                inventoryFlag = 0;
                if (inventory[i] == 0) {
                    cout << "You have collected a Cell Phone" << endl << endl;
                    inventory[i] = cell_phone;
                    inventoryFlag = 1;
                    cin >> action;
                    break;
                }
            }

            if (inventoryFlag == 0)  {                                                                      // If the inventory is filled, asks the user which slot they want to replace
                Inventory(inventory);
                cout << "Which slot in your inventory do you want to replace with this item (Enter 1-7)?" << endl;
                do  {
                    cin >> inventorySwap;
                    if (inventorySwap >= 1 && inventorySwap <= 7)  {            // Checks to make sure the inputed inventory slot is a valid slot
                        cout << "You have collected an Cell Phone" << endl << endl;
                        inventory[inventorySwap - 1] = cell_phone;
                        cin >> action;
                    }
                    else {
                        cout << "Enter a valid inventory slot" << endl << endl;
                    }
                } while (inventorySwap < 1 || inventorySwap > 7);
            }

        }
        else if (action == "inventory") {                                       // Shows the player their current inventory
            Inventory(inventory);
            cin >> action;
            }

        else if (action == "controls") {                                        // Displays control panel to the user
            Controls();
            cin >> action;
        }

        else if (action == "a" || action == "A"){                                    // Player looks at the west wall
            moveCount++;
            if (randGaurdAlert == moveCount){
                cout << "As you are searching the room you trip over a chair and fall into " << endl;       // Player triggers guard and warns them to get out of the room
                cout << "the vending machine. Somehow you manage to hit every button and food " << endl;
                cout << "starts crashing to the bottom of a machine. The food is really loud and now you " << endl;
                cout << "are afraid a prison guard heard you. He is likely on his way now!" << endl << endl;
            }
            else if (moveCount == 7) {
                return "lose";
            }
            cout << "On the west wall, you see a couch, a coat rack, and a coffee machine. There doesn't ." << endl << endl;      // Description of the west wall
            cout << "seem to be anything of use on the counter, or in the couch cushions." << endl << endl;

            do  {
                cin >> action;
                if (action != "w" || action != "W" || action != "a" || action != "A" || action != "s" || action != "S" || action != "d" || action != "D") {
                    break;
                }
            } while (1);
        }
        else if (action == "s" || action == "S"){                               // Player looks at the south wall
            moveCount++;
            if (randGaurdAlert == moveCount){
                cout << "As you are searching the room you trip over a chair and fall into " << endl;       // Player triggers guard and warns them to get out of the room
                cout << "the vending machine. Somehow you manage to hit every button and food " << endl;
                cout << "starts crashing to the bottom of a machine. The food is really loud and now you " << endl;
                cout << "are afraid a prison guard heard you. He is likely on his way now!" << endl << endl;
            }
            else if (moveCount == 7) {
                return "lose";
            }
            cout << "On the south wall, you see a tv. The rerun of the 1976 Reds world series game is on." << endl;            // Description of the south wall
            cout << "Underneth the tv, there a tv stand which has a remote on top of it." << endl;

            do  {
                cin >> action;
                if (action != "w" || action != "W" || action != "a" || action != "A" || action != "s" || action != "S" || action != "d" || action != "D") {
                    break;
                }
            } while(1);
        }
        else if (action == "w" || action == "W"){                               // Player looks at the north wall
            moveCount++;
            if (randGaurdAlert == moveCount){
                cout << "As you are searching the room you trip over a chair and fall into " << endl;       // Player triggers guard and warns them to get out of the room
                cout << "the vending machine. Somehow you manage to hit every button and food " << endl;
                cout << "starts crashing to the bottom of a machine. The food is really loud and now you " << endl;
                cout << "are afraid a prison guard heard you. He is likely on his way now!" << endl << endl;
            }
            else if (moveCount == 7) {
                return "lose";
            }
            cout << "On the north wall, you see nothing but the holes from the guards throwing darts. " << endl;            // Description of the north wall
            cout << "After scanning the wall for something useful, you look up to the ceiling and notce . " << endl;
            cout << "a large air vent. Maybe theres a way to pull yourself up into it and crawl around." << endl;

            do  {
                cin >> action;
                if (action == "use_rope" && (inventory[0] == 4 || inventory[1] == 4 || inventory[2] == 4 || inventory[3] == 4 || inventory[4] == 4 || inventory[5] == 4 || inventory[6] == 4))   {
                    cout << endl << "You used the rope to pull yourself up into the vent and began to crawl" << endl;
                    return "wardensOffice";      // Returns the new location of the player
                }
                else if (action == "use_blanket" || action == "use_plastic_spoon" || action == "use_food_tray" || action == "use_scissors" || action == "use_revolver" || action == "use_backpack" || action == "use_cell_phone" || action == "use_candle" || action == "use_rope" || action == "use_soap" || action == "use_id_card" || action == "use_flashlight" || action == "use_paperclip") {
                    cout << "That item cannot be used here" << endl;
                }
                else if (action != "w" || action != "W" || action != "a" || action != "A" || action != "s" || action != "S" || action != "d" || action != "D") {
                    break;
                }
            } while(1);
        }
        else if (action == "d" || action == "D"){                               // Player looks at the east wall
            moveCount++;
            if (randGaurdAlert == moveCount){
                cout << "As you are searching the room you trip over a chair and fall into " << endl;       // Player triggers guard and warns them to get out of the room
                cout << "the vending machine. Somehow you manage to hit every button and food " << endl;
                cout << "starts crashing to the bottom of a machine. The food is really loud and now you " << endl;
                cout << "are afraid a prison guard heard you. He is likely on his way now!" << endl << endl;
            }
            else if (moveCount == 7) {
                return "lose";
            }
            cout << "On the east wall, you see a closed door that resembled the high tech door in the cell block." << endl << endl;                                    // Description of the east wall

            do  {
                cin >> action;
                if (action == "use_id_card" && (inventory[0] == 2 || inventory[1] == 2 || inventory[2] == 2 || inventory[3] == 2 || inventory[4] == 2 || inventory[5] == 2 || inventory[6] == 2))   {
                    cout << endl << "You use the id_card to get through the door" << endl;
                    return "wardensOffice";      // Returns the new location of the player
                }
                else if (action == "use_blanket" || action == "use_plastic_spoon" || action == "use_food_tray" || action == "use_scissors" || action == "use_revolver" || action == "use_backpack" || action == "use_cell_phone" || action == "use_candle" || action == "use_rope" || action == "use_soap" || action == "use_wrench" || action == "use_flashlight" || action == "use_paperclip") {
                    cout << "That item cannot be used here" << endl;
                }
                else if (action != "w" || action != "W" || action != "a" || action != "A" || action != "s" || action != "S" || action != "d" || action != "D") {
                    break;
                }
            } while(1);
        }

        else {                                                              // Checks the users input statement to see if it is valid
            cout << "That is not a valid command / Invalid Order of Commands" << endl;
            cin >> action;
        }

        } while  (location == "breakRoom");
    }
}

/* Function Name: Library
 *
 * Function Description:
 * This function preforms all the actions needed that the player can make within
 * this room
 *
 * Parameters:
 * The (&inventory)[7] parameter is the array of integers that corresponds
 * to what items the player has at that time
 * The &libraryCnt parameter keeps track of how many times they've been in this room
 * The &location parameter passes in the string location variable which is used in main
 *
 * return value:
 * string (This value gets assigned to the updated location variable in main which will call the new room function)
 */

string Library(int (&inventory)[7], int &libraryCnt, string &location){
    string action = "";
    string useItem;
    int inventoryFlag = 0;
    int candle = 15;
    int inventorySwap;
    int moveCount = 0;
    int randGaurdAlert = rand() % 3 + 4;


    cout << endl << "You are in the Library" << endl << endl;

    if (libraryCnt == 0){                                                  // Gives detailed description of the room first time the player enters the room
        cout << "You look around the dimly lit room. At first glance you notice very little as your eyes" << endl;
        cout << "adjust to the new lighting. Its a lot different then the cell block. Around the room are" << endl;
        cout << "scattered tables with some chairs. After feeling one of the tables, you notice its charred from a candle." << endl;
        cout << "Also, down one of the isles of books, a mysterious shadow catches your eye. Maybe this room will be useful." << endl << endl;

        libraryCnt++;
    }

    if (libraryCnt != 0) {                                                 // Gives no detailed description any other time the player enters the room
        cin >> action;
        do {

            cout << endl;

        if (action == "pickup_candle"){  // Initiates picking up the candle

            for (int i = 0; i < 7; i++){                                // Puts the item into the players first open inventory slot
                inventoryFlag = 0;
                if (inventory[i] == 0) {
                    cout << "You have collected a candle" << endl << endl;
                    inventory[i] = candle;
                    inventoryFlag = 1;
                    cin >> action;
                    break;
                }
            }

            if (inventoryFlag == 0)  {                                                                      // If the inventory is filled, asks the user which slot they want to replace
                Inventory(inventory);
                cout << "Which slot in your inventory do you want to replace with this item (Enter 1-7)?" << endl;
                do  {
                    cin >> inventorySwap;
                    if (inventorySwap >= 1 && inventorySwap <= 7)  {            // Checks to make sure the inputed inventory slot is a valid slot
                        cout << "You have collected a candle" << endl << endl;
                        inventory[inventorySwap - 1] = candle;
                        cin >> action;
                    }
                    else {
                        cout << "Enter a valid inventory slot" << endl << endl;
                    }
                } while (inventorySwap < 1 || inventorySwap > 7);
            }

        }

        else if (action == "inventory") {                                       // Shows the player their current inventory
            Inventory(inventory);
            cin >> action;
            }

        else if (action == "controls") {                                        // Displays control panel to the user
            Controls();
            cin >> action;
        }

        else if (action == "a" || action == "A"){                                    // Player looks at the west wall
            moveCount++;
            if (randGaurdAlert == moveCount){
                cout << "You accidentally bump into a bust of Colonel Mustard, ironic isn't it. That was pretty loud, and you" << endl;       // Player triggers guard and warns them to get out of the room
                cout << "are afraid a prison guard heard you. He is likely on his way now!" << endl << endl;
            }
            else if (moveCount == 7) {
                return "lose";
            }
            cout << "After turning to the west wall you quickly determine its to dark to make anything out besides there is shelves uopn" << endl;
            cout << "shelves of books. Maybe you could get better baring of the wall if you had some light." << endl << endl;                       // Description of the west wall

            do  {
                cin >> action;
                if (action == "use_flashlight" && (inventory[0] == 5 || inventory[1] == 5 || inventory[2] == 5 || inventory[3] == 5 || inventory[4] == 5 || inventory[5] == 5 || inventory[6] == 5))  {
                    cout << endl << "Using the flashlight, it reveled a book out of place. Upon pulling the book out, a secret hallway appeared, which you enter." << endl;
                    return "breakRoom";
                }
                else if (action == "use_candle" && (inventory[0] == 15 || inventory[1] == 15 || inventory[2] == 15 || inventory[3] == 15 || inventory[4] == 15 || inventory[5] == 15 || inventory[6] == 15)) {
                    cout << "It turns out the wick isnt lit, and you have no lighter. Maybe try something else." << endl;
                }
                else if (action == "use_id_card" || action == "use_blanket" || action == "use_plastic_spoon" || action == "use_food_tray" || action == "use_scissors" || action == "use_revolver" || action == "use_backpack" || action == "use_cell_phone" || action == "use_wrench" || action == "use_soap" || action == "use_rope" || action == "use_paperclip")   {
                    cout << "That item cannot be used here" << endl;
                }
                else if (action != "w" || action != "W" || action != "a" || action != "A" || action != "s" || action != "S" || action != "d" || action != "D") {
                    break;
                }
            } while (1);
        }
        else if (action == "s" || action == "S"){                               // Player looks at the south wall
            moveCount++;
            if (randGaurdAlert == moveCount){
                cout << "You accidentally bump into a bust of Colonel Mustard, ironic isn't it. That was pretty loud, and you" << endl;       // Player triggers guard and warns them to get out of the room
                cout << "are afraid a prison guard heard you. He is likely on his way now!" << endl << endl;
            }
            else if (moveCount == 7) {
                return "lose";
            }
            cout << "On the south wall, you see nothing but a baren stone surface." << endl;            // Description of the south wall
            cout << "After running your hands over the wall, you notice some posters losely hung up, " << endl;
            cout << "and some barred slits letting in moonlight at the top. Sadly they look out of reach." << endl << endl;

            do  {
                cin >> action;
                if (action == "use_id_card" || action == "use_blanket" || action == "use_plastic_spoon" || action == "use_food_tray" || action == "use_scissors" || action == "use_revolver" || action == "use_backpack" || action == "use_cell_phone" || action == "use_candle" || action == "use_wrench" || action == "use_soap" || action == "use_rope" || action == "use_flashlight" || action == "use_paperclip")   {
                    cout << "That item cannot be used here" << endl;
                }
                else if (action != "w" || action != "W" || action != "a" || action != "A" || action != "s" || action != "S" || action != "d" || action != "D") {
                    break;
                }
            } while(1);
        }
        else if (action == "w" || action == "W"){                               // Player looks at the north wall
            moveCount++;
            if (randGaurdAlert == moveCount){
                cout << "You accidentally bump into a bust of Colonel Mustard, ironic isn't it. That was pretty loud, and you" << endl;       // Player triggers guard and warns them to get out of the room
                cout << "are afraid a prison guard heard you. He is likely on his way now!" << endl << endl;
            }
            else if (moveCount == 7) {
                return "lose";
            }
            cout << "On the north wall, you see the high tech door you went through earlier." << endl;            // Description of the north wall
            cout << "Around it are some book shelves." << endl << endl;

            do  {
                cin >> action;
                if (action == "use_id_card" && (inventory[0] == 2 || inventory[1] == 2 || inventory[2] == 2 || inventory[3] == 2 || inventory[4] == 2 || inventory[5] == 2 || inventory[6] == 2))   {
                    cout << endl << "You have successfully used the id_card to get through the high tech door. " << endl;
                    return "Cell";      // Returns the new location of the player
                }
                else if (action == "use_blanket" || action == "use_plastic_spoon" || action == "use_food_tray" || action == "use_scissors" || action == "use_revolver" || action == "use_backpack" || action == "use_cell_phone" || action == "use_candle" || action == "use_wrench" || action == "use_soap" || action == "use_rope" || action == "use_flashlight" || action == "use_paperclip") {
                    cout << "That item cannot be used here" << endl;
                }
                else if (action != "w" || action != "W" || action != "a" || action != "A" || action != "s" || action != "S" || action != "d" || action != "D") {
                    break;
                }
            } while(1);
        }
        else if (action == "d" || action == "D"){                               // Player looks at the east wall
            moveCount++;
            if (randGaurdAlert == moveCount){
                cout << "You accidentally bump into a bust of Colonel Mustard, ironic isn't it. That was pretty loud, and you" << endl;       // Player triggers guard and warns them to get out of the room
                cout << "are afraid a prison guard heard you. He is likely on his way now!" << endl << endl;
            }
            else if (moveCount == 7) {
                return "lose";
            }
            cout << "One the east wall, you notice a wooden door that has been left slightly adjar. There seems ." << endl;                                    // Description of the east wall
            cout << "to be nothing blocking you from entering through it. Would you like to procceed?" << endl << endl;

            do  {
                cin >> action;
                if (action == "yes" || action == "y")  {
                    cout << endl << "You walked through the open door" << endl;
                    return "Showers";
                }
                else if (action == "no" || action == "n")  {
                    cout << endl << "Whats your next move?" << endl;
                    cin >> action;
                    break;
                }
                if (action == "use_id_card" || action == "use_blanket" || action == "use_plastic_spoon" || action == "use_food_tray" || action == "use_scissors" || action == "use_revolver" || action == "use_backpack" || action == "use_cell_phone" || action == "use_candle" || action == "use_wrench" || action == "use_soap" || action == "use_rope" || action == "use_flashlight" || action == "use_paperclip")  {
                    cout << "That item cannot be used here" << endl;
                }
                else if (action != "w" || action != "W" || action != "a" || action != "A" || action != "s" || action != "S" || action != "d" || action != "D") {
                    break;
                }
            } while (1);
        }

        else {                                                              // Checks the users input statement to see if it is valid
            cout << "That is not a valid command / Invalid Order of Commands" << endl;
            cin >> action;
        }

        } while  (location == "Library");
    }
}

/* Function Name: Showers
 *
 * Function Description:
 * This function preforms all the actions needed that the player can make within
 * this room
 *
 * Parameters:
 * The (&inventory)[7] parameter is the array of integers that corresponds
 * to what items the player has at that time
 * The &showersCnt parameter keeps track of how many times they've been in this room
 * The &location parameter passes in the string location variable which is used in main
 *
 * return value:
 * string (This value gets assigned to the updated location variable in main which will call the new room function)
 */

string Showers(int (&inventory)[7], int &showersCnt, string &location){
        string action = "";
        string useItem;
        int inventoryFlag = 0;
        int wrench = 3;
        int soap = 16;
        int inventorySwap;
        int moveCount = 0;
        int randGaurdAlert = rand() % 3 + 4;


        cout << endl << "You are in the Showers." << endl << endl;

        if (showersCnt == 0){                                                  // Gives detailed description of the room first time the player enters the room
            cout << "As soon as you enter the room, you notice the stench, " << endl;
            cout << "alomst as if it hasn't been cleaned in days. That seems funny considering the maintence cart " << endl;
            cout << "sitting off to the side of the room. You notice many tools, including a hammer, measuring_tape, and a wrench " << endl;
            cout << "on the cart. Also, someone seems to have left a bar of soap near one of the showers." << endl << endl;

            showersCnt++;
        }

        if (showersCnt != 0) {                                                 // Gives no detailed description any other time the player enters the room
            cin >> action;
            do {

                cout << endl;

            if (action == "pickup_hammer" || action == "pickup_measuring_tape"){
                cout << "Looks like this tool is broken and won't be useful" << endl;
                cin >> action;
            }

            else if (action == "pickup_wrench"){  // Initiates picking up the wrench

                for (int i = 0; i < 7; i++){                                // Puts the item into the players first open inventory slot
                    inventoryFlag = 0;
                    if (inventory[i] == 0) {
                        cout << "You have collected a wrench" << endl << endl;
                        inventory[i] = wrench;
                        inventoryFlag = 1;
                        cin >> action;
                        break;
                    }
                }

                if (inventoryFlag == 0)  {                                                                      // If the inventory is filled, asks the user which slot they want to replace
                    Inventory(inventory);
                    cout << "Which slot in your inventory do you want to replace with this item (Enter 1-7)?" << endl;
                    do  {
                        cin >> inventorySwap;
                        if (inventorySwap >= 1 && inventorySwap <= 7)  {            // Checks to make sure the inputed inventory slot is a valid slot
                            cout << "You have collected an wrench" << endl << endl;
                            inventory[inventorySwap - 1] = wrench;
                            cin >> action;
                        }
                        else {
                            cout << "Enter a valid inventory slot" << endl << endl;
                        }
                    } while (inventorySwap < 1 || inventorySwap > 7);
                }

            }
            else if (action == "pickup_soap") {  // Initiates picking up the Soap

                for (int i = 0; i < 7; i++){                                      // Puts the item into the players first open inventory slot
                    inventoryFlag = 0;
                    if (inventory[i] == 0) {
                        cout << "You have collected a bar of soap" << endl << endl;
                        inventory[i] = soap;
                        inventoryFlag = 1;
                        cin >> action;
                        break;
                    }
                }

                if (inventoryFlag == 0)  {                                                                     // If the inventory is filled, asks the user which slot they want to replace
                    Inventory(inventory);
                    cout << "Which slot in your inventory do you want to replace with this item?" << endl;
                    do  {
                        cin >> inventorySwap;
                        if (inventorySwap >= 1 && inventorySwap <= 7)  {            // Checks to make sure the inputed inventory slot is valid
                            cout << "You have collected a bar of soap" << endl << endl;
                            inventory[inventorySwap - 1] = soap;
                            cin >> action;
                        }
                        else {
                            cout << "Enter a valid inventory slot" << endl << endl;
                        }
                    } while (inventorySwap < 1 || inventorySwap > 7);
                }
            }
            else if (action == "inventory") {                                       // Shows the player their current inventory
                Inventory(inventory);
                cin >> action;
                }

            else if (action == "controls") {                                        // Displays control panel to the user
                Controls();
                cin >> action;
            }

            else if (action == "a" || action == "A"){                                    // Player looks at the west wall
                moveCount++;
                if (randGaurdAlert == moveCount){
                    cout << "As you are manuvering around the room, you accidently turn on one of the showers." << endl;       // Player triggers guard and warns them to get out of the room
                    cout << "You hear the water run through the pipes and out of the room. Now you " << endl;
                    cout << "are afraid a prison guard heard you. He is likely on his way now!" << endl << endl;
                }
                else if (moveCount == 7) {
                    return "lose";
                }
                cout << "On the west wall, you see the open door to the library. Would you like to go through?" << endl << endl;                                    // Description of the west wall

                do  {
                    cin >> action;
                    if (action == "yes" || action == "y")  {
                        cout << endl << "You walked through the open door" << endl;
                        return "Library";
                    }
                    else if (action == "no" || action == "n")  {
                        cout << endl << "Whats your next move?" << endl;
                        cin >> action;
                        break;
                    }
                    if (action == "use_id_card" || action == "use_blanket" || action == "use_plastic_spoon" || action == "use_food_tray" || action == "use_scissors" || action == "use_revolver" || action == "use_backpack" || action == "use_cell_phone" || action == "use_candle" || action == "use_wrench" || action == "use_soap" || action == "use_rope" || action == "use_flashlight" || action == "use_paperclip")  {
                        cout << "That item cannot be used here" << endl;
                    }
                    else if (action != "w" || action != "W" || action != "a" || action != "A" || action != "s" || action != "S" || action != "d" || action != "D") {
                        break;
                    }
                } while (1);
            }
            else if (action == "s" || action == "S"){                               // Player looks at the south wall
                moveCount++;
                if (randGaurdAlert == moveCount){
                    cout << "As you are manuvering around the room, you accidently turn on one of the showers." << endl;       // Player triggers guard and warns them to get out of the room
                    cout << "You hear the water run through the pipes and out of the room. Now you " << endl;
                    cout << "are afraid a prison guard heard you. He is likely on his way now!" << endl << endl;
                }
                else if (moveCount == 7) {
                    return "lose";
                }
                cout << "On the south wall, there is nothing but showers and puddles along the floor." << endl << endl;            // Description of the south wall

                do  {
                    cin >> action;
                    if (action == "use_blanket" || action == "use_plastic_spoon" || action == "use_food_tray" || action == "use_scissors" || action == "use_revolver" || action == "use_backpack" || action == "use_cell_phone" || action == "use_candle" || action == "use_wrench" || action == "use_soap" || action == "use_rope" || action == "use_flashlight" || action == "use_paperclip") {
                        cout << "That item cannot be used here" << endl;
                    }
                    else if (action != "w" || action != "W" || action != "a" || action != "A" || action != "s" || action != "S" || action != "d" || action != "D") {
                        break;
                    }
                } while(1);
            }
            else if (action == "w" || action == "W"){                               // Player looks at the north wall
                moveCount++;
                if (randGaurdAlert == moveCount){
                    cout << "As you are manuvering around the room, you accidently turn on one of the showers." << endl;       // Player triggers guard and warns them to get out of the room
                    cout << "You hear the water run through the pipes and out of the room. Now you " << endl;
                    cout << "are afraid a prison guard heard you. He is likely on his way now!" << endl << endl;
                }
                else if (moveCount == 7) {
                    return "lose";
                }
                cout << "As you peer at the north wall, you notice its very similar to the south and east walls." << endl;            // Description of the north wall
                cout << "Showers line the entire wall, however you notice its much more dry then the other walls." << endl;
                cout << "When you look down you see a large shower grate with some loose bolts, maybe it can be removed." << endl << endl;

                do  {
                    cin >> action;
                    if (action == "use_wrench" && (inventory[0] == 3 || inventory[1] == 3 || inventory[2] == 3 || inventory[3] == 3 || inventory[4] == 3 || inventory[5] == 3 || inventory[6] == 3))   {
                        cout << endl << "The grate opened easily once the wrench was used to take off the bolts" << endl;
                        return "Storage";      // Returns the new location of the player
                    }
                    else if (action == "use_blanket" || action == "use_plastic_spoon" || action == "use_food_tray" || action == "use_scissors" || action == "use_revolver" || action == "use_backpack" || action == "use_cell_phone" || action == "use_candle" || action == "use_id_card" || action == "use_soap" || action == "use_rope" || action == "use_flashlight" || action == "use_paperclip") {
                        cout << "That item cannot be used here" << endl;
                    }
                    else if (action != "w" || action != "W" || action != "a" || action != "A" || action != "s" || action != "S" || action != "d" || action != "D") {
                        break;
                    }
                } while(1);
            }
            else if (action == "d" || action == "D"){                               // Player looks at the east wall
                moveCount++;
                if (randGaurdAlert == moveCount){
                    cout << "As you are manuvering around the room, you accidently turn on one of the showers." << endl;       // Player triggers guard and warns them to get out of the room
                    cout << "You hear the water run through the pipes and out of the room. Now you " << endl;
                    cout << "are afraid a prison guard heard you. He is likely on his way now!" << endl << endl;
                }
                else if (moveCount == 7) {
                    return "lose";
                }
                cout << "On the east wall, you see some showers along with some mirrors. They seem to be cracked " << endl;        // Description of the east wall
                cout << "in certain places. Maybe someone used a heavy object to try and break through?" << endl << endl;
                do  {
                    cin >> action;
                    if (action == "use_id_card" || action == "use_blanket" || action == "use_plastic_spoon" || action == "use_food_tray" || action == "use_scissors" || action == "use_revolver" || action == "use_backpack" || action == "use_cell_phone" || action == "use_candle" || action == "use_wrench" || action == "use_soap" || action == "use_rope" || action == "use_flashlight" || action == "use_paperclip")  {
                        cout << "That item cannot be used here" << endl;
                    }
                    else if (action != "w" || action != "W" || action != "a" || action != "A" || action != "s" || action != "S" || action != "d" || action != "D") {
                        break;
                    }
                } while (1);
            }

            else {                                                              // Checks the users input statement to see if it is valid
                cout << "That is not a valid command / Invalid Order of Commands" << endl;
                cin >> action;
            }

            } while  (location == "Showers");
        }
}

/* Function Name: Menu
 *
 * Function Description:
 * This function outputs the menu screen to the player
 *
 * Parameters:
 * N/A
 *
 * return value:
 * void
 */

void Menu()  {
    cout << endl << endl;
    cout << "        " << "*********************************************************************************************" << endl << endl;
    cout << "           " << "PPPPPPPPP      RRRRRRRRR      IIIIIIIIIII      SSSSSSS         OOOOO      NNN       NNN" << endl;
    cout << "           " << "PPPPPPPPPP     RRRRRRRRRR     IIIIIIIIIII     SSSSSSSSS       OOOOOOO     NNNN      NNN" << endl;
    cout << "           " << "PPP    PPPP    RRR    RRRR        III        SSSS   SSSS     OOO   OOO    NNNNN     NNN" << endl;
    cout << "           " << "PPP     PPP    RRR     RRRR       III       SSSS     SSSS   OOO     OOO   NNN NNN   NNN" << endl;
    cout << "           " << "PPP    PPPP    RRR    RRRR        III       SSSSS           OOO     OOO   NNN NNN   NNN" << endl;
    cout << "           " << "PPPPPPPPPP     RRRRRRRRRR         III         SSSSS         OOO     OOO   NNN  NNN  NNN" << endl;
    cout << "           " << "PPPPPPPP       RRRRRRR            III            SSSS       OOO     OOO   NNN  NNN  NNN" << endl;
    cout << "           " << "PPP            RRR RRR            III             SSSSS     OOO     OOO   NNN  NNN  NNN" << endl;
    cout << "           " << "PPP            RRR  RRR           III               SSSSS   OOO     OOO   NNN   NNN NNN" << endl;
    cout << "           " << "PPP            RRR   RRR          III       SSSS     SSSS   OOO     OOO   NNN   NNN NNN" << endl;
    cout << "           " << "PPP            RRR    RRR         III        SSSS   SSSS     OOO   OOO    NNN    NNNNNN" << endl;
    cout << "           " << "PPP            RRR     RRR    IIIIIIIIIII     SSSSSSSSS       OOOOOOO     NNN     NNNNN" << endl;
    cout << "           " << "PPP            RRR      RRR   IIIIIIIIIII      SSSSSSS         OOOOO      NNN       NNN" << endl << endl;

    cout << "           " << "EEEEEEEEEEE       SSSSSSS           CCCCCC      AAAAAAA     PPPPPPPPP      EEEEEEEEEEEE" << endl;
    cout << "           " << "EEEEEEEEEEE      SSSSSSSSS        CCCCCCCCC    AAAAAAAAA    PPPPPPPPPP     EEEEEEEEEEEE" << endl;
    cout << "           " << "EEE             SSSS   SSSS     CCCCCCCC      AAAA   AAAA   PPP    PPPP    EEE         " << endl;
    cout << "           " << "EEE            SSSS     SSSS    CCCC          AAA     AAA   PPP     PPP    EEE         " << endl;
    cout << "           " << "EEE            SSSSS            CCC           AAA     AAA   PPP    PPPP    EEE         " << endl;
    cout << "           " << "EEE              SSSSS          CCC           AAAAAAAAAAA   PPPPPPPPPP     EEE         " << endl;
    cout << "           " << "EEEEEEEEEEE         SSSS        CCC           AAAAAAAAAAA   PPPPPPPPP      EEEEEEEEEEEE" << endl;
    cout << "           " << "EEEEEEEEEEE          SSSSS      CCC           AAA     AAA   PPP            EEEEEEEEEEEE" << endl;
    cout << "           " << "EEE                    SSSSS    CCC           AAA     AAA   PPP            EEE         " << endl;
    cout << "           " << "EEE            SSSS     SSSS    CCCC          AAA     AAA   PPP            EEE         " << endl;
    cout << "           " << "EEE             SSSS   SSSS     CCCCCCCC      AAA     AAA   PPP            EEE         " << endl;
    cout << "           " << "EEEEEEEEEEE      SSSSSSSSS        CCCCCCCCC   AAA     AAA   PPP            EEEEEEEEEEEE" << endl;
    cout << "           " << "EEEEEEEEEEE       SSSSSSS           CCCCCC    AAA     AAA   PPP            EEEEEEEEEEEE" << endl << endl;
    cout << "        " << "*********************************************************************************************" << endl << endl;
    cout << "           " << "                      Developed By: Joshua Sutton & Andrew Dillon                      " << endl << endl;
    cout << "           " << "                                1: Controls/Commands                                   " << endl;
    cout << "           " << "                                2: Start Your Escape!                                  " << endl << endl;

    int menuChoice;
    do {
    cin >> menuChoice;
    if (menuChoice == 1){
        Controls();

        cout << "           Press 2 to start your Great Escape!" << endl;
        cin >> menuChoice;
    }
    else if (menuChoice == 2) {
        system("CLS");
        return;
    }
    else {
        cout << "Please input a valid menu choice, dummy" << endl;
    }
    } while (menuChoice != 2);
    system("CLS");
    return;
}

/* Function Name: main
 *
 * Function Description:
 * This is where the navigation of the room funictions happens. An infitite while loop
 * will only break when a room function return "win" or "lose". Otherwise, location will be updated
 * and call a new room function.
 *
 * Parameters:
 * N/A
 *
 * return value:
 * int 0 when program is complete
 */

int main(){

    srand(time(NULL));

    Menu();

    int cellCnt = 0;
    int messHallCnt = 0;
    int officeCnt = 0;
    int kitchenCnt = 0;
    int storageCnt = 0;
    int breakRoomCnt = 0;
    int libraryCnt = 0;
    int showersCnt = 0;

    int paperclip = 1;
    int inventory[7] = {0,0,0,0,0,0,0};
    inventory[0] = paperclip;
    string location = "Cell";

    while (1) {

    if (location == "Cell"){
        location = Cell(inventory, cellCnt, location);
    }
    else if (location == "messHall") {
        location = messHall(inventory, messHallCnt, location);
    }
    else if (location == "Kitchen") {
        location = Kitchen(inventory, kitchenCnt, location);
    }
    else if (location == "Yard") {
        location = Yard(inventory);
    }
    else if (location == "wardensOffice") {
        location = wardensOffice(inventory, officeCnt, location);
    }
    else if (location == "Storage") {
        location = Storage(inventory, storageCnt, location);
    }
    else if (location == "breakRoom") {
        location = breakRoom(inventory, breakRoomCnt, location);
    }
    else if (location == "Library") {
        location = Library(inventory, libraryCnt, location);
    }
    else if (location == "Showers") {
        location = Showers(inventory, showersCnt, location);
    }
    else if (location != "win") {
        break;
    }
    else if (location != "lose") {
        break;
    }
}

    if (location == "win"){
        cout << "                                   SUCCESS!!" << endl << endl;
        cout << "You walk outside and are able to pass the watch tower because of your disguise. " << endl;
        cout << "After walking around for a few minutes, you use the rope to climb up the wall." << endl;
        cout << "Once you get to the top of the wall, you use the scissors to cut the barbed" << endl;
        cout << "wire. You then use the rope to repel down the wall and successfully ESCAPE THE PRISON!!!" << endl << endl;
    }
    else if (location == "lose") {
        cout << endl << "Unfortunately, you took too long and the guards found you. You will" << endl;
        cout << "return to prison and stay there for a long, long time :(" << endl << endl;
    }
    return 0;
}
