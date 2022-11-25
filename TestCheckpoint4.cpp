#include "Model.h"

using namespace std;

int main(){
    Model m1;

    m1.ShowStatus();
    View v1;
    v1.Clear();
    m1.Display(v1);
    v1.Draw();

    return 0;
}