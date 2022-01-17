#include <stdio.h>
#include <stdlib.h>

void check_comment (char) ;
void close_comment (int) ; 
void string_comment();
void character_comment();

int main(void)
{
    char c;
    while((c=getchar())!=EOF)       // read the file character by character
        check_comment(c);   

    return 0;
}
void check_comment(char c)// check a character if it is the beginning of a comment
{
    char d;
    int line;
    int num;
    char e;
    char f;
    if(c=='\n'){
        line++;
        num=line;    
    }
    else if( c == '/')   // if the character starts with '/', it 'could' be a comment
    {
        if((d=getchar())=='*'){
         num+= 1;  // if the next character is '*', it is the beginning of comment  
         close_comment(num);  
                              }
        else
        {
            putchar(c);
            putchar(d);
        }
    }
    else if (c == '\"')
    {
        putchar(c);        
        string_comment();
        }
        
     else if (c == '\'')
    {
        putchar(c);
        character_comment();
        }
        
     else if (c=='\\'){
          if((d=getchar())=='n'){
               putchar('\n');  }
                    }     
    else
        putchar(c);
}

//checks if a comment is properly closed
void close_comment(int num)
{

 int d,e;

    while((d=getchar())!=EOF) // the block comment has started, read the character
    {
        if(d=='*')    // if the comment 'seems' like ending
        { 
            e=getchar();  // check if it actually ends (block comments end with '*/')

            if(e=='/'){       // if the comment 'has' ended, return from the function
                putchar(' ');  
                return;
                      }
        }
   }
   printf("\nError: line %d: unterminated comment",num);
}

//handles string literals
void string_comment(){
    char d,e;
     while((d=getchar())!=EOF){
        putchar(d);
    
        }
    }
//handles character literals    
void character_comment(){
    char d,e;
    while((d=getchar())!=EOF){
        putchar(d);
        }
}

