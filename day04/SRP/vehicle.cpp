class Vehicle {
 public:
  int max_fuel_;
  int remaining_fuel_;

  Vehicle(int maxFuel) {
    max_fuel_ = maxFuel;
    remaining_fuel_ = maxFuel;
  }

  int GetMaxFuel() { return max_fuel_; }

  int GetRemainingFuel() { return remaining_fuel_; }

  void SetRemainingFuel(int remaining_fuel) {
    remaining_fuel_ = remaining_fuel;
  }

  void Accelerate() { remaining_fuel_--; }

 private:
};

class GasStation {
  Vehicle vehicle;

  // this is not a car's responsibility.
  void ReFuel() { vehicle.remaining_fuel_ = vehicle.max_fuel_; }
};