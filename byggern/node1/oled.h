/**
 * @file
 * @brief OLED interface
 */

#ifndef OLED_H_
#define OLED_H_
///////////////////////////////////////////////
// Includes
///////////////////////////////////////////////
#include <avr/io.h>

/**
 * @brief Initialize the oled interface
 * 
 */
void oled_init(void);

/**
 * @brief Print left facing arrow on oled
 * 
 */
void oled_print_arrow();

/**
 * @brief Clear the oled screen
 * 
 */
void oled_reset();

/**
 * @brief Go to position (0,0) on the Ooled screen
 * 
 */
void oled_home();

/**
 * @brief Go to a specified page (line) of the oled screen
 * 
 * @param[in] page The page to go to
 */
void oled_gotoLine(uint8_t page);

/**
 * @brief Go to a specified column of the oled screen
 * 
 * @param[in] column The column to go to
 */
void oled_gotoColumn(uint8_t column);

/**
 * @brief Clear a specified page (line)
 * 
 * @param[in] page The page to clear
 */
void oled_clearLine(uint8_t page);

/**
 * @brief Print char array to oled screen
 * 
 * @param[in] character The char array to write to screen
 */
void oled_print(char* character);

#endif