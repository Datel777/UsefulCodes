cmake_minimum_required(VERSION 3.5)

set(TARGET VulkanTest)
#SET(BUILD_SHARED_LIBS OFF) #Not sure about this
SET(CMAKE_EXE_LINKER_FLAGS "-static")   #to link qt's mingw libs staticly

project(${TARGET} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${TARGET} main.cpp)

#After installing Vulkan_SDK it is also will add %VULKAN_SDK% enviroment system path
#Cmake already has FindVulkan.cmake in modules path which use %VULKAN_SDK%
find_package(Vulkan REQUIRED)

#target_compile_definitions(${TARGET} PRIVATE VK_USE_PLATFORM_WIN32_KHR)    #not sure
target_include_directories(${TARGET} PRIVATE Vulkan::Vulkan)
target_link_libraries(${TARGET} PRIVATE Vulkan::Vulkan)
