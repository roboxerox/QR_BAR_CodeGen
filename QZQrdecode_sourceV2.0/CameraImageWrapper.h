#ifndef CAMERAIMAGE_H
#define CAMERAIMAGE_H

#include <QImage>
#include <QString>
#include <zqrdecode/zqrdecode/LuminanceSource.h>

using namespace zqrdecode;

class CameraImageWrapper : public LuminanceSource
{
public:
    CameraImageWrapper();
    CameraImageWrapper(const QImage& sourceImage);
    CameraImageWrapper(CameraImageWrapper& otherInstance);
    ~CameraImageWrapper();

    static CameraImageWrapper* Factory(const QImage& image, int maxWidth=-1, int maxHeight=-1, bool smoothTransformation=false);
    
    int getWidth() const;
    int getHeight() const;
    
    unsigned char getPixel(int x, int y) const;
    unsigned char* copyMatrix() const;
    
    QImage grayScaleImage(QImage::Format f);
    QImage getOriginalImage();

    // Callers take ownership of the returned memory and must call delete [] on it themselves.
    ArrayRef<char> getRow(int y, ArrayRef<char> row) const;
    ArrayRef<char> getMatrix() const;
  
private:
    QImage image;
    unsigned char* pRow;
    unsigned char* pMatrix;
};

#endif //CAMERAIMAGE_H
