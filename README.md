# Eximius_Android_Training_Batch1
Android Nougat (7.1.2) Bring Up on Raspberry Pi 3

# 1. System Requirements
Refer to https://source.android.com/setup/requirements

# 2. Establishing a Build Environment
Refer to https://source.android.com/setup/initializing

# 3. Download Android Nougat Source with patches (local_manifests)
Refer to http://source.android.com/source/downloading.html
$ repo init -u https://android.googlesource.com/platform/manifest -b android-7.1.2_r19
$ git clone https://github.com/android-rpi/local_manifests .repo/local_manifests
$ repo sync -f
 
# 4. Build for Raspberry Pi 3

# 1. Build Kernel
 Install gcc-arm-linux-gnueabihf
 $ cd kernel/rpi
 $ ARCH=arm scripts/kconfig/merge_config.sh arch/arm/configs/bcm2709_defconfig android/configs/android-base.cfg android/configs/android-recommended.cfg
 $ ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- make zImage
 $ ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- make dtbs

# 2. Install python mako module
  sudo apt-get install python-mako

# 3. Patch framework source :
  
# 4. Build Android source
 Continue build with http://source.android.com/source/building.html
 $ source build/envsetup.sh
 $ lunch rpi3-eng
 $ make -j4

# 5. Prepare SD Card
 Partitions of the card should be set-up as follows
  p1 512MB for BOOT : Do fdisk : W95 FAT32(LBA) & Bootable, mkfs.vfat
  p2 512MB for /system : Do fdisk, new primary partition
  p3 512MB for /cache  : Do fdisk, mkfs.ext4
  p4 remaining for /data : Do fdisk, mkfs.ext4
 Set volume label for each partition - system, cache, userdata
  : use -L option of mkfs.ext4, e2label command, or -n option of mkfs.vfat
 
# 6. Write system partition
  $ cd out/target/product/rpi3
  $ sudo dd if=system.img of=/dev/<p2> bs=1M
  
# 7. Copy kernel & ramdisk to BOOT partition
  device/brcm/rpi3/boot/* to p1:/
  kernel/rpi/arch/arm/boot/zImage to p1:/
  kernel/rpi/arch/arm/boot/dts/bcm2710-rpi-3-b.dtb to p1:/
  kernel/rpi/arch/arm/boot/dts/overlays/vc4-kms-v3d.dtbo to p1:/overlays/vc4-kms-v3d.dtbo
  out/target/product/rpi3/ramdisk.img to p1:/

