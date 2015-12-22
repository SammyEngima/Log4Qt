#ifndef LOG4QT_BINARYLAYOUT_H
#define LOG4QT_BINARYLAYOUT_H

#include "layout.h"

#include <QtCore/QByteArray>

namespace Log4Qt
{

class LoggingEvent;
class BinaryLoggingEvent;

class LOG4QT_EXPORT BinaryLayout : public Layout
{
    Q_OBJECT
    Q_PROPERTY(QByteArray binaryFooter READ binaryFooter WRITE setBinaryFooter)
    Q_PROPERTY(QByteArray binaryHeader READ binaryHeader WRITE setBinaryHeader)
public:
    explicit BinaryLayout(QObject *parent = 0);

    virtual QByteArray binaryFormat(const BinaryLoggingEvent &rEvent);
    virtual QString format(const LoggingEvent &rEvent) override;

    virtual QString contentType() const override;

    virtual QByteArray binaryFooter() const;
    void setBinaryFooter(const QByteArray &rFooter);

    virtual QByteArray binaryHeader() const;
    void setBinaryHeader(const QByteArray &rHeader);

protected:
#ifndef QT_NO_DEBUG_STREAM
    virtual QDebug debug(QDebug &rDebug) const override;
#endif // QT_NO_DEBUG_STREAM

private:
    Q_DISABLE_COPY(BinaryLayout)

    QByteArray mFooter;
    QByteArray mHeader;
};

inline QByteArray BinaryLayout::binaryFooter() const
{
    return mFooter;
}

inline void BinaryLayout::setBinaryFooter(const QByteArray &rFooter)
{
    mFooter = rFooter;
}

inline QByteArray BinaryLayout::binaryHeader() const
{
    return mHeader;
}

inline void BinaryLayout::setBinaryHeader(const QByteArray &rHeader)
{
    mHeader = rHeader;
}

} // namespace Log4Qt

#endif // LOG4QT_BINARYLAYOUT_H
