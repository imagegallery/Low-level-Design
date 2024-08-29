#include <bits/stdc++.h>

using namespace std;
/*
    Dependency Inversion principle: class should depend on interfaces rather than concrete classes.

    lets say we have Keyboard interface with 2 classes extending from it (bluetooth keyboard and wired keyboard)
    and another mouse interface with 2 classes (bluetooth mouse and wired mouse)
*/

class Macbook{
    const WiredKeyboard keyboard;  //private const members only accessible within the class and cant be modified once assigned value.
    const WiredMouse mouse;
    public:
    Macbook(){
        keyboard = new WiredKeyboard();  //instead of using interface we are using concrete classes so violating the dependency inversion principle
        mouse = new WiredMouse();  //As we cant enhance keyboard and mouse to bluetooth one.
    }
};

//what we should have done that
class Macbook{
    Keyboard keyboard;
    Mouse mouse;
    public:
    Macbook(Keyboard keyboard, Mouse mouse){
        keyboard = keyboard;  
        mouse = mouse; 
    }
};
