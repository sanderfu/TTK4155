/**
 * @file
 * @brief CAN Controller Interface
 */

#ifndef CAN_controller_H_
#define CAN_controller_H_

///////////////////////////////////////////////
// Includes
///////////////////////////////////////////////
#include <avr/io.h>

///////////////////////////////////////////////
// Function declarations
///////////////////////////////////////////////

/**
 * @brief Initialize CAN Controller Interface
 * 
 */
void CAN_controller_init();

/**
 * @brief Read from CAN Controller
 * 
 * @param[in] addr Address to read from
 */
uint8_t CAN_controller_read(uint8_t addr);

/**
 * @brief Write to CAN Controller
 * 
 * @param[in] addr Address to write to
 * @param[in] addr Address to write to
 */
void CAN_controller_write(uint8_t addr, uint8_t data);

/**
 * @brief Request to send, function to be called after loading transmission buffer.
 * 
 * @param[in] buffer Buffer to send
 */
void CAN_controller_RTS(uint8_t buffer);

/**
 * @brief Change mode of CAN_controller.
 * 
 * @param[in] mode Mode to set controller in
 */
void CAN_controller_setMode(uint8_t mode);

/**
 * @brief Modify chosen bits on transceiver register.
 * 
 * @param[in] mask Mask to use
 * @param[in] addr Address to use
 * @param[in] data Data to use
 */
void CAN_controller_bitModify(uint8_t mask, uint8_t addr, uint8_t data);
#endif /* CAN_controller_H_ */