/*
 * CAN.h
 *
 * Created: 25.09.2019 13:03:02
 *  Author: sanderfu
 */ 


#ifndef CAN_controller_H_
#define CAN_controller_H_
uint8_t CAN_controller_init();
uint8_t CAN_controller_read(uint8_t addr);
void CAN_controller_write(uint8_t addr, uint8_t data);


#endif /* CAN_controller_H_ */