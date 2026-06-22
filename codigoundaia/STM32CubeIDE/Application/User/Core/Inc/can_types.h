/*
 * can_types.h
 *
 *  Created on: 2 de mar. de 2026
 *      Author: D E L L
 */

#ifndef APPLICATION_USER_CORE_INC_CAN_TYPES_H_
#define APPLICATION_USER_CORE_INC_CAN_TYPES_H_

#include "main.h"

#pragma pack(push, 1)
typedef struct {
    uint32_t id;
    uint8_t  data[8];
} can_msg_t;
#pragma pack(pop)


#endif /* APPLICATION_USER_CORE_INC_CAN_TYPES_H_ */
