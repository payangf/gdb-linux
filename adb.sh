#!/bin/bash
#https://wiki.linaro.org/LMG/Kernel/AndroidConfigFSGadgets#ADB_gadget_configuration
modprobe g_ether
rmmod g_ether
sleep 1
#Mount ConfigFS and create Gadget
mount -t configfs none /config
mkdir -p /config/usb_gadget/g1
cd /config/usb_gadget/g1

#Set default Vendor and Product IDs for now
echo 0x18d1 > idVendor
echo 0x4E26 > idProduct

#Create English strings and add random deviceID
mkdir strings/0x409
echo 0123459876 > strings/0x409/serialnumber

#Update following if you want to
echo "Test" > strings/0x409/manufacturer
echo "Test" > strings/0x409/product

#Create gadget configuration
mkdir configs/c.1
mkdir configs/c.1/strings/0x409
echo "Conf 1" > configs/c.1/strings/0x409/configuration
echo 120 > configs/c.1/MaxPower

#Create Adb FunctionFS function
#And link it to the gadget configuration
#stop adbd
mkdir -p functions/fs.adb
ln -s /config/usb_gadget/g1/functions/fs.adb /config/usb_gadget/g1/configs/c.1/fs.adb

#Start adbd application
mkdir -p /dev/usb/adb
mount -o uid=1000,gid=0 -t functions adb /dev/fs/adb
adbd &

#Enable the Gadget
#Replace "any_linux.0" with your platform UDC driver as found in /sys/class/udc/
echo 'cl_master.0' > /sys/class/UDC$
#start adbd

#commandargs [-] -c ($);
