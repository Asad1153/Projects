/* PLEASE DO NOT MODIFY A SINGLE STATEMENT IN THE TEXT BELOW.
READ THE FOLLOWING CAREFULLY AND FILL IN THE GAPS

I hereby declare that all the work that was required to 
solve the following problem including designing the algorithms
and writing the code below, is solely my own and that I received
no help in creating this solution and I have not discussed my solution 
with anybody. I affirm that I have read and understood
the Senate Policy on Academic honesty at 
https://secretariat-policies.info.yorku.ca/policies/academic-honesty-senate-policy-on/
and I am well aware of the seriousness of the matter and the penalties that I will face as a 
result of committing plagiarism in this assignment.

BY FILLING THE GAPS,YOU ARE SIGNING THE ABOVE STATEMENTS.

Full Name: AsadUllah Usmani
Student Number: 217010372
Course Section: O
eecs user id: asad1153
*/

#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#define IMAGE_SIZE 10

#define LARGEST 100000
int forward = 0;
int number = 0;  
int backward = -1;
int firstarr[LARGEST];

//Below is a function called "everything" to see if the order is empty or not empty

bool everything() {
return number == LARGEST;
}

//Below is a function called "putIn" which puts information in the proper order

void putIn(int information) {
    if(!everything()) {
        if(backward == LARGEST-1) {
        backward = -1;
   }   
        firstarr[++backward] = information;
        number++;
    }
}
//Below is a function called "nothing" which also checks to see if the order is empty or not

bool nothing() {
return number == 0;
}
//Below is a function called "weight" which measures the size of the order

int weight() {
return number;
}

//Below is a function called "element" which gets the element of the program which is at the forefront from the order

int element() {
int information = firstarr[forward++];
  
if(forward == LARGEST) {
forward = 0;
}
  
number--;
return information;
}
//This method below basically verifies that the cells in the pictures are accurate 
int correct(int a,int b){
   if(a>=0&&a<IMAGE_SIZE&&b>=0&&b<IMAGE_SIZE)
   return 1;
   else
   return 0;
}

// this function prints the array
void printImgArray(int array[IMAGE_SIZE][IMAGE_SIZE])
{
  
    printf("------ Image Contents -------\n");
    int i, j;
	for (i=0; i<IMAGE_SIZE; i++)
    {
    for (j=0; j<IMAGE_SIZE; j++)
        printf("%02d, ",array[i][j]);
    printf("\n");
    }
    printf("-----------------------------\n");
}
//What this method below does is that it stores the index in the proper order, and with the while loop it repeats the order until it is empty
//Inside the while loop the front element is taken from the order and the calculations involve the size of the image to recieve the row and column number
//Finally the repitition involves the cells that are beside each other and it will be placed in based on the validity of the cell and if it contains the number "1"
void arr_new(int j,int k,int picture[IMAGE_SIZE][IMAGE_SIZE],int number){
   putIn((j)*IMAGE_SIZE+(k));
   int importance;
   int a,b; 
   while(weight()>0){
       importance=element(); 
        a=importance/IMAGE_SIZE;
        b=importance%IMAGE_SIZE;
        int first_array[]={-1,-1,1,1,0,0,1,-1};
       int second_array[]={-1,1,1,-1,-1,1,0,0};
       picture[a][b]=number;
       for(j=0;j<7;j++){
           if(correct(a+first_array[j],b+second_array[j])&&picture[a+first_array[j]][b+second_array[j]]==1)
           putIn((a+first_array[j])*IMAGE_SIZE+(b+second_array[j]));
       }
   }
  
}

/**
 * This function counts the number of distinct 
 * number (i.e. the number of cells)
 *
 * feel free to add auxiliary data structures and helper functions
 **/

int cellCount(int image[IMAGE_SIZE][IMAGE_SIZE]){
    // insert your code for task1.2 here
    // you may want to change the return value.

    //The array below is to locate the element
    //the if-statement depends on the cell in the image being 0 or 1; If it's 0, that means that the cells haven't moved so the count is increased by 1
   int number;
   int j,k;
   int list[100001 + 1]; 
   number=0;
   for(j=0;j<IMAGE_SIZE;j++){
       for(k=0;k<IMAGE_SIZE;k++){  
           if(image[j][k]!=0 && list[image[j][k]]==0){
               number++;
               list[image[j][k]]=1; 
           }
       }
   }
   return number;
}
/**
 * This function colors each blood cell with a unique color
 * (i.e. unique number)
 * Hint: scan the array element by element, and explore each element as much as possible, 
 * when come to an already labelled one, relabell the array to form larger cell
 * 
 * feel free to add auxiliary data structures and helper functions
 **/
void color(int image[IMAGE_SIZE][IMAGE_SIZE]){
    // insert your code for task 1.1 here

    //This method here is similar to void cellcount
    //arr_new is a function for this program which updates the array
    int number;
    number =2;
    int j,k;
    for(j=0;j<IMAGE_SIZE;j++){
       for(k=0;k<IMAGE_SIZE;k++){
            if(image[j][k]==1){  
              arr_new(j,k,image,number); 
              number++;
            }
         }
    }
}

/********************************************************************************/
//the function and all the helper functions (if any) should use pointer notation, 
// instead of array index notation []. It is okey to use [] only when declaring extra arrays
void colorPtr(int* image){
    // insert your code for task 2.1 here

}

//the function and all the helper functions (if any) should use pointer notation, 
// instead of array index notation []. It is okey to use [] only when declaring extra arrays
int cellCountPtr(int* image){
    // insert your code for task 2.2 here
   return 0;
}

/********************************************************************************/

/**
 * This function colors each cell with a unique color
 * (i.e., unique number).
 **/

int colorRecursively(int image[IMAGE_SIZE][IMAGE_SIZE]) {
    
    return 0;
 
}


#ifndef __testing
int main(){

    // DO not change anything in main(), it will confuse the
    // auto-checker.  
    puts("testing the code with color() function");
    int count = 0;
    int cellImg[IMAGE_SIZE][IMAGE_SIZE]={{0,0,1,1,0,0,1,0,0,1},\
		               {1,0,1,1,0,0,1,1,0,1},\
		               {1,0,0,1,1,0,1,1,0,1},\
		               {1,1,0,0,0,0,0,0,0,0},\
		               {1,0,0,1,1,1,0,0,1,0},\
		               {0,0,0,0,1,0,0,1,1,0},\
		               {0,0,1,0,0,1,0,1,0,0},\
		               {0,0,1,1,0,0,1,0,0,0},\
		               {0,0,1,0,0,0,0,0,1,1},
		               {0,1,1,0,0,0,1,1,1,1}};

    printImgArray(cellImg);
    color(cellImg);
    printImgArray(cellImg);
    count=cellCount(cellImg);
    printf("Total number of cells in the image: %d\n",count);
 

    puts("Testing the code with colorPtr");
    int cellImg_[IMAGE_SIZE][IMAGE_SIZE]={{0,0,1,1,0,0,1,0,0,1},\
		               {1,0,1,1,0,0,1,1,0,1},\
		               {1,0,0,1,1,0,1,1,0,1},\
		               {1,1,0,0,0,0,0,0,0,0},\
		               {1,0,0,1,1,1,0,0,1,0},\
		               {0,0,0,0,1,0,0,1,1,0},\
		               {0,0,1,0,0,1,0,1,0,0},\
		               {0,0,1,1,0,0,1,0,0,0},\
		               {0,0,1,0,0,0,0,0,1,1},
		               {0,1,1,0,0,0,1,1,1,1}};

    int* ptr = cellImg_;

    printImgArray(ptr);
    colorPtr(ptr);
    printImgArray(ptr);
    count=cellCountPtr(ptr);
    printf("Total number of cells in the image: %d\n",count); 
    
	puts("Testing the code with colorRecursively");
    int cellImg__[IMAGE_SIZE][IMAGE_SIZE]={{0,0,1,1,0,0,1,0,0,1},\
		               {1,0,1,1,0,0,1,1,0,1},\
		               {1,0,0,1,1,0,1,1,0,1},\
		               {1,1,0,0,0,0,0,0,0,0},\
		               {1,0,0,1,1,1,0,0,1,0},\
		               {0,0,0,0,1,0,0,1,1,0},\
		               {0,0,1,0,0,1,0,1,0,0},\
		               {0,0,1,1,0,0,1,0,0,0},\
		               {0,0,1,0,0,0,0,0,1,1},
		               {0,1,1,0,0,0,1,1,1,1}};
    printImgArray(cellImg__);
    colorRecursively(cellImg__);
    printImgArray(cellImg__);
    count=cellCount(cellImg__);
    printf("Total number of cells in the image: %d\n",count);
    return 0;
}
#endif
