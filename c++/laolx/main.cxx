//
//  main.cpp
//  laolx
//
//  Created by George P. Burdell on 12/18/19.
//  Copyright © 2019 George P. Burdell. All rights reserved.
//

#include <string>
#include <iostream>
#include "laolx/parser/string.hxx"

using std::string;
using std::cout;
using std::endl;
using apfev3::TPNode;
using apfev3::Consumer;
using apfev3::CharBuf;
using laolx::parser::String;

int main(int argc, const char** argv) {
    {
        CharBuf INPUT("\"we are here\"");
        Consumer consumer(INPUT);
        TPNode MATCH = String::THE_ONE.accept(consumer);
    }
    return 0;
}
