/* 
 * File:   BLE2Click.h
 * Author: I16092
 *
 * Created on April 24, 2018, 8:03 PM
 */

#ifndef BLE2CLICK_H
#define	BLE2CLICK_H

#ifdef	__cplusplus
extern "C" {
#endif

char buf[64];
const char cmd_factoryreset[] = "SF,1\r\n";
const char cmd_userdefineprofile[] = "SS,00000001\r\n";
const char cmd_peripheral[] = "SR,20000000\r\n";
const char cmd_cleanprivateservice[] = "PZ\r\n";
const char cmd_UUID[] = "PS,00112233445566778899AABBCCDDEEFF\r\n";
const char cmd_led_control[] =   "PC,012301234567456789AB89ABCDEFCDEF,08,08\r\n";
const char cmd_serialized_name[] = "S-,BLE2Click\r\n";
const char cmd_name[]="SN,BLE2Click\r\n";
const char cmd_reboot[] = "R,1\r\n";
const char cmd_advertise[] = "A\r\n";
const char cmd_sleep[] = "K\r\n";
const char cmd_stop_advertise[] = "Y\r\n";
const char resp_cmd[]="CMD";
const char resp_AOK[]="AOK";
const char resp_conn[]="Connected";
const char resp_conn_param[]="ConnParam";
const char resp_conn_data[]="WV";
const char resp_conn_notification[]="WC";
const char resp_conn_end[]="Connection End";

void BLE2ClickSetup (void) ;
void BLE2ClickGetstr (void);


#ifdef	__cplusplus
}
#endif

#endif	/* BLE2CLICK_H */

