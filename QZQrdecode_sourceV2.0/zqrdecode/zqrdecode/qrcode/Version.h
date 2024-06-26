#ifndef __VERSION_H__
#define __VERSION_H__

/*
 *  Version.h
 *  zqrdecode
 *
 */

#include <zqrdecode/common/Counted.h>
#include <zqrdecode/qrcode/ErrorCorrectionLevel.h>
#include <zqrdecode/ReaderException.h>
#include <zqrdecode/common/BitMatrix.h>
#include <zqrdecode/common/Counted.h>
#include <vector>

namespace zqrdecode {
namespace qrcode {

class ECB {
private:
  int count_;
  int dataCodewords_;
public:
  ECB(int count, int dataCodewords);
  int getCount();
  int getDataCodewords();
};

class ECBlocks {
private:
  int ecCodewordsPerBloc_;
  std::vector<ECB*> ecBlocks_;
public:
  ECBlocks(int ecCodewordsPerBloc, ECB *ecBlocks);
  ECBlocks(int ecCodewordsPerBloc, ECB *ecBlocks1, ECB *ecBlocks2);
  int getECCodewordsPerBloc();
  int getTotalECCodewords();
  std::vector<ECB*>& getECBlocks();
  ~ECBlocks();
};

class Version : public Counted {

private:
  int versionNumber_;
  std::vector<int> &alignmentPatternCenters_;
  std::vector<ECBlocks*> ecBlocks_;
  int totalCodewords_;
  Version(int versionNumber, std::vector<int> *alignmentPatternCenters, ECBlocks *ecBlocks1, ECBlocks *ecBlocks2,
          ECBlocks *ecBlocks3, ECBlocks *ecBlocks4);

public:
  static unsigned int VERSION_DECODE_INFO[];
  static int N_VERSION_DECODE_INFOS;
  static std::vector<Ref<Version> > VERSIONS;

  ~Version();
  int getVersionNumber() const;
  std::vector<int> &getAlignmentPatternCenters();
  int getTotalCodewords();
  int getDimensionForVersion();
  ECBlocks &getECBlocksForLevel(const ErrorCorrectionLevel &ecLevel) const;
  static Ref<Version> getProvisionalVersionForDimension(int dimension);
  static Ref<Version> getVersionForNumber(int versionNumber);
  static Ref<Version> decodeVersionInformation(unsigned int versionBits);
  Ref<BitMatrix> buildFunctionPattern();
  static int buildVersions();
};
}
}

#endif // __VERSION_H__
