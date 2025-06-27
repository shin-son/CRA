#include <string>
#include <vector>

#include "master.cpp"
#include "movie.cpp"
#include "rental.cpp"
#include "statement.cpp"

using std::string;
using std::vector;

class Customer {
 private:
  string name;
  vector<Rental> rentals;

  string printFormat(StatementFormatter& report) {
    master master;
    string rentalBill = report.formatHeader(name);

    for (Rental& rental : rentals) rentalBill += report.formatLine(rental);

    rentalBill +=
        report.formatFooter(master.calculateTotalAmounts(rentals, 0),
                            master.getFrequentRenterPoints(rentals, 0));

    return rentalBill;
  }

 public:
  Customer(const string& name) : name{name} {}

  void addRental(Rental arg) { rentals.push_back(arg); }

  string getName() const { return name; }

  string statement() {
    StatementFormatter billReport;
    return printFormat(billReport);
  }
};