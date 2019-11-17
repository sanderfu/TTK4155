/**
 * @file
 * @brief XMEM Interface
 */

#ifndef XMEM_H_
#define XMEM_H_

///////////////////////////////////////////////
// Function declarations
///////////////////////////////////////////////

/**
 * @brief Initialize the xmem interface
 * 
 */
void xmem_init(void);

/**
 * @brief Write to external memory
 * 
 * @param[in] data Data to write
 * @param[in] addr Address to write to
 */
void xmemWrite(uint8_t data, uint16_t addr);

/**
 * @brief Read from external memory
 * 
 * @param[in] addr Address to write to
 * @param[out] data Data read from external memory
 */
uint8_t xmemRead(uint16_t addr);

#endif