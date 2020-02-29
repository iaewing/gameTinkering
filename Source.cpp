#include <stdio.h>
#include <stdlib.h> //rand and srand
#include <time.h> //time

//Function prototypes
int combat(int playerStats[], int enemyStats[]);
int statGenerator(int difficulty);
int getNum(void);
void navigation(void);

int main(void)
{
	int playerStats[3] = { 10, 1, 3 }; //Health, Armour, Attack for player character
	int enemyStats[3] = { 0 }; //Health, Armour, Attack for enemy
	int difficulty = 0;
	int direction = 0;

	srand(time(0));  //Creates a semi-random seed for rand()

	while (playerStats[0] > 0)
	{
		printf("Welcome to the the Punch Punch RPG.\n");
		printf("Please enter a difficulty level.\n10 for easy, 15 for challenging, 20 for hard.\n");
		difficulty = getNum();

		printf("You're standing in the long-grass of a bright sunny valley.\n");
		printf("In the distance, to the north, you spot a ruined building.\n");
		printf("Behind you, to the south, is nothing but more long-grass and the occasional bush.\n");
		printf("The hills rise to your east and west.\n\n");
		navigation();

		direction = getNum();

		if (direction == 1)
		{
			printf("You approach the ruined building.\n");
			printf("As you draw nearer to the door, you realize that this was once a small home.\n");
			printf("You open the door and enter the darkened room.\n");
			combat(playerStats, enemyStats);
		}
		else if (direction == 2)
		{
			printf("You head to the east. As you begin to climb the hill\n");
			printf("you begin to realize it is much steeper than it looked.\n");
			printf("A loose rock under your right foot falls, sending you tumbling backward.\n");
			playerStats[0] = 0;
		}
		else if (direction == 3)
		{
			
		}
		else if (direction == 4)
		{
			printf("You head to the west. As you begin to climb the hill\n");
			printf("you realize the hill is much steeper than you anticipated.\n");
			printf("You struggle up the hill, fighting for every foothold.\n");
			printf("You climb a section of vertical rock face and are startled by\n");
			printf("the screech of a passing falcon. You lose your grip of the rock\n");
			printf("and go tumbling backward.\n");
			playerStats[0] = 0;
		}
		else
		{
			printf("Please enter a number.\n");
		}
		/*
		for (int i = 0; i < 3; i++)
		{
			playerStats[i] = statGenerator(); //Fills player stats for each new game.

			while (playerStats[2] >= enemyStats[1]) //Checks to ensure player's attack is higher than enemy's armour.
			{
				playerStats[2] = statGenerator();
			}
		}
		*/

		for (int i = 0; i < 3; i++) //Fills enemy stats for each new encounter.
		{
			enemyStats[i] = statGenerator(difficulty);
		}
	}
	printf("Your limp body falls to the ground, lifeless.\n");
	printf("This is the end of your adventure.");
}


/*
Name: statGenerator
Description: Random generation of int values to populate character stats.
The attempt with the int difficulty is to allow the user to enter a numberic value
that will dictate within what range rand() can generate a number.
*/
int statGenerator(int difficulty)
{
	int result = 0;

	result = rand() % difficulty + 5;

	return result;
}

/*
Name: combat
Description: Runs an instance of combat between player and enemy.
Exits when one reaches 0 health. Returns boolean value to call.
Will not allow a particpant to have a negative attack value.
*/
int combat(int playerStats[], int enemyStats[])
{
	int playerDmg = 0;
	int enemyDmg = 0;

	//This block prevents the enemy from gaining health if the player attack is lower than enemy armour
	if (playerStats[2] < enemyStats[1])
	{
		playerDmg = 0;
	}
	else
	{
		playerDmg = (playerStats[2] - enemyStats[1]);
	}

	//This block prevents the player from gaining health if the enemy attack is lower than player armour
	if (enemyStats[2] < playerStats[1])
	{
		enemyDmg = 0;
			 
	}
	else
	{
		enemyDmg = (enemyStats[2] - playerStats[1]);
	}

	printf("Combat Log:\n");

	while (playerStats[0] != 0 || enemyStats[0] != 0)
	{
		enemyStats[0] -= playerDmg;
		printf("The enemy has %d health left.\n", enemyStats[0]);

		playerStats[0] -= enemyDmg;
		printf("You have %d health left.\n", playerStats[0]);

		if (enemyStats[0] <= 0)
		{
			printf("Victory is yours!\n");
			printf("You have %d health left.", playerStats[0]);
			return 1;
		}
		else if (playerStats[0] <= 0)
		{
			return 0;
		}
	}
}

#pragma warning(disable: 4996)
int getNum(void)
{
	char input[10] = { 0 };
	int number = 0;

	fgets(input, 10, stdin);

	if (sscanf(input, "%d", &number) != 1)
	{
		/* if the user did not enter a number recognizable by
		 * the system, set number to -1 */
		number = -1;
	}
	return number;
}

/*
Name: navigation
Description: Provides a menu print with the directions for the player to navigate.
*/
void navigation(void)
{
	printf("Which direction do you go?\n");
	printf("1. Head North\n");
	printf("2. Head East\n");
	printf("3. Head South\n");
	printf("4. Head West\n");
}