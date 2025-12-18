# ============================================================================
# QGroundControl Custom Plugin Example
# Template for building custom QGroundControl plugins
# ============================================================================

message(STATUS "QGC: Adding Custom Resources")

# ============================================================================
# Custom Resources and Import Paths
# ============================================================================

# Add custom Qt resources
list(APPEND CUSTOM_RESOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/custom.qrc"
    "${CMAKE_SOURCE_DIR}/custom/resources/instrumentValueIcons/InstrumentValueIcons.qrc"
)
set(QGC_RESOURCES ${QGC_RESOURCES} ${CUSTOM_RESOURCES} CACHE STRING "Paths to .qrc Resources" FORCE)

# Add custom QML import path
set(QML_IMPORT_PATH ${QML_IMPORT_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/resources" CACHE STRING "Extra qml import paths" FORCE)
