#include <iostream>
#include "InpRepl.h"


int main(int argc, char *argv[]) {
    InpRepl repl;


    if(argc >= 2){
        repl.runRepl(argv[1]);
    }else{
        std::cout<<"Specify the script route";
    }

    return 0;
}
