#include <stdio.h>



    //  Tasks to complete rotational cipher. 5 to the right meaning that A = E 
    //  1. Make key
    //  2. Make encyption
    //  3. Make decyption 
    
    int main()
{

    FILE * file_pointer;                        //initalise a file for use
    file_pointer = fopen("input.txt", "r"); // opens the file
    if (file_pointer == NULL) {
        perror("Error:");
        return -1;
    }
    
//    printf("Enter Message : \n");       // Starting Input   
//    printf("Enter Rotation Key : \n");  // Starting Input For Key
    
    char letterE; // LetterE intialised for encypted letter
    int key;     // intialises key for future use
    char letter; // stores 'letter' as a char variable
    char buffer[1];
    
    // loop until the char left == 0 
    
    /*git test */
    while (fscanf(stream, "%s", buffer) == 1) // expect 1 successful conversion
    {
        
        fscanf(file_pointer, "%d %c", &key, &letter); // get the values from the input text file
        printf("Key is %d and letter is %c\n", key, letter); // print the intial key and letter from the file

    }
    if (feof(stream)) 
    {
    break;
    }
    
       
    if(letter > 90 )
    {
            
        letter = letter - 32; // turns the letter ASCII number from a lowercase to uppercase
        printf("%d\n", letter); // prints the new upper case letter
        letterE = letter + key; // inputs the key into the uppercase letter and stores it in encypted letterE
        printf("The ASCII Value is %d, and the letter is %c\n", letterE, letterE); //Prints the encypted letter as well as the encypted ASCII value
    
    }
    else 
    {
       
        printf("%d\n", letter); // prints the new upper case letter
        letterE = letter + key; // inputs the key into the uppercase letter and stores it in encypted letterE
        printf("The ASCII Value is %d, and the letter is %c\n", letterE, letterE); //Prints the encypted letter as well as the encypted ASCII value
    
    }   


fclose(file_pointer); //closes the file
return(0);
} 