#include <iostream>
#include <Windows.h>

using namespace std;

CRITICAL_SECTION critical;

class Leader {

  public:
    static Leader * getInstance() {
      EnterCriticalSection(&critical);
      
      if (_instance == NULL) {
        _instance = new Leader();
      }
      return _instance;
      LeaveCriticalSection(&critical);
    }

  private:
	  static Leader * _instance;
	  // Define the constructor to be protected
	  Leader() {
		  cout << "New Leader elected" << endl;
	  }

  public:
    void giveSpeech() {
      cout << "Address the public." << endl;
    }
};

Leader* Leader::_instance = 0;

int main() {
	InitializeCriticalSection(&critical);

	Leader::getInstance()->giveSpeech();

	DeleteCriticalSection(&critical);

	cout << "No longer in critical section" << endl;
}