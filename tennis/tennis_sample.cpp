#include <string>
using std::string;

class Tennis {
 public:
  const string tennis_score(int p1Score, int p2Score) {
    if (p1Score == p2Score)
      return CheckScoreSame(p1Score);
    else if (p1Score >= 4 || p2Score >= 4)
      return CheckScoreOver40(p1Score, p2Score);
    else
      return CheckScoreDefault(p1Score, p2Score);
  }

 private:
  std::string CheckScoreSame(int p1Score) {
  std:
    string score = "";
    switch (p1Score) {
      case 0:
        score = "Love-All";
        break;
      case 1:
        score = "Fifteen-All";
        break;
      case 2:
        score = "Thirty-All";
        break;
      default:
        score = "Deuce";
        break;
    }
    return score;
  }

  std::string CheckScoreOver40(int p1Score, int p2Score) {
  std:
    string score = "";
    int ScoreDiff = p1Score - p2Score;
    if (ScoreDiff == 1)
      score = "Advantage player1";
    else if (ScoreDiff == -1)
      score = "Advantage player2";
    else if (ScoreDiff >= 2)
      score = "Win for player1";
    else
      score = "Win for player2";
    return score;
  }

  std::string CheckScoreDefault(int p1Score, int p2Score) {
  std:
    string score = "";
    int tempScore = 0;
    for (int i = 1; i < 3; i++) {
      if (i == 1)
        tempScore = p1Score;
      else {
        score += "-";
        tempScore = p2Score;
      }
      switch (tempScore) {
        case 0:
          score += "Love";
          break;
        case 1:
          score += "Fifteen";
          break;
        case 2:
          score += "Thirty";
          break;
        case 3:
          score += "Forty";
          break;
      }
    }
    return score;
  }
};