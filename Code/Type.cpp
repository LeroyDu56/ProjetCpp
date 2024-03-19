#include <iostream>
#include <cstdlib>

void displayType1() {
    std::cout << "=> Type 1: Robot Engine Start" << std::endl;
}

void displayType0() {
    std::cout << "=> Type 0: Robot Engine Stop" << std::endl;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Error: bad parameter" << std::endl;
        return 1;
    }

    // Convertir le paramètre en entier
    int parametre = std::atoi(argv[1]);

    if (parametre == 1) {
        displayType1();
    } else if (parametre == 0) {
        displayType0();
    } else {
        std::cout << "=> Error: parameter must be 0 or 1" << std::endl;
        return 1;
    }

    return 0;
}
