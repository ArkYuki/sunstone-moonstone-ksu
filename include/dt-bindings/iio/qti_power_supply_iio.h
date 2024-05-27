/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2020-2021 The Linux Foundation. All rights reserved.
 */

#ifndef __QTI_POWER_SUPPLY_IIO_H__
#define __QTI_POWER_SUPPLY_IIO_H__

/* PSY_IIO properties */

/* USB */
#define PSY_IIO_PD_CURRENT_MAX			0x00
#define PSY_IIO_TYPEC_MODE			0x01
#define PSY_IIO_TYPEC_POWER_ROLE		0x02
#define PSY_IIO_TYPEC_CC_ORIENTATION		0x03
#define PSY_IIO_PD_ACTIVE			0x04
#define PSY_IIO_USB_INPUT_CURRENT_SETTLED	0x05
#define PSY_IIO_INPUT_CURRENT_NOW		0x06
#define PSY_IIO_PE_START			0x07
#define PSY_IIO_CTM_CURRENT_MAX			0x08
#define PSY_IIO_HW_CURRENT_MAX			0x09
#define PSY_IIO_USB_REAL_TYPE			0x0a
#define PSY_IIO_PD_VOLTAGE_MAX			0x0b
#define PSY_IIO_PD_VOLTAGE_MIN			0x0c
#define PSY_IIO_CONNECTOR_TYPE			0x0d
#define PSY_IIO_CONNECTOR_HEALTH		0x0e
#define PSY_IIO_VOLTAGE_MAX_LIMIT		0x0f
#define PSY_IIO_SMB_EN_MODE			0x10
#define PSY_IIO_SMB_EN_REASON			0x11
#define PSY_IIO_ADAPTER_CC_MODE			0x12
#define PSY_IIO_MOISTURE_DETECTED		0x13
#define PSY_IIO_HVDCP_OPTI_ALLOWED		0x14
#define PSY_IIO_QC_OPTI_DISABLE			0x15
#define PSY_IIO_VOLTAGE_VPH			0x16
#define PSY_IIO_THERM_ICL_LIMIT			0x17
#define PSY_IIO_SKIN_HEALTH			0x18
#define PSY_IIO_APSD_RERUN			0x19
#define PSY_IIO_APSD_TIMEOUT			0x1a
#define PSY_IIO_CHARGER_STATUS			0x1b
#define PSY_IIO_USB_INPUT_VOLTAGE_SETTLED	0x1c

#define PSY_IIO_TYPEC_SRC_RP			0x1d
#define PSY_IIO_PD_IN_HARD_RESET		0x1e
#define PSY_IIO_PD_USB_SUSPEND_SUPPORTED	0x1f
#define PSY_IIO_PR_SWAP				0x20

/* MAIN */
#define PSY_IIO_MAIN_INPUT_CURRENT_SETTLED	0x21
#define PSY_IIO_MAIN_INPUT_VOLTAGE_SETTLED	0x22
#define PSY_IIO_FCC_DELTA			0x23
#define PSY_IIO_FLASH_ACTIVE			0x24
#define PSY_IIO_FLASH_TRIGGER			0x25
#define PSY_IIO_TOGGLE_STAT			0x26
#define PSY_IIO_MAIN_FCC_MAX			0x27
#define PSY_IIO_IRQ_STATUS			0x28
#define PSY_IIO_FORCE_MAIN_FCC			0x29
#define PSY_IIO_FORCE_MAIN_ICL			0x2a
#define PSY_IIO_COMP_CLAMP_LEVEL		0x2b
#define PSY_IIO_HOT_TEMP			0x2c

#define PSY_IIO_VOLTAGE_MAX			0x2d
#define PSY_IIO_CONSTANT_CHARGE_CURRENT_MAX	0x2e
#define PSY_IIO_CURRENT_MAX			0x2f
#define PSY_IIO_HEALTH				0x30

/* DC */
#define PSY_IIO_INPUT_VOLTAGE_REGULATION	0x31
#define PSY_IIO_DC_REAL_TYPE			0x32
#define PSY_IIO_DC_RESET			0x33
#define PSY_IIO_AICL_DONE			0x34

/* BATTERY */
#define PSY_IIO_CHARGER_TEMP			0x35
#define PSY_IIO_CHARGER_TEMP_MAX		0x36
#define PSY_IIO_INPUT_CURRENT_LIMITED		0x37
#define PSY_IIO_SW_JEITA_ENABLED		0x38
#define PSY_IIO_CHARGE_DONE			0x39
#define PSY_IIO_PARALLEL_DISABLE		0x3a
#define PSY_IIO_SET_SHIP_MODE			0x3b
#define PSY_IIO_DIE_HEALTH			0x3c
#define PSY_IIO_RERUN_AICL			0x3d
#define PSY_IIO_DP_DM				0x3e
#define PSY_IIO_RECHARGE_SOC			0x3f
#define PSY_IIO_FORCE_RECHARGE			0x40
#define PSY_IIO_FCC_STEPPER_ENABLE		0x41

/* BMS */
#define PSY_IIO_CAPACITY			0x42
#define PSY_IIO_CAPACITY_RAW			0x43
#define PSY_IIO_REAL_CAPACITY			0x44
#define PSY_IIO_TEMP				0x45
#define PSY_IIO_VOLTAGE_NOW			0x46
#define PSY_IIO_VOLTAGE_OCV			0x47
#define PSY_IIO_CURRENT_NOW			0x48
#define PSY_IIO_CHARGE_COUNTER			0x49
#define PSY_IIO_RESISTANCE			0x4a
#define PSY_IIO_RESISTANCE_ID			0x4b
#define PSY_IIO_SOC_REPORTING_READY		0x4c
#define PSY_IIO_RESISTANCE_CAPACITIVE		0x4d
#define PSY_IIO_DEBUG_BATTERY			0x4e
#define PSY_IIO_VOLTAGE_MIN			0x4f
#define PSY_IIO_BATT_FULL_CURRENT		0x50
#define PSY_IIO_BATT_PROFILE_VERSION		0x51
#define PSY_IIO_CYCLE_COUNT			0x52
#define PSY_IIO_CHARGE_FULL			0x53
#define PSY_IIO_CHARGE_FULL_DESIGN		0x54
#define PSY_IIO_TIME_TO_FULL_AVG		0x55
#define PSY_IIO_TIME_TO_FULL_NOW		0x56
#define PSY_IIO_TIME_TO_EMPTY_AVG		0x57
#define PSY_IIO_ESR_ACTUAL			0x58
#define PSY_IIO_ESR_NOMINAL			0x59
#define PSY_IIO_SOH				0x5a
#define PSY_IIO_CC_SOC				0x5b
#define PSY_IIO_FG_RESET			0x5c
#define PSY_IIO_VOLTAGE_AVG			0x5d
#define PSY_IIO_CURRENT_AVG			0x5e
#define PSY_IIO_POWER_AVG			0x5f
#define PSY_IIO_POWER_NOW			0x60
#define PSY_IIO_SCALE_MODE_EN			0x61
#define PSY_IIO_BATT_AGE_LEVEL			0x62
#define PSY_IIO_FG_TYPE				0x63

#define PSY_IIO_TYPEC_ACCESSORY_MODE		0x64

/* CHARGE PUMP */
#define PSY_IIO_CP_STATUS1			0x65
#define PSY_IIO_CP_STATUS2			0x66
#define PSY_IIO_CP_ENABLE			0x67
#define PSY_IIO_CP_SWITCHER_EN			0x68
#define PSY_IIO_CP_DIE_TEMP			0x69
#define PSY_IIO_CP_ISNS				0x6a
#define PSY_IIO_CP_ISNS_SLAVE			0x6b
#define PSY_IIO_CP_TOGGLE_SWITCHER		0x6c
#define PSY_IIO_CP_ILIM				0x6d
#define PSY_IIO_CHIP_VERSION			0x6e
#define PSY_IIO_PARALLEL_MODE			0x6f
#define PSY_IIO_PARALLEL_OUTPUT_MODE		0x70
#define PSY_IIO_MIN_ICL				0x71

#define PSY_IIO_CP_INPUT_CURRENT_MAX		0x72
#define PSY_IIO_CURRENT_CAPABILITY		0x73

/* SMB1355 Parallel */
#define PSY_IIO_CHARGE_TYPE			0x74
#define PSY_IIO_ONLINE				0x75
#define PSY_IIO_CHARGING_ENABLED		0x76
#define PSY_IIO_PIN_ENABLED			0x77
#define PSY_IIO_INPUT_SUSPEND			0x78
#define PSY_IIO_PARALLEL_BATFET_MODE		0x79
#define PSY_IIO_PARALLEL_FCC_MAX		0x7a

/* USB */
#define PSY_IIO_MOISTURE_DETECTION_EN		0x7b

/* BMS */
#define PSY_IIO_CLEAR_SOH			0x7c
#define PSY_IIO_OTG_ENABLE			0x7d
#define PSY_IIO_BOARD_TEMP			0x7e
/*Charge PUMP*/
#define PSY_IIO_APDO_MAX_VOLT       0x7f
#define PSY_IIO_APDO_MAX_CURR       0x80
#endif /* __QTI_POWER_SUPPLY_IIO_H__ */
