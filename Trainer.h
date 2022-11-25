#ifndef Trainer_h
#define Trainer_h

#include "GameObject.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Point2D.h"
#include "Vector2D.h"
#include <string>
#include <math.h>

enum TrainerStates {
    STOPPED = 0,
    MOVING = 1,
    FAINTED = 2,
    AT_CENTER = 3,
    IN_GYM = 4,
    MOVING_TO_CENTER = 5,
    MOVING_TO_GYM = 6,
    BATTLING_IN_GYM = 7,
    RECOVERING_HEALTH = 8
};

class Trainer: public GameObject {
    private: 
        double speed;
        bool is_at_center = false;
        bool is_IN_GYM = false;
        unsigned int health = 20;
        unsigned int experience = 0;
        double PokeDollars = 0;
        unsigned int battles_to_buy = 0;
        unsigned int potions_to_buy = 0;
        string name;
        PokemonCenter* current_center = NULL;
        PokemonGym* current_gym = NULL;
        Point2D destination;
        Vector2D delta;
    protected:
        bool UpdateLocation();
        void SetupDestination(Point2D dest);
    public:
        Trainer();
        Trainer(char in_code);
        Trainer(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc);
        virtual ~Trainer();
        void StartMoving(Point2D dest);
        void StartMovingToGym(PokemonGym* gym);
        void StartMovingToCenter(PokemonCenter* center);
        void StartBattling(unsigned int num_battles);
        void StartRecoveringHealth(unsigned int num_potions);
        void Stop();
        bool HasFainted();
        bool ShouldBeVisible();
        void ShowStatus();
        bool Update();
        string GetTrainerName();
};

double GetRandomAmountOfPokeDollars();

#endif