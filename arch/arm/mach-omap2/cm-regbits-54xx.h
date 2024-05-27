/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * OMAP54xx Clock Management register bits
 *
 * Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com
 *
 * Paul Walmsley (paul@pwsan.com)
 * Rajendra Nayak (rnayak@ti.com)
 * Benoit Cousson (b-cousson@ti.com)
 *
 * This file is automatically generated from the OMAP hardware databases.
 * We respectfully ask that any modifications to this file be coordinated
 * with the public linux-omap@vger.kernel.org mailing list and the
 * authors above to ensure that the autogeneration scripts are kept
 * up-to-date with the file contents.
 */

#ifndef __ARCH_ARM_MACH_OMAP2_CM_REGBITS_54XX_H
#define __ARCH_ARM_MACH_OMAP2_CM_REGBITS_54XX_H

#define OMAP54XX_ABE_STATDEP_SHIFT					3
#define OMAP54XX_AUTO_DPLL_MODE_MASK					(0x7 << 0)
#define OMAP54XX_CLKSEL_SHIFT						24
#define OMAP54XX_CLKSEL_WIDTH						0x1
#define OMAP54XX_CLKSEL_0_0_SHIFT					0
#define OMAP54XX_CLKSEL_0_0_WIDTH					0x1
#define OMAP54XX_CLKSEL_AESS_FCLK_SHIFT					24
#define OMAP54XX_CLKSEL_AESS_FCLK_WIDTH					0x1
#define OMAP54XX_CLKSEL_DIV_SHIFT					25
#define OMAP54XX_CLKSEL_DIV_WIDTH					0x1
#define OMAP54XX_CLKSEL_FCLK_SHIFT					24
#define OMAP54XX_CLKSEL_FCLK_WIDTH					0x1
#define OMAP54XX_CLKSEL_GPU_CORE_GCLK_SHIFT				24
#define OMAP54XX_CLKSEL_GPU_CORE_GCLK_WIDTH				0x1
#define OMAP54XX_CLKSEL_GPU_HYD_GCLK_SHIFT				25
#define OMAP54XX_CLKSEL_GPU_HYD_GCLK_WIDTH				0x1
#define OMAP54XX_CLKSEL_INTERNAL_SOURCE_SHIFT				26
#define OMAP54XX_CLKSEL_INTERNAL_SOURCE_WIDTH				0x2
#define OMAP54XX_CLKSEL_OPP_SHIFT					0
#define OMAP54XX_CLKSEL_OPP_WIDTH					0x2
#define OMAP54XX_CLKSEL_SOURCE_SHIFT					24
#define OMAP54XX_CLKSEL_SOURCE_WIDTH					0x2
#define OMAP54XX_CLKSEL_SOURCE_L3INIT_MMC1_SHIFT			24
#define OMAP54XX_CLKSEL_SOURCE_L3INIT_MMC1_WIDTH			0x1
#define OMAP54XX_CLKSEL_UTMI_P1_SHIFT					24
#define OMAP54XX_CLKSEL_UTMI_P1_WIDTH					0x1
#define OMAP54XX_CLKSEL_UTMI_P2_SHIFT					25
#define OMAP54XX_CLKSEL_UTMI_P2_WIDTH					0x1
#define OMAP54XX_DIVHS_MASK						(0x3f << 0)
#define OMAP54XX_DIVHS_0_4_MASK						(0x1f << 0)
#define OMAP54XX_DIVHS_0_6_MASK						(0x7f << 0)
#define OMAP54XX_DPLL_DIV_MASK						(0x7f << 0)
#define OMAP54XX_DPLL_EN_MASK						(0x7 << 0)
#define OMAP54XX_DPLL_LPMODE_EN_MASK					(1 << 10)
#define OMAP54XX_DPLL_MULT_MASK						(0x7ff << 8)
#define OMAP54XX_DPLL_REGM4XEN_MASK					(1 << 11)
#define OMAP54XX_DPLL_SD_DIV_MASK					(0xff << 24)
#define OMAP54XX_DSP_STATDEP_SHIFT					1
#define OMAP54XX_DSS_STATDEP_SHIFT					8
#define OMAP54XX_EMIF_STATDEP_SHIFT					4
#define OMAP54XX_GPU_STATDEP_SHIFT					10
#define OMAP54XX_IPU_STATDEP_SHIFT					0
#define OMAP54XX_IVA_STATDEP_SHIFT					2
#define OMAP54XX_L3INIT_STATDEP_SHIFT					7
#define OMAP54XX_L3MAIN1_STATDEP_SHIFT					5
#define OMAP54XX_L3MAIN2_STATDEP_SHIFT					6
#define OMAP54XX_L4CFG_STATDEP_SHIFT					12
#define OMAP54XX_L4PER_STATDEP_SHIFT					13
#define OMAP54XX_L4SEC_STATDEP_SHIFT					14
#define OMAP54XX_OPTFCLKEN_32KHZ_CLK_SHIFT				11
#define OMAP54XX_OPTFCLKEN_32KHZ_CLK_8_8_SHIFT				8
#define OMAP54XX_OPTFCLKEN_48MHZ_CLK_SHIFT				9
#define OMAP54XX_OPTFCLKEN_CLK32K_SHIFT					8
#define OMAP54XX_OPTFCLKEN_CTRLCLK_SHIFT				8
#define OMAP54XX_OPTFCLKEN_DBCLK_SHIFT					8
#define OMAP54XX_OPTFCLKEN_DSSCLK_SHIFT					8
#define OMAP54XX_OPTFCLKEN_HSIC480M_P1_CLK_SHIFT			13
#define OMAP54XX_OPTFCLKEN_HSIC480M_P2_CLK_SHIFT			14
#define OMAP54XX_OPTFCLKEN_HSIC480M_P3_CLK_SHIFT			7
#define OMAP54XX_OPTFCLKEN_HSIC60M_P1_CLK_SHIFT				11
#define OMAP54XX_OPTFCLKEN_HSIC60M_P2_CLK_SHIFT				12
#define OMAP54XX_OPTFCLKEN_HSIC60M_P3_CLK_SHIFT				6
#define OMAP54XX_OPTFCLKEN_REFCLK960M_SHIFT				8
#define OMAP54XX_OPTFCLKEN_REF_CLK_SHIFT				8
#define OMAP54XX_OPTFCLKEN_SLIMBUS_CLK_SHIFT				11
#define OMAP54XX_OPTFCLKEN_SYS_CLK_SHIFT				10
#define OMAP54XX_OPTFCLKEN_TXPHY_CLK_SHIFT				8
#define OMAP54XX_OPTFCLKEN_TXPHY_LS_CLK_SHIFT				9
#define OMAP54XX_OPTFCLKEN_USB_CH0_CLK_SHIFT				8
#define OMAP54XX_OPTFCLKEN_USB_CH1_CLK_SHIFT				9
#define OMAP54XX_OPTFCLKEN_USB_CH2_CLK_SHIFT				10
#define OMAP54XX_OPTFCLKEN_UTMI_P1_CLK_SHIFT				8
#define OMAP54XX_OPTFCLKEN_UTMI_P2_CLK_SHIFT				9
#define OMAP54XX_OPTFCLKEN_UTMI_P3_CLK_SHIFT				10
#define OMAP54XX_PAD_CLKS_GATE_SHIFT					8
#define OMAP54XX_SLIMBUS1_CLK_GATE_SHIFT				10
#define OMAP54XX_ST_DPLL_CLK_MASK					(1 << 0)
#define OMAP54XX_SYS_CLKSEL_SHIFT					0
#define OMAP54XX_SYS_CLKSEL_WIDTH					0x3
#define OMAP54XX_WKUPAON_STATDEP_SHIFT					15
#endif
