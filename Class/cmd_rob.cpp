#include <iostream>
#include <chrono> // Pour utiliser std::chrono::milliseconds
#include <thread> // Pour utiliser std::this_thread::sleep_for

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
        cout << "linear x = " << linear_x << ", angular z = " << angular_z << endl;
    }

    // Méthode pour passer la vitesse linéaire sur l'axe des X à 1,5
    void Avance(int milliseconds) {
        linear_x = 1.5;
        angular_z = 0.0;
        Display();
        std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
    }

    // Méthode pour passer la vitesse angulaire sur l'axe des Z à 2,7 et la vitesse linéaire sur l'axe des X à 0,5
    void Tourne(int milliseconds) {
        linear_x = 0.5;
        angular_z = 2.7;
        Display();
        std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
    }

    // Méthode pour passer toutes les vitesses à 0
    void Stop() {
        linear_x = 0.0;
        angular_z = 0.0;
        Display();
    }
};

int main(int argc, char **argv) {
    Velocity cmd_vel;

    // Séquence pour tracer un U inversé
    cmd_vel.Avance(1000);
    cmd_vel.Tourne(500);
    cmd_vel.Avance(1000);
    cmd_vel.Stop();
    cmd_vel.Tourne(500);
    cmd_vel.Avance(1000);

    return 0;
}
