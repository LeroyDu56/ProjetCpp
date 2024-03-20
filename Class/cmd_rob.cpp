#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>

using namespace std;

class Velocity {
private:
    float linear_x;
    float angular_z;

public:
    // Constructeur
    Velocity() : linear_x(0), angular_z(0) {
        cout << "Création de l'objet Velocity" << endl;
    }

    // Destructeur
    ~Velocity(){
        cout << "Destruction de l'objet Velocity" << endl;
    }

    // Afficher les vitesses
    void Display() {
        auto now = chrono::system_clock::now();
        auto now_as_time_t = chrono::system_clock::to_time_t(now);
        auto now_ms = chrono::duration_cast<chrono::milliseconds>(now.time_since_epoch()) % 1000;

        cout << put_time(localtime(&now_as_time_t), "%H:%M:%S.") << setfill('0') << setw(3) << now_ms.count()
             << " Vitesse linéaire : " << linear_x << ", Vitesse angulaire : " << angular_z << endl;
    }

    // Avancer avec une certaine vitesse pendant un certain nombre de millisecondes
    void MoveForward(float speed, int milliseconds) {
        angular_z = 0; // Assurer que le mouvement angulaire est nul
        linear_x = speed;
        Display();
        this_thread::sleep_for(chrono::milliseconds(milliseconds));
    }

    // Tourner avec une certaine vitesse pendant un certain nombre de millisecondes
    void Turn(float speed, int milliseconds) {
        linear_x = 0; // Assurer que le mouvement linéaire est nul
        angular_z = speed;
        Display();
        this_thread::sleep_for(chrono::milliseconds(milliseconds));
    }

    // Arrêter tous les mouvements
    void Stop() {
        linear_x = 0;
        angular_z = 0;
        Display();
    }
};

int main(int argc, char **argv) {
    Velocity cmd_vel;

    // Séquence de mouvements U inversée
    cmd_vel.MoveForward(1.5, 2000); // Premier segment
    cmd_vel.Turn(2.7, 1000);         // Premier virage à 90 degrés
    cmd_vel.MoveForward(1.5, 2000); // Traversée du fond du "U" inversé
    cmd_vel.Turn(2.7, 1000);         // Second virage à 90 degrés
    cmd_vel.MoveForward(1.5, 2000); // Dernier segment vertical
    cmd_vel.Stop();

    return 0;
}
