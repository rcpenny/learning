#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Leader {

  private:
    static Leader * _instance;

    Leader() {
      cout << "new leader elected" << endl;
    }
  
  public:
    static Leader * getInstance() {
      if (_instance == NULL) {
        _instance = new Leader;
      }
      return _instance;
    }

    void giveSpeech() {
      cout << "address the public" << endl;
    }
};

Leader* Leader::_instance = NULL;

int main() {
  Leader::getInstance() -> giveSpeech();
}