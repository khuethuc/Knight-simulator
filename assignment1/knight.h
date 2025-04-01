#ifndef _KNIGHT_H_
#define _KNIGHT_H_

#include "main.h"

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue);
bool prime(int n);
int substring(string s, string s1);
int s1(int n1);
int max(int mg1[]);
int vtmax(int mg[],int n2);
int vtmin(int mg[],int n2);
int vtmax3(int mg1[],int n2);
int vtmin3(int mg1[],int n2);
int fibo(int n);
void turn(int & dem, bool & small, int & HP, int & maxHP, bool & frog, int & level, int & LV);
bool arthur(int & maxHP);
double damage(int n, int levelO);
bool lancelot(int & maxHP);
void event99(int & maxHP, int & level, int & rescue);
void event1to5(int & tam, int & HP, int & level, int & phoenixdown, int & rescue, int & maxHP, int n, int levelO, int b, int i, bool & small);
void event6(int & HP,int &maxHP, int & level, int & remedy, int & rescue,int levelO,bool &small,int b,int i);
void event7(int & maxHP,int & LV, int & level, int & maidenkiss, int & rescue, int levelO, bool & frog, int b, int i);
void event11(int & HP, int & level, int & phoenixdown, int & maxHP, int & rescue);
void event12(int & HP, int & level, int & phoenixdown, int & maxHP, int & rescue);
void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue);

#endif // _KNIGHT_H_`