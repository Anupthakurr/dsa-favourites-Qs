#include <iostream>
using namespace std;

class Car {
public:
    string brand;
    string color;
    int speed;

    void start() {
        cout << brand << " has started." << endl;
    }

    void stop() {
        cout << brand << " has stopped." << endl;
    }

    void display() {
        cout << "Brand : " << brand << endl;
        cout << "Color : " << color << endl;
        cout << "Speed : " << speed << " km/h" << endl;
        cout << "------------------------" << endl;
    }
};

int main() {

    // Creating Objects
    Car bmw;
    Car audi;
    Car tesla;

    // Initializing BMW
    bmw.brand = "BMW";
    bmw.color = "Black";
    bmw.speed = 250;

    // Initializing Audi
    audi.brand = "Audi";
    audi.color = "White";
    audi.speed = 240;

    // Initializing Tesla
    tesla.brand = "Tesla";
    tesla.color = "Red";
    tesla.speed = 260;

    // Using BMW Object
    bmw.display();
    bmw.start();
    bmw.stop();

    cout << endl;

    // Using Audi Object
    audi.display();
    audi.start();
    audi.stop();

    cout << endl;

    // Using Tesla Object
    tesla.display();
    tesla.start();
    tesla.stop();

    return 0;
}
