#include <iostream>
#include "Space.hpp"
#include "ItemSpace.hpp"
#include "PressurePlateSpace.hpp"
#include "LockedItemSpace.hpp"
#include "Player.hpp"

int main() {
    // Initializing the map. Better to use the STL Map container
    // Legend:
    //   [▣] - Locked Item Chest (Has Key)
    //   [□] - Unlocked Item Chest
    //   [╏] - Locked Door
    //   [▃] - Pressure Switch 
    //   [☆] - Exit

    // 1. Start at "space1"
    // 2. "space3" contains a rock used to depress the pressure switch "space9"
    // 3. When "space9" is triggered a connection will be made from:
    //    - "space3"<->"space4"
    //    - "space8"<->"space9"
    // 4. "space8" contains a "chest key" that will open the locked chest "space9"
    // 5. "space12" contains another rock used to depress the pressure switch "space4"
    // 6. When "space4" is triggered a connection will be made from:
    //    - "space6"<->"space7"
    // 7. The user must have the key in order to unlock "space7"

    // [1]-[2]-[□]?[▃]
    //  |   |
    // [5]-[6]?[╏]-[☆]<-Exit
    //  |   |   
    // [▃] [10]?[▣]-[□]
    int turn = 20;
    Space space1;   // Regular space
    ItemSpace item1("rock");
    ItemSpace item2("key");
    PressurePlateSpace plate1;
    LockedItemSpace lockedItem1("master key");
    
    Player p1(space1);

    space1.topConnectToBottomOf(item1);
    item1.bottomConnectToTopOf(space1);

    item2.leftConnectToRightOf(item1);
    item1.rightConnectToLeftOf(item2);

    space1.bottomConnectToTopOf(plate1);
    plate1.topConnectToBottomOf(space1);

    space1.leftConnectToRightOf(lockedItem1);
    lockedItem1.rightConnectToLeftOf(space1);

    while (turn > 0) {
        p1.showInventory();
        p1.move();
        p1.inspectSpace();
        turn--;
    }

    // move -> getSpaceInfo -> inspectSpace

    // Space space2(20);
    // Space space3(30);
    // Space space4(40);
    // ItemSpace item1("Rock");

    // space1.topConnectToBottomOf(item1);
    // item1.bottomConnectToTopOf(space1);
    // space2.bottomConnectToTopOf(space1);
    // space1.rightConnectToLeftOf(space3);
    // space3.leftConnectToRightOf(space1);
    // space1.bottomConnectToTopOf(space4);
    // space4.topConnectToBottomOf(space1);
    // space2.rightConnectToLeftOf(item1);
    // item1.leftConnectToRightOf(space2);
    // Player p1(space1);
    // p1.move();
    // p1.activateSpace();
    // p1.activate();
    // p1.showInventory();


    return 0;
}