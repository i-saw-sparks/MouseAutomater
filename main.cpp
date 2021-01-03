#include <iostream>
#include "InpRepl.h"


int main(int argc, char *argv[]) {
    InpRepl repl;

    if(argc == 1){
        repl.runRepl("test.txt");
    }


    return 0;
}
