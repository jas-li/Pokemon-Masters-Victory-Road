#include <iostream>
#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "Building.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"

using namespace std;

int main(){
    Point2D p1(1.2, 3.4);
    Point2D p2(2.2, 8.2);
    Point2D p3(4.2, 1.6);

    cout << "Testing Building" << endl;
    cout << endl;

    Building b1;
    Building b2('b', 1, p1);
    b1.AddOneTrainer();
    b1.RemoveOneTrainer();
    b1.RemoveOneTrainer();
    b1.ShowStatus();
    cout << b2.ShouldBeVisible() << endl;

    cout << endl;
    cout << "Testing PokemonCenter" << endl;
    cout << endl;

    PokemonCenter c1;
    PokemonCenter c2(4, 5, 20, p2);
    c1.ShowStatus();
    c2.ShowStatus();

    cout << endl;
    cout << "Testing PokemonGym" << endl;
    cout << endl;

    PokemonGym g1;
    PokemonGym g2(6, 8, 20.3, 2, 9, p2);
    g1.ShowStatus();
    g2.ShowStatus();

    return 0;





    // //
    // Point2D firstpoint;
    // firstpoint.x=1;
    // firstpoint.y=1;
    
    // //Testing GameObject.cpp
    // int in_id= 2;
    // char in_code='b';
    // GameObject game1(firstpoint, in_id, in_code);
    // GameObject game2('Z');
    // Point2D newpoint=game1.GetLocation();
    // cout << newpoint << endl;
    // int id2= game2.GetId();
    // int id1= game1.GetId();
    // //cout<< id1<< " "<<id2<< endl;
    
    // //Testing building.cpp
    // Building B1(in_code, in_id, firstpoint);
    // B1.AddOneTrainer();
    // B1.ShowStatus();
    
    // //Testing PokemonCenter
    // //Figure out why idnum prints a weird number
    // PokemonCenter Center1;
    // PokemonCenter Center2(2,5,10,firstpoint);
    // bool decision=Center1.HasPotions();
    // cout<< decision <<endl;
    // unsigned int remains=Center1.GetNumPotionRemaining();
    // cout<<remains<<endl;
    // int potion=4;
    // double budget=20.0;
    // decision=Center1.CanAffordPotion(potion,budget);
    // cout<<decision<<endl;
    // double cost_potion=Center1.GetPokeDollarCost(potion);
    // cout<<cost_potion<<endl;
    // remains=Center1.Update();
    // cout<<remains<<endl;
    // Center1.ShowStatus();
    // Center2.ShowStatus();
    
    // //Testing PokemonGym
    // PokemonGym Gym1;
    // Gym1.ShowStatus();
}
