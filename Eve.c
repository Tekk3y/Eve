#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main (void)
{
    //declaring vriables
    DIR *dp;
    struct dirent *ep;
    dp = opendir ("./");
    const int MAXFILES = 100;
    char list[MAXFILES][256];

    int c = 0;

    int possibleIssues = 0;
    int issueCount = 0;
    int mode = 0;

//starts program
printf("Eve V0.1 \n\n");
printf("Dev Notes: Most features are still not functioning. \n\n\n");
while (mode < 3){
if (mode == 0){

    printf("\n\nOptions:\n");
    printf("\n\n1: Scan Directory ");
    printf("\n\n2: Display Files ");
    printf("\n\n3: Exit ");
    printf("\n\nEnter Route: ");
    scanf("%d",&mode);

    DIR *dp;
    struct dirent *ep;


}

//reads directory constantly

if (dp != NULL)
    {
        while ((ep = readdir (dp)) && (c < MAXFILES)){
            strcpy(list[c],ep->d_name);


            if (list[c] == "bin"){
            possibleIssues = possibleIssues + 1;
            }

            ++c;

            issueCount = possibleIssues;
            possibleIssues = 0;


        }

(void) closedir (dp);
    }
    else
        perror ("Couldn't open the directory");


//displays issues (doesnt wor yet)
if (mode == 1){

if (dp != NULL)
    {
        while ((ep = readdir (dp)) && (c < MAXFILES)){
            strcpy(list[c],ep->d_name);


            if (list[c] == "bin"){
            possibleIssues = possibleIssues + 1;

            }


            ++c;

        }


(void) closedir (dp);
    }
    else
        perror ("Couldn't open the directory");

    issueCount = possibleIssues;
    possibleIssues = 0;

printf("\n\n Issues:\n");
printf("\n [%d]\n", issueCount);

mode = 0;
}



//Displays all of the files in the directory
if (mode == 2){

printf("\n All files in Directory: \n");
while (c > 0){
    printf("\n [%s]\n", list[c]);


    c = c - 1;
}
mode = 0;
}
}
return 0;
}
