/**
 * @file
 * @brief CAN interface
 */


#ifndef CAN_H_
#define CAN_H_

///////////////////////////////////////////////
// Includes
///////////////////////////////////////////////

#include <avr/io.h>

///////////////////////////////////////////////
// Structures
///////////////////////////////////////////////
typedef struct {
	volatile uint8_t data[8];
	volatile uint16_t ID;
	volatile uint8_t data_length;

} CAN_message_t;


///////////////////////////////////////////////
// Global variables
///////////////////////////////////////////////
CAN_message_t received_message;
uint8_t flag;

///////////////////////////////////////////////
// Function declarations
///////////////////////////////////////////////

/**
 * @brief Initialize CAN Interface
 * 
 */
void CAN_init();

/**
 * @brief Transmit CAN message
 * 
 * @param[in] message Can message to transmit
 */
void CAN_transmit_message(CAN_message_t * message);

/**
 * @brief Receive CAN message. Function is inplace.
 * 
 * @param[in] recieved_message Pointer to the global recieved_message variable
 */
void CAN_receiveMessage(CAN_message_t * received_message);


/**
 * @brief Send input data (joystick position, slider position and touch buttons) to Node 2
 * 
 */
void CAN_sendInputData();

/**
 * @brief Clear the CAN interrupt flag for received CAN message
 * 
 */
void CAN_clearInterrupt();
#endif /* CAN_H_ */