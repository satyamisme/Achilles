#ifndef DEVICE_H
#define DEVICE_H

#include <Achilles.h>
#include <usb/usb.h>
#include <exploit/dfu.h>
#include <utils/log.h>
#include <IOKit/IOKitLib.h>

enum DeviceMode {
    MODE_NORMAL,
    MODE_RECOVERY,
    MODE_DFU,
    MODE_PONGO
};

typedef enum DeviceMode DeviceMode;

typedef struct
{
    usb_handle_t handle;
    char *serialNumber;
    DeviceMode mode;
} device_t;

// ******************************************************
// Function: findDevice()
//
// Purpose: Find a device
//
// Parameters:
//      device_t *device: the device struct to return
//
// Returns:
//      int: 0 if the device was found, 1 otherwise
// ******************************************************
int findDevice(device_t *device, bool waiting);

// ******************************************************
// Function: waitForDeviceInMode()
//
// Purpose: Wait for a device to be in a certain mode
//
// Parameters:
//      device_t *device: the device to wait for
//      DeviceMode mode: the mode to wait for
//      int timeout: the timeout in seconds
//
// Returns:
//      int: 0 if the device was found, 1 otherwise
// ******************************************************
int waitForDeviceInMode(device_t *device, DeviceMode mode, int timeout);

#endif // DEVICE_H