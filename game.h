#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

void EnterPlayerName();
void CheckPlayMode();
void GetSearchWord();
void StartGame();
void PlaymodeCasual();
void ConvertSearchWordToConcealed();
void PlayerGuess();
int WhilePlayCondition();
void ReplaceCharInConsealedWord(int placeInChar,char charToPlace);
void AddToTriedChars(char currentGuess);
void SortTriedChars();
void ExitTriedChars();

#endif // GAME_H_INCLUDED
