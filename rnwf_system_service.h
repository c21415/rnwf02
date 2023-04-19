/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */



/*! \page system_service System Service Layer
This page introduces the user to the topic.
*/


// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef RNWF_SYSTEM_SERVICE_H
#define	RNWF_SYSTEM_SERVICE_H

#include <xc.h> // include processor files - each processor file is guarded.  

#define RNWF_RESET_TARGET   "AT+RST\r\n"
#define RNWF_GET_MAN_ID     "AT+GMI\r\n"

#define RNWF_GET_SYS_TIME   "AT+TIME,3\r\n"

#define RNWF_SET_SYS_TIME_UNIX  "AT+TIME=1,%lu\r\n"
#define RNWF_SET_SYS_TIME_NTP   "AT+TIME=2,%lu\r\n"
/* Date/time in format YYYY-MM-DDTHH:MM:SS.00Z */ 
#define RNWF_SET_SYS_TIME_STRING    "AT+TIME=3,\"%s\"\r\n"

#define RNWF_GET_CERT_LIST  "AT+FS=2,1\r\n"
#define RNWF_GET_KEY_LIST   "AT+FS=2,2\r\n"


/**
 @defgroup SERVICE_GRP System Service API
 @{
 */


/**
 @brief System Service List
 
 */
typedef enum{
    RNWF_SYSTEM_RESET,             /**<Request/Trigger reset the system */
    RNWF_SYSTEM_GET_MAN_ID,        /**<Get the manufacturing ID */
    RNWF_SYSTEM_SET_TIME_UNIX,     /**<Set the sytem time in UNIX format */            
    RNWF_SYSTEM_SET_TIME_NTP,      /**<Set the system time in NTP format */            
    RNWF_SYSTEM_SET_TIME_STRING,   /**<Set the system time in string(YYYY-MM-DDTHH:MM:SS.00Z) format */                        
    RNWF_SYSTEM_GET_TIME,          /**<Get the system time */            
    RNWF_SYSTEM_GET_CERT_LIST,     /**<Get the available certificate list */
    RNWF_SYSTEM_GET_KEY_LIST,      /**<Get the available private key list */
            
}RNWF_SYSTEM_SERVICE_t;


/**
 * @brief System Service Layer API to handle system operations.
 * 
 *
 * @param[in] request   Service request ::RNWF_SYSTEM_SERVICE_t
 * @param[in] input     Parameters for the requested service
 * 
 * @return ::RNWF_PASS Requested service is handled successfully
 * @return ::RNWF_FAIL Requested service has failed
 */
RNWF_RESULT_t RNWF_SYSTEM_SrvCtrl(RNWF_SYSTEM_SERVICE_t request, uint8_t *input);

#endif	/* RNWF_SYSTEM_SERVICE_H */

/** @}*/