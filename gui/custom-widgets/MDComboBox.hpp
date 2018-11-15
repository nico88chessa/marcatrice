#ifndef MDCOMBOBOX_HPP
#define MDCOMBOBOX_HPP

#include <QComboBox>

class MDComboBox : public QComboBox {
    Q_OBJECT

    Q_PROPERTY(QString labelText READ getLabelText WRITE setLabelText)
    Q_PROPERTY(int labelLeft READ getLabelLeft WRITE setLabelLeft)
    Q_PROPERTY(int labelTop READ getLabelTop WRITE setLabelTop)
    Q_PROPERTY(int labelTextWidth READ getLabelTextWidth WRITE setLabelTextWidth)
    Q_PROPERTY(QColor labelHoverColor READ getLabelHoverColor WRITE setLabelHoverColor)

public:
    using Ptr = MDComboBox*;
    using ConstPtr = const MDComboBox*;

private:
    QString labelText;
    int labelLeft;
    int labelTop;
    int labelTextWidth;
    QColor labelHoverColor;

public:
    explicit MDComboBox(QWidget *parent = nullptr);

    QString getLabelText() const;
    void setLabelText(const QString& value);

    int getLabelLeft() const;
    void setLabelLeft(int value);

    int getLabelTop() const;
    void setLabelTop(int value);

    int getLabelTextWidth() const;
    void setLabelTextWidth(int value);

    QColor getLabelHoverColor() const;
    void setLabelHoverColor(const QColor& value);

protected:
    void paintEvent(QPaintEvent* event);
};

#endif // MDCOMBOBOX_HPP
