/*
 * CAN.h
 *
 * Created: 25.09.2019 13:03:02
 *  Author: sanderfu
 */ 


#ifndef CAN_H_
#define CAN_H_
void CAN_init();
char CAN_read(uint8_t addr) ;
void CAN_write(uint8_t addr, uint8_t data);


#endif /* CAN_H_ */