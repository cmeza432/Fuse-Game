#include "puzzle.h"
#include "fuse.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
  char x;
  int win = 0;
  Fuse fuses;
  Puzzle game;
  string proposed;
  game.puzzle("carlos meza");
  int time = 10;
  fuses.fuse(time);

  cout << "\n\n\n";
  cout << "===============" << endl;
  cout << "   B O O M !   " << endl;
  cout << "===============" << endl;
  cout << "Enter lower case letters to guess," << endl;
  cout << "! to propose a solution," << endl;
  cout << "0 to exit." << endl;

  while(fuses.burn() != false){
    cout << "   " + fuses.to_string() << endl;
    cout << "  /\n,+,\n| |\n|_|" << endl;
    cout << game.to_string() << endl;
    cout << "Enter char: ";
    cin >> x;
    cin.ignore();

    if(x == '0'){
      cout << "Now exiting..." << endl;
      break;
    }

    if(x == '!'){
      cout << "Enter guess: ";
      getline(cin, proposed);
      if(game.solve(proposed) == false){
        cout << "###BOOM###\nThe answer was: " + game.get_solution() << endl;
        break;
      }
      else{
        cout << "* * * W I N N E R * * *" << endl;
        break;
      }
    }

    else{
      game.guess(x);
      game.to_string();
      if(game.to_string() == game.get_solution()){
        cout << "\n\n* * * W I N N E R * * *" << endl;
        cout << "   " + fuses.to_string() << endl;
        cout << "  /\n,+,\n| |\n|_|" << endl;
        cout << game.to_string() << endl;
        win = 1;
        break;
      }
    }
  }
  if(fuses.burn() == false && win == 0){
    cout << "###BOOM###\nThe answer was: " + game.get_solution() << endl;
  }
  return 1;
}
