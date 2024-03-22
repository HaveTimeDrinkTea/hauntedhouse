#include <iostream>
#include <string>
#include <map>
#include "Layout.h"
#include "GameState.h"
#include "CommonDefinitions.h"
#include "Character.h"
#include "Inventory.h"
#include "ActionPick.h"
#include "ActionStore.h"
#include "ItemPickWear.h"

using namespace std;

GUIState guiState;
string guiStrings[] = { "Main", "Move", "Explore", "Inventory"};


int main2()
{
    return 0;
    Character c = Character("hola", "hola2");

    cout << c.getName() << endl;
    cout << c.getDesc() << endl;

}

void HandleAction(Action* a, Item* item, Inventory* hand, Inventory* bag)
{
    if (ActionPick* aPick = dynamic_cast<ActionPick*>(a))
    {
        if (Item* iObject = dynamic_cast<ItemPickWear*>(item))
        {

        }
    }
    else if (ActionStore* aStore = dynamic_cast<ActionStore*>(a))
    {
        
    }
}

int main()
{
	Layout house = Layout();
	GameState gameState = GameState();
	gameState.setCurrentRoom(house.getFirstRoom());
    Inventory bag = Inventory("Bag", 6, false);
    Inventory hands = Inventory("Hands", 2, true);

    int mainOption = -1;
    int moveOption = -1;
    int exploreOption = -1;
    int itemOption = -1;
    int selectInventoryOption = -1;
    int inventoryOption = -1;
    int numItems = 0;

    Room* current;
    Room* next;
    Item* currentItem;

    guiState = MainGUI;

    do
    {
        system("cls");

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
            cout << "[1] Move to another Room\n";
            cout << "[2] Explore Room\n";
            cout << "[3] Inventory\n";

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
            case 3:
                guiState = SelectInventoryGUI;
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
            currentItem->displayHoldingItems();

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
                Action* a = currentItem->getAction(itemOption - 1);

                //HandleAction(a);
            }
            
            break;
        case SelectInventoryGUI:
            cout << "Inventory Options:\n";
            cout << "[0] Go Back\n";
            cout << "[1] Carrying on Hands\n";
            cout << "[2] Carrying in Bag\n";

            cout << "\nSelect an option > ";
            cin >> selectInventoryOption;

            if (selectInventoryOption == 0)
            {
                guiState = MainGUI;
            }
            else if (selectInventoryOption > 0 && selectInventoryOption < 3)
            {
                guiState = InventoryGUI;
            }
            break;
        case InventoryGUI:
            if (selectInventoryOption == 1)
            {
                cout << "Carrying in hands, options:\n";
                cout << "[0] Go Back\n";
                hands.displayInventory();
                numItems = hands.getNumItems();
            }
            else
            {
                cout << "Carrying in bag, options:\n";
                cout << "[0] Go Back\n";
                bag.displayInventory();
                numItems = bag.getNumItems();
            }
            
            cout << "\nSelect an option > ";
            cin >> inventoryOption;

            if (inventoryOption == 0)
            {
                guiState = SelectInventoryGUI;
            }
            else if (inventoryOption > 0 && inventoryOption < numItems)
            {
                guiState = InventoryItemGUI;
            }
            break;
        case InventoryItemGUI:
            if (selectInventoryOption == 1)
            {
                currentItem = hands.getItem(inventoryOption - 1);
                cout << "Carrying in hands, options:\n";
                cout << "[0] Go Back\n";
                hands.displayInventory();
            }
            else
            {
                currentItem = bag.getItem(inventoryOption - 1);
                cout << "Carrying in bag, options:\n";
                cout << "[0] Go Back\n";
                bag.displayInventory();
            }

            cout << currentItem->getDisplayString() << endl << endl;
            currentItem->displayHoldingItems();

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
