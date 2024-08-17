/*
 * Copyright (C) 2021-2022 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <libinit_dalvik_heap.h>
#include <libinit_variant.h>
#include <libinit_utils.h>

#include "vendor_init.h"

#define FINGERPRINT_GL "POCO/moonstone_p_global/moonstone:14/UKQ1.231003.002/V816.0.7.0.UMPMIXM:user/release-keys"
#define FINGERPRINT_CN "Redmi/sunstone_global/sunstone:14/UKQ1.230917.001/V816.0.5.0.UMQMIXM:user/release-keys"

static const variant_info_t stone_global_info = {
    .hwc_value = "",
    .sku_value = "moonstone_p_global",

    .brand = "POCO",
    .device = "moonstone",
    .model = "POCO X5 5G",
    .mod_device = "moonstone_p_global",
    .build_fingerprint = FINGERPRINT_GL,
    .soc_model = "Snapdragon 695",
};

static const variant_info_t stone_in_info = {
    .hwc_value = "",
    .sku_value = "moonstone_p_in",

    .brand = "POCO",
    .device = "moonstone",
    .model = "POCO X5 5G",
//  .mod_device = "moonstone_in_global",
    .mod_device = "moonstone_p_global", // Fixed miuicamera crash
    .build_fingerprint = FINGERPRINT_GL,
    .soc_model = "Snapdragon 695",
};

static const variant_info_t sunstone_cn_info = {
    .hwc_value = "",
    .sku_value = "sunstone_cn",

    .brand = "Redmi",
    .device = "sunstone",
    .model = "Redmi Note 12 5G",
//  .mod_device = "moonstone",
    .mod_device = "moonstone_global", // Fixed miuicamera crash
    .build_fingerprint = FINGERPRINT_CN,
    .soc_model = "Snapdragon 4 Gen 1",
};

static const variant_info_t sunstone_global_info = {
    .hwc_value = "",
    .sku_value = "sunstone_global",

    .brand = "Redmi",
    .device = "sunstone",
    .model = "Redmi Note 12 5G",
//  .mod_device = "moonstone",
    .mod_device = "moonstone_global", // Fixed miuicamera crash
    .build_fingerprint = FINGERPRINT_CN,
    .soc_model = "Snapdragon 4 Gen 1",
};

static const variant_info_t sunstone_in_info = {
    .hwc_value = "",
    .sku_value = "sunstone_in",

    .brand = "Redmi",
    .device = "sunstone",
    .model = "Redmi Note 12 5G",
//  .mod_device = "moonstone",
    .mod_device = "moonstone_global", // Fixed miuicamera crash
    .build_fingerprint = FINGERPRINT_CN,
    .soc_model = "Snapdragon 4 Gen 1",
};

static const variant_info_t sunstone_x_info = {
    .hwc_value = "",
    .sku_value = "sunstone_x",

    .brand = "Redmi",
    .device = "sunstone",
    .model = "Redmi Note 12R Pro",
//  .mod_device = "moonstone",
    .mod_device = "moonstone_global", // Fixed miuicamera crash
    .build_fingerprint = FINGERPRINT_CN,
    .soc_model = "Snapdragon 4 Gen 1",
};

static const std::vector<variant_info_t> variants = {
    stone_global_info,
    stone_in_info,
    sunstone_global_info,
    sunstone_cn_info,
    sunstone_in_info,
    sunstone_x_info,
};

void vendor_load_properties() {
    set_dalvik_heap();
    search_variant(variants);

    // SafetyNet workaround
    property_override("ro.boot.verifiedbootstate", "green");

    // Release Keys
    property_override("ro.build.keys", "release-keys");
    property_override("ro.build.tags", "release-keys");

}
