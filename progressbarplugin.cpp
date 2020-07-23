#include "progressbar.h"
#include "progressbarplugin.h"

#include <QtPlugin>

ProgressBarPlugin::ProgressBarPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void ProgressBarPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool ProgressBarPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *ProgressBarPlugin::createWidget(QWidget *parent)
{
    return new ProgressBar(parent);
}

QString ProgressBarPlugin::name() const
{
    return QLatin1String("ProgressBar");
}

QString ProgressBarPlugin::group() const
{
    return QLatin1String("");
}

QIcon ProgressBarPlugin::icon() const
{
    return QIcon();
}

QString ProgressBarPlugin::toolTip() const
{
    return QLatin1String("");
}

QString ProgressBarPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool ProgressBarPlugin::isContainer() const
{
    return false;
}

QString ProgressBarPlugin::domXml() const
{
    return QLatin1String("<widget class=\"ProgressBar\" name=\"progressBar\">\n</widget>\n");
}

QString ProgressBarPlugin::includeFile() const
{
    return QLatin1String("progressbar.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(progressbarplugin, ProgressBarPlugin)
#endif // QT_VERSION < 0x050000
