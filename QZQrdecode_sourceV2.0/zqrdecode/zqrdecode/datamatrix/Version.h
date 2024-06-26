#ifndef __VERSION_H__
#define __VERSION_H__

/*
 *  Version.h
 *  zqrdecode
 *
 */

#include <zqrdecode/ReaderException.h>
#include <zqrdecode/common/BitMatrix.h>
#include <zqrdecode/common/Counted.h>
#include <vector>

namespace zqrdecode {
namespace datamatrix {

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
  int ecCodewords_;
  std::vector<ECB*> ecBlocks_;
public:
  ECBlocks(int ecCodewords, ECB *ecBlocks);
  ECBlocks(int ecCodewords, ECB *ecBlocks1, ECB *ecBlocks2);
  int getECCodewords();
  std::vector<ECB*>& getECBlocks();
  ~ECBlocks();
};

class Version : public Counted {
private:
  int versionNumber_;
  int symbolSizeRows_;
  int symbolSizeColumns_;
  int dataRegionSizeRows_;
  int dataRegionSizeColumns_;
  ECBlocks* ecBlocks_;
  int totalCodewords_;
  Version(int versionNumber, int symbolSizeRows, int symbolSizeColumns, int dataRegionSizeRows,
		  int dataRegionSizeColumns, ECBlocks *ecBlocks);

public:
  static std::vector<Ref<Version> > VERSIONS;
  
  ~Version();
  int getVersionNumber();
  int getSymbolSizeRows();
  int getSymbolSizeColumns();  
  int getDataRegionSizeRows();  
  int getDataRegionSizeColumns();
  int getTotalCodewords();
  ECBlocks* getECBlocks();
  static int  buildVersions();  
  Ref<Version> getVersionForDimensions(int numRows, int numColumns);
  
private:
  Version(const Version&);
  Version & operator=(const Version&);
};
}
}

#endif // __VERSION_H__
