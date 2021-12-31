add_library (jsoncpp
  json/json-forwards.h
  json/json.h
  jsoncpp.cpp)

install (TARGETS jsoncpp DESTINATION bin)
install (FILES json.h json/json-forwards.h DESTINATION include)