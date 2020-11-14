// SPDX-License-Identifier: BSD-3-Clause
// Copyright (c) 2020, The Monero Project.

#ifndef XMRIGWIDGET_H
#define XMRIGWIDGET_H

#include <QMenu>
#include <QWidget>
#include <QItemSelection>

#include "utils/xmrig.h"
#include "utils/config.h"
#include "appcontext.h"

namespace Ui {
    class XMRigWidget;
}

class XMRigWidget : public QWidget
{
    Q_OBJECT

public:
    explicit XMRigWidget(AppContext *ctx, QWidget *parent = nullptr);
    ~XMRigWidget();
    QStandardItemModel *model();

public slots:
    void onWalletClosed();
    void onWalletOpened();
    void onStartClicked();
    void onStopClicked();
    void onClearClicked();
    void onDownloads(const QJsonObject &data);
    void linkClicked();
    void onProcessError(const QString &msg);
    void onProcessOutput(const QByteArray &msg);
    void onHashrate(const QString &hashrate);
    void onCustomPathChecked(int state);
    void onSoloChecked(int state);

private slots:
    void onBrowseClicked();
    void onThreadsValueChanged(int date);
    void onPoolChanged(int pos);

signals:
    void miningStarted();
    void miningEnded();

private:
    void showContextMenu(const QPoint &pos);

    AppContext *m_ctx;
    Ui::XMRigWidget *ui;
    QStandardItemModel *m_model;
    QMenu *m_contextMenu;
    unsigned int m_threads;
    QStringList m_urls;
    QStringList m_pools{"pool.xmr.pt:9000", "pool.supportxmr.com:9000", "mine.xmrpool.net:443", "xmrpool.eu:9999", "xmr-eu1.nanopool.org:14433", "pool.minexmr.com:6666", "us-west.minexmr.com:6666", "monerohash.com:9999", "cryptonote.social:5555", "cryptonote.social:5556"};
};

#endif // REDDITWIDGET_H