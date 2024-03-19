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
}; // Ajout du point-virgule pour terminer la définition de la classe

int main(int argc, char **argv)
{
    Velocity cmd_vel;

    cout << "linear x = " << cmd_vel.linear_x;
    cout << "angular z = " << cmd_vel.angular_z;

    return 0;
}
