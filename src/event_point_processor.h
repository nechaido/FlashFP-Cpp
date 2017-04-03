#ifndef SRC_EVENT_POINT_PROCESSOR_H_
#define SRC_EVENT_POINT_PROCESSOR_H_

#include <list>

#include "config.h"
#include "audio_source.h"
#include "fingerprint.h"

namespace audio_recognition {

class EventPointProcessor {
 public:
  EventPointProcessor(const Config* config);

  std::list<FingerPrint> getFingerprints(AudioSource& audioSource);

  void reset();
 private:
  const Config* config_;
};

} // namespace audio_recognition

#endif //SRC_EVENT_POINT_PROCESSOR_H_
