#include "Trainer.h"

using namespace std;

Trainer::Trainer() : GameObject::GameObject('T') {
    speed = 5;
    cout << "Trainer default constructed." << endl;
}

Trainer::Trainer(char in_code) : GameObject::GameObject('T') {
    speed = 5;
    cout << "Trainer constructed." << endl;
    state = STOPPED;
    display_code = in_code;
}

Trainer::Trainer(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc) : GameObject::GameObject('T') {
    display_code = in_code;
    id_num = in_id;
    speed = in_speed;
    name = in_name;
    location = in_loc;
    state = STOPPED;
    cout << "Trainer constructed." << endl;
}

Trainer::~Trainer() {
    cout << "Trainer destructed" << endl;
}

void Trainer::StartMoving(Point2D dest) {
    SetupDestination(dest);
    
    if(GetDistanceBetween(GetLocation(), dest) == 0) {
        cout << display_code << ' ' << id_num << ": I’m already there. See?" << endl;
    } else if (state == FAINTED) {
        cout << display_code << ' ' << id_num << ": My pokemon have fainted. I may move but you cannot see me." << endl;
    } else {
        if(state == IN_GYM) {
            current_gym->RemoveOneTrainer();
        } else if(state == AT_CENTER) {
            current_center->RemoveOneTrainer();
        }
        state = MOVING;
        cout << display_code << ' ' << id_num << ": On my way." << endl;
    }
}

void Trainer::StartMovingToGym(PokemonGym* gym) {
    SetupDestination(gym->GetLocation());

    if(state == FAINTED) {
        cout << display_code << ' ' << id_num << ": My Pokemon have fainted so I can’t move to gym..." << endl;
    } else if(GetDistanceBetween(GetLocation(), gym->GetLocation()) == 0) {
        cout << display_code << ' ' << id_num << ": I am already at the PokemonGym!" << endl;
    } else {
        if(state == IN_GYM) {
            current_gym->RemoveOneTrainer();
        } else if(state == AT_CENTER) {
            current_center->RemoveOneTrainer();
        }
        state = MOVING_TO_GYM;
        current_gym = gym;
        cout << display_code << ' ' << id_num << ": on my way to gym " << gym->GetId() << "." << endl;
    }
}

void Trainer::StartMovingToCenter(PokemonCenter* center) {
    SetupDestination(center->GetLocation());

    if(state == FAINTED) {
        cout << display_code << ' ' << id_num << "My pokemon have fainted so I should have gone to the center.." << endl;
    } else if(GetDistanceBetween(GetLocation(), center->GetLocation()) == 0) {
        cout << display_code << ' ' << id_num << ": I am already at the Center!" << endl;
    } else {
        if(state == IN_GYM) {
            current_gym->RemoveOneTrainer();
        } else if(state == AT_CENTER) {
            current_center->RemoveOneTrainer();
        }
        state = MOVING_TO_CENTER;
        current_center = center;
        cout << display_code << ' ' << id_num << ": On my way to Center " << center->GetId() << "." << endl;
    }
}

void Trainer::StartBattling(unsigned int num_battles) {
    if(state == FAINTED) {
        cout << display_code << ' ' << id_num << ": My Pokemon have fainted so no more battles for me..." << endl; // come back here
    } else if(state != IN_GYM) {
        cout << display_code << ' ' << id_num << ": I can only battle in a PokemonGym!" << endl;
    } else if(current_gym->GetPokeDollarCost(num_battles) > PokeDollars) {
        cout << display_code << ' ' << id_num << ": Not enough money for battles" << endl;
    } else if(current_gym->passed()) {
        cout << display_code << ' ' << id_num << ": Cannot battle! This PokemonGym has no more trainers to battle!" << endl;
    } else {
        state = BATTLING_IN_GYM;
        battles_to_buy = num_battles; // current_gym->TrainPokemon(num_battles);
        cout << display_code << ' ' << id_num << ": Started to battle at the PokemonGym " << current_gym->GetId() << " with " << num_battles << " battles" << endl;
    }
}

void Trainer::StartRecoveringHealth(unsigned int num_potions) {
    if(current_center->GetPokeDollarCost(num_potions) > PokeDollars) {
        cout << display_code << ' ' << id_num << ": Not enough money to recover health." << endl;
    } else if(!current_center->HasPotions()) {
        cout << display_code << ' ' << id_num << ": Cannot recover! No potion remaining in this Pokemon Center" << endl;
    } else if(state != AT_CENTER) {
        cout << display_code << ' ' << id_num << ": I can only recover health at a Pokemon Center!" << endl;
    } else {
        state = RECOVERING_HEALTH;
        cout << display_code << ' ' << id_num << ": Started recovering " << num_potions << " potions at Pokemon Center " << current_center->GetId() << endl;
        potions_to_buy = current_center->DistributePotion(num_potions);
        health += 5*potions_to_buy;
    }
}

void Trainer::Stop() {
    state = STOPPED;
    cout << display_code << ' ' << id_num << ": Stopping..." << endl;
}

bool Trainer::HasFainted() {
    if(health == 0) {
        return true;
    } else {
        return false;
    }
}

bool Trainer::ShouldBeVisible() {
    if(state != FAINTED) {
        return true;
    } else {
        return false;
    }
}

void Trainer::ShowStatus() {
    cout << name << " status: " << endl;
    GameObject::ShowStatus();
    switch(state) {
        case STOPPED:
            cout << " stopped" << endl;
            break;
        case MOVING:
            cout << " moving at a speed of " << speed << " to destination " << destination << " at each step of " << delta << "." << endl;
            break;
        case MOVING_TO_GYM:
            cout << " heading to PokemonGym " << current_gym->GetId() << " at a speed of " << speed << " at each step of " << delta << endl;
            break;
        case MOVING_TO_CENTER:
            cout << " heading to Pokemon Center " << current_center->GetId() << " at a speed of " << speed << " at each step of " << delta << endl;
            break;
        case IN_GYM:
            cout << " inside PokemonGym " << current_gym->GetId() << endl;
            break;
        case AT_CENTER:
            cout << " inside Pokemon Center " << current_center->GetId() << endl;
            break;
        case BATTLING_IN_GYM:
            cout << " battling in PokemonGym " << current_gym->GetId() << endl;
            break;
        case RECOVERING_HEALTH:
            cout << " recovering health in Pokemon Center " << current_center->GetId() << endl;
            break;
    }
    // cout << "Health: " << health << endl;
    // cout << "PokeDollars: " << PokeDollars << endl;
    // cout << "Experience: " << experience << endl;
}

bool Trainer::Update() {
    int exp_gain;

    if(HasFainted() && state != FAINTED) {
        cout << name << " status:" << endl;
        cout << "Health: " << health << endl;
        cout << "PokeDollars: " << PokeDollars << endl;
        cout << "Experience: " << experience << endl;
        cout << name << " is out of health and can’t move" << endl;
        state = FAINTED;
        return true;
    }

    switch(state) {
        case STOPPED:
            cout << name << " status:" << endl;
            cout << "Health: " << health << endl;
            cout << "PokeDollars: " << PokeDollars << endl;
            cout << "Experience: " << experience << endl;
            return false;
        case MOVING:
            health -= 1;
            PokeDollars += GetRandomAmountOfPokeDollars();
            cout << name << " status:" << endl;
            cout << "Health: " << health << endl;
            cout << "PokeDollars: " << PokeDollars << endl;
            cout << "Experience: " << experience << endl;

            if(UpdateLocation()) {
                state = STOPPED;
                return true;
            } else {
                return false;
            }
        case MOVING_TO_GYM:
            health -= 1;
            PokeDollars += GetRandomAmountOfPokeDollars();
            cout << name << " status:" << endl;
            cout << "Health: " << health << endl;
            cout << "PokeDollars: " << PokeDollars << endl;
            cout << "Experience: " << experience << endl;

            if(UpdateLocation()) {
                state = IN_GYM;
                current_gym->AddOneTrainer();
                return true;
            } else {
                return false;
            }
        case MOVING_TO_CENTER:
            health -= 1;
            PokeDollars += GetRandomAmountOfPokeDollars();
            cout << name << " status:" << endl;
            cout << "Health: " << health << endl;
            cout << "PokeDollars: " << PokeDollars << endl;
            cout << "Experience: " << experience << endl;
            if(UpdateLocation()) {
                state = AT_CENTER;
                current_center->AddOneTrainer();
                return true;
            } else {
                return false;
            }
        case IN_GYM:
            cout << name << " status:" << endl;
            cout << "Health: " << health << endl;
            cout << "PokeDollars: " << PokeDollars << endl;
            cout << "Experience: " << experience << endl;
            return false;
        case AT_CENTER:
            cout << name << " status:" << endl;
            cout << "Health: " << health << endl;
            cout << "PokeDollars: " << PokeDollars << endl;
            cout << "Experience: " << experience << endl;
            return false;
        case BATTLING_IN_GYM:
            health -= current_gym->GetHealthCost(battles_to_buy);
            PokeDollars -= current_gym->GetPokeDollarCost(battles_to_buy);
            exp_gain = current_gym->TrainPokemon(battles_to_buy);
            experience += exp_gain;
            cout << name << " status:" << endl;
            cout << "Health: " << health << endl;
            cout << "PokeDollars: " << PokeDollars << endl;
            cout << "Experience: " << experience << endl;
            cout << "** " << name << " completed " << battles_to_buy << " battle(s)! **" << endl;
            cout << "** " << name << " gained " << exp_gain << " experience! **" << endl;
            state = IN_GYM;
            return true;
        case RECOVERING_HEALTH:
            StartRecoveringHealth(potions_to_buy);
            PokeDollars -= current_center->GetPokeDollarCost(potions_to_buy);
            cout << name << " status:" << endl;
            cout << "Health: " << health << endl;
            cout << "PokeDollars: " << PokeDollars << endl;
            cout << "Experience: " << experience << endl;
            cout << "** " << name << " recovered " << 5*potions_to_buy << " health! **" << endl;
            cout << "** " << name << " bought " << potions_to_buy << " potion(s)! **" << endl;
            state = AT_CENTER;
            return true;
        default:
            return false;
    }
}

bool Trainer::UpdateLocation() {
    Vector2D diff = destination - location;
    if((fabs(diff.x) <= fabs(delta.x)) && (fabs(diff.y) <= fabs(delta.y))) { // checks if object is within one step
        location = destination;
        cout << display_code << ' ' << id_num << ": I'm there!" << endl;
        return true;
    } else {
        location = location + delta;
        cout << display_code << ' ' << id_num << ": step..." << endl;
        return false;
    }
}

void Trainer::SetupDestination(Point2D dest) {
    destination = dest;
    delta = (destination - GetLocation()) * (speed / GetDistanceBetween(destination, GetLocation()));
}

string Trainer::GetTrainerName() {
    return name;
}

double GetRandomAmountOfPokeDollars() {
    srand((unsigned) time(NULL));

    return (double)(rand()) / ((double)(RAND_MAX/(2)));
}