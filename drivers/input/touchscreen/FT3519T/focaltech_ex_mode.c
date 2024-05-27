/*
 *
 * FocalTech ftxxxx TouchScreen driver.
 *
 * Copyright (c) 2012-2020, Focaltech Ltd. All rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

/*****************************************************************************
*
* File Name: focaltech_ex_mode.c
*
* Author: Focaltech Driver Team
*
* Created: 2016-08-31
*
* Abstract:
*
* Reference:
*
*****************************************************************************/

/*****************************************************************************
* 1.Included header files
*****************************************************************************/
#include "focaltech_core.h"

/*****************************************************************************
* 2.Private constant and macro definitions using #define
*****************************************************************************/

/*****************************************************************************
* 3.Private enumerations, structures and unions using typedef
*****************************************************************************/
enum _ex_mode {
	MODE_GLOVE = 0,
	MODE_COVER,
	MODE_CHARGER,
	MODE_EDGE,
	MODE_PALM,
};

/*****************************************************************************
* 4.Static variables
*****************************************************************************/

/*****************************************************************************
* 5.Global variable or extern global variabls/functions
*****************************************************************************/

/*****************************************************************************
* 6.Static function prototypes
*******************************************************************************/
static int fts_ex_mode_switch(enum _ex_mode mode, u8 value)
{
	int ret = 0;
	u8 m_val = 0;

	if (value)
		m_val = value;
	else
		m_val = 0x00;

	switch (mode) {
	case MODE_GLOVE:
		ret = fts_write_reg(FTS_REG_GLOVE_MODE_EN, m_val);
		if (ret < 0) {
			FTS_ERROR("MODE_GLOVE switch to %d fail", m_val);
		}
		break;
	case MODE_COVER:
		ret = fts_write_reg(FTS_REG_COVER_MODE_EN, m_val);
		if (ret < 0) {
			FTS_ERROR("MODE_COVER switch to %d fail", m_val);
		}
		break;
	case MODE_CHARGER:
		ret = fts_write_reg(FTS_REG_CHARGER_MODE_EN, m_val);
		if (ret < 0) {
			FTS_ERROR("MODE_CHARGER switch to %d fail", m_val);
		}
		break;
	case MODE_EDGE:
		ret = fts_write_reg(FTS_REG_EDGE_MODE_EN, m_val);
		if (ret < 0) {
			FTS_ERROR("MODE_EDGE switch to %d fail", m_val);
		}
		break;
	case MODE_PALM:
		ret = fts_write_reg(FTS_REG_PALM_MODE_EN, m_val);
		if (ret < 0) {
			FTS_ERROR("MODE_PALM switch to %d fail", m_val);
		}
		break;
	default:
		FTS_ERROR("mode(%d) unsupport", mode);
		ret = -EINVAL;
		break;
	}

	return ret;
}

static ssize_t fts_glove_mode_show(struct device *dev,
				   struct device_attribute *attr, char *buf)
{
	int count = 0;
	u8 val = 0;
	struct fts_ts_data *ts_data = dev_get_drvdata(dev);
	struct input_dev *input_dev = ts_data->input_dev;

	mutex_lock(&input_dev->mutex);
	fts_read_reg(FTS_REG_GLOVE_MODE_EN, &val);
	count = snprintf(buf + count, PAGE_SIZE, "Glove Mode:%s\n",
			 ts_data->glove_mode ? "On" : "Off");
	count += snprintf(buf + count, PAGE_SIZE, "Glove Reg(0xC0):%d\n", val);
	mutex_unlock(&input_dev->mutex);

	return count;
}

static ssize_t fts_glove_mode_store(struct device *dev,
				    struct device_attribute *attr,
				    const char *buf, size_t count)
{
	int ret = 0;
	struct fts_ts_data *ts_data = dev_get_drvdata(dev);

	if (FTS_SYSFS_ECHO_ON(buf)) {
		if (!ts_data->glove_mode) {
			FTS_DEBUG("enter glove mode");
			ret = fts_ex_mode_switch(MODE_GLOVE, ENABLE);
			if (ret >= 0) {
				ts_data->glove_mode = ENABLE;
			}
		}
	} else if (FTS_SYSFS_ECHO_OFF(buf)) {
		if (ts_data->glove_mode) {
			FTS_DEBUG("exit glove mode");
			ret = fts_ex_mode_switch(MODE_GLOVE, DISABLE);
			if (ret >= 0) {
				ts_data->glove_mode = DISABLE;
			}
		}
	}

	FTS_DEBUG("glove mode:%d", ts_data->glove_mode);
	return count;
}

static ssize_t fts_cover_mode_show(struct device *dev,
				   struct device_attribute *attr, char *buf)
{
	int count = 0;
	u8 val = 0;
	struct fts_ts_data *ts_data = dev_get_drvdata(dev);
	struct input_dev *input_dev = ts_data->input_dev;

	mutex_lock(&input_dev->mutex);
	fts_read_reg(FTS_REG_COVER_MODE_EN, &val);
	count = snprintf(buf + count, PAGE_SIZE, "Cover Mode:%s\n",
			 ts_data->cover_mode ? "On" : "Off");
	count += snprintf(buf + count, PAGE_SIZE, "Cover Reg(0xC1):%d\n", val);
	mutex_unlock(&input_dev->mutex);

	return count;
}

static ssize_t fts_cover_mode_store(struct device *dev,
				    struct device_attribute *attr,
				    const char *buf, size_t count)
{
	int ret = 0;
	struct fts_ts_data *ts_data = dev_get_drvdata(dev);

	if (FTS_SYSFS_ECHO_ON(buf)) {
		if (!ts_data->cover_mode) {
			FTS_DEBUG("enter cover mode");
			ret = fts_ex_mode_switch(MODE_COVER, ENABLE);
			if (ret >= 0) {
				ts_data->cover_mode = ENABLE;
			}
		}
	} else if (FTS_SYSFS_ECHO_OFF(buf)) {
		if (ts_data->cover_mode) {
			FTS_DEBUG("exit cover mode");
			ret = fts_ex_mode_switch(MODE_COVER, DISABLE);
			if (ret >= 0) {
				ts_data->cover_mode = DISABLE;
			}
		}
	}

	FTS_DEBUG("cover mode:%d", ts_data->cover_mode);
	return count;
}

static ssize_t fts_palm_mode_show(struct device *dev,
				  struct device_attribute *attr, char *buf)
{
	int count = 0;
	u8 val = 0;
	struct fts_ts_data *ts_data = dev_get_drvdata(dev);
	struct input_dev *input_dev = ts_data->input_dev;

	mutex_lock(&input_dev->mutex);
	fts_read_reg(FTS_REG_PALM_MODE_EN, &val);
	count = snprintf(buf + count, PAGE_SIZE, "PALM Mode:%s\n",
			 ts_data->palm_mode ? "On" : "Off");
	count += snprintf(buf + count, PAGE_SIZE, "palm Reg(0x9A):%d\n", val);
	mutex_unlock(&input_dev->mutex);

	return count;
}

static ssize_t fts_palm_mode_store(struct device *dev,
				   struct device_attribute *attr,
				   const char *buf, size_t count)
{
	struct fts_ts_data *ts_data = dev_get_drvdata(dev);

	if (FTS_SYSFS_ECHO_ON(buf)) {
		FTS_INFO("enable palm");
		ts_data->palm_mode = 1;
		fts_write_reg(0x9A, 0x01);
	} else if (FTS_SYSFS_ECHO_OFF(buf)) {
		FTS_INFO("disable palm");
		ts_data->palm_mode = 0;
		fts_write_reg(0x9A, 0x00);
	}

	FTS_INFO("palm mode:%d", ts_data->palm_mode);
	return count;
}

static ssize_t fts_charger_mode_show(struct device *dev,
				     struct device_attribute *attr, char *buf)
{
	int count = 0;
	u8 val = 0;
	struct fts_ts_data *ts_data = dev_get_drvdata(dev);
	struct input_dev *input_dev = ts_data->input_dev;

	mutex_lock(&input_dev->mutex);
	fts_read_reg(FTS_REG_CHARGER_MODE_EN, &val);
	count = snprintf(buf + count, PAGE_SIZE, "Charger Mode:%s\n",
			 ts_data->charger_mode ? "On" : "Off");
	count += snprintf(buf + count, PAGE_SIZE, "Charger Reg(0x8B):%d\n", val);
	mutex_unlock(&input_dev->mutex);

	return count;
}

static ssize_t fts_charger_mode_store(struct device *dev,
				      struct device_attribute *attr,
				      const char *buf, size_t count)
{
	int ret = 0;
	struct fts_ts_data *ts_data = dev_get_drvdata(dev);

	if (FTS_SYSFS_ECHO_ON(buf)) {
		if (!ts_data->charger_mode) {
			FTS_DEBUG("enter charger mode");
			ret = fts_ex_mode_switch(MODE_CHARGER, ENABLE);
			if (ret >= 0) {
				ts_data->charger_mode = ENABLE;
			}
		}
	} else if (FTS_SYSFS_ECHO_OFF(buf)) {
		if (ts_data->charger_mode) {
			FTS_DEBUG("exit charger mode");
			ret = fts_ex_mode_switch(MODE_CHARGER, DISABLE);
			if (ret >= 0) {
				ts_data->charger_mode = DISABLE;
			}
		}
	}

	FTS_DEBUG("charger mode:%d", ts_data->charger_mode);
	return count;
}
/* BSP.TP - 2022.06.23 - modify for TP add Edge Mode */
/* read and write edge mode
 * read example: cat fts_edge_mode		---read  edge mode
 * write example:echo 1 > fts_edge_mode   ---write edge mode to 01
 */
static ssize_t fts_edge_mode_show(struct device *dev,
				  struct device_attribute *attr, char *buf)
{
	int count = 0;
	u8 val = 0;
	struct fts_ts_data *ts_data = fts_data;
	struct input_dev *input_dev = ts_data->input_dev;

	mutex_lock(&input_dev->mutex);
	fts_read_reg(FTS_REG_EDGE_MODE_EN, &val);
	count = snprintf(buf + count, PAGE_SIZE, "Edge Mode:%s\n",
			 ts_data->edge_mode ? "On" : "Off");
	count += snprintf(buf + count, PAGE_SIZE, "Edge Reg(0x8C):%d\n", val);
	mutex_unlock(&input_dev->mutex);

	return count;
}

static ssize_t fts_edge_mode_store(struct device *dev,
				   struct device_attribute *attr,
				   const char *buf, size_t count)
{
	int ret = 0;
	struct fts_ts_data *ts_data = fts_data;

	if (FTS_SYSFS_ECHO_ON(buf)) {
		if (buf[0] == '1') /*USB PORTS RIGHT*/ {
			FTS_INFO("enter right mode");
			ret = fts_ex_mode_switch(MODE_EDGE, 1);
			if (ret >= 0) {
				ts_data->edge_mode = 1;
			}
		}
		if (buf[0] == '2') /*USB PORTS LEFT*/ {
			FTS_INFO("enter left mode");
			ret = fts_ex_mode_switch(MODE_EDGE, 2);
			if (ret >= 0) {
				ts_data->edge_mode = 2;
			}
		}
	} else if (FTS_SYSFS_ECHO_OFF(buf)) {
			FTS_DEBUG("exit edge mode");
			ret = fts_ex_mode_switch(MODE_EDGE, DISABLE);
			if (ret >= 0) {
				ts_data->edge_mode = DISABLE;
			}
	}

	FTS_DEBUG("edge mode:%d", ts_data->edge_mode);
	return count;
}
/* end modify*/

/* read and write charger mode
 * read example: cat fts_glove_mode		---read  glove mode
 * write example:echo 1 > fts_glove_mode   ---write glove mode to 01
 */
static DEVICE_ATTR(fts_glove_mode, S_IRUGO | S_IWUSR, fts_glove_mode_show,
		   fts_glove_mode_store);

static DEVICE_ATTR(fts_cover_mode, S_IRUGO | S_IWUSR, fts_cover_mode_show,
		   fts_cover_mode_store);

static DEVICE_ATTR(fts_charger_mode, S_IRUGO | S_IWUSR, fts_charger_mode_show,
		   fts_charger_mode_store);

static DEVICE_ATTR(fts_edge_mode, S_IRUGO | S_IWUSR, fts_edge_mode_show,
		   fts_edge_mode_store);
static DEVICE_ATTR(fts_palm_mode, S_IRUGO | S_IWUSR, fts_palm_mode_show,
		   fts_palm_mode_store);

static struct attribute *fts_touch_mode_attrs[] = {
	&dev_attr_fts_glove_mode.attr,   &dev_attr_fts_cover_mode.attr,
	&dev_attr_fts_charger_mode.attr, &dev_attr_fts_edge_mode.attr,
	&dev_attr_fts_palm_mode.attr,    NULL,
};

static struct attribute_group fts_touch_mode_group = {
	.attrs = fts_touch_mode_attrs,
};

int fts_ex_mode_recovery(struct fts_ts_data *ts_data)
{
	if (ts_data->glove_mode) {
		fts_ex_mode_switch(MODE_GLOVE, ENABLE);
	}

	if (ts_data->cover_mode) {
		fts_ex_mode_switch(MODE_COVER, ENABLE);
	}

	if (ts_data->charger_mode) {
		fts_ex_mode_switch(MODE_CHARGER, ENABLE);
	}

	if (ts_data->edge_mode) {
		fts_ex_mode_switch(MODE_EDGE, ts_data->edge_mode);
	}

	if (ts_data->palm_mode) {
		fts_ex_mode_switch(MODE_PALM, ts_data->palm_mode);
	}
	return 0;
}

int fts_ex_mode_init(struct fts_ts_data *ts_data)
{
	int ret = 0;

	ts_data->glove_mode = DISABLE;
	ts_data->cover_mode = DISABLE;
	ts_data->charger_mode = DISABLE;
	ts_data->edge_mode = DISABLE;
	ts_data->palm_mode = DISABLE;

	ret = sysfs_create_group(&ts_data->dev->kobj, &fts_touch_mode_group);
	if (ret < 0) {
		FTS_ERROR("create sysfs(ex_mode) fail");
		sysfs_remove_group(&ts_data->dev->kobj, &fts_touch_mode_group);
		return ret;
	} else {
		FTS_DEBUG("create sysfs(ex_mode) successfully");
	}

	return 0;
}

int fts_ex_mode_exit(struct fts_ts_data *ts_data)
{
	sysfs_remove_group(&ts_data->dev->kobj, &fts_touch_mode_group);
	return 0;
}
