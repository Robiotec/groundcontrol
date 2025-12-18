/****************************************************************************
 *
 * (c) 2009-2024 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/


/// @file
///     @author Don Gagne <don@thegagnes.com>

#include "QGCPalette.h"
#include "QGCCorePlugin.h"

#include <QtCore/QDebug>

QList<QGCPalette*>   QGCPalette::_paletteObjects;

QGCPalette::Theme QGCPalette::_theme = QGCPalette::Dark;

QMap<int, QMap<int, QMap<QString, QColor>>> QGCPalette::_colorInfoMap;

QStringList QGCPalette::_colors;

QGCPalette::QGCPalette(QObject* parent) :
    QObject(parent),
    _colorGroupEnabled(true)
{
    if (_colorInfoMap.isEmpty()) {
        _buildMap();
    }

    // We have to keep track of all QGCPalette objects in the system so we can signal theme change to all of them
    _paletteObjects += this;
}

QGCPalette::~QGCPalette()
{
    bool fSuccess = _paletteObjects.removeOne(this);
    if (!fSuccess) {
        qWarning() << "Internal error";
    }
}

void QGCPalette::_buildMap()
{
    //                                      Light                 Dark
    //                                      Disabled   Enabled    Disabled   Enabled
    DECLARE_QGC_COLOR(window,               "#ffffff", "#ffffff", "#222222", "#222222")
    DECLARE_QGC_COLOR(windowTransparent,    "#ccffffff", "#ccffffff", "#cc222222", "#cc222222")
    DECLARE_QGC_COLOR(windowShadeLight,     "#909090", "#828282", "#707070", "#626262")
    DECLARE_QGC_COLOR(windowShade,          "#d9d9d9", "#d9d9d9", "#333333", "#333333")
    DECLARE_QGC_COLOR(windowShadeDark,      "#bdbdbd", "#bdbdbd", "#282828", "#282828")
    DECLARE_QGC_COLOR(text,                 "#9d9d9d", "#333333", "#707070", "#ffffff")
    DECLARE_QGC_COLOR(windowTransparentText,"#9d9d9d", "#000000", "#707070", "#ffffff")
    DECLARE_QGC_COLOR(warningText,          "#cc0808", "#cc0808", "#f85761", "#f85761")
    DECLARE_QGC_COLOR(button,               "#ffffff", "#D0DFF0", "#707070", "#323239")
    DECLARE_QGC_COLOR(buttonBorder,         "#9d9d9d", "#FFAE12", "#94693C", "#EDA960")
    DECLARE_QGC_COLOR(buttonText,           "#9d9d9d", "#333333", "#A6A6A6", "#ffffff")
    DECLARE_QGC_COLOR(buttonHighlight,      "#e4e4e4", "#FF7E12", "#3a3a3a", "#fff291")
    DECLARE_QGC_COLOR(buttonHighlightText,  "#2c2c2c", "#ffffff", "#2c2c2c", "#000000")
    DECLARE_QGC_COLOR(primaryButton,        "#585858", "#E3A76F", "#585858", "#E3A76F")
    DECLARE_QGC_COLOR(primaryButtonText,    "#2c2c2c", "#333333", "#2c2c2c", "#000000")
    DECLARE_QGC_COLOR(textField,            "#ffffff", "#ffffff", "#707070", "#ffffff")
    DECLARE_QGC_COLOR(textFieldText,        "#808080", "#333333", "#000000", "#000000")
    DECLARE_QGC_COLOR(mapButton,            "#585858", "#333333", "#585858", "#000000")
    DECLARE_QGC_COLOR(mapButtonHighlight,   "#585858", "#be781c", "#585858", "#be781c")
    DECLARE_QGC_COLOR(mapIndicator,         "#585858", "#bb1fa6", "#585858", "#bb1fa6")
    DECLARE_QGC_COLOR(mapIndicatorChild,    "#585858", "#BA5EAE", "#585858", "#BA5EAE")
    DECLARE_QGC_COLOR(colorGreen,           "#00CA40", "#00CA40", "#00e04b", "#00e04b")
    DECLARE_QGC_COLOR(colorYellow,          "#a2a200", "#a2a200", "#ffff00", "#ffff00")
    DECLARE_QGC_COLOR(colorYellowGreen,     "#799f26", "#799f26", "#9dbe2f", "#9dbe2f")
    DECLARE_QGC_COLOR(colorOrange,          "#bf7539", "#bf7539", "#de8500", "#de8500")
    DECLARE_QGC_COLOR(colorRed,             "#C41714", "#C41714", "#f32836", "#f32836")
    DECLARE_QGC_COLOR(colorGrey,            "#808080", "#808080", "#bfbfbf", "#bfbfbf")
    DECLARE_QGC_COLOR(colorBlue,            "#1a72ff", "#1a72ff", "#536dff", "#536dff")
    DECLARE_QGC_COLOR(alertBackground,      "#eecc44", "#eecc44", "#191919", "#191919")
    DECLARE_QGC_COLOR(alertBorder,          "#808080", "#808080", "#000000", "#000000")
    DECLARE_QGC_COLOR(alertText,            "#000000", "#000000", "#F0D201", "#F0D201")
    DECLARE_QGC_COLOR(missionItemEditor,    "#585858", "#6bfde5", "#585858", "#34646d")
    DECLARE_QGC_COLOR(toolStripHoverColor,  "#585858", "#9D9D9D", "#585858", "#585d83")
    DECLARE_QGC_COLOR(statusFailedText,     "#9d9d9d", "#000000", "#707070", "#ffffff")
    DECLARE_QGC_COLOR(statusPassedText,     "#9d9d9d", "#000000", "#707070", "#ffffff")
    DECLARE_QGC_COLOR(statusPendingText,    "#9d9d9d", "#000000", "#707070", "#ffffff")
    DECLARE_QGC_COLOR(toolbarBackground,    "#60dfffff", "#60dfffff", "#2a3b3b22", "#2a3b3b22")
    DECLARE_QGC_COLOR(groupBorder,          "#bbbbbb", "#FFAE12", "#94693C", "#EDA960")

    // Colors not affecting by theming
    //                                                      Disabled     Enabled
    DECLARE_QGC_NONTHEMED_COLOR(brandingPurple,             "#C36B0E", "#ED8311")
    DECLARE_QGC_NONTHEMED_COLOR(brandingBlue,               "#48D6FF", "#6045c5")
    DECLARE_QGC_NONTHEMED_COLOR(toolStripFGColor,           "#707070", "#ffffff")
    DECLARE_QGC_NONTHEMED_COLOR(photoCaptureButtonColor,    "#ffffff", "#D0DFF0")
    DECLARE_QGC_NONTHEMED_COLOR(videoCaptureButtonColor,    "#A61B24", "#f32836")

    // Colors not affecting by theming or enable/disable
    DECLARE_QGC_SINGLE_COLOR(mapWidgetBorderLight,          "#e0e0e0")
    DECLARE_QGC_SINGLE_COLOR(mapWidgetBorderDark,           "#212121")
    DECLARE_QGC_SINGLE_COLOR(mapMissionTrajectory,          "#bb1fa6")
    DECLARE_QGC_SINGLE_COLOR(surveyPolygonInterior,         "green")
    DECLARE_QGC_SINGLE_COLOR(surveyPolygonTerrainCollision, "red")

// Colors for UTM Adapter
#ifdef QGC_UTM_ADAPTER
    DECLARE_QGC_COLOR(switchUTMSP,        "#b0e0e6", "#b0e0e6", "#b0e0e6", "#b0e0e6");
    DECLARE_QGC_COLOR(sliderUTMSP,        "#9370db", "#9370db", "#9370db", "#9370db");
    DECLARE_QGC_COLOR(successNotifyUTMSP, "#3cb371", "#3cb371", "#3cb371", "#3cb371");
#endif
}

void QGCPalette::setColorGroupEnabled(bool enabled)
{
    _colorGroupEnabled = enabled;
    emit paletteChanged();
}

void QGCPalette::setGlobalTheme(Theme newTheme)
{
    // Mobile build does not have themes
    if (_theme != newTheme) {
        _theme = newTheme;
        _signalPaletteChangeToAll();
    }
}

void QGCPalette::_signalPaletteChangeToAll()
{
    // Notify all objects of the new theme
    for (QGCPalette *palette : std::as_const(_paletteObjects)) {
        palette->_signalPaletteChanged();
    }
}

void QGCPalette::_signalPaletteChanged()
{
    emit paletteChanged();
}
