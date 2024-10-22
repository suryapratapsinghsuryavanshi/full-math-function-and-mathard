#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function prototypes
void display_help();
double calculate_area(double radius);
double calculate_circumference(double radius);
double calculate_diameter(double radius);

int main(int argc, char *argv[]) {
    // Check if no arguments were passed
    if (argc < 2) {
        printf("No options provided. Use --help for usage information.\n");
        return 1;
    }

    // Parse command-line arguments
    double radius = -1;
    int show_help = 0;
    
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--help") == 0) {
            show_help = 1;
        } else if (strcmp(argv[i], "--radius") == 0 && i + 1 < argc) {
            radius = atof(argv[++i]);
        }
    }

    if (show_help) {
        display_help();
        return 0;
    }

    if (radius <= 0) {
        printf("Invalid or missing radius. Use --help for usage information.\n");
        return 1;
    }

    // Perform calculations
    double area = calculate_area(radius);
    double circumference = calculate_circumference(radius);
    double diameter = calculate_diameter(radius);

    // Output the results
    printf("Circle properties for radius: %.2f\n", radius);
    printf("Area: %.2f\n", area);
    printf("Circumference: %.2f\n", circumference);
    printf("Diameter: %.2f\n", diameter);

    return 0;
}

// Function to display help message
void display_help() {
    printf("Usage: circle_calc [OPTIONS]\n");
    printf("This program calculates circle-related properties such as area, circumference, and diameter.\n");
    printf("Options:\n");
    printf("  --radius <value>     Provide the radius of the circle (positive number required).\n");
    printf("  --help               Display this help message.\n");
    printf("\nExamples:\n");
    printf("  circle_calc --radius 5\n");
    printf("  circle_calc --help\n");
}

// Function to calculate the area of a circle
double calculate_area(double radius) {
    return PI * radius * radius;
}

// Function to calculate the circumference of a circle
double calculate_circumference(double radius) {
    return 2 * PI * radius;
}

// Function to calculate the diameter of a circle
double calculate_diameter(double radius) {
    return 2 * radius;
}
