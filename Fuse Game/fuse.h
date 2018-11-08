#include <string>
using namespace std;

class Fuse
{
  private:
    int time;
  public:
    void fuse(int x);
    bool burn();
    string to_string();
};

