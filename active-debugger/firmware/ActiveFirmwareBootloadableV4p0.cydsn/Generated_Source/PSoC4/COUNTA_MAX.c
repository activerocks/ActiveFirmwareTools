/*******************************************************************************
* File Name: COUNTA_MAX.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware to read the value of a Status 
*  Register.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "COUNTA_MAX.h"

#if !defined(COUNTA_MAX_sts_sts_reg__REMOVED) /* Check for removal by optimization */


/*******************************************************************************
* Function Name: COUNTA_MAX_Read
********************************************************************************
*
* Summary:
*  Reads the current value assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The current value in the Status Register.
*
*******************************************************************************/
uint8 COUNTA_MAX_Read(void) 
{ 
    return COUNTA_MAX_Status;
}


/*******************************************************************************
* Function Name: COUNTA_MAX_InterruptEnable
********************************************************************************
*
* Summary:
*  Enables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void COUNTA_MAX_InterruptEnable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    COUNTA_MAX_Status_Aux_Ctrl |= COUNTA_MAX_STATUS_INTR_ENBL;
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: COUNTA_MAX_InterruptDisable
********************************************************************************
*
* Summary:
*  Disables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void COUNTA_MAX_InterruptDisable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    COUNTA_MAX_Status_Aux_Ctrl &= (uint8)(~COUNTA_MAX_STATUS_INTR_ENBL);
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: COUNTA_MAX_WriteMask
********************************************************************************
*
* Summary:
*  Writes the current mask value assigned to the Status Register.
*
* Parameters:
*  mask:  Value to write into the mask register.
*
* Return:
*  None.
*
*******************************************************************************/
void COUNTA_MAX_WriteMask(uint8 mask) 
{
    #if(COUNTA_MAX_INPUTS < 8u)
    	mask &= ((uint8)(1u << COUNTA_MAX_INPUTS) - 1u);
	#endif /* End COUNTA_MAX_INPUTS < 8u */
    COUNTA_MAX_Status_Mask = mask;
}


/*******************************************************************************
* Function Name: COUNTA_MAX_ReadMask
********************************************************************************
*
* Summary:
*  Reads the current interrupt mask assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The value of the interrupt mask of the Status Register.
*
*******************************************************************************/
uint8 COUNTA_MAX_ReadMask(void) 
{
    return COUNTA_MAX_Status_Mask;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
