#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

class ComplexNumber {
private:
    double real;     // Real part
    double imag;     // Imaginary part

public:
    // Default constructor
    ComplexNumber() : real(0.0), imag(0.0) {}

    // Constructor with initialization
    ComplexNumber(double realPart, double imaginaryPart) : real(realPart), imag(imaginaryPart) {}

    // Copy constructor
    ComplexNumber(const ComplexNumber &c) : real(c.real), imag(c.imag) {} // NOLINT(*-use-equals-default)

    // Destructor
    ~ComplexNumber() {}

    // Assignment operator overloading
    ComplexNumber& operator=(const ComplexNumber& other) {
        if (this != &other) { // Check for self-assignment
            real = other.real;
            imag = other.imag;
        }
        return *this;
    }

    // Method to input a complex number from the keyboard
    void InputComplexNumber() {
        std::cout << "Enter the real part: ";
        std::cin >> real;
        std::cout << "Enter the imaginary part: ";
        std::cin >> imag;
    }

    // Method to display the complex number
    void DisplayComplex() const {
        if (imag >= 0) {
            std::cout << real << " + " << imag << "i" << std::endl;
        } else {
            std::cout << real << " - " << -imag << "i" << std::endl;
        }
    }

    // Method to multiply the complex number by another complex number
    void Multiply(const ComplexNumber &complex) {
        double newReal = (real * complex.real) - (imag * complex.imag);
        double newImag = (imag * complex.real) + (real * complex.imag);
        real = newReal;
        imag = newImag;
    }

    // Method to calculate the module (magnitude) of the complex number
    double Module() const {
        return sqrt((pow(real, 2) + pow(imag, 2)));
    }

    // Method to compare two complex numbers by their module
    bool IsSmaller(const ComplexNumber &complex1, const ComplexNumber &complex2) const {
        return complex1.Module() < complex2.Module();
    }
};

// Function to perform selection sort on an array of complex numbers based on module
void SelectionSort(ComplexNumber *array, int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (array[j].Module() < array[minIndex].Module()) {
                minIndex = j;
            }
        }
        // Swap elements
        ComplexNumber temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
    }
}

// Function to perform insertion sort on an array of complex numbers based on module
void SortByInsertion(ComplexNumber *array, int size) {
    for (int i = 1; i < size; ++i) {
        ComplexNumber key = array[i];
        int j = i - 1;

        // Move elements of array[0.i-1] that are greater than key.module()
        // to one position ahead of their current position
        while (j >= 0 && array[j].Module() > key.Module()) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

// Function to perform bubble sort on an array of complex numbers based on module
void BubbleSort(ComplexNumber *array, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (array[j].Module() > array[j + 1].Module()) {
                // Échange les éléments si ils sont dans le mauvais ordre
                ComplexNumber temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main() {
    // Create an initial complex number
    ComplexNumber complexNumber1;
    std::srand(static_cast<unsigned>(std::time(nullptr))); // Initialize random number generation

    int size;
    std::cout << "Enter the size of the array of complex numbers: ";
    std::cin >> size;

    // Allocate memory for the array of complex numbers
    ComplexNumber* complexArray = new ComplexNumber[size];

    // Fill the array with random complex numbers
    for (int i = 0; i < size; ++i) {
        double realPart = static_cast<double>(std::rand()) / RAND_MAX * 20.0 - 10.0; // Real part between -10 and 10
        double imaginaryPart = static_cast<double>(std::rand()) / RAND_MAX * 20.0 - 10.0; // Imaginary part between -10 and 10
        complexArray[i] = ComplexNumber(realPart, imaginaryPart);
    }

    for (int i = 0; i < size; ++i) {
        std::cout << "Complex number: " << std::endl;
        complexArray[i].DisplayComplex();
        std::cout << "Module: " << std::endl;
        std::cout << complexArray[i].Module() << std::endl;
    }

    SelectionSort(complexArray, size);

    std::cout << "Sorted by selection" << std::endl;

    for (int i = 0; i < size; ++i) {
        std::cout << "Complex number: " << std::endl;
        complexArray[i].DisplayComplex();
        std::cout << "Module: " << std::endl;
        std::cout << complexArray[i].Module() << std::endl;
    }

    SortByInsertion(complexArray, size);

    std::cout << "Sorted by insertion" << std::endl;

    for (int i = 0; i < size; ++i) {
        std::cout << "Complex number: " << std::endl;
        complexArray[i].DisplayComplex();
        std::cout << "Module: " << std::endl;
        std::cout << complexArray[i].Module() << std::endl;
    }

    complexNumber1.InputComplexNumber();
    std::cout << "Initial complex number: ";
    complexNumber1.DisplayComplex();

    // Create a new complex number as a copy of the previous one
    ComplexNumber complexNumber2 = complexNumber1;
    std::cout << "Copied complex number: ";
    complexNumber2.DisplayComplex();

    // Create another complex number on the heap
    ComplexNumber *complexNumber3 = new ComplexNumber(3.0, 4.0);
    std::cout << "Complex number on the heap: ";
    complexNumber3->DisplayComplex();

    // Multiply the two complex numbers
    complexNumber1.Multiply(*complexNumber3);
    std::cout << "Result of multiplication: ";
    complexNumber1.DisplayComplex();

    // Free memory for the complex number on the heap
    delete complexNumber3;
    delete[] complexArray;

    return 0;
}
