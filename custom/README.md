# QGroundControl Custom Build

Estación de control terrestre multi-plataforma para drones (Android, Linux, Windows)

## Linux AppImage error

[ERROR] Command '['tar', '-xvf', '/dev/shm/appimagelint-yylid6_v.tmp/data.tar.xz']' returned non-zero exit status 2.

## Nix AppImage fast deploy

nix run nixpkgs#appimage-run build/*.AppImage
  67890

## Changed Source Code

- _src/GPS/GPSProvider.cc Line 223:_ Temporary fix for new GPSDriverUBX use of GPSDriverUBX::Settings struct.
(last argument provided was: `GPSDriverUBX::Settings(0b111, kGPSHeadingOffset, UBX_BAUDRATE_M8_AND_NEWER, true, GPSDriverUBX::UBXMode::GroundControlStation)`)
- _src/QmlControls/QGCPalette.cc:_ Change palette directly from source.
- _src/UI/AppSettings/HelpSettings.qml:_ Change for Robiotec Info.
- _src/Vehicle/Vehicle.cc:_ Add necessary copied code to add RPMSensor display.
- _src/Vehicle/Vehicle.h:_ Add necessary copied code to add RPMSensor diplay.
- _src/Vehicle/FactGroups/CMakeLists.txt:_ Add necessary copied code to compile RPMSensor display.
- _src/Vehicle/FactGroups/RPMSensorFact.json:_ Copy of RPMFact.json with less inputs.
- _src/Vehicle/FactGroups/VehicleRPMSensorFactGroup.cc:_ Copy of VehicleRPMFactGroup.cc w/ VehicleHygrometerFactGroup.cc with MAVLINK_MSG_ID_RPM input data from ArdupilotMega.XML MavLink dialect.
- _src/Vehicle/FactGroups/VehicleRPMSensorFactGroup.h:_ Copy of VehicleRPMFactGroup.h to setup RPM Sensor display.
