#include "mymodel.h"

MyModel::MyModel(QObject *parent)
    : QAbstractItemModel(parent)
{
    m_strList.clear();
    for (int i = 0; i < 10; i++) {
        m_strList.append(QString("湖北省-%1").arg(i));
    }
}

QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    return QAbstractItemModel::headerData(section, orientation, role);
}

bool MyModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if (value != headerData(section, orientation, role)) {
        // FIXME: Implement me!
        emit headerDataChanged(orientation, section, section);
        return true;
    }
    return false;
}

QModelIndex MyModel::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
    return createIndex(row, column);
}

QModelIndex MyModel::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
    return QModelIndex();
}

int MyModel::rowCount(const QModelIndex &parent) const
{
//    if (!parent.isValid())
//        return 0;
    return m_strList.size();
}

int MyModel::columnCount(const QModelIndex &parent) const
{
//    if (!parent.isValid())
//        return 0;
       return 1;
}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole || role == Qt::EditRole)
        return m_strList.at(index.row());

    return QVariant();
}

bool MyModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        m_strList[index.row()] = value.toString();

        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags MyModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable | Qt::ItemIsEnabled; // FIXME: Implement me!
}
