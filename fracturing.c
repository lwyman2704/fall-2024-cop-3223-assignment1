#include <math.h>
#include <stdio.h>
#define PI 3.14159 // makes PI a variable that can be passed and used with the functions


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

  void calculate_distance(){ //the void means this function is not outputting anything
    Coordinates* coords = getCoordinates();
    static double distance = 0.0; //a way to store value for distance without global; also so it aint negative
    distance = sqrt(pow(coords->x2 - coords->x1, 2) + pow(coords->y2 - coords->y1, 2)); //equation to calculate the distance of the points
      printf("\nThe distance between the two points is: %.3f\n", distance);
}

  double getDistance(){ //so this is gonna refer to the distance and then return that value so it can be used by the other functions
  Coordinates* coords = getCoordinates();
  return sqrt(pow(coords->x2 - coords->x1, 2) + pow(coords->y2 - coords->y1, 2));
}

  double calculate_perimeter(){  
    double distance = getDistance(); //this just uses the previously defined function for distance and brings the value
    double perimeter = 2 * PI * distance - 2; //equation for calculating perimeter of a circle
      printf("The perimeter of the city encompassed by your request is: %.3lf \n", perimeter);

}
  double calculate_area() {
    double distance = getDistance();
    double area = PI * pow(distance / 2, 2) + 1; // formula for calculating area; +3 is for difficulty level
      printf("The area of the city encompassed by your request is: %.3lf\n", area);
}

  double calculate_width() {
    Coordinates* coords = getCoordinates(); //get the coordinates from before
    double width = fabs(coords->x2 - coords->x1) + 2; //this fabs is so that it doesnt make the value negative ;) it computes abs val of floating numbs*
      printf("The width of the city encompassed by your request is: %.3f\n", width);
}

  double calculate_height() {
    Coordinates* coords = getCoordinates();
    double height = fabs(coords->y2 - coords->y1) + 3;
      printf("The height of the city encompassed by your request is: %.3f\n", height);
}

  int main() {    
    Coordinates* coords = getCoordinates(); //this is where you input the values for the typestruct earlier so that they can be used. they gotta go in main
      coords->x1 = 1;
      coords->x2 = 2;
      coords->y1 = 2;
      coords->y2 = 2;

// only to print once bcuz it started to print more than once
      printf("Point #1 entered: x1 = %d, x2 = %d\n", coords->x1, coords->x2); //they work similar like a regular thing when referencing a variable 
      printf("Point #2 entered: y1 = %d, y2 = %d \n", coords->y1, coords->y2);

      calculate_distance(); //these statements are here in the main function so that they can be called upon, and we done so in the order they are one after the other. basically the output of everything
        
      calculate_perimeter();
      calculate_area();
      calculate_width();
      calculate_height();
        
  return (0); 

}