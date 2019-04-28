#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    //Function prototypes
    
    char EIB(char letter, int key); //encryption in bounds of 56 - 90
    char EOB(char letter, int key); //encryption out of bounds of 56 - 90
    char DIB(char letter, int key); //decryption in bounds of 56 - 90
    char DOB(char letter, int key); //decryption out of  bounds of 56 - 90
    char DWK(char letter, int key); //rotation decryption with key
    char EWK(char letter, int key); //Rotation encryption with key
    char SUBEWK(char letter, int i); //Substitution encryption with key
    char SUBDWK(char letter, int i); //Substitution decryption with key
    int main()
    
{

    //Variables
    int key;     // intialises key for future use
    char letter; // stores 'letter' as a char variable
    int userchoice; 
    char subkey[26];
    int i ;
    char ch;
    char *p;
    int index;
    char letterN;
    
    FILE * subkeyinput;
        subkeyinput = fopen("subkeyinput.txt", "r");
    FILE * output;
    output = fopen("rotkeyoutput.txt", "w"); 
    if (output == NULL) 
        {
        perror("Error:");
        return -1;
        }  
    FILE * file_pointer;                    // intialising and opening of key input text file
    file_pointer = fopen("rotkeyinput.txt", "r");
    if (file_pointer == NULL) 
        {
        perror("Error:");
        return -1;
        }
    FILE * subinput;
    subinput = fopen("subinput.txt", "r" );
    if (file_pointer == NULL) 
        {
        perror("Error:");
        return -1;
        }
        
         //fscanf(file_pointer,  "%d", &key);
         //fprintf(output, "Key is %d\n", key);
         //printf("%c", EWK(letter, key));
         //printf("%c", DWK(letter, key));
         //printf("%c", SUBEWK(letter, i));
         //printf("%c", SUBDWK(letter, i));
    while(!feof(subinput))
    {
        fscanf(subkeyinput, "%s", subkey);
        fscanf(subinput, "%c", &letter);
        if(letter >= 'A' && letter <= 'Z')
        {
            printf("%c\t\t", letter);
            
            p = strchr(subkey, letter);
            printf("%d\t", p);
            index = (int)(p - subkey);
            printf("%d\t\t",index);
            fseek( subkeyinput, index , SEEK_SET);
            letterN = index + 65;
            printf("%c\n", letterN);
            p = 0;
        }
        else if(letter >= 'a' && letter <= 'z')
        {
            letter = letter - 32;
            char *p;
            int index;
            p = strchr(subkey, letter);
            index = (int)(p - subkey);
            fseek( subkeyinput, index , SEEK_SET);
            letterN = index + 65;
            printf("%c\n", letterN);
            
        }
        else
        {
            letterN = letter;
            printf("%c\n", letter);
            p = 0;
        } 
    }


    
    
   

   
  /* const char c;
   char *p;
        while (!feof(subinput))
        {
            fscanf(subkeyinput, "%s", subkey);  // reads key file as a string
            fscanf(subinput, "%c", &letter); // scans the text file for a char
           
            p = strchr(subkey, letter);
            
            printf("%c", p);
        }
*/
fclose(output);       //closes the file
fclose(file_pointer); //closes the file

return(0);
}

//Function Definitions

char EIB(char letter, int key)
{
    char letterE;
    letterE = letter + key;
    return(letterE);
}

char EOB(char letter, int key)
{
    char letterE;
    letterE = letter + key - 26;
    return(letterE);
}

char DIB(char letter, int key)
{
    char letterD;
    letterD = letter - key;
    return(letterD);
}

char DOB(char letter, int key)
{
    char letterD;
    letterD = letter - key + 26;
    return(letterD);
}

char DWK(char letter, int key)
{
FILE * outputtext;
    outputtext = fopen("rotoutput.txt", "w");
    FILE * input;                    // intialising and opening of input text file
    input = fopen("rotinput.txt", "r"); 
    FILE * output;
    output = fopen("rotkeyoutput.txt", "w");
    FILE * file_pointer;                    // intialising and opening of key input text file
    file_pointer = fopen("rotkeyinput.txt", "r");

   fscanf(file_pointer,  "%d", &key); // enters value of key
        printf("Key is %d\n", key);
        
    while (!feof(input)) // expect 1 successful conversion
        {
         fscanf(input,  "%c", &letter); // get the values from the input text file
            if(letter >=65 && letter <=90)
                {
                    
                    if(letter - key < 'A' )
                    {
                        printf("%c", DOB(letter, key)); 
                        fprintf(outputtext, "%c", EOB(letter, key));
                    }
                    else
                    {
                        printf("%c", DIB(letter, key));
                        fprintf(outputtext, "%c", DIB(letter, key));
                    }
                }
            
            else if(letter >= 'a' && letter <= 'z')
                {
                    letter = letter - 32;
                    if(letter - key < 'A' )
                    {
                        printf("%c", DOB(letter, key));
                        fprintf(outputtext, "%c", DOB(letter, key));
                    }
                    else
                    {
                        printf("%c", DIB(letter, key));
                        fprintf(outputtext, "%c", DIB(letter, key));
                    }
                }
            else
                {
                    printf("%c", letter);
                    fprintf(outputtext, "%c", letter);
                }
        } 
        return(letter);
}

char EWK(char letter, int key)
{
    FILE * outputtext;
    outputtext = fopen("rotoutput.txt", "w");
    FILE * input;                    // intialising and opening of input text file
    input = fopen("rotinput.txt", "r"); 
    FILE * output;
    output = fopen("rotkeyoutput.txt", "w");
    FILE * file_pointer;                    // intialising and opening of key input text file
    file_pointer = fopen("rotkeyinput.txt", "r");

   fscanf(file_pointer,  "%d", &key); // enters value of key
        printf("Key is %d\n", key);
        
    while (!feof(input)) // expect 1 successful conversion
        {
         fscanf(input,  "%c", &letter); // get the values from the input text file
            if(letter >=65 && letter <=90)
                {
                    
                    if(letter + key > 'Z' )
                    {
                        printf("%c", EOB(letter, key)); 
                        fprintf(outputtext, "%c", EOB(letter, key));
                    }
                    else
                    {
                        printf("%c", EIB(letter, key));
                        fprintf(outputtext, "%c", EIB(letter, key));
                    }
                }
            
            else if(letter >= 'a' && letter <= 'z')
                {
                    letter = letter - 32;
                    if(letter - key > 'Z' )
                    {
                        printf("%c", EOB(letter, key));
                        fprintf(outputtext, "%c", EOB(letter, key));
                    }
                    else
                    {
                        printf("%c", EIB(letter, key));
                        fprintf(outputtext, "%c", EIB(letter, key));
                    }
                }
            else
                {
                    printf("%c", letter);
                    fprintf(outputtext, "%c", letter);
                }
        } 
        return(letter);
}
char SUBEWK(char letter, int i) 
{
    
    
        FILE * subkeyinput;
        subkeyinput = fopen("subkeyinput.txt", "r");
        FILE * subinput;
        subinput = fopen("subinput.txt", "r" );
        
   while (!feof(subinput)) // expect 1 successful conversion 
        {
            char subkey[26];
            int i;
            char letter, ch;
            
            fscanf(subkeyinput, "%s", subkey);  // reads key file as a string
            fscanf(subinput, "%c", &letter); // scans the text file for a char
            
            
            if(letter >= 'A' && letter <= 'Z')
            {
                letter = letter - 65;            // makes the letter a int between 1 to 26
                i = letter;                      // makes the 'i' offset = to the letter so that the seek statement can move to the key in that slot.
                fseek( subkeyinput, i , SEEK_SET ); // moves pointer to the corresponding letter
                fscanf(subkeyinput, "%c", &ch);     // scans the single character and prints the encryption
                printf("%c", ch);   
            }
            else if(letter >= 'a' && letter <= 'z')
            {
                letter = letter - 32;
                letter = letter - 65;            // makes the letter a int between 1 to 26
                i = letter;                      // makes the 'i' offset = to the letter so that the seek statement can move to the key in that slot.
                fseek( subkeyinput, i , SEEK_SET ); // moves pointer to the corresponding letter
                fscanf(subkeyinput, "%c", &ch);     // scans the single character and prints the encryption
                printf("%c", ch);
            }
            else if(fscanf(subkeyinput, "%c", &ch)) 
            {
                printf("%c", letter);
            }
        }
}

