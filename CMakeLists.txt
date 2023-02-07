cmake_minimum_required(VERSION 3.21)
project("theWorld"
	VERSION 0.0.1
	DESCRIPTION "Project that aims to simulate a world using population models."
	LANGUAGES CXX
	)
set (CMAKE_CXX_STANDARD 20)

enable_testing()

add_subdirectory("randEngine")
add_subdirectory("dicesLibrary")



