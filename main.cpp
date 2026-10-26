
/*
 * ECE 231L - Assignment 7
 * Working with Classes
 *
 * Description:
 * This program uses Electric_Field and Magnetic_Field
 * classes to manage three-dimensional field vectors.
 * It calculates magnitudes, the electric field inner
 * product, and the magnetic field unit vector.
 */

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// CLASS 1: ELECTRIC FIELD

class Electric_Field
{
private:
    // Pointer to dynamically allocated array.
    // E[0] = x, E[1] = y, E[2] = z.
    double *E;

public:
    // Default constructor.
    // Allocate memory and initialize all
    // three electric-field components to zero.
    Electric_Field()
    {
        E = new double[3];

        E[0] = 0.0;
        E[1] = 0.0;
        E[2] = 0.0;
    }

    // Constructor accepting three components.
    Electric_Field(double x, double y, double z)
    {
        E = new double[3];

        E[0] = x;
        E[1] = y;
        E[2] = z;
    }

    // Copy constructor.
    // Make an independent copy of the array.
    Electric_Field(const Electric_Field &other)
    {
        E = new double[3];

        for (int i = 0; i < 3; i++)
        {
            E[i] = other.E[i];
        }
    }

    // Copy assignment operator.
    // Copy components without sharing memory.
    Electric_Field &operator=(const Electric_Field &other)
    {
        if (this != &other)
        {
            for (int i = 0; i < 3; i++)
            {
                E[i] = other.E[i];
            }
        }

        return *this;
    }

    // Destructor.
    // Release dynamically allocated memory.
    ~Electric_Field()
    {
        delete[] E;
    }

    // Setter functions.
    void setX(double x)
    {
        E[0] = x;
    }

    void setY(double y)
    {
        E[1] = y;
    }

    void setZ(double z)
    {
        E[2] = z;
    }

    // Getter functions.
    double getX() const
    {
        return E[0];
    }

    double getY() const
    {
        return E[1];
    }

    double getZ() const
    {
        return E[2];
    }

    // Calculate electric-field magnitude.
    double calculateMagnitude() const
    {
        return sqrt(E[0] * E[0] +
                    E[1] * E[1] +
                    E[2] * E[2]);
    }

    // Electric-field-specific function.
    // Calculate the inner product E dot E.
    double calculateInnerProduct() const
    {
        return E[0] * E[0] +
               E[1] * E[1] +
               E[2] * E[2];
    }
};


// CLASS 2: MAGNETIC FIELD

class Magnetic_Field
{
private:
    // Pointer to dynamically allocated array.
    // B[0] = x, B[1] = y, B[2] = z.
    double *B;

public:
    // Default constructor.
    Magnetic_Field()
    {
        B = new double[3];

        B[0] = 0.0;
        B[1] = 0.0;
        B[2] = 0.0;
    }

    // Constructor accepting three components.
    Magnetic_Field(double x, double y, double z)
    {
        B = new double[3];

        B[0] = x;
        B[1] = y;
        B[2] = z;
    }

    // Copy constructor.
    Magnetic_Field(const Magnetic_Field &other)
    {
        B = new double[3];

        for (int i = 0; i < 3; i++)
        {
            B[i] = other.B[i];
        }
    }

    // Copy assignment operator.
    Magnetic_Field &operator=(const Magnetic_Field &other)
    {
        if (this != &other)
        {
            for (int i = 0; i < 3; i++)
            {
                B[i] = other.B[i];
            }
        }

        return *this;
    }

    // Destructor.
    // Free the dynamically allocated array.
    ~Magnetic_Field()
    {
        delete[] B;
    }

    // Setter functions.
    void setX(double x)
    {
        B[0] = x;
    }

    void setY(double y)
    {
        B[1] = y;
    }

    void setZ(double z)
    {
        B[2] = z;
    }

    // Getter functions.
    double getX() const
    {
        return B[0];
    }

    double getY() const
    {
        return B[1];
    }

    double getZ() const
    {
        return B[2];
    }

    // Calculate magnetic-field magnitude.
    double calculateMagnitude() const
    {
        return sqrt(B[0] * B[0] +
                    B[1] * B[1] +
                    B[2] * B[2]);
    }

    // Magnetic-field-specific function.
    // Calculate and print the unit vector.
    void calculateUnitVector() const
    {
        double magnitude = calculateMagnitude();

        // A zero vector has no unit vector.
        if (magnitude == 0.0)
        {
            cout << "Unit vector is undefined "
                 << "for a zero magnetic field."
                 << endl;
            return;
        }

        double unitX = B[0] / magnitude;
        double unitY = B[1] / magnitude;
        double unitZ = B[2] / magnitude;

        cout << "Magnetic field unit vector: ("
             << unitX << ", "
             << unitY << ", "
             << unitZ << ")" << endl;
    }
};


int main()
{
    // Display numerical results with 4 decimals.
    cout << fixed << setprecision(4);

    cout << "ECE 231L - Assignment 7" << endl;
    cout << "Working with Classes" << endl;

    // Create an electric field using the default constructor

    Electric_Field E_default;

    cout << "\n--- Electric Field: Default Constructor ---"
         << endl;

    // Set components using setter functions.
    E_default.setX(3.0);
    E_default.setY(4.0);
    E_default.setZ(12.0);

    // Print components using getter functions.
    cout << "Electric field components: ("
         << E_default.getX() << ", "
         << E_default.getY() << ", "
         << E_default.getZ() << ")" << endl;

    cout << "Electric field magnitude: "
         << E_default.calculateMagnitude() << endl;

    // Call the class-specific function.
    cout << "Electric field inner product: "
         << E_default.calculateInnerProduct() << endl;


    // ELECTRIC FIELD OBJECT 2
    // Using the parameterized constructor.

    Electric_Field E_components(1e5, 10.9, 1.7e2);

    cout << "\n--- Electric Field: Component Constructor ---"
         << endl;

    cout << "Electric field components: ("
         << E_components.getX() << ", "
         << E_components.getY() << ", "
         << E_components.getZ() << ")" << endl;

    cout << "Electric field magnitude: "
         << E_components.calculateMagnitude() << endl;

    cout << "Electric field inner product: "
         << E_components.calculateInnerProduct() << endl;

    // MAGNETIC FIELD OBJECT 1
    // Using the default constructor.

    Magnetic_Field B_default;

    cout << "\n--- Magnetic Field: Default Constructor ---"
         << endl;

    // Set components using setter functions.
    B_default.setX(2.0);
    B_default.setY(3.0);
    B_default.setZ(6.0);

    // Print components using getter functions.
    cout << "Magnetic field components: ("
         << B_default.getX() << ", "
         << B_default.getY() << ", "
         << B_default.getZ() << ")" << endl;

    cout << "Magnetic field magnitude: "
         << B_default.calculateMagnitude() << endl;

    // Call the class-specific function.
    B_default.calculateUnitVector();

    // MAGNETIC FIELD OBJECT 2
    // Using the parameterized constructor.

    Magnetic_Field B_components(1.0, 2.0, 2.0);

    cout << "\n--- Magnetic Field: Component Constructor ---"
         << endl;

    cout << "Magnetic field components: ("
         << B_components.getX() << ", "
         << B_components.getY() << ", "
         << B_components.getZ() << ")" << endl;

    cout << "Magnetic field magnitude: "
         << B_components.calculateMagnitude() << endl;

    B_components.calculateUnitVector();

    // Demonstrate the zero-vector case.

    Magnetic_Field B_zero;

    cout << "\n--- Zero Magnetic Field ---" << endl;

    cout << "Magnetic field magnitude: "
         << B_zero.calculateMagnitude() << endl;

    B_zero.calculateUnitVector();

    // Demonstrate deep copying.

    Electric_Field E_copy = E_default;

    cout << "\n--- Electric Field Copy ---" << endl;

    cout << "Copied electric field magnitude: "
         << E_copy.calculateMagnitude() << endl;

    // Destructors automatically free memory
    // when the objects go out of scope.

    cout << "\nProgram completed successfully."
         << endl;

    return 0;
}
