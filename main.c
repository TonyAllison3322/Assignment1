#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    //Function prototypes
    
    char EIB(char letter, int key); //encryption in bounds of 56 - 90
    char EOB(char letter, int key); //encryption out of bounds of 56 - 90
    char DIB(char letter, int key); //decryption in bounds of 56 - 90
    char DOB(char letter, int key); //decryption out of  bounds of 56 - 90
    char DWK(char letter, int key); //decryption with key
    char EWK(char letter, int key); //encryption with key
    int main()
    
{

    //Variables
    int key;     // intialises key for future use
    char letter; // stores 'letter' as a char variable
    int userchoice; 

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
        
        // Decryption with key 
         fscanf(file_pointer,  "%d", &key);
         fprintf(output, "Key is %d\n", key);
         //printf("%c", EWK(letter, key));
         //printf("%c", DWK(letter, key));
         
         

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
}

char DOB(char letter, int key)
{
    char letterD;
    letterD = letter - key + 26;
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
                    
                    if(letter + key < 'A' )
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
}
