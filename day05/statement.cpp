#pragma once
#include <vector>

#include "master.cpp"
#include "rental.cpp"

class StatementFormatter {
 public:
  string printFormat(std::vector<Rental>& rentals, string customer_name) {
    master master;

    string rentalBill = formatHeader(customer_name);

    for (Rental& rental : rentals) rentalBill += formatLine(rental);

    rentalBill += formatFooter(master.calculateTotalAmounts(rentals, 0),
                               master.getFrequentRenterPoints(rentals, 0));

    return rentalBill;
  }

  string formatHeader(string customer_name) {
    return "Rental Record for " + customer_name + "\n";
  }

  string formatFooter(double amounts, int points) {
    return "Amount owed is " + roundDoubleToString(amounts) + "\n" +
           "You earned " + std::to_string(points) + " frequent renter points";
  }

  string formatLine(Rental& rentalMovie) {
    return "\t" + rentalMovie.getMovie().getTitle() + "\t" +
           roundDoubleToString(rentalMovie.getCharge()) + "\n";
  }

 private:
  string roundDoubleToString(double tar) {
    char buf[20] = {0};
    sprintf_s(buf, sizeof(buf), "%.1f", tar);
    return string{buf};
  }
};