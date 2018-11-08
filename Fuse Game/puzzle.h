#include <string>
using namespace std;


class Puzzle
{
  private:
    string solution;
    bool guesses[255];
  public:
    int count = 0;
    int repeat = 0;
    char user_guesses[28];
    void puzzle(string guess);
    bool guess(char c);
    bool solve(string p_solution);
    string to_string();
    string get_solution();

};
