#include "Model.h"

using namespace std;

Model::Model() {
    time = 0;
    Point2D pt;

    // Make T1
    pt.x = 5;
    pt.y = 1;
    Trainer* T1 = new Trainer("Ash", 1, 'T', 1, pt);
    object_ptrs[0] = T1;
    trainer_ptrs[0] = T1;

    // Make T2
    pt.x = 10;
    pt.y = 1;
    Trainer* T2 = new Trainer("Misty", 2, 'T', 2, pt);
    object_ptrs[1] = T2;
    trainer_ptrs[1] = T2;

    // Make C1
    pt.x = 1;
    pt.y = 20;
    PokemonCenter* C1 = new PokemonCenter(1, 1, 100, pt);
    object_ptrs[2] = C1;
    center_ptrs[0] = C1;

    // Make C2
    pt.x = 10;
    pt.y = 20;
    PokemonCenter* C2 = new PokemonCenter(2, 2, 200, pt);
    object_ptrs[3] = C2;
    center_ptrs[1] = C2;

    // Make G1
    pt.x = 0;
    pt.y = 0;
    PokemonGym* G1 = new PokemonGym(10, 1, 2, 3, 1, pt);
    object_ptrs[4] = G1;
    gym_ptrs[0] = G1;

    // Make G2
    pt.x = 5;
    pt.y = 5;
    PokemonGym* G2 = new PokemonGym(20, 5, 7.5, 4, 2, pt);
    object_ptrs[5] = G2;
    gym_ptrs[1] = G2;

    num_objects = 6;
    num_trainers = 2;
    num_centers = 2;
    num_gyms = 2;
    cout << "Model default constructed" << endl;
}

Model::~Model() {
    for(int i=0; i<num_trainers; i++) {
        delete trainer_ptrs[i];
    }

    for(int i=0; i<num_centers; i++) {
        delete center_ptrs[i];
    }

    for(int i=0; i<num_gyms; i++) {
        delete gym_ptrs[i];
    }

    cout << "Model destructed" << endl;
}

Trainer* Model::GetTrainerPtr(int id) {
    for(int i=0; i<num_trainers; i++) {
        if(id == trainer_ptrs[i]->GetId()) {
            return trainer_ptrs[i];
        }
    }
    return 0;
}

PokemonCenter* Model::GetPokemonCenterPtr(int id) {
    for(int i=0; i<num_centers; i++) {
        if(id == center_ptrs[i]->GetId()) {
            return center_ptrs[i];
        }
    }
    return 0;
}

PokemonGym* Model::GetPokemonGymPtr(int id) {
    for(int i=0; i<num_gyms; i++) {
        if(id == gym_ptrs[i]->GetId()) {
            return gym_ptrs[i];
        }
    }
    return 0;
}

bool Model::Update() {
    time++;
    int count = 0;
    // GAME OVER YOU WIN
    count = 0;
    for(int i=0; i<num_gyms; i++) {
        if(gym_ptrs[i]->passed()) {
            count++;
        }
    }
    if(count == num_gyms) {
        cout << "GAME OVER: You win! All battles done!" << endl;
        exit(0);
    }
    // GAME OVER YOU LOSE
    count = 0;
    for(int i=0; i<num_trainers; i++) {
        if(trainer_ptrs[i]->HasFainted()) {
            count++;
        }
    }
    if(count == num_trainers) {
        cout << "GAME OVER: You lose! All of your Trainers’ pokemon have fainted!" << endl;
        exit(0);
    }
    // Update
    for(int i=0; i<num_objects; i++) {
        if(object_ptrs[i]->Update()) {
            return true;
        }
    } 
    return false;
}

void Model::Display(View& view) {
    view.Clear();
    for(int i=0; i<num_objects; i++) {
        view.Plot(object_ptrs[i]);
    }
    view.Draw();
}

void Model::ShowStatus() {
    cout << "Time: " << time << endl;
    for(int i=0; i<num_objects; i++) {
        object_ptrs[i]->ShowStatus();
    }
}