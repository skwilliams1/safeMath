# safeMath

This project shows operations with the C safe-math library. These operations include:
 
  - psnip_safe_bool psnip_safe_char_mul (char* res, char a, char b)
  - psnip_safe_bool psnip_safe_int_mul (int* res, int a, int b)
  - psnip_safe_bool psnip_safe_long_mul (long* res, long a, long b)

The program 
  - takes two input strings A and B, and converts them to longs. If the conversion fails the values are set to 0.
  - multiplies A and B using the smallest single type T, and outputs the result.The eligible types T are char, int, and long, where char is “smaller” than int and int is “smaller” than long.
    
It will return that the A and B could successfully be multiplied as T or that they cannot be multiplied. 
  
