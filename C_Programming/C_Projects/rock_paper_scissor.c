/*
* Project 1: Rock, Paper, Scissors
* Author: Rorie Reyes
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to implement the game
int game(char player, char computer) {

    /*
    * If both the player and computer
    * has choose the same thing
    */
   if (player == computer) {
    return -1;
   }

   /*
   * If player's choice is rock and
   * computer's choice is paper
   */
  if (player == 'r' && computer == 'p') {
    return 0;
  } 

   /* 
   * If player's choice is paper and
   * computer's choice is rock
   */
  else if (player == 'p' && computer == 'r') {
    return 1;
  }
  if (player == 'r' && computer == 's') {
    return 1;
    }

 /*
 * If player's choice is scissor and
 * computer's choice is rock
 */
else if (player == 's' && computer == 'r') {
    return 0;
}

/*
* If player's choice is paper and
* computer's choice is scissor
*/
if (player == 'p' && computer == 's') {
    return 0;
}

/*
* If player's choice is paper and
* computer's choice is scissor
*/
if (player == 'p' && computer == 's') {
    return 0;
}

/*
* If player's choice is scissor and 
* computer's choice is paper
*/
else if (player == 's' && computer == 'p') {
    return 1;
}

}