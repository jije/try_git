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

INCLUDE_DIRECTORIES (${CMAKE_SOURCE_DIR}/third-party/libwebsockets/include ${CMAKE_SOURCE_DIR}/third-party/jsoncpp/json)

find_package(Threads REQUIRED)
if(THREADS_HAVE_PTHREAD_ARG)
  set_property(TARGET websocketManager PROPERTY COMPILE_OPTIONS "-pthread")
  set_property(TARGET websocketManager PROPERTY INTERFACE_COMPILE_OPTIONS "-pthread")
endif()
if(CMAKE_THREAD_LIBS_INIT)
  target_link_libraries(websocketManager "${CMAKE_THREAD_LIBS_INIT}")
endif()


target_link_libraries (websocketManager jsoncpp websockets)
install (TARGETS websocketManager DESTINATION bin)
#install (FILES json.h json/json-forwards.h DESTINATION include)