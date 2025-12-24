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
- _src/Vehicle/FactGroups/RPMFact.json:_ Add RPM Sensors.
- _src/Vehicle/FactGroups/VehicleRPMFactGroup.cc:_ w/ help of code from VehicleHygrometerFactGroup.cc with MAVLINK_MSG_ID_RPM input data from ArdupilotMega.XML MavLink dialect.
- _src/Vehicle/FactGroups/VehicleRPMFactGroup.h:_ Declare RPM Sensors variables and methods.
- _src/GQCApplication.cc:_ Delete QGC_DAILY_BUILD from Application information in order to build without \<_Daily_\> after the name.
- _src/FlightMap/Widgets/CompassHeadingIndicator.qml:_ Changing infill colors derived from [Qt Color Table](https://doc.qt.io/qt-6/qml-color.html?search=hsla#svg-color-reference) to differenciate from QGC.
- _src/FlightMap/Widgets/QGCArtificialHorizon.qml:_ Changing Gradient colors obtained from [Qt Color Table](https://doc.qt.io/qt-6/qml-color.html?search=hsla#svg-color-reference) to differenciate from QGC.
