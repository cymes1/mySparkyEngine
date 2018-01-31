ADD_LIBRARY(buffers buffer.cpp indexBuffer.cpp vertexArray.cpp)

TARGET_LINK_LIBRARIES(buffers ${GLEW_LIBRARIES})
