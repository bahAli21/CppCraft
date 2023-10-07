#include <iostream>

// Definition of the NombreReel structure
struct NombreReel {
    bool type; // true for single precision, false for double precision
    float single; // number in single precision
    double doublep; // number in double precision
};

// Procedure to input a NombreReel
void inputNombreReel(NombreReel &nombreReel) {
    std::cout << "Enter the type of the number (S for single precision, D for double precision): ";
    char choice;
    std::cin >> choice;

    if (choice == 'S' || choice == 's') {
        nombreReel.type = true;
        std::cout << "Enter the number in single precision: ";
        std::cin >> nombreReel.single;
    } else {
        nombreReel.type = false;
        std::cout << "Enter the number in double precision: ";
        std::cin >> nombreReel.doublep;
    }
}

// Procedure to display a NombreReel
void displayNombreReel(const NombreReel &nombreReel) {
    if (nombreReel.type) {
        std::cout << nombreReel.single << " (single precision)" << std::endl;
    } else {
        std::cout << nombreReel.doublep << " (double precision)" << std::endl;
    }
}

// Procedure to convert a NombreReel to the other precision type
void convertNombreReel(NombreReel &nombreReel) {
    if (nombreReel.type) {
        // Conversion from single precision to double precision
        nombreReel.doublep = static_cast<double>(nombreReel.single);
        nombreReel.type = false;
    } else {
        // Conversion from double precision to single precision
        nombreReel.single = static_cast<float>(nombreReel.doublep);
        nombreReel.type = true;
    }
}

int main() {
    NombreReel number;

    // Input a real number in single precision
    inputNombreReel(number);

    // Display the real number in single precision
    displayNombreReel(number);

    // Convert it to double precision
    convertNombreReel(number);

    // Display the real number in double precision
    displayNombreReel(number);

    return 0;
}
