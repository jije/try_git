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
 * The websocket class manages websocket connection.
 */

#ifndef SRC_CONNECTIONMANAGER_WEBSOCKET_H_
#define SRC_CONNECTIONMANAGER_WEBSOCKET_H_
#include <libwebsockets.h>

class websocket {
 public:
/**
 * Constructor
 *
*/
 websocket(struct lws *wsi);

/**
 * Destructor
 *
*/
  ~websocket();

 private:
  lws *wsi_;
};
#endif  // SRC_CONNECTIONMANAGER_WEBSOCKET_H_