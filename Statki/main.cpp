#include <iostream>

#include "Warships.h"
#include "DisplayCmd.h"

int main()
{
    while (true)
    {
        DisplayCmd display;

        display.menu();

        switch (display.getChoice())
        {
        case '1':
        {
            Warships Game(display);

            Game.play();
            break;
        }
        case '2':
        {
            return 0;
            break;
        }
        }
    }

    return 0;
}

