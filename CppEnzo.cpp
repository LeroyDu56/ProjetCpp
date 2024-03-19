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
    Velocity() : linear_x(0), angular_z(0) {
        cout << "Creation Velocity" << endl;
    }

    ~Velocity(){
        cout << "Destruction Velocity" << endl;
    }

    void Display() {
        // Obtention de l'heure actuelle avec précision jusqu'aux millisecondes
        auto now = chrono::system_clock::now();
        auto now_as_time_t = chrono::system_clock::to_time_t(now);
        auto now_ms = chrono::duration_cast<chrono::milliseconds>(now.time_since_epoch()) % 1000;

        // Affichage de l'heure, des millisecondes et des vitesses
        cout << put_time(localtime(&now_as_time_t), "%H:%M:%S.") << setfill('0') << setw(3) << now_ms.count()
             << " linear x=" << linear_x << " angular z=" << angular_z << endl;
    }

    void Avance(float speed, int milliseconds) {
        // S'assurer que le mouvement angulaire est nul avant de commencer à avancer
        angular_z = 0;
        linear_x = speed;
        Display();
        this_thread::sleep_for(chrono::milliseconds(milliseconds));
    }

    void Tourne(float speed, int milliseconds) {
        // S'assurer que le mouvement linéaire est nul avant de commencer à tourner
        linear_x = 0;
        angular_z = speed;
        Display();
        this_thread::sleep_for(chrono::milliseconds(milliseconds));
    }

    void Stop() {
        linear_x = 0;
        angular_z = 0;
        Display();
    }
};

int main(int argc, char **argv) {
    Velocity cmd_vel;

    // Séquence de mouvements respectant le cycle 2s, 1s, 2s, 1s, 2s
    cmd_vel.Avance(1.5, 2000); // Premier segment
    cmd_vel.Tourne(2.7, 1000); // Premier virage à 90 degrés
    cmd_vel.Avance(1.5, 2000); // Traversée du fond du "U" inversé
    cmd_vel.Tourne(2.7, 1000); // Second virage à 90 degrés
    cmd_vel.Avance(1.5, 2000); // Dernier segment vertical
    cmd_vel.Stop();
}