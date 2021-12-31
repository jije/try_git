add_library (third-party 
  Speaker.h
  Speaker.cpp)

install (TARGETS third-party DESTINATION bin)
install (FILES Speaker.h DESTINATION include)
