IF (WIN32)
	SET (CMAKE_CXX_FLAGS "-Wall -std=gnu++11")
ELSE ()
	SET (CMAKE_CXX_FLAGS "-Wall -std=c++11")
ENDIF ()

ADD_SUBDIRECTORY (src)

ADD_EXECUTABLE (sparky main.cpp)

TARGET_LINK_LIBRARIES (sparky ${GLEW_LIBRARIES})
TARGET_LINK_LIBRARIES (sparky glfw)
TARGET_LINK_LIBRARIES (sparky ${OPENGL_gl_LIBRARY})

TARGET_LINK_LIBRARIES (sparky graphics)
TARGET_LINK_LIBRARIES (sparky buffers)
TARGET_LINK_LIBRARIES (sparky layers)
TARGET_LINK_LIBRARIES (sparky math)

CONFIGURE_FILE(
	${CMAKE_SOURCE_DIR}/sparky-core/src/shaders/basic.vert
	${CURRENT_CMAKE_BINARY_DIR}/shaders/basic.vert
	COPYONLY)
CONFIGURE_FILE(
	${CMAKE_SOURCE_DIR}/sparky-core/src/shaders/basic.frag
	${CURRENT_CMAKE_BINARY_DIR}/shaders/basic.frag
	COPYONLY)
