/*
 * hidl interface for wpa_supplicant daemon
 * Copyright (c) 2004-2016, Jouni Malinen <j@w1.fi>
 * Copyright (c) 2004-2016, Roshan Pius <rpius@google.com>
 *
 * This software may be distributed under the terms of the BSD license.
 * See README for more details.
 */

#ifndef WPA_SUPPLICANT_HIDL_HIDL_H
#define WPA_SUPPLICANT_HIDL_HIDL_H

#ifdef _cplusplus
extern "C" {
#endif  // _cplusplus

/**
 * This is the hidl RPC interface entry point to the wpa_supplicant core.
 * This initializes the hidl driver & HidlManager instance and then forwards
 * all the notifcations from the supplicant core to the HidlManager.
 */
struct wpas_hidl_priv;
struct wpa_global;

struct wpas_hidl_priv *wpas_hidl_init(struct wpa_global *global);
void wpas_hidl_deinit(struct wpas_hidl_priv *priv);

#ifdef CONFIG_CTRL_IFACE_HIDL
int wpas_hidl_register_interface(struct wpa_supplicant *wpa_s);
int wpas_hidl_unregister_interface(struct wpa_supplicant *wpa_s);
int wpas_hidl_register_network(
    struct wpa_supplicant *wpa_s, struct wpa_ssid *ssid);
int wpas_hidl_unregister_network(
    struct wpa_supplicant *wpa_s, struct wpa_ssid *ssid);
int wpas_hidl_notify_state_changed(struct wpa_supplicant *wpa_s);
int wpas_hidl_notify_network_request(
    struct wpa_supplicant *wpa_s, struct wpa_ssid *ssid,
    enum wpa_ctrl_req_type rtype, const char *default_txt);
#else   // CONFIG_CTRL_IFACE_HIDL
static inline int wpas_hidl_register_interface(struct wpa_supplicant *wpa_s)
{
	return 0;
}
static inline int wpas_hidl_unregister_interface(struct wpa_supplicant *wpa_s)
{
	return 0;
}
static inline int wpas_hidl_register_network(
    struct wpa_supplicant *wpa_s, struct wpa_ssid *ssid)
{
	return 0;
}
static inline int wpas_hidl_unregister_network(
    struct wpa_supplicant *wpa_s, struct wpa_ssid *ssid)
{
	return 0;
}
static inline int wpas_hidl_notify_state_changed(struct wpa_supplicant *wpa_s)
{
	return 0;
}
static inline int wpas_hidl_notify_network_request(
    struct wpa_supplicant *wpa_s, struct wpa_ssid *ssid,
    enum wpa_ctrl_req_type rtype, const char *default_txt)
{
	return 0;
}
#endif  // CONFIG_CTRL_IFACE_HIDL

#ifdef _cplusplus
}
#endif  // _cplusplus

#endif  // WPA_SUPPLICANT_HIDL_HIDL_H
