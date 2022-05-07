#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool isIn (char, const int, char *);
void countCharater (char *);
int howMany(char *, const int, char);
void printResult(int *, char *, const int);

int main(void) {

  char phrase[10000];

  printf("enter your phrase: ");
  fgets(phrase, sizeof(phrase), stdin);

  countCharater(phrase);

  return 0;
}

void countCharater (char *c) {

  //create a varuable to get  the length of *c
  const int length = strlen(c);

  //create a pointer to alocate the memory
  char *p = (char *) malloc(length * sizeof(char));

  /*
    char *p = (char *) malloc(length * sizeof(char));
    is the same as we declare
    char p[length];
  */

  //for the number of each charater
  int *number = (int *) malloc(length * sizeof(int));

  //create a counter for p;
  int counter = 0;

  for (int i = 0; i < length && c[i] != '\n'; i++) {
    if (!isIn(c[i], length, p)) {
      p[counter++] = c[i];
      number[counter-1] = howMany(c, length, p[counter-1]);
    }
  }

  printResult(number, p, counter);
}

//"c == string" "l == length" "p == pointer"
//look to countCharater!!!

bool isIn (char c, const int l, char *p) {

  //start a loop to check if the chracter exist
  for (int i = 0; i < l; i++) {
    if (c == p[i])
      return true;
  }
  return false;
}

int howMany (char *c, const int l, char p) {

  int counter = 0;

  //start a loop to get the number of each charater
  for (int i = 0; i < l && c[i] != '\n'; i++) {
    if (c[i] == p)
      counter++;
  }
  return counter;
}

void printResult (int *number, char *p, const int counter) {

  int max = number[0], min = number[0];
  int maxI = 0, minI = 0;

  for (int i = 0; i < counter; i++) {
    printf("charater: \'%c\', number: %i\n", p[i], number[i]);

    if (number[i] > max) {
      max = number[i];
      maxI = i;
    }
    if (number[i] < min) {
      min = number[i];
      minI = i;
    }
  }

  printf("The most repeated character is \'%c\' with %i times \n", p[maxI], number[maxI]);

  printf("The less repeated character is \'%c\' with %i times\n", p[minI], number[minI]);
}
