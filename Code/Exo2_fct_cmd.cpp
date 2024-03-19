#include <iostream>
#include <unistd.h>
#include <termios.h>

// For non-blocking keyboard inputs
int getch(void) {
    int ch;
    struct termios oldt, newt;

    // Store old settings, and copy to new settings
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    // Make required changes and apply the settings
    newt.c_lflag &= ~(ICANON | ECHO | ECHOK | ECHOE | ECHONL | ISIG | IEXTEN);
    newt.c_iflag &= ~(INLCR | ICRNL | IXON | IXOFF);
    newt.c_iflag |= IGNBRK;
    newt.c_cc[VMIN] = 1;
    newt.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // Get the current character
    ch = getchar();

    // Reapply old settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}

int main() {
    int vitesse = 0;
    char commande;
    int numCommande = 0;

    std::cout << "Debut du programme." << std::endl;
    
    while (true) {
        char c = getch();
        numCommande++;
        
        if (c == 'q') {
            std::cout << "Sortie du programme." << std::endl;
            break;
        } else if (c == 'a') {
            vitesse = std::min(vitesse + 2, 20);
        } else if (c == 'z') {
            vitesse = std::max(vitesse - 2, 0);
        }

        std::cout << "Commande " << numCommande << ": Touche " << c << ", Vitesse courante: " << vitesse << std::endl;
    }

    return 0;
}
