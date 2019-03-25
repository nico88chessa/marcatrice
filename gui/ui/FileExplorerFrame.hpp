#ifndef FILEEXPLORERFRAME_HPP
#define FILEEXPLORERFRAME_HPP

#include <QDataWidgetMapper>
#include <QFrame>

namespace Ui {
class FileExplorerFrame;
}

class FileExplorerFrame : public QFrame
{
    Q_OBJECT

public:
    explicit FileExplorerFrame(QWidget *parent = nullptr);
    ~FileExplorerFrame();

private:
    Ui::FileExplorerFrame *ui;

private:
    void setupSignalsAndSlots();
    void setupUi();

private slots:
    void updateBreadCrumb(const QString& folderPath);
    void updateFileExplorer(const QString& folderPath);

};

#endif // FILEEXPLORERFRAME_HPP
