/* Header */
#include "DrvImu.h"

/* Private includes */
#include <assert.h>
#include <stddef.h>

/*
 * Private functions
 */


/*
 * Public functions
 */
void DrvImu_setIicAddress(DrvImu_t *p_pImu, uint8_t p_iicAddress) {
	/* Check input */
	assert(p_pImu != NULL);

	p_pImu->iicAddress = p_iicAddress;
}

DrvImuStatus_t DrvImu_whoAmI(DrvImu_t * p_pImu, uint8_t * p_pIdentity) {

	uint8_t l_whoAmIReg = (uint8_t)DRV_IMU_WHO_AM_I_ADDR;

	/* Check input */
	assert(p_pImu != NULL);
	assert(p_pIdentity != NULL);

	/* Read who am i register */
	if(p_pImu->iicTransmit(p_pImu->iicAddress, &l_whoAmIReg, 1) == DrvImu_error)
		return DrvImu_error;

	if(p_pImu->iicReceive(p_pImu->iicAddress, p_pIdentity, 1) == DrvImu_error)
		return DrvImu_error;

	return DrvImu_ok;
}





