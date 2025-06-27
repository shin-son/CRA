#include <vector>;

#include "rental.cpp"

class master {
 public:
  double calculateTotalAmounts(std::vector<Rental>& rentals, double amounts) {
    for (Rental& rental : rentals) amounts += rental.getCharge();
    return amounts;
  }

  int getFrequentRenterPoints(std::vector<Rental>& rentals, int points) {
    for (Rental& rental : rentals) points += rental.getPoints();
    return points;
  }
};