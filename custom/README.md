# QGroundControl Custom Build

Estación de control terrestre multi-plataforma para drones (Android, Linux, Windows)

## Linux AppImage error

[ERROR] Command '['tar', '-xvf', '/dev/shm/appimagelint-yylid6_v.tmp/data.tar.xz']' returned non-zero exit status 2.

## Nix AppImage fast deploy

nix run nixpkgs#appimage-run build/*.AppImage
  67890

## Changed Source Code

- src/GPS/GPSProvider.cc : Line 223: Temporary fix for new GPSDriverUBX use of GPSDriverUBX::Settings struct.
- src/QmlControls/QGCPalette.cc: Change palette directly from source.
- src/UI/AppSettings/HelpSettings.qml: Change for Robiotec Info.
- src/Vehicle/Vehicle.cc: Add necessary copied code to add RPMSensor display.
- src/Vehicle/Vehicle.h: Add necessary copied code to add RPMSensor diplay.
- src/Vehicle/FactGroups/CMakeLists.txt: Add necessary copied code to compile RPMSensor display.
- src/Vehicle/FactGroups/RPMSensorFact.json: Copy of RPMFact.json with less inputs.
- src/Vehicle/FactGroups/VehicleRPMSensorFactGroup.cc: Copy of VehicleRPMFactGroup.cc w/ VehicleHygrometerFactGroup.cc with MAVLINK_MSG_ID_RPM input data from ArdupilotMega.XML MavLink dialect.
- src/Vehicle/FactGroups/VehicleRPMSensorFactGroup.h: Copy of VehicleRPMFactGroup.h to setup RPM Sensor display.
