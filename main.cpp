#include <iostream>
#include <string>
#include <map>
#include "Layout.h"
#include "GameState.h"
#include "CommonDefinitions.h"

using namespace std;

GUIState guiState;
string guiStrings[] = { "Main", "Move", "Explore" };

int main()
{
	Layout house = Layout();
	GameState gameState = GameState();
	gameState.setCurrentRoom(house.getFirstRoom());

    int mainOption = -1;
    int option = -1;

    Room* current;
    Room* next;

    guiState = MainGUI;

    do
    {
        system("cls");

        mainOption = -1;
        option = -1;

        current = gameState.getCurrentRoom();

        cout << "Looking around "
            + current->getName()
            + " you see "
            + current->getDesc()
            + "\n\n";
        

        switch (guiState)
        {
        case MainGUI:
            cout << "Main Options:\n";
            cout << "[0] Exit Game\n";
            cout << "[1] Move\n";
            cout << "[2] Explore\n";

            cout << "\nSelect an option > ";
            cin >> mainOption;

            switch (mainOption)
            {
            case 1:
                guiState = MoveGUI;
                break;
            case 2:
                guiState = ExploreGUI;
                break;
            }

            break;
        case MoveGUI:
            cout << "Move Options:\n";
            cout << "[0] Main Menu\n";

            current->Displayrooms();
            
            cout << "\nSelect an option > ";
            cin >> option;

            if (option == 0)
            {
                guiState = MainGUI;
            }
            else if (option > 0 && option < 4)
            {
                next = current->getLinkedRoom(option - 1);
                if (next != nullptr)
                {
                    //set the current room to be the room in that direction
                    gameState.setCurrentRoom(next);
                    guiState = MainGUI;
                }
            }
            break;
        case ExploreGUI:
            cout << "Explore Options:\n";
            cout << "[0] Main Menu\n";

            //current->Displayrooms();

            cout << "\nSelect an option > ";
            cin >> option;

            if (option == 0)
            {
                guiState = MainGUI;
            }
            /*else if (option > 0 && option < 4)
            {
            }
            */
            break;
        }
        

    } while (mainOption != 0);
}
