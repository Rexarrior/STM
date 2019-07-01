#ifndef STM32L152_LCD
#define STM32L152_LCD
#include "stm32l1xx.h"                  // Device header
#include "stm32l1xx_hal.h"   

#define LCD_RAMRegister_0               ((uint32_t)0x00000000) /*!< LCD RAM Register 0  */
#define LCD_RAMRegister_1               ((uint32_t)0x00000001) /*!< LCD RAM Register 1  */
#define LCD_RAMRegister_2               ((uint32_t)0x00000002) /*!< LCD RAM Register 2  */
#define LCD_RAMRegister_3               ((uint32_t)0x00000003) /*!< LCD RAM Register 3  */
#define LCD_RAMRegister_4               ((uint32_t)0x00000004) /*!< LCD RAM Register 4  */
#define LCD_RAMRegister_5               ((uint32_t)0x00000005) /*!< LCD RAM Register 5  */
#define LCD_RAMRegister_6               ((uint32_t)0x00000006) /*!< LCD RAM Register 6  */
#define LCD_RAMRegister_7               ((uint32_t)0x00000007) /*!< LCD RAM Register 7  */
#define LCD_RAMRegister_8               ((uint32_t)0x00000008) /*!< LCD RAM Register 8  */
#define LCD_RAMRegister_9               ((uint32_t)0x00000009) /*!< LCD RAM Register 9  */
#define LCD_RAMRegister_10              ((uint32_t)0x0000000A) /*!< LCD RAM Register 10 */
#define LCD_RAMRegister_11              ((uint32_t)0x0000000B) /*!< LCD RAM Register 11 */
#define LCD_RAMRegister_12              ((uint32_t)0x0000000C) /*!< LCD RAM Register 12 */
#define LCD_RAMRegister_13              ((uint32_t)0x0000000D) /*!< LCD RAM Register 13 */
#define LCD_RAMRegister_14              ((uint32_t)0x0000000E) /*!< LCD RAM Register 14 */
#define LCD_RAMRegister_15              ((uint32_t)0x0000000F) /*!< LCD RAM Register 15 */
#define BOOL 														int
#define LCD_CHAR_COUNT									 6





void LCD_GLASS_WriteChar(uint8_t* ch, BOOL point, BOOL column, uint8_t position);
void LCD_GLASS_DisplayString(uint8_t* ptr);
void LCD_GLASS_InitController(void);
void LCD_GLASS_InitGpio(void);
void LCD_GLASS_DisplayWholeString(uint8_t* ptr, uint8_t len, uint8_t updateDelay);
void LCD_GLASS_Tiker(uint8_t* ptr, uint8_t len,  uint8_t updateDelay, uint8_t betweenMessageDelay, uint8_t times, BOOL callback());
#endif