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
        cout << "Objet Velocity créé." << endl;
    }

    ~Velocity() {
        cout << "Objet Velocity détruit." << endl;
    }

    void Display() {
        auto now = chrono::system_clock::now();
        auto now_as_time_t = chrono::system_clock::to_time_t(now);
        auto now_ms = chrono::duration_cast<chrono::milliseconds>(now.time_since_epoch()) % 1000;
        cout << put_time(localtime(&now_as_time_t), "%H:%M:%S.") << setfill('0') << setw(3) << now_ms.count()
             << " Vitesse linéaire : " << linear_x << ", Vitesse angulaire : " << angular_z << endl;
    }

    void MoveForward(float speed, int milliseconds) {
        linear_x = speed;
        Display();
        this_thread::sleep_for(chrono::milliseconds(milliseconds));
    }

    void Turn(float speed, int milliseconds) {
        angular_z = speed;
        Display();
        this_thread::sleep_for(chrono::milliseconds(milliseconds));
    }

    void Stop() {
        linear_x = 0;
        angular_z = 0;
        Display();
    }

    // Bonus : Méthode pour déplacer le robot en diagonale
    void MoveDiagonal(float speed, int milliseconds) {
        linear_x = speed;
        angular_z = speed;
        Display();
        this_thread::sleep_for(chrono::milliseconds(milliseconds));
        Stop();
    }
};

int main(int argc, char **argv) {
    Velocity cmd_vel;

    // Exécution de la séquence principale
    cmd_vel.MoveForward(1.5, 2000);
    cmd_vel.Turn(2.7, 1000);
    cmd_vel.MoveForward(1.5, 2000);
    cmd_vel.Turn(2.7, 1000);
    cmd_vel.MoveForward(1.5, 2000);

    // Exécution de l'objectif bonus
    cmd_vel.MoveDiagonal(1.5, 3000); // Avancer en diagonale

    return 0;
}
