# ============================================================================
# Custom Build Configuration Overrides
# Template for customizing QGroundControl branding and feature set
# ============================================================================

# ============================================================================
# Application Metadata
# ============================================================================

set(QGC_APP_NAME "RobiotecGC" CACHE STRING "Application Name" FORCE)
set(QGC_APP_COPYRIGHT "Copyright (c) 2025 Robiotec Ecuador S.A. Todos los derechos reservados." CACHE STRING "Copyright notice" FORCE)
set(QGC_APP_DESCRIPTION "Aplicación de control aéreo no tripulado" CACHE STRING "Application description" FORCE)
set(QGC_ORG_NAME "Robiotec" CACHE STRING "Organization name" FORCE)
set(QGC_ORG_DOMAIN "robiotec.ec" CACHE STRING "Organization domain" FORCE)
set(QGC_PACKAGE_NAME "org.mavlink.rgc" CACHE STRING "Package identifier" FORCE)

# ============================================================================
# Feature Flags
# ============================================================================

#set(QGC_UTM_ADAPTER ON CACHE BOOL "Enable UTM (Unmanned Traffic Management) Adapter" FORCE)
#set(QGC_VIEWER3D OFF CACHE BOOL "Enable 3D Viewer (requires Qt Quick 3D)" FORCE)

# ============================================================================
# Video Streaming Options
# ============================================================================

set(QGC_ENABLE_QT_VIDEOSTREAMING ON CACHE BOOL "Enable QtMultimedia video backend" FORCE)

# ============================================================================
# Autopilot Plugin Configuration
# ============================================================================

# PX4 Plugin
set(QGC_DISABLE_PX4_PLUGIN ON CACHE BOOL "Disable PX4 plugin" FORCE)
set(QGC_DISABLE_PX4_PLUGIN_FACTORY ON CACHE BOOL "Disable PX4 Plugin Factory" FORCE)

# ============================================================================
# Platform-Specific Configuration
# ============================================================================

# ----------------------------------------------------------------------------
# Android Platform
# ----------------------------------------------------------------------------
set(QT_ANDROID_DEPLOYMENT_TYPE "Release" CACHE STRING "Android deployment type (empty or Release)" FORCE)
set(QT_ANDROID_SIGN_APK ON CACHE BOOL "Enable APK signing" FORCE)

# ----------------------------------------------------------------------------
# Linux Platform
# ----------------------------------------------------------------------------
if(EXISTS "${CMAKE_SOURCE_DIR}/custom/resources/brand/medium_256.png")
    set(QGC_APPIMAGE_ICON_256_PATH "${CMAKE_SOURCE_DIR}/custom/resources/brand/medium_256.png" CACHE FILEPATH "AppImage 256x256 icon path" FORCE)
endif()
if(EXISTS "${CMAKE_SOURCE_DIR}/custom/resources/brand/logotipo.svg")
    set(QGC_APPIMAGE_ICON_SCALABLE_PATH "${CMAKE_SOURCE_DIR}/custom/resources/brand/logotipo.svg" CACHE FILEPATH "AppImage Icon SVG Path" FORCE)
endif()
if(EXISTS "${CMAKE_SOURCE_DIR}/custom/deploy/linux/AppRun")
    set(QGC_APPIMAGE_APPRUN_PATH "${CMAKE_SOURCE_DIR}/custom/deploy/linux/AppRun" CACHE FILEPATH "AppImage AppRun script path" FORCE)
endif()
set(QGC_APPIMAGE_APPDATA_DEVELOPER "galvarado" CACHE STRING "AppImage developer name" FORCE)

# ----------------------------------------------------------------------------
# Windows Platform
# ----------------------------------------------------------------------------
if(EXISTS "${CMAKE_SOURCE_DIR}/custom/resources/brand/install_header.bmp")
    set(QGC_WINDOWS_INSTALL_HEADER_PATH "${CMAKE_SOURCE_DIR}/custom/resources/brand/install_header.bmp" CACHE FILEPATH "Windows installer header image" FORCE)
endif()
if(EXISTS "${CMAKE_SOURCE_DIR}/custom/resources/brand/small_128.ico")
    set(QGC_WINDOWS_ICON_PATH "${CMAKE_SOURCE_DIR}/custom/resources/brand/small_128.ico" CACHE FILEPATH "Windows application icon" FORCE)
endif()
