#include "puzzle.h"
#include <iostream>
#include <string>


void Puzzle::puzzle(string guess)
{
  solution = guess;
}

bool Puzzle::guess(char c)
{
  for(int i = 0; i < count; i++)
  {
    repeat = 0;
    if(c == guesses[i]){
      repeat++;
      return false;
    }
  }
  if(c >= 'a' && c <= 'z' && repeat == 0){
    guesses[count] = c;
    user_guesses[count] = c;
    count++;
    return true;
  }
  else{
    return false;
  }
}

bool Puzzle::solve(string p_solution)
{
  if(p_solution == solution)
  return true;
  else
  return false;
}

string Puzzle::to_string()
{
  string display(solution.length(), '_');
  for(int i = 0; i < solution.length();i++)
  {
    if(solution[i] == ' '){
      display[i] = ' ';
    }
    else{
      for(int k = 0; k < count;k++){
        if(solution[i] == user_guesses[k]){
          display[i] = solution[i];
        }
      }
    }
  }
  return display;

}

string Puzzle::get_solution()
{
  return solution;
}
