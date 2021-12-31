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


#include "websocket_manager.h"

#include <stdio.h>

/**
 * Constructor
 *
*/
websocketManager::websocketManager() {
  //log (trace)
  printf("create websocketManager!\n");
  //load configuration
  // test fix port : 9999
  int16_t port = 9999;

  //create connectionManager
  connection_manager_ = std::make_unique<connectionManager>();
  service_manager_= std::make_unique<serviceManager>();
  token_manager_ = std::make_unique<tokenManager>();
  websocket_server_ = std::make_unique<websocketServer>(port);
}

/**
 * Destructor
 *
*/
websocketManager::~websocketManager() {
  //log (trace)
  printf("create websocketManager!\n");
}