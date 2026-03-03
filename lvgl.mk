LVGL_PATH ?= ${shell pwd}/lvgl
LVGL_ENABLE_DEMOS ?= 0
LVGL_ENABLE_EXAMPLES ?= 0

ASRCS += $(shell find $(LVGL_PATH)/src -type f -name '*.S')
CSRCS += $(shell find $(LVGL_PATH)/src -type f -name '*.c')

ifeq ($(LVGL_ENABLE_DEMOS), 1)
CSRCS += $(shell find $(LVGL_PATH)/demos -type f -name '*.c')
endif

ifeq ($(LVGL_ENABLE_EXAMPLES), 1)
CSRCS += $(shell find $(LVGL_PATH)/examples -type f -name '*.c')
endif
CXXEXT := .cpp
CXXSRCS += $(shell find $(LVGL_PATH)/src -type f -name '*${CXXEXT}')

AFLAGS += "-I$(LVGL_PATH)"
CFLAGS += "-I$(LVGL_PATH)"
CXXFLAGS += "-I$(LVGL_PATH)"
