#include <string>
#include <vector>

#include "movie.cpp"
#include "rental.cpp"

using std::string;
using std::vector;

class Customer {
 private:
  string name;
  vector<Rental> rentals;

  string roundDoubleToString(double tar) {
    char buf[20] = {0};
    sprintf_s(buf, sizeof(buf), "%.1f", tar);
    return string{buf};
  }

  string header() const { return "Rental Record for " + name + "\n"; }
  string footer(double amounts, int points) {
    return "Amount owed is " + roundDoubleToString(amounts) + "\n" +
           "You earned " + std::to_string(points) + " frequent renter points";
  }

  double calculateAmountFor(Rental& rentalMovie) {
    double Amount = 0;

    switch (rentalMovie.getMovie().getPriceCode()) {
      case Movie::REGULAR:
        Amount += 2;
        if (rentalMovie.getDaysRented() > 2)
          Amount += (rentalMovie.getDaysRented() - 2) * 1.5;
        break;
      case Movie::NEW_RELEASE:
        Amount += rentalMovie.getDaysRented() * 3;
        break;
      case Movie::CHILDREN:
        Amount += 1.5;
        if (rentalMovie.getDaysRented() > 3)
          Amount += (rentalMovie.getDaysRented() - 3) * 1.5;
        break;
    }

    return Amount;
  }

  int calculatePointsFor(Rental& rentalMovie) {
    int points = 1;

    if (rentalMovie.getMovie().getPriceCode() == Movie::NEW_RELEASE &&
        rentalMovie.getDaysRented() > 1) {
      points++;
    }

    return points;
  }

  string formatLineFor(Rental& rentalMovie) {
    return "\t" + rentalMovie.getMovie().getTitle() + "\t" +
           roundDoubleToString(calculateAmountFor(rentalMovie)) + "\n";
  }

 public:
  Customer(const string& name) : name{name} {}

  void addRental(Rental arg) { rentals.push_back(arg); }

  string getName() const { return name; }

  string statement() {
    double totalAmount = 0;
    int frequentRenterPoints = 0;
    string rentalReport = header();

    for (Rental rental : rentals) {
      totalAmount += calculateAmountFor(rental);
      frequentRenterPoints += calculatePointsFor(rental);
      rentalReport += formatLineFor(rental);
    }

    // add footer lines
    rentalReport += footer(totalAmount, frequentRenterPoints);

    return rentalReport;
  }
};