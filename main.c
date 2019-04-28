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
    int userinput;
    int userchoice;
    int i;
   
    printf("Hello\nWhich cipher would you like to use?\n\n1) Rotational?\n2) Substitutional?\n");
    scanf("%d", &userchoice);
    switch (userchoice)
    {
        case(1) :
        {
            printf("Are you trying to 1) Encrypt or 2) Decrypt?\n");
            scanf("%d", &userinput);
            switch(userinput)
            {
                case(1) :
                {
                    printf("You picked Encrypt\nTo input and output your key and message you will need to have three files named : \n");
                    printf("rotinput.txt, rotkeyinput.txt, rotoutput.txt\n For your text input, key input and text output respectively\n");
                    printf("If no error has occured you have named files correctly and it will now encrypt.\n");
                    printf("%c", EWK(letter, key));
                    break;
                }
                case(2) :
                {
                    printf("You picked Decrypt\nTo input and output your key and message you will need to have three files named : \n");
                    printf("subinput.txt, subkeyinput.txt, suboutput.txt\n For your text input, key input and text output respectively\n");
                    printf("If no error has occured you have named files correctly and it will now decrypt.\n");
                    printf("%c", DWK(letter, key));
                    break;
                }
            }
            break;
        }
        case(2) :
        {
            printf("Are you trying to 1) Encrypt or 2) Decrypt?\n");
            scanf("%d", &userinput);
            switch(userinput)
            {
                case(1) : 
                {
                    printf("You picked Encrypt\nTo input and output your key and message you will need to have three files named : \n");
                    printf("rotinput.txt, rotkeyinput.txt, rotoutput.txt\n For your text input, key input and text output respectively\n");
                    printf("If no error has occured you have named files correctly and it will now encrypt.\n");
                    printf("%c", SUBEWK(letter, i));   
                }
                case(2) :
                {
                    printf("You picked Decrypt\nTo input and output your key and message you will need to have three files named : \n");
                    printf("rotinput.txt, rotkeyinput.txt, rotoutput.txt\n For your text input, key input and text output respectively\n");
                    printf("If no error has occured you have named files correctly and it will now decrypt.\n");
                    printf("%c", SUBDWK(letter, i));
                }
            }
            break;
        }
        default :
        {
            printf("You failed try again");
            break;
        }
    }
    return 0;
}

    
        

         //printf("%c", EWK(letter, key));
         //printf("%c", DWK(letter, key));
         //printf("%c", SUBEWK(letter, i));
         //printf("%c", SUBDWK(letter, i));



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
        FILE * suboutput;
        suboutput = fopen("suboutput.txt","w");
    
        
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
                fprintf(suboutput, "%c", ch);
            }
            else if(letter >= 'a' && letter <= 'z')
            {
                letter = letter - 32;
                letter = letter - 65;            // makes the letter a int between 1 to 26
                i = letter;                      // makes the 'i' offset = to the letter so that the seek statement can move to the key in that slot.
                fseek( subkeyinput, i , SEEK_SET ); // moves pointer to the corresponding letter
                fscanf(subkeyinput, "%c", &ch);     // scans the single character and prints the encryption
                printf("%c", ch);
                fprintf(suboutput, "%c", ch);
            }
            else if(fscanf(subkeyinput, "%c", &ch)) 
            {
                printf("%c", letter);
                fprintf(suboutput, "%c", letter);
            }
        }
}
char SUBDWK(char letter, int i)
{
     // stores 'letter' as a char variable
    char subkey[26];
    char ch;
    char *p; // sets a pointer for use in th strchr function.
    int index;  // allows a value to be associated with the length of a str at the pointer.
    char letterN;
    FILE * subkeyinput;
    subkeyinput = fopen("subkeyinput.txt", "r");
    FILE * subinput;
    subinput = fopen("subinput.txt", "r" );
    FILE * suboutput;
    suboutput = fopen("suboutput.txt","w");
    
    while(!feof(subinput))
    {
        fscanf(subkeyinput, "%s", subkey);
        fscanf(subinput, "%c", &letter);
        if(letter >= 'A' && letter <= 'Z')
        {
           
            p = strchr(subkey, letter); // scanning the key for the first instance of a letter.
            index = (int)(p - subkey); // algorithim which gives the length of a str at the pointer.
            fseek( subkeyinput, index , SEEK_CUR); // using the index the seek statment has a address to look at
            letterN = index + 65; //the index will be between 0 and 25 so adding 65 will bump it into ascii
            printf("%c", letterN);
            fprintf(suboutput, "%c", letterN);
        }
        else if(letter >= 'a' && letter <= 'z')
        {
            letter = letter - 32;
            char *p;
            int index;
            p = strchr(subkey, letter);
            index = (int)(p - subkey);
            fseek( subkeyinput, index , SEEK_CUR);
            letterN = index + 65;
            printf("%c", letterN);
            fprintf(suboutput, "%c", letterN);
       }
         else
        {
            
            printf("%c", letter);
            fprintf(suboutput, "%c", letter);
        } 
    }
}


