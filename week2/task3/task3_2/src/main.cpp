#include <iostream>
#include "../include/Car.hpp"

using namespace std;

void Car::addPassenger(Passenger* passenger) {
  if (passenger1 == nullptr) {
  passenger1 = passenger;
  } else if (passenger2 == nullptr) {
  passenger2 = passenger;
  } else {
  cout << "В автомобиле уже два пассажира." << endl;
  }
}

void Car::removePassenger(Passenger* passenger) {
  if (passenger1 == passenger) {
  passenger1 = nullptr;
  } else if (passenger2 == passenger) {
  passenger2 = nullptr;
  }
}

void Car::displayInfo() const {
  cout << "Модель автомобиля: " << model << endl;
  cout << "Мощность двигателя: " << engine.getPower() << " л.с." << endl;
  cout << "Пассажиры:" << endl;
  if (passenger1 != nullptr) {
  cout << " - " << passenger1->getName() << endl;
  }
  if (passenger2 != nullptr) {
  cout << " - " << passenger2->getName() << endl;
  }
}

int main() {

  Engine engine1(188); // Двигатель мощностью 188 л.с.

  Car car1("Hyundai Sonata", engine1);

  Passenger* passenger1 = new Passenger("Кузьма");
  Passenger* passenger2 = new Passenger("Степан");

  car1.addPassenger(passenger1);
  car1.addPassenger(passenger2);

  car1.displayInfo();

  car1.removePassenger(passenger1);

  car1.displayInfo();

  delete passenger1;
  delete passenger2;

  return 0;
}
