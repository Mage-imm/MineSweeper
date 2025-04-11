#include "field.hpp"
#include "buffer.hpp"
#include "setup.hpp"
#include "colour.hpp"
#include "display.hpp"

int main()
{
    bool playAgain = true;

    while (playAgain)
    {
        system("clear");
        setGameMode();
        getQuickClearSettings();

        Field field;

        while (true)
        {
            system("clear");

            dispBanner();
            field.drawField();
            dispFlagCounter();

            if (gameState != RUNNING)
                dispVictoryOrDefeat();
            else
                dispControls();

            writeBuf.disp();
            writeBuf.clear();

            if (gameState == RUNNING)
                field.getMove();
            else
                break;
        }

        std::cout << "\nPlay again? (y/n): ";
        char choice;
        std::cin >> choice;
        playAgain = (choice == 'y' || choice == 'Y');
    }

    std::cout << std::endl << reset;
    return 0;
}
