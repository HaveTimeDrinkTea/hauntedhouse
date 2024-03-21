#include <iostream>
#include <string>
#include <map>
#include "Layout.h"
#include "GameState.h"
#include "CommonDefinitions.h"
#include "Character.h"

using namespace std;

GUIState guiState;
string guiStrings[] = { "Main", "Move", "Explore" };

int main2()
{
    return 0;
    Character c = Character("hola", "hola2");

    cout << c.getName() << endl;
    cout << c.getDesc() << endl;

}

int main()
{
	Layout house = Layout();
	GameState gameState = GameState();
	gameState.setCurrentRoom(house.getFirstRoom());

    int mainOption = -1;
    int moveOption = -1;
    int exploreOption = -1;
    int itemOption = -1;

    Room* current;
    Room* next;
    Item* currentItem;

    guiState = MainGUI;

    do
    {
        system("cls");

        /*
        mainOption = -1;
        moveOption = -1;
        exploreOption = -1;
        itemOption = -1;
        */

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
            cout << "[0] Go Back\n";

            current->displayRooms();
            
            cout << "\nSelect an option > ";
            cin >> moveOption;

            if (moveOption == 0)
            {
                guiState = MainGUI;
            }
            else if (moveOption > 0 && moveOption < 4)
            {
                next = current->getLinkedRoom(moveOption - 1);
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
            cout << "[0] Go Back\n";

            current->displayItems();

            cout << "\nSelect an option > ";
            cin >> exploreOption;

            if (exploreOption == 0)
            {
                guiState = MainGUI;
            }
            else if (exploreOption > 0 && exploreOption < current->getNumItems())
            {
                guiState = ItemGUI;
            }
            break;
        case ItemGUI:
            currentItem = current->getItem(exploreOption - 1);

            cout << currentItem->getDisplayString() << endl << endl;

            cout << "Item Options:\n";
            cout << "[0] Go Back\n";

            
            currentItem->displayActions();

            cout << "\nSelect an option > ";
            cin >> itemOption;

            if (itemOption == 0)
            {
                guiState = ExploreGUI;
            }
            else if (itemOption > 0 && itemOption < currentItem->getNumActions())
            {

            }
            
            break;
        }
        

    } while (mainOption != 0);
}
