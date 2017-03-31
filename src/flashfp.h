#ifndef SRC_DB_H_
#define SRC_DB_H_

#include <list>
#include <string>

#include "audio_info.h"
#include "audio_source.h"
#include "config.h"
#include "fingerprint.h"
#include "query_result.h"
#include "storage_provider.h"

namespace audio_recognition {

class FlashFP {
 public:
  FlashFP(const Config* config, StorageProvider* storage);
  ~FlashFP();

  bool store(int id, AudioSource audioSource, AudioInfo info);

  AudioInfo getAudioDescription(int id);

  std::list<QueryResult> match(AudioSource audioSource, int limit);

  bool contains(AudioInfo info);

 private:
  const Config* config_;
  StorageProvider* storage_;

  list<FingerPrint> extractFingerprints(AudioSource source);
};

}  // namespace audio_recognition

#endif  // SRC_DB_H_
