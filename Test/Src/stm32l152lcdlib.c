#include "stm32l152lcdlib.h"

/* code for '?' character */
#define C_UMAP 0x6084

/* code for 'm' character */
#define C_mMap 0xb210

/* code for 'n' character */
#define C_nMap 0x2210


/* constant code for '*' character */
#define star 0xA0DD

/* constant code for '-' character */
#define C_minus 0xA000

/* constant code for '/' */
#define C_slatch  0x00c0

/* constant code for ? */
#define C_percent_1 0xec00

/* constant code  for small o */
#define C_percent_2 0xb300

#define C_full 0xffdd

/* Constant table for cap characters 'A' --> 'Z' */
const uint16_t CapLetterMap[26]=
{
	/* A      B      C      D      E      F      G      H      I  */
	0xFE00,0x6714,0x1d00,0x4714,0x9d00,0x9c00,0x3f00,0xfa00,0x0014,
	/* J      K      L      M      N      O      P      Q      R  */
	0x5300,0x9841,0x1900,0x5a48,0x5a09,0x5f00,0xFC00,0x5F01,0xFC01,
	/* S      T      U      V      W      X      Y      Z  */
	0xAF00,0x0414,0x5b00,0x18c0,0x5a81,0x00c9,0x0058,0x05c0
};

/* Constant table for number '0' --> '9' */
const uint16_t NumberMap[10]=
{
	/* 0      1      2      3      4      5      6      7      8      9  */
	0x5F00,0x4200,0xF500,0x6700,0xEa00,0xAF00,0xBF00,0x04600,0xFF00,0xEF00
};



static void LCD_Conv_Char_Seg(uint8_t* c, BOOL point, BOOL column,uint8_t* digit);
static void LCD_GLASS_WriteChar(uint8_t* ch, BOOL point, BOOL column, uint8_t position);

/**
* @brief  Converts an ascii char to the a LCD digit.
* @param  c: a char to display.
* @param  point: a point to add in front of char
*         This parameter can be: POINT_OFF or POINT_ON
* @param  column : flag indicating if a column has to be add in front
*         of displayed character.
*         This parameter can be: COLUMN_OFF or COLUMN_ON.
* @param 	digit array with segment 
* @retval None
*/
static void LCD_Conv_Char_Seg(uint8_t* c, BOOL point, BOOL column, uint8_t* digit)
{
	uint16_t ch = 0 ;
	uint8_t i,j;

	switch (*c)
	{
	case ' ' : 
		ch = 0x00;
		break;

	case '*':
		ch = star;
		break;

	case '?' :
		ch = C_UMAP;
		break;

	case 'm' :
		ch = C_mMap;
		break;

	case 'n' :
		ch = C_nMap;
		break;					

	case '-' :
		ch = C_minus;
		break;

	case '/' :
		ch = C_slatch;
		break;  

	//case '?' :
	//	ch = C_percent_1;
	//	break;  
	case '%' :
		ch = C_percent_2; 
		break;
	case 255 :
		ch = C_full;
		break ;

	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':			
		ch = NumberMap[*c-0x30];		
		break;

	default:
		/* The character c is one letter in upper case*/
		if ( (*c < 0x5b) && (*c > 0x40) )
		{
			ch = CapLetterMap[*c-'A'];
		}
		/* The character c is one letter in lower case*/
		if ( (*c <0x7b) && ( *c> 0x60) )
		{
			ch = CapLetterMap[*c-'a'];
		}
		break;
	}

	/* Set the digital point can be displayed if the point is on */
	if (point)
	{
		ch |= 0x0002;
	}

	/* Set the "COL" segment in the character that can be displayed if the column is on */
	if (column)
	{
		ch |= 0x0020;
	}		

	for (i = 12,j=0 ;j<4; i-=4,j++)
	{
		digit[j] = (ch >> i) & 0x0f; //To isolate the less signifiant dibit
	}
}

static void LCD_GLASS_WriteChar(uint8_t* ch, int point, int column, uint8_t position)
{
	uint8_t digit[4];     /* Digit frame buffer */

	/* To convert displayed character in segment in array digit */
	LCD_Conv_Char_Seg(ch,point,column,digit);


	switch (position)
	{
		/* Position 1 on LCD (Digit1)*/
	case 1:
		LCD->RAM[LCD_RAMRegister_0] &= 0xcffffffc;
		LCD->RAM[LCD_RAMRegister_2] &= 0xcffffffc;
		LCD->RAM[LCD_RAMRegister_4] &= 0xcffffffc;
		LCD->RAM[LCD_RAMRegister_6] &= 0xcffffffc;

		LCD->RAM[LCD_RAMRegister_0] |= ((digit[0]& 0x0c) << 26 ) | (digit[0]& 0x03) ; // 1G 1B 1M 1E	    
		LCD->RAM[LCD_RAMRegister_2] |= ((digit[1]& 0x0c) << 26 ) | (digit[1]& 0x03) ; // 1F 1A 1C 1D 
		LCD->RAM[LCD_RAMRegister_4] |= ((digit[2]& 0x0c) << 26 ) | (digit[2]& 0x03) ; // 1Q 1K 1Col 1P                                                                                                                                    
		LCD->RAM[LCD_RAMRegister_6] |= ((digit[3]& 0x0c) << 26 ) | (digit[3]& 0x03) ; // 1H 1J 1DP 1N

		break;

		/* Position 2 on LCD (Digit2)*/
	case 2:
		LCD->RAM[LCD_RAMRegister_0] &= 0xf3ffff03;
		LCD->RAM[LCD_RAMRegister_2] &= 0xf3ffff03;      
		LCD->RAM[LCD_RAMRegister_4] &= 0xf3ffff03;
		LCD->RAM[LCD_RAMRegister_6] &= 0xf3ffff03;

		LCD->RAM[LCD_RAMRegister_0] |= ((digit[0]& 0x0c) << 24 )|((digit[0]& 0x02) << 6 )|((digit[0]& 0x01) << 2 ) ; // 2G 2B 2M 2E	  
		LCD->RAM[LCD_RAMRegister_2] |= ((digit[1]& 0x0c) << 24 )|((digit[1]& 0x02) << 6 )|((digit[1]& 0x01) << 2 ) ; // 2F 2A 2C 2D
		LCD->RAM[LCD_RAMRegister_4] |= ((digit[2]& 0x0c) << 24 )|((digit[2]& 0x02) << 6 )|((digit[2]& 0x01) << 2 ) ; // 2Q 2K 2Col 2P
		LCD->RAM[LCD_RAMRegister_6] |= ((digit[3]& 0x0c) << 24 )|((digit[3]& 0x02) << 6 )|((digit[3]& 0x01) << 2 ) ; // 2H 2J 2DP 2N

		break;

		/* Position 3 on LCD (Digit3)*/
	case 3:
		LCD->RAM[LCD_RAMRegister_0] &= 0xfcfffcff;
		LCD->RAM[LCD_RAMRegister_2] &= 0xfcfffcff;
		LCD->RAM[LCD_RAMRegister_4] &= 0xfcfffcff;
		LCD->RAM[LCD_RAMRegister_6] &= 0xfcfffcff;

		LCD->RAM[LCD_RAMRegister_0] |= ((digit[0]& 0x0c) << 22 ) | ((digit[0]& 0x03) << 8 ) ; // 3G 3B 3M 3E	
		LCD->RAM[LCD_RAMRegister_2] |= ((digit[1]& 0x0c) << 22 ) | ((digit[1]& 0x03) << 8 ) ; // 3F 3A 3C 3D
		LCD->RAM[LCD_RAMRegister_4] |= ((digit[2]& 0x0c) << 22 ) | ((digit[2]& 0x03) << 8 ) ; // 3Q 3K 3Col 3P
		LCD->RAM[LCD_RAMRegister_6] |= ((digit[3]& 0x0c) << 22 ) | ((digit[3]& 0x03) << 8 ) ; // 3H 3J 3DP 3N

		break;

		/* Position 4 on LCD (Digit4)*/
	case 4:
		LCD->RAM[LCD_RAMRegister_0] &= 0xffcff3ff;
		LCD->RAM[LCD_RAMRegister_2] &= 0xffcff3ff;
		LCD->RAM[LCD_RAMRegister_4] &= 0xffcff3ff;
		LCD->RAM[LCD_RAMRegister_6] &= 0xffcff3ff;

		LCD->RAM[LCD_RAMRegister_0] |= ((digit[0]& 0x0c) << 18 ) | ((digit[0]& 0x03) << 10 ) ; // 4G 4B 4M 4E	
		LCD->RAM[LCD_RAMRegister_2] |= ((digit[1]& 0x0c) << 18 ) | ((digit[1]& 0x03) << 10 ) ; // 4F 4A 4C 4D
		LCD->RAM[LCD_RAMRegister_4] |= ((digit[2]& 0x0c) << 18 ) | ((digit[2]& 0x03) << 10 ) ; // 4Q 4K 4Col 4P
		LCD->RAM[LCD_RAMRegister_6] |= ((digit[3]& 0x0c) << 18 ) | ((digit[3]& 0x03) << 10 ) ; // 4H 4J 4DP 4N

		break;

		/* Position 5 on LCD (Digit5)*/
	case 5:
		LCD->RAM[LCD_RAMRegister_0] &= 0xfff3cfff;
		LCD->RAM[LCD_RAMRegister_2] &= 0xfff3cfff;
		LCD->RAM[LCD_RAMRegister_4] &= 0xfff3efff;
		LCD->RAM[LCD_RAMRegister_6] &= 0xfff3efff;

		LCD->RAM[LCD_RAMRegister_0] |= ((digit[0]& 0x0c) << 16 ) | ((digit[0]& 0x03) << 12 ) ; // 5G 5B 5M 5E	
		LCD->RAM[LCD_RAMRegister_2] |= ((digit[1]& 0x0c) << 16 ) | ((digit[1]& 0x03) << 12 ) ; // 5F 5A 5C 5D
		LCD->RAM[LCD_RAMRegister_4] |= ((digit[2]& 0x0c) << 16 ) | ((digit[2]& 0x01) << 12 ) ; // 5Q 5K   5P 
		LCD->RAM[LCD_RAMRegister_6] |= ((digit[3]& 0x0c) << 16 ) | ((digit[3]& 0x01) << 12 ) ; // 5H 5J   5N

		break;

		/* Position 6 on LCD (Digit6)*/
	case 6:
		LCD->RAM[LCD_RAMRegister_0] &= 0xfffc3fff;
		LCD->RAM[LCD_RAMRegister_2] &= 0xfffc3fff;
		LCD->RAM[LCD_RAMRegister_4] &= 0xfffc3fff;
		LCD->RAM[LCD_RAMRegister_6] &= 0xfffc3fff;

		LCD->RAM[LCD_RAMRegister_0] |= ((digit[0]& 0x04) << 15 ) | ((digit[0]& 0x08) << 13 ) | ((digit[0]& 0x03) << 14 ) ; // 6B 6G 6M 6E	
		LCD->RAM[LCD_RAMRegister_2] |= ((digit[1]& 0x04) << 15 ) | ((digit[1]& 0x08) << 13 ) | ((digit[1]& 0x03) << 14 ) ; // 6A 6F 6C 6D
		LCD->RAM[LCD_RAMRegister_4] |= ((digit[2]& 0x04) << 15 ) | ((digit[2]& 0x08) << 13 ) | ((digit[2]& 0x01) << 14 ) ; // 6K 6Q    6P 
		LCD->RAM[LCD_RAMRegister_6] |= ((digit[3]& 0x04) << 15 ) | ((digit[3]& 0x08) << 13 ) | ((digit[3]& 0x01) << 14 ) ; // 6J 6H   6N

		break;

	default:
		break;
	}

}

/**
* @brief  This function writes a char in the LCD RAM.
* @param  ptr: Pointer to string to display on the LCD Glass.
* @retval None
*/
void LCD_GLASS_DisplayString(uint8_t* ptr)
{
	while(LCD->SR & LCD_SR_UDR);
	uint8_t i = 0x01;



	/* Send the string character by character on lCD */
	while ((*ptr != 0) & (i < LCD_CHAR_COUNT))
	{
		/* Display one character on LCD */
		LCD_GLASS_WriteChar(ptr, 0, 0, i);

		/* Point on the next character */
		ptr++;

		/* Increment the character counter */
		i++;
	}
	LCD->SR |= LCD_SR_UDR;
}



/**
* @brief  This function writes a whole string on LCD with scrolling for long strings. 
* @param  ptr: Pointer to string to display on the LCD Glass.
* @param  len: Length of string
* @param  updateDelay: Time in millisecond - delay between character printing
* @retval None
*/
void LCD_GLASS_DisplayWholeString(uint8_t* ptr, uint8_t len, uint8_t updateDelay)
{
	
	uint8_t offset = 0;
	while(offset + LCD_CHAR_COUNT < len)
	{
		LCD_GLASS_DisplayString(ptr);
		offset++;
		ptr++;
		HAL_Delay(updateDelay);
	}
	LCD_GLASS_DisplayString(ptr);
}
	

/**
* @brief  This function writes a whole string on LCD with scrolling for long strings time by time specific number of times or until callback will return TRUE. 
* @param  ptr: Pointer to string to display on the LCD Glass.
* @param  len: Length of string
* @param  updateDelay: Time in millisecond - delay between character printing
	@param  betweenMessageDelay: Time in millisecond - delay between message retelling
	@param  times: Number of retelling. 0 for infinity
  @param  callback: Callback function for indicate stop moment. NULL for infinity loop. 
* @retval None
*/
void LCD_GLASS_Tiker(uint8_t* ptr, uint8_t len,  uint8_t updateDelay, uint8_t betweenMessageDelay, uint8_t times, BOOL callback())
{
	uint8_t i = 0;
	while(1)
	{
		if (times != 0 && i >= times)
			break;
		if (callback != NULL)
			if (callback())
				break;
		LCD_GLASS_DisplayWholeString(ptr, len, updateDelay);
		HAL_Delay(betweenMessageDelay);
	}
}



/**
* @brief  This function initialize GPIO for LCD controlling.
* @retval None
*/
void LCD_GLASS_InitGpio(void)
{
	RCC->AHBENR |= 0x7;
	GPIOA->MODER |= 0x802A00A8;
	GPIOB->MODER |= 0xAAAA0A80;
	GPIOC->MODER |= 0xAAA0AA;
	GPIOA->OTYPER &= ~0x870E;
	GPIOB->OTYPER &= ~0xFF38;
	GPIOC->OTYPER &= ~0xFCF;
	GPIOA->PUPDR &= ~0xC03F00FC;
	GPIOB->PUPDR &= ~0xFFFF0FC0;
	GPIOC->PUPDR &= ~0xFFF0FF;
	GPIOA->OSPEEDR &= ~0xC03F00FC;
	GPIOB->OSPEEDR &= ~0xFFFF0FC0;
	GPIOC->OSPEEDR &= ~0xFFFFF0FF;
	GPIOA->AFR[0] |= 0xBBB0;
	GPIOA->AFR[1] |= 0xB0000BBB;
	GPIOB->AFR[0] |= 0xBBB000;
	GPIOB->AFR[1] |= 0xBBBBBBBB;
	GPIOC->AFR[0] |= 0xBB00BBBB;
	GPIOC->AFR[1] |= 0xBBBB;
}


/**
* @brief  This function initialize timers and LCD for LCD controlling.
* @retval None
*/
void LCD_GLASS_InitController(void)
{
	RCC->APB1ENR |= 0x10000200;
	PWR->CR |= 0x100;
	RCC->CSR |= 0x800000;
	RCC->CSR &= ~0x800000;
	RCC->CSR |= 0x100;
	while(!(RCC->CSR&RCC_CSR_LSERDY));
	RCC->CSR |= 0x10000;
	LCD->CR &= ~0x60;
	LCD->CR |= 0x40;
	LCD->CR &= ~0x1C;
	LCD->CR |= 0xC;
	LCD->CR |= 0x80;
	LCD->FCR &= ~0x3C00000;
	LCD->FCR &= ~0x3C0000;
	LCD->FCR |= 0x1040000;
	LCD->FCR &= ~0x1C00;
	LCD->FCR |= 0x800;
	while(!(LCD->SR&LCD_SR_FCRSR));
	LCD->CR &= ~0x2;
	LCD->CR |= 0x1;
	while(!(LCD->SR&LCD_SR_RDY));
	while(!(LCD->SR&LCD_SR_ENS));

}