#include <iostream>
#include <SDL.h>
#include "App.h"

using namespace std;


int main(int argc, char** args) {
    try {
        App app;
        app.HandleEvents();
    }
    catch (exception& e) {
        cerr << e.what() << '\n';
        return 1;
    }
    return 0;
}