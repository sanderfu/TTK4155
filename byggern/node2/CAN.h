/*
 * CAN.h
 *
 * Created: 04.10.2019 15:12:44
 *  Author: haavaei
 */ 


#ifndef CAN_H_
#define CAN_H_
#include <avr/io.h>

typedef struct {
	volatile uint8_t data[8];
	volatile uint16_t ID;
	volatile uint8_t data_length;

} CAN_message_t;

/**
 * @brief Send a CAN message
 *
 * @param[in] message pointer to CAN message to transmit
 */
void CAN_transmit_message(CAN_message_t * message);

/**
 * @brief Read message over CAN and do action according to ID
 */
void CAN_receiveMessage();

/**
 * @brief Initialize CAN module
 */
void CAN_init();


/**
 * @brief Set joystick, buttons and slider values from CAN message.
 *
 * @param[in] message with data representing joystick, buttons and slider values 
 */
void CAN_readPosition(CAN_message_t mess);

/**
 * @brief Clear CAN receive message interrupt
 */
void CAN_clearInterrupt();
#endif /* CAN_H_ */