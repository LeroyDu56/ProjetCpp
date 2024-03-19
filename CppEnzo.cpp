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

    ~Velocity() {
        cout << "Destruction Velocity" << endl;
    }

    void Display() {
        auto now = chrono::system_clock::now();
        auto now_as_time_t = chrono::system_clock::to_time_t(now);
        auto now_ms = chrono::duration_cast<chrono::milliseconds>(now.time_since_epoch()) % 1000;
        cout << put_time(localtime(&now_as_time_t), "%H:%M:%S.") << setfill('0') << setw(3) << now_ms.count()
             << " linear x=" << linear_x << " angular z=" << angular_z << endl;
    }

    void Avance(float speed, int milliseconds) {
        linear_x = speed;
        Display();
        this_thread::sleep_for(chrono::milliseconds(milliseconds));
        Stop();
    }

    void Tourne(float speed, int milliseconds) {
        angular_z = speed;
        Display();
        this_thread::sleep_for(chrono::milliseconds(milliseconds));
        Stop();
    }

    void Stop() {
        linear_x = 0;
        angular_z = 0;
        Display();
    }

    // Méthode pour exécuter le parcours complet
    void ExecutePath() {
        MoveForwardAndStop(2000); // Premier segment vertical
        TurnAndStop(1000);        // Premier virage à 90 degrés
        MoveForwardAndStop(2000); // Fond du "U" inversé
        TurnAndStop(1000);        // Deuxième virage à 90 degrés
        MoveForwardAndStop(2000); // Dernier segment vertical
    }

private:
    void MoveForwardAndStop(int milliseconds) {
        Avance(1.5, milliseconds);
    }

    void TurnAndStop(int milliseconds) {
        Tourne(2.7, milliseconds);
    }
};

int main(int argc, char **argv) {
    Velocity cmd_vel;

    // Appel de la méthode orchestrant le parcours complet
    cmd_vel.ExecutePath();

    return 0;
}
