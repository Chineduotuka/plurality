#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// MAX is a number defined that would be used to make refernce to the maximum number of candidates when creating candidate array
#define MAX 9

//define a candidate struct that has a name and votes
typedef struct 
{
    char *name;
    int votes;
}
candidate;

//Array of candidates
candidate candidates[MAX];

//define a candidate count of type integer
int candidate_count;

//define a function for voting which returns true or false
bool vote(char *votedName);

//define a function that prints out the winner
void print_winner(void);

int main(int argc, char *argv[])
{
//check the argcument count to not be less than 2
    if(argc <2)
    {
//print out an error if argument count is less than 2
        printf("usage: plurality [candidate ...]\n");

        return 1;
    }

//equating candidate_count to be 1 less than the argument count, this is factoring that fact that the argument count includes ./plurality
    candidate_count = argc - 1;

//checvking is candidate_count is greter than the defined MAX and printing out an error.
    if(candidate_count > MAX)
    {
        printf("maximum number of candidates is %d\n", MAX);

        return 2;
    }

//loop throught the candidate count and assign a name to different index of the candidate name structure and
//assigning each candidate votes to zero(0)
    for(int i=0; i<candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];

        candidates[i].votes = 0;
    }

//defining a voter count of type integer
    int voter_count;

//print out the discription of the intended user input.
    printf("input number of voters: ");

//recieveing an input from the user.(number olf voters)
    scanf("%d", &voter_count);

//defining a char of intended  voters choice
    char votedName[50];

//looping through the voter count     
    for(int j=0; j<voter_count; j++)
    {
        printf("voter's choice: ");

        fgets(votedName, 50, stdin);
        votedName[strcspn(votedName, "\n")] = '\0';

        if(!vote(votedName))
        {
            printf("inavild vote. \n");
        }
    }

    print_winner();

}

//funtion for vote
bool vote(char *votedName)
{

//looping throught the candidate count and comparing it with the inputpted voter's chioice
//if it matches, we increment the candidates vote count by 1.
    for(int i =0; i<candidate_count; i++)
    {
        if(strcmp(candidates[i].name, votedName) == 0)
        {
            candidates[i].votes ++;

            return true;
        }
    }

    return false;
}

void print_winner(void)
{

//defining a maximum vote value to refernce to     
    int maximum_vote = 0;

//looping through to copy the candidate votes value to maximum vote value if and only if it is greater than maximum vote value
    for(int i =0; i<candidate_count; i++)
    {
        if(candidates[i].votes > maximum_vote)
        {
            maximum_vote = candidates[i].votes;
        }
    }

//looping through the candidate count to find out if the candidate vote at a specific index is the maximum vote value
//and printing out the candidate name at that specific index.
    for(int i=0; i<candidate_count; i++)
    {
        if(candidates[i].votes == maximum_vote)
        {
            printf("the winner is : %s\n", candidates[i].name);
        }
    }
    return;
}
