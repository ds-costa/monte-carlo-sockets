/**
 * function: conv_points_2_string
 * Converts the quantity of points into a vector of char
 * @param points, Holds the quantity of points 
 * @param buffer, Vector that will receive the convertion  
 */
void conv_points_2_string(unsigned long points, char* buffer);

/**
 * function: conv_string_2_points
 * Returns the convertion of a vector of char into a quantity of points 
 * @param buffer, Vector char that contains the quatity of points
 */
unsigned long conv_string_2_points(char* buffer);

/**
 * function: conv_double_2_string
 * Converts the double number into a vector of char
 * @param buffer, Vector that will receive the convertion
 */
void conv_double_2_string(double number, char* buffer);

/**
 * function: conv_string_2_double
 * Returns the convertion of a vector of char into double
 * @param buffer, Vector char that contains the double number
 */
double conv_string_2_double(char* buffer);