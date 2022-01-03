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
 * The connectionManager class manages websocket connections.
 */

#include "connection_manager.h"
#include "websocket.h"

#include <stdio.h>
#include <libwebsockets.h>
/**
 * Constructor
 *
*/
connectionManager::connectionManager() {
  //log (trace)
  printf("create connectionManager!\n");
  connection_lists_.clear();
}

/**
 * Destructor
 *
*/
connectionManager::~connectionManager() {
  //log (trace)
  printf("create connectionManager!\n");
}

/**
 * Function Destructor
 *
*/
void connectionManager::addNewConnection(struct lws *wsi) {
  if (wsi != nullptr) {
    auto connection = std::make_unique<websocket>(wsi);
    connection_lists_.push_back(std::move(connection));
  }
}