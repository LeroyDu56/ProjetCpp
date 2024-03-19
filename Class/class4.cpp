#include <iostream>

using namespace std;

class Velocity {
private:
    float linear_x;
    float linear_y;
    float linear_z;
    float angular_x;
    float angular_y;
    float angular_z;

public:
    // Constructeur par défaut
    Velocity() {
        cout << "Création Velocity" << endl;
        linear_x = 0.0;
        linear_y = 0.0;
        linear_z = 0.0;
        angular_x = 0.0;
        angular_y = 0.0;
        angular_z = 0.0;
    }

    // Destructeur
    ~Velocity() {
        cout << "Destruction Velocity" << endl;
    }

    // Méthode pour afficher les valeurs des attributs
    void Display() {
        cout << "linear x = " << linear_x << endl;
        cout << "angular z = " << angular_z << endl;
    }
};

int main(int argc, char **argv) {
    Velocity cmd_vel;

    cmd_vel.Display();

    return 0;
}
