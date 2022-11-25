#include "Building.h"

using namespace std;

Building::Building() : GameObject::GameObject('B') {
    display_code = 'B';
    cout << "Building default constructed" << endl;
}

Building::Building(char in_code, int in_Id, Point2D in_loc) : GameObject::GameObject(in_loc, in_Id, in_code) {
    id_num = in_Id;
    location = in_loc;
    display_code = in_code;
    cout << "Building constructed" << endl;
}

void Building::AddOneTrainer() {
    trainer_count++;
}

void Building::RemoveOneTrainer() {
    if(trainer_count > 0) {
        trainer_count--;
    }
}

void Building::ShowStatus() {
    cout << display_code << ' ' << id_num << " located at " << location << endl;
    cout << trainer_count << " trainers is/are in this building" << endl;
}

bool Building::ShouldBeVisible() {
    return true;
}