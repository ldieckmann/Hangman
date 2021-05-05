#ifndef VISUALASE_H_INCLUDED
#define VISUALASE_H_INCLUDED

void HangmanVisualize(int wrongAttempt);
void GameIntroduction();
void HangmanTitle();
void PrintSearchWordHidden(char searchWord[25]);
void ExitAttempt(int totalAttempt,int rightAttempt);
void EndGame(int totalAttempt,int rightAttempt);
void Won(char playername[20],int totalAttempt,int rightAttempt);
void Lose(char playername[20],int totalAttempt,int rightAttempt);
#endif // VISUALASE_H_INCLUDED
