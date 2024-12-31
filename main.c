#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
   int flagSet;
   int opt;
   char execfile[256] = ""; 
   while((opt = getopt(argc, argv, ":f:")) != -1)  {  //this is easier than long opts and -1 dependancy
        switch(opt)  
        {  
            case 'f':  
                printf("Executing %s\n", optarg);
                strncpy(execfile, optarg, sizeof(execfile) - 1);
                execfile[sizeof(execfile) - 1] = '\0';  
                break;  
            case ':':  
                printf("Option needs a value\n");  
                break;  
            case '?':  
                printf("Unknown option: %c\n", optopt); 
                break;  
        }  
    }  
   if (strlen(execfile) == 0) {
       fprintf(stderr, "No file provided with -f option\n");
       return 1;
   }
   FILE* file = fopen(execfile, "r");
   char line[256];
   if (file != NULL) {//hope it aint null
      while (fgets(line, sizeof(line), file)) {
         line[strcspn(line, "\n")] = '\0';  
         // i may add a dpendancy thing later
         if (strncmp(line, "<exec>", 6) == 0) {
            flagSet = 1;
         } else if (strncmp(line, "<info>", 6) == 0) {
            flagSet = 2;
         } else if (strncmp(line, "<com>", 5) == 0) {
            flagSet = 0;
         } else if (strncmp(line, "<out>", 5) == 0) {
            flagSet = 3;
         } else if (strncmp(line, "<end>", 5) == 0) {
            printf("End of script!\n");
            break;  
         } else if (strncmp(line, "<start>", 7) == 0) {
            printf("Starting Script\n");
         } else if (strncmp(line, "<pkgname>", 6) == 0) {
            flagSet = 4;//i gotta get rid of this int controlling 
         } else if (strncmp(line, "<version>", 5) == 0) {
            flagSet = 5;
         } else if (strncmp(line, "<repo>", 5) == 0) {
            flagSet = 6;
         }
         if (flagSet == 0) {
            if (strncmp(line, "<com>", 5) == 0) {// TODO: make this better maybe use a // or # for comments
            } else {
            }
         }
         if (flagSet == 1) {
            if (strncmp(line, "<exec>", 5) == 0) {//might switch exec to pkgcmds but idk
            } else {
               printf("Executing: %s\n", line);
               char cmd[256];
               strncpy(cmd, line, sizeof(cmd)-1); 
               cmd[sizeof(cmd)-1] = '\0'; 
               system(cmd);
            }
         }
         if (flagSet == 2) {
            if (strncmp(line, "<info>", 5) == 0) {

            } else {
               printf("Info: %s\n", line);
            }
         }
         if (flagSet == 3) {
            if (strncmp(line, "<out>", 5) == 0) {
            } else {
               printf("%s\n", line);
            }
         }
         if (flagSet == 4) {
            if (strncmp(line, "<pkgname>", 5) == 0) {
            } else {
               printf("Package Name: %s\n", line);
            }
         }
         if (flagSet == 5) {
            if (strncmp(line, "<version>", 5) == 0) {
            } else {
               printf("Version: %s\n", line);
            }
         }

         if (flagSet == 6) {
            if (strncmp(line, "<repo>", 5) == 0) {
            } else {
               printf("Repo: %s\n", line);
            }
         }
      }
      fclose(file);//closes the file!
   } else {
      fprintf(stderr, "File unable to be read\n");//it failed to read :C
   }
   return 0;//must return 0
}