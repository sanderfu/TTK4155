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

/**
 * @brief Request to send to chosen buffer
 *
 * @param[in] buffer one of three possible transmit buffers: 0, 1, 2
 */
void CAN_controller_RTS(uint8_t buffer);

/**
 * @brief Set CAN transceiver in wanted mode.
 *
 * @param[in] mode CAN transceiver mode
 */
void CAN_controller_setMode(uint8_t mode);


/**
 * @brief Modify certain bits in Can Transceiver register
 *
 * @param[in] mask, bitmask to modify
 * @param[in] addr, register to modify
 * @param[in] data, data to set
 */
void CAN_controller_bitModify(uint8_t mask, uint8_t addr, uint8_t data);
#endif /* CAN_controller_H_ */