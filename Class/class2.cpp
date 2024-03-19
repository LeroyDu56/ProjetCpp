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
}; 

int main(int argc, char **argv) {
    Velocity cmd_vel;

    // Initialisation des membres de la classe Velocity
    cmd_vel.linear_x = 0.0;
    cmd_vel.linear_y = 0.0;
    cmd_vel.linear_z = 0.0;
    cmd_vel.angular_x = 0.0;
    cmd_vel.angular_y = 0.0;
    cmd_vel.angular_z = 0.0;

    // Affichage des valeurs des membres de la classe Velocity
    cout << "linear x = " << cmd_vel.linear_x << endl;
    cout << "angular z = " << cmd_vel.angular_z << endl;

    return 0;
}
