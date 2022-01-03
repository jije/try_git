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

#ifndef SRC_WEBSOCKETSERVER_WEBSOCKET_SERVER_H_
#define SRC_WEBSOCKETSERVER_WEBSOCKET_SERVER_H_

#include <stdint.h>
#include <pthread.h>

class websocketManager;
class websocketServer {
 public:
/**
 * Constructor
 *
 * @param manager is pointer of websocketManager object
 * @param port is server port number
*/
  websocketServer(websocketManager* manager, int16_t port);

/**
 * Destructor
 *
*/
  ~websocketServer();

 private:
  void connectionEstablished(struct lws *wsi);
  static void* createAndStartServer(int16_t port);

 private:
  int16_t port_;
  websocketManager* manager_;
  pthread_mutex_t lock_;
};
#endif  // SRC_WEBSOCKETSERVER_WEBSOCKET_SERVER_H_