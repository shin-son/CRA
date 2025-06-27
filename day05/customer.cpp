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
  StatementFormatter bill;

 public:
  Customer(const string& name) : name{name} {}

  void addRental(Rental arg) { rentals.push_back(arg); }

  string getName() const { return name; }

  string getBill() { return bill.printFormat(rentals, name); }
};