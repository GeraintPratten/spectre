# Distributed under the MIT License.
# See LICENSE.txt for details.

set(LIBRARY ScalarWave)

set(LIBRARY_SOURCES
    Equations.cpp
    )

add_library(${LIBRARY} ${LIBRARY_SOURCES})

target_link_libraries(
  ${LIBRARY}
  INTERFACE DataStructures
  INTERFACE ErrorHandling
  )
