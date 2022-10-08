//implementation of a lexical analyzer.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int iskeyword(char buffer[])
{
   char keywords[32][10] = {
   "auto","break","case","char","const","continue","default",
"do","double","else","enum","extern","float","for","goto",
"if","int","long","register","return","short","signed",
"sizeof","static","struct","switch","typedef","union",
"unsigned","void","volatile","while" }; 
   int flag = 0;
   for(int i = 0; i < 32; ++i) 
   {
        if(strcmp(keywords[i], buffer) == 0)
        {
            flag = 1;
            break;
        }
        
   }
   
   return flag;
}
int main()
{
   char ch, buffer[50];
   char operators[] = "+-=*%/";
   int i , j = 0;
   FILE* fp;
   fp = fopen("demo1.c", "r");
   if(fp == NULL){
    printf("error while opening the file\n");
    exit(0);
}
   while((ch = fgetc(fp)) != EOF)
   {
    for(i = 0; i < 6; i++)
    {
        if(ch == operators[i])
        {
            printf("%c is an operator", ch);
        }
    }
    if(isalnum(ch))
    {
        buffer[j++] = ch;
    }
    else if((ch == ' ' || ch == '\n') && (j != 0))
    {
         buffer[j] = '\0';
         j = 0;
         if(iskeyword(buffer) == 1)
         {
            printf("%s is a keyword\n", buffer);
         }
         else
         printf("%s is an identifier\n", buffer);
    }
    }
    fclose(fp);
    return 0;
}
