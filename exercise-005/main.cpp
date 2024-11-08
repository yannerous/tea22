#include <fmt/chrono.h>
#include <fmt/format.h>

#include "triangle.h"

#include "CLI/CLI.hpp"
#include "config.h"

struct Person {
    unsigned int alter;
    float gewicht;
    char name[25];
};
auto main(int argc, char **argv) -> int
{
    Person paul;
    paul.alter = 14;

    Person* pPers = &paul;
    fmt::print("Hello, {}!\n", argv[0]);
    fmt::print("{}\n",pPers->alter);
    /* INSERT YOUR CODE HERE */
    Person paula = {18,57,"Paula"};
    fmt::print("Paula ist {} Jahre alt\n",paula.alter);
    pPers = &paula;
    fmt::print("Die Person bei pPers is {} Jahre alt\n",pPers->alter);

    strncpy(paul.name,"Paul",sizeof(paul.name)/sizeof(paul.name[0]));
    fmt::print("Der Name von Paul ist {}\n",paul.name);

    paul=paula;//structs werden Bitweise kopiert
    fmt::print("Der Name von Paul ist {}\n",paul.name);


    Triangle* trig = newTriangle();
    fmt::print("Der Umfang des Dreiecks ist {}\n",trig->func(trig));

    //Speicherleck:
    //trig = newTriangle();

    //richtig:
    free(trig);
    trig = newTriangle();

    return 0; /* exit gracefully*/
}
