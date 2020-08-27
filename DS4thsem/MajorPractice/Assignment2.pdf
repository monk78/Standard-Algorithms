#include<stdio.h>

//Header file
#include<stdlib.h>

#include<string.h>

int main()
{
  //Variable Declaration

  char quest [5][200];
  char option1 [3][100],option2 [3][100],
  option3 [3][100],option4 [3][100], option5 [3][100];

  int response[5], correct_ans[5], option,i, marks;

  printf("\n\n\n\n\n\t\t\t\t PROGRAM QUIZ GAME\n");
  printf("\n\t\t\t________________________________________");
  printf("\n\t\t\t\t   WELCOME ");
  printf("\n\t\t\t\t      to ");
  printf("\n\t\t\t\t   THE GAME ");
  printf("\n\t\t\t________________________________________");
  printf("\n\t\t\t________________________________________");
  printf("\n\t\t\t   BECOME A MILLIONAIRE!!!!!!!!!!!    ") ;
  printf("\n\t\t\t________________________________________");
  printf("\n\t\t\t________________________________________");

  //Directions to the Quiz Game

  printf("\n\n\t\t Here are some tips you might wanna know before playing:");
  printf("\n\t\t -------------------------------------------------------");
  printf("\n\t\t >> There is only one round in this Quiz Game");
  printf("\n\t\t >> In this round you will be asked a total of 5 questions to test your meme knowledge");
  printf("\n\t\t   Each right answer will be awarded $1000000!");
  printf("\n\t\t    By this way you can win upto $5 Million cash prize!!!!!..........");
  printf("\n\t\t >> You will be given 3 options and you have to press 1, 2 ,3 ");
  printf("\n\t\t    right option.");
  printf("\n\t\t >> You will be asked questions continuously, till end of all the questions");
  printf("\n\t\t >> No negative marking for wrong answers!");
  printf("\n\n\t\t\t!!!!!!!!!!!!! ALL THE BEST !!!!!!!!!!!!!");

  //Question 1

  strcpy(quest[0], "Which of these words rhymes with house?");
  strcpy(option1[0], "1. Dog");
  strcpy(option1[1], "2. Satan");
  strcpy(option1[2], "3. Mouse");
  correct_ans[0] = 1;

  //Question 2

  strcpy(quest[1], "Calculate the value of sinx/n?");
  strcpy(option2[0], "1. Very tough.");
  strcpy(option2[1], "2. Exact six.");
  strcpy(option2[2]," 3. I need time till death.");
  correct_ans[1]=1;

  //Question 3

  strcpy(quest[2], "How to save a drowning person?");
  strcpy(option3[0], "1.Jump into the water and save him.");
  strcpy(option3[1], "2.Comment on the post.");
  strcpy(option3 [2], "3.Tell him not to drown.");
  correct_ans[2]=2;

  //Question 4

  strcpy(quest[3], "Where will you be in 2 years from now?");
  strcpy(option4[0], "1.Obviously on earth");
  strcpy(option4[1], "2.In 2021");
  strcpy(option4[2], "3.In google");
  correct_ans[3] = 0;

  //Question 5

  strcpy(quest[4], "How can you fly like a bird?");
  strcpy(option5[0], "1.Keep a balloon on your head.");
  strcpy(option5[1], "2.Flap your arm really hard");
  strcpy(option5[2], "3.Sleep and dream");
  correct_ans[4] = 1;


  do
  {
       //Selection Menu

       printf("\n\t\t 1. Display Questions");
       printf("\n\t\t 2. Display Correct Answers");
       printf("\n\t\t 3. Display Result");
       printf("\n\t\t 4. EXIT");
       printf ("\n\t\t ____________________________________");
       printf("\n\n\n\t\t Enter your option: ");

       //User Input
       scanf("%d", &option);

       //Switch - Case for the option selected

       switch(option)
       {

             case 1:

                  //Printing Question 1 and taking response
                  printf ("\n\t\t %s \n", quest [0]);
                  for(i=0;i<3;i++)
                  {
                     printf("\n\t\t %s", option1[i]);
                  }
                  printf ("\n\n\t\t Enter your answer number: ");
                  scanf("%d", &response[0]);

                  //Printing Question 2 and taking response
                  printf ("\n\t\t %s \n", quest [1]);
                  for (i=0;i<3;i++)
                  {
                     printf("\n\t\t %s", option2[i]);
                  }
                  printf("\n\n\t\t Enter your answer number: ");
                  scanf("%d", &response[1]);

                  //Printing Question 3 and taking response
                  printf("\n\t\t %s \n", quest[2]);
                  for(i=0;i<3;i++)
                  {
                     printf("\n\t\t %s", option3[i]);
                  }
                  printf("\n\n\t\t Enter your answer number: ");
                  scanf ("%d", &response [2]);

                  //Printing Question 4 and taking response
                  printf("\n\t\t %s \n", quest[3]);
                  for (i=0;i<3;i++)
                  {
                     printf("\n\t\t %s", option4[i]);
                  }
                  printf("\n\n\t\t Enter your answer number: ");
                  scanf ("%d", &response [3]);

                  //Printing Question 5 and taking response
                  printf("\n\t\t %s \n", quest[4]);
                  for (i=0;i<3;i++)
                  {
                     printf("\n\t\t %s", option5[i]);
                  }
                  printf("\n\n\t\t Enter your answer number: ");
                  scanf ("%d", &response [4]);

                  //End of Case 1
                  break;

             case 2:

                  //Display the correct answers of all the questions
                  printf("\n\n\t\t CHECK THE CORRECT ANSWERS");
                  printf("\n\t\t__________________________________________________");

                  printf("\n\n\t\t %s \n\t\t%s",quest[0] ,option1[correct_ans[0]]);
                  printf("\n\n\t\t %s \n\t\t%s",quest[1] ,option2[correct_ans[1]]);
                  printf("\n\n\t\t %s \n\t\t%s",quest[2] ,option3[correct_ans[2]]);
                  printf("\n\n\t\t %s \n\t\t%s",quest[3] ,option4[correct_ans[3]]);
                  printf("\n\n\t\t %s \n\t\t%s",quest[4] ,option5[correct_ans[4]]);

                  //End of Case 2
                  break;

             case 3:

                  //Displaying the score obtained in the Quiz
                  marks = 0;
                  for(i = 0;i <= 4;i++)
                  {
                     if(correct_ans[i]+1==response[i])
                     {
                         marks++;
                     }
                  }

                  //Condition when at least 1 answer is correct but not all are correct
                  if(marks > 0 && marks < 5)
	              {
                     printf("\n\n\t\t**************** CONGRATULATION *****************");
	                 printf("\n\t\t You won $%d",marks*1000000);
                  }

                  //Condition when all the answers are correct
	              else if(marks == 5)
	              {
                     printf("\n\n\n\t\t**************** CONGRATULATION ****************");
                     printf("\n\t\t YOU ARE A MILLIONAIRE!!!!!!!!!");
                     printf("\n\t\t You won $%d",marks*1000000);
	                 printf("\n\t\t Thank You!!");
                  }

                  //Condition when no answer is correct
	              else
                  {
	                 printf("\n\n\t\t\t******** SORRY YOU DIDN'T WIN ANY CASH ********");
                     printf("\n\t\t\t\t Thanks for your participation");
	                 printf("\n\t\t\t\t TRY AGAIN");
                  }

                  //End of Case 3
                  break;

      //End of switch - case block
      }

   //End of do - while loop with condition that choice input is not 4 (Exit Case)
   }while(option != 4);

   //End of main() function
   return 0;

}
