#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdint.h>

int getpoints(int fd,char* answers)
{
    char student_answer;
    int correct = 0;
    for(int i = 0; i < 25; i++)
    {
        if(read(fd,&student_answer,1) == -1)
        {
            //close(fd);
            //free(answers);
            //err(1,"Cannot read answers!");
            return -1;
        }

        if(student_answer == answers[i])
            correct++;

        if(lseek(fd,SEEK_CUR,1) == -1)
        {
            //close(fd);
            //free(answers);
            //err(1,"Lseek dont work!");
            return -1;
        }
    }

    return correct;    
}

char getgrade(int points)
{
    if(points <= 25 && points >= 22)
        return '6';
    else if(points <= 21 && points >= 19)
        return '5';
    else if(points <= 18 && points >= 16)
        return '4';
    else if(points <= 15 && points >= 13)
        return '3';
    else
        return '2';
}



int main(int argc, char* argv[])
{
    int fd_answers = open(argv[2],O_RDONLY);
    if(fd_answers == -1) err(1,"Answers cannot open!"); 

    char *answers = malloc(sizeof(char) * 25); 
    if(answers == NULL)
    {
        close(fd_answers);
        err(1,"Cannot allocate memory!");
    }  
 
    for(int i = 0; i < 25; i++)
    {
        if(read(fd_answers,&answers[i],sizeof(char)) == -1)
        {
            close(fd_answers);
            free(answers);
            err(1,"Cannot read answers!");
        }
        if(lseek(fd_answers,1,SEEK_CUR) == -1)
        {
            close(fd_answers);
            free(answers);
            err(1,"Lseek dont work!");
        }
    }
    
    close(fd_answers);
    
    /*for(int i = 0; i<25; i++)
        printf("%c\n",answers[i]);*/

    
    for(int i = 1; i <= 25;i++)
    {
        char* answers_path = malloc(strlen(argv[1]) + sizeof(char) * 3);
        if(answers_path == NULL)
        { 
            free(answers);
            err(1,"Cannot allocate answers_path memory!");
        }  
        if(sprintf(answers_path,"%s%d\0",argv[1],i) == -1)
        {
            free(answers);
            free(answers_path);
            err(1,"Sprintf() doesnt work!");
        }


        char* results_path = malloc(strlen(argv[3]) + sizeof(char) * 3);
        if(results_path == NULL)
        {
            free(answers);
            free(answers_path);
            err(1,"Cannot allocate results_path memory!");
        }  
        if(sprintf(results_path,"%s%d\0",argv[3],i) == -1)
        {
            free(answers);
            free(answers_path);
            free(results_path);
            err(1,"Sprintf() doesnt work!");
        }


        int fd_student = open(answers_path,O_RDONLY);
        if(fd_student == -1)
        {
            free(answers);
            free(answers_path);
            free(results_path);
            err(1,"Student file cannot open!");
        }
        
        int fd_result = open(results_path,O_WRONLY);
        if(fd_result == -1)
        {
            close(fd_student);
            free(answers);
            free(answers_path);
            free(results_path);
            err(1,"Result file cannot open!");
        }

        int points = getpoints(fd_student,answers);       
    
        if(points == -1)
        {
            close(fd_student);
            close(fd_result);
            free(answers);
            free(answers_path);
            free(results_path);
            err(1,"Cannot take points!");
        }

        char grade = getgrade(points);
        printf("Student %d : grade:%c points: %d\n",i,grade,points);
        if(write(fd_result,&grade,1) == -1)
        {
            close(fd_student);
            close(fd_result);
            free(answers);
            free(answers_path);
            free(results_path);
            err(1,"Cannot write in file!");
        }
        
        close(fd_student);
        close(fd_result);
        free(answers_path);
        free(results_path);
    }
    
    free(answers);
    
    return 0;
    
}
