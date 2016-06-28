#ifndef SYSTEMTRAYPLUGIN_H
#define SYSTEMTRAYPLUGIN_H

#include "pluginsiteminterface.h"
#include "traywidget.h"
#include "dbus/dbustraymanager.h"

class SystemTrayPlugin : public QObject, PluginsItemInterface
{
    Q_OBJECT
    Q_INTERFACES(PluginsItemInterface)
    Q_PLUGIN_METADATA(IID "com.deepin.dock.PluginsItemInterface" FILE "system-tray.json")

public:
    explicit SystemTrayPlugin(QObject *parent = 0);

    const QString pluginName() const;
    void init(PluginProxyInterface *proxyInter);
    ItemType pluginType(const QString &itemKey);

    QWidget *itemWidget(const QString &itemKey);

private slots:
    void pluginAdded(const quint32 winId);
    void pluginRemoved(const quint32 winId);

private:
    DBusTrayManager *m_trayInter;
    QMap<quint32, TrayWidget *> m_trayList;
};

#endif // SYSTEMTRAYPLUGIN_H
