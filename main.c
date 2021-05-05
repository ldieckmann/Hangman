#include "visualase.h"
#include "game.h"
#include "encryption.h"

int main()
{

    HangmanTitle();
    GameIntroduction();
    EnterPlayerName();
//    CheckPlayMode();
    GetSearchWord();
    StartGame();
    Encryption();

}
