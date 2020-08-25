/*
 * SIM800.h
 *
 *  Created on: Jan 12, 2019
 *      Author: Itachi
 */

#ifndef SIM800_H_
#define SIM800_H_

#define IP_Adress        "171.235.62.21"
#define PORT             "2015"
extern char SIM_startTCP_command[50];
extern char OK[4];
void SIM_Init(void);
bool SIM_TCPSend(char *datasource);
bool SIM_Respond(char *correct_resp);
bool SIM_SendCMD_Comp(char *command,
                      char *correct_res,
                      int   time_try);




#endif /* SIM800_H_ */
