#!/bin/sh
# establish root in common system directories for 3rd party applications
/system/bin/mount -o remount,rw /dev/stl5 /system
/system/bin/rm /system/bin/su
/system/bin/rm /system/xbin/su
/system/bin/rm /bin/su
ln -s /sbin/su /system/bin/su
ln -s /sbin/su /system/xbin/su

chown root root /sbin/su
chmod 4755 /sbin/su

# fix busybox DNS while system is read-write
if [ ! -f "/system/etc/resolv.conf" ]; then
  /bin/echo "nameserver 8.8.8.8" >> /system/etc/resolv.conf
  /bin/echo "nameserver 8.8.8.4" >> /system/etc/resolv.conf
fi
#setup proper passwd and group files for 3rd party root access
if [ ! -f "/system/etc/passwd" ]; then
	/bin/echo "root::0:0:root:/data/local:/system/bin/sh" > /system/etc/passwd
	/bin/chmod 0666 /system/etc/passwd
fi
if [ ! -f "/system/etc/group" ]; then
	/bin/echo "root::0:" > /system/etc/group
	/bin/chmod 0666 /system/etc/group
fi

#provide support for a shell script to protect root access
if [ ! -f "/system/app/Superuser.apk" ]; then
  cp /sbin/Superuser.apk /system/app/Superuser.apk
fi

/system/etc/custom/*
/system/bin/mount -o remount,ro /dev/stl5 /system
