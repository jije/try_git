/**
 * COPYRIGHT ⓒ 2017 Obigo Inc.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Obigo Inc.,and may be
 * used and copied only in accordance with the terms of the
 * said agreement.
 *
 * Obigo Inc. assumes no responsibility or
 * liability for any errors or inaccuracies in this software,
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 * 
 * @section DESCRIPTION
 *
 * The websocketServer class starts websocket server.
 */

//#include "libwebsockets.h"
#include <stdint.h>

class websocketServer {
 public:
/**
 * Constructor
 *
 * @param port is server port number
*/
  websocketServer(int16_t port);

/**
 * Destructor
 *
*/
  ~websocketServer();

 private:
  void createAndStartServer(int16_t port);

 private:
  int16_t port_;
};