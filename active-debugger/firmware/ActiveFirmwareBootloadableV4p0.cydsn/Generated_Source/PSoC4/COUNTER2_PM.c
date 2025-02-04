/*******************************************************************************
* File Name: COUNTER2_PM.c
* Version 2.10
*
* Description:
*  This file contains the setup, control, and status commands to support
*  the component operations in the low power mode.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "COUNTER2.h"

static COUNTER2_BACKUP_STRUCT COUNTER2_backup;


/*******************************************************************************
* Function Name: COUNTER2_SaveConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to save here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void COUNTER2_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: COUNTER2_Sleep
********************************************************************************
*
* Summary:
*  Stops the component operation and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void COUNTER2_Sleep(void)
{
    if(0u != (COUNTER2_BLOCK_CONTROL_REG & COUNTER2_MASK))
    {
        COUNTER2_backup.enableState = 1u;
    }
    else
    {
        COUNTER2_backup.enableState = 0u;
    }

    COUNTER2_Stop();
    COUNTER2_SaveConfig();
}


/*******************************************************************************
* Function Name: COUNTER2_RestoreConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to restore here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void COUNTER2_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: COUNTER2_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and restores the enable state.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void COUNTER2_Wakeup(void)
{
    COUNTER2_RestoreConfig();

    if(0u != COUNTER2_backup.enableState)
    {
        COUNTER2_Enable();
    }
}


/* [] END OF FILE */
