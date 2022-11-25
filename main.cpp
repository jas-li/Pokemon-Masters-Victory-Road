#include "View.h"
#include "Model.h"
#include "GameCommand.h"
#include "Trainer.h"
#include "GameObject.h"
#include "Point2D.h"
#include "Vector2D.h"
#include "PokemonGym.h"
#include "PokemonCenter.h"
#include "Building.h"

using namespace std;

int main() {
    Model m1;
    View v1;
    Point2D pt;
    char input;
    int id1;
    int id2;
    int num1;
    int num2;

    m1.ShowStatus();
    m1.Display(v1);
    while(true) {
        cout << "Enter the game command: " << endl;
        cin >> input;

        switch(input) {
            case 'm':
                cin >> id1;
                cin >> num1;
                cin >> num2;
                pt.x = num1;
                pt.y = num2;
                cout << "moving " << id1 << " to " << pt << endl;
                DoMoveCommand(m1,id1,pt);
                break;
            case 'c':
                cin >> id1;
                cin >> id2;
                DoMoveToCenterCommand(m1, id1, id2);
                break;
            case 'g':
                cin >> id1;
                cin >> id2;
                DoMoveToGymCommand(m1, id1, id2);
                break;
            case 's':
                cin >> id1;
                DoStopCommand(m1,id1);
                break;
            case 'p':
                cin >> id1;
                cin >> num1;
                DoRecoverInCenterCommand(m1, id1, num1);
                break;
            case 'b':
                cin >> id1;
                cin >> num1;
                DoBattleCommand(m1, id1, num1);
                break;
            case 'a':
                DoAdvanceCommand(m1, v1);
                break;
            case 'r':
                DoRunCommand(m1, v1);
                break;
            case 'q':
                return 0;
            default:
                break;
        }
    }
    



    return 0;
}
