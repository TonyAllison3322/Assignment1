#include <stdio.h>
#include <stdlib.h>

    //Function prototypes
    
    char EIB(int letter, int key); //encryption in bounds of 56 - 90
    char EOB(int letter, int key); //encryption out of bounds of 56 - 90
    char DIB(int letter, int key); //decryption in bounds of 56 - 90
    char DOB(int letter, int key); //decryption out of  bounds of 56 - 90
    
    
    int main()
    
{
    //Functions

    //Variables
    
    int key;     // intialises key for future use
    char letter; // stores 'letter' as a char variable
    int userchoice; 

        /*-----------------User interface here-------------------------*/
        /*printf("Hello, Which cipher would you like to use?\n\n1) Rotational\n2) Substitution\n");
        scanf("%d", &userchoice);
        switch(userchoice)
            {
            case '1': 
            printf("You chose Rotational Cipher\n")
            printf("")
            }*/
    FILE * file_pointer;                    //initalise a file for use
    file_pointer = fopen("input.txt", "r"); // opens the file
    
    if (file_pointer == NULL) 
        {
        perror("Error:");
        return -1;
        }
    //fix the space bar key and star degryption
    
    /*Encyption 
   
        fscanf(file_pointer,  "%d", &key); // enters value of key
        printf("Key is %d\n\n", key);
        
    while (!feof(file_pointer)) // expect 1 successful conversion
        {
        fscanf(file_pointer,  "%c", &letter); // get the values from the input text file
       
        // Spacebar Block
        
       
            if(letter == 32) {// 32 = space
            printf("%c", letter);
           }

            else if  (letter > 90) // encyption
            {  
            letter = letter - 32; // turns the letter ASCII number from a lowercase to uppercase
            if(letter + key > 90) 
                {        
                printf("%c", EOB(letter, key)); 
                } 
                    else
                    {        
                    printf("%c", EIB(letter, key)); 
                    }
            } 

                       
            
            //Uppercase Block  
            else if (letter <91)
            {
            printf("%c", EIB(letter, key)); 
        }

                else 
                {        
                printf("%c", letter); //printf("%c", EOB(letter, key)); 
                } 
               
        
 } */
fclose(file_pointer); //closes the file
return(0);

}
//Function Definitions

char EIB(int letter, int key)
{
    char letterE;
    letterE = letter + key;
    return(letterE);
}

char EOB(int letter, int key)
{
    char letterE;
    letterE = letter + key - 26;
    return(letterE);
}

char DIB(int letter, int key)
{
    char letterD;
    letterD = letter - key;
}

char DOB(int letter, int key)
{
    char letterD;
    letterD = letter - 32;
}
