#ifndef __DETECTOR_H__
#define __DETECTOR_H__

/*
 *  Detector.h
 *  zqrdecode
 *
 */

#include <zqrdecode/common/Point.h>
#include <zqrdecode/common/DetectorResult.h>
#include <zqrdecode/NotFoundException.h>
#include <zqrdecode/BinaryBitmap.h>
#include <zqrdecode/DecodeHints.h>

namespace zqrdecode {
namespace pdf417 {
namespace detector {

class Detector {
private:
  static const int INTEGER_MATH_SHIFT = 8;
  static const int PATTERN_MATCH_RESULT_SCALE_FACTOR = 1 << INTEGER_MATH_SHIFT;
  static const int MAX_AVG_VARIANCE;
  static const int MAX_INDIVIDUAL_VARIANCE;

  static const int START_PATTERN[];
  static const int START_PATTERN_LENGTH;
  static const int START_PATTERN_REVERSE[];
  static const int START_PATTERN_REVERSE_LENGTH;
  static const int STOP_PATTERN[];
  static const int STOP_PATTERN_LENGTH;
  static const int STOP_PATTERN_REVERSE[];
  static const int STOP_PATTERN_REVERSE_LENGTH;

  Ref<BinaryBitmap> image_;
  
  static ArrayRef< Ref<ResultPoint> > findVertices(Ref<BitMatrix> matrix, int rowStep);
  static ArrayRef< Ref<ResultPoint> > findVertices180(Ref<BitMatrix> matrix, int rowStep);

  static ArrayRef<int> findGuardPattern(Ref<BitMatrix> matrix,
                                        int column,
                                        int row,
                                        int width,
                                        bool whiteFirst,
                                        const int pattern[],
                                        int patternSize,
                                        ArrayRef<int>& counters);
  static int patternMatchVariance(ArrayRef<int>& counters, const int pattern[],
                                  int maxIndividualVariance);

  static void correctVertices(Ref<BitMatrix> matrix,
                              ArrayRef< Ref<ResultPoint> >& vertices,
                              bool upsideDown);
  static void findWideBarTopBottom(Ref<BitMatrix> matrix,
                                   ArrayRef< Ref<ResultPoint> >& vertices,
                                   int offsetVertice,
                                   int startWideBar,
                                   int lenWideBar,
                                   int lenPattern,
                                   int nIncrement);
  static void findCrossingPoint(ArrayRef< Ref<ResultPoint> >& vertices,
                                int idxResult,
                                int idxLineA1,int idxLineA2,
                                int idxLineB1,int idxLineB2,
                                Ref<BitMatrix>& matrix);
  static Point intersection(Line a, Line b);
  static float computeModuleWidth(ArrayRef< Ref<ResultPoint> >& vertices);
  static int computeDimension(Ref<ResultPoint> const& topLeft,
                              Ref<ResultPoint> const& topRight,
                              Ref<ResultPoint> const& bottomLeft,
                              Ref<ResultPoint> const& bottomRight,
                              float moduleWidth);
  int computeYDimension(Ref<ResultPoint> const& topLeft,
                        Ref<ResultPoint> const& topRight,
                        Ref<ResultPoint> const& bottomLeft,
                        Ref<ResultPoint> const& bottomRight,
                        float moduleWidth);

  Ref<BitMatrix> sampleLines(ArrayRef< Ref<ResultPoint> > const& vertices, int dimensionY, int dimension);

public:
  Detector(Ref<BinaryBitmap> image);
  Ref<BinaryBitmap> getImage();
  Ref<DetectorResult> detect();
  Ref<DetectorResult> detect(DecodeHints const& hints);
};

}
}
}

#endif // __DETECTOR_H__
