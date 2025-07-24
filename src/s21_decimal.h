/*

                _             __ _ 
 _ __  __ _ _ _(_)__ _ _ __  / _(_)
| '  \/ _` | '_| / _` | '  \|  _| |
|_|_|_\__,_|_| |_\__,_|_|_|_|_| |_|
                                   
                       arts by me :)

                   

*/
/*
    _  _____ ____  _  _    ___  _ _      _     
   / |/  __//  __\/ \/ \   \  \/// \  /|/ \__/|
   | ||  \  |  \/|| || |    \  / | |\ ||| |\/||
/\_| ||  /_ |    /| || |_/\ / /  | | \||| |  ||
\____/\____\\_/\_\\_/\____//_/   \_/  \|\_/  \|
                                               
                        

*/


#ifndef _S21_DECIMAL_
#define _S21_DECIMAL_

typedef struct{
    int bits[4];
} s21_decimal;

/*
             █████     ███  ████         
            ░░███     ░░░  ░░███         
 █████ ████ ███████   ████  ░███   █████ 
░░███ ░███ ░░░███░   ░░███  ░███  ███░░  
 ░███ ░███   ░███     ░███  ░███ ░░█████ 
 ░███ ░███   ░███ ███ ░███  ░███  ░░░░███
 ░░████████  ░░█████  █████ █████ ██████ 
  ░░░░░░░░    ░░░░░  ░░░░░ ░░░░░ ░░░░░
 */

int set_bit(s21_decimal * number, int i, int j);
int set_sign(s21_decimal * number);
int unset_sign(s21_decimal * number);
int set_exponent(s21_decimal *number, int exponent);
void remove_char(const char *src, char *dest, char to_remove);
int divide_by_10(s21_decimal *d);
int multiply_by_10(s21_decimal *d);
int get_exponent(s21_decimal number);
int get_sign(s21_decimal number);
int is_zero(s21_decimal number);
int make_same_exponent(s21_decimal *a, s21_decimal *b);
int copy_decimal(s21_decimal src, s21_decimal *dst);
int get_frac(s21_decimal value, s21_decimal *result);
int s21_ceil(s21_decimal value, s21_decimal *result);
int add_abs(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int sub_abs(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int shift_left(s21_decimal *d);
int get_bit(s21_decimal d, int index);
void integer_division(s21_decimal dividend, s21_decimal divisor, s21_decimal *quotient, s21_decimal *remainder);

/*

           █████    █████                                
          ░░███    ░░███                                 
  ██████  ███████   ░███████    ██████  ████████   █████ 
 ███░░███░░░███░    ░███░░███  ███░░███░░███░░███ ███░░  
░███ ░███  ░███     ░███ ░███ ░███████  ░███ ░░░ ░░█████ 
░███ ░███  ░███ ███ ░███ ░███ ░███░░░   ░███      ░░░░███
░░██████   ░░█████  ████ █████░░██████  █████     ██████ 
 ░░░░░░     ░░░░░  ░░░░ ░░░░░  ░░░░░░  ░░░░░     ░░░░░░  
                                                         
                                                         
                                                         
                          
*/
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

/*
                                                              █████                              
                                                             ░░███                               
  ██████   ██████  ████████   █████ █████  ██████  ████████  ███████    ██████  ████████   █████ 
 ███░░███ ███░░███░░███░░███ ░░███ ░░███  ███░░███░░███░░███░░░███░    ███░░███░░███░░███ ███░░  
░███ ░░░ ░███ ░███ ░███ ░███  ░███  ░███ ░███████  ░███ ░░░   ░███    ░███ ░███ ░███ ░░░ ░░█████ 
░███  ███░███ ░███ ░███ ░███  ░░███ ███  ░███░░░   ░███       ░███ ███░███ ░███ ░███      ░░░░███
░░██████ ░░██████  ████ █████  ░░█████   ░░██████  █████      ░░█████ ░░██████  █████     ██████ 
 ░░░░░░   ░░░░░░  ░░░░ ░░░░░    ░░░░░     ░░░░░░  ░░░░░        ░░░░░   ░░░░░░  ░░░░░     ░░░░░░  
                                                                                                 
                                                                                                 
                                                                                                 


*/
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float* dst);

/*

                                                                  ███                             
                                                                 ░░░                              
  ██████   ██████  █████████████   ████████   ██████   ████████  ████   █████   ██████  ████████  
 ███░░███ ███░░███░░███░░███░░███ ░░███░░███ ░░░░░███ ░░███░░███░░███  ███░░   ███░░███░░███░░███ 
░███ ░░░ ░███ ░███ ░███ ░███ ░███  ░███ ░███  ███████  ░███ ░░░  ░███ ░░█████ ░███ ░███ ░███ ░███ 
░███  ███░███ ░███ ░███ ░███ ░███  ░███ ░███ ███░░███  ░███      ░███  ░░░░███░███ ░███ ░███ ░███ 
░░██████ ░░██████  █████░███ █████ ░███████ ░░████████ █████     █████ ██████ ░░██████  ████ █████
 ░░░░░░   ░░░░░░  ░░░░░ ░░░ ░░░░░  ░███░░░   ░░░░░░░░ ░░░░░     ░░░░░ ░░░░░░   ░░░░░░  ░░░░ ░░░░░ 
                                   ░███                                                           
                                   █████                                                          
                                  ░░░░░                                                           

*/
int s21_is_equal(s21_decimal a, s21_decimal b);
int s21_is_less(s21_decimal a, s21_decimal b);
int s21_is_greater(s21_decimal a, s21_decimal b);
int s21_is_greater_or_equal(s21_decimal a, s21_decimal b);
int s21_is_less_or_equal(s21_decimal a, s21_decimal b);
int s21_is_not_equal(s21_decimal, s21_decimal);

/*
                      ███   █████    █████                                █████     ███          
                     ░░░   ░░███    ░░███                                ░░███     ░░░           
  ██████   ████████  ████  ███████   ░███████   █████████████    ██████  ███████   ████   ██████ 
 ░░░░░███ ░░███░░███░░███ ░░░███░    ░███░░███ ░░███░░███░░███  ███░░███░░░███░   ░░███  ███░░███
  ███████  ░███ ░░░  ░███   ░███     ░███ ░███  ░███ ░███ ░███ ░███████   ░███     ░███ ░███ ░░░ 
 ███░░███  ░███      ░███   ░███ ███ ░███ ░███  ░███ ░███ ░███ ░███░░░    ░███ ███ ░███ ░███  ███
░░████████ █████     █████  ░░█████  ████ █████ █████░███ █████░░██████   ░░█████  █████░░██████ 
 ░░░░░░░░ ░░░░░     ░░░░░    ░░░░░  ░░░░ ░░░░░ ░░░░░ ░░░ ░░░░░  ░░░░░░     ░░░░░  ░░░░░  ░░░░░░  
                                                                                                 
                                                                                                 
                                                                                                 


*/
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);


#endif


