cmake_minimum_required(VERSION 3.15.0)

cmake_policy(SET CMP0016 NEW)

project(parallel_executor VERSION 1.0.0 DESCRIPTION "Синхронизация нескольких потоков исполнения через очередь сообщений на C++")

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

include_directories(${CMAKE_SOURCE_DIR}/include)

include_directories(${CMAKE_SOURCE_DIR}/src)

include_directories(${CMAKE_SOURCE_DIR})

SET(HEADERS "./include/Device.h" "./include/Event.h" "./include/EventQueue.h" "./include/DeviceEvent.h" "./include/DataEvent.h" "./include/StartedEvent.h" "./include/WorkDoneEvent.h" "./include/DeviceA.h" "./include/DeviceB.h")

SET(SRC_FILES "./src/parallel_executor/main.cpp" "./src/parallel_executor/EventQueue.cpp" "./src/parallel_executor/DeviceEvent.cpp" "./src/parallel_executor/DataEvent.cpp" "./src/parallel_executor/StartedEvent.cpp" "./src/parallel_executor/WorkDoneEvent.cpp" "./src/parallel_executor/DeviceA.cpp" "./src/parallel_executor/DeviceB.cpp")

add_executable(main ${SRC_FILES})