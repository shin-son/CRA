#include <string>
using std::string;

class Tennis {
 public:
  const string tennis_score(int player1Score, int player2Score) {
    if (player1Score == player2Score) {
      return evenScoreDescription(player1Score);
    }
    if (player1Score >= 4 || player2Score >= 4) {
      return advantageOrWinDescription(player1Score, player2Score);
    }
    return normalScoreDescription(player1Score, player2Score);
}

private:
    string evenScoreDescription(int score) {
        switch (score) {
            case 0:
              return "Love-All";
            case 1:
              return "Fifteen-All";
            case 2:
              return "Thirty-All";
            default:
              return "Deuce";
  }
}

string advantageOrWinDescription(int player1Score, int player2Score) {
  int scoreDifference = player1Score - player2Score;
  if (scoreDifference == 1) return "Advantage player1";
  if (scoreDifference == -1) return "Advantage player2";
  if (scoreDifference >= 2) return "Win for player1";
  return "Win for player2";
}

string scorePointDescription(int score) {
  switch (score) {
    case 0:
      return "Love";
    case 1:
      return "Fifteen";
    case 2:
      return "Thirty";
    default:
      return "Forty";
  }
}

string normalScoreDescription(int player1Score, int player2Score) {
      return scorePointDescription(player1Score) + "-" +
             scorePointDescription(player2Score);
    }
}
;
