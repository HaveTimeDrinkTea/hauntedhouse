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
#include "ActionDrop.h"
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

bool HandleAction(Room* r, Action* a, Item* item, Inventory* hand, Inventory* bag, string* m)
{
    bool retVal = false;

    if (ActionPick* aPick = dynamic_cast<ActionPick*>(a))
    {
        if (item->getNumHoldingItems() == 0)
        {
            if (hand->addItem(item, m))
            {
                item->picked();
                r->removeItem(item);
                bag->removeItem(item);
                *m = "Item was picked and now you are holding it";
                retVal = true;
            }
            else
            {
                retVal = false;
            }
        }
        else
        {
            *m = "Item can not be picked while it is hokding items";
            retVal = false;
        }
    }
    else if (ActionStore* aStore = dynamic_cast<ActionStore*>(a))
    {
        if (bag->addItem(item, m))
        {
            item->stored();
            r->removeItem(item);
            hand->removeItem(item);
            *m = "Item was stored in your bag";
            retVal = true;
        }
        else
        {
            retVal = false;
        }
    }
    else if (ActionDrop* aDrop = dynamic_cast<ActionDrop*>(a))
    {
        item->dropped();
        r->setItem(item);
        item->setPosDesc("Laying on the floor");
        
        hand->removeItem(item);
        bag->removeItem(item);
        *m = "Item has been dropped to the floor";
        retVal = true;
    }

    return retVal;
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
    string message = "";

    Room* currentRoom;
    Room* next;
    Item* currentItem;

    guiState = MainGUI;

    do
    {
        system("cls");

        currentRoom = gameState.getCurrentRoom();

        cout << "Looking around "
            + currentRoom->getName()
            + " you see "
            + currentRoom->getDesc()
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

            message = "";

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

            currentRoom->displayRooms();
            
            cout << "\nSelect an option > ";
            cin >> moveOption;

            if (moveOption == 0)
            {
                guiState = MainGUI;
            }
            else if (moveOption > 0 && moveOption < 5)
            {
                message = "";

                next = currentRoom->getLinkedRoom(moveOption - 1);
                if (next != nullptr)
                {
                    //set the current room to be the room in that direction
                    gameState.setCurrentRoom(next);
                    guiState = MainGUI;
                }
            }
            break;
        case ExploreGUI:

            cout << message << endl << endl;

            cout << "Explore Options:\n";
            cout << "[0] Go Back\n";

            currentRoom->displayItems();

            cout << "\nSelect an option > ";
            cin >> exploreOption;

            if (exploreOption == 0)
            {
                guiState = MainGUI;
            }
            else if (exploreOption > 0 && exploreOption <= currentRoom->getNumItems())
            {
                message = "";

                guiState = ItemGUI;                
            }
            break;
        case ItemGUI:
            currentItem = currentRoom->getItem(exploreOption - 1);

            cout << message << endl << endl;

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
            else if (itemOption > 0 && itemOption <= currentItem->getNumActions())
            {
                message = "";

                Action* a = currentItem->getAction(itemOption - 1);

                if (HandleAction(currentRoom, a, currentItem, &hands, &bag, &message))
                {
                    guiState = ExploreGUI;
                }
            }
            
            break;
        case SelectInventoryGUI:

            message = "";
            //cout << message << endl << endl;

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
                message = "";

                guiState = InventoryGUI;
            }
            break;
        case InventoryGUI:

            cout << message << endl << endl;

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
            else if (inventoryOption > 0 && inventoryOption <= numItems)
            {
                message = "";

                guiState = InventoryItemGUI;
            }
            break;
        case InventoryItemGUI:

            cout << message << endl << endl;

            if (selectInventoryOption == 1)
            {
                currentItem = hands.getItem(inventoryOption - 1);
            }
            else
            {
                currentItem = bag.getItem(inventoryOption - 1);
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
            else if (itemOption > 0 && itemOption <= currentItem->getNumActions())
            {
                message = "";

                Action* a = currentItem->getAction(itemOption - 1);

                if (HandleAction(currentRoom, a, currentItem, &hands, &bag, &message))
                {
                    guiState = InventoryGUI;
                }

            }

            break;
        }
        

    } while (mainOption != 0);
}
