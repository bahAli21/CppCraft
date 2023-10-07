#include <iostream>
using namespace std;

class Person {
private:
    string name, firstName;
    long uniqNumber;

public:
    void inputInformation() {
        cout << "Enter the name : \n";
        cin >> this->name;
        cout << "Enter the first name : \n";
        cin >> this->firstName;
        cout << "Enter the secure number : \n";
        cin >> this->uniqNumber;
    }

    void displayPerson() const {
        cout << this->name <<" "<<this->firstName;
    }

    void displayPerson(const char sep) const {
        cout << this->name <<sep<<this->firstName;
    }

    //getter and setter

    string getName() const {
        return this->name;
    }

    void setName(string n) {
        this->name = n;
    }

    string getFirstName() const {
        return this->firstName;
    }

    void setFirstName(string f_n) {
        this->firstName = f_n;
    }

    long getSecureNumber() const {
        return this->uniqNumber;
    }

    void setSecureNumber(long s_n) {
        this->uniqNumber = s_n;
    }

};

class Point2D {
public:
    float x, y;

    Point2D(float a, float b) : x(a), y(b) {}

    ~Point2D(){}

     Point2D operator + (const Point2D & opRight) const {
         Point2D res{};
         res.x = this->x + opRight.x;
         res.y = this->y + opRight.y;
         return res;
    }

    Point2D operator - (const Point2D & opRight) const {
        Point2D res{};
        res.x = this->x - opRight.x;
        res.y = this->y - opRight.y;
        return res;
    }

    bool operator == (const Point2D & opRight) const {
        if(this->x == opRight.x && this->y == opRight.y)
            return true;
        return false;
    }

    Point2D & operator = (const Point2D & opRight) {
       this->x = opRight.x;
        this->y = opRight.y;
        return *this;
    }

    Point2D & operator ++ () {
        this->x = this->x + 1;
        this->y = this->y + 1;
        return *this;
    }

    bool operator ! () const {
        if(this->x == 0.0 && this->y == 0.0)
            return true;
        return false;
    }

    friend std::ostream& operator << (std::ostream& flux, const Point2D& p) {
        flux << "( " << p.x << " , " << p.y << " )";
        return flux;
    }

    friend std::istream& operator >> (std::istream& flux, Point2D& p) {
        flux >> p.x >> p.y;
        return flux;
    }

    Point2D operator - () const {
        return Point2D(-x,-y);
    }


};



int main() {
    Point2D p1(1, 2);
    Point2D p2(1.3, 2.8);
    /*int size = 0;
    std::cout << "size of array : \n";
    while (size == 0)
        std::cin >> size;
    double *array;
    array = new double[size];
    for(int i = 0 ; i < size ; ++i) {
        std::cout << "case " << i+1 << " : ";
        std::cin >> *(array + i); // = array[i];
    }
    for (int i = 0; i < size; ++i) {
            std::cout << "|"<<*(array + i);
    }
    std::cout << "|";
    delete array;
    array = nullptr;*/
    return 0;
}
