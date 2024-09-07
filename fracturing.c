#include <math.h>
#include <stdio.h>

#define PI 3.14159 // makes PI a variable that can be passed and used with the functions; just defines PI basically

typedef struct { //this is for making the variables for the points without making them global 
  int x1;
  int x2;
  int y1;
  int y2;
} Coordinates;
    
  Coordinates* getCoordinates() { //this piece connects with the last and makes the coordinates static and not global
    static Coordinates coords;  //later, the functions will be able to calculate using the recalled points without having value changed
    return &coords;
}

  void calculateDistance(){   //the void means this function is not outputting anything, just being called on by other functions to get coordinates and distance
    Coordinates*coords = getCoordinates();
    static double distance = 0.0;    //a way to store value for distance without global; also so it stops turning my output values negative
    distance = sqrt(pow(coords->x2 - coords->x1, 2) + pow(coords->y2 - coords->y1, 2));    // equation to calculate the distance of the points using pointers bcuz of no global variables
      printf("\nThe distance between the two points is: %.3f\n", distance);
}

  double getDistance(){ //so this is gonna refer to the distance and then return that value so it can be used by the other functions
  Coordinates* coords = getCoordinates();
  return sqrt(pow(coords->x2 - coords->x1, 2) + pow(coords->y2 - coords->y1, 2));
}

  double calculatePerimeter(){  
    double distance = getDistance(); //this just uses the previously defined function for distance and brings the value
    double perimeter = 2 * PI * distance; //equation for calculating perimeter of a circle w/ offset for func. difficulty
      printf("The perimeter of the city encompassed by your request is: %.3lf \n", perimeter);

}
  double calculateArea() {
    double distance = getDistance();
    double area = PI * pow(distance / 2, 2); // formula for calculating area; +2 is for difficulty level req. in pdf instructions
      printf("The area of the city encompassed by your request is: %.3lf\n", area);
}

  double calculateWidth() {
    Coordinates* coords = getCoordinates();  //gets the coordinates from before
    double width = fabs(coords->x2 - coords->x1);  //this fabs is so that it doesnt make the value negative ;) it computes abs val of floating numbs*
      printf("The width of the city encompassed by your request is: %.3f\n", width); // w/ offset for func. difficulty
}

  double calculateHeight() {
    Coordinates* coords = getCoordinates();
    double height = fabs(coords->y2 - coords->y1); // offset for func. difficulty
      printf("The height of the city encompassed by your request is: %.3f\n", height);
}

  int main() {    
    Coordinates* coords = getCoordinates(); //this is where you input the values for the typestruct earlier so that they can be used. they gotta go in main
      printf("Please enter the 'x' values of the coordinates: ");
      scanf("%d" "%d", &coords->x1, &coords->x2); // if i put a "," the program expects a second arg w/ char which is nowhere, so user needs to press space or enter when typing values so they will be seperate.
      printf("Please enter the 'y' values of the coordinates: ");
      scanf("%d" "%d", &coords->y1, &coords->y2);
      
// only here to print once bcuz it started to print more than once when code was running.
//they work similar like a regular thing when referencing a variable normally

      printf("\nPoint #1 entered: x1 = %d, y1 = %d\n", coords->x1, coords->y1); 
      printf("Point #2 entered: x2 = %d, y2 = %d \n", coords->x2, coords->y2);

//these statements are here in the main function so that they can be called upon, and done so in the order they are one after the other. basically the output of everything

      calculateDistance();   
      calculatePerimeter();
      calculateArea();
      calculateWidth();
      calculateHeight();
        
  return (0); 

}