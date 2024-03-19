#include <iostream>

using namespace std;

class Velocity {
public:
    float linear_x;
    float linear_y;
    float linear_z;
    float angular_x;
    float angular_y;
    float angular_z;

    Velocity(){
        cout << " Création Velocity " << endl;
        linear_x = 0.0;
        linear_y = 0.0;
        linear_z = 0.0;
        angular_x = 0.0;
        angular_y = 0.0;
        angular_z = 0.0;
    }
    ~Velocity(){
        cout << " Destruction Velocity " << endl;
    }
}; 
