#ifndef SRC_AUDIO_SOURCE_H
#define SRC_AUDIO_SOURCE_H

#include <cstdint>

#include "audio_format.h"

namespace audio_recognition {

float* pcm_to_float(const int* pcm, int length);

struct AudioSource {
  AudioSource(const float* buffer, const int length, const AudioFormat format)
      : buffer(buffer), length(length), format(format) {};

  AudioSource(const int* pcm, const int length, const AudioFormat format)
      : buffer(pcm_to_float(pcm, length)),
        length(length),
        format(format) {};

  const float* buffer;
  const int length;
  const AudioFormat format;
};

}  // namespace audio_recognition

#endif  // SRC_AUDIO_SOURCE_H