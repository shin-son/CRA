#include "customer.cpp"

#include "gmock/gmock.h"

using namespace testing;

const string NAME = "NAME_NOT_IMPORTANT";
const string TITLE = "TITLE_NOT_IMPORTANT";

class CustomerFixture : public Test {
 public:
  Customer customer = Customer{NAME};
  Rental createRentalFor(int daysRented, int priceCode) {
    Movie movie{TITLE, priceCode};
    Rental rental{movie, daysRented};
    return rental;
  }
};

TEST_F(CustomerFixture, StatementForNoRental) {
  // assert
  EXPECT_EQ(customer.getBill(),
            "" + string{"Rental Record for NAME_NOT_IMPORTANT\n"} +
                string{"Amount owed is 0.0\n"} +
                string{"You earned 0 frequent renter points"});
}

TEST_F(CustomerFixture, StatementForRegularMovieRentalForLessThan3Days) {
  customer.addRental(createRentalFor(2, Movie::REGULAR));

  // assert
  EXPECT_EQ(customer.getBill(),
            "" + string{"Rental Record for NAME_NOT_IMPORTANT\n"} +
                string{"\tTITLE_NOT_IMPORTANT\t2.0\n"} +
                string{"Amount owed is 2.0\n"} +
                string{"You earned 1 frequent renter points"});
}

TEST_F(CustomerFixture, StatementForRegularMovieRentalForMoreThan2Days) {
  customer.addRental(createRentalFor(3, Movie::REGULAR));

  // assert
  EXPECT_EQ(customer.getBill(),
            "" + string{"Rental Record for NAME_NOT_IMPORTANT\n"} +
                string{"\tTITLE_NOT_IMPORTANT\t3.5\n"} +
                string{"Amount owed is 3.5\n"} +
                string{"You earned 1 frequent renter points"});
}

TEST_F(CustomerFixture, StatementForNewReleaseMovie) {
  customer.addRental(createRentalFor(1, Movie::NEW_RELEASE));

  // assert
  EXPECT_EQ(customer.getBill(),
            "" + string{"Rental Record for NAME_NOT_IMPORTANT\n"} +
                string{"\tTITLE_NOT_IMPORTANT\t3.0\n"} +
                string{"Amount owed is 3.0\n"} +
                string{"You earned 1 frequent renter points"});
}

TEST_F(CustomerFixture, StatementForChildrenMovieRentalMoreThan2Days) {
  customer.addRental(createRentalFor(3, Movie::CHILDREN));

  // assert
  EXPECT_EQ(customer.getBill(),
            "" + string{"Rental Record for NAME_NOT_IMPORTANT\n"} +
                string{"\tTITLE_NOT_IMPORTANT\t1.5\n"} +
                string{"Amount owed is 1.5\n"} +
                string{"You earned 1 frequent renter points"});
}

TEST_F(CustomerFixture, StatementForChildrenMovieRentalMoreThan3Days) {
  customer.addRental(createRentalFor(4, Movie::CHILDREN));

  // assert
  EXPECT_EQ(customer.getBill(),
            "" + string{"Rental Record for NAME_NOT_IMPORTANT\n"} +
                string{"\tTITLE_NOT_IMPORTANT\t3.0\n"} +
                string{"Amount owed is 3.0\n"} +
                string{"You earned 1 frequent renter points"});
}

TEST_F(CustomerFixture, StatementForNewReleaseMovieRentalMoreThan1Day) {
  customer.addRental(createRentalFor(2, Movie::NEW_RELEASE));

  // assert
  EXPECT_EQ(customer.getBill(),
            "" + string{"Rental Record for NAME_NOT_IMPORTANT\n"} +
                string{"\tTITLE_NOT_IMPORTANT\t6.0\n"} +
                string{"Amount owed is 6.0\n"} +
                string{"You earned 2 frequent renter points"});
}

TEST_F(CustomerFixture, StatementForFewMovieRentals) {
  customer.addRental(createRentalFor(1, Movie::REGULAR));
  customer.addRental(createRentalFor(4, Movie::NEW_RELEASE));
  customer.addRental(createRentalFor(4, Movie::CHILDREN));

  // assert
  EXPECT_EQ(customer.getBill(),
            "" + string{"Rental Record for NAME_NOT_IMPORTANT\n"} +
                string{"\tTITLE_NOT_IMPORTANT\t2.0\n"} +
                string{"\tTITLE_NOT_IMPORTANT\t12.0\n"} +
                string{"\tTITLE_NOT_IMPORTANT\t3.0\n"} +
                string{"Amount owed is 17.0\n"} +
                string{"You earned 4 frequent renter points"});
}