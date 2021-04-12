#include <iostream>
#include <math.h>
using namespace std;
 
//All Function declaration
double getDiameter(double radius);
double getCircumference(double radius);
double getArea(double radius);
 
 
int main()
{
    float radius, diameter, circle, area;
 
    // Inputting radius of circle from user
    cout<<"Enter radius of circle: ";
    cin>>radius;
 
    diameter  = getDiameter(radius);       // Calling getDiameter function
    circle = getCircumference(radius);  // Calling getCircumference function
    area = getArea(radius);           // Calling getArea function
 
    cout<<"Diameter of the circle: "<<diameter <<" units"<<endl;
    cout<<"Circumference of the circle: "<< circle<<" units"<<endl;
    cout<<"Area of the circle:"<< area<<" sq. units"<<endl;
 
    return 0;
}
 
// Calculating diameter of circle whose radius is given
 
double getDiameter(double radius)
{
    return (2 * radius);
}
 
 
//Calculating circumference of circle whose radius is given
 
double getCircumference(double radius)
{
    return (2 * M_PI * radius); // PI = 3.14
}
 
//Finding area of circle whose radius is given
 
double getArea(double radius)
{
    return (M_PI * radius * radius); // PI = 3.14
}