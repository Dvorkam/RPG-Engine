cmake_minimum_required(VERSION 3.21)
project("RPG_ENGINE"
	VERSION 0.0.1
	DESCRIPTION "Project that aims to prepare tools for further project."
	LANGUAGES CXX
	)
set (CMAKE_CXX_STANDARD 20)

enable_testing()

add_subdirectory("randEngine")
add_subdirectory("dicesLibrary")



