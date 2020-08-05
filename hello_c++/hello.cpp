// CPP program to illustrate 
// parameterized constructors 
#include <iostream> 
using namespace std; 

extern "C" void init_cacheinfo (void);
void __attribute__ ((constructor)) b_constructor() {
  //cout << "in b_constructor" << endl;
  init_cacheinfo();
  //cout << "init cacheinfo run" << endl;
}
  
class Point { 
private: 
    int x, y; 
  
public: 
    // Parameterized Constructor 
    Point(int x1, int y1) 
    { 
        x = x1; 
        y = y1; 
    } 
  
    int getX() 
    { 
        return x; 
    } 
    int getY() 
    { 
        return y; 
    } 
}; 
  
int main() 
{ 
    cout << "Called before constructor" << endl;

    // Constructor called 
    Point p1(10, 15); 
  
    // Access values assigned by constructor 
    cout << "p1.x = " << p1.getX() << ", p1.y = " << p1.getY() << endl; 

    cout << "Called after constructor" << endl; 
    while(1);

    return 0; 
} 
