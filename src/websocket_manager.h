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
 * The websocketManager class.
 */
#ifndef SRC_WEBSOCKET_MANAGER_H_
#define SRC_WEBSOCKET_MANAGER_H_

#include "connectionManager/connection_manager.h"
#include "serviceManager/service_manager.h"
#include "tokenManager/token_manager.h"
#include "websocketServer/websocket_server.h"

#include <memory>

class websocketManager {
 public:
/**
 * Constructor
 *
*/
  websocketManager();

/**
 * Destructor
 *
*/
  ~websocketManager();

  connectionManager* getConnectionManager() { return connection_manager_.get(); }
 private:
  std::unique_ptr<connectionManager> connection_manager_;
  std::unique_ptr<serviceManager> service_manager_;
  std::unique_ptr<tokenManager> token_manager_;
  std::unique_ptr<websocketServer> websocket_server_;
};
#endif  // SRC_WEBSOCKET_MANAGER_H_