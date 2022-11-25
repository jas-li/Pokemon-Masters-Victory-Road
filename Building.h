#ifndef Building_h
#define Building_h

#include "GameObject.h"
#include "Point2D.h"

class Building: public GameObject {
    private: 
        unsigned int trainer_count = 0;

    public: 
        Building();
        Building(char in_code, int in_Id, Point2D in_loc);
        void AddOneTrainer();
        void RemoveOneTrainer();
        void ShowStatus();
        bool ShouldBeVisible();
};

#endif