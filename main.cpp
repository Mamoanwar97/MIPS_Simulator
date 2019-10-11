#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
// ================== QTreeWidget ========================
//  items added in tree can have sub-item (child item with the same type(QTreeWidgetItem) )
//
//  setColumnCount(int colomns)   must be called first to determine how much colomns in Tree
//  setHeaderLabels(const QStringList &labels)    colomns titles
//  addTopLevelItem(QTreeWidgetItem* item)
//
//  setColumnWidth(int index , int width )   set colomn with index to width (default =100)
//  insetTopLevelItem(int index , QTreeWidgetItem* item)
//  int topLevelItemCount()   return the size of items
//  int	indexOfTopLevelItem(QTreeWidgetItem *item)
//  QTreeWidgetItem *	topLevelItem(int index)
// =======================================================
// ================== QTreeWidgetItem ========================
//  you can consider it as an array of strings QStringList that has a size = the num of colomns in the tree widget
//
//    QTreeWidgetItem(const QStringList &strings)
//    void	setText(int column, const QString &text)
//
//    QString	text(int column) const
//    void	setTextAlignment(int column, int Qt::alignment)
// =======================================================
