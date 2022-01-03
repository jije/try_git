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

/**
 * Constructor
 *
 * @param port is server port number
*/

#include "websocket_server.h"
#include "../connectionManager/connection_manager.h"
#include "../websocket_manager.h"

#include <stdio.h>
#include <libwebsockets.h>

static const lws_retry_bo_t retry = {
  .secs_since_valid_ping = 3,
  .secs_since_valid_hangup = 10,
};

websocketServer::websocketServer(websocketManager* manager, int16_t port)
 : manager_(manager)
 , port_(port) {
  //log (trace)
  printf("create websocketServer!\n");

  pthread_t th;
  int tid, status;
  pthread_mutex_init(&lock_, nullptr);
  tid = pthread_create(&th, nullptr, &websocketServer::createAndStartServer, (void*)port);

  pthread_join(th, (void **)&status);
}

/**
 * Destructor
 *
*/
websocketServer::~websocketServer() {
  //log (trace)
  printf("create websocketServer!\n");
}

void websocketServer::connectionEstablished(struct lws *wsi) {

  //log (trace)
  printf("websocketServer::connectionEstablished!\n");
  pthread_mutex_lock(&lock_);
  manager_->getConnectionManager()->addNewConnection(wsi);
  pthread_mutex_unlock(&lock_);
}

static int
callback_server(struct lws *wsi, enum lws_callback_reasons reason,
         void *user, void *in, size_t len)
{
   switch (reason) {
   case LWS_CALLBACK_PROTOCOL_INIT:
      printf("websocketServer::callback_minimal LWS_CALLBACK_PROTOCOL_INIT!\n");
      break;

   case LWS_CALLBACK_ESTABLISHED:
      /* add ourselves to the list of live pss held in the vhd */
      printf("websocketServer::callback_minimal LWS_CALLBACK_ESTABLISHED! wsi:%p\n", wsi);
     // connectionEstablished();
      break;

   case LWS_CALLBACK_CLOSED:
      printf("websocketServer::callback_minimal LWS_CALLBACK_CLOSED!\n");
      break;

   case LWS_CALLBACK_SERVER_WRITEABLE:
      //printf("websocketServer::callback_minimal LWS_CALLBACK_CLOSED!\n");
      break;

   case LWS_CALLBACK_RECEIVE:
      printf("websocketServer::callback_minimal LWS_CALLBACK_RECEIVE! wsi:%p, str:%.*s\n", wsi, len, (char*)in);
      break;

   default:
      break;
   }

   return 0;
}

static void* websocketServer::createAndStartServer(int16_t port) {
  printf("websocketServer::createAndStartServer!\n");
  struct lws_context_creation_info info;
  struct lws_context *context;
  struct lws_protocols protocol;
  const char *p;
  int n = 0;

  protocol.name = "";
  protocol.callback = callback_server;
  protocol.per_session_data_size=0;
  protocol.rx_buffer_size = 0;

  memset(&info, 0, sizeof info); /* otherwise uninitialized garbage */
  info.port = port;
  info.protocols = &protocol;
  info.vhost_name = "localhost";
  info.options =
     LWS_SERVER_OPTION_HTTP_HEADERS_SECURITY_BEST_PRACTICES_ENFORCE;

#if 0//defined(LWS_WITH_TLS)
  // lwsl_user("Server using TLS\n");
  info.options |= LWS_SERVER_OPTION_DO_SSL_GLOBAL_INIT;
  info.ssl_cert_filepath = "localhost-100y.cert";
  info.ssl_private_key_filepath = "localhost-100y.key";
#endif

  info.retry_and_idle_policy = &retry;

  context = lws_create_context(&info);
  if (!context) {
    printf("lws init failed\n");
    return 1;
  }

  while (n >= 0)
    n = lws_service(context, 0);

  lws_context_destroy(context);
}