#include "GameCommand.h"

using namespace std;

void DoMoveCommand(Model & model, int trainer_id, Point2D p1) {
    if(model.GetTrainerPtr(trainer_id) != 0) {
        model.GetTrainerPtr(trainer_id)->StartMoving(p1);
        cout << "Moving " << model.GetTrainerPtr(trainer_id)->GetTrainerName() << " to " << p1 << endl;
    } else {
        cout << "“Error: Please enter a valid command!" << endl;
    }
}

void DoMoveToCenterCommand(Model & model, int trainer_id, int center_id) {
    if(model.GetTrainerPtr(trainer_id) != 0 && model.GetPokemonCenterPtr(center_id) != 0) {
        model.GetTrainerPtr(trainer_id)->StartMovingToCenter(model.GetPokemonCenterPtr(center_id));
        cout << "Moving " << model.GetTrainerPtr(trainer_id)->GetTrainerName() << " to pokemon center " << center_id << endl;
    } else {
        cout << "“Error: Please enter a valid command!" << endl;
    }
}

void DoMoveToGymCommand(Model & model, int trainer_id, int gym_id) {
    if(model.GetTrainerPtr(trainer_id) != 0 && model.GetPokemonGymPtr(gym_id) != 0) {
        model.GetTrainerPtr(trainer_id)->StartMovingToGym(model.GetPokemonGymPtr(gym_id));
        cout << "Moving " << model.GetTrainerPtr(trainer_id)->GetTrainerName() << " to gym " << gym_id << endl;
    } else {
        cout << "“Error: Please enter a valid command!" << endl;
    }
}

void DoStopCommand(Model & model, int trainer_id) {
    if(model.GetTrainerPtr(trainer_id) != 0) {
        model.GetTrainerPtr(trainer_id)->Stop();
        cout << "Stopping " << model.GetTrainerPtr(trainer_id)->GetTrainerName() << endl;
    } else {
        cout << "“Error: Please enter a valid command!" << endl;
    }
}

void DoBattleCommand(Model & model, int trainer_id, unsigned int battles) {
    if(model.GetTrainerPtr(trainer_id) != 0) {
        model.GetTrainerPtr(trainer_id)->StartBattling(battles);
        cout << model.GetTrainerPtr(trainer_id)->GetTrainerName() << " is battling" << endl;
    } else {
        cout << "“Error: Please enter a valid command!" << endl;
    }
}

void DoRecoverInCenterCommand(Model& model, int trainer_id, unsigned int potions_needed) {
    if(model.GetTrainerPtr(trainer_id) != 0) {
        model.GetTrainerPtr(trainer_id)->StartRecoveringHealth(potions_needed);
        cout << "Recovering " << model.GetTrainerPtr(trainer_id)->GetTrainerName() << "\'s Pokemon\'s health" << endl;
    } else {
        cout << "“Error: Please enter a valid command!" << endl;
    }
}

void DoAdvanceCommand(Model& model, View& view) {
    cout << "Advancing one tick." << endl;
    model.Update();
    model.ShowStatus();
    model.Display(view);
}

void DoRunCommand(Model& model, View& view) {
    cout << "Advancing to next event." << endl;
    for(int i=0; i<5; i++) {
        if(model.Update()) {
            break;
        }
    }
    model.ShowStatus();
    model.Display(view);
}