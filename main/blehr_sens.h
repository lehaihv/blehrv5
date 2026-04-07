/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#ifndef H_BLEHR_SENSOR_
#define H_BLEHR_SENSOR_

#include "nimble/ble.h"
#include "modlog/modlog.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * 128-bit UUIDs matching the Flutter app definitions.
 * NimBLE stores UUID bytes in little-endian order, so the bytes below
 * are the reverse of the canonical string representation.
 */

/*
 * Use BLE_UUID128_INIT (struct initializer) so these macros can be used
 * to initialize ble_uuid128_t variables. BLE_UUID128_DECLARE is a pointer
 * expression and cannot be used as a variable initializer.
 * Bytes are in little-endian order (reverse of the canonical UUID string).
 */

/* Heart Rate Service: 0000180d-0000-1000-8000-00805f9b34fb */
#define GATT_HRS_UUID_INIT \
    BLE_UUID128_INIT(0xfb,0x34,0x9b,0x5f,0x80,0x00,0x00,0x80, \
                     0x00,0x10,0x00,0x00,0x0d,0x18,0x00,0x00)

/* Heart Rate Measurement: 00002a37-0000-1000-8000-00805f9b34fb */
#define GATT_HRS_MEASUREMENT_UUID_INIT \
    BLE_UUID128_INIT(0xfb,0x34,0x9b,0x5f,0x80,0x00,0x00,0x80, \
                     0x00,0x10,0x00,0x00,0x37,0x2a,0x00,0x00)

/* Body Sensor Location: 00002a38-0000-1000-8000-00805f9b34fb */
#define GATT_HRS_BODY_SENSOR_LOC_UUID_INIT \
    BLE_UUID128_INIT(0xfb,0x34,0x9b,0x5f,0x80,0x00,0x00,0x80, \
                     0x00,0x10,0x00,0x00,0x38,0x2a,0x00,0x00)

/* Device Information Service: 0000180a-0000-1000-8000-00805f9b34fb */
#define GATT_DEVICE_INFO_UUID_INIT \
    BLE_UUID128_INIT(0xfb,0x34,0x9b,0x5f,0x80,0x00,0x00,0x80, \
                     0x00,0x10,0x00,0x00,0x0a,0x18,0x00,0x00)

/* Manufacturer Name: 00002a29-0000-1000-8000-00805f9b34fb */
#define GATT_MANUFACTURER_NAME_UUID_INIT \
    BLE_UUID128_INIT(0xfb,0x34,0x9b,0x5f,0x80,0x00,0x00,0x80, \
                     0x00,0x10,0x00,0x00,0x29,0x2a,0x00,0x00)

/* Model Number: 00002a24-0000-1000-8000-00805f9b34fb */
#define GATT_MODEL_NUMBER_UUID_INIT \
    BLE_UUID128_INIT(0xfb,0x34,0x9b,0x5f,0x80,0x00,0x00,0x80, \
                     0x00,0x10,0x00,0x00,0x24,0x2a,0x00,0x00)

/* Health Thermometer Service: 00001809-0000-1000-8000-00805f9b34fb */
#define GATT_TEMP_SERVICE_UUID_INIT \
    BLE_UUID128_INIT(0xfb,0x34,0x9b,0x5f,0x80,0x00,0x00,0x80, \
                     0x00,0x10,0x00,0x00,0x09,0x18,0x00,0x00)

/* Temperature Measurement: 00002a1c-0000-1000-8000-00805f9b34fb */
#define GATT_TEMP_MEASUREMENT_UUID_INIT \
    BLE_UUID128_INIT(0xfb,0x34,0x9b,0x5f,0x80,0x00,0x00,0x80, \
                     0x00,0x10,0x00,0x00,0x1c,0x2a,0x00,0x00)

extern uint16_t hrs_hrm_handle;
extern uint16_t temp_val_handle;

struct ble_hs_cfg;
struct ble_gatt_register_ctxt;

void gatt_svr_register_cb(struct ble_gatt_register_ctxt *ctxt, void *arg);
int gatt_svr_init(void);

#ifdef __cplusplus
}
#endif

#endif
