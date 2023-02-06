cmake_minimum_required(VERSION 3.16)
project("theWorld"
	VERSION 0.0.1
	DESCRIPTION "Project that aims to simulate a world using population models."
	LANGUAGES CXX
	)
set (CMAKE_CXX_STANDARD 20)

#add_subdirectory("randEngine")
add_executable(TEST_PROJECT)
add_subdirectory("dicesLibrary")
