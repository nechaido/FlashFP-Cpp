#ifndef SRC_STORAGE_PROVIDER_H_
#define SRC_STORAGE_PROVIDER_H_

#include <list>

#include "query_result.h"
#include "fingerprint.h"
#include "audio_info.h"

namespace audio_recognition {

using std::list;

class StorageProvider {
 public:
  virtual int getFingerprintCount() = 0;

  virtual int getAudioCount() = 0;

  virtual bool contains(int id) = 0;

  virtual bool contains(AudioInfo info) = 0;

  virtual void addAudio(const int id,
                        const AudioInfo* info,
                        std::list<int> hashes) = 0;

  virtual AudioInfo getAuidioInfo(int id) = 0;

  virtual list<QueryResult> getMatches(list<FingerPrint> fingerprints) = 0;
};

} // namespace audio_recognition

#endif SRC_STORAGE_PROVIDER_H_
