/***********************************************************************************************************
 ===========================================================================================================
 Module      :  Fan state
 Author      :  AHMED ADLY
 date        :  29/2/2024
 Description :  the Fan states Header file
 ===========================================================================================================
 ***********************************************************************************************************/
#ifndef FAN_STATE_H_
#define FAN_STATE_H_

/*******************************************************************************
 *                               Types Declaration                                 *
 *******************************************************************************/
typedef enum
{
	OFF,ON
}FAN_STATE;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*Description :
 * This function is responsible for updating the LCD display
 */
void LCD_displayUpdate(void);

/*Description:
 * This function is responsible for tracking the Fan State based on the Temperature value
 *  and rotates the DC motor accordingly
 */
void Fan_Process (void);


#endif /* FAN_STATE_H_ */
