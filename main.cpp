#include <iostream>
#include <string>

class Engine {
public:
    Engine(const std::string& type, int power) : type_(type), power_(power) {}

    // Constructor de copiere
    Engine(const Engine& other) : type_(other.type_), power_(other.power_) {}

    // Operator= de copiere
    Engine& operator=(const Engine& other) {
        if (this != &other) {
            type_ = other.type_;
            power_ = other.power_;
        }
        return *this;
    }

    // Destructor
    ~Engine() {
        std::cout << "Engine destructor called for " << type_ << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const Engine& engine) {
        os << "Engine Type: " << engine.type_ << ", Power: " << engine.power_;
        return os;
    }

    void Start() const {
        std::cout << "Starting the " << type_ << " engine." << std::endl;
    }

private:
    std::string type_;
    int power_;
};

class Car {
public:
    Car(const std::string& make, const Engine& engine) : make_(make), engine_(engine) {}

    // Constructor de copiere
    Car(const Car& other) : make_(other.make_), engine_(other.engine_) {}

    // Operator= de copiere
    Car& operator=(const Car& other) {
        if (this != &other) {
            make_ = other.make_;
            engine_ = other.engine_;
        }
        return *this;
    }

    // Destructor
    ~Car() {
        std::cout << "Car destructor called for " << make_ << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const Car& car) {
        os << "Car Make: " << car.make_ << ", " << car.engine_;
        return os;
    }

    void Drive() const {
        engine_.Start();
        std::cout << "Driving the " << make_ << " car." << std::endl;
    }

private:
    std::string make_;
    Engine engine_;
};

class Garage {
public:
    Garage(const std::string& location) : location_(location) {}

    // Destructor
    ~Garage() {
        std::cout << "Garage destructor called for " << location_ << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const Garage& garage) {
        os << "Garage Location: " << garage.location_;
        return os;
    }

    void ParkCar(const Car& car) {
        std::cout << "Parked a " << car << " in the " << location_ << " garage." << std::endl;
    }

private:
    std::string location_;
};

int main() {
    Engine sportsEngine("V10", 450);
    Car sportsCar("Bmw M5", sportsEngine);

    Engine familyEngine("L4", 150);
    Car familyCar("Toyota Camry", familyEngine);

    Garage homeGarage("Home");
    Garage workGarage("Work");

    std::cout << "In the morning:\n";
    workGarage.ParkCar(sportsCar);
    sportsCar.Drive();

    std::cout << "\nIn the evening:\n";
    homeGarage.ParkCar(familyCar);
    familyCar.Drive();

    return 0;
}
