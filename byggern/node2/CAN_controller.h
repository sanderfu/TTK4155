/*
 * CAN.h
 *
 * Created: 25.09.2019 13:03:02
 *  Author: sanderfu
 */ 

#include <avr/io.h>
#include <stdlib.h>
#ifndef CAN_controller_H_
#define CAN_controller_H_

/**
 * @brief Initialize CAN controller
 */
void CAN_controller_init();

/**
 * @brief Read value from register on CAN transceiver
 *
 * @param[in] addr address on CAN transceiver to read from
 */
uint8_t CAN_controller_read(uint8_t addr);

/**
 * @brief Write to address on CAN transceiver
 *
 * @param[in] addr Address on CAN transceiver to write to
 * @param[in] data Data to write 
 */
void CAN_controller_write(uint8_t addr, uint8_t data);

//Request to send in chosen buffer
/**
 * @brief Set joystick, buttons and slider values from CAN message.
 *
 * @param[in] message with data representing joystick, buttons and slider values 
 */
void CAN_controller_RTS(uint8_t buffer);

/**
 * @brief Set joystick, buttons and slider values from CAN message.
 *
 * @param[in] message with data representing joystick, buttons and slider values 
 */
void CAN_controller_setMode(uint8_t mode);

//Modify certain bits in Can Transceiver register
/**
 * @brief Set joystick, buttons and slider values from CAN message.
 *
 * @param[in] message with data representing joystick, buttons and slider values 
 */
void CAN_controller_bitModify(uint8_t mask, uint8_t addr, uint8_t data);
#endif /* CAN_controller_H_ */