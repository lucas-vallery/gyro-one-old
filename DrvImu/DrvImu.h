/*
 * DrvImu.h
 *
 *  Created on: Sep 21, 2023
 *      Author: lucas
 */

#ifndef INC_DRVIMU_H_
#define INC_DRVIMU_H_

/* Includes */
#include <stdint.h>

#define DRV_IMU_WHO_AM_I_ADDR 0x0F

typedef enum {
	DrvImu_ok,
	DrvImu_error
}DrvImuStatus_t;

typedef DrvImuStatus_t (* iicTransmit_t)(uint16_t p_address, uint8_t * p_pData, uint16_t p_length);
typedef DrvImuStatus_t (* iicReceive_t)  (uint16_t p_address, uint8_t * p_buff, uint16_t p_length);

typedef struct {

	uint8_t iicAddress;

	iicTransmit_t iicTransmit;
	iicReceive_t iicReceive;

} DrvImu_t;

void DrvImu_setIicAddress(DrvImu_t * p_pImu, uint8_t p_iicAddress);
DrvImuStatus_t DrvImu_whoAmI(DrvImu_t * p_pImu, uint8_t * p_pIdentity);


#endif /* INC_DRVIMU_H_ */
