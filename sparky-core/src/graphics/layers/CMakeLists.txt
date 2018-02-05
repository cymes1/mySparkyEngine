ADD_LIBRARY(layers layer.cpp tilelayer.cpp)

TARGET_LINK_LIBRARIES(layers ${GLEW_LIBRARIES})
TARGET_LINK_LIBRARIES(layers graphics)
