#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>


int main(int argc, char** argv)
{

    int pipefd[3][2];
    char *arg_cut[] = {"cut", "-d", ":", "-f", "7","/etc/passwd",NULL};
    char *arg_sort[] = {"sort",NULL};
    char *arg_uniq[] = {"uniq",NULL};
    char *arg_wc[] = {"wc","-l",NULL};

    if (pipe(pipefd[0]) == -1) 
    {
            perror("pipe");
            exit(EXIT_FAILURE);
    }
    


    pid_t pid1 = fork();
    if(pid1 == -1)
	{
		perror("fork failed");
        exit(EXIT_FAILURE);
	} 


    if(pid1 == 0)
    {
          close(pipefd[0][0]);
          if(dup2(pipefd[0][1],STDOUT_FILENO) == -1)
          {
            close(pipefd[0][1]);
            perror("dup2");
            exit(EXIT_FAILURE);
          }

          close(pipefd[0][1]);

          if(execvp(arg_cut[0],arg_cut) == -1)
          {
                perror("execvp");
                exit(EXIT_FAILURE);
          }
    }   
    
    if (pipe(pipefd[1]) == -1) 
    {
            perror("pipe");
            exit(EXIT_FAILURE);
    }
    
    pid_t pid2 = fork();               
    if(pid2 == -1)
	{
		perror("fork failed");
        exit(EXIT_FAILURE);
	} 
    

    if(pid2 == 0)
    {
          close(pipefd[0][1]);
          close(pipefd[1][0]);

          if(dup2(pipefd[0][0],STDIN_FILENO) == -1)
          {
            close(pipefd[0][0]);
            close(pipefd[1][1]);
            perror("dup2");
            exit(EXIT_FAILURE);
          }

          if(dup2(pipefd[1][1],STDOUT_FILENO) == -1)
          {
            close(pipefd[0][0]);
            close(pipefd[1][1]);
            perror("dup2");
            exit(EXIT_FAILURE);
          }

          close(pipefd[0][0]);
          close(pipefd[1][1]);

          if(execvp(arg_sort[0],arg_sort) == -1)
          {
                perror("execvp");
                exit(EXIT_FAILURE);
          }

    } 

    close(pipefd[0][0]);
    close(pipefd[0][1]);

    if (pipe(pipefd[2]) == -1) 
    {
            perror("pipe");
            exit(EXIT_FAILURE);
    }    

    pid_t pid3 = fork();
    if(pid3 == -1)
	{
		perror("fork failed");
        exit(EXIT_FAILURE);
	}
    

    if(pid3 == 0)
    {
          close(pipefd[1][1]);
          close(pipefd[2][0]);
          
          if(dup2(pipefd[1][0],STDIN_FILENO) == -1)
          {
            close(pipefd[1][0]);
            close(pipefd[2][1]);
            perror("dup2");
            exit(EXIT_FAILURE);
          }

          if(dup2(pipefd[2][1],STDOUT_FILENO) == -1)
          {
            close(pipefd[1][0]);
            close(pipefd[2][1]);
            perror("dup2");
            exit(EXIT_FAILURE);
          }          

          close(pipefd[1][0]);
          close(pipefd[2][1]);

          if(execvp(arg_uniq[0],arg_uniq) == -1)
          {
                perror("execvp");
                exit(EXIT_FAILURE);
          }

    } 

    close(pipefd[1][1]);
    close(pipefd[1][0]);

    pid_t pid4 = fork();

    if(pid4 == -1)
	{
		perror("fork failed");
        exit(EXIT_FAILURE);
	} 
    

    if(pid4 == 0)
    {
          close(pipefd[2][1]);
          
          
          if(dup2(pipefd[2][0],STDIN_FILENO) == -1)
          {
            close(pipefd[2][0]);
            perror("dup2");
            exit(EXIT_FAILURE);
          }
                   

          close(pipefd[2][0]);

          if(execvp(arg_wc[0],arg_wc) == -1)
          {
                perror("execvp");
                exit(EXIT_FAILURE);
          }

    }

    
    close(pipefd[2][1]);
    close(pipefd[2][0]);    

    waitpid(pid1,NULL,0);
    waitpid(pid2,NULL,0);
    waitpid(pid3,NULL,0);
    waitpid(pid4,NULL,0);

   
    return 0;	
}
