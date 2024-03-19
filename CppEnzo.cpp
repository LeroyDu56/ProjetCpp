#include <iostream> 

using namespace std;

class Velocity {
    public:
        float linear_x; 
        float linear_y; 
        float linear_z; 
        float angular_x; 
        float angluar_y; 
        float angular_z;
};

int main(int argc, char **argv)
{ 
    Velocity cmd_vel;
    cout << "linear x = " << cmd_vel.linear_x << endl;
    cout << "angular z =" << cmd_vel.angular_z << endl;
return 0;
}