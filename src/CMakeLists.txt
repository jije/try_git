add_library (websocketManager
  websocket_manager.cc
  websocket_manager.h
  connectionManager/connection_manager.cc
  connectionManager/connection_manager.h
  connectionManager/websocket.cc
  connectionManager/websocket.h
  serviceManager/service_manager.cc
  serviceManager/service_manager.h
  tokenManager/token_manager.cc
  tokenManager/token_manager.h
  websocketServer/websocket_server.cc
  websocketServer/websocket_server.h)

INCLUDE_DIRECTORIES (../third-party/libwebsockets/include ../third-party/jsoncpp/json)

install (TARGETS websocketManager DESTINATION bin)
#install (FILES json.h json/json-forwards.h DESTINATION include)