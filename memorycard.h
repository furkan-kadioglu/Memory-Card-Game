#ifndef MEMORYCARD_H
#define MEMORYCARD_H

#include <QtCore/QObject>
#include <QtWidgets/QGraphicsPixmapItem>

class MemoryGameBoard;

class MemoryCard : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
    Q_PROPERTY(qreal scale READ scale WRITE setScale)
    QPixmap m_face, m_back;
    bool m_isFace;
    int m_id;

    void flip(const char *slotName);

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);

public:
    explicit MemoryCard(MemoryGameBoard *scene);
    explicit MemoryCard(const QPixmap &face, const QPixmap &back, MemoryGameBoard *scene, int id);
    bool isFace() const;

signals:
    void matched();

private slots:
    void setToFace();
    void setToBack();

public slots:
    void flyOut();
    void flipToFace();
    void flipToBack();

};

#endif // MEMORYCARD_H
