#pragma once

#include <vector>;

#include "movie.cpp";

class Rental {
 public:
  Rental(const Movie &movie, int days_rented)
      : movie{movie}, daysRented{days_rented} {}

  int getDaysRented() const { return daysRented; }

  Movie getMovie() { return movie; }

  double getCharge() {
    double amount = 0;

    switch (movie.getPriceCode()) {
      case Movie::REGULAR:
        amount += 2;
        if (getDaysRented() > 2) amount += (getDaysRented() - 2) * 1.5;
        break;
      case Movie::NEW_RELEASE:
        amount += getDaysRented() * 3;
        break;
      case Movie::CHILDREN:
        amount += 1.5;
        if (getDaysRented() > 3) amount += (getDaysRented() - 3) * 1.5;
        break;
    }

    return amount;
  }

  int getPoints() {
    int points = 1;

    if (movie.getPriceCode() == Movie::NEW_RELEASE && getDaysRented() > 1)
      points++;

    return points;
  }

 private:
  Movie movie;
  int daysRented;
};