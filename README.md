# C++ Vector Manipulation

This repository contains C++ code for manipulating 3D vectors and arrays of vectors.

## Contents

- [Introduction](#introduction)
- [Functions and Procedures](#functions-and-procedures)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction

This C++ project demonstrates various operations on 3D vectors, including calculating the norm, normalizing, adding, and more. It also includes functions for working with arrays of vectors, such as concatenation and reversal.

## Functions and Procedures

### Vector Operations

- `Vecteur3DGetNorme`: Calculates the norm (magnitude) of a vector.
- `Vecteur3DNormaliser`: Normalizes a vector to have a norm of 1.
- `Vecteur3DEstNormalise`: Checks if a vector is normalized.
- `Vecteur3DAdd`: Adds two vectors.
- `Vecteur3DAfficher`: Displays a vector in the format (x, y, z).

### Array Operations

- `Vecteur3DRemplirTabVecteurs`: Fills an array of vectors with random values.
- `Vecteur3DAfficherTabVecteurs`: Displays an array of vectors.
- `Vecteur3DMaxTabVecteurs`: Finds the index of the vector with the largest norm in an array.

### Array Manipulation

- `Vecteur3DConcatenationTabVecteurs`: Concatenates two arrays of vectors.
- `Vecteur3DInverseTabVecteurs`: Reverses the contents of an array of vectors.

## Usage

You can use this code to perform various operations on 3D vectors and arrays of vectors. The provided functions and procedures are documented within the code.

To compile and run the program, use a C++ compiler such as g++:

```bash
g++ Vecteur3D.cpp -o Vecteur3D.out
./Vecteur3D.out
