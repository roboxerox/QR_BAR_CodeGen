#ifndef __LINESSAMPLER_H__
#define __LINESSAMPLER_H__


#include <map>
#include <zqrdecode/common/BitMatrix.h>
#include <zqrdecode/ResultPoint.h>
#include <zqrdecode/common/Point.h>

namespace zqrdecode {
namespace pdf417 {
namespace detector {

class LinesSampler {
private:
  static const int MODULES_IN_SYMBOL = 17;
  static const int BARS_IN_SYMBOL = 8;
  static const int POSSIBLE_SYMBOLS = 2787;
  static const std::vector<float> RATIOS_TABLE;
  static std::vector<float> init_ratios_table();
  static const int BARCODE_START_OFFSET = 2;

  Ref<BitMatrix> linesMatrix_;
  int symbolsPerLine_;
  int dimension_;
  
  static std::vector<Ref<ResultPoint> > findVertices(Ref<BitMatrix> matrix, int rowStep);
  static std::vector<Ref<ResultPoint> > findVertices180(Ref<BitMatrix> matrix, int rowStep);

  static ArrayRef<int> findGuardPattern(Ref<BitMatrix> matrix,
                                        int column,
                                        int row,
                                        int width,
                                        bool whiteFirst,
                                        const int pattern[],
                                        int patternSize,
                                        ArrayRef<int> counters);
  static int patternMatchVariance(ArrayRef<int> counters, const int pattern[],
                                  int maxIndividualVariance);

  static void correctVertices(Ref<BitMatrix> matrix,
                              std::vector<Ref<ResultPoint> > &vertices,
                              bool upsideDown);
  static void findWideBarTopBottom(Ref<BitMatrix> matrix,
                                   std::vector<Ref<ResultPoint> > &vertices,
                                   int offsetVertice,
                                   int startWideBar,
                                   int lenWideBar,
                                   int lenPattern,
                                   int nIncrement);
  static void findCrossingPoint(std::vector<Ref<ResultPoint> > &vertices,
                                int idxResult,
                                int idxLineA1,int idxLineA2,
                                int idxLineB1,int idxLineB2,
                                Ref<BitMatrix> matrix);
  static float computeModuleWidth(std::vector<Ref<ResultPoint> > &vertices);
  static int computeDimension(Ref<ResultPoint> topLeft,
                              Ref<ResultPoint> topRight,
                              Ref<ResultPoint> bottomLeft,
                              Ref<ResultPoint> bottomRight,
                              float moduleWidth);
  int computeYDimension(Ref<ResultPoint> topLeft,
                        Ref<ResultPoint> topRight,
                        Ref<ResultPoint> bottomLeft,
                        Ref<ResultPoint> bottomRight,
                        float moduleWidth);

   Ref<BitMatrix> sampleLines(std::vector<Ref<ResultPoint> > const &vertices,
                              int dimensionY,
                              int dimension);

  static void codewordsToBitMatrix(std::vector<std::vector<int> > &codewords,
                                   Ref<BitMatrix> &matrix);
  static int calculateClusterNumber(int codeword);
  static Ref<BitMatrix> sampleGrid(Ref<BitMatrix> image,
                                   int dimension);
  static void computeSymbolWidths(std::vector<float>& symbolWidths,
                                  const int symbolsPerLine, Ref<BitMatrix> linesMatrix);
  static void linesMatrixToCodewords(std::vector<std::vector<int> > &clusterNumbers,
                                     const int symbolsPerLine,
                                     const std::vector<float> &symbolWidths,
                                     Ref<BitMatrix> linesMatrix,
                                     std::vector<std::vector<int> > &codewords);
  static std::vector<std::vector<std::map<int, int> > >
      distributeVotes(const int symbolsPerLine,
                      const std::vector<std::vector<int> >& codewords,
                      const std::vector<std::vector<int> >& clusterNumbers);
  static std::vector<int>
      findMissingLines(const int symbolsPerLine,
                       std::vector<std::vector<int> > &detectedCodeWords);
  static int decodeRowCount(const int symbolsPerLine,
                            std::vector<std::vector<int> > &detectedCodeWords,
                            std::vector<int> &insertLinesAt);

  static int round(float d);
  static Point intersection(Line a, Line b);

public:
  LinesSampler(Ref<BitMatrix> linesMatrix, int dimension);
  Ref<BitMatrix> sample();
};

}
}
}

#endif // __LINESSAMPLER_H__
