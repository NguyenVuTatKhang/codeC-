BBB_GPIO_VERSION = 1.0
BBB_GPIO_SITE = $(TOPDIR)/package/bbb_gpio/src
BBB_GPIO_SITE_METHOD = local

define BBB_GPIO_BUILD_CMDS
    $(MAKE) $(TARGET_CONFIGURE_OPTS) -C $(@D)
endef

define BBB_GPIO_INSTALL_TARGET_CMDS
    $(INSTALL) -D -m 0755 $(@D)/libbbb_gpio.so \
        $(TARGET_DIR)/usr/lib/libbbb_gpio.so
endef

$(eval $(generic-package))
