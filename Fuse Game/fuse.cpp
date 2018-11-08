#include "fuse.h"
#include <iostream>
#include <string>

void Fuse::fuse(int x)
{
  time = x;
}

bool Fuse::burn()
{
  if(time == 0){
    return false;
  }
  else{
    time -= 1;
    return true;
  }
}

string Fuse::to_string()
{
  string bomb(time+1, ' ');
  for(int i = 0; i < time;i++)
  {
    bomb[i] = '_';
  }
  bomb[time] = '*';
  return bomb;
}
