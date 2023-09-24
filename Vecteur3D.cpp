#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// Define a structure Vecteur3D that contains three real fields (x, y, and z).
struct Vecteur3D {
    double x;
    double y;
    double z;
};

// Function to calculate the norm of a vector.
double Vecteur3DGetNorme(Vecteur3D vector) {
    return sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
}

// Procedure to normalize a vector.
void Vecteur3DNormaliser(Vecteur3D &vector) {
    double norm = Vecteur3DGetNorme(vector);
    vector.x /= norm;
    vector.y /= norm;
    vector.z /= norm;
}

// Function to check if a vector is normalized.
bool Vecteur3DEstNormalise(Vecteur3D vector) {
    return abs(Vecteur3DGetNorme(vector) - 1.0) < 1e-6; // Using a small epsilon for comparison
}

// Function to add two vectors.
Vecteur3D Vecteur3DAdd(Vecteur3D vector1, Vecteur3D vector2) {
    Vecteur3D result;
    result.x = vector1.x + vector2.x;
    result.y = vector1.y + vector2.y;
    result.z = vector1.z + vector2.z;
    return result;
}

// Procedure to display a vector in the format (x, y, z).
void Vecteur3DAfficher(Vecteur3D vector) {
    cout << "(" << vector.x << "," << vector.y << "," << vector.z << ")";
}

// Procedure to fill an array of vectors with random values.
void Vecteur3DRemplirTabVecteurs(Vecteur3D *tab, int size) {
    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 0; i < size; i++) {
        tab[i].x = (rand() / (double)RAND_MAX) * 20.0 - 10.0;
        tab[i].y = (rand() / (double)RAND_MAX) * 20.0 - 10.0;
        tab[i].z = (rand() / (double)RAND_MAX) * 20.0 - 10.0;
    }
}

// Procedure to display an array of vectors.
void Vecteur3DAfficherTabVecteurs(Vecteur3D *tab, int size) {
    for (int i = 0; i < size; i++) {
        Vecteur3DAfficher(tab[i]);
        if (i < size - 1) {
            cout << " ; ";
        }
    }
    cout << endl;
}

// Function to find the index of the vector with the largest norm in an array of vectors.
int Vecteur3DMaxTabVecteurs(Vecteur3D *tab, int size) {
    double maxNorm = -1.0;
    int maxIndex = -1;
    for (int i = 0; i < size; i++) {
        double norm = Vecteur3DGetNorme(tab[i]);
        if (norm > maxNorm) {
            maxNorm = norm;
            maxIndex = i;
        }
    }
    return maxIndex;
}

// Procedure to concatenate two arrays of vectors into a third array.
void Vecteur3DConcatenationTabVecteurs(Vecteur3D *tab1, int size1, Vecteur3D *tab2, int size2, Vecteur3D *result) {
    for (int i = 0; i < size1; i++) {
        result[i] = tab1[i];
    }
    for (int i = 0; i < size2; i++) {
        result[size1 + i] = tab2[i];
    }
}

// Procedure to reverse the contents of an array of vectors.
void Vecteur3DInverseTabVecteurs(Vecteur3D *tab, int size) {
    int start = 0;
    int end = size - 1;
    while (start < end) {
        // Swap the vectors at start and end indices
        //meilleur algorithme wollah
        Vecteur3D temp = tab[start];
        tab[start] = tab[end];
        tab[end] = temp;
        start++;
        end--;
    }
}

int main() {

    //main exo 5
    // Create two arrays of vectors with random values
    const int arraySize1 = 5;
    const int arraySize2 = 6;
    Vecteur3D tab1[arraySize1];
    Vecteur3D tab2[arraySize2];
    Vecteur3DRemplirTabVecteurs(tab1, arraySize1);
    Vecteur3DRemplirTabVecteurs(tab2, arraySize2);

    // Display the arrays of vectors
    cout << "Tableau 1 de vecteurs aleatoires : ";
    Vecteur3DAfficherTabVecteurs(tab1, arraySize1);
    cout << "Tableau 2 de vecteurs aleatoires : ";
    Vecteur3DAfficherTabVecteurs(tab2, arraySize2);

    // Create an array to store the concatenated vectors
    const int concatenatedSize = arraySize1 + arraySize2;
    Vecteur3D tabConcatenated[concatenatedSize];

    // Concatenate the two arrays of vectors
    Vecteur3DConcatenationTabVecteurs(tab1, arraySize1, tab2, arraySize2, tabConcatenated);

    // Display the concatenated array of vectors
    cout << "Tableau concatene de vecteurs : ";
    Vecteur3DAfficherTabVecteurs(tabConcatenated, concatenatedSize);

    // Reverse the concatenated array of vectors
    Vecteur3DInverseTabVecteurs(tabConcatenated, concatenatedSize);

    // Display the reversed array of vectors
    cout << "Tableau inverse de vecteurs : ";
    Vecteur3DAfficherTabVecteurs(tabConcatenated, concatenatedSize);

    //auther

    // Create two vectors
    Vecteur3D vecteur1 = {5, 2, 1};
    Vecteur3D vecteur2 = {0, 3, 2};

    cout << "vecteur1 non normalise: ";
    Vecteur3DAfficher(vecteur1);
    cout << endl;
    cout << "vecteur2 non normalise: ";
    Vecteur3DAfficher(vecteur2);
    cout << endl;

    // Calculate and display the sum of vectors
    cout << "somme: ";
    Vecteur3DAfficher(Vecteur3DAdd(vecteur1, vecteur2));
    cout << endl;

    // Normalize vectors
    Vecteur3DNormaliser(vecteur1);
    Vecteur3DNormaliser(vecteur2);

    cout << "vecteur1 normalise: ";
    Vecteur3DAfficher(vecteur1);
    cout << endl;
    cout << "vecteur2 normalise: ";
    Vecteur3DAfficher(vecteur2);
    cout << endl;

    // Calculate and display the sum of vectors after normalization
    Vecteur3D somme = Vecteur3DAdd(vecteur1, vecteur2);
    cout << "somme: ";
    Vecteur3DAfficher(somme);

    if (Vecteur3DEstNormalise(somme)) {
        cout << " est normalise" << endl;
    } else {
        cout << " n'est pas normalise" << endl;
    }

    // Create an array of 10 random vectors
    const int arraySize = 10;
    Vecteur3D tab[arraySize];
    Vecteur3DRemplirTabVecteurs(tab, arraySize);

    // Display the array of vectors
    cout << "Tableau de vecteurs aleatoires : ";
    Vecteur3DAfficherTabVecteurs(tab, arraySize);

    // Find and display the index of the vector with the largest norm
    int maxIndex = Vecteur3DMaxTabVecteurs(tab, arraySize);
    cout << "Le vecteur de plus grande norme est a l'indice " << maxIndex << ": ";
    Vecteur3DAfficher(tab[maxIndex]);
    cout << endl;

    return 0;
}
