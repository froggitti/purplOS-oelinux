BASEMACHINE ?= "genericarmv8-64"
require conf/machine/include/basemachine.inc

# Pull in security flags
require ${COREBASE}/meta-qti-bsp/conf/distro/include/security_flags.inc

require conf/machine/include/arm/arch-armv8.inc

PREFERRED_PROVIDER_virtual/kernel = "linux-msm"
PREFERRED_VERSION_linux-msm = "4.9"

MACHINE_DISPLAY_WIDTH_PIXELS ?= "480"
MACHINE_DISPLAY_HEIGHT_PIXELS ?= "640"

SERIAL_CONSOLE ?= "${@['', '115200 ttyV0'][d.getVar('VARIANT', True) == ('' or 'debug')]}"

DISTRO ?= "msm"

MACHINE_FEATURES += "kernel26 keyboard"

PAGE_SIZE ?= '4096'

# Max supported inodes
EXTRA_IMAGECMD ?= "-N 2048"

# Sizes for EXT4 (in bytes)
SYSTEM_SIZE_EXT4 ?= "65536000"
USERDATA_SIZE_EXT4 ?= "65536000"
CACHE_SIZE_EXT4 ?= "65536000"
RECOVERYFS_SIZE_EXT4 ?= "65536000"

# Multilib configuration
# This sets any packages preprended with lib32- to be built with
# the armv7a tuning (32 bit) instead of 64 bit aarch.
require conf/multilib.conf
MULTILIBS = "multilib:lib32"
DEFAULTTUNE_virtclass-multilib-lib32 = "armv7a-neon"

DISTRO_FEATURES:append = " avble"

# Formats of root filesystem images.
IMAGE_FSTYPES += "ext4"
