#include <iostream>
#include <string>
#include <map>
#include "Layout.h"
#include "GameState.h"

using namespace std;

int main()
{
	Layout house = Layout();
	GameState gameState = GameState();
	gameState.setCurrentRoom(house.getFirstRoom());

    int option = -1;
    Room* current;
    Room* next;

    do
    {
        system("cls");
        current = gameState.getCurrentRoom();

        cout << "Looking around "
            + current->getName()
            + " you see "
            + current->getDesc()
            + "\n";

        current->Displayrooms();

        option = -1;
        cout << "[4] Exit game\n";
        cout << "Select an option > ";
        cin >> option;

        //if the index for command in linked rooms != end
        //if command ("n") is in linked rooms : { "n" : &kitchen, "s": hall}

        //check if input == direction
        if (option >= 0 && option < 4)
        {
            next = current->getLinkedRoom(option);
            if ( next != nullptr)
            {
                //set the current room to be the room in that direction
                gameState.setCurrentRoom(next);
            }
        }

    } while (option != 4);
}
