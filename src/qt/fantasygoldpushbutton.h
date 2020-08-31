#ifndef FGCPUSHBUTTON_H
#define FGCPUSHBUTTON_H
#include <QPushButton>
#include <QStyleOptionButton>
#include <QIcon>

class FantasyGoldPushButton : public QPushButton
{
public:
    explicit FantasyGoldPushButton(QWidget * parent = Q_NULLPTR);
    explicit FantasyGoldPushButton(const QString &text, QWidget *parent = Q_NULLPTR);

protected:
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;

private:
    void updateIcon(QStyleOptionButton &pushbutton);

private:
    bool m_iconCached;
    QIcon m_downIcon;
};

#endif // FGCPUSHBUTTON_H
